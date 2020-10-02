/***********************************************************************
** Copyright (C) Tongwei Video Technology Co.,Ltd. All rights reserved.
** Author       : Ԭʯά
** Date         : 2010-11-25
** Name         : CDDConfig.h
** Version      : 1.0
** Description  :
** Modify Record:
1:
***********************************************************************/
#ifndef _DD_CONFIG_MAN_H_
#define _DD_CONFIG_MAN_H_

#include <list>
#include "dvrdvsconfig.h"
#include "dvrdvstypedef.h"
#include "DDPublic.h"

typedef struct _dd_config_file_head_
{
	unsigned int	iSize;

	unsigned int   version;				//���ö���汾��
	unsigned int	fileLength;				//�ļ�����
	unsigned int	itemnum;				//��������Ŀ

	unsigned int	productID;				//��Ʒ���
	DD_DEVICE_INFO	deviceInfo;				//��Ӧ���豸��Ϣ
}DD_CONFIG_FILE_HEAD;

const unsigned int CONFIG_DATA_POS = sizeof(DD_CONFIG_FILE_HEAD) + 32;

typedef enum _dd_cofnig_group_
{
	DD_CONFIG_GROUP_NULL					= 0x0,

	DD_CONFIG_GROUP_SYSTEM		= (0x01<<0),
	DD_CONFIG_GROUP_LIVE		= (0x01<<1),
	DD_CONFIG_GROUP_VIDEO		= (0x01<<2),
	DD_CONFIG_GROUP_ENCODE		= (0x01<<3),
	DD_CONFIG_GROUP_RECORD		= (0x01<<4),
	DD_CONFIG_GROUP_NETWORK		= (0x01<<5),
	DD_CONFIG_GROUP_ACCOUNT		= (0x01<<6),
	DD_CONFIG_GROUP_SENSOR		= (0x01<<7),
	DD_CONFIG_GROUP_MOTION		= (0x01<<8),
	DD_CONFIG_GROUP_SHELTER		= (0x01<<9),
	DD_CONFIG_GROUP_VLOSS		= (0x01<<10),
	DD_CONFIG_GROUP_ALARM_OUT	= (0x01<<11),
	DD_CONFIG_GROUP_PTZ			= (0x01<<12)
}DD_CONFIG_GROUP;

class CDDConfig
{
public:
	~CDDConfig ();
	static CDDConfig* Instance();
	bool Initial (const DD_DEVICE_INFO & deviceInfo, const char *pFilePath = NULL);
	void Quit ();

	bool LoadDefault(unsigned int param);

	//////////////////////////////////////////////////////////////////////////
	void EnterConfig(unsigned int clientID = DD_LOCAL_CLIENT_ID);
	void ExitConfig();
	inline unsigned int cfgClient(){return m_clientID;};

	bool GetConfig(unsigned char *pItemHead, unsigned int headLen, unsigned char **pDataBlock,unsigned int &dataLen);
	bool GetConfigEx(std::list<DD_CONFIG_ITEM_ID> &itemList, unsigned char **pDataBlock, unsigned int &dataLen);
	bool GetDefaultData(unsigned char *pItemHead, unsigned int headLen, unsigned char **pDataBlock,unsigned int &dataLen);
	bool SetConfig(const unsigned char *pDataBlock, unsigned int dataLen);
protected:
private:
	//methods
	CDDConfig ();

	bool InitialConfig ();	//����û��Config.dat�ļ����ڣ�����Ҫ���ø÷���������
	bool LoadConfig (const char *pFilePath);		//������Config.dat�ļ����ڣ�����Ҫ���ø÷����������ݡ�
	//////////////////////////////////////////////////////////////////////////
	bool InitialHead();		//��ʼ���ļ�ͷ
	bool InitialBody();		//��ʼ��������

	 //id����ͷ�����ݼ���洢
	bool SetConfigBlock(const unsigned char *pDataBlock,  unsigned int num, unsigned int dataLen);
	bool GetConfigBlock(std::list<DD_CONFIG_ITEM_HEAD> &itemHeadList, unsigned char **pDataBlock,unsigned int &Len, unsigned short &itemNum);

	bool LoadDefaultConfig(unsigned int param);
	bool WriteConfig(unsigned char *pConfig, unsigned int len, size_t pos);
	bool InitialConfigItemHead(); //��ʼ��������������

	bool LoadSystemConfig(unsigned char **ppConfig, unsigned int & len, unsigned short & num);
	bool LoadLiveConfig(unsigned char **ppConfig, unsigned int & len, unsigned short & num);
	bool LoadChnnConfig(unsigned char **ppConfig, unsigned int & len, unsigned short & num);
	bool LoadEncodeConfig(unsigned char **ppConfig, unsigned int & len, unsigned short & num);
	bool LoadRecordConfig(unsigned char **ppConfig, unsigned int & len, unsigned short & num);
	bool LoadNetworkConfig(unsigned char **ppConfig, unsigned int & len, unsigned short & num);
	bool LoadAccountConfig(unsigned char **ppConfig, unsigned int & len, unsigned short & num);
	bool LoadSensorConfig(unsigned char **ppConfig, unsigned int & len, unsigned short & num);
	bool LoadMotionConfig(unsigned char **ppConfig, unsigned int & len, unsigned short & num);
	bool LoadShelterConfig(unsigned char **ppConfig, unsigned int & len, unsigned short & num);
	bool LoadVLossConfig(unsigned char **ppConfig, unsigned int &len, unsigned short &num);
	bool LoadAlarmOutConfig(unsigned char **ppConfig, unsigned int & len, unsigned short & num);
	bool LoadPTZConfig( unsigned char **ppConfig, unsigned int &len, unsigned short &num );

	//////////////////////////////////////////////////////////////////////////
	//variable
	//////////////////////////////////////////////////////////////////////////
	unsigned int	m_clientID;
	FILE			*m_pFile;

	DD_VIDEO_FORMAT		m_videoFormat;
	unsigned int		m_productID;
	DD_DEVICE_INFO		m_deviceInfo;
	DD_CONFIG_FILE_HEAD	m_cfgHead;
	//////////////////////////////////////////////////////////////////////////
	std::list <DD_CONFIG_ITEM_HEAD_EX> m_itemList;

	//CPUB_Lock		m_lock;
	//////////////////////////////////////////////////////////////////////////
};
#endif //_DD_CONFIG_MAN_H_

