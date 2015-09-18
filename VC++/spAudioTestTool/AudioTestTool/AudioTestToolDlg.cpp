// AudioTestToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AudioTestTool.h"
#include "AudioTestToolDlg.h"

///#include "windev.h"
///#include "odm_ioctl.h"
#include "spPlayWav.h"
//#include <stdlib.h>
//#include "afxcmn.h"
//#include "afxwin.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CAudioTestToolDlg dialog

CAudioTestToolDlg::CAudioTestToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAudioTestToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAudioTestToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//DDX_Control(pDX, IDC_SLIDER_MIC_VOLUME, mSliderMicVol);
	DDX_Control(pDX, IDC_1ST_OUT_BALANCE_SLIDER, m_1stOutBalance);
	DDX_Control(pDX, IDC_1ST_OUT_FADER_SLIDER, m_1stOutFader);
	DDX_Control(pDX, IDC_1ST_OUT_LEVEL_PROGRESS, m_1stOutLevelProgress);
	DDX_Control(pDX, IDC_2ND_OUT_LEVEL_PROGRESS, m_2ndOutLevelProgress);

	DDX_Control(pDX, IDC_1ST_OUTPATH_SYSTEM, m_1stOutPathSystem);
	DDX_Control(pDX, IDC_1ST_OUTPATH_RADIO, m_1stOutPathRadio);
	DDX_Control(pDX, IDC_1ST_OUTPATH_DISK, m_1stOutPathDisk);
	DDX_Control(pDX, IDC_1ST_OUTPATH_AUXIN, m_1stOutPathAUXin);
	DDX_Control(pDX, IDC_2ND_OUTPATH_NAVI, m_2ndOutPathNavi);
	DDX_Control(pDX, IDC_2ND_OUTPATH_PHONE_RADIO, m_2ndOutPathPhone);
	DDX_Control(pDX, IDC_2ND_OUTPATH_OFF, m_2ndOutPathOff);

	DDX_Control(pDX, IDC_MUTE_FRONT_RIGHT_CHECK, m_MuteFrontRightChk);
	DDX_Control(pDX, IDC_MUTE_FRONT_LEFT_CHECK, m_MuteFrontLeftChk);
	DDX_Control(pDX, IDC_MUTE_REAR_RIGHT_CHECK, m_MuteRearRightChk);
	DDX_Control(pDX, IDC_MUTE_REAR_LEFT_CHECK, m_MuteRearLeftChk);
	DDX_Control(pDX, IDC_MUTE_QUICK_ALL_CHECK, m_MuteQuickAllChk);

	DDX_Control(pDX, IDC_WAV2ID_0_CHECK, m_Wav2ID0Chk);
	DDX_Control(pDX, IDC_WAV2ID_1_CHECK, m_Wav2ID1Chk);
	DDX_Control(pDX, IDC_WAV2ID_2_CHECK, m_Wav2ID2Chk);

	///DDX_Control(pDX, IDC_WAV2ID_0_CHECK, m_1stOutLevelStatic);
	///DDX_Control(pDX, IDC_WAV2ID_1_CHECK, m_2ndOutLevelStatic);
	///DDX_Control(pDX, IDC_WAV2ID_2_CHECK, m_1stOutBalanceStatic);

}

BEGIN_MESSAGE_MAP(CAudioTestToolDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_1ST_OUTPATH_SYSTEM, &CAudioTestToolDlg::OnBnClicked1stOutpathSystem)
	ON_BN_CLICKED(IDC_1ST_OUTPATH_AUXIN, &CAudioTestToolDlg::OnBnClicked1stOutpathAuxin)
	ON_BN_CLICKED(IDC_1ST_OUTPATH_DISK, &CAudioTestToolDlg::OnBnClicked1stOutpathDisk)
	ON_BN_CLICKED(IDC_1ST_OUTPATH_RADIO, &CAudioTestToolDlg::OnBnClicked1stOutpathRadio)
	ON_BN_CLICKED(IDC_2ND_OUTPATH_PHONE, &CAudioTestToolDlg::OnBnClicked2ndOutpathPhoneRadio)
	ON_BN_CLICKED(IDC_2ND_OUTPATH_NAVI, &CAudioTestToolDlg::OnBnClicked2ndOutpathNavi)
	ON_BN_CLICKED(IDC_2ND_OUTPATH_OFF, &CAudioTestToolDlg::OnBnClicked2ndOutpathOff)
	ON_BN_CLICKED(IDC_OUT_LEVEL_DOWN_BUTTON, &CAudioTestToolDlg::OnBnClickedOutLevelDownButton)
	ON_BN_CLICKED(IDC_OUT_LEVEL_UP_BUTTON, &CAudioTestToolDlg::OnBnClickedOutLevelUpButton)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_2ND_OUT_LEVEL_PROGRESS, &CAudioTestToolDlg::OnNMCustomdraw2ndOutLevelProgress)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_1ST_OUT_BALANCE_SLIDER, &CAudioTestToolDlg::OnNMCustomdraw1stOutBalanceSlider)
	ON_BN_CLICKED(IDC_EXIT_QUIT_BUTTON, &CAudioTestToolDlg::OnBnClickedExitQuitButton)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_1ST_OUT_LEVEL_PROGRESS, &CAudioTestToolDlg::OnNMCustomdraw1stOutLevelProgress)
	ON_BN_CLICKED(IDC_MUTE_FRONT_RIGHT_CHECK, &CAudioTestToolDlg::OnBnClickedMuteFrontRightCheck)
	ON_BN_CLICKED(IDC_MUTE_FRONT_LEFT_CHECK, &CAudioTestToolDlg::OnBnClickedMuteFrontLeftCheck)
	ON_BN_CLICKED(IDC_MUTE_REAR_RIGHT_CHECK, &CAudioTestToolDlg::OnBnClickedMuteRearRightCheck)
	ON_BN_CLICKED(IDC_MUTE_REAR_LEFT_CHECK, &CAudioTestToolDlg::OnBnClickedMuteRearLeftCheck)
	ON_BN_CLICKED(IDC_MUTE_QUICK_ALL_CHECK, &CAudioTestToolDlg::OnBnClickedMuteQuickAllCheck)
	ON_BN_CLICKED(IDC_1ST_OUT_LEVEL_BUTTON, &CAudioTestToolDlg::OnBnClicked1stOutLevelButton)
	ON_BN_CLICKED(IDC_2ND_OUT_LEVEL_BUTTON, &CAudioTestToolDlg::OnBnClicked2ndOutLevelButton)
	ON_BN_CLICKED(IDC_1ST_OUT_BALANCE_BUTTON, &CAudioTestToolDlg::OnBnClicked1stOutBalanceButton)
	ON_BN_CLICKED(IDC_OUT_LEVEL_DOWN_BUTTON2, &CAudioTestToolDlg::OnBnClickedOutLevelDownButton2)
	ON_BN_CLICKED(IDC_OUT_LEVEL_UP_BUTTON2, &CAudioTestToolDlg::OnBnClickedOutLevelUpButton2)
	ON_BN_CLICKED(IDC_2ND_OUTPATH_PHONE_RADIO, &CAudioTestToolDlg::OnBnClicked2ndOutpathPhoneRadio)
	ON_BN_CLICKED(IDC_WAV2ID_0_CHECK, &CAudioTestToolDlg::OnBnClickedWav2id0Check)
	ON_BN_CLICKED(IDC_WAV2ID_1_CHECK, &CAudioTestToolDlg::OnBnClickedWav2id1Check)
	ON_BN_CLICKED(IDC_WAV2ID_2_CHECK, &CAudioTestToolDlg::OnBnClickedWav2id2Check)
	ON_BN_CLICKED(IDC_1ST_OUT_FADER_BUTTON, &CAudioTestToolDlg::OnBnClicked1stOutFaderButton)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_1ST_OUT_FADER_SLIDER, &CAudioTestToolDlg::OnNMCustomdraw1stOutFaderSlider)
END_MESSAGE_MAP()


// CAudioTestToolDlg message handlers

BOOL CAudioTestToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	m_hMMlib = 0;
	m_1stOutPathType = emOPsystem;
	m_2ndOutPathType = emOPoff;
	///m_CtrlTargetItem = emCTInone;
	m_CtrlTargetItem = emCTI1stOutLevel;

	m_1stOutputLevel = 0;
	m_2ndOutputLevel = 0;
	m_LROutputBalance = 0;
	m_FROutputBalance = 0;

	m_MuteFrontRightChk.SetRedraw();
	m_MuteFrontLeftChk.SetRedraw();

	InitSetting();

    UpdateSetting();

	///spPlayWav* pPWav = new spPlayWav( TEXT("\\wavplay_id0.wav") );
	///pPWav->SetDevice( 0 );
	///pPWav->Play();

	///spPlayWav PWav1 = spPlayWav( TEXT("\\wavplay_id0.wav") );
	///PWav1.SetDevice( 0 );
	///PWav1.Play();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CAudioTestToolDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_AUDIOTESTTOOL_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_AUDIOTESTTOOL_DIALOG));
	}
}
#endif


BOOL CAudioTestToolDlg::UpdateSetting()
{
    
    NKDbgPrintfW (L"UpdateSetting +++\r\n");





	return TRUE;
}


BOOL CAudioTestToolDlg::allocateMMlib()
{
	BOOL bRet = FALSE;
	
	m_hMMlib = MMlib_initCaller();
	if( m_hMMlib > 0 )
		bRet = TRUE;
	else
	{
		m_hMMlib = 0;
		::MessageBox( NULL, TEXT("allocate MMlib fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );
	}

	return bRet;
}


BOOL CAudioTestToolDlg::releaseMMlib()
{
	BOOL bRet = TRUE;

	if( 0 != m_hMMlib )
	{
		MMlib_deinitCaller( m_hMMlib );
	}

	return bRet;
}


BOOL CAudioTestToolDlg::InitSetting()
{
	BOOL bRet = FALSE;


	if( allocateMMlib() )	///get MMlib
	{
		m_2ndOutPathOff.SetCheck( 1 );

		SetDlgItemText( IDC_1ST_OUT_LEVEL_STATIC, _T("0"));
		SetDlgItemText( IDC_2ND_OUT_LEVEL_STATIC, _T("0"));
		SetDlgItemText( IDC_1ST_OUT_BALANCE_STATIC, _T("0"));
		SetDlgItemText( IDC_1ST_OUT_FADER_STATIC, _T("0"));

		m_1stOutBalance.SetRange( -127, 127 );
		m_1stOutBalance.SetTic( 10 );
		m_1stOutBalance.SetPos( 0 );
		m_1stOutBalance.SetTicFreq( 20 );

		m_1stOutFader.SetRange( -127, 127 );
		m_1stOutFader.SetTic( 10 );
		m_1stOutFader.SetPos( 0 );
		m_1stOutFader.SetTicFreq( 20 );

		m_1stOutLevelProgress.SetRange( 0, 63 );
		m_1stOutLevelProgress.SetPos( 0 );
		m_1stOutLevelProgress.SetStep( 1 );

		m_2ndOutLevelProgress.SetRange( 0, 63 );
		m_2ndOutLevelProgress.SetPos( 0 );
		m_2ndOutLevelProgress.SetStep( 1 );

		m_MuteFrontRightChk.SetCheck( 0 );
		m_MuteFrontLeftChk.SetCheck( 0 );
		m_MuteRearRightChk.SetCheck( 0 );
		m_MuteRearLeftChk.SetCheck( 0 );
		m_MuteQuickAllChk.SetCheck( 0 );

		bRet = TRUE;
	}

	return bRet;
}


void CAudioTestToolDlg::Ctrl1stOutputLevel( BOOL onUP, BOOL onFast )
{
	MMlibVOLUME outvalue = m_1stOutputLevel;
	MMlibVOLUME offset = 0;

	if(	onFast )
		offset = 10;
	else
		offset = 1;
	
	if( onUP )	///go up
	{
		if( 63 != outvalue )
			outvalue = outvalue + offset;
		if( outvalue > 63 )
			outvalue = 63;
	}
	else
	{
		if( 0 != outvalue )
			outvalue = outvalue - offset;
		if( outvalue > 63 )
			outvalue = 0;
	}

	NKDbgPrintfW(L"Ctrl1stOutputLevel %d\r\n", outvalue );
	///if( 0 == MMlib_volumesetFrontRear( m_hMMlib, outvalue ) )
	if( 0 == MMlib_volumesetMainFunction( m_hMMlib, outvalue ) )
	{
		m_1stOutputLevel = outvalue;
		m_1stOutLevelProgress.SetPos( outvalue );
		wsprintf( m_szString, TEXT("%d"), outvalue );
		SetDlgItemText( IDC_1ST_OUT_LEVEL_STATIC, m_szString );
	}
	else
		::MessageBox( NULL, TEXT("MMlib_volumesetFrontRear fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );

}

void CAudioTestToolDlg::Ctrl2ndOutputLevel( BOOL onUP, BOOL onFast )
{
	MMlibVOLUME outvalue = m_2ndOutputLevel;
	MMlibVOLUME offset = 0;

	if(	onFast )
		offset = 10;
	else
		offset = 1;
	
	if( onUP )	///go up
	{
		if( 63 != outvalue )
			outvalue = outvalue + offset;
		if( outvalue > 63 )
			outvalue = 63;
	}
	else
	{
		if( 0 != outvalue )
			outvalue = outvalue - offset;
		if( outvalue > 63 )
			outvalue = 0;
	}

	NKDbgPrintfW(L"Ctrl2ndOutputLevel %d\r\n", outvalue );
	///if( 0 == MMlib_volumesetFrontRear( m_hMMlib, outvalue ) )
	if( 0 == MMlib_volumesetSecondFunction( m_hMMlib, outvalue ) )
	{
		m_2ndOutputLevel = outvalue;
		m_2ndOutLevelProgress.SetPos( outvalue ); 
		wsprintf( m_szString, TEXT("%d"), outvalue );
		SetDlgItemText( IDC_2ND_OUT_LEVEL_STATIC, m_szString );
	}
	else
		::MessageBox( NULL, TEXT("MMlib_volumesetFrontRear fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );

}

void CAudioTestToolDlg::CtrlLROutputBalance( BOOL onRIGHT, BOOL onFast )
{
	MMlibVOLBALANCE outvalue = m_LROutputBalance;
	MMlibVOLBALANCE offset = 0;

	if(	onFast )
		offset = 10;
	else
		offset = 1;
	
	if( onRIGHT )	///go right
	{
		if( 127 != outvalue )
			outvalue = outvalue + offset;

		if( onFast )
			outvalue = 127;
	}
	else
	{
		if( -127 != outvalue )
			outvalue = outvalue - offset;
		if( onFast )
			outvalue = -127;
	}


	NKDbgPrintfW(L"CtrlLROutputBalance %d\r\n", outvalue );
	if( 0 == MMlib_volumesetLRbalance( m_hMMlib, outvalue ) )
	{
		m_LROutputBalance = outvalue;
		m_1stOutBalance.SetPos( outvalue );
		wsprintf( m_szString, TEXT("%d"), outvalue );
		SetDlgItemText( IDC_1ST_OUT_BALANCE_STATIC, m_szString );
	}
	else
		::MessageBox( NULL, TEXT("MMlib_volumesetLRbalance fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );

}

void CAudioTestToolDlg::CtrlFROutputBalance( BOOL onREAR, BOOL onFast )
{
	MMlibVOLBALANCE outvalue = m_FROutputBalance;
	MMlibVOLBALANCE offset = 0;

	if(	onFast )
		offset = 10;
	else
		offset = 1;
	
	if( onREAR )	///go right
	{
		if( 127 != outvalue )
			outvalue = outvalue + offset;

		if( onFast )
			outvalue = 127;
	}
	else
	{
		if( -127 != outvalue )
			outvalue = outvalue - offset;
		if( onFast )
			outvalue = -127;
	}


	NKDbgPrintfW(L"CtrlFROutputBalance %d\r\n", outvalue );
	if( 0 == MMlib_volumesetFader( m_hMMlib, outvalue ) )
	{
		m_LROutputBalance = outvalue;
		m_1stOutFader.SetPos( outvalue );
		wsprintf( m_szString, TEXT("%d"), outvalue );
		SetDlgItemText( IDC_1ST_OUT_FADER_STATIC, m_szString );
	}
	else
		::MessageBox( NULL, TEXT("MMlib_volumesetFader fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );

}

BOOL CAudioTestToolDlg::Ctrl1stOutPath( emOutPathType toPathType )
{
	BOOL bRet = FALSE;

	switch( toPathType )
	{
		case emOPsystem:
			if( 0 == MMlib_pathsetHostAudio( m_hMMlib ) )
				bRet = TRUE;
			else
				::MessageBox( NULL, TEXT("MMlib_pathsetHostAudio fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );
			break;

		case emOPradio:
			if( 0 == MMlib_pathsetRadioAudioA( m_hMMlib ) )
				bRet = TRUE;
			else
				::MessageBox( NULL, TEXT("MMlib_pathsetRadioAudioA fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );
			break;

		case emOPdisk:
			if( 0 == MMlib_pathsetDiskAudioA( m_hMMlib ) )
				bRet = TRUE;
			else
				::MessageBox( NULL, TEXT("MMlib_pathsetDiskAudioA fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );
			break;

		case emOPauxin:
			if( 0 == MMlib_pathsetAUXAudioA( m_hMMlib ) )
				bRet = TRUE;
			else
				::MessageBox( NULL, TEXT("MMlib_pathsetAUXAudioA fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );
			break;

		default:
			break;
	}

	return bRet;
}

BOOL CAudioTestToolDlg::Ctrl2ndOutPath( emOutPathType toPathType )
{
	BOOL bRet = FALSE;

	switch( toPathType )
	{
		case emOPnavi:
			if( 0 == MMlib_pathsetNaviAudioD( m_hMMlib ) )
				bRet = TRUE;
			else
				::MessageBox( NULL, TEXT("MMlib_pathsetNaviAudioD fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );
			break;

		case emOPphone:
			if( 0 == MMlib_pathsetPhoneAudioD( m_hMMlib ) )
				bRet = TRUE;
			else
				::MessageBox( NULL, TEXT("MMlib_pathsetPhoneAudioD fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );
			break;

		case emOPoff:
			if( 0 == MMlib_pathsetNaviAudioD( m_hMMlib ) )
				bRet = TRUE;
			else
				::MessageBox( NULL, TEXT("MMlib_pathsetNaviAudioD fail !! "), TEXT("Warning"), MB_OK|MB_TOPMOST );
			break;

		default:
			break;
	}

	return bRet;
}


void CAudioTestToolDlg::Clr1stOutPathSet()
{
	m_1stOutPathSystem.SetCheck( 0 );
	m_1stOutPathRadio.SetCheck( 0 );
	m_1stOutPathDisk.SetCheck( 0 );
	m_1stOutPathAUXin.SetCheck( 0 );
}

void CAudioTestToolDlg::Clr2ndOutPathSet()
{
	m_2ndOutPathNavi.SetCheck( 0 );
	m_2ndOutPathPhone.SetCheck( 0 );
	m_2ndOutPathOff.SetCheck( 0 );
}



void CAudioTestToolDlg::OnBnClicked1stOutpathSystem()
{
	// TODO: Add your control notification handler code here
	if( m_1stOutPathType != emOPsystem )
	{
		if( Ctrl1stOutPath( emOPsystem ) )
		{
			m_1stOutPathType = emOPsystem;
			Clr1stOutPathSet();
			m_1stOutPathSystem.SetCheck( 1 );
		}
	}
}

void CAudioTestToolDlg::OnBnClicked1stOutpathAuxin()
{
	// TODO: Add your control notification handler code here
	if( m_1stOutPathType != emOPauxin )
	{
		if( Ctrl1stOutPath( emOPauxin ) )
		{
			m_1stOutPathType = emOPauxin;
			Clr1stOutPathSet();
			m_1stOutPathAUXin.SetCheck( 1 );
		}
	}
}

void CAudioTestToolDlg::OnBnClicked1stOutpathDisk()
{
	// TODO: Add your control notification handler code here
	if( m_1stOutPathType != emOPdisk )
	{
		if( Ctrl1stOutPath( emOPdisk ) )
		{
			m_1stOutPathType = emOPdisk;
			Clr1stOutPathSet();
			m_1stOutPathDisk.SetCheck( 1 );
		}
	}
}

void CAudioTestToolDlg::OnBnClicked1stOutpathRadio()
{
	// TODO: Add your control notification handler code here
	if( m_1stOutPathType != emOPradio )
	{
		if( Ctrl1stOutPath( emOPradio ) )
		{
			m_1stOutPathType = emOPradio;
			Clr1stOutPathSet();
			m_1stOutPathRadio.SetCheck( 1 );
		}
	}
}

void CAudioTestToolDlg::OnBnClicked2ndOutpathNavi()
{
	// TODO: Add your control notification handler code here
	if( m_2ndOutPathType != emOPnavi )
	{
		if( Ctrl2ndOutPath( emOPnavi ) )
		{
			m_2ndOutPathType = emOPnavi;
			Clr2ndOutPathSet();
			m_2ndOutPathNavi.SetCheck( 1 );
		}
	}
}

/*
void CAudioTestToolDlg::OnBnClicked2ndOutpathPhone()
{
	// TODO: Add your control notification handler code here
}
*/

void CAudioTestToolDlg::OnBnClicked2ndOutpathPhoneRadio()
{
	// TODO: Add your control notification handler code here
	if( m_2ndOutPathType != emOPphone )
	{
		if( Ctrl2ndOutPath( emOPphone ) )
		{
			m_2ndOutPathType = emOPphone;
			Clr2ndOutPathSet();
			m_2ndOutPathPhone.SetCheck( 1 );
		}
	}

}

void CAudioTestToolDlg::OnBnClicked2ndOutpathOff()
{
	// TODO: Add your control notification handler code here
	if( m_2ndOutPathType != emOPoff )
	{
		if( Ctrl2ndOutPath( emOPoff ) )
		{
			m_2ndOutPathType = emOPoff;
			Clr2ndOutPathSet();
			m_2ndOutPathOff.SetCheck( 1 );
		}
	}
}

void CAudioTestToolDlg::OnBnClickedOutLevelDownButton()
{
	// TODO: Add your control notification handler code here
	NKDbgPrintfW(L"OnBnClickedOutLevelDownButton %d\r\n", 0 );
	switch( m_CtrlTargetItem )
	{
		case emCTInone:
			break;
		
		case emCTI1stOutLevel:
			Ctrl1stOutputLevel( FALSE, FALSE );
			break;

		case emCTI2ndOutLevel:
			Ctrl2ndOutputLevel( FALSE, FALSE );
			break;

		case emCTILROutBalance:
			CtrlLROutputBalance( FALSE, FALSE );
			break;

		case emCTIFROutBalance:
			CtrlFROutputBalance( FALSE, FALSE );
			break;

		default:
			break;
	}
}

void CAudioTestToolDlg::OnBnClickedOutLevelUpButton()
{
	// TODO: Add your control notification handler code here
	NKDbgPrintfW(L"OnBnClickedOutLevelUpButton %d\r\n", 1 );
	switch( m_CtrlTargetItem )
	{
		case emCTInone:
			break;
		
		case emCTI1stOutLevel:
			Ctrl1stOutputLevel( TRUE, FALSE );
			break;

		case emCTI2ndOutLevel:
			Ctrl2ndOutputLevel( TRUE, FALSE );
			break;

		case emCTILROutBalance:
			CtrlLROutputBalance( TRUE, FALSE );
			break;

		case emCTIFROutBalance:
			CtrlFROutputBalance( TRUE, FALSE );
			break;

		default:
			break;
	}

}

void CAudioTestToolDlg::OnBnClickedOutLevelDownButton2()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	NKDbgPrintfW(L"OnBnClickedOutLevelDownButton2 %d\r\n", 0 );
	switch( m_CtrlTargetItem )
	{
		case emCTInone:
			break;
		
		case emCTI1stOutLevel:
			Ctrl1stOutputLevel( FALSE, TRUE );
			break;

		case emCTI2ndOutLevel:
			Ctrl2ndOutputLevel( FALSE, TRUE );
			break;

		case emCTILROutBalance:
			CtrlLROutputBalance( FALSE, TRUE );
			break;

		case emCTIFROutBalance:
			CtrlFROutputBalance( FALSE, TRUE );
			break;

		default:
			break;
	}

}

void CAudioTestToolDlg::OnBnClickedOutLevelUpButton2()
{
	// TODO: Add your control notification handler code here
	NKDbgPrintfW(L"OnBnClickedOutLevelUpButton2 %d\r\n", 1 );
	switch( m_CtrlTargetItem )
	{
		case emCTInone:
			break;
		
		case emCTI1stOutLevel:
			Ctrl1stOutputLevel( TRUE, TRUE );
			break;

		case emCTI2ndOutLevel:
			Ctrl2ndOutputLevel( TRUE, TRUE );
			break;

		case emCTILROutBalance:
			CtrlLROutputBalance( TRUE, TRUE );
			break;

		case emCTIFROutBalance:
			CtrlFROutputBalance( TRUE, TRUE );
			break;

		default:
			break;
	}

}



void CAudioTestToolDlg::OnNMCustomdraw2ndOutLevelProgress(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	///m_CtrlTargetItem = emCTI2ndOutLevel;
	NKDbgPrintfW(L"OnNMCustomdraw2ndOutLevelProgress %d\r\n", 0 );
}

void CAudioTestToolDlg::OnStnClickedStatic2ndOutLevel()
{
	// TODO: Add your control notification handler code here
	m_CtrlTargetItem = emCTI2ndOutLevel;
	NKDbgPrintfW(L"OnStnClickedStatic2ndOutLevel %d\r\n", 0 );
}

void CAudioTestToolDlg::OnStnClickedStatic1stOutLevel()
{
	// TODO: Add your control notification handler code here
	m_CtrlTargetItem = emCTI1stOutLevel;
	NKDbgPrintfW(L"OnStnClickedStatic1stOutLevel %d\r\n", 0 );
}

void CAudioTestToolDlg::OnStnClickedStatic1stOutBalance()
{
	// TODO: Add your control notification handler code here
	m_CtrlTargetItem = emCTILROutBalance;
	NKDbgPrintfW(L"OnStnClickedStatic1stOutBalance %d\r\n", 0 );
}

void CAudioTestToolDlg::OnNMCustomdraw1stOutBalanceSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	///m_CtrlTargetItem = emCTILROutBalance;
	NKDbgPrintfW(L"OnNMCustomdraw1stOutBalanceSlider %d\r\n", 0 );
}

void CAudioTestToolDlg::OnBnClickedExitQuitButton()
{
	// TODO: Add your control notification handler code here
	releaseMMlib();	///release MMlib

	// same as double-clicking on main window close box
	ASSERT(AfxGetApp()->m_pMainWnd != NULL);
	AfxGetApp()->m_pMainWnd->SendMessage(WM_CLOSE);
}

void CAudioTestToolDlg::OnNMCustomdraw1stOutLevelProgress(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	///m_CtrlTargetItem = emCTI1stOutLevel;
	NKDbgPrintfW(L"OnNMCustomdraw1stOutLevelProgress %d\r\n", 0 );
}


BOOL CAudioTestToolDlg::CtrlMute()
{
	BOOL bRet = FALSE;


	if(	m_MuteFrontRightChk.GetCheck() )
		MMlib_mutesetFrontRight( TRUE );
	else
		MMlib_mutesetFrontRight( FALSE );

	if(	m_MuteFrontLeftChk.GetCheck() )
		MMlib_mutesetFrontLeft( TRUE );
	else
		MMlib_mutesetFrontLeft( FALSE );

	if(	m_MuteRearRightChk.GetCheck() )
		MMlib_mutesetRearRight( TRUE );
	else
		MMlib_mutesetRearRight( FALSE );

	if(	m_MuteRearLeftChk.GetCheck() )
		MMlib_mutesetRearLeft( TRUE );
	else
		MMlib_mutesetRearLeft( FALSE );

	if(	m_MuteQuickAllChk.GetCheck() )
		MMlib_mutesetQuick( TRUE );
	else
		MMlib_mutesetQuick( FALSE );

	return bRet;
}

void CAudioTestToolDlg::OnBnClickedMuteFrontRightCheck()
{
	// TODO: Add your control notification handler code here
	if( m_MuteFrontRightChk.GetCheck() )
	{	///un-check it
		m_MuteFrontRightChk.SetCheck( 0 );
	}
	else
	{	///check it
		m_MuteFrontRightChk.SetCheck( 1 );
	}

	CtrlMute();
}

void CAudioTestToolDlg::OnBnClickedMuteFrontLeftCheck()
{
	// TODO: Add your control notification handler code here
	if( m_MuteFrontLeftChk.GetCheck() )
	{	///un-check it
		m_MuteFrontLeftChk.SetCheck( 0 );
	}
	else
	{	///check it
		m_MuteFrontLeftChk.SetCheck( 1 );
	}

	CtrlMute();
}

void CAudioTestToolDlg::OnBnClickedMuteRearRightCheck()
{
	// TODO: Add your control notification handler code here
	if( m_MuteRearRightChk.GetCheck() )
	{	///un-check it
		m_MuteRearRightChk.SetCheck( 0 );
	}
	else
	{	///check it
		m_MuteRearRightChk.SetCheck( 1 );
	}

	CtrlMute();
}

void CAudioTestToolDlg::OnBnClickedMuteRearLeftCheck()
{
	// TODO: Add your control notification handler code here
	if( m_MuteRearLeftChk.GetCheck() )
	{	///un-check it
		m_MuteRearLeftChk.SetCheck( 0 );
	}
	else
	{	///check it
		m_MuteRearLeftChk.SetCheck( 1 );
	}

	CtrlMute();
}

void CAudioTestToolDlg::OnBnClickedMuteQuickAllCheck()
{
	// TODO: Add your control notification handler code here
	if( m_MuteQuickAllChk.GetCheck() )
	{	///un-check it
		m_MuteQuickAllChk.SetCheck( 0 );
	}
	else
	{	///check it
		m_MuteQuickAllChk.SetCheck( 1 );
	}

	CtrlMute();
}

void CAudioTestToolDlg::OnBnClicked1stOutLevelButton()
{
	// TODO: Add your control notification handler code here
	m_CtrlTargetItem = emCTI1stOutLevel;
	NKDbgPrintfW(L"OnBnClicked1stOutLevelButton %d\r\n", emCTI1stOutLevel );
}

void CAudioTestToolDlg::OnBnClicked2ndOutLevelButton()
{
	// TODO: Add your control notification handler code here
	m_CtrlTargetItem = emCTI2ndOutLevel;
	NKDbgPrintfW(L"OnBnClicked2ndOutLevelButton %d\r\n", emCTI2ndOutLevel );
}

void CAudioTestToolDlg::OnBnClicked1stOutBalanceButton()
{
	// TODO: Add your control notification handler code here
	m_CtrlTargetItem = emCTILROutBalance;
	NKDbgPrintfW(L"OnBnClicked1stOutBalanceButton %d\r\n", emCTILROutBalance );
}

void CAudioTestToolDlg::OnBnClicked1stOutFaderButton()
{
	// TODO: Add your control notification handler code here
	m_CtrlTargetItem = emCTIFROutBalance;
	NKDbgPrintfW(L"OnBnClicked1stOutFaderButton %d\r\n", emCTILROutBalance );
}

void CAudioTestToolDlg::OnNMCustomdraw1stOutFaderSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}



#define		WAVFILE0			TEXT("\\Storage Card\\C0_16_48_Test.wav")
#define		WAVFILE1			TEXT("\\Storage Card\\C1_16_48_Test.wav")
#define		WAVFILE2			TEXT("\\Storage Card\\C2_16_48_Test.wav")
#define		WAVFILE3			TEXT("\\Storage Card\\C3_16_48_Test.wav")
#define		WAVFILE4			TEXT("\\Storage Card\\C4_16_48_Test.wav")
#define		WAVFILE5			TEXT("\\Storage Card\\C5_16_48_Test.wav")
#define		WAVFILE6			TEXT("\\Storage Card\\C6_16_48_Test.wav")
#define		WAVFILE7			TEXT("\\Storage Card\\C7_16_48_Test.wav")
#define		WAVFILE8			TEXT("\\Storage Card\\C8_16_48_Test.wav")



void CAudioTestToolDlg::OnBnClickedWav2id0Check()
{
	// TODO: Add your control notification handler code here
	if( m_Wav2ID0Chk.GetCheck() )
	{	///un-check it
		m_Wav2ID0Chk.SetCheck( 0 );
	}
	else
	{	///check it
		m_Wav2ID0Chk.SetCheck( 1 );

		spPlayWav PWav1 = spPlayWav();
		PWav1.SetDevice( 0 );
		///PWav1.Play( TEXT("startup.wav") );
		///PWav1.Play( WAVFILE0 );
		///PWav1.Play( WAVFILE1 );
		///PWav1.Play( WAVFILE2 );
		PWav1.Play( WAVFILE3 );
		PWav1.Play( WAVFILE4 );
		PWav1.Play( WAVFILE5 );
		PWav1.Play( WAVFILE6 );
		PWav1.Play( WAVFILE7 );
		PWav1.Play( WAVFILE8 );

		m_Wav2ID0Chk.SetCheck( 0 );
	}
}

void CAudioTestToolDlg::OnBnClickedWav2id1Check()
{
	// TODO: Add your control notification handler code here
	if( m_Wav2ID1Chk.GetCheck() )
	{	///un-check it
		m_Wav2ID1Chk.SetCheck( 0 );
	}
	else
	{	///check it
		m_Wav2ID1Chk.SetCheck( 1 );

		spPlayWav PWav1 = spPlayWav();
		PWav1.SetDevice( 1 );
		///PWav1.Play( TEXT("startup.wav") );
		///PWav1.Play( WAVFILE0 );
		///PWav1.Play( WAVFILE1 );
		///PWav1.Play( WAVFILE2 );
		PWav1.Play( WAVFILE3 );
		PWav1.Play( WAVFILE4 );
		PWav1.Play( WAVFILE5 );
		PWav1.Play( WAVFILE6 );
		PWav1.Play( WAVFILE7 );
		PWav1.Play( WAVFILE8 );

		m_Wav2ID1Chk.SetCheck( 0 );
	}

}

void CAudioTestToolDlg::OnBnClickedWav2id2Check()
{
	// TODO: Add your control notification handler code here
	if( m_Wav2ID2Chk.GetCheck() )
	{	///un-check it
		m_Wav2ID2Chk.SetCheck( 0 );
	}
	else
	{	///check it
		m_Wav2ID2Chk.SetCheck( 1 );

		spPlayWav PWav1 = spPlayWav();
		PWav1.SetDevice( 2 );
		///PWav1.Play( TEXT("startup.wav") );
		///PWav1.Play( WAVFILE0 );
		///PWav1.Play( WAVFILE1 );
		///PWav1.Play( WAVFILE2 );
		PWav1.Play( WAVFILE3 );
		PWav1.Play( WAVFILE4 );
		PWav1.Play( WAVFILE5 );
		PWav1.Play( WAVFILE6 );
		PWav1.Play( WAVFILE7 );
		PWav1.Play( WAVFILE8 );

		m_Wav2ID2Chk.SetCheck( 0 );
	}

}

