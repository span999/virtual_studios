
// ************ IMPORTANT NOTICE **************************************************************************************
//  Some IOCTL definitions in this header file are reserved for future use. 
//  That means, not every IOCTL defined in this document has been implemented in the project.
//  To check whether the IOCTL has been implmeneted in project or not, you shall check the "GPS External Interface SRS.doc" document
// **********************************************************************************************************************

/*
Modifier 		Date			Sign        		Description
================================================================================================================================
Hazel Dong      11/12/02        Haz111202_1         Add ioctl for out path, microphone on/off, and set/get mic volume.
Jacob         11/03/31        JC_R07_EN_IPOD_USBAUDIO     IOCTL code for iPod Player to send SET_CUR request (SetSampleRate)
Kevin.H         11/03/18        Kevin.H_110318      Add IOCTL_ODM_VIDEO_GET_FORMAT for get DVD format
Morgan Chang  11/03/04        Morgan_R04_110304    Add save iNAND CID to ODM_FCC_SYS+44
Eric Wu       11/03/03        eric_R04_110303      fix IOCTL battery fault to ODM_FCC_SYS+44
Eric Wu       11/02/25        eric_R04_110225      Add window message when resume 
Eric Wu       11/02/14        eric_R00_101206      IOCTL for battery fault
Johnny Lin    11/01/11	      Johnny110111		   IOCTL for Humpback MCU Control
Shengkai Weng 10/12/14        shengkai1214                 Software PCM WAV Message & IOCTL for IPOD Audio Path Switch
Jacob         10/11/19        JC_T10_EN_IPOD_CONTROL       IOCTL for iPod/iPhone
Shengkai Weng 10/10/13           RADQoo                    IOCTL for CD-ROM player
Shengkai Weng 10/10/12          Shengkai1012               IOCTL for Audio Processor Path Control
Winna Wei     10/08/19           winna0819                 1. IOCTL  supports to  disable/ enable power button interrupt when need 2.Detect if SD card is inserted
Mona Hu         10/04/20           mona0420                  IOCTL  supports to get the ADC value of Dimmer sensor and set the Backlight with Dimmer sensor in auto/manual mode
Daniel Dong    10/04/02          daniel0402                IOCTL and names event to detect  whether AP is running norma (SYS WDG)
Raymond Tsai  10/02/24          raymond0224            IOCTL  supports to change battery type
Summer Chen  10/01/07           summer0107              IOCTL  supports for backlight control
Bob Wu         10/01/05             bob100105                 IOCTL  supports to get the reset reason (MGN project)
Bob Wu         09/11/13              bob091113                 IOCTL and message for device SN, Hidden NAND R/W(client buffer), HW version. (MGN project)
Bob Wu         09/11/12              bob091112                 IOCTL and message for timer (MGN project)
Daniel Dong 09/11/12               daniel1112                 Add IOCTL for backlihgt ON/OFF
Jerry Yang   09/11/10              Jerry_091110           Add  maggellan interface to flow ODM interface standard(VPA message and IOCTL)
Mindy yang   09/08/26             Min090826             Add IOCTL for tuner power on/off
Bob Wu         09/07/14             bob090714                IOCTL  for write BT MAC Addr (not in UT, but in CE)
Charles Kuo  09/05/11              charlesK_090511      Add definition of returned GPS type - Sirf Prima GPS. (IOCTL for get the current GPS solution)
Val Zhang     09/04/3 0            val0430                     Message used for waveOutMessage API to set FM Transmitter standby mode function On/Off
Bob Wu         09/04/08             bob090409               IOCTL to Check current 3-way switch position
Dick Hsu      09/04/07             dick090407               IOCTL for set backlight time out
Lucy Zeng     09/03/02             lucy090302               IOCTL for disable/enable button function
Bob Wu         09/02/24             bob090224                IOCTL to code to let OS know current state & WM to indicate switch off->on
Lucy Zeng     09/02/24             lucy090224               IOCTL for video control
Bob Wu          09/02/20             bob090220               IOCTL to judge whether this sleep back is STF image restore.
Ronnie Yang  09/02/13             ronnie0213                 IOCTL used internally for sdmlc driver  (This IOCTL is for internal used only. Not described in SRS)
Solike Yang   09/02/09             so0209                       GPS solution type for IOCTL to get the current GPS solution
Jerry Yang    09/01/20              jerry20090120         IOCTL for get the current GPS solution
Jerry Yang    09/01/15              jerry20090115           IOCTL for 3TW GPS to control GPS reset pin
Jerry Yang    09/01/13              jerry20090113           IOCTL to adjust 3TW GPS GSV refresh frequence
Jerry Yang    08/11/21              jerry1121                      IOCTL supports to FM Transmitter
Mindy Yang    08/10/23             mindy1023                  IOCTL supports to control brightness of CIM module. (TV)
Changes Liao  08/10/17             changes1017                IOCTL to read TV module serial number
JackeyChuang08/04/17	 MitacSoleus_080417 IOCTL for GSM function 
JackeyChuang08/01/29	 MitacSoleus_080110 Add window message when SIM card Insert / Remove 
Bob Wu          08/08/25              bob080825                For wake up interrupt information
Yu Zheng        08/08/19              yu0819                       Message for FM transmitter
Bob Wu           08/08/07              bob0807                     IOCTL to get  region checksum & get HW version
Mindy Yang    08/07/30              mindy0730                IOCTL supports to control CIM module. (TV)
Raymond         08/07/24              RAD_T06_0724A     Add AVIN volume IOCtrls
Bob Wu           08/07/22              bob0723                     IOCTL to get  backlight infor
Winna Wei    08/07/14               winna0714                  New image type for iBoot image upgrade
Sneeper Yu     08/07/03              sneeper0703              Waveform Aduio Driver Messages
Bob Wu            08/07/01              bob0701                      IOCTL to get region kernel information. It is used by appstartuppri.exe and iboot.exe for date information. (This IOCTL is for internal used only. Not described in SRS)
Bob Wu            08/06/30              bob0630                     IOCTL for date information (for Navman map)
Jerry.Yang      08/03/07             Jerry0307	        IOCTL  for compass (revised, removed data structure)
Bob Wu            08/02/22              bob0222                     IOCTL for compass (original)
Ronnie Yang    07/12/28               ronnie1228                 IOCTL to get Uboot version number
Bob Wu            07/12/28               bob1228                      IOCTL for new image upgrade mechanism
Jerry Yang      07/12/07               jerry1207                   window message for reboot system by USB insert
Bob Wu            07/11/20                bob1120                      IOCTL to get the lock status of uboot
Bob Wu            07/11/20                bob1120                      IOCTL for lock uboot or unlock uboot
Kitty Xd           07/11/19                 kitty1119                    Add IOCTL to check whether splash screen been wrote correctly into flash reserve area in production process
Katrina Liu       07/11/19                 katrina1119              Add IOCTL to get SD disk information 
Jayson Lin        07/10/1	                 jayson1001              Add IOCTL to set device UUID  
Raymond Tsai   07/09/10	      raymond0910         This IOCTL supports to set the AV in path mode.
Hazel Dong       07/08/23               Haz070823            Add WM for key lock function
Elliot Chao        07/08/14                elliot0814              Add WM for iPod direct control(this message was first created for NN710/746 project)
Bob Wu             07/07/25                bob070725           Add definition to prevents multiple inclusions of the file
Isan Ren            07/07/20                joe0720                Add one device for map control
Isan Ren            07/07/11                 isan0711                 IOCTL for Save/Load echo firmware to/from flash
WenHsi Wen     07/07/06                wen0706                IOCTL for port control (applied in NN746 project only)
Ray Tsai             07/07/02                ray0702                 Window Message for key lock function use.
Bob Wu              07/06/22                bob0622                 IOCTL for supporting iBoot from MyFlashDisk (for UT image)
Joe Chou            07/06/21                joe0621                   Remve  IOCTL_ODM_SYS_SWITCHOFF_DEVICE. Instead AP shall use  IOCTL_ODM_POWER_SWITCHOFF_DEVICE to switch off device.
Ronnie Yang       07/06/12                ronnie0612             IOCTL for supporting iBoot from USB/SD (for UT image)
Bob Wu               07/06/07                bob0607                IOCTL for supporting iBoot from MyFlashDisk (for CE image)
Jason Zang         07/06/07                jason0607             WM for open/close camera (front cover)
Bob Wu               07/06/01                 bob0601                 WM for power button short press and long press. 
Raymond Tsai      07/05/30	          raymond0530       IOCTL for set/get audio path to mono output or stereo outputl
Sneeper Yu          07/05/29               sneeper0529         IOCTL for load/save touch screen calibration data
Raymond Tsai      07/05/18	          raymond0518        IOCTL for set FM audio channel
Raymond Tsai       07/05/10                raymond0510        IOCTL for different MIC source selection
Raymond Tsai       07/04/17                raymond0417        IOCTL for set TV (TDMB) audio routine & EQ setting
Elliot Chao            07/04/17                elliot0417              IOCTL for open or close USB function interrupt 
Ray Tsai                07/04/17                ray0417                 IOCTL for touch sense
Raymond Tsai       07/04/11                 raymond0411         IOCTL for control I2S(audio)  clock
Joe Chou               07/04/11                 joe0411                  Remove IOCTL for screen control, we will use MSFT SETPOWERMANAGEMENT/GETPOWERMANAGEMENT
Jayson Lin             07/03/26               jay0326                IOCTL for accessing security data (reserved 1K) for ODMmap
Dick Hsu                07/02/13                dick0213               IOCTL for power button. The behavior is different when short-press and press-n-hold power button. 
Bob Wu                  07/02/05               bob0205                IOCTL for saving splash screen bitmap to reseved flash block
Span Liu                 07/02/05               span0205              IOCTL for set/get vidio source input
Jawa Chen              07/01/30               jawa0130               IOCTL for ActiveSync and MassStorage driver switching
Joe Chou                07/01/12                joe0112                  IOCTL for PSA (Pressure Sensor & Altitude)
Ernie Lin                07/01/05               ernie070105         IOCTL for read/write reserved block
Joe Chou                07/01/02		joe0102		IOCTL for getting CPLD user code 
Joe Chou		06/12/14		joe1214		IOCTL for control Bluetooth LED On/Off 
Joe Chou		06/12/08		joe1208		IOCTL for switch off device (power is totally cut off, but not suspend) 
Joe Chou		06/12/05		joe1205		IOCTL for enable&disable the touch screen 
Joe Chou		06/10/31		joe1031		IOCTL for Unit Testing Framework
Joe Chou		06/09/29	   	joe0929		IOCTL for TV driver
Joe Chou		06/09/22	   				First release
Chris Huang     10/10/28        chris_101028        add a new return value of IOCTL_ODM_GPS_GET_CURRENT_SOLUTION for ST solution
*/
//bob070725
#ifndef __ODM_IOCTL_H			
#define __ODM_IOCTL_H			

#if __cplusplus
extern "C" {
#endif

//
// Define the various device type values.  Note that values used by Microsoft
// Corporation are in the range 0-32767, and 32768-65535 are reserved for use
// by customers.
//
//
// File device code for ODM GPS specific device driver
//
#define FILE_DEVICE_ODM_SYSTEM            0x00008000
#define FILE_DEVICE_ODM_BATTERY           0x00008001
#define FILE_DEVICE_ODM_BACKLIGHT         0x00008002
#define FILE_DEVICE_ODM_AUDIO             0x00008003
#define FILE_DEVICE_ODM_SDMMC             0x00008004
#define FILE_DEVICE_ODM_DISPLAY           0x00008005
#define FILE_DEVICE_ODM_POWER             0x00008006
#define FILE_DEVICE_ODM_BLUETOOTH         0x00008007
#define FILE_DEVICE_ODM_TV                0x00008008
#define FILE_DEVICE_ODM_COMPASS           0x00008009
#define FILE_DEVICE_ODM_WALKITALKIE       0x0000800A
#define FILE_DEVICE_ODM_UNITTESTFRAMEWORK 0x0000800B  //joe1031
#define FILE_DEVICE_ODM_TOUCHSCREEN       0x0000800C
#define FILE_DEVICE_ODM_PSA               0x0000800D  // joe0112
#define FILE_DEVICE_ODM_VIDEO             0x0000800E  // span0205
#define FILE_DEVICE_ODM_TOUCHSENSE        0x0000800F  // ray0417
#define FILE_DEVICE_ODM_USB               0x00008010  // elliot0417
#define FILE_DEVICE_ODM_PORT              0x00008011  // wen0706
#define FILE_DEVICE_ODM_MAP               0x00008012  // joe0720
#define FILE_DEVICE_ODM_GSM               0x00008013  // MitacSoleus_080417
#define FILE_DEVICE_ODM_FMTRANSMITTER     0x00008014  // jerry1121
#define FILE_DEVICE_ODM_GPS		          0x00008015  // jerry20090113			
#define FILE_DEVICE_ODM_BUTTON		      0x00008016  // lucy090302
#define FILE_DEVICE_ODM_VPA               0x00008017  //Jerry_091110 
#define FILE_DEVICE_ODM_DIMMERSENSOR      0x00008018  //mona0420
#define FILE_DEVICE_ODM_CDP               0x00008019	//RADQoo
#define FILE_DEVICE_ODM_MCU               0x00008020    //Johnny110111

// Macro definition for defining IOCTL function control codes.  Note
// that function codes 0-2047 are reserved for Microsoft Corporation, and
// 2048-4095 are reserved for customers
//
//
// Function control code for ODM GPS specific functions
//
#define ODM_FCC_BASE			2048
#define ODM_FCC_BATTERY			ODM_FCC_BASE
#define ODM_FCC_BACKLIGHT 		ODM_FCC_BASE+10  
#define ODM_FCC_AUDIO			ODM_FCC_BASE+20
#define ODM_FCC_SDMMC			ODM_FCC_BASE+30
#define ODM_FCC_NAND			ODM_FCC_BASE+40
#define ODM_FCC_SERIAL			ODM_FCC_BASE+50
#define ODM_FCC_USB			    ODM_FCC_BASE+60
#define ODM_FCC_TOUCHSCREEN		ODM_FCC_BASE+70
#define ODM_FCC_DISPLAY			ODM_FCC_BASE+80   
#define ODM_FCC_BUTTON			ODM_FCC_BASE+90
#define ODM_FCC_POWER			ODM_FCC_BASE+100
#define ODM_FCC_BLUETOOTH		ODM_FCC_BASE+120  
#define ODM_FCC_TV 		        ODM_FCC_BASE+130  
#define ODM_FCC_PRESSURESENSOR  ODM_FCC_BASE+140 // joe0112
#define ODM_FCC_VIDEO           ODM_FCC_BASE+150 // span0205
#define ODM_FCC_TOUCHSENSE      ODM_FCC_BASE+160 // ray0417
#define ODM_FCC_PORT            ODM_FCC_BASE+170 // WenHsi0706
#define ODM_FCC_COMPASS         ODM_FCC_BASE+180 //bob0222
#define ODM_FCC_FMTRANSMITTER   ODM_FCC_BASE+190 //jerry1121
#define ODM_FCC_VPA             ODM_FCC_BASE+200 //Jerry_091110
#define ODM_FCC_MCU             ODM_FCC_BASE+210 //Johnny110111
#define	ODM_FCC_POWER_TIMER		ODM_FCC_BASE+230 //bob091112
#define ODM_FCC_CDP             ODM_FCC_BASE+240	//RADQoo
#define ODM_FCC_DIMMERSENSOR    ODM_FCC_BASE+250 //mona0420

#define ODM_FCC_UTF			    ODM_FCC_BASE+850  // ODM Unit Test Framework 
#define ODM_FCC_SYS			    ODM_FCC_BASE+900  // ODM specific system function 

// ====== IOCTL ====================================================================================================================================================================
//
// IO control definition for ODM specific functions
//  
// Format  for IOCTL defininition:  IOCTL_ODM_DEVICETYPE_FUNCTION(V+N)
//

// -------------- lucy090302: to disable/enable button function  ---------------------------
#define IOCTL_ODM_BUTTON_SET      CTL_CODE(FILE_DEVICE_ODM_BUTTON,ODM_FCC_BUTTON, METHOD_BUFFERED, FILE_ANY_ACCESS)
//ronnie101110 typedef struct _ButtonSetting
//ronnie101110 {   
//ronnie101110     bool  bIsEnable;  // true-> enable; false-> disable
//ronnie101110     DWORD dwKeys;     //Indicate which keys
//ronnie101110 } ButtonSetting, *PButtonSetting;

// -------------- jerry20090113:  for 3tw GPS adjust GSV output frequence   ----------
#define IOCTL_ODM_GPS_GSV_REFRESH_FREQ      CTL_CODE(FILE_DEVICE_ODM_GPS,ODM_FCC_SERIAL+1, METHOD_BUFFERED, FILE_ANY_ACCESS)
//--------------jerry20090115: for 3TW GPS to let sirfnavdrv.dll is independ with HW 
#define IOCTL_ODM_GPS_RESET      	        CTL_CODE(FILE_DEVICE_ODM_GPS,ODM_FCC_SERIAL+2, METHOD_BUFFERED, FILE_ANY_ACCESS)
//--------------jerry20090120: to get the current GPS solution
#define IOCTL_ODM_GPS_GET_CURRENT_SOLUTION  CTL_CODE(FILE_DEVICE_ODM_GPS,ODM_FCC_SERIAL+3, METHOD_BUFFERED, FILE_ANY_ACCESS)
// -------------so0209, GPS solution type ---------------------
#define ODM_HW_CHIP_TYPE_UNKNOWN            0x00
#define ODM_HW_CHIP_TYPE_SIRF_SW            0x01
#define ODM_HW_CHIP_TYPE_SIRF_HW            0x02
#define ODM_HW_CHIP_TYPE_ATHEROS_STANDALONE 0x03
#define ODM_HW_CHIP_TYPE_ATHEROS_HOST       0x04
#define ODM_HW_CHIP_TYPE_SIRF_PRIMA         0x05   // charlesK_090511
#define ODM_HW_CHIP_TYPE_BROADCOM_HABI      0x06   //Jerry Yang
#define ODM_HW_CHIP_TYPE_ST_CARTESIOPLUS_SW 0x0A   //chris_101028
//

// -------------- elliot0417:  for open or close USB function interrupt   ----------
#define IOCTL_ODM_USB_PLUG_ON               CTL_CODE(FILE_DEVICE_ODM_USB,ODM_FCC_USB+1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_USB_PLUG_OFF              CTL_CODE(FILE_DEVICE_ODM_USB,ODM_FCC_USB+2, METHOD_BUFFERED, FILE_ANY_ACCESS)

// -------------- ray0417:  for Touchsense control function  ----------
// ray0417:Control touchsense power on/off
#define IOCTL_ODM_TSN_SET_POWER             CTL_CODE(FILE_DEVICE_ODM_TOUCHSENSE,ODM_FCC_TOUCHSENSE+1, METHOD_BUFFERED, FILE_ANY_ACCESS)
// ray0417:Control SENSOR_FREQ pin frequency
#define IOCTL_ODM_TSN_SET_FREQ_FREQ         CTL_CODE(FILE_DEVICE_ODM_TOUCHSENSE,ODM_FCC_TOUCHSENSE+2, METHOD_BUFFERED, FILE_ANY_ACCESS)
// ray0417:Control SENSOR_MAG pin frequency
#define IOCTL_ODM_TSN_SET_MAG_FREQ          CTL_CODE(FILE_DEVICE_ODM_TOUCHSENSE,ODM_FCC_TOUCHSENSE+3, METHOD_BUFFERED, FILE_ANY_ACCESS)
// ray0417:Control SENSOR_FREQ pin duty cycle
#define IOCTL_ODM_TSN_SET_FREQ_DUTYCYCLE    CTL_CODE(FILE_DEVICE_ODM_TOUCHSENSE,ODM_FCC_TOUCHSENSE+4, METHOD_BUFFERED, FILE_ANY_ACCESS)
// ray0417:Control SENSOR_MAG pin duty cycle
#define IOCTL_ODM_TSN_SET_MAG_DUTYCYCLE     CTL_CODE(FILE_DEVICE_ODM_TOUCHSENSE,ODM_FCC_TOUCHSENSE+5, METHOD_BUFFERED, FILE_ANY_ACCESS)

// -------------- joe0112: support PSA (pressure sensor altitude) funtions ----------
#define IOCTL_ODM_PSA_GET_ALTITUDE 			CTL_CODE(FILE_DEVICE_ODM_PSA, ODM_FCC_PRESSURESENSOR +1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_PSA_CALIBRATE_ALTITUDE 	CTL_CODE(FILE_DEVICE_ODM_PSA, ODM_FCC_PRESSURESENSOR +2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_PSA_CALIBRATE_64KPA 		CTL_CODE(FILE_DEVICE_ODM_PSA, ODM_FCC_PRESSURESENSOR +3, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_PSA_CALIBRATE_105KPA 		CTL_CODE(FILE_DEVICE_ODM_PSA, ODM_FCC_PRESSURESENSOR +4, METHOD_BUFFERED, FILE_ANY_ACCESS)

// -------------- joe1214: IOCTL for control Bluetooth LED On/Off  ----------
#define IOCTL_ODM_BT_SET_LED      CTL_CODE(FILE_DEVICE_ODM_BLUETOOTH,   ODM_FCC_BLUETOOTH,       METHOD_BUFFERED, FILE_ANY_ACCESS)

// -------------- joe1205: support AP or driver which can call KernelIoControl function to enable&disable the touch panel's function ----------
#define IOCTL_ODM_TOUCHSCREEN_SET       CTL_CODE(FILE_DEVICE_ODM_TOUCHSCREEN,   ODM_FCC_TOUCHSCREEN,    METHOD_BUFFERED, FILE_ANY_ACCESS)
//sneeper0529
#define IOCTL_ODM_TOUCHSCREEN_LOAD_CALI   CTL_CODE(FILE_DEVICE_ODM_TOUCHSCREEN, ODM_FCC_TOUCHSCREEN+1,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_TOUCHSCREEN_SAVE_CALI   CTL_CODE(FILE_DEVICE_ODM_TOUCHSCREEN, ODM_FCC_TOUCHSCREEN+2,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_TOUCHSCREEN_DELETE_CALI CTL_CODE(FILE_DEVICE_ODM_TOUCHSCREEN, ODM_FCC_TOUCHSCREEN+3,  METHOD_BUFFERED, FILE_ANY_ACCESS)

// -------------- joe1031: for Unit Test Framework, these IOCTL is used to lauch test suit ----------
#define IOCTL_ODM_UTF_BATTERY     CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF,         METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_BACKLIGHT	  CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+1,       METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_AUDIO       CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+2,       METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_SDMMC       CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+3,       METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_NAND	      CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+4,       METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_SERIAL      CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+5,       METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_USB         CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+6,       METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_TOUCHSCREEN CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+7,       METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_DISPLAY     CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+8,       METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_BUTTON      CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+9,       METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_POWER       CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+10,      METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_BLUETOOTH   CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+11,      METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_UTF_TV          CTL_CODE(FILE_DEVICE_ODM_UNITTESTFRAMEWORK,   ODM_FCC_UTF+12,      METHOD_BUFFERED, FILE_ANY_ACCESS)

//Jerry0307 start
#define IOCTL_ODM_COMPASS_READ_CALI     CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+0,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_ODM_COMPASS_WRITE_CALI    CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+1,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_ODM_COMPASS_DELETE_CALI   CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+2,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_ODM_COMPASS_READ_TEMP     CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+3,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_ODM_COMPASS_WRITE_TEMP    CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+4,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_ODM_COMPASS_DELETE_TEMP   CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+5,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_ODM_COMPASS_READ_SLOPE    CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+6,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_ODM_COMPASS_WRITE_SLOPE   CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+7,METHOD_BUFFERED,FILE_ANY_ACCESS)
//Jerry0307 end

// ----bob0222 start ---------------
// the following IOCTL and data structure is only for reference. It is specific for the Yamaha compass IC. Please refer to Jerry0307

//#define IOCTL_ODM_COMPASS_READ_CALI     CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+0,METHOD_BUFFERED,FILE_ANY_ACCESS)
//#define IOCTL_ODM_COMPASS_WRITE_CALI    CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+1,METHOD_BUFFERED,FILE_ANY_ACCESS)
//#define IOCTL_ODM_COMPASS_DELETE_CALI   CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+2,METHOD_BUFFERED,FILE_ANY_ACCESS)
//#define IOCTL_ODM_COMPASS_READ_TEMP     CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+3,METHOD_BUFFERED,FILE_ANY_ACCESS)
//#define IOCTL_ODM_COMPASS_WRITE_TEMP    CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+4,METHOD_BUFFERED,FILE_ANY_ACCESS)
//#define IOCTL_ODM_COMPASS_DELETE_TEMP   CTL_CODE(FILE_DEVICE_ODM_COMPASS,ODM_FCC_COMPASS+5,METHOD_BUFFERED,FILE_ANY_ACCESS)
//typedef struct _tagWCOMDATA {
//         double      cx,cy1,cy2;
//         SINT32     xw1,y1w1,y2w1,tw1;
//         SINT32     xw2,y1w2,y2w2,tw2;
//         SINT32     data1_flag;
//         SINT32     data2_flag;
//         SINT32     ct_flag;
//         SINT32     Nave;
//} WcompData, *pWcompData;
//typedef struct _tagMS2ROUGHOFFSET {
//         UINT16 wRox1;                                                        /* Rough offset value of the X-axis */
//         UINT16 wRoy1;                                                        /* Rough offset value of the Y-axis */
//         UINT16 wRoy2;                                                        /* Rough offset value of the Z-axis */
//} MS2ROUGHOFFSET, *pMS2ROUGHOFFSET;
//typedef struct _tagMS2OFFSET {
//         SINT16 cx;                                                                /* Offset value of the X-axis */
//         SINT16 cy;                                                                /* Offset value of the Y-axis */
//         SINT16 cz;                                                                /* Offset value of the Z-axis */
//         SINT16 ct;                                                                 /* Temperature at the time of offset */
//         SINT16 cr;                                                                 /* Radius */
//         SINT16 ci1,ci2,ci3;                                         /* Measurement value of slope sensor */
//         MS2ROUGHOFFSET RoughOffset;           /* Rough offset */
//} MS2OFFSET, *PMS2OFFSET;
//-----bob0222 end-----------------

// -------------- for system function , these IOCTL is used for KernelIoControl -------------------------------------------------------
//joe0621 //#define IOCTL_ODM_SYS_SWITCHOFF_DEVICE	 CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+1,         METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_SET_DVS_CODE	     CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+2,         METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_CLEAR_REGISTRY     CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+3,         METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_GET_CEIMG_VERSION	 CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+4,         METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_GET_CEIMG_CHECKSUM CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+5,         METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_GET_UBOOT_CHECKSUM CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+6,         METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_GET_BTMAC_ADDR	 CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+7,         METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_IBOOT   	         CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+8,         METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_IBOOT_SD           CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+9,         METHOD_BUFFERED, FILE_ANY_ACCESS)
// -------------- joe0102: support to get CPLD user code ----------
#define IOCTL_ODM_SYS_GET_CPLD_USERCODE  CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+10,        METHOD_BUFFERED, FILE_ANY_ACCESS)
// -------------- ernie070105: for read/write rsvd block ----------
#define IOCTL_ODM_SYS_READ_RESERVED_BLOCK      CTL_CODE(FILE_DEVICE_ODM_SYSTEM,  ODM_FCC_SYS+11,   METHOD_BUFFERED, FILE_ANY_ACCESS) 
#define IOCTL_ODM_SYS_WRITE_RESERVED_BLOCK     CTL_CODE(FILE_DEVICE_ODM_SYSTEM,  ODM_FCC_SYS+12,   METHOD_BUFFERED, FILE_ANY_ACCESS)  
// -------------- jawa0130: for ActiveSync and MassStorage driver switching ----------
#define IOCTL_ODM_SYS_ACTIVE_SYNC	           CTL_CODE(FILE_DEVICE_ODM_SYSTEM,  ODM_FCC_SYS+13,   METHOD_BUFFERED, FILE_ANY_ACCESS)  
#define IOCTL_ODM_SYS_MASS_STORAGE	           CTL_CODE(FILE_DEVICE_ODM_SYSTEM,  ODM_FCC_SYS+14,   METHOD_BUFFERED, FILE_ANY_ACCESS)  
// -------------- bob0205: for  saving splash screen bitmap to reseved flash block ----------
#define IOCTL_ODM_SYS_STORE_SPLASHSCREEN       CTL_CODE(FILE_DEVICE_ODM_SYSTEM,  ODM_FCC_SYS+15,   METHOD_BUFFERED, FILE_ANY_ACCESS)  
#define IOCTL_HAL_STORE_SPLASHSCREEN IOCTL_ODM_SYS_STORE_SPLASHSCREEN // redefine for backward compatible with Venus series project
// -------------- jay0326: for accessing security data (reserved 1K) for ODMmap ----------
#define IOCTL_ODM_SYS_READ_ODMMAP_DATA         CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+16,  METHOD_BUFFERED, FILE_ANY_ACCESS) 
#define IOCTL_ODM_SYS_WRITE_ODMMAP_DATA        CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+17,  METHOD_BUFFERED, FILE_ANY_ACCESS) 
// -------------- bob0607: for  supporting iBoot from My Flash Disk ----------
#define IOCTL_ODM_SYS_IBOOT_MYFLASHDISK        CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+18,  METHOD_BUFFERED, FILE_ANY_ACCESS)
// -------------- eric_R00_101206: for battery fault kerneliocontrol---------------------- ----------
//eric_R04_110303 #define IOCTL_HAL_MEM_SELFREFRESH              CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+19,  METHOD_BUFFERED, FILE_ANY_ACCESS)

// -------------- ronnie0612: for  supporting iBoot (UT image) from USB and SD ----------
//ronnie0612
#define IOCTL_ODM_SYS_IBOOT_USB_UT             CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+19,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_IBOOT_SD_UT              CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+20,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//bob0622
#define IOCTL_ODM_SYS_IBOOT_MYFLASHDISK_UT     CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+21,  METHOD_BUFFERED, FILE_ANY_ACCESS)
// jayson1001
#define IOCTL_ODM_SYS_SET_UUID                 CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+22,  METHOD_BUFFERED, FILE_ANY_ACCESS)
// kitty1119
#define IOCTL_ODM_SYS_GET_SPL_CKS              CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+23,  METHOD_BUFFERED, FILE_ANY_ACCESS)
// bob1120
#define IOCTL_ODM_SYS_UBOOT_LOCK               CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+24,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_UBOOT_SHOWFLAG           CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+25,  METHOD_BUFFERED, FILE_ANY_ACCESS)

//bob1228 start
#define IOCTL_ODM_SYS_IBOOT_IMAGE_UPGRADE      CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+26,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//Image type
#define UPGRADE_CEIMAGE           0
#define UPGRADE_UBOOT             1
#define UPGRADE_CEIMAGE_AND_UBOOT 2
//winna0714
#define UPGRADE_CEIMAGE_UBOOT_REGION 3
#define UPGRADE_CEIMAGE_AND_REGION 4
#define UPGRADE_UBOOT_AND_REGION 5
#define UPGRADE_REGION 6

//Upgrade media
#define VIA_USB         0
#define VIA_SD          1
#define VIA_MYFLASHDISK 2
//Need to format or not
#define NOT_FORMAT   0
#define FORCE_FORMAT 1
//ronnie101110 typedef struct _IBOOT_PARAMETER{
//ronnie101110 DWORD dwImagetype;       // 0-CE,1-Uboot,2-CE+Uboot
//ronnie101110 DWORD dwVia;             //0-USB,1-SD,2-MyFlashDisk
//ronnie101110 DWORD dwFormat;          //0-unformat,1-format;
//ronnie101110 DWORD dwReserved0;       //Just reserved
//ronnie101110 DWORD dwReserved1;
//ronnie101110 DWORD dwReserved2;
//ronnie101110 }IBOOT_PARAMETER,*PIBOOT_PARAMETER;
//bob1228 end

//ronnie1228
#define IOCTL_ODM_SYS_GET_UBOOT_VERSION      CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+27,  METHOD_BUFFERED, FILE_ANY_ACCESS)

//bob0630
#define IOCTL_ODM_SYS_WRITE_FIRST_DATETIME   CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+28,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_READ_FIRST_DATETIME    CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+29,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_WRITE_LASTEST_DATETIME CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+30,  METHOD_BUFFERED, FILE_ANY_ACCESS) 
#define IOCTL_ODM_SYS_READ_LASTEST_DATETIME  CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+31,  METHOD_BUFFERED, FILE_ANY_ACCESS)

//bob0701 - internal used only
#define IOCTL_ODM_SYS_GET_REGION_DATA        CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+32,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//bob0807
#define IOCTL_ODM_SYS_GET_REGION_CHECKSUM    CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+33,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//ronnie0213 - internal used only
#define IOCTL_ODM_SYS_STORE_DRIVER_FUNCTION_POINTER  CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+34,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//bob090224 - App call this code to let OS know current state, lock or unlock, maybe driver need use this state to take some operation
#define IOCTL_ODM_SYS_LOCK_STATE                     CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+35,  METHOD_BUFFERED, FILE_ANY_ACCESS) 
//bob090714 start
#define IOCTL_ODM_SYS_SET_BTMAC_ADDR                 CTL_CODE (FILE_DEVICE_ODM_SYSTEM,  ODM_FCC_SYS+36,  METHOD_BUFFERED, FILE_ANY_ACCESS) 
#define BTADDR_VALID_FLAG   0x55AA55AA
//ronnie101110 typedef struct _tagBTMacAddr 
//ronnie101110 {   
//ronnie101110        BYTE   pBTAddr[16];   // 16 bytes, For store BT MAC Addr
//ronnie101110        DWORD  dwBTAddrValid; // 4 bytes, 0x55AA55AA Indicate pBTAddr valid;
//ronnie101110 } BTMacAddr, *PBTMacAddr; 
// bob090714 end

// bob091113 start
#define	    IOCTL_ODM_SYS_GET_HW_VERSION          CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+37, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	    IOCTL_ODM_SYS_SERIAL_NUM_READ         CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+38, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	    IOCTL_ODM_SYS_SERIAL_NUM_WRITE        CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+39, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	    IOCTL_ODM_SYS_HIDDEN_NAND_READ        CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+40, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	    IOCTL_ODM_SYS_HIDDEN_NAND_WRITE       CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+41, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define		ODM_SERIAL_NUMBER_UNKNOWN             L"999999999999"
// bob091113 end

// bob100105 start
#define IOCTL_ODM_SYS_GET_RESET_REASON            CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+42, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define ROS_HWRESET     0x1
#define ROS_WDRESET     0x2
#define ROS_SWRESET     0x4
#define ROS_SLEEPWAKEUP 0x8
#define ROS_UNDEFINED   0x80000000
#define ROS_RTCALARM    0X40000000   // if this bit set to 1, means reset due to RTC alarm
#define ROS_SYSCALL     0X20000000   // this bit mainly for software reset, reserved for the project has reset button,  if set to 0, means due to user press reset button, if set to 1, means reset due to
                                     // application/driver call KernelIOCTL (IOCTL_HAL_REBOOT)
// bob100105 end
//add by Morgan
//MC_R03_ADD_UUID_FUNCTION start
//#define IOCTL_ODM_SYS_SAVE_FLASH_CID              CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+43,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_SYS_GET_UUID              CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+43,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//MC_R03_ADD_UUID_FUNCTION end

// -------------- eric_R04_110303: for battery fault kerneliocontrol---------------------- ----------
#define IOCTL_HAL_MEM_SELFREFRESH              CTL_CODE(FILE_DEVICE_ODM_SYSTEM,   ODM_FCC_SYS+44,  METHOD_BUFFERED, FILE_ANY_ACCESS)

// ==========================================  IOCTL below this line are used for DeviceIoControl ============================================================

// -------------- for backlight control function --------------------------------------------
#define IOCTL_ODM_BKL_GET_BRIGHTNESS	 CTL_CODE(FILE_DEVICE_ODM_BACKLIGHT,ODM_FCC_BACKLIGHT+1,   METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_BKL_SET_BRIGHTNESS	 CTL_CODE(FILE_DEVICE_ODM_BACKLIGHT,ODM_FCC_BACKLIGHT+2,   METHOD_BUFFERED, FILE_ANY_ACCESS)
//bob0723
#define IOCTL_ODM_BKL_GET_BKLINFO        CTL_CODE(FILE_DEVICE_ODM_BACKLIGHT,ODM_FCC_BACKLIGHT+3,   METHOD_BUFFERED, FILE_ANY_ACCESS)

//daniel1112
#define IOCTL_ODM_BKL_OFF_BACKLIGHT          CTL_CODE(FILE_DEVICE_ODM_BACKLIGHT,ODM_FCC_BACKLIGHT+4,   METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_ODM_BKL_ON_BACKLIGHT           CTL_CODE(FILE_DEVICE_ODM_BACKLIGHT,ODM_FCC_BACKLIGHT+5,   METHOD_BUFFERED,FILE_ANY_ACCESS)

// -------------- for Audio I2S clock control function --------------------------------------------
// raymond0411
#define IOCTL_ODM_AUD_SET_I2S_CLOCK	 CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+1,   METHOD_BUFFERED, FILE_ANY_ACCESS)
// raymond0417 start
//ronnie101110 enum EQ_MODE {
//ronnie101110     DEFAULT=0,
//ronnie101110     ROCK,
//ronnie101110     POP,
//ronnie101110     JAZZ,
//ronnie101110     CLASSICAL,
//ronnie101110     DANCE,  
//ronnie101110     HEAVY,  
//ronnie101110     DISCO,  
//ronnie101110    SOFT,  
//ronnie101110     LIVE,
//ronnie101110     HALL
//ronnie101110 };
#define IOCTL_ODM_AUD_SET_EQ         CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+2,     METHOD_BUFFERED, FILE_ANY_ACCESS)
//raymond0417 end
//raymond0510
#define IOCTL_ODM_AUD_SELECT_MIC_SOURCE CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+3,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//raymond0518
#define IOCTL_ODM_AUD_SELECT_FM		    CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+4,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//raymond0530
#define IOCTL_ODM_AUD_SET_OUT_PATH	    CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+5,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_AUD_GET_PATH_STATE    CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+6,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//isan0711
//Haz111207 modify start
//#define IOCTL_ODM_AUD_SAVE_ECHOFIRM    CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+7,   METHOD_BUFFERED, FILE_ANY_ACCESS)
//#define IOCTL_ODM_AUD_LOAD_ECHOFIRM    CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+8,   METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_BT_HANDSFREE_SET_VOLUME   CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+7,   METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_BT_HANDSFREE_GET_VOLUME   CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+8,   METHOD_BUFFERED, FILE_ANY_ACCESS)
//Haz111207 modify end
//raymond0910
#define IOCTL_ODM_AUD_SET_AVIN         CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+9,   METHOD_BUFFERED, FILE_ANY_ACCESS)
//RAD_T06_0724A
#define IOCTL_ODM_AUD_SET_AVIN_VOL     CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+10,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//Shengkai1012
#define IOCTL_WAV_SOURCE_Switch  CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+11,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//shengkai1214
#define IOCTL_ODM_AUD_SET_IPODIN_PATH  CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+12,  METHOD_BUFFERED, FILE_ANY_ACCESS) 
//shengkai110428
#define IOCTL_ODM_CD_VolumeSet  CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+14,  METHOD_BUFFERED, FILE_ANY_ACCESS) 
//shengkai0513
#define IOCTL_ODM_AUXIN_VolumeSet CTL_CODE(FILE_DEVICE_ODM_AUDIO,ODM_FCC_AUDIO+15,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//Haz111202_1 start
#define IOCTL_ODM_AUD_MIC_ON_OFF        CTL_CODE(FILE_DEVICE_ODM_AUDIO, ODM_FCC_AUDIO+16,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_AUD_SET_MIC_VOLUME    CTL_CODE(FILE_DEVICE_ODM_AUDIO, ODM_FCC_AUDIO+17,  METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_AUD_GET_MIC_VOLUME    CTL_CODE(FILE_DEVICE_ODM_AUDIO, ODM_FCC_AUDIO+18,  METHOD_BUFFERED, FILE_ANY_ACCESS)
//Haz111202_1 end

//katrina1119
#define IOCTL_ODM_SD_GET_CARD_ID       CTL_CODE(FILE_DEVICE_ODM_SDMMC,ODM_FCC_SDMMC,   METHOD_BUFFERED, FILE_ANY_ACCESS)
//winna0819
#define IOCTL_ODM_SD_GET_DETECT_STATE  CTL_CODE(FILE_DEVICE_ODM_SDMMC,ODM_FCC_SDMMC+1, METHOD_BUFFERED, FILE_ANY_ACCESS)

// joe0411 // -------------- for screen control function -----------------------------------------------
// joe0411
// joe0411 #define IOCTL_ODM_DISP_OFF_SCREEN	 CTL_CODE(FILE_DEVICE_ODM_DISPLAY,  ODM_FCC_DISPLAY+1,     METHOD_BUFFERED, FILE_ANY_ACCESS)
// joe0411 #define IOCTL_ODM_DISP_ON_SCREEN	 CTL_CODE(FILE_DEVICE_ODM_DISPLAY,  ODM_FCC_DISPLAY+2,     METHOD_BUFFERED, FILE_ANY_ACCESS)
// joe0411 #define IOCTL_ODM_DISP_GET_SCREEN_STATUS CTL_CODE(FILE_DEVICE_ODM_DISPLAY,  ODM_FCC_DISPLAY+3,     METHOD_BUFFERED, FILE_ANY_ACCESS)

// -------------- for timer / power control function -------------------------------------------------
#define IOCTL_ODM_POWER_SET_SUSPEND_TIMER     CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+1,    METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_POWER_RESET_SUSPEND_TIMER   CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+2,    METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_POWER_ENABLE_SUSPEND_TIMER  CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+3,    METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_POWER_DISABLE_SUSPEND_TIMER CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+4,    METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_POWER_SWITCHOFF_DEVICE      CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+5,    METHOD_BUFFERED, FILE_ANY_ACCESS) //joe1208

// bob080825	  For Wakeup interrupt 
#define IOCTL_ODM_POWER_GET_WAKEUP_INTERRUPT  CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+6,    METHOD_BUFFERED, FILE_ANY_ACCESS)
#define WAKEUPSRC_NOTFIND   0x4e6f5753
#define WAKEUPSRC_PWRBUTTON 0x1
#define WAKEUPSRC_ACPULLIN  0x2
#define WAKEUPSRC_USBPULLIN 0x4
#define WAKEUPSRC_SDCARDIN  0x8
#define WAKEUPSRC_GPRSMODE  0x10
#define WAKEUPSRC_RTCALARM  0x80000000

//bob090220
#define IOCTL_ODM_POWER_CHECK_STF_STATE         CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+7, METHOD_BUFFERED, FILE_ANY_ACCESS)
//bob090409
#define IOCTL_ODM_POWER_CHECK_SWITCH_POSITION   CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+8, METHOD_BUFFERED, FILE_ANY_ACCESS) 
//dick090407
#define IOCTL_ODM_POWER_SET_BKL_TIMEOUT         CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+9, METHOD_BUFFERED, FILE_ANY_ACCESS)

//daniel0402
//Enable driver to get the AP event:
#define IOCTL_ODM_POWER_SET_SYSWD		        CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+10, METHOD_BUFFERED, FILE_ANY_ACCESS)
//Event name definition:
#define PWR_ODM_EVENT_SYSWD		L"PWR_ODM_EVENT_SYSWD"
//application should set this event before expire time, otherwise, system watchdog timer will be expired and will do reset!!
#define SYSWD_DISABLE							0
#define SYSWD_ENABLE							1
//ronnie101110 typedef struct _tagSysWD 
//ronnie101110 {   
//ronnie101110        DWORD  dwSysWDTimeout;  //System watchdog expire time, unit is second; //application should set event during the time, otherwise, system watchdog timer will be //expired. 
//ronnie101110        DWORD  dwEnabelThr;     // disable function not ready now: 0: disable thread; 1: enable thread;
//ronnie101110        DWORD  dwReserved;      // this is reserved;
//ronnie101110 } SysWD, *pSysWD ;
//summer0107
#define IOCTL_ODM_POWER_SET_BKL_DOWNON          CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+11, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_POWER_GET_BKL_DOWN            CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+12, METHOD_BUFFERED, FILE_ANY_ACCESS)
//winna0819
#define IOCTL_ODM_POWER_PWRBUTTON_CONTROL       CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+13, METHOD_BUFFERED, FILE_ANY_ACCESS)
//raymond0224
#define IIOCTL_ODM_POWER_BATT_TYPE              CTL_CODE(FILE_DEVICE_ODM_POWER,   ODM_FCC_POWER+14, METHOD_BUFFERED, FILE_ANY_ACCESS)

// bob091112 - define for MGN , timer related
#define	IOCTL_ODM_POWEROFF_TIMER_ENABLE         CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_POWER_TIMER+0, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	IOCTL_ODM_POWEROFF_TIMER_DISABLE        CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_POWER_TIMER+1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	IOCTL_ODM_POWEROFF_TIMER_SET            CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_POWER_TIMER+2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	IOCTL_ODM_SUSPEND_TIMER_ENABLE          CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_POWER_TIMER+3, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	IOCTL_ODM_SUSPEND_TIMER_DISABLE         CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_POWER_TIMER+4, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	IOCTL_ODM_SUSPEND_TIMER_SET             CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_POWER_TIMER+5, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	IOCTL_ODM_DEMO_TIMER_ENABLE             CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_POWER_TIMER+6, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	IOCTL_ODM_DEMO_TIMER_DISABLE            CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_POWER_TIMER+7, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	IOCTL_ODM_DEMO_TIMER_SET                CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_POWER_TIMER+8, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define	OS_ODM_MSG_POWEROFF_TIMER_TIMEOUT		L"OS_ODM_MSG_POWEROFF_TIMER_TIMEOUT"
#define	OS_ODM_MSG_SUSPEND_TIMER_TIMEOUT		L"OS_ODM_MSG_SUSPEND_TIMER_TIMEOUT"
#define	OS_ODM_MSG_DEMO_TIMER_TIMEOUT		    L"OS_ODM_MSG_DEMO_TIMER_TIMEOUT"
// bob091112

//Johnny110111 start
#define	IOCTL_ODM_MCU_UPDATE	            CTL_CODE(FILE_DEVICE_ODM_MCU, ODM_FCC_MCU+0, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	IOCTL_ODM_MCU_AP_READY              CTL_CODE(FILE_DEVICE_ODM_MCU, ODM_FCC_MCU+1, METHOD_BUFFERED, FILE_ANY_ACCESS)
//Johnny110111 end

//RADQoo start
/*ronnie101110 start
typedef struct _CDPlay
{
	int iplay_command;	//play, stop, pause, ejectCD
	int iplay_mode;		//Repeat, random play
	int iFast_play;		//forward, backward,
	int iJump_play;		//next track, previous track
	int iIndex;		//index of song to play
	int itime;		//time of song to play
	DWORD resrved;
}CDPlay, *PCDPlay;

typedef struct _CDInfo_total
{
	int inum_tracks;	//number of tracks
	int itime_total;	//total time of all songs.
	DWORD resrved;
}CDInfo_total, *PCDInfo_total;

typedef struct _CDInfo_single
{
	int iIndex;		//index of song
	int itime;		// time of this song.
	char *sname_track;	//name of track
	char *sname_performer;	//name of performer
	char *sinfo_track;	//information of track
	DWORD resrved;
}CDInfo_single, *PCDInfo_single;
ronnie101110 end*/
#define	IOCTL_ODM_CDP_GETDATA                CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_CDP+1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define	IOCTL_ODM_CDP_PLAY                CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_CDP+2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_I2C_CDP_MASTER_RECEIVE      CTL_CODE(FILE_DEVICE_ODM_POWER, ODM_FCC_CDP+3, METHOD_BUFFERED, FILE_ANY_ACCESS)
//RADQoo end

// -------------- For backward compatible reason, we keep original IOCTL for map -------------
#define IOCTL_HAL_GET_MAPVENDER_OLD CTL_CODE( FILE_DEVICE_HAL, 2071, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_HAL_GET_MAPREGION     CTL_CODE( FILE_DEVICE_HAL, 2072, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_HAL_GET_MAPSUBREG     CTL_CODE( FILE_DEVICE_HAL, 2073, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_HAL_GET_MAPEXTRA      CTL_CODE( FILE_DEVICE_HAL, 2074, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_HAL_GET_MAPVENDER     CTL_CODE( FILE_DEVICE_HAL, 2075, METHOD_BUFFERED, FILE_ANY_ACCESS )
//bob0807
#define IOCTL_HAL_READ_HW_VERSION   CTL_CODE(FILE_DEVICE_HAL,2058, METHOD_BUFFERED, FILE_ANY_ACCESS)

// --------------joe0929: For TV control -------------
#define IOCTL_ODM_TV_UP_CHANNEL     CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+1, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_TV_DOWN_CHANNEL   CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+2, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_TV_UP_VOLUME      CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+3, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_TV_DOWN_VOLUME    CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+4, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_TV_ON_VIDEO       CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+5, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_TV_OFF_VIDEO      CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+6, METHOD_BUFFERED, FILE_ANY_ACCESS )
// --------------raymond0417 -------------
#define IOCTL_ODM_TV_SET_AUDIO_CHANNEL  CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+7, METHOD_BUFFERED, FILE_ANY_ACCESS )

// --------------mindy0730 -------------
#define IOCTL_ODM_CIM_QUERY         CTL_CODE(FILE_DEVICE_ODM_TV, ODM_FCC_TV+8, METHOD_BUFFERED, FILE_ANY_ACCESS)    //get some infor about CIM setting
#define IOCTL_ODM_CIM_CONFIGURE     CTL_CODE(FILE_DEVICE_ODM_TV, ODM_FCC_TV+9, METHOD_BUFFERED, FILE_WRITE_ACCESS)  //set source size to CIM
#define IOCTL_ODM_CIM_ON            CTL_CODE(FILE_DEVICE_ODM_TV, ODM_FCC_TV+10,METHOD_BUFFERED, FILE_WRITE_ACCESS) //CIM open
#define IOCTL_ODM_CIM_GETBUFFER     CTL_CODE(FILE_DEVICE_ODM_TV, ODM_FCC_TV+11,METHOD_BUFFERED, FILE_WRITE_ACCESS) //Get CIM DMA buffer address
#define IOCTL_ODM_CIM_OFF           CTL_CODE(FILE_DEVICE_ODM_TV, ODM_FCC_TV+12,METHOD_BUFFERED, FILE_WRITE_ACCESS) // CIM off
#define IOCTL_ODM_CIM_CHECKBUFFER   CTL_CODE(FILE_DEVICE_ODM_TV, ODM_FCC_TV+13,METHOD_BUFFERED, FILE_WRITE_ACCESS) //Check if CIM DMA data is ready
#define IOCTL_ODM_CIM_SOURCE        CTL_CODE(FILE_DEVICE_ODM_TV, ODM_FCC_TV+14,METHOD_BUFFERED, FILE_WRITE_ACCESS) //Check source format (NTSC/PAL/SECAM)

// --------------changes1017 -------------
#define IOCTL_ODM_TV_SET_SERIAL_NO  CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+15, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_TV_GET_SERIAL_NO  CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+16, METHOD_BUFFERED, FILE_ANY_ACCESS)

// mindy1023
#define IOCTL_ODM_CIM_SET_BRIGHTNESS CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+17, METHOD_BUFFERED, FILE_ANY_ACCESS)

//Min090826 - Add IOCTL for tuner power on/off
#define IOCTL_ODM_Tuner_POWER_ON     CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+18, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ODM_Tuner_POWER_OFF    CTL_CODE( FILE_DEVICE_ODM_TV, ODM_FCC_TV+19, METHOD_BUFFERED, FILE_ANY_ACCESS)

// --------------span0205: For Video source input control -------------
#define IOCTL_ODM_VIDEO_SET_SOURCE_INPUT CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+1, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_VIDEO_GET_SOURCE_INPUT CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+2, METHOD_BUFFERED, FILE_ANY_ACCESS )
// span0205,  enum for Video source input

// lucy090224 start
#define IOCTL_ODM_VIDEO_OPEN_AVIN_POWER  CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+3, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_VIDEO_CLOSE_AVIN_POWER CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+4, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_VIDEO_ON               CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+5, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_VIDEO_OFF              CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+6, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_VIDEO_IN_SIZE          CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+7, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_VIDEO_OUT_SIZE         CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+8, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_VIDEO_OUT_POS          CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+9, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_VIDEO_GET_AVIN_STATUS  CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+10,METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_VIDEO_SET_LAYER        CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+11,METHOD_BUFFERED, FILE_ANY_ACCESS )
// Kevin.H add
#define IOCTL_ODM_VIDEO_CHANGE_COLOR     CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+12,METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_VIDEO_GET_FORMAT       CTL_CODE( FILE_DEVICE_ODM_VIDEO, ODM_FCC_VIDEO+13,METHOD_BUFFERED, FILE_ANY_ACCESS ) // Kevin.H_110318
//ronnie101110 typedef struct _VideoSizePos
//ronnie101110 {
//ronnie101110 	unsigned short x;
//ronnie101110 	unsigned short y;
//ronnie101110 }VideoSizePos, *PVideoSizePos;
#define AVI_APOPEN         (1<<0)   //AP created the handle of AVIN driver 
#define AVI_MODULE_ON      (1<<1)   //The AVIN chip is powered on
#define AVI_VIDEO_ON       (1<<2)   //the video is on showing
#define AVI_OVERLAY        (1<<3)   //The overlay layer is selected
#define AVI_LOCK           (1<<16)  //Lock the AVIN signal
#define AVI_SRCFORMAT_NTSC (1<<17)  //The src format is NTSC
#define AVI_CABLEIN        (1<<18)  //The cable is plugged in
// lucy090224 end

// --------------wen0706: For Port Control (used in NN746 only)-------------
#define IOCTL_ODM_PORT_GET_SPEED_PULSE   CTL_CODE( FILE_DEVICE_ODM_PORT, ODM_FCC_PORT+1, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_PORT_GET_PARKING_BRAKE CTL_CODE( FILE_DEVICE_ODM_PORT, ODM_FCC_PORT+2, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_PORT_GET_REVERSE       CTL_CODE( FILE_DEVICE_ODM_PORT, ODM_FCC_PORT+3, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_PORT_GET_KMODE         CTL_CODE( FILE_DEVICE_ODM_PORT, ODM_FCC_PORT+4, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_PORT_SET_CPU_WDT       CTL_CODE( FILE_DEVICE_ODM_PORT, ODM_FCC_PORT+5, METHOD_BUFFERED, FILE_ANY_ACCESS )

// --------------jerry1121: For FM Transmitter-------------
#define IOCTL_ODM_FMT_SET_FREQ   CTL_CODE( FILE_DEVICE_ODM_FMTRANSMITTER, ODM_FCC_FMTRANSMITTER+1, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_FMT_SET_PA     CTL_CODE( FILE_DEVICE_ODM_FMTRANSMITTER, ODM_FCC_FMTRANSMITTER+2, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_FMT_SET_VOLUME CTL_CODE( FILE_DEVICE_ODM_FMTRANSMITTER, ODM_FCC_FMTRANSMITTER+3, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_FMT_SET_MODE   CTL_CODE( FILE_DEVICE_ODM_FMTRANSMITTER, ODM_FCC_FMTRANSMITTER+4, METHOD_BUFFERED, FILE_ANY_ACCESS )

// --------------mona0420: for Dimmer sensor: 1. get the ADC value 2. enable/disalbe auot control of  backlight-------------
#define IOCTL_ODM_DMS_GET_ADC       CTL_CODE( FILE_DEVICE_ODM_DIMMERSENSOR, ODM_FCC_DIMMERSENSOR+1, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_ODM_DMS_SET_BKLMODE   CTL_CODE( FILE_DEVICE_ODM_DIMMERSENSOR, ODM_FCC_DIMMERSENSOR+2, METHOD_BUFFERED, FILE_ANY_ACCESS )

// -------------- Jerry_091110:  for VPA get mode and status   ----------
#define IOCTL_ODM_VPA_GET_MODE   CTL_CODE(FILE_DEVICE_ODM_VPA,ODM_FCC_VPA+1, METHOD_BUFFERED, FILE_ANY_ACCESS)
//Note: current just support the two mode : MGN_VPA_MODE_UNKNOWN and MGN_VPA_MODE_AC_POWER
#define ODM_VPA_MODE_UNKNOWN            0x00
#define ODM_VPA_MODE_HEADPHONE          0x01
#define ODM_VPA_MODE_AC_POWER	   	    0x02
#define ODM_VPA_MODE_MASS_STORAGE       0x04
#define ODM_VPA_MODE_RDS                0x08 

#define IOCTL_ODM_VPA_GET_STATUS        CTL_CODE(FILE_DEVICE_ODM_VPA,ODM_FCC_VPA+2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define ODM_VPA_STATUS_DISCONNECTED     0x00
#define ODM_VPA_STATUS_CONNECTED        0x01

// ===== ESCAPE CODE ===============================================================================================================================================================
//
//  Microsoft reserves all escape code values up to 99,999
//  We start our escape code starting at the decimal value 100,000
//  Escape code for ODM GPS specific functions
//
#define DRVESC_ODM_DISP_OFF_SCREEN          100000
#define DRVESC_ODM_DISP_ON_SCREEN           100001
#define DRVESC_ODM_DISP_GET_SCREEN_STATUS   100002
#define DRVESC_ODM_DISP_SET_SCREEN_STATUS   100003//RYAN.LIN111125

// ====== WINDOW MESSAGE =======================================================================================================================================================
// All messagees are named in form of WM_ODM_xxx
//
// NOTE: 0 through WM_USER¡V1 Messages reserved for use by the system.   (WM_USER=0x0400)
//  WM_USER through 0x7FFF Integer messages for use by private window classes.  (ODM driver team use this section)
//  WM_APP through 0xBFFF Messages available for use by applications.  (WM_APP=0x8000)
//  

// -------------- For old project , when the old project is phase out, these definition will no longer to use ----------------------
#define WM_MITAC_OFFSET             2000
#define WM_OEM_OFFSET               200
#define WM_OEM_MITAC_OFFSET        (WM_MITAC_OFFSET + WM_OEM_OFFSET)

#define WM_OEM_POWERBUTTON_PRESSED (WM_USER + WM_OEM_MITAC_OFFSET + 31) // PWRBTN short pressed. Only used in MRS current projects. New project shall use WM_ODM_PWRBTN_SHORT_PRESS.
#define WM_OEM_SD_REMOVED          (WM_USER + WM_OEM_MITAC_OFFSET + 11)
#define WM_OEM_SD_INSERT           (WM_USER + WM_OEM_MITAC_OFFSET + 12)
#define WM_OEM_USB_CONNECT         (WM_USER + WM_OEM_MITAC_OFFSET + 21)
#define WM_OEM_USB_DISCONNECT      (WM_USER + WM_OEM_MITAC_OFFSET + 22)

// Ray0702
#define WM_OEM_KEYLOCK             (2200 + 51)      //  see comment in WM_ODM_KEYLOCK 

//--------------- For New project -----------------------------------
#define WM_ODM_START                    0x0401   // 0x401=1025

#define WM_ODM_REMOVE_SD               (WM_ODM_START + 11)
#define WM_ODM_INSERT_SD               (WM_ODM_START + 12)

//Elliot0814
//JC_T10_EN_IPOD_CONTROL #define WM_ODM_REMOVE_IPOD            (WM_ODM_START +15)
//JC_T10_EN_IPOD_CONTROL #define WM_ODM_INSERT_IPOD            (WM_ODM_START +16)
#define WM_ODM_REMOVE_IPOD            (WM_ODM_START +15)    //JC_T10_EN_IPOD_CONTROL
#define WM_ODM_INSERT_IPOD            (WM_ODM_START +16)    //JC_T10_EN_IPOD_CONTROL
#define WM_ODM_SET_SAMPLERATE         (WM_ODM_START +17)    //JC_T03_EN_IPOD_USBAUDIO
#define WM_ODM_READ_IPODCPREG         (WM_ODM_START +18)    //JC_R07_EN_IPOD_USBAUDIO
#define WM_ODM_WRITE_IPODCPREG        (WM_ODM_START +19)    //JC_R07_EN_IPOD_USBAUDIO

#define WM_ODM_CONNECT_USB             (WM_ODM_START + 21)
#define WM_ODM_DISCONNECT_USB          (WM_ODM_START + 22)

//Jerry1207
#define WM_ODM_CONNECT_USB_REBOOT      (WM_ODM_START + 23)
#define WM_ODM_PMU_RESUME              (WM_ODM_START + 31) //eric_R04_110225
#define WM_ODM_PMU_SUSPEND             (WM_ODM_START + 32) // PWRBTN short pressed. Only used in Mantas, PT310, Picasso100. New project shall use WM_ODM_PWRBTN_SHORT_PRESS.

// Bob0601														   
#define WM_ODM_PWRBTN_SHORT_PRESS      (WM_ODM_START + 33) // PWRBTN short press, Suspend device without showing up a message box.
#define WM_ODM_PWRBTN_LONG_PRESS       (WM_ODM_START + 34) // PWRBTN press-n-hold 5 seconds. It may pop up a message box to get confirm from user, per product spec. 
//bob090224
#define WM_ODM_PWRBTN_RELEASE          (WM_ODM_START + 35) //Switch OFF->ON (app need unlock system if under lock state)

// Jason0607
#define WM_ODM_OPEN_CAMERA             (WM_ODM_START + 41)  // when user open camera(front cover), driver post this WM
#define WM_ODM_CLOSE_CAMERA            (WM_ODM_START + 42)  // when user close camera(front cover), driver post this WM

// Ray0702
#define WM_ODM_KEYLOCK                 (WM_ODM_START + 51)  // if bKeyLock= TRUE; then postmessage WM_ODM_KEYLOCK.
                                                            // if bKeyLock= FALSE; do the normal things as usual. The bKeyLock states will be set in keypad driver.
//Haz070823 - to support PT310 AP to be able to tell apart messages sent by Power from by Keyboard in power saving mode, in which system will not be waken up by pressing keyboard button
#define WM_ODM_KEYLOCK_KBD             (WM_ODM_START + 52)  //Haz070823													

//MitacSoleus_080110: report GSM SIM card is Removed / Inserted
#define WM_ODM_REMOVE_SIM              (WM_ODM_START + 53)
#define WM_ODM_INSERT_SIM              (WM_ODM_START + 54)

// window message for xxx funtion , continue from here

// yu0819 - window message for FM transmitter
// To inform AP to set the FM transmitter work mode when FM transmitter is running.
#define WM_ODM_FMTRANSMITTER_STANDBY   (WM_ODM_START + 61)
#define WM_ODM_FMTRANSMITTER_NORMAL    (WM_ODM_START + 62)
// To inform AP to check whether the antenna is in when FM radio is running.
#define WM_ODM_FMRADIO_ANTENNA_DETECT  (WM_ODM_START + 63)
#define WM_ODM_SWITCH_FMTRANSMITTER  (WM_ODM_START + 64) // jerry1121 

//Jerry_091110  start
#define OS_ODM_MSG_VPA_CONNECTED	(WM_ODM_START + 70)
#define OS_ODM_MSG_VPA_DISCONNECTED	(WM_ODM_START + 71)
//Jerry_091110  end
#define WM_ODM_CDP_DISKIO       (WM_ODM_START + 80)

//sneeper0703
// ====Waveform Aduio Driver Messages =============================
//============
//Old interface
//============
//For Medion/Magellen Mic volume gain
#define WIDM_SET_MIC_VOLUME       210  
#define WIDM_GET_MIC_VOLUME       220
//For Hamback  
#define WODM_TEL_MUTE             240
//For BT audio routing
#define WODM_BT_SCO_AUDIO_CONTROL 500
//For Echo on/off
#define WIDM_SET_SWECHO           600

//============
//New Interface
//============
//For output control
#define WODM_ODM_BASE	1000
//#define WODM_ODM_SWITCH_FMTRANSMITTER	(WODM_ODM_BASE+1)  // This one is cancelled because it has same function with IOCTL_ODM_AUD_SELECT_FM 090702

// val0430
//#define WODM_ODM_FMT_STANDBY_SWITCH     (WODM_ODM_BASE+2)  // this is old one, please don't use it
#define WODM_ODM_FMT_AUTO_STANDBY_SWITCH  (WODM_ODM_BASE+2)

//For input control 
#define WIDM_ODM_BASE	2000
#define WIDM_ODM_SWITCH_FMRADIO		(WIDM_ODM_BASE+1)
#define WIDM_ODM_SET_FMRADIO_VOLUME	(WIDM_ODM_BASE+2)
#define WIDM_ODM_GET_FMRADIO_VOLUM	(WIDM_ODM_BASE+3)
#define WIDM_ODM_GET_ANTENNA_STATE	(WIDM_ODM_BASE+4)

//shengkai1214 s
#define WM_ODM_AUDIO_PCM_ENABLE   (WM_ODM_START + 72)
#define WM_ODM_AUDIO_PCM_DISABLE    (WM_ODM_START + 73)
//shengkai1214 e
#if __cplusplus
}
#endif

#endif // __ODM_IOCTL_H 	 //bob070725



