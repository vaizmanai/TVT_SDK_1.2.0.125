
#ifndef _DVR_NET_SDK_H_
#define _DVR_NET_SDK_H_

#include "dvrdvstypedef.h"
#include "dvrdvsconfig.h"
#include "dvrdvsdefine.h"

#ifdef WIN32

#define CALL_METHOD __stdcall

#ifdef __cplusplus
#define __EXTERN_C extern "C"
#else
#define __EXTERN_C extern
#endif

#ifdef DVR_NET_SDK_EXPORTS
#define NET_SDK_API __EXTERN_C __declspec(dllexport)
#else
#ifndef __STATIC__
#define NET_SDK_API __EXTERN_C __declspec(dllimport)
#else
#define NET_SDK_API
#endif
#endif

#else

#define CALL_METHOD
#define NET_SDK_API __attribute__ ((visibility("default")))

#endif

#if __cplusplus
extern "C"{
#endif

//#define GetDeviceIPCInfoLogFile "/root/"
//#define gettid() syscall(__NR_gettid)
//LastError����
typedef enum
{
	NET_SDK_SUCCESS,
	NET_SDK_PASSWORD_ERROR,
	NET_SDK_NOENOUGH_AUTH,
	NET_SDK_NOINIT,
	NET_SDK_CHANNEL_ERROR,
	NET_SDK_OVER_MAXLINK,
	NET_SDK_LOGIN_REFUSED,
	NET_SDK_VERSION_NOMATCH,
	NET_SDK_NETWORK_FAIL_CONNECT,
	NET_SDK_NETWORK_NOT_CONNECT,
	NET_SDK_NETWORK_SEND_ERROR,
	NET_SDK_NETWORK_RECV_ERROR,
	NET_SDK_NETWORK_RECV_TIMEOUT,
	NET_SDK_NETWORK_ERRORDATA,
	NET_SDK_ORDER_ERROR,
	NET_SDK_OPER_BY_OTHER,
	NET_SDK_OPER_NOPERMIT,
	NET_SDK_COMMAND_TIMEOUT,
	NET_SDK_ERROR_SERIALPORT,
	NET_SDK_ERROR_ALARMPORT,
	NET_SDK_PARAMETER_ERROR,
	NET_SDK_CHAN_EXCEPTION,
	NET_SDK_NODISK,
	NET_SDK_ERROR_DISKNUM,
	NET_SDK_DISK_FULL,
	NET_SDK_DISK_ERROR,
	NET_SDK_NOSUPPORT,
	NET_SDK_BUSY,
	NET_SDK_MODIFY_FAIL,
	NET_SDK_PASSWORD_FORMAT_ERROR,
	NET_SDK_DISK_FORMATING,
	NET_SDK_DVR_NORESOURCE,
	NET_SDK_DVR_OPRATE_FAILED,
	NET_SDK_OPEN_HOSTSOUND_FAIL,
	NET_SDK_DVR_VOICEOPENED,
	NET_SDK_TIME_INPUTERROR,
	NET_SDK_NOSPECFILE,
	NET_SDK_CREATEFILE_ERROR,
	NET_SDK_FILEOPENFAIL,
	NET_SDK_OPERNOTFINISH,
	NET_SDK_GETPLAYTIMEFAIL,
	NET_SDK_PLAYFAIL,
	NET_SDK_FILEFORMAT_ERROR,
	NET_SDK_DIR_ERROR,
	NET_SDK_ALLOC_RESOURCE_ERROR,
	NET_SDK_AUDIO_MODE_ERROR,
	NET_SDK_NOENOUGH_BUF,
	NET_SDK_CREATESOCKET_ERROR,
	NET_SDK_SETSOCKET_ERROR,
	NET_SDK_MAX_NUM,
	NET_SDK_USERNOTEXIST,
	NET_SDK_WRITEFLASHERROR,
	NET_SDK_UPGRADEFAIL,
	NET_SDK_CARDHAVEINIT,
	NET_SDK_PLAYERFAILED,
	NET_SDK_MAX_USERNUM,
	NET_SDK_GETLOCALIPANDMACFAIL,
	NET_SDK_NOENCODEING,
	NET_SDK_IPMISMATCH,
	NET_SDK_MACMISMATCH,
	NET_SDK_UPGRADELANGMISMATCH,
	NET_SDK_MAX_PLAYERPORT,
	NET_SDK_NOSPACEBACKUP,
	NET_SDK_NODEVICEBACKUP,
	NET_SDK_PICTURE_BITS_ERROR,
	NET_SDK_PICTURE_DIMENSION_ERROR,
	NET_SDK_PICTURE_SIZ_ERROR,
	NET_SDK_LOADPLAYERSDKFAILED,
	NET_SDK_LOADPLAYERSDKPROC_ERROR,
	NET_SDK_LOADDSSDKFAILED,
	NET_SDK_LOADDSSDKPROC_ERROR,
	NET_SDK_DSSDK_ERROR,
	NET_SDK_VOICEMONOPOLIZE,
	NET_SDK_JOINMULTICASTFAILED,
	NET_SDK_CREATEDIR_ERROR,
	NET_SDK_BINDSOCKET_ERROR,
	NET_SDK_SOCKETCLOSE_ERROR,
	NET_SDK_USERID_ISUSING,
	NET_SDK_PROGRAM_EXCEPTION,
	NET_SDK_WRITEFILE_FAILED,
	NET_SDK_FORMAT_READONLY,
	NET_SDK_WITHSAMEUSERNAME,
	NET_SDK_DEVICETYPE_ERROR,
	NET_SDK_LANGUAGE_ERROR,
	NET_SDK_PARAVERSION_ERROR,
	NET_SDK_FILE_SUCCESS,
	NET_SDK_FILE_NOFIND,
	NET_SDK_NOMOREFILE,
	NET_SDK_FILE_EXCEPTION,
	NET_SDK_TRY_LATER,
	NET_SDK_DEVICE_OFFLINE,
	NET_SDK_CREATEJPEGSTREAM_FAIL,
    NET_SDK_USER_ERROR_NO_USER,
    NET_SDK_USER_ERROR_USER_OR_PASSWORD_IS_NULL,
    NET_SDK_USER_ERROR_ALREDAY_LOGIN,
    NET_SDK_USER_ERROR_SYSTEM_BUSY,

}NET_SDK_ERROR;

enum NET_DEVICE_STATUS
{
	NET_DEVICE_STATUS_CONNECTED,
	NET_DEVICE_STATUS_DISCONNECT,
};

enum NET_SDK_STREAM_TYPE
{
	NET_SDK_MAIN_STREAM,
	NET_SDK_SUB_STREAM,
};

enum NET_SDK_PLAYCTRL_TYPE
{
	NET_SDK_PLAYCTRL_PAUSE,
	NET_SDK_PLAYCTRL_FF,
	NET_SDK_PLAYCTRL_REW,
	NET_SDK_PLAYCTRL_RESUME,
	NET_SDK_PLAYCTRL_STOP,
	NET_SDK_PLAYCTRL_FRAME,
	NET_SDK_PLAYCTRL_NORMAL,
	NET_SDK_PLAYCTRL_STARTAUDIO,	//�ÿ������ͼ�����������������ֻ����SDK�ڲ�������ʾʱ�Ż�������
	NET_SDK_PLAYCTRL_STOPAUDIO,
	NET_SDK_PLAYCTRL_AUDIOVOLUME,
	NET_SDK_PLAYCTRL_SETPOS,
};

enum NET_SDK_RPB_SPEED
{
	NET_SDK_RPB_SPEED_1_32X = 1,
	NET_SDK_RPB_SPEED_1_16X,
	NET_SDK_RPB_SPEED_1_8X,		//1/8
	NET_SDK_RPB_SPEED_1_4X,		//1/4
	NET_SDK_RPB_SPEED_1_2X,		//1/2
	NET_SDK_RPB_SPEED_1X,		//1
	NET_SDK_RPB_SPEED_2X,
	NET_SDK_RPB_SPEED_4X,
	NET_SDK_RPB_SPEED_8X,
	NET_SDK_RPB_SPEED_16X,
	NET_SDK_RPB_SPEED_32X,
};

const int MAX_NAMELEN			= 36;
const int MAX_CONTENTLEN		= 512;

#pragma pack(4)

//��¼�ṹ����
typedef struct _net_sdk_deviceinfo
{
	unsigned char	localVideoInputNum;		//������Ƶ����ͨ����Ŀ
	unsigned char	audioInputNum;			//��Ƶ����ͨ����Ŀ
	unsigned char	sensorInputNum;			//����������ͨ����Ŀ
	unsigned char	sensorOutputNum;		//�̵��������Ŀ
	unsigned int   displayResolutionMask;  //��������ѡ��ķֱ���

	unsigned char	videoOuputNum;			//��Ƶ�����Ŀ����֧�ֻط����ͨ������
	unsigned char	netVideoOutputNum;		//����ط����ͨ����Ŀ
	unsigned char	netVideoInputNum;		//�����źŽ���ͨ����Ŀ
	unsigned char	IVSNum;					//���ܷ���ͨ����Ŀ

	unsigned char	presetNumOneCH;			//ÿ��ͨ��Ԥ�õ���Ŀ
	unsigned char	cruiseNumOneCH;			//ÿ��ͨ��Ѳ������Ŀ
	unsigned char	presetNumOneCruise;		//ÿ��Ѳ���ߵ�Ԥ�õ���Ŀ
	unsigned char	trackNumOneCH;			//ÿ��ͨ���켣��Ŀ

	unsigned char	userNum;				//�û���Ŀ 
	unsigned char	netClientNum;			//���ͻ�����Ŀ
	unsigned char	netFirstStreamNum;		//�����������ͨ�������Ŀ����ͬʱ�����м����ͻ��˲鿴������
	unsigned char	deviceType;				//�豸����

	unsigned char	doblueStream;			//�Ƿ����ṩ˫����
	unsigned char	audioStream;			//�Ƿ����ṩ��Ƶ��
	unsigned char	talkAudio;				//�Ƿ��жԽ�����: 1��ʾ�жԽ�����;0��ʾû��
	unsigned char	bPasswordCheck;			//�����Ƿ�Ҫ��������

	unsigned char	defBrightness;			//ȱʡ����
	unsigned char	defContrast;			//ȱʡ�Աȶ�
	unsigned char	defSaturation;			//ȱʡ���Ͷ�
	unsigned char	defHue;					//ȱʡɫ��

	unsigned short	videoInputNum;			//��Ƶ����ͨ����Ŀ�����ؼ����磩
	unsigned short  deviceID;				//�豸ID��
	unsigned int   videoFormat;            //ϵͳ��ǰ��ʽ

	//������FUNC_REMOTE_UPGRADE��Ӧ�Ĺ��ܣ���ô��FUNC_REMOTE_UPGRADE������Ϊ1������Ϊ�㡣
	unsigned int	function[8];			//��������

	unsigned int	deviceIP;				//�豸�����ַ
	unsigned char	deviceMAC[6];			//�豸�����ַ
	unsigned short	devicePort;				//�豸�˿�

	unsigned int	buildDate;				//��������:year<<16 + month<<8 + mday
	unsigned int	buildTime;				//����ʱ��:hour<<16 + min<<8 + sec

	char			deviceName[36];			//�豸����

	char	firmwareVersion[36];			//�̼��汾
	char	kernelVersion[64];				//�ں˰汾
	char	hardwareVersion[36];			//Ӳ���汾
	char	MCUVersion[36];					//��Ƭ���汾
    char	firmwareVersionEx[100];			//�̼��汾��չ����Ҫ����²�Ʒ
    char	deviceProduct[28];			//�豸�ͺ�
}NET_SDK_DEVICEINFO, *LPNET_SDK_DEVICEINFO;

//����֡ͷ����
typedef struct _net_sdk_frame_info
{
	unsigned int		deviceID;
	unsigned int       channel;
	unsigned int		frameType;	//�ο�DD_FRAME_TYPE
	unsigned int		length;
	unsigned int		keyFrame;	//0���ǹؼ�֡ 1���ؼ�֡
	unsigned int       width;
	unsigned int       height;
	unsigned int		frameIndex;
	unsigned int		frameAttrib;//�ο�DD_FRAME_ATTRIB
	unsigned int		streamID;
	LONGLONG			time;	   //��1970��1��1��0��0��0�뿪ʼ�ľ���ʱ�䣬��λ΢��
	LONGLONG			relativeTime;//���ʱ�䣬��λ΢��
}NET_SDK_FRAME_INFO;

//¼��ʱ����Ϣ����
typedef struct _net_sdk_rec_time
{
	DWORD			dwChannel;	//ͨ����
	DD_TIME			startTime;	//�ö�¼��ʼʱ��
	DD_TIME			stopTime;	//�ö�¼�����ʱ��
}NET_SDK_REC_TIME;

typedef struct _net_sdk_rec_file
{
	DWORD			dwChannel;
	DWORD			bFileLocked;
	DD_TIME			startTime;
	DD_TIME			stopTime;
	DWORD			dwRecType;
	DWORD			dwPartition;
	DWORD			dwFileIndex;
}NET_SDK_REC_FILE;

typedef struct _net_sdk_rec_event
{
	DWORD			dwChannel;
	DD_TIME			startTime;
	DD_TIME			stopTime;
	DWORD			dwRecType;	//DD_RECORD_TYPE
}NET_SDK_REC_EVENT;

//��־��Ϣ����
typedef struct _net_sdk_log
{
	DD_TIME			strLogTime;
	DWORD			dwMajorType;
	DWORD			dwMinorType;
	char			sNetUser[MAX_NAMELEN];
	DWORD			dwRemoteHostAddr;
	char			sContent[MAX_CONTENTLEN];
}NET_SDK_LOG,*LPNET_SDK_LOG;

typedef struct _net_sdk_event
{
	unsigned short chnn;			//�¼���Ӧ��ͨ��
	unsigned short type;			//�¼����ͣ�DD_EVENT_TYPE
	DD_TIME        startTime;		//�¼������Ŀ�ʼʱ��
	DD_TIME        endTime;			//�¼��Ľ���ʱ��
}NET_SDK_EVENT,*LPNET_SDK_EVENT;

typedef struct _net_sdk_clientinfo
{
	LONG    lChannel;
	LONG    streamType;
	HWND    hPlayWnd;
}NET_SDK_CLIENTINFO, *LPNET_SDK_CLIENTINFO;

//�豸�ϴ���Ϣ����
enum NET_SDK_DEVICE_MSG_TYPE
{
	NET_SDK_ALARM,		//�豸������Ϣ
	NET_SDK_RECORD,		//�豸¼����Ϣ
	NET_SDK_IVM_RULE,	//������Ϊ������Ϣ(��ʱ����)
	NET_SDK_TRADEINFO,	//ATM������Ϣ(��ʱ����)
	NET_SDK_IPCCFG,		//�����DVR��IPC��Ϣ���(��ʱ����)
};

//�豸�ϴ���ϢΪ��������ʱ�ľ��屨������
enum NET_SDK_ALARM_TYPE
{
	NET_SDK_ALARM_TYPE_MOTION,		//�ƶ����
	NET_SDK_ALARM_TYPE_SENSOR,		//�ź�������
	NET_SDK_ALARM_TYPE_VLOSS,		//�źŶ�ʧ
	NET_SDK_ALARM_TYPE_SHELTER,		//�ڵ�����
	NET_SDK_ALARM_TYPE_DISK_FULL,	//Ӳ����
	NET_SDK_ALARM_TYPE_DISK_UNFORMATTED,//Ӳ��δ��ʽ��
	NET_SDK_ALARM_TYPE_DISK_WRITE_FAIL,	//��дӲ�̳���
	NET_SDK_ALARM_TYPE_EXCEPTION,
};


//�豸�ϴ���ϢΪ���ܱ������¼�����
enum NET_SDK_IVM_RULE_TYPE
{
    NET_SDK_IVM_RULE_TYPE_VFD, //����ʶ�𱨾�  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_SCENE, //��Ƶ�쳣��ϳ����仯  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_CLARITY, //��Ƶ�쳣�����Ƶģ��  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_COLOR, //��Ƶ�쳣�����Ƶƫɫ  NET_SDK_IVM_STATUS_INFO
};


/************************************************************************/
    /*  ���屨��������������Դ    �ںܶ�ط�ʹ�����ö��ֵ��ʱ����ı�������BYTE����������
    ҪС�Ķ���*/
    /************************************************************************/
enum NET_SDK_N9000_ALARM_TYPE
{
    NET_SDK_N9000_ALARM_TYPE_RANGE_BEGIN,
    NET_SDK_N9000_ALARM_TYPE_MOTION=0x01,/////�ƶ���ⱨ������
    NET_SDK_N9000_ALARM_TYPE_SENSOR,/////��������������
    NET_SDK_N9000_ALARM_TYPE_VLOSS,////��Ƶ��ʧ��������
    NET_SDK_N9000_ALARM_TYPE_FRONT_OFFLINE, //////ǰ���豸���߱���
    NET_SDK_N9000_ALARM_TYPE_OSC,           ////��Ʒ������ⱨ��
    NET_SDK_N9000_ALARM_TYPE_AVD,           ////��Ƶ�쳣��ⱨ��
    NET_SDK_N9000_ALARM_TYPE_AVD_SCENE,//only IPC
    NET_SDK_N9000_ALARM_TYPE_AVD_CLARITY,//only IPC
    NET_SDK_N9000_ALARM_TYPE_AVD_COLOR,//only IPC

    NET_SDK_N9000_ALARM_TYPE_PEA_TRIPWIRE,  ////Խ����ⱨ��
    NET_SDK_N9000_ALARM_TYPE_PEA_PERIMETER, ////����������ⱨ��
    NET_SDK_N9000_ALARM_TYPE_PEA,           ////Խ������������������
    NET_SDK_N9000_ALARM_TYPE_VFD,           ////������⣨Ŀǰ��IPC��
    NET_SDK_N9000_ALARM_TYPE_CDD,           ////Crowdy density
    NET_SDK_N9000_ALARM_TYPE_IPD,           ////people intrusion
    NET_SDK_N9000_ALARM_TYPE_CPC,           ////people counting

    NET_SDK_N9000_ALARM_TYPE_GPS_SPEED_OVER=0x21,//�ͳ����йصı���������
    NET_SDK_N9000_ALARM_TYPE_GPS_CROSS_BOADER,//Խ��
    NET_SDK_N9000_ALARM_TYPE_GPS_TEMPERATURE_OVER,//�¶ȱ���
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_X,//GSENSOR����
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_Y,
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_Z,

    NET_SDK_N9000_ALARM_TYPE_EXCEPTION = 0x41,
    NET_SDK_N9000_ALARM_TYPE_IP_CONFLICT,   /////IP��ַ��ͻ
    NET_SDK_N9000_ALARM_TYPE_DISK_IO_ERROR, /////����IO����
    NET_SDK_N9000_ALARM_TYPE_DISK_FULL,	   /////������
    NET_SDK_N9000_ALARM_TYPE_RAID_SUBHEALTH, //�����ǽ���
    NET_SDK_N9000_ALARM_TYPE_RAID_UNAVAILABLE, //���в�����
    NET_SDK_N9000_ALARM_TYPE_ILLEIGAL_ACCESS,  /////�Ƿ�����
    NET_SDK_N9000_ALARM_TYPE_NET_DISCONNECT,  /////����Ͽ�
    NET_SDK_N9000_ALARM_TYPE_NO_DISK,		////������û�д���
    NET_SDK_N9000_ALARM_TYPE_SIGNAL_SHELTER, //�ź��ڵ�
    NET_SDK_N9000_ALARM_TYPE_HDD_PULL_OUT, //ǰ���Ӳ�̰γ�

    NET_SDK_N9000_ALARM_TYPE_ALARM_OUT = 0x51,  /////������������ͣ��������Ҳ��״̬��Ҫ����

    NET_SDK_N9000_ALARM_TYPE_RANGE_END = 0xFF,////���ܳ������ֵ  ��������
};


//�豸�ϴ���ϢΪ��������ʱ���ϴ���Ϣ�ṹ
typedef struct _net_sdk_alarminfo
{
	DWORD		dwAlarmType;
	DWORD		dwSensorIn;		//��������������˿ں�
	DWORD		dwChannel;		//�ڱ�����ͨ�����ʱ����ʾ������ͨ����
	DWORD		dwDisk;			//�ڴ��̱���ʱ����ʾ���������Ĵ��̺�
}NET_SDK_ALARMINFO;

typedef struct _net_sdk_record_status
{
	DWORD		dwRecordType;		//DD_RECORD_TYPE
	DWORD		dwChannel;
}NET_SDK_RECORD_STATUS;

typedef struct _net_sdk_IVM_rule_status
{
    DWORD		dwIVMType;		//NET_SDK_IVM_RULE_TYPE
    DWORD		dwIVMSize;      //NET_SDK_IVM_RULE_TYPE���¼���Ӧ�Ľṹ���С
}
NET_SDK_IVM_RULE_STATUS;

//�������澯�ϱ�
typedef struct _net_sdk_IVM_status_info
{
    DWORD		dwAlarmType;    //NET_SDK_IVM_RULE_TYPE
    DWORD		dwChannel;		//�澯ͨ����

}NET_SDK_IVM_STATUS_INFO;

typedef enum _net_sdk_disk_status
{	
	NET_SDK_DISK_NORMAL,				//���� 
	NET_SDK_DISK_NO_FORMAT,				//δ��ʽ��
}NET_SDK_DISK_STATUS;

typedef enum _net_sdkdisk_property
{
	NET_SDK_DISK_READ_WRITE = 0,			//��������д
	NET_SDK_DISK_ONLY_READ,					//ֻ�ܶ�������д
	NET_SDK_DISK_REDUNDANCY					//����
}NET_SDK_DISK_PROPERTY;

typedef enum _net_sdk_connect_type
{
	NET_SDK_CONNECT_TCP		= 0,			//TCP��ʽ��½
	NET_SDK_CONNECT_NAT		= 1,			//NAT��ʽ��½
    NET_SDK_CONNECT_NAT_TCP		= 2,			//��NAT���е�TCP����

	NET_SDK_CONNECT_END
}NET_SDK_CONNECT_TYPE;

typedef enum _net_sdk_camera_type
{
	NET_SDK_NOT_SUPPORT_PTZ		= 0,		//��֧����̨��ǹ��
	NET_SDK_DOME_SUPPORT_PTZ	= 1,		//֧����̨��ǹ��
	NET_SDK_SUPPORT_PTZ			= 2,		//֧����̨�����
	NET_SDK_PTZ_END
}NET_SDK_CAMERA_TYPE;

typedef struct _net_sdk_disk_info
{
	LONG		diskIndex;			//���̱��
	short		diskStatus;			//����״̬���ο�NET_SDK_DISK_STATUS
	short		diskProperty;		//����״̬���ο�NET_SDK_DISK_PROPERTY
	DWORD		diskTotalSpace;		//�����ܿռ䣬��λMB
	DWORD		diskFreeSpace;		//����ʣ��ռ䣬��λMB
}NET_SDK_DISK_INFO;

typedef struct
{
	WORD     wPicSize;
	WORD     wPicQuality;
}NET_SDK_JPEGPARA,*LPNET_SDK_JPEGPARA;

typedef enum _net_sdk_exception_type
{
	NETWORK_DISCONNECT = 0,
	NETWORK_RECONNECT,
	NETWORK_CH_DISCONNECT,	//ͨ������
	NETWORK_CH_RECONNECT,	//ͨ������
}NET_SDK_EXCEPTION_TYPE;

enum NET_SDK_DEVICE_TYPE
{
	NET_SDK_DVR,
	NET_SDK_DVS,
	NET_SDK_IPCAMERA,
	NET_SDK_NVR,
	NET_SDK_SUPERDVR,
	NET_SDK_DECODER,
};

typedef enum _net_sdk_device_firmware_type
{
	NET_SDK_DEVICE_FIRMWARE_V3,			
	NET_SDK_DEVICE_FIRMWARE_IPC,		
	NET_SDK_DEVICE_FIRMWARE_NVMS_V1,
	NET_SDK_DEVICE_FIRMWARE_OTHER,
}NET_SDK_DEVICE_FIRMWARE_TYPE;

typedef struct _net_sdk_device_discovery_info
{
	unsigned int		deviceType;		//NET_SDK_DEVICE_TYPE
	char				productType[16];
	char				strIP[16];
	char				strNetMask[16];
	char				strGateWay[16];
	unsigned char		byMac[8];
	unsigned short		netPort;
	unsigned short		httpPort;
	unsigned int		softVer;
	unsigned int		softBuildDate;
	unsigned char		ucIPMode;			//0 ��̬IP 1 dhcp
}NET_SDK_DEVICE_DISCOVERY_INFO;

typedef struct _net_sdk_device_ip_info_
{
	char szMac[36];					//�豸��ǰmac��ַ
	char szIpAddr[64];				//Ҫ�޸ĳɵ�ip
	char szMark[36];
	char szGateway[36];
	char szPassword[64];			//admin�û�������
	char szDdns1[36];
	char szDdns2[36];
	char ucIPMode;					//0Ϊ��̬IP, 1ΪDHCP
}NET_SDK_DEVICE_IP_INFO;

typedef struct _net_sdk_ipc_device_info_
{
	unsigned int	deviceID;				//�豸ID(��ʱδ����)
	unsigned short	channel;				//�������豸�ڱ��ط����ͨ��(��0��ʼ)
	unsigned short	status;					//����״̬��0�������ߣ�1��ʾ���ߣ�
	char			szEtherName[16];		//���Ϊ�գ�Ĭ��Ϊeth0
	char			szServer[64];			//�����豸IP��ַ
	unsigned short	nPort;					//�����豸�˿ں�
	unsigned short	nHttpPort;				//HTTP�˿�
	unsigned short	nCtrlPort;				//���ƶ˿ڣ�һ����nPort��ͬ
	char			szID[64];				//�����豸��ʶ(����MAC��ַ)
	char			username[36];			//�û���

	unsigned int	manufacturerId;			//�豸����ID(��ʱδ����)
	char			manufacturerName[36];	//�豸������(��ʱδ����)
	char			productModel[36];		//��Ʒ�ͺ�(��ʱδ����)
	unsigned char	bUseDefaultCfg;			//��ʱδ����
	unsigned char	bPOEDevice;				//��ʱδ����
	unsigned char	resv[2];				//��ʱδ����
}NET_SDK_IPC_DEVICE_INFO;

//ץͼ����
enum IMAGE_EVENT_TYPE
{
    IMAGE_TYPE_ALARM,
    IMAGE_TYPE_MANUAL,
};
//��������˳��
enum IMAGE_SORT_TYPE
{
    IMAGE_SORT_ASC,
    IMAGE_SORT_DESC,
};


typedef struct _net_sdk_image_
{
    DWORD			dwChannel; //ץͼͨ��
    DWORD			dwImageType; //ץͼ���� IMAGE_EVENT_TYPE
    DD_TIME			captureTime;//ʱ��
    DWORD			totalNum;//ͼƬ����
    unsigned char	resv[8];
}NET_SDK_IMAGE;

typedef struct _net_sdk_image_sreach
{
    DWORD			dwChannel;//ץͼͨ��
    DD_TIME			StartTime; //ʱ��
    DD_TIME			StopTime; //ʱ��
    DWORD			pageIndex;//�ڼ�ҳ
    DWORD			pageSize;//ÿҳ��
    IMAGE_SORT_TYPE sort; //��������˳��
    unsigned char	resv[8];
}NET_SDK_IMAGE_SREACH;


//ͼƬ����
enum IMAGE_MODE
{
    IMAGE_MODE_JPG,
    IMAGE_MODE_PNG,
    IMAGE_MODE_BMP,
};
typedef struct _net_sdk_image_info
{
    unsigned int	imageSize;
    IMAGE_MODE		imageMode; //ͼƬ��ʽ
    unsigned char	resv[8];
}NET_SDK_IMAGE_INFO;

typedef enum __Channel_type__
{
    E_NULL_CHL_TYPE,
    E_DIGITAL_CHL_TYPE,     //����ͨ��
    E_ANALOG_CHL_TYPE,      //ģ��ͨ��
    E_ALARMOUT_CHL_TYPE,	  //�������ͨ��
    E_SENSOR_CHL_TYPE,	  //������ͨ��
}CHANNEL_TYPE;

typedef struct _net_sdk_channel_ptz
{
    unsigned int	dwChannel;
    CHANNEL_TYPE      eChanneltype;
    unsigned char	resv[8];
}NET_SDK_CHANNEL_PTZ;

typedef enum __IVM_rule_config_type__
{
    IVM_RULE_VFD_CONFIG, //����ʶ������
    IVM_RULE_VFD_TRIGGER_CONFIG, //����ʶ����������
    IVM_RULE_VFD_SCHEDULE_CONFIG, //����ʶ���ų�
    IVM_RULE_AVD_CONFIG, //�쳣��Ƶ����

}IVM_RULE_CONFIG_TYPE;

typedef struct _rectangle_
{
    unsigned int X1;
    unsigned int Y1;
    unsigned int X2;
    unsigned int Y2;
}RECTANGLE;
//IVM_RULE_VFD_CONFIG
typedef struct _net_sdk_Vfd_Config
{
    unsigned int      bSwitch; //ʹ�ܣ�0 or 1
    unsigned int      alarmHoldTime;//��������ʱ��
    unsigned int      saveFacePicture;//�������������ͼƬ
    unsigned int      saveSourcePicture;//�����������ԴͼƬ
    unsigned int      rectangleNum;
    RECTANGLE	rectangle;
    unsigned char	resv[40];
}NET_SDK_VFD_CONFIG;

//IVM_RULE_VFD_TRIGGER_CONFIG
typedef struct _net_sdk_Vfd_trigger_Config
{
    unsigned short    snapCHNum ; //֧�����ץͼͨ����
    unsigned char     snapChannelId;//ץͼͨ��
    unsigned char     snapBswitch ;//ץͼʹ��
    unsigned short    recordCHNum ; //֧�����¼��ͨ����
    unsigned char     recordChannelId;//¼��ͨ��
    unsigned char     recordBswitch ;//¼��ʹ��
    unsigned short    alarmOutCHNum ; //֧����󱨾������
    unsigned char     alarmOutChannelId;//�������ͨ��
    unsigned char     alarmOutBswitch ;//�������ʹ��
    unsigned char     Resv[256];//����������������չ��ͨ��

}NET_SDK_VFD_TRIGGER_CONFIG;

typedef struct
{
    unsigned char    byStartHour;
    unsigned char    byStartMin;
    unsigned char    byStopHour;
    unsigned char    byStopMin;
}NET_DVR_SCHEDTIME, *LPNET_DVR_SCHEDTIME;

typedef struct
{
    unsigned char    mounth;
    unsigned char    day;
    unsigned char    Resv[2];
    NET_DVR_SCHEDTIME sScheduleTime;

}NET_DVR_SCHEDDATE, *LPNET_DVR_SCHEDDATE; //���ض����ڶ����ų�

typedef struct
{
    unsigned int    wDay; //�������е�����������Ϊ0����������Ϊ6
    NET_DVR_SCHEDTIME sScheduleTime;

}NET_DVR_SCHEDWEEK, *LPNET_DVR_SCHEDWEEK;//���������������ų�

//IVM_RULE_VFD_SCHEDULE_CONFIG
typedef struct
{
    unsigned int wDayCount; //sScheduleWeek��Ч����
    unsigned int dayCount;  //sScheduleDate ��Ч����
    NET_DVR_SCHEDWEEK sScheduleWeek[70]; //�����Զ�70��
    NET_DVR_SCHEDDATE sScheduleDate[31]; //�����Զ�31��  ֵ��С����ipc��Э��

}NET_SDK_VFD_SCHEDULE_CONFIG;

//�뱸�����
typedef enum _net_sdk_backup_data_type
{
    NET_DVR_BACKUP_DATA_TYPE_DVR,
    NET_DVR_BACKUP_DATA_TYPE_AVI,
    NET_DVR_BACKUP_DATA_TYPE_NULL,
}NET_DVR_BACKUP_DATA_TYPE;

typedef struct _download_sdk_frame_info
{
    unsigned int		nLength;	//֡���ݳ���
    unsigned short		frameType;	//�ο�DD_FRAME_TYPE
    unsigned short		keyFrame;	//0���ǹؼ�֡ 1���ؼ�֡
    unsigned short		nWidth;		//�����, ��λ����, �������Ƶ������Ϊ0
    unsigned short		nHeight;	//�����, �������Ƶ������Ϊ0
    LONGLONG			nStamp;		//֡ʱ��, ��λ����, ��1970��1��1��0��0��0�뿪ʼ�ľ���ʱ��
}NET_DVR_DOWNlOAD_FRAME_INFO;

typedef enum _net_sdk_backup_status
{
    NET_DVR_BACKUP_STOP,
    NET_DVR_BACKUP_END,

}NET_DVR_BACKUP_STATUS;

typedef struct
{
    char                            serverAddress[256];             // ���ı�ʶ ���ڵ��������˶�ʹ��
    long long                          currentTime;                    // ��ǰʱ��
    long long                          terminationTime;                // ��ֹʱ��
    char                            resv[64];                       // ������չ��
}NET_DVR_SUBSCRIBE_REPLY;


// �����¼�����
typedef enum
{
    NET_DVR_SMART_AVD,            // ��Ƶ�쳣��Ϲ��ܼ��
    NET_DVR_SMART_VFD,            // �������

}NET_DVR_SMART_TYPE;

typedef struct
{
    int X;
    int Y;
}NET_DVR_IVE_POINT_T;
typedef struct
{
    LONGLONG      time;            //���Դ���ݵ�ǰʱ�� /* ΢�뼶 */
    LONGLONG      relativeTime;    //���Դ�������ʱ�� /* ΢�뼶 */
    unsigned int     detectDataLen;   //���Դ���ݳ���
    unsigned int     softwareVersion; //����汾��, 0xABCDEFGH,AB������ CD�����汾 EFGH���Ӱ汾 ���� 1:ŷķ�� �汾:V5.00
    unsigned int     softwareBuildDate;//�����������,0xYYYYMMDD
    unsigned int     faceCnt;         //�����ĸ��������40��
    unsigned int     faceDataLen[40]; //ÿ�������ĳ���
}NET_DVR_IVE_VFD_RESULT_HEAD_T;

typedef struct
{
    unsigned int     type;  ///<: 0, JPG; 1, YUV
    unsigned int     status; ///<:0, INVALID; 1, VALID; 2, SAVED
    unsigned int     width;
    unsigned int     height;
    unsigned int     dataLen;
}NET_DVR_IVE_VFD_RESULT_DATA_INFO_T;

typedef struct
{
    int                      faceId;         /* face ID Number */
    unsigned int                     ptWidth;        /*���������*/
    unsigned int                     ptHeight;       /*���������*/
    NET_DVR_IVE_POINT_T                 ptLeftTop;      /* Left-Top     Face Coordinates    */
    NET_DVR_IVE_POINT_T                 ptRightTop;     /* Right-Top    Face Coordinates    */
    NET_DVR_IVE_POINT_T                 ptLeftBottom;   /* Left-Bottom  Face Coordinates    */
    NET_DVR_IVE_POINT_T                 ptRightBottom;  /* Right-Bottom Face Coordinates    */
    int                      nPose;          /* Face Pose                        */
    int                      nConfidence;    /* Confidence Degree                */
    int                      age;
    int                      sex;
    int                      dtFrames;
    int                         featureSize;
    NET_DVR_IVE_POINT_T                 stPosFaceImg;  //�������Ͻ�����(�ڼ��ԴͼƬ��λ��)
    int                         reserved[14];
    NET_DVR_IVE_VFD_RESULT_DATA_INFO_T  stFaceImgData;
}NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T;


//IVM_RULE_AVD_CONFIG
typedef struct _net_sdk_AVD_Config
{
    unsigned int      alarmHoldTime; //��������ʱ��
    unsigned int      sceneChangeSwitch;//�������ʹ�ܣ�0 or 1
    unsigned int      clarityAbnormalSwitch;//��Ƶģ��ʹ�ܣ�0 or 1
    unsigned int      colorAbnormalSwitch;//��Ƶƫɫʹ�ܣ�0 or 1
    unsigned int      sensitivity;
    unsigned int      maxSensitivity;
    unsigned int      minSensitivity;
    char              resv[40];

}NET_SDK_AVD_CONFIG;

typedef struct
{
    unsigned int      eventId;               // �¼�ID
    unsigned int      status;                // ����״̬,0:none 1:start 2:end 3:procedure
    unsigned int      type;                  // ��������,0:none 1:Scene 2:Clarity 3:Color
}NET_SDK_IVE_AVD_INFO_T;

typedef struct
{
    unsigned int          count;             // ����
    NET_SDK_IVE_AVD_INFO_T   avdInfo[32];       // �쳣�����Ϣ
}NET_SDK_IVE_AVD_T;

typedef struct
{
    unsigned int          minValue;             // ��Сֵ
    unsigned int          maxValue;             // ���ֵ
    unsigned int          curValue;             // ��ǰֵ
    unsigned int          defaultValue;             // Ĭ��ֵ

}NET_SDK_IMAGE_EFFECT_T;

#pragma pack()

//�ص���������
typedef void (CALLBACK *EXCEPTION_CALLBACK)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser);

typedef void (CALLBACK *DRAW_FUN_CALLBACK)(long long lLiveHandle, HDC hDC, void *pUser);

typedef void (CALLBACK *LIVE_DATA_CALLBACK)(long long lLiveHandle, NET_SDK_FRAME_INFO frameInfo, BYTE *pBuffer, void *pUser);

typedef void (CALLBACK *LIVE_DATA_CALLBACK_EX)(long long lLiveHandle, UINT dataType, BYTE *pBuffer, UINT dataLen, void *pUser);

typedef BOOL (CALLBACK *NET_MESSAGE_CALLBACK)(LONG lCommand, LONG lUserID, char *pBuf, DWORD dwBufLen, void *pUser);

typedef void (CALLBACK *PLAY_DATA_CALLBACK)(long long lPlayHandle, NET_SDK_FRAME_INFO frameInfo, BYTE *pBuffer, void *pUser);

typedef void (CALLBACK *TALK_DATA_CALLBACK)(long long lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void *pUser);

//////////////////////////////////////////////////////////////////////////
//2012-3-15����SDK����DVR����ע��Ĺ���
typedef void (CALLBACK *ACCEPT_REGISTER_CALLBACK)(LONG lUserID, LONG lRegisterID, LPNET_SDK_DEVICEINFO pDeviceInfo, void *pUser);

//////////////////////////////////////////////////////////////////////////
//�ӿڶ���
/********************************SDK�ӿں�������*********************************/
//SDK��ʼ�����˳�
NET_SDK_API BOOL CALL_METHOD NET_SDK_Init();
NET_SDK_API BOOL CALL_METHOD NET_SDK_Cleanup();

//������ǰ���豸����
NET_SDK_API int CALL_METHOD NET_SDK_DiscoverDevice(NET_SDK_DEVICE_DISCOVERY_INFO *pDeviceInfo, int bufNum, int waitSeconds);

//�޸��豸IP
NET_SDK_API BOOL CALL_METHOD NET_SDK_ModifyDeviceNetInfo(NET_SDK_DEVICE_IP_INFO *pDeviceIPInfo);

//ͨ�������ƻ�ȡIP��ַ
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceIPByName(char *sSerIP,DWORD wSerPort,char *sDvrName,char *sDvrIP);

//SDK�����쳣�ص�
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetSDKMessageCallBack(UINT nMessage, HWND hWnd, EXCEPTION_CALLBACK fExceptionCallBack, void *pUser);

//DVR������״̬�ص�
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDVRMessageCallBack(NET_MESSAGE_CALLBACK fMessageCallBack, void *pUser);

//������������
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetConnectTime(DWORD dwWaitTime = 5000, DWORD dwTryTimes = 3);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetReconnect(DWORD dwInterval = 5000, BOOL bEnableRecon = TRUE);

//�汾��Ϣ
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetSDKVersion();
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetSDKBuildVersion();
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceFirmwareType(LONG lUserID, NET_SDK_DEVICE_FIRMWARE_TYPE *pFirmwareType);

NET_SDK_API LONG CALL_METHOD NET_SDK_GetProductSubID(char *sDVRIP,WORD wDVRPort);

//�豸��¼�ǳ�
NET_SDK_API LONG CALL_METHOD NET_SDK_Login(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_SDK_DEVICEINFO lpDeviceInfo);
NET_SDK_API LONG CALL_METHOD NET_SDK_LoginEx(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_SDK_DEVICEINFO lpDeviceInfo, NET_SDK_CONNECT_TYPE eConnectType, const char *sDevSN = NULL);
NET_SDK_API BOOL CALL_METHOD NET_SDK_Logout(LONG lUserID);

//�����ѯ
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetLastError();
NET_SDK_API char* CALL_METHOD NET_SDK_GetErrorMsg(LONG *pErrorNo = NULL);

//Ԥ����ؽӿ�
NET_SDK_API long long CALL_METHOD NET_SDK_LivePlay(LONG lUserID, LPNET_SDK_CLIENTINFO lpClientInfo, LIVE_DATA_CALLBACK fLiveDataCallBack = NULL, void* pUser = NULL);
NET_SDK_API long long CALL_METHOD NET_SDK_LivePlayEx(LONG lUserID, LPNET_SDK_CLIENTINFO lpClientInfo, LIVE_DATA_CALLBACK_EX fLiveDataCallBack = NULL, void* pUser = NULL);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopLivePlay(long long lLiveHandle);

NET_SDK_API BOOL CALL_METHOD NET_SDK_RegisterDrawFun(long long lLiveHandle, DRAW_FUN_CALLBACK fDrawFun, void *pUser);

NET_SDK_API BOOL CALL_METHOD NET_SDK_SetPlayerBufNumber(long long lLiveHandle, DWORD dwBufNum);

NET_SDK_API BOOL CALL_METHOD NET_SDK_OpenSound(long long lLiveHandle);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseSound();

NET_SDK_API BOOL CALL_METHOD NET_SDK_Volume(long long lLiveHandle, WORD wVolume);

NET_SDK_API BOOL CALL_METHOD NET_SDK_SaveLiveData(long long lLiveHandle, char *sFileName);

NET_SDK_API BOOL CALL_METHOD NET_SDK_StopSaveLiveData(long long lLiveHandle);

NET_SDK_API BOOL CALL_METHOD NET_SDK_SetLiveDataCallBack(long long lLiveHandle, LIVE_DATA_CALLBACK fLiveDataCallBack, void *pUser);

NET_SDK_API BOOL CALL_METHOD NET_SDK_SetLiveDataCallBackEx(long long lLiveHandle, LIVE_DATA_CALLBACK_EX fLiveDataCallBack, void *pUser);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CapturePicture(long long lLiveHandle, char *sPicFileName);//bmp
NET_SDK_API BOOL CALL_METHOD NET_SDK_CapturePicture_Other(LONG lUserID, LONG lChannel,char *sPicFileName);//bmp

//��̬����I֡
NET_SDK_API BOOL CALL_METHOD NET_SDK_MakeKeyFrame(LONG lUserID, LONG lChannel);//������
NET_SDK_API BOOL CALL_METHOD NET_SDK_MakeKeyFrameSub(LONG lUserID, LONG lChannel);//������

//��̨������ؽӿ�
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl(long long lLiveHandle, DWORD dwPTZCommand, DWORD dwSpeed);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCommand, DWORD dwSpeed);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl_3D(long long lLiveHandle, LONG lChannel, PTZ_3D_POINT_INFO *pPtz3DInfo);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZPreset(long long lLiveHandle, DWORD dwPTZPresetCmd, DWORD dwPresetIndex);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZPreset_Other(LONG lUserID, LONG lChannel, DWORD dwPTZPresetCmd, DWORD dwPresetIndex);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZCruise(long long lLiveHandle, DWORD dwPTZCruiseCmd, BYTE byCruiseRoute);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZCruise_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCruiseCmd, BYTE byCruiseRoute);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZTrack(long long lLiveHandle, DWORD dwPTZTrackCmd);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZTrack_Other(LONG lUserID, LONG lChannel, DWORD dwPTZTrackCmd);
//�Զ�ɨ������ɨ�趼����ӿ�,bIsAutoScan = true,�Զ�ɨ�衣
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZAutoScan(long long lLiveHandle, DWORD dwPTZAutoScanCmd, DWORD dwSpeed, BOOL bIsAutoScan = TRUE);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZAutoScan_Other(LONG lUserID, LONG lChannel, DWORD dwPTZAutoScanCmd);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZSetCruise(long long lLiveHandle, BYTE byCruiseRoute, DD_CRUISE_POINT_INFO *pCruisePoint, WORD pointNum);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZSetCruise_Other(LONG lUserID, LONG lChannel, BYTE byCruiseRoute, DD_CRUISE_POINT_INFO *pCruisePoint, WORD pointNum);

NET_SDK_API BOOL CALL_METHOD NET_SDK_GetPTZCameraType(LONG lUserID, NET_SDK_CAMERA_TYPE *pCameraType);
//��ȡͨ��֧��PTZ���б�
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetSupportPtzList(LONG lUserID, int listNum, NET_SDK_CHANNEL_PTZ* pOutChannelPtz, int *returnListNum);

//�ļ�������ط�
NET_SDK_API long long CALL_METHOD NET_SDK_FindRecDate(LONG lUserID);

NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextRecDate(long long lFindHandle, DD_DATE *lpRecDate);

NET_SDK_API BOOL CALL_METHOD NET_SDK_FindRecDateClose(long long lFindHandle);

NET_SDK_API long long CALL_METHOD NET_SDK_FindFile(LONG lUserID, LONG lChannel, DD_TIME *lpStartTime, DD_TIME *lpStopTime);

NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextFile(long long lFindHandle, NET_SDK_REC_FILE *lpFindData);

NET_SDK_API BOOL CALL_METHOD NET_SDK_FindClose(long long lFindHandle);

NET_SDK_API long long CALL_METHOD NET_SDK_FindEvent(LONG lUserID, LONG lChannel, DWORD dwRecType, DD_TIME *lpStartTime, DD_TIME *lpStopTime);

NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextEvent(long long lFindHandle, NET_SDK_REC_EVENT *lpRecEvent);

NET_SDK_API BOOL CALL_METHOD NET_SDK_FindEventClose(long long lFindHandle);

NET_SDK_API long long CALL_METHOD NET_SDK_FindTime(LONG lUserID, LONG lChannel, DD_TIME *lpStartTime, DD_TIME *lpStopTime);

NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextTime(long long lFindHandle, NET_SDK_REC_TIME *lpRecTime);

NET_SDK_API BOOL CALL_METHOD NET_SDK_FindTimeClose(long long lFindHandle);

NET_SDK_API BOOL CALL_METHOD NET_SDK_LockFile(LONG lUserID, NET_SDK_REC_FILE *pFileToLock, LONG fileNum);

NET_SDK_API BOOL CALL_METHOD NET_SDK_UnlockFile(LONG lUserID, NET_SDK_REC_FILE *pFileToUnlock, LONG fileNum);

NET_SDK_API BOOL CALL_METHOD NET_SDK_DeleteRecFile(LONG lUserID, NET_SDK_REC_FILE *pFileToUnlock, LONG fileNum);

NET_SDK_API long long CALL_METHOD NET_SDK_PlayBackByTime(LONG lUserID, LONG *pChannels, LONG channelNum, DD_TIME *lpStartTime, DD_TIME *lpStopTime, HWND *hWnds);

NET_SDK_API long long CALL_METHOD NET_SDK_PlayBackByTimeEx(LONG lUserID, LONG *pChannels, LONG channelNum, DD_TIME *lpStartTime, DD_TIME *lpStopTime, HWND *hWnds, BOOL bFirstStream);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PlayBackControl(long long lPlayHandle, DWORD dwControlCode, DWORD dwInValue, DWORD *lpOutValue);

NET_SDK_API BOOL CALL_METHOD NET_SDK_StopPlayBack(long long lPlayHandle);

NET_SDK_API BOOL CALL_METHOD NET_SDK_SetPlayDataCallBack(long long lPlayHandle, PLAY_DATA_CALLBACK fPlayDataCallBack, void *pUser);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PlayBackSaveData(long long lPlayHandle, LONG lChannel, char *sFileName);

NET_SDK_API BOOL CALL_METHOD NET_SDK_StopPlayBackSave(long long lPlayHandle, LONG lChannel);

NET_SDK_API BOOL CALL_METHOD NET_SDK_GetPlayBackOsdTime(long long lPlayHandle, DD_TIME *lpOsdTime);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PlayBackCaptureFile(long long lPlayHandle, LONG lChannel, char *sFileName);

NET_SDK_API long long CALL_METHOD NET_SDK_GetFileByTime(LONG lUserID, LONG lChannel, DD_TIME *lpStartTime, DD_TIME *lpStopTime, char *sSavedFileName);
typedef void (CALLBACK *BACKUP_DATA_CALLBACK)(LONG lFileHandle, UINT dataType, BYTE *pBuffer, UINT dataLen, void *pUser);
NET_SDK_API long long CALL_METHOD NET_SDK_GetFileByTimeEx(LONG lUserID,LONG lChannel, DD_TIME * lpStartTime, DD_TIME * lpStopTime, char *sSavedFileName, BOOL bCustomFormat, BOOL bUseCallBack=false, BACKUP_DATA_CALLBACK fBackupDataCallBack= NULL, void* pUser = NULL); //bCustomFormat���Ƿ�ʹ��˽���ļ���ʽ
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopGetFile(long long lFileHandle);

NET_SDK_API int CALL_METHOD NET_SDK_GetDownloadPos(long long lFileHandle);

//����
NET_SDK_API long long CALL_METHOD NET_SDK_Upgrade(LONG lUserID, char *sFileName);

NET_SDK_API int CALL_METHOD NET_SDK_GetUpgradeState(long long lUpgradeHandle);

NET_SDK_API int CALL_METHOD NET_SDK_GetUpgradeProgress(long long lUpgradeHandle);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseUpgradeHandle(long long lUpgradeHandle);

//Զ�̹�����ʽ��Ӳ��
NET_SDK_API long long CALL_METHOD NET_SDK_FindDisk(LONG lUserID);

NET_SDK_API BOOL CALL_METHOD NET_SDK_GetNextDiskInfo(long long lDiskHandle, NET_SDK_DISK_INFO *pDiskInfo);

NET_SDK_API BOOL CALL_METHOD NET_SDK_FindDiskClose(long long lDiskHandle);

NET_SDK_API BOOL CALL_METHOD NET_SDK_ChangeDiskProperty(LONG lUserID, LONG lDiskNumber, short newProperty);

NET_SDK_API long long CALL_METHOD NET_SDK_FormatDisk(LONG lUserID, LONG lDiskNumber);

NET_SDK_API BOOL CALL_METHOD NET_SDK_GetFormatProgress(long long lFormatHandle, LONG *pCurrentFormatDisk, LONG *pCurrentDiskPos, LONG *pFormatStatic);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseFormatHandle(long long lFormatHandle);

//����
NET_SDK_API LONG CALL_METHOD NET_SDK_SetupAlarmChan(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseAlarmChan(LONG lAlarmHandle);
//��ȡ��ǰ������Ϣ N9000��ǰ������ IPC��3.0�豸�����ϱ��ı���
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetAlarmStatus(LONG lUserID, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);

//�����Խ�
NET_SDK_API long long CALL_METHOD NET_SDK_StartVoiceCom(LONG lUserID, BOOL bNeedCBNoEncData, TALK_DATA_CALLBACK fVoiceDataCallBack, void* pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetAudioInfo(long long lVoiceComHandle, void *pAudioInfo, LONG infoLen);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetVoiceComClientVolume(long long lVoiceComHandle, WORD wVolume);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopVoiceCom(long long lVoiceComHandle);

//����ת��
NET_SDK_API long long CALL_METHOD NET_SDK_StartVoiceCom_MR(LONG lUserID, BOOL bNeedNoEncodeData, TALK_DATA_CALLBACK fVoiceDataCallBack, void* pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_VoiceComSendData(long long lVoiceComHandle, char *pSendBuf, DWORD dwBufSize);

//////////////////////////////////////////////////////////////////////////
//͸�����ڹ���δ�ṩ

//��Ƶ����
NET_SDK_API long long CALL_METHOD NET_SDK_InitAudioDecoder(void *pAudioInfo, LONG infoLen);

NET_SDK_API BOOL CALL_METHOD NET_SDK_DecodeAudioFrame(long long lDecHandle, unsigned char *pInBuffer, LONG inLen, unsigned char *pOutBuffer, int *pOutLen);

NET_SDK_API void CALL_METHOD NET_SDK_ReleaseAudioDecoder(long long lDecHandle);
//��Ƶ����
NET_SDK_API long long CALL_METHOD NET_SDK_InitAudioEncoder(void *pAudioInfo, LONG infoLen);

NET_SDK_API BOOL CALL_METHOD NET_SDK_EncodeAudioFrame(long long lEncodeHandle, unsigned char *pInBuffer, LONG inLen, unsigned char *pOutBuffer, int *pOutLen);

NET_SDK_API void CALL_METHOD NET_SDK_ReleaseAudioEncoder(long long lEncodeHandle);

//Զ�̿����豸���ֶ�¼��
NET_SDK_API BOOL CALL_METHOD NET_SDK_StartDVRRecord(LONG lUserID, LONG lChannel, LONG lRecordType);

NET_SDK_API BOOL CALL_METHOD NET_SDK_StopDVRRecord(LONG lUserID, LONG lChannel);

//��־
NET_SDK_API long long CALL_METHOD NET_SDK_FindDVRLog(LONG lUserID, DWORD dwType, DD_TIME *lpStartTime, DD_TIME *lpStopTime);

NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextLog(long long lLogHandle, LPNET_SDK_LOG lpLogData);

NET_SDK_API BOOL CALL_METHOD NET_SDK_FindLogClose(long long lLogHandle);

//JPEGץͼ���ڴ�
NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_SDK_JPEGPARA lpJpegPara, char *sJpegPicBuffer, DWORD dwPicSize, LPDWORD lpSizeReturned);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJpeg(LONG lUserID, LONG lChannel, LONG dwResolution, char *sJpegPicBuffer, DWORD dwPicBufSize, LPDWORD lpSizeReturned);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGData_V2(LONG lUserID, LONG lChannel, char *sJpegPicBuffer, DWORD dwPicSize, LPDWORD lpSizeReturned);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGFile_V2(LONG lUserID, LONG lChannel, char *sPicFileName);

//end
NET_SDK_API BOOL CALL_METHOD NET_SDK_RefreshPlay(long long lPlayHandle);
//�ָ�Ĭ��ֵ
NET_SDK_API BOOL CALL_METHOD NET_SDK_RestoreConfig(LONG lUserID);
//�������
NET_SDK_API BOOL CALL_METHOD NET_SDK_SaveConfig(LONG lUserID);
//����
NET_SDK_API BOOL CALL_METHOD NET_SDK_RebootDVR(LONG lUserID);
//�ر�DVR
NET_SDK_API BOOL CALL_METHOD NET_SDK_ShutDownDVR(LONG lUserID);

//��������
NET_SDK_API LONG CALL_METHOD NET_SDK_EnterDVRConfig(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDVRConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned, BOOL bDefautlConfig);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDVRConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer,  DWORD dwInBufferSize);
NET_SDK_API BOOL CALL_METHOD NET_SDK_ExitDVRConfig(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetVideoEffect(LONG lUserID, LONG lChannel, DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetVideoEffect(LONG lUserID, LONG lChannel, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetVideoEffect_Ex(LONG lUserID, LONG lChannel, NET_SDK_IMAGE_EFFECT_T *pBrightValue, NET_SDK_IMAGE_EFFECT_T *pContrastValue, NET_SDK_IMAGE_EFFECT_T *pSaturationValue, NET_SDK_IMAGE_EFFECT_T *pHueValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetVideoEffect_Ex(LONG lUserID, LONG lChannel, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);

NET_SDK_API BOOL CALL_METHOD NET_SDK_SaveVideoEffect(LONG lUserID, LONG lChannel, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDefaultVideoEffect(LONG lUserID, DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDVRConfig_SubStreamEncodeInfo(LONG lUserID, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned, BOOL bDefautlConfig);	//For N9000
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDVRConfig_SubStreamEncodeInfo(LONG lUserID, LONG lChannel, LPVOID lpInBuffer,  DWORD dwInBufferSize);													//For N9000
//���NET_SDK_GetDVRConfig_SubStreamEncodeInfo�����ؽṹ���ж���֧�ֵ�����ѡ��; ���ص���֧�ֵı�����Ϣ
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDVRConfig_SubStreamEncodeInfo_Ex(LONG lUserID, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned, BOOL bDefautlConfig);	//For N9000

//�޸��豸ϵͳʱ��
NET_SDK_API BOOL CALL_METHOD NET_SDK_ChangTime(LONG lUserID, unsigned int time);

//�����ļ���������
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetConfigFile(LONG lUserID, char *sFileName);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetConfigFile(LONG lUserID, char *sFileName);

//������־�ļ�д��ӿ�
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetLogToFile(BOOL bLogEnable = FALSE, char *strLogDir = NULL, BOOL bAutoDel = TRUE);

//��ȡ�豸��Ϣ
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceInfo(LONG lUserID, LPNET_SDK_DEVICEINFO pdecviceInfo);
NET_SDK_API LONG CALL_METHOD NET_SDK_GetDeviceTypeName(LONG lUserID, char *pNameBuffer, int bufferLen);

//////////////////////////////////////////////////////////////////////////
//2012-3-15����SDK����DVR����ע��Ĺ���

//�豸����DVR����ע��ı���ƽ̨�˿ں�
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetRegisterPort(WORD wRegisterPort);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetRegisterCallback(ACCEPT_REGISTER_CALLBACK fRegisterCBFun, void *pUser);

//////////////////////////////////////////////////////////////////////////
//2012-2-18��������ʱ��ת��Ϊ��ʽ����ʱ��Ľӿ�
NET_SDK_API void CALL_METHOD NET_SDK_FormatTime(LONGLONG intTime, DD_TIME *pFormatTime);

/////////////////////////////////////////////////////////////////////////
//2012-6-4�����¼������ӿ�
NET_SDK_API long long CALL_METHOD NET_SDK_FindEventInfo(LONG lUserID, DWORD dwType, ULONGLONG channlMask, DD_TIME *lpStartTime, DD_TIME *lpStopTime);

NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextEventInfo(long long lEventHandle, LPNET_SDK_EVENT lpEventData);

NET_SDK_API BOOL CALL_METHOD NET_SDK_FindEventInfoClose(long long lEventHandle);



//////////////////////////////////////////////////////////////////////////
//2012-6-19���ӻ�ȡ�豸��ǰʱ��ӿ�
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceTime(LONG lUserID,DD_TIME *pTime);

//2014-10-25 �����ֶ�����\�رձ�����ؽӿ�
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDeviceManualAlarm(LONG lUserID, LONG *pAramChannel, LONG *pValue, LONG lAramChannelCount, BOOL bAlarmOpen);

//��ȡNVR��ͨ�����õ�IPC��Ϣ
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceIPCInfo(LONG lUserID, NET_SDK_IPC_DEVICE_INFO* pDeviceIPCInfo, LONG lBuffSize, LONG* pIPCCount);

//��ѯץͼ NET_SDK_IMAGE
NET_SDK_API BOOL CALL_METHOD NET_SDK_SearchPictures(LONG lUserID, NET_SDK_IMAGE_SREACH sInSreachImage, LONG lInImageBufferSize, NET_SDK_IMAGE *pOutImageInfo, LONG *pOutImageNum);
//Զ��ץͼ
NET_SDK_API BOOL CALL_METHOD NET_SDK_RemoteSnap(LONG lUserID, int lChannel);
//��ȡͼƬ��Ϣ
NET_SDK_API BOOL CALL_METHOD NET_SDK_DownLoadPicture(LONG lUserID, NET_SDK_IMAGE captureImage, NET_SDK_IMAGE_INFO *pOutImageInfo, char* pOutBuffer, int outBufferSize);

// dwCommand ��ȡ���ܷ�����ز���
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetIVMRuleConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetIVMRuleConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer,  DWORD dwInBufferSize);
//dwCommand NET_DVR_SMART_TYPE
//NET_DVR_IVE_VFD_RESULT_HEAD_T+[NET_DVR_IVE_VFD_RESULT_DATA_INFO_T+Դ����]+[NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T+��������+��������ֵ]+...+[NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T+��������+��������ֵ]
typedef void (CALLBACK *SUBSCRIBE_CALLBACK)(LONG lUserID, DWORD dwCommand, char *pBuf, DWORD dwBufLen, void *pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetSubscribCallBack(SUBSCRIBE_CALLBACK fSubscribCallBack, void *pUser);

NET_SDK_API BOOL CALL_METHOD NET_SDK_SmartSubscrib(LONG lUserID, DWORD dwCommand, LONG lChannel, NET_DVR_SUBSCRIBE_REPLY *pOutBuffer);
NET_SDK_API BOOL CALL_METHOD NET_SDK_UnSmartSubscrib(LONG lUserID, DWORD dwCommand, LONG lChannel, char *pInServerAddress, int *dwResult);


#ifdef __cplusplus
}
#endif

#endif
