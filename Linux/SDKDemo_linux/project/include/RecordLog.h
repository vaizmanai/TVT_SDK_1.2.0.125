/***********************************************************************
** Copyright (C) Tongwei Video Technology Co.,Ltd. All rights reserved.
** Author       :	Ԭʯά
** Date         : 2010-12-17
** Name         : DDRecordLog.h
** Version      : 1.0
** Description  :
** Modify Record:
***********************************************************************/
#ifndef _DD_RECORD_LOG_H_
#define _DD_RECORD_LOG_H_

typedef struct  _dd_record_log_file_head_info_
{
	unsigned int	headFlag;				//�ļ�ͷ����ʶ
	unsigned int	version;				//���ļ��İ汾��

	unsigned int	recordChnnNum;			//��¼��ͨ����Ŀ
	unsigned int	recordFileNum;			//��¼���ļ���Ŀ
	
	unsigned int	recordFileLen;			//¼���ļ���С
	unsigned int	recordFileStart;		//¼���ļ�����ʼλ�ã������ڣ�
	unsigned int	recordFileEnd;			//¼���ļ��Ľ���λ�ã������ڣ�
	
	unsigned int	diskInfoOffset;			//������Ϣ����ƫ�ƣ�ÿ��¼���ļ���Ӧһ�Σ�
	unsigned int	diskInfoLen;			//������Ϣ�����ܳ���

	unsigned int	recordFileLogNum;		//Ԥ���洢�ռ��д�ļ�¼��Ŀ
	unsigned int	recordFileInfoOffset;	//¼���ļ���Ϣƫ�ƣ��ļ���¼ƫ�ƣ�
	unsigned int	recordFileInfoLen;		//¼���ļ���Ϣ�����ܳ���

	unsigned int	fileLen;				//���Ľ�����

	unsigned int	checkBit;				//У��λ
}DD_RECORD_LOG_FILE_HEAD_INFO;

typedef struct _dd_disk_index_info_
{
	unsigned int	channel;	//ͨ����
	unsigned int	flag;		//��ǣ�����Ϊ0XFFFF)
	
	unsigned int	recv[6];	//������
}DD_DISK_INDEX_INFO;

typedef struct _dd_file_file_info_
{
	unsigned short		deviceID;		//�豸��
	unsigned short		cameraID;		//��������
	unsigned int		channel;		//ͨ����
	
	unsigned int		startTime;		//��ʼʱ��
	unsigned int		endTime;		//����ʱ��

	unsigned int		checkBit;		//У��λ
}DD_FILE_FILE_INFO;

typedef struct _dd_file_log_info_
{
	unsigned char	bLocked;		//0��ʾδ������1��ʾ����
	unsigned char	bUnofficial;	//0��ʾ��ʽ��¼��1��ʾ����ʽ��¼�����޸�ʱ�����ص���¼��
	unsigned char	enableCard;		//�Ƿ�ʹ�ÿ���
	unsigned char	recv;			//�����ֽ�

	unsigned int	type;			//¼������
	unsigned int	startTime;		//��ʼʱ��
	unsigned int	endTime;		//����ʱ��
	unsigned int	size;			//�ö�¼�����ݳ���

	char			cardNo[32];		//����

	unsigned char	recv[8];		//������

	unsigned int	checkBit;		//У��λ
}DD_FILE_LOG_INFO;

typedef struct _dd_date_info_
{
	DD_DATE		date;						//������Ϣ
	std::list<unsigned short> *pFileList;	//���飨ͨ����
}DD_DATE_INFO, *P_DD_DATE_INFO;

const unsigned int	MAX_RECORD_LOG_NUM = 256;

class CDDRecordLog
{
public:
	CDDRecordLog();
	~CDDRecordLog();

	//����һ���µ����ݿ��ļ�
	static bool CreateLogFile(const char *pFilePath, unsigned int fileNum, unsigned char videoInputNum, unsigned int maxLogNum);

	//��ʼ���ͷ���ʼ��һ�����е����ݿ��ļ�
	bool Initial(unsigned char diskIndex, const char *pFilePath = NULL);
	void Quit();
	bool CreateDateList();

	//
	unsigned int WriteLogStart(unsigned int type, unsigned int startTime, bool bCardNo = false, const char *pCardNo = NULL);
	unsigned int WriteLogEnd(unsigned int type, unsigned int endTime, unsigned int size);

	//һЩ��ѯ�ķ���
	unsigned int GetDateList(std::list<DD_DATE> & list);
	unsigned int GetRecordLog(const std::list<unsigned short> & chnn, unsigned int startTime, unsigned int endTime, \
		unsigned int type, std::list<DD_RECORD_LOG> *pLogList);

	//
	unsigned int Lock(const std::list<DD_RECORD_LOG> &logList);
	unsigned int UnLock(const std::list<DD_RECORD_LOG> &logList);
protected:
private:
};
