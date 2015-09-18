//
//
//


#include "spPlayWav.h"


	
spPlayWav::spPlayWav()
{
	uiID = 0;
	pBufferBits = NULL;
	pwfx = NULL;
	pszFilename = m_szNameString;
}


spPlayWav::spPlayWav( LPCTSTR pszWavFile )
{
	uiID = 0;
	pBufferBits = NULL;
	pwfx = NULL;
	///pszWavFile = pszFilename;
	wsprintf( m_szNameString, TEXT("%s"), pszWavFile );
	pszFilename = m_szNameString;
}


spPlayWav::~spPlayWav()
{
}


void spPlayWav::SetDevice( UINT uID )
{
	uiID = uID;
}


MMRESULT spPlayWav::Play( LPCTSTR pszWavFile )
{
	///pszWavFile = pszFilename;
	wsprintf( m_szNameString, TEXT("%s"), pszWavFile );
	return Play();
}

MMRESULT spPlayWav::Play()
{

	hevDone = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (hevDone == NULL) {
        return MMSYSERR_NOMEM;
    }

    RETAILMSG(1, (TEXT("opening wav file \"%s\" \r\n")
        , pszFilename
        ));	

    mr = ReadWaveFile(pszFilename,&pwfx,&dwBufferSize,&pBufferBits);
    MRCHECK(mr, ReadWaveFile, ERROR_READ);

    // Note: Cast to UINT64 below is to avoid potential DWORD overflow for large (>~4MB) files.
    dwDuration = (DWORD)(((UINT64)dwBufferSize) * 1000 / pwfx->nAvgBytesPerSec);

    RETAILMSG(1, (TEXT("\"%s\" %c%02d %5dHz %6d bytes %5d ms\r\n")
        , pszFilename
        , pwfx->nChannels == 2 ? L'S' : L'M'
        , pwfx->wBitsPerSample
        , pwfx->nSamplesPerSec
        , dwBufferSize
        , dwDuration
        ));	

	mr = waveOutOpen( &hwo, uiID, pwfx, (DWORD)hevDone, NULL, CALLBACK_EVENT );	
	MRCHECK(mr, waveOutOpen, ERROR_OPEN);
		
    memset(&hdr, 0, sizeof(hdr));
    hdr.dwBufferLength = dwBufferSize;
    hdr.lpData = (char *) pBufferBits;

    mr = waveOutPrepareHeader(hwo, &hdr, sizeof(hdr));
    MRCHECK(mr, waveOutPrepareHeader, ERROR_PLAY);

    mr = waveOutWrite(hwo, &hdr, sizeof(hdr));
    MRCHECK(mr, waveOutWrite, ERROR_PLAY);

    // wait for play + 1 second slop
    dwSlop = 1000;
    dwWait = WaitForSingleObject(hevDone, dwDuration + dwSlop);
    if (dwWait != WAIT_OBJECT_0) {
        // not much to here, other than issue a warning
        RETAILMSG(1, (TEXT("Timeout waiting for playback to complete\r\n")));
    }

    mr = waveOutUnprepareHeader(hwo, &hdr, sizeof(hdr));
    MRCHECK(mr, waveOutUnprepareHeader, ERROR_PLAY);

ERROR_PLAY:
    mr = waveOutClose(hwo);
    MRCHECK(mr, waveOutClose, ERROR_OPEN);

ERROR_OPEN:
    delete [] pBufferBits;
    delete [] pwfx;

ERROR_READ:
    CloseHandle(hevDone);
    return mr;

}


BOOL
spPlayWav::ReadChunk(HANDLE fh, DWORD dwChunkType, PVOID * ppBuffer, DWORD * pdwSize, PDWORD pdwBytesLeft)
{ DWORD dwBytesRead;
  PVOID pBuffer;
  RIFF_CHUNKHEADER Chunk;

    if ((!pdwBytesLeft) || (*pdwBytesLeft <= 0) || (!pdwSize) || (!ppBuffer)) {
        RETAILMSG(1, (TEXT("Invalid parameter to ReadChunk()\r\n")));
        return FALSE;
    }

    // now scan for the format chunk
    while (*pdwBytesLeft > 0) {
        // now read the wave header (or what we hope is the wave header)
        if (! ReadFile(fh, &Chunk, sizeof(Chunk), &dwBytesRead, NULL) || dwBytesRead < sizeof(Chunk)) {
            RETAILMSG(1, (TEXT("Error reading chunk header\n")));
            return FALSE;
        }
        *pdwBytesLeft -= dwBytesRead;
        RETAILMSG(1, (TEXT("Chunk: \"%c%c%c%c\" size=0x%08x\r\n"), 
            (Chunk.dwCKID >>  0) & 0xff, 
            (Chunk.dwCKID >>  8) & 0xff, 
            (Chunk.dwCKID >> 16) & 0xff, 
            (Chunk.dwCKID >> 24) & 0xff, 
            Chunk.dwSize));
        if (Chunk.dwCKID == dwChunkType) {
            // found the desired chunk
            break;
        }
        // skip the data we don't know or care about...
        if (0xFFFFFFFF == SetFilePointer (fh, Chunk.dwSize, NULL, FILE_CURRENT)) {
            RETAILMSG(1,  (TEXT("Error setting file pointer while scanning for chunk\n")));
            return FALSE;
        }
        *pdwBytesLeft -= Chunk.dwSize;
    }
    // found the desired chunk.
    // allocate a buffer and read in the data
    pBuffer = new BYTE[Chunk.dwSize];
    if (pBuffer == NULL) {
        RETAILMSG(1, (TEXT("Unable to allocate chunk buffer\r\n")));
        return FALSE;
    }
    if (! ReadFile(fh, pBuffer, Chunk.dwSize, &dwBytesRead, NULL) || dwBytesRead < Chunk.dwSize) {
        delete [] pBuffer;
        RETAILMSG(1, (TEXT("Unable to read chunk data\r\n")));
        return FALSE;
    }
    *pdwBytesLeft -= dwBytesRead;
    *ppBuffer = pBuffer;
    *pdwSize = Chunk.dwSize;
    return TRUE;
}

MMRESULT
spPlayWav::ReadWaveFile(LPCTSTR pszFilename, PWAVEFORMATEX * ppWFX, PDWORD pdwBufferSize, PBYTE * ppBufferBits)
{ RIFF_FILEHEADER FileHeader;
  DWORD dwBytesRead;
  DWORD dwBufferSize;
  DWORD dwFormatSize;
  PBYTE pBufferBits = NULL;
  PWAVEFORMATEX pwfx = NULL;
  DWORD dwBytesInChunk;
  HANDLE fh;
  MMRESULT mmRet = MMSYSERR_ERROR;

    fh = CreateFile(pszFilename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if( fh == INVALID_HANDLE_VALUE ) {
        RETAILMSG(1, (TEXT("Error opening %s. Error code = 0x%08x\n"), pszFilename, GetLastError()));
        return mmRet;
    }

    // Read file and determine sound format
    // Start with RIFF header:

    if (! ReadFile(fh, &FileHeader, sizeof(FileHeader), &dwBytesRead, NULL) || dwBytesRead < sizeof(FileHeader)) {
        RETAILMSG(1, (TEXT("Error reading file header\n")));
        goto ERROR_EXIT;
    }

    if ( FileHeader.dwRiff != RIFF_FILE || FileHeader.dwWave != RIFF_WAVE) {
        RETAILMSG(1, (TEXT("Invalid wave file header\n")));
        goto ERROR_EXIT;
    }

    dwBytesInChunk = FileHeader.dwSize;

    // load the wave format
    if (! ReadChunk(fh, RIFF_FORMAT, (PVOID*) &pwfx, &dwFormatSize, &dwBytesInChunk)) {
        RETAILMSG(1, (TEXT("Unable to read format chunk\r\n")));
        goto ERROR_EXIT;
    }
    if (dwFormatSize < sizeof(PCMWAVEFORMAT)) {
        RETAILMSG(1, (TEXT("Format record too small\r\n")));
        goto ERROR_EXIT;
    }

    // load the wave data
    if (! ReadChunk(fh, RIFF_CHANNEL, (PVOID*) &pBufferBits, &dwBufferSize, &dwBytesInChunk)) {
        RETAILMSG(1, (TEXT("Unable to read format chunk\r\n")));
        goto ERROR_EXIT;
    }

    *ppWFX = pwfx;
    *pdwBufferSize = dwBufferSize;
    *ppBufferBits = pBufferBits;

    // Success
    mmRet = MMSYSERR_NOERROR;
    goto EXIT;

ERROR_EXIT:
    delete [] pBufferBits;
    delete [] pwfx;
EXIT:
    CloseHandle(fh);
    return mmRet;   
}



MMRESULT
spPlayWav::WriteWaveFile (LPCTSTR pszFilename, PWAVEFORMATEX pWFX, DWORD dwBufferSize, PBYTE pBufferBits)
{ RIFF_FILEHEADER FileHeader;
  RIFF_CHUNKHEADER WaveHeader;
  RIFF_CHUNKHEADER DataHeader;
  DWORD dwBytesWritten;
  HANDLE fh;
  MMRESULT mmRet = MMSYSERR_ERROR;

    
    // Fill in the file, wave and data headers
    WaveHeader.dwCKID = RIFF_FORMAT;
    WaveHeader.dwSize = sizeof(WAVEFORMATEX) + pWFX->cbSize;

    // the DataHeader chunk contains the audio data
    DataHeader.dwCKID = RIFF_CHANNEL;
    DataHeader.dwSize = dwBufferSize;

    // The FileHeader
    FileHeader.dwRiff = RIFF_FILE;
    FileHeader.dwWave = RIFF_WAVE;
    FileHeader.dwSize = sizeof(FileHeader.dwWave)+sizeof(WaveHeader) + WaveHeader.dwSize + sizeof(DataHeader) + DataHeader.dwSize;

    // Open wave file
    fh = CreateFile(pszFilename, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, 0, NULL);
    if( fh == INVALID_HANDLE_VALUE ) {
        RETAILMSG(1, (TEXT("Error opening %s. Error code = 0x%08x\n"), pszFilename, GetLastError()));
        return mmRet;
    }

    // write the riff file
    if (! WriteFile(fh, &FileHeader, sizeof(FileHeader), &dwBytesWritten, NULL)) {
        RETAILMSG(1, (TEXT("Error writing file header\r\n")));
        goto ERROR_EXIT;
    }

    // write the wave header
    if (! WriteFile(fh, &WaveHeader, sizeof(WaveHeader), &dwBytesWritten, NULL)) {
        RETAILMSG(1, (TEXT("Error writing wave header\r\n")));
        goto ERROR_EXIT;
    }

    // write the wave format
    if (! WriteFile(fh, pWFX, WaveHeader.dwSize, &dwBytesWritten, NULL)) {
        RETAILMSG(1, (TEXT("Error writing wave format\r\n")));
        goto ERROR_EXIT;
    }

    // write the data header
    if (! WriteFile(fh, &DataHeader, sizeof(DataHeader), &dwBytesWritten, NULL)) {
        RETAILMSG(1, (TEXT("Error writing PCM data header\r\n")));
        goto ERROR_EXIT;
    }

    // write the PCM data
    if (! WriteFile(fh, pBufferBits, DataHeader.dwSize, &dwBytesWritten, NULL)) {
        RETAILMSG(1, (TEXT("Error writing PCM data\r\n")));
        goto ERROR_EXIT;
    }

    // Success
    mmRet = MMSYSERR_NOERROR;

ERROR_EXIT:
    CloseHandle(fh);
    return mmRet;
}

