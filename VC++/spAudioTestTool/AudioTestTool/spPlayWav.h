//
//
//

#include <windows.h>


#define MRCHECK(r,str,label)\
    if ((r != MMSYSERR_NOERROR)) { RETAILMSG(1, (TEXT(#str) TEXT(" failed. mr=%08x\r\n"), r)); mr = r; goto label;}

///#ifndef UINT
///typedef		unsigned int	UINT;
///#endif


// -----------------------------------------------------------------------------
//                              FileHeader
// -----------------------------------------------------------------------------
typedef struct
{
   DWORD   dwRiff;     // Type of file header.
   DWORD   dwSize;     // Size of file header.
   DWORD   dwWave;     // Type of wave.
} RIFF_FILEHEADER, *PRIFF_FILEHEADER;


// -----------------------------------------------------------------------------
//                              ChunkHeader
// -----------------------------------------------------------------------------
typedef struct
{
   DWORD   dwCKID;        // Type Identification for current chunk header.
   DWORD   dwSize;        // Size of current chunk header.
} RIFF_CHUNKHEADER, *PRIFF_CHUNKHEADER;

/*  Chunk Types  
*/
#define RIFF_FILE       mmioFOURCC('R','I','F','F')
#define RIFF_WAVE       mmioFOURCC('W','A','V','E')
#define RIFF_FORMAT     mmioFOURCC('f','m','t',' ')
#define RIFF_CHANNEL    mmioFOURCC('d','a','t','a')



class spPlayWav
{
public:

	spPlayWav();
	spPlayWav( LPCTSTR pszWavFile );
	
	~spPlayWav();

/// Implementation
protected:
	MMRESULT	mr;
	DWORD dwBufferSize;
	PBYTE pBufferBits/* = NULL*/;
	PWAVEFORMATEX pwfx/* = NULL*/;
	DWORD dwSlop;
	DWORD dwWait;
	DWORD dwDuration;
	HANDLE hevDone;
	UINT uiID;
	LPCTSTR pszFilename;
	HWAVEOUT hwo;
	WAVEHDR hdr;

	WCHAR				m_szNameString[128];

	BOOL ReadChunk( HANDLE fh, DWORD dwChunkType, PVOID * ppBuffer, DWORD * pdwSize, PDWORD pdwBytesLeft );
	MMRESULT ReadWaveFile( LPCTSTR pszFilename, PWAVEFORMATEX * ppWFX, PDWORD pdwBufferSize, PBYTE * ppBufferBits );
	MMRESULT WriteWaveFile( LPCTSTR pszFilename, PWAVEFORMATEX pWFX, DWORD dwBufferSize, PBYTE pBufferBits );
	
public:
	void SetDevice( UINT uID );
	MMRESULT Play();
	MMRESULT Play( LPCTSTR pszWavFile );

};

