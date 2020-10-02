/***********************************************************************
** Copyright (C) Tongwei Video Technology Co.,Ltd. All rights reserved.
** Author       : WZY
** Date         : 2011-03-12
** Name         : decoderconfig.h
** Version      : 1.0
1:����
***********************************************************************/

#ifndef _DECODER_DEFINE_H_
#define _DECODER_DEFINE_H_

const unsigned int MSG_USER_NAME_LEN = 36;
const unsigned int MSG_PASSWD_LEN = 36;
const unsigned char	COMPUTER_NAME_LEN = 36;
const unsigned int DEC_MAX_CHNN_NUM = 64;

typedef enum _dec_cfg_item_id
{
	//�˷�ΧID�洢ϵͳ�������õ�����     
	DEC_NCFG_ITEM_SYSTEM_BASE = 0,

	DEC_NCFG_ITEM_DEVICE_ID,				//�豸ID��unsigned int
	DEC_NCFG_ITEM_DEVICE_NAME,				//�豸���ƣ�NCFG_INFO_SHORT_NAME

	//��ӵ�����ѡ��zhouhb
	DEC_NCFG_ITEM_SOFT_VERSION,			//����汾��	unsigned int
	DEC_NCFG_ITEM_MAX_CHANNAL,	//������ͨ������	unsigned int
	DEC_NCFG_ITEM_PRODUCT_ID,		//��ƷID��(Ҳ������ν�Ĳ�Ʒ����)	unsigned int
	DEC_NCFG_ITEM_PRODUCT_SUB_ID,	//��Ʒ��ID��	unsigned int
	DEC_NCFG_ITEM_HARDWARE_VERSION,	//Ӳ���汾	char[VERSION_LEN]
	DEC_NCFG_ITEM_MCU_VERSION,		//MCU�汾	char[VERSION_LEN]
	DEC_NCFG_ITEM_KERNEL_VERSION,	//�ں˰汾	char[VERSION_LEN]


	DEC_NCFG_ITEM_LIVE_AUDIO_VOLUME,		//ϵͳ����unsigned int
	DEC_NCFG_ITEM_DATE_FORMAT,				//���ڸ�ʽ��unsigned int
	DEC_NCFG_ITEM_HOUR_FORMAT,				//ʱ���ʽ��H����H��unsigned int

	//NCFG_ITEM_LANGUAGE,					//���ԣ�unsigned int
	DEC_NCFG_ITEM_TIME_ZONE,				//ʱ����int
	DEC_NCFG_ITEM_TIME_SYNC,				//�Ƿ�����ʱ��ͬ����unsigned int
	DEC_NCFG_ITEM_TIME_SERVER,		//����ʱ��ͬ����������ַ��NCFG_INFO_LONG_NAME
	DEC_NCFG_ITEM_VGA_RESOLUTION,	//��ʾ���ֱ��ʣ�unsigned int��

	//NCFG_ITEM_VGA_REFRESH,			 //��ʾ����Ļˢ����,VGA_SUPPORT_REFRSHHZ[n]
	DEC_NCFG_ITEM_USER,					//�û���Ϣ��NCFG_INFO_USER [MAX_USER_NUM]
	DEC_NCFG_ITEM_DAYLIGHT_INFO,		//����ʱ��Ϣ��DAYLIGHT_INFO
	DEC_NCFG_ITEM_MAX_CLIENT_NUM,   	//��������û���Ŀunsigned int
	DEC_NCFG_ITEM_TVWALL_CONFIG_INFO,	//����������ǰ���豸����Ϣ����������ݲ����ǣ�TVWALL_SWITCH_T[MAX_CHNN_NUM]

	DEC_NCFG_ITEM_SYSTEM_END,


	//���粿��
	DEC_NCFG_ITEM_NET_BASE = 0x0100,
	//NCFG_ITEM_UPNP_ENABLE,			//�Ƿ�����UPNP����, unsigned int
	//NCFG_ITEM_UPNP_FRIENDLY_NAME,	//UPNP�豸��ʾ������, NCFG_INFO_LONG_NAME
	DEC_NCFG_ITEM_HTTP_PORT,				//HTTP �˿�, unsigned int
	DEC_NCFG_ITEM_SERVER_PORT,				//�������˿ڣ�unsigned int
	DEC_NCFG_ITEM_NETWORK_ADDR_INFO,		//�����ַ�����Ϣ��NETWORK_ADDR_INFO

	DEC_NCFG_ITEM_DNS_1,					//unsigned int
	DEC_NCFG_ITEM_DNS_2,					//unsigned int
	//NCFG_ITEM_DDNS_INFO,				//DDNS��Ϣ��DDNS_INFO
	DEC_NCFG_ITEM_PPPOE_INFO,				//PPPoE�������Ϣ��PPPOE_INFO

	DEC_NCFG_ITEM_NETINFO_END
}DEC_NCFG_ITEM_ID;

//CMS��Ȩ�޶���
typedef enum _cms_authority
{
	CMS_AUTH_BASIC				= 0x0001,		//����Ȩ��

	CMS_AUTH_PARA_SET			= 0x0002,		//��������(д)
	CMS_AUTH_READ_PARA			= 0x0004,		//ϵͳ������ȡ(��)
	CMS_AUTH_CTL_SERIAL_PORT	= 0x0008,		//���ڲ�������
	CMS_AUTH_SHUTDOWN_SYS		= 0x0010,		//�ػ���������
	CMS_AUTH_VOICE_TALK			= 0x0020,		//�Խ�
	CMS_AUTH_REMOTE_VIEW		= 0x0040,		//Զ��Ԥ��

	CMS_AUTH_ALL				= 0xffffffff	//ȫ��Ȩ��
}CMS_AUTHORITY;

typedef struct _decoder_info
{
	bool getStreamStatus;		//ע��:���ѡ��Ϊtrue, �������Ϣ����Ч
	unsigned int encIp;		//ǰ���豸IP
	unsigned int encPort;		//ǰ���豸�Ķ˿ں�
	int encCh; 					//ǰ���豸��ͨ����ע��ӿ�ʼ����
	char computerName[COMPUTER_NAME_LEN];		//ǰ���豸�ļ��������
	unsigned char   MAC[6];					//����Mac��ַ

}DECODER_INFO;

// zhouhb_changed
//���ڿͻ��˵�½�Ľṹ�壺CMD_MSG_LOGIN
typedef struct _net_login
{
	//�����ǿͻ��˵�½������ʱ����Ϣ����
	char			userName[36];
	char			userPwd[36];

	//CMSȨ�޼�: CMS_AUTHORITY�Ķ���
	unsigned int	authority;			//�û�Ȩ��
	unsigned int	connectType;		//��������,ENUM_CONNECT_TYPE
	unsigned int   IP;					//�ͻ����������ӵ�IP��ַ
	char			computerName[36];	//���������
	unsigned char   MAC[6];				//����Mac��ַ
	unsigned int	netprotocolver;		//�ͻ���Ŀǰʹ�õ�����Э��汾
	DECODER_INFO 	decoderInfo[4]; //����������ͨ������Ϣ

	unsigned char	resv[16];		//�����ֽڣ�������
	
}NET_LOGIN;

typedef struct __tvwall_switch_t
{
	//������ǰ���豸����Ϣ����
	unsigned int encIp;//ǰ���豸IP
	unsigned int encPort;//ǰ���豸�Ķ˿ں�
	int encCh; //ǰ���豸��ͨ����ע���1��ʼ����

	int channelProtocol;// Э������	  1tcp,2Udp,3mcast 
	int channelStreamtype;//��������
	unsigned char  primaryStream; //������Ϊ

	int encNum;//ǰ���豸��ͨ������
	int encKeepAlive; //�Ƿ��������		���ã�������


	//�����ǽ���������Ϣ����
	unsigned char  decChannel; //���ǽ�������ͨ����
	int channelKeepAlive;//�趨������ĳͨ���Ĺ���״̬����������״̬�� :���ڷ�����״̬

	//ǰ���豸�������Ƶ����ʾ�ڽ��������Ǹ�����λ�á�
	int displayMode;		//�������ķ���ģʽ
	int displayChannel;		//�ھ������ģʽ�е���һ��ͨ����0��ʼ����


	//�������Ϣ���ڵ�½ǰ���豸
	char encUserName[MSG_USER_NAME_LEN];	//��½���û���������
	char encUserPwd[MSG_PASSWD_LEN];
	char			computerName[28];		//ǰ���豸�ļ��������
	unsigned char   MAC[6];					//����Mac��ַ
	unsigned int	netprotocolver;		//�ͻ���Ŀǰʹ�õ�����Э��汾
	unsigned int	connectType;			//��������,ENUM_CONNECT_TYPE

	char reserv[12]; //�Ա�����

} TVWALL_SWITCH_T;

//�û����������ѯ�û���Ϣ, ɾ���û���Ϣ, �����û���Ϣ, �����û���Ϣ��
const unsigned int  	MAX_DEC_USER_NUM				= 16;

typedef struct _dec_ncfg_info_user
{
	unsigned int   bindMac;	//0 ����1��
	unsigned int   authority;	//�û�Ȩ��
	unsigned int   group;

	char            name[MSG_USER_NAME_LEN];
	char            password[MSG_PASSWD_LEN];
	unsigned char   MAC[8];
}DEC_NCFG_INFO_USER;


//������Э��
typedef	struct _message_data
{
	unsigned int	clientID; //�ͻ��˵�ID�ţ����û����������õĵ�
	unsigned int	deviceID;
	char*			pData;	  //������Ϣ���洢�����������Ϣͷ�����ݲ��֣�
	int				dataLen;  
}MESSAGE_DATA;

typedef struct __MSG_HEAD_t
{
	unsigned	int	clientID; //�ͻ��˵�ID�ţ����û����������õĵ�
	unsigned	int	cmdType;	//��������
	unsigned	int	cmdSubtype;	//����������
	unsigned	int	cmdVer;		//����汾
	unsigned	int		dateSize;	// msgDataָ������ݲ��ֵĳ���

	unsigned	int	ackFlag;	//���ڷ��صı�־
}MSG_HEAD;

typedef struct __net_msg_t
{
	MSG_HEAD			msgHead;		//��Ϣͷ
	char				*msgData;		//��Ϣ����
}NET_MSG;

typedef enum  CMS_DEC_NET_PROTOCOL_H_
{

	//��һ������: ��ǰ���豸��ͨ��

	//�ͻ��˵�¼
	CMD_BASE_LOGIN		= 0x0100,
	CMD_REQUEST_LOGIN_DECODER,			//�����¼ǰ���豸
	CMD_REQUEST_LOGOUT_DECODER,			//����ǳ�ǰ���豸
	CMD_END_NUM_LOGIN,

	// ��ǰ���豸�������п���
	CMD_BASE_ENCODER		= 0x0300,
	CMD_STREAM_START,		//����ǰ���豸����
	CMD_STREAM_SWITCH,		//�����л�ǰ���豸����
	CMD_STREAM_STOP,			//����ֹͣǰ���豸����
	CMD_KEYFRAME,				//����ͨ���ؼ�֡������������ͨ������ϣ��������������
	CMD_END_NUM_ENCODER,

	//�ڶ�������: ��CMS������Ϣ����

	//�������ã����ò������ȡ������
	CMD_BASE_NUM_CFG			= 0x010000,
	CMD_CONFIG_GET,		//��������
	CMD_CONFIG_SET,		//��������

	// iVMS���ƽ���������������
	CMD_BASE_NUM_CMS_CONTROL_ENC	= 0x020000,
	CMD_SWITCH_ENC, 		//�Խ�������ĳһ��ͨ���л�ǰ���豸
	CMD_STOP_DECODE, 		//ֹͣ����
	CMD_START_DECODE, 	//��ʼ����	

	//�ͻ�����Ϣ������
	CMD_BASE_NUM_CTRL		= 0x030000,
	CMD_MSG_LOGIN,			//CMS�����¼
	CMD_MSG_LOGOUT,		//CMS����ǳ�
	CMD_MSG_REBOOT,		//CMS��������ϵͳ
	CMD_MSG_SHUTDOWN,		//CMS����ػ�
	CMD_MSG_EXFACTORY_SETUP,	//����ָ���������
	CMD_CHANGE_TIME,	//�޸�ϵͳʱ��
	CMD_Exception_Set, 		//�豸�쳣���������
	CMD_GET_VERSION_INFO, 	//��ȡ�汾��Ϣ
	MSG_GET_DEVICE_INFO, 		//��ȡ�豸��Ϣ
	CMD_NET_DEVICE_SEARCH, 	//�������ڹ㲥�����豸

	//�û�������
	CMD_GET_ALL_USERINFO,		//��ѯ�豸�������û���Ϣ
	CMD_SET_ALL_USERINFO,		//�����û���Ϣ

	//Զ���������
	CMD_UPDATE_START,			//Զ���������--->����		
	CMD_UPDATE_DATA			//���յ���Զ���ϴ����������
};

//����ķ����룬��Ҫ�Ƿ��ظ�CMS�ġ�
enum NET_REPLY_CLIENT
{
	ACK_SUCCESS 	= 	0,  //�ɹ�
	ACK_ERROR_NAME,		//�û�������
	ACK_ERROR_PWD,			//�������
	ACK_ERROR_RIGHT,		//Ȩ�޲���

	ACK_LONGIN_SUCC,		//�����¼�������豸��Ϣ
	ACK_LONGIN_FAIL,		//�ܾ���¼�����ߵ�¼ʧ��

	ACK_CFG_DEFAULT,		//�ظ�Ĭ������
	ACK_CFG_DATA,			//�ظ���������
	//ACK_CFG_DEFAULT,		//�ظ��ָ�Ĭ��������Ϣ
	ACK_CFG_FAIL,			//�ظ�����ʧ�ܣ�����ʧ����
	
	//���������緽��
	NETERR_PARAMCHECK_OK	,			//��Ϣͨ����������֤
	NETERR_PARAMCHECK_ENAMEPWD,			//�û��������������
	NETERR_PARAMCHECK_EHOSTDOMAIN,		//dydnds.com���û����������������������
	NETERR_PARAMCHECK_ETIMEOUT,			//��ʱ��
	NETERR_PARAMCHECK_ECONNECT,			//����δ����,δ������
	NETERR_PARMACHECK_ENETUNREACHD,		//���粻�ɴ�
	NETERR_PARMACHECK_EHOSTDOMAIN_EMPTY,	//��������Ϊ��
	NETERR_PARAMCHECK_EUNKNOWN,			//δ֪����	
	NETERR_PARAMCHECK_ABUSE,				//dyndns.com��ע���������block
	NETERR_PARAMCHECK_NOHOST,			//dyndns.com���Ҳ����������
	NETERR_PARAMCHECK_NOTFQDN,			//dyndns.com���������������Ϲ���
	NETERR_PARAMCHECK_NUMHOST,			//dyndns.com��̫���������update
	NETERR_PARAMCHECK_REGISTER_SUCC,		//��dynamic.visionica.comע��ɹ�
	NETERR_PARAMCHECK_REGISTER_FAIL,		//��dynamic.visionica.comע��ʧ��

	NETERR_PARAMCHECK_EIPCONFLICT,	//��̬���õ�IP��ͻ
	NETERR_PARAMCHECK_EIPORSUBMASK,		//ip��ַ������,���������������
	NETERR_PARAMCHECK_ENONICDEVICE,		//û��ָ����NIC�豸
	NETERR_PARAMCHECK_EUSERNAMEEMPTY,	//�û���Ϊ��

	ACK_UPDATE_FILE_ERR,

	ACK_ERROR_OTHER = 0xffff 		//��������
};
#endif	
