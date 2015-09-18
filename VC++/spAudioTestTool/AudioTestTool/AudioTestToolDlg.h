// AudioTestToolDlg.h : header file
//

#pragma once

#include "afxcmn.h"
#include "afxwin.h"

/// include MMlib
#include "MMlib_header.h"



// CAudioTestToolDlg dialog
class CAudioTestToolDlg : public CDialog
{
// Construction
public:
	CAudioTestToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_AUDIOTESTTOOL_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:

	CSliderCtrl			m_1stOutBalance;
	CSliderCtrl			m_1stOutFader;
	CProgressCtrl		m_1stOutLevelProgress; 
	CProgressCtrl		m_2ndOutLevelProgress;
	CButton				m_1stOutPathSystem;
	CButton				m_1stOutPathRadio;
	CButton				m_1stOutPathDisk;
	CButton				m_1stOutPathAUXin;
	CButton				m_2ndOutPathNavi;
	CButton				m_2ndOutPathPhone;
	CButton				m_2ndOutPathOff;
	CButton				m_MuteFrontRightChk;
	CButton				m_MuteFrontLeftChk;
	CButton				m_MuteRearRightChk;
	CButton				m_MuteRearLeftChk;
	CButton				m_MuteQuickAllChk;

	CButton				m_Wav2ID0Chk;
	CButton				m_Wav2ID1Chk;
	CButton				m_Wav2ID2Chk;

	///CStatic				m_1stOutLevelStatic;
	///CStatic				m_2ndOutLevelStatic;
	///CStatic				m_1stOutBalanceStatic;

	WCHAR				m_szString[128];

	HANDLE m_hMMlib;

    BOOL UpdateSetting();
	BOOL allocateMMlib();
	BOOL releaseMMlib();
	BOOL InitSetting();

	enum emOutPathType {
		emOPoff = 0,
		emOPsystem,
		emOPradio,
		emOPdisk,
		emOPauxin,
		emOPnavi,
		emOPphone
	};

	emOutPathType m_1stOutPathType;
	emOutPathType m_2ndOutPathType;

	void Clr1stOutPathSet();
	void Clr2ndOutPathSet();

	enum emCtrlTargetItem {
		emCTInone = 0,
		emCTI1stOutLevel,
		emCTI2ndOutLevel,
		emCTILROutBalance,
		emCTIFROutBalance
	};

	emCtrlTargetItem m_CtrlTargetItem;

	MMlibVOLUME m_1stOutputLevel;
	void Ctrl1stOutputLevel( BOOL onUP, BOOL onFast );

	MMlibVOLUME m_2ndOutputLevel;
	void Ctrl2ndOutputLevel( BOOL onUP, BOOL onFast );

	MMlibVOLBALANCE m_LROutputBalance;
	void CtrlLROutputBalance( BOOL onRIGHT, BOOL onFast );

	MMlibVOLBALANCE m_FROutputBalance;
	void CtrlFROutputBalance( BOOL onRIGHT, BOOL onFast );

	BOOL Ctrl1stOutPath( emOutPathType toPathType );
	BOOL Ctrl2ndOutPath( emOutPathType toPathType );

	BOOL CtrlMute();

	afx_msg void OnBnClicked1stOutpathSystem();
	afx_msg void OnBnClicked1stOutpathAuxin();
	afx_msg void OnBnClicked1stOutpathDisk();
	afx_msg void OnBnClicked1stOutpathRadio();
	afx_msg void OnBnClicked2ndOutpathNavi();
	///afx_msg void OnBnClicked2ndOutpathPhone();
	afx_msg void OnBnClicked2ndOutpathPhoneRadio();
	afx_msg void OnBnClicked2ndOutpathOff();
	afx_msg void OnBnClickedOutLevelDownButton();
	afx_msg void OnBnClickedOutLevelUpButton();
	afx_msg void OnNMCustomdraw2ndOutLevelProgress(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnStnClickedStatic2ndOutLevel();
	afx_msg void OnStnClickedStatic1stOutLevel();
	afx_msg void OnStnClickedStatic1stOutBalance();
	afx_msg void OnNMCustomdraw1stOutBalanceSlider(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedExitQuitButton();
	afx_msg void OnNMCustomdraw1stOutLevelProgress(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedMuteFrontRightCheck();
	afx_msg void OnBnClickedMuteFrontLeftCheck();
	afx_msg void OnBnClickedMuteRearRightCheck();
	afx_msg void OnBnClickedMuteRearLeftCheck();
	afx_msg void OnBnClickedMuteQuickAllCheck();
	afx_msg void OnBnClicked1stOutLevelButton();
	afx_msg void OnBnClicked2ndOutLevelButton();
	afx_msg void OnBnClicked1stOutBalanceButton();
	afx_msg void OnBnClickedOutLevelDownButton2();
	afx_msg void OnBnClickedOutLevelUpButton2();
	afx_msg void OnBnClickedWav2id0Check();
	afx_msg void OnBnClickedWav2id1Check();
	afx_msg void OnBnClickedWav2id2Check();
	afx_msg void OnBnClicked1stOutFaderButton();
	afx_msg void OnNMCustomdraw1stOutFaderSlider(NMHDR *pNMHDR, LRESULT *pResult);
};
