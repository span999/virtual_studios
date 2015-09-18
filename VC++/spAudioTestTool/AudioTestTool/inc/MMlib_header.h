/*






*/
/*
	Please be aware that this header fit to WINCE platform only!!
	please refer link below if you want some doc about this MMlib API!!
	https://docs.google.com/document/pub?id=1-5vwXKgsxTLp1ED-uM1geQIKIvtdsQYFEipCxrCQ_WA
	all error return refer WINCE system error code!!
	http://msdn.microsoft.com/en-us/library/ms932980.aspx
*/
#ifndef __MMLIB_HEADER_H__
#define __MMLIB_HEADER_H__


#if defined(__cplusplus)
extern "C"
{
#endif  /* defined(__cplusplus) */



/*
    get MM system knowing about the caller
	each application or user must call this function one time before start using MMlib.
    return the handle number from xxx_Open()
*/
HANDLE MMlib_initCaller( void );


/*
    get MM system knowing about the caller
	each application or user must call this function one time before ending.
*/
void MMlib_deinitCaller( HANDLE id );


/*****************************************************************************/
/*	part of audio routing control                                            */
/*****************************************************************************/


/*

*/
int MMlib_pathsetHostAudio( HANDLE caller );


/*

*/
int MMlib_pathsetSoftMpeg( HANDLE caller );


/*

*/
int MMlib_pathsetHardMpeg( HANDLE caller );


/*

*/
int MMlib_pathsetIPODAudioA( HANDLE caller );


/*

*/
int MMlib_pathsetIPODAudioD( HANDLE caller );


/*

*/
int MMlib_pathsetDiskAudioA( HANDLE caller );


/*

*/
int MMlib_pathsetDiskAudioD( HANDLE caller );


/*

*/
int MMlib_pathsetRadioAudioA( HANDLE caller );


/*

*/
int MMlib_pathsetRadioAudioD( HANDLE caller );


/*

*/
int MMlib_pathsetNaviAudioA( HANDLE caller );


/*

*/
int MMlib_pathsetNaviAudioD( HANDLE caller );


/*

*/
int MMlib_pathsetPhoneAudioA( HANDLE caller );


/*

*/
int MMlib_pathsetPhoneAudioD( HANDLE caller );


/*

*/
int MMlib_pathsetAUXAudioA( HANDLE caller );


/*

*/
int MMlib_pathsetAUXAudioD( HANDLE caller );




/*****************************************************************************/
/*	part of volume control                                                   */
/*****************************************************************************/

typedef 	unsigned char			MMlibVOLUME;
typedef 	signed char				MMlibVOLBALANCE;



/*

*/
int MMlib_volumesetFrontRear( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetFRbalance( HANDLE caller, MMlibVOLBALANCE Bal );

/*

*/
int MMlib_volumesetFader( HANDLE caller, MMlibVOLBALANCE Bal );


/*

*/
int MMlib_volumesetLRbalance( HANDLE caller, MMlibVOLBALANCE Bal );


/*

*/
int MMlib_volumesetCenter( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetWoofer( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetMainFunction( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetSecondFunction( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetAll( HANDLE caller, MMlibVOLUME Vol );

								
/*

*/
int MMlib_volumesetHostAudio( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetSoftMpeg( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetHardMpeg( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetIPODAudioA( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetIPODAudioD( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetDiskAudioA( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetDiskAudioD( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetRadioAudioA( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetRadioAudioD( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetNaviAudioA( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetNaviAudioD( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetPhoneAudioA( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetPhoneAudioD( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetAUXAudioA( HANDLE caller, MMlibVOLUME Vol );


/*

*/
int MMlib_volumesetAUXAudioD( HANDLE caller, MMlibVOLUME Vol );




/*****************************************************************************/
/*	part of mute control                                                   */
/*****************************************************************************/




/*

*/
int MMlib_mutesetFront( BOOL bMute );


/*

*/
int MMlib_mutesetFrontLeft( BOOL bMute );


/*

*/
int MMlib_mutesetFrontRight( BOOL bMute );


/*

*/
int MMlib_mutesetRear( BOOL bMute );


/*

*/
int MMlib_mutesetRearLeft( BOOL bMute );


/*

*/
int MMlib_mutesetRearRight( BOOL bMute );


/*

*/
int MMlib_mutesetCenter( BOOL bMute );


/*

*/
int MMlib_mutesetWoofer( BOOL bMute );


/*

*/
int MMlib_mutesetAll( BOOL bMute );


/*

*/
int MMlib_mutesetQuick( BOOL bMute );




									
									



/*****************************************************************************/
/*	part of Event & Notofication                                             */
/*****************************************************************************/

/*
	MM system will use named event below for notification
	you can get notify by create the event with the same name!
*/
#define		MM_EVENT_NAME_OVERALL			TEXT("named MM system overall event")
#define		MM_EVENT_NAME_HOST				TEXT("named MM system HOST event")
#define		MM_EVENT_NAME_IPOD				TEXT("named MM system IPOD event")
#define		MM_EVENT_NAME_DISK				TEXT("named MM system DISK event")
#define		MM_EVENT_NAME_RADIO				TEXT("named MM system RADIO event")
#define		MM_EVENT_NAME_NAVI				TEXT("named MM system NAVI event")
#define		MM_EVENT_NAME_PHONE				TEXT("named MM system PHONE event")
#define		MM_EVENT_NAME_AUX				TEXT("named MM system AUX event")


/*
    register MM system notification, 
	after registered MM system will sent event for notification
*/
HANDLE MMlib_registerNotify( HANDLE caller );


typedef struct t_MMlib_RDSDECODEDATA
{
	DWORD	dataA;	///error bit included in byte3
	DWORD	dataB;	///error bit included in byte3
	DWORD	dataC;	///error bit included in byte3
	DWORD	dataD;	///error bit included in byte3
} MMlibRDSDECODE, *PMMlibRDSDECODE;

/*

*/
int MMlib_getRDSdecodeData( HANDLE caller, MMlibRDSDECODE* pData );


/*

*/
int MMlib_getRDSdemodData( HANDLE caller/*, TBD*/ );


/*

*/
int MMlib_getRadioStatus( HANDLE caller/*, TBD*/ );



typedef struct t_MMlib_STATUS
{
	BOOL Query;
} MMlibSTATUS, *PMMlibSTATUS;
/*

*/
MMlibSTATUS MMlib_getMMstatus( HANDLE caller );






#ifdef __cplusplus
}
#endif

#endif  /* #ifndef __MMLIB_HEADER_H__ */
