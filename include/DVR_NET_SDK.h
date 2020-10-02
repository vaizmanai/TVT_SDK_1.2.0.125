
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
//LastError定义
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
	NET_SDK_PLAYCTRL_STARTAUDIO,	//该控制类型及以下两个控制类型只有在SDK内部解码显示时才会起作用
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

//登录结构定义
typedef struct _net_sdk_deviceinfo
{
	unsigned char	localVideoInputNum;		//本地视频输入通道数目
	unsigned char	audioInputNum;			//音频输入通道数目
	unsigned char	sensorInputNum;			//传感器输入通道数目
	unsigned char	sensorOutputNum;		//继电器输出数目
	unsigned int   displayResolutionMask;  //监视器可选择的分辨率

	unsigned char	videoOuputNum;			//视频输出数目（及支持回放最大通道数）
	unsigned char	netVideoOutputNum;		//网络回放最大通道数目
	unsigned char	netVideoInputNum;		//数字信号接入通道数目
	unsigned char	IVSNum;					//智能分析通道数目

	unsigned char	presetNumOneCH;			//每个通道预置点数目
	unsigned char	cruiseNumOneCH;			//每个通道巡航线数目
	unsigned char	presetNumOneCruise;		//每个巡航线的预置点数目
	unsigned char	trackNumOneCH;			//每个通道轨迹数目

	unsigned char	userNum;				//用户数目 
	unsigned char	netClientNum;			//最多客户端数目
	unsigned char	netFirstStreamNum;		//主码流传输的通道最大数目，即同时可以有几个客户端查看主码流
	unsigned char	deviceType;				//设备类型

	unsigned char	doblueStream;			//是否有提供双码流
	unsigned char	audioStream;			//是否有提供音频流
	unsigned char	talkAudio;				//是否有对讲功能: 1表示有对讲功能;0表示没有
	unsigned char	bPasswordCheck;			//操作是否要输入密码

	unsigned char	defBrightness;			//缺省亮度
	unsigned char	defContrast;			//缺省对比度
	unsigned char	defSaturation;			//缺省饱和度
	unsigned char	defHue;					//缺省色调

	unsigned short	videoInputNum;			//视频输入通道数目（本地加网络）
	unsigned short  deviceID;				//设备ID号
	unsigned int   videoFormat;            //系统当前制式

	//假如是FUNC_REMOTE_UPGRADE对应的功能，那么第FUNC_REMOTE_UPGRADE个比特为1，否则为零。
	unsigned int	function[8];			//功能描述

	unsigned int	deviceIP;				//设备网络地址
	unsigned char	deviceMAC[6];			//设备物理地址
	unsigned short	devicePort;				//设备端口

	unsigned int	buildDate;				//创建日期:year<<16 + month<<8 + mday
	unsigned int	buildTime;				//创建时间:hour<<16 + min<<8 + sec

	char			deviceName[36];			//设备名称

	char	firmwareVersion[36];			//固件版本
	char	kernelVersion[64];				//内核版本
	char	hardwareVersion[36];			//硬件版本
	char	MCUVersion[36];					//单片机版本
    char	firmwareVersionEx[100];			//固件版本扩展，主要针对新产品
    char	deviceProduct[28];			//设备型号
}NET_SDK_DEVICEINFO, *LPNET_SDK_DEVICEINFO;

//数据帧头定义
typedef struct _net_sdk_frame_info
{
	unsigned int		deviceID;
	unsigned int       channel;
	unsigned int		frameType;	//参考DD_FRAME_TYPE
	unsigned int		length;
	unsigned int		keyFrame;	//0：非关键帧 1：关键帧
	unsigned int       width;
	unsigned int       height;
	unsigned int		frameIndex;
	unsigned int		frameAttrib;//参考DD_FRAME_ATTRIB
	unsigned int		streamID;
	LONGLONG			time;	   //从1970年1月1日0点0分0秒开始的绝对时间，单位微秒
	LONGLONG			relativeTime;//相对时间，单位微秒
}NET_SDK_FRAME_INFO;

//录像时间信息定义
typedef struct _net_sdk_rec_time
{
	DWORD			dwChannel;	//通道号
	DD_TIME			startTime;	//该段录像开始时间
	DD_TIME			stopTime;	//该段录像结束时间
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

//日志信息定义
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
	unsigned short chnn;			//事件对应的通道
	unsigned short type;			//事件类型：DD_EVENT_TYPE
	DD_TIME        startTime;		//事件产生的开始时间
	DD_TIME        endTime;			//事件的结束时间
}NET_SDK_EVENT,*LPNET_SDK_EVENT;

typedef struct _net_sdk_clientinfo
{
	LONG    lChannel;
	LONG    streamType;
	HWND    hPlayWnd;
}NET_SDK_CLIENTINFO, *LPNET_SDK_CLIENTINFO;

//设备上传信息类型
enum NET_SDK_DEVICE_MSG_TYPE
{
	NET_SDK_ALARM,		//设备报警消息
	NET_SDK_RECORD,		//设备录像信息
	NET_SDK_IVM_RULE,	//智能行为分析信息(暂时保留)
	NET_SDK_TRADEINFO,	//ATM交易信息(暂时保留)
	NET_SDK_IPCCFG,		//混合型DVR的IPC信息变更(暂时保留)
};

//设备上传信息为报警类型时的具体报警类型
enum NET_SDK_ALARM_TYPE
{
	NET_SDK_ALARM_TYPE_MOTION,		//移动侦测
	NET_SDK_ALARM_TYPE_SENSOR,		//信号量报警
	NET_SDK_ALARM_TYPE_VLOSS,		//信号丢失
	NET_SDK_ALARM_TYPE_SHELTER,		//遮挡报警
	NET_SDK_ALARM_TYPE_DISK_FULL,	//硬盘满
	NET_SDK_ALARM_TYPE_DISK_UNFORMATTED,//硬盘未格式化
	NET_SDK_ALARM_TYPE_DISK_WRITE_FAIL,	//读写硬盘出错
	NET_SDK_ALARM_TYPE_EXCEPTION,
};


//设备上传信息为智能报警的事件类型
enum NET_SDK_IVM_RULE_TYPE
{
    NET_SDK_IVM_RULE_TYPE_VFD, //人脸识别报警  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_SCENE, //视频异常诊断场景变化  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_CLARITY, //视频异常诊断视频模糊  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_COLOR, //视频异常诊断视频偏色  NET_SDK_IVM_STATUS_INFO
};


/************************************************************************/
    /*  定义报警输入和输出的资源    在很多地方使用这个枚举值的时候定义的变量都是BYTE的所以这里
    要小心定义*/
    /************************************************************************/
enum NET_SDK_N9000_ALARM_TYPE
{
    NET_SDK_N9000_ALARM_TYPE_RANGE_BEGIN,
    NET_SDK_N9000_ALARM_TYPE_MOTION=0x01,/////移动侦测报警输入
    NET_SDK_N9000_ALARM_TYPE_SENSOR,/////传感器报警输入
    NET_SDK_N9000_ALARM_TYPE_VLOSS,////视频丢失报警输入
    NET_SDK_N9000_ALARM_TYPE_FRONT_OFFLINE, //////前端设备掉线报警
    NET_SDK_N9000_ALARM_TYPE_OSC,           ////物品看护侦测报警
    NET_SDK_N9000_ALARM_TYPE_AVD,           ////视频异常侦测报警
    NET_SDK_N9000_ALARM_TYPE_AVD_SCENE,//only IPC
    NET_SDK_N9000_ALARM_TYPE_AVD_CLARITY,//only IPC
    NET_SDK_N9000_ALARM_TYPE_AVD_COLOR,//only IPC

    NET_SDK_N9000_ALARM_TYPE_PEA_TRIPWIRE,  ////越界侦测报警
    NET_SDK_N9000_ALARM_TYPE_PEA_PERIMETER, ////区域入侵侦测报警
    NET_SDK_N9000_ALARM_TYPE_PEA,           ////越界侦测与区域入侵侦测
    NET_SDK_N9000_ALARM_TYPE_VFD,           ////人脸侦测（目前仅IPC）
    NET_SDK_N9000_ALARM_TYPE_CDD,           ////Crowdy density
    NET_SDK_N9000_ALARM_TYPE_IPD,           ////people intrusion
    NET_SDK_N9000_ALARM_TYPE_CPC,           ////people counting

    NET_SDK_N9000_ALARM_TYPE_GPS_SPEED_OVER=0x21,//和车载有关的报警，超速
    NET_SDK_N9000_ALARM_TYPE_GPS_CROSS_BOADER,//越界
    NET_SDK_N9000_ALARM_TYPE_GPS_TEMPERATURE_OVER,//温度报警
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_X,//GSENSOR报警
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_Y,
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_Z,

    NET_SDK_N9000_ALARM_TYPE_EXCEPTION = 0x41,
    NET_SDK_N9000_ALARM_TYPE_IP_CONFLICT,   /////IP地址冲突
    NET_SDK_N9000_ALARM_TYPE_DISK_IO_ERROR, /////磁盘IO错误
    NET_SDK_N9000_ALARM_TYPE_DISK_FULL,	   /////磁盘满
    NET_SDK_N9000_ALARM_TYPE_RAID_SUBHEALTH, //阵列亚健康
    NET_SDK_N9000_ALARM_TYPE_RAID_UNAVAILABLE, //阵列不可用
    NET_SDK_N9000_ALARM_TYPE_ILLEIGAL_ACCESS,  /////非法访问
    NET_SDK_N9000_ALARM_TYPE_NET_DISCONNECT,  /////网络断开
    NET_SDK_N9000_ALARM_TYPE_NO_DISK,		////盘组下没有磁盘
    NET_SDK_N9000_ALARM_TYPE_SIGNAL_SHELTER, //信号遮挡
    NET_SDK_N9000_ALARM_TYPE_HDD_PULL_OUT, //前面板硬盘拔出

    NET_SDK_N9000_ALARM_TYPE_ALARM_OUT = 0x51,  /////报警输出的类型，报警输出也有状态需要管理

    NET_SDK_N9000_ALARM_TYPE_RANGE_END = 0xFF,////不能超过这个值  否则会出错
};


//设备上传信息为报警类型时的上传信息结构
typedef struct _net_sdk_alarminfo
{
	DWORD		dwAlarmType;
	DWORD		dwSensorIn;		//传感器报警输入端口号
	DWORD		dwChannel;		//在报警与通道相关时，表示报警的通道号
	DWORD		dwDisk;			//在磁盘报警时，表示产生报警的磁盘号
}NET_SDK_ALARMINFO;

typedef struct _net_sdk_record_status
{
	DWORD		dwRecordType;		//DD_RECORD_TYPE
	DWORD		dwChannel;
}NET_SDK_RECORD_STATUS;

typedef struct _net_sdk_IVM_rule_status
{
    DWORD		dwIVMType;		//NET_SDK_IVM_RULE_TYPE
    DWORD		dwIVMSize;      //NET_SDK_IVM_RULE_TYPE中事件对应的结构体大小
}
NET_SDK_IVM_RULE_STATUS;

//人脸检测告警上报
typedef struct _net_sdk_IVM_status_info
{
    DWORD		dwAlarmType;    //NET_SDK_IVM_RULE_TYPE
    DWORD		dwChannel;		//告警通道号

}NET_SDK_IVM_STATUS_INFO;

typedef enum _net_sdk_disk_status
{	
	NET_SDK_DISK_NORMAL,				//正常 
	NET_SDK_DISK_NO_FORMAT,				//未格式化
}NET_SDK_DISK_STATUS;

typedef enum _net_sdkdisk_property
{
	NET_SDK_DISK_READ_WRITE = 0,			//可正常读写
	NET_SDK_DISK_ONLY_READ,					//只能读，不能写
	NET_SDK_DISK_REDUNDANCY					//冗余
}NET_SDK_DISK_PROPERTY;

typedef enum _net_sdk_connect_type
{
	NET_SDK_CONNECT_TCP		= 0,			//TCP方式登陆
	NET_SDK_CONNECT_NAT		= 1,			//NAT方式登陆
    NET_SDK_CONNECT_NAT_TCP		= 2,			//用NAT库中的TCP连接

	NET_SDK_CONNECT_END
}NET_SDK_CONNECT_TYPE;

typedef enum _net_sdk_camera_type
{
	NET_SDK_NOT_SUPPORT_PTZ		= 0,		//不支持云台的枪机
	NET_SDK_DOME_SUPPORT_PTZ	= 1,		//支持云台的枪机
	NET_SDK_SUPPORT_PTZ			= 2,		//支持云台的球机
	NET_SDK_PTZ_END
}NET_SDK_CAMERA_TYPE;

typedef struct _net_sdk_disk_info
{
	LONG		diskIndex;			//磁盘编号
	short		diskStatus;			//磁盘状态，参考NET_SDK_DISK_STATUS
	short		diskProperty;		//磁盘状态，参考NET_SDK_DISK_PROPERTY
	DWORD		diskTotalSpace;		//磁盘总空间，单位MB
	DWORD		diskFreeSpace;		//磁盘剩余空间，单位MB
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
	NETWORK_CH_DISCONNECT,	//通道掉线
	NETWORK_CH_RECONNECT,	//通道上线
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
	unsigned char		ucIPMode;			//0 静态IP 1 dhcp
}NET_SDK_DEVICE_DISCOVERY_INFO;

typedef struct _net_sdk_device_ip_info_
{
	char szMac[36];					//设备当前mac地址
	char szIpAddr[64];				//要修改成的ip
	char szMark[36];
	char szGateway[36];
	char szPassword[64];			//admin用户的密码
	char szDdns1[36];
	char szDdns2[36];
	char ucIPMode;					//0为静态IP, 1为DHCP
}NET_SDK_DEVICE_IP_INFO;

typedef struct _net_sdk_ipc_device_info_
{
	unsigned int	deviceID;				//设备ID(暂时未用上)
	unsigned short	channel;				//该网络设备在本地分配的通道(从0开始)
	unsigned short	status;					//连接状态（0代表离线，1表示在线）
	char			szEtherName[16];		//如果为空，默认为eth0
	char			szServer[64];			//网络设备IP地址
	unsigned short	nPort;					//网络设备端口号
	unsigned short	nHttpPort;				//HTTP端口
	unsigned short	nCtrlPort;				//控制端口，一般与nPort相同
	char			szID[64];				//网络设备标识(或是MAC地址)
	char			username[36];			//用户名

	unsigned int	manufacturerId;			//设备厂商ID(暂时未用上)
	char			manufacturerName[36];	//设备厂商名(暂时未用上)
	char			productModel[36];		//产品型号(暂时未用上)
	unsigned char	bUseDefaultCfg;			//暂时未用上
	unsigned char	bPOEDevice;				//暂时未用上
	unsigned char	resv[2];				//暂时未用上
}NET_SDK_IPC_DEVICE_INFO;

//抓图类型
enum IMAGE_EVENT_TYPE
{
    IMAGE_TYPE_ALARM,
    IMAGE_TYPE_MANUAL,
};
//返回排列顺序
enum IMAGE_SORT_TYPE
{
    IMAGE_SORT_ASC,
    IMAGE_SORT_DESC,
};


typedef struct _net_sdk_image_
{
    DWORD			dwChannel; //抓图通道
    DWORD			dwImageType; //抓图类型 IMAGE_EVENT_TYPE
    DD_TIME			captureTime;//时间
    DWORD			totalNum;//图片总数
    unsigned char	resv[8];
}NET_SDK_IMAGE;

typedef struct _net_sdk_image_sreach
{
    DWORD			dwChannel;//抓图通道
    DD_TIME			StartTime; //时间
    DD_TIME			StopTime; //时间
    DWORD			pageIndex;//第几页
    DWORD			pageSize;//每页数
    IMAGE_SORT_TYPE sort; //返回排列顺序
    unsigned char	resv[8];
}NET_SDK_IMAGE_SREACH;


//图片类型
enum IMAGE_MODE
{
    IMAGE_MODE_JPG,
    IMAGE_MODE_PNG,
    IMAGE_MODE_BMP,
};
typedef struct _net_sdk_image_info
{
    unsigned int	imageSize;
    IMAGE_MODE		imageMode; //图片格式
    unsigned char	resv[8];
}NET_SDK_IMAGE_INFO;

typedef enum __Channel_type__
{
    E_NULL_CHL_TYPE,
    E_DIGITAL_CHL_TYPE,     //数字通道
    E_ANALOG_CHL_TYPE,      //模拟通道
    E_ALARMOUT_CHL_TYPE,	  //报警输出通道
    E_SENSOR_CHL_TYPE,	  //传感器通道
}CHANNEL_TYPE;

typedef struct _net_sdk_channel_ptz
{
    unsigned int	dwChannel;
    CHANNEL_TYPE      eChanneltype;
    unsigned char	resv[8];
}NET_SDK_CHANNEL_PTZ;

typedef enum __IVM_rule_config_type__
{
    IVM_RULE_VFD_CONFIG, //人脸识别配置
    IVM_RULE_VFD_TRIGGER_CONFIG, //人脸识别联动配置
    IVM_RULE_VFD_SCHEDULE_CONFIG, //人脸识别排程
    IVM_RULE_AVD_CONFIG, //异常视频配置

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
    unsigned int      bSwitch; //使能，0 or 1
    unsigned int      alarmHoldTime;//报警持续时间
    unsigned int      saveFacePicture;//保存人脸检测脸图片
    unsigned int      saveSourcePicture;//保存人脸检测源图片
    unsigned int      rectangleNum;
    RECTANGLE	rectangle;
    unsigned char	resv[40];
}NET_SDK_VFD_CONFIG;

//IVM_RULE_VFD_TRIGGER_CONFIG
typedef struct _net_sdk_Vfd_trigger_Config
{
    unsigned short    snapCHNum ; //支持最大抓图通道数
    unsigned char     snapChannelId;//抓图通道
    unsigned char     snapBswitch ;//抓图使能
    unsigned short    recordCHNum ; //支持最大录像通道数
    unsigned char     recordChannelId;//录像通道
    unsigned char     recordBswitch ;//录像使能
    unsigned short    alarmOutCHNum ; //支持最大报警输出数
    unsigned char     alarmOutChannelId;//报警输出通道
    unsigned char     alarmOutBswitch ;//报警输出使能
    unsigned char     Resv[256];//保留，将来用于扩展多通道

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

}NET_DVR_SCHEDDATE, *LPNET_DVR_SCHEDDATE; //按特定日期订的排程

typedef struct
{
    unsigned int    wDay; //在星期中的天数，周天为0，，，周六为6
    NET_DVR_SCHEDTIME sScheduleTime;

}NET_DVR_SCHEDWEEK, *LPNET_DVR_SCHEDWEEK;//根据星期数订的排程

//IVM_RULE_VFD_SCHEDULE_CONFIG
typedef struct
{
    unsigned int wDayCount; //sScheduleWeek有效个数
    unsigned int dayCount;  //sScheduleDate 有效个数
    NET_DVR_SCHEDWEEK sScheduleWeek[70]; //最多可以订70个
    NET_DVR_SCHEDDATE sScheduleDate[31]; //最多可以订31个  值大小来自ipc的协议

}NET_SDK_VFD_SCHEDULE_CONFIG;

//与备份相关
typedef enum _net_sdk_backup_data_type
{
    NET_DVR_BACKUP_DATA_TYPE_DVR,
    NET_DVR_BACKUP_DATA_TYPE_AVI,
    NET_DVR_BACKUP_DATA_TYPE_NULL,
}NET_DVR_BACKUP_DATA_TYPE;

typedef struct _download_sdk_frame_info
{
    unsigned int		nLength;	//帧数据长度
    unsigned short		frameType;	//参考DD_FRAME_TYPE
    unsigned short		keyFrame;	//0：非关键帧 1：关键帧
    unsigned short		nWidth;		//画面宽, 单位像素, 如果是音频数据则为0
    unsigned short		nHeight;	//画面高, 如果是音频数据则为0
    LONGLONG			nStamp;		//帧时间, 单位毫秒, 从1970年1月1日0点0分0秒开始的绝对时间
}NET_DVR_DOWNlOAD_FRAME_INFO;

typedef enum _net_sdk_backup_status
{
    NET_DVR_BACKUP_STOP,
    NET_DVR_BACKUP_END,

}NET_DVR_BACKUP_STATUS;

typedef struct
{
    char                            serverAddress[256];             // 订阅标识 后期的续订和退订使用
    long long                          currentTime;                    // 当前时间
    long long                          terminationTime;                // 终止时间
    char                            resv[64];                       // 后期扩展用
}NET_DVR_SUBSCRIBE_REPLY;


// 智能事件类型
typedef enum
{
    NET_DVR_SMART_AVD,            // 视频异常诊断功能检测
    NET_DVR_SMART_VFD,            // 人脸检测

}NET_DVR_SMART_TYPE;

typedef struct
{
    int X;
    int Y;
}NET_DVR_IVE_POINT_T;
typedef struct
{
    LONGLONG      time;            //检测源数据当前时间 /* 微秒级 */
    LONGLONG      relativeTime;    //检测源数据相对时间 /* 微秒级 */
    unsigned int     detectDataLen;   //检测源数据长度
    unsigned int     softwareVersion; //软件版本号, 0xABCDEFGH,AB：厂家 CD：主版本 EFGH：子版本 厂商 1:欧姆龙 版本:V5.00
    unsigned int     softwareBuildDate;//软件生成日期,0xYYYYMMDD
    unsigned int     faceCnt;         //人脸的个数，最大40个
    unsigned int     faceDataLen[40]; //每个人脸的长度
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
    unsigned int                     ptWidth;        /*坐标比例宽*/
    unsigned int                     ptHeight;       /*坐标比例高*/
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
    NET_DVR_IVE_POINT_T                 stPosFaceImg;  //人脸左上角坐标(在检测源图片的位置)
    int                         reserved[14];
    NET_DVR_IVE_VFD_RESULT_DATA_INFO_T  stFaceImgData;
}NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T;


//IVM_RULE_AVD_CONFIG
typedef struct _net_sdk_AVD_Config
{
    unsigned int      alarmHoldTime; //报警持续时间
    unsigned int      sceneChangeSwitch;//场景变更使能，0 or 1
    unsigned int      clarityAbnormalSwitch;//视频模糊使能，0 or 1
    unsigned int      colorAbnormalSwitch;//视频偏色使能，0 or 1
    unsigned int      sensitivity;
    unsigned int      maxSensitivity;
    unsigned int      minSensitivity;
    char              resv[40];

}NET_SDK_AVD_CONFIG;

typedef struct
{
    unsigned int      eventId;               // 事件ID
    unsigned int      status;                // 报警状态,0:none 1:start 2:end 3:procedure
    unsigned int      type;                  // 报警类型,0:none 1:Scene 2:Clarity 3:Color
}NET_SDK_IVE_AVD_INFO_T;

typedef struct
{
    unsigned int          count;             // 个数
    NET_SDK_IVE_AVD_INFO_T   avdInfo[32];       // 异常侦测信息
}NET_SDK_IVE_AVD_T;

typedef struct
{
    unsigned int          minValue;             // 最小值
    unsigned int          maxValue;             // 最大值
    unsigned int          curValue;             // 当前值
    unsigned int          defaultValue;             // 默认值

}NET_SDK_IMAGE_EFFECT_T;

#pragma pack()

//回调函数定义
typedef void (CALLBACK *EXCEPTION_CALLBACK)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser);

typedef void (CALLBACK *DRAW_FUN_CALLBACK)(long long lLiveHandle, HDC hDC, void *pUser);

typedef void (CALLBACK *LIVE_DATA_CALLBACK)(long long lLiveHandle, NET_SDK_FRAME_INFO frameInfo, BYTE *pBuffer, void *pUser);

typedef void (CALLBACK *LIVE_DATA_CALLBACK_EX)(long long lLiveHandle, UINT dataType, BYTE *pBuffer, UINT dataLen, void *pUser);

typedef BOOL (CALLBACK *NET_MESSAGE_CALLBACK)(LONG lCommand, LONG lUserID, char *pBuf, DWORD dwBufLen, void *pUser);

typedef void (CALLBACK *PLAY_DATA_CALLBACK)(long long lPlayHandle, NET_SDK_FRAME_INFO frameInfo, BYTE *pBuffer, void *pUser);

typedef void (CALLBACK *TALK_DATA_CALLBACK)(long long lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void *pUser);

//////////////////////////////////////////////////////////////////////////
//2012-3-15增加SDK接收DVR主动注册的功能
typedef void (CALLBACK *ACCEPT_REGISTER_CALLBACK)(LONG lUserID, LONG lRegisterID, LPNET_SDK_DEVICEINFO pDeviceInfo, void *pUser);

//////////////////////////////////////////////////////////////////////////
//接口定义
/********************************SDK接口函数声明*********************************/
//SDK初始化及退出
NET_SDK_API BOOL CALL_METHOD NET_SDK_Init();
NET_SDK_API BOOL CALL_METHOD NET_SDK_Cleanup();

//局域网前端设备发现
NET_SDK_API int CALL_METHOD NET_SDK_DiscoverDevice(NET_SDK_DEVICE_DISCOVERY_INFO *pDeviceInfo, int bufNum, int waitSeconds);

//修改设备IP
NET_SDK_API BOOL CALL_METHOD NET_SDK_ModifyDeviceNetInfo(NET_SDK_DEVICE_IP_INFO *pDeviceIPInfo);

//通过备名称获取IP地址
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceIPByName(char *sSerIP,DWORD wSerPort,char *sDvrName,char *sDvrIP);

//SDK操作异常回调
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetSDKMessageCallBack(UINT nMessage, HWND hWnd, EXCEPTION_CALLBACK fExceptionCallBack, void *pUser);

//DVR报警或状态回调
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDVRMessageCallBack(NET_MESSAGE_CALLBACK fMessageCallBack, void *pUser);

//设置重连参数
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetConnectTime(DWORD dwWaitTime = 5000, DWORD dwTryTimes = 3);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetReconnect(DWORD dwInterval = 5000, BOOL bEnableRecon = TRUE);

//版本信息
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetSDKVersion();
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetSDKBuildVersion();
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceFirmwareType(LONG lUserID, NET_SDK_DEVICE_FIRMWARE_TYPE *pFirmwareType);

NET_SDK_API LONG CALL_METHOD NET_SDK_GetProductSubID(char *sDVRIP,WORD wDVRPort);

//设备登录登出
NET_SDK_API LONG CALL_METHOD NET_SDK_Login(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_SDK_DEVICEINFO lpDeviceInfo);
NET_SDK_API LONG CALL_METHOD NET_SDK_LoginEx(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_SDK_DEVICEINFO lpDeviceInfo, NET_SDK_CONNECT_TYPE eConnectType, const char *sDevSN = NULL);
NET_SDK_API BOOL CALL_METHOD NET_SDK_Logout(LONG lUserID);

//错误查询
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetLastError();
NET_SDK_API char* CALL_METHOD NET_SDK_GetErrorMsg(LONG *pErrorNo = NULL);

//预览相关接口
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

//动态生成I帧
NET_SDK_API BOOL CALL_METHOD NET_SDK_MakeKeyFrame(LONG lUserID, LONG lChannel);//主码流
NET_SDK_API BOOL CALL_METHOD NET_SDK_MakeKeyFrameSub(LONG lUserID, LONG lChannel);//子码流

//云台控制相关接口
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl(long long lLiveHandle, DWORD dwPTZCommand, DWORD dwSpeed);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCommand, DWORD dwSpeed);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl_3D(long long lLiveHandle, LONG lChannel, PTZ_3D_POINT_INFO *pPtz3DInfo);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZPreset(long long lLiveHandle, DWORD dwPTZPresetCmd, DWORD dwPresetIndex);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZPreset_Other(LONG lUserID, LONG lChannel, DWORD dwPTZPresetCmd, DWORD dwPresetIndex);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZCruise(long long lLiveHandle, DWORD dwPTZCruiseCmd, BYTE byCruiseRoute);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZCruise_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCruiseCmd, BYTE byCruiseRoute);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZTrack(long long lLiveHandle, DWORD dwPTZTrackCmd);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZTrack_Other(LONG lUserID, LONG lChannel, DWORD dwPTZTrackCmd);
//自动扫描和随机扫描都这个接口,bIsAutoScan = true,自动扫描。
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZAutoScan(long long lLiveHandle, DWORD dwPTZAutoScanCmd, DWORD dwSpeed, BOOL bIsAutoScan = TRUE);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZAutoScan_Other(LONG lUserID, LONG lChannel, DWORD dwPTZAutoScanCmd);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZSetCruise(long long lLiveHandle, BYTE byCruiseRoute, DD_CRUISE_POINT_INFO *pCruisePoint, WORD pointNum);

NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZSetCruise_Other(LONG lUserID, LONG lChannel, BYTE byCruiseRoute, DD_CRUISE_POINT_INFO *pCruisePoint, WORD pointNum);

NET_SDK_API BOOL CALL_METHOD NET_SDK_GetPTZCameraType(LONG lUserID, NET_SDK_CAMERA_TYPE *pCameraType);
//获取通道支持PTZ的列表
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetSupportPtzList(LONG lUserID, int listNum, NET_SDK_CHANNEL_PTZ* pOutChannelPtz, int *returnListNum);

//文件查找与回放
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
NET_SDK_API long long CALL_METHOD NET_SDK_GetFileByTimeEx(LONG lUserID,LONG lChannel, DD_TIME * lpStartTime, DD_TIME * lpStopTime, char *sSavedFileName, BOOL bCustomFormat, BOOL bUseCallBack=false, BACKUP_DATA_CALLBACK fBackupDataCallBack= NULL, void* pUser = NULL); //bCustomFormat：是否使用私有文件格式
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopGetFile(long long lFileHandle);

NET_SDK_API int CALL_METHOD NET_SDK_GetDownloadPos(long long lFileHandle);

//升级
NET_SDK_API long long CALL_METHOD NET_SDK_Upgrade(LONG lUserID, char *sFileName);

NET_SDK_API int CALL_METHOD NET_SDK_GetUpgradeState(long long lUpgradeHandle);

NET_SDK_API int CALL_METHOD NET_SDK_GetUpgradeProgress(long long lUpgradeHandle);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseUpgradeHandle(long long lUpgradeHandle);

//远程管理及格式化硬盘
NET_SDK_API long long CALL_METHOD NET_SDK_FindDisk(LONG lUserID);

NET_SDK_API BOOL CALL_METHOD NET_SDK_GetNextDiskInfo(long long lDiskHandle, NET_SDK_DISK_INFO *pDiskInfo);

NET_SDK_API BOOL CALL_METHOD NET_SDK_FindDiskClose(long long lDiskHandle);

NET_SDK_API BOOL CALL_METHOD NET_SDK_ChangeDiskProperty(LONG lUserID, LONG lDiskNumber, short newProperty);

NET_SDK_API long long CALL_METHOD NET_SDK_FormatDisk(LONG lUserID, LONG lDiskNumber);

NET_SDK_API BOOL CALL_METHOD NET_SDK_GetFormatProgress(long long lFormatHandle, LONG *pCurrentFormatDisk, LONG *pCurrentDiskPos, LONG *pFormatStatic);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseFormatHandle(long long lFormatHandle);

//报警
NET_SDK_API LONG CALL_METHOD NET_SDK_SetupAlarmChan(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseAlarmChan(LONG lAlarmHandle);
//获取当前报警信息 N9000当前报警， IPC，3.0设备主动上报的报警
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetAlarmStatus(LONG lUserID, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);

//语音对讲
NET_SDK_API long long CALL_METHOD NET_SDK_StartVoiceCom(LONG lUserID, BOOL bNeedCBNoEncData, TALK_DATA_CALLBACK fVoiceDataCallBack, void* pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetAudioInfo(long long lVoiceComHandle, void *pAudioInfo, LONG infoLen);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetVoiceComClientVolume(long long lVoiceComHandle, WORD wVolume);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopVoiceCom(long long lVoiceComHandle);

//语音转发
NET_SDK_API long long CALL_METHOD NET_SDK_StartVoiceCom_MR(LONG lUserID, BOOL bNeedNoEncodeData, TALK_DATA_CALLBACK fVoiceDataCallBack, void* pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_VoiceComSendData(long long lVoiceComHandle, char *pSendBuf, DWORD dwBufSize);

//////////////////////////////////////////////////////////////////////////
//透明串口功能未提供

//音频解码
NET_SDK_API long long CALL_METHOD NET_SDK_InitAudioDecoder(void *pAudioInfo, LONG infoLen);

NET_SDK_API BOOL CALL_METHOD NET_SDK_DecodeAudioFrame(long long lDecHandle, unsigned char *pInBuffer, LONG inLen, unsigned char *pOutBuffer, int *pOutLen);

NET_SDK_API void CALL_METHOD NET_SDK_ReleaseAudioDecoder(long long lDecHandle);
//音频编码
NET_SDK_API long long CALL_METHOD NET_SDK_InitAudioEncoder(void *pAudioInfo, LONG infoLen);

NET_SDK_API BOOL CALL_METHOD NET_SDK_EncodeAudioFrame(long long lEncodeHandle, unsigned char *pInBuffer, LONG inLen, unsigned char *pOutBuffer, int *pOutLen);

NET_SDK_API void CALL_METHOD NET_SDK_ReleaseAudioEncoder(long long lEncodeHandle);

//远程控制设备端手动录像
NET_SDK_API BOOL CALL_METHOD NET_SDK_StartDVRRecord(LONG lUserID, LONG lChannel, LONG lRecordType);

NET_SDK_API BOOL CALL_METHOD NET_SDK_StopDVRRecord(LONG lUserID, LONG lChannel);

//日志
NET_SDK_API long long CALL_METHOD NET_SDK_FindDVRLog(LONG lUserID, DWORD dwType, DD_TIME *lpStartTime, DD_TIME *lpStopTime);

NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextLog(long long lLogHandle, LPNET_SDK_LOG lpLogData);

NET_SDK_API BOOL CALL_METHOD NET_SDK_FindLogClose(long long lLogHandle);

//JPEG抓图到内存
NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_SDK_JPEGPARA lpJpegPara, char *sJpegPicBuffer, DWORD dwPicSize, LPDWORD lpSizeReturned);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJpeg(LONG lUserID, LONG lChannel, LONG dwResolution, char *sJpegPicBuffer, DWORD dwPicBufSize, LPDWORD lpSizeReturned);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGData_V2(LONG lUserID, LONG lChannel, char *sJpegPicBuffer, DWORD dwPicSize, LPDWORD lpSizeReturned);

NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGFile_V2(LONG lUserID, LONG lChannel, char *sPicFileName);

//end
NET_SDK_API BOOL CALL_METHOD NET_SDK_RefreshPlay(long long lPlayHandle);
//恢复默认值
NET_SDK_API BOOL CALL_METHOD NET_SDK_RestoreConfig(LONG lUserID);
//保存参数
NET_SDK_API BOOL CALL_METHOD NET_SDK_SaveConfig(LONG lUserID);
//重启
NET_SDK_API BOOL CALL_METHOD NET_SDK_RebootDVR(LONG lUserID);
//关闭DVR
NET_SDK_API BOOL CALL_METHOD NET_SDK_ShutDownDVR(LONG lUserID);

//参数配置
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
//相对NET_SDK_GetDVRConfig_SubStreamEncodeInfo，返回结构体中多了支持的码率选项; 返回的是支持的编码信息
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDVRConfig_SubStreamEncodeInfo_Ex(LONG lUserID, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned, BOOL bDefautlConfig);	//For N9000

//修改设备系统时间
NET_SDK_API BOOL CALL_METHOD NET_SDK_ChangTime(LONG lUserID, unsigned int time);

//配置文件导出导入
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetConfigFile(LONG lUserID, char *sFileName);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetConfigFile(LONG lUserID, char *sFileName);

//启用日志文件写入接口
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetLogToFile(BOOL bLogEnable = FALSE, char *strLogDir = NULL, BOOL bAutoDel = TRUE);

//获取设备信息
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceInfo(LONG lUserID, LPNET_SDK_DEVICEINFO pdecviceInfo);
NET_SDK_API LONG CALL_METHOD NET_SDK_GetDeviceTypeName(LONG lUserID, char *pNameBuffer, int bufferLen);

//////////////////////////////////////////////////////////////////////////
//2012-3-15增加SDK接收DVR主动注册的功能

//设备接收DVR主动注册的本地平台端口号
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetRegisterPort(WORD wRegisterPort);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetRegisterCallback(ACCEPT_REGISTER_CALLBACK fRegisterCBFun, void *pUser);

//////////////////////////////////////////////////////////////////////////
//2012-2-18增加整型时间转换为格式化的时间的接口
NET_SDK_API void CALL_METHOD NET_SDK_FormatTime(LONGLONG intTime, DD_TIME *pFormatTime);

/////////////////////////////////////////////////////////////////////////
//2012-6-4增加事件搜索接口
NET_SDK_API long long CALL_METHOD NET_SDK_FindEventInfo(LONG lUserID, DWORD dwType, ULONGLONG channlMask, DD_TIME *lpStartTime, DD_TIME *lpStopTime);

NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextEventInfo(long long lEventHandle, LPNET_SDK_EVENT lpEventData);

NET_SDK_API BOOL CALL_METHOD NET_SDK_FindEventInfoClose(long long lEventHandle);



//////////////////////////////////////////////////////////////////////////
//2012-6-19增加获取设备当前时间接口
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceTime(LONG lUserID,DD_TIME *pTime);

//2014-10-25 增加手动开启\关闭报警相关接口
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDeviceManualAlarm(LONG lUserID, LONG *pAramChannel, LONG *pValue, LONG lAramChannelCount, BOOL bAlarmOpen);

//获取NVR的通道配置的IPC信息
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceIPCInfo(LONG lUserID, NET_SDK_IPC_DEVICE_INFO* pDeviceIPCInfo, LONG lBuffSize, LONG* pIPCCount);

//查询抓图 NET_SDK_IMAGE
NET_SDK_API BOOL CALL_METHOD NET_SDK_SearchPictures(LONG lUserID, NET_SDK_IMAGE_SREACH sInSreachImage, LONG lInImageBufferSize, NET_SDK_IMAGE *pOutImageInfo, LONG *pOutImageNum);
//远程抓图
NET_SDK_API BOOL CALL_METHOD NET_SDK_RemoteSnap(LONG lUserID, int lChannel);
//获取图片信息
NET_SDK_API BOOL CALL_METHOD NET_SDK_DownLoadPicture(LONG lUserID, NET_SDK_IMAGE captureImage, NET_SDK_IMAGE_INFO *pOutImageInfo, char* pOutBuffer, int outBufferSize);

// dwCommand 获取智能分析相关参数
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetIVMRuleConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetIVMRuleConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer,  DWORD dwInBufferSize);
//dwCommand NET_DVR_SMART_TYPE
//NET_DVR_IVE_VFD_RESULT_HEAD_T+[NET_DVR_IVE_VFD_RESULT_DATA_INFO_T+源数据]+[NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T+人脸数据+人脸特征值]+...+[NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T+人脸数据+人脸特征值]
typedef void (CALLBACK *SUBSCRIBE_CALLBACK)(LONG lUserID, DWORD dwCommand, char *pBuf, DWORD dwBufLen, void *pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetSubscribCallBack(SUBSCRIBE_CALLBACK fSubscribCallBack, void *pUser);

NET_SDK_API BOOL CALL_METHOD NET_SDK_SmartSubscrib(LONG lUserID, DWORD dwCommand, LONG lChannel, NET_DVR_SUBSCRIBE_REPLY *pOutBuffer);
NET_SDK_API BOOL CALL_METHOD NET_SDK_UnSmartSubscrib(LONG lUserID, DWORD dwCommand, LONG lChannel, char *pInServerAddress, int *dwResult);


#ifdef __cplusplus
}
#endif

#endif
