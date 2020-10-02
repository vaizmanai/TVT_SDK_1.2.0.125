
#ifndef _VIDEO_DECODE_SDK_H_
#define _VIDEO_DECODE_SDK_H_

/************************************************************************
�ý�����ģ����ö��߳̽��룬�����CPU�������Զ�������ͬ��Ŀ�Ľ����̣߳��Դ�
���������CPU��Դ���н����������
/************************************************************************/

#define CALL_METHOD __stdcall

#ifdef VIDEO_DECODE_SDK_EXPORTS
#define DECODE_API __declspec(dllexport)
#else
//#define DECODE_API __declspec(dllimport)
#define DECODE_API
#endif

enum VIDEO_DECODE_RET
{
	DECODE_RET_SUCCESS,
	DECODE_RET_NOT_START,
	DECODE_RET_BUSY,
};

typedef struct encode_frame_info
{
	unsigned int	keyFrame;
	int			nWidth;
	int			nHeight;
	unsigned int	time;

	int			frameIndex;

	unsigned int	dwLen;
	unsigned char	*pData;
}ENCODE_FRAME_INFO;

typedef struct decode_frameInfo
{
	int			nWidth;
	int			nHeight;
	unsigned int	time;

	unsigned int	dwLen;
	unsigned char	*pData;
}DECODE_FRAME_INFO;

#ifdef __cplusplus
extern "C"
{
#endif

typedef void (CALL_METHOD *DecDataCallbackFun)(int threadID, int deviceID, unsigned short channel, int streamType, DECODE_FRAME_INFO frameData, void *pUser);

//��ʼ����������Ϊ������������Դ
DECODE_API BOOL CALL_METHOD DECODE_Initial();

//�˳����������ͷŽ�������Դ
DECODE_API void CALL_METHOD DECODE_Quit();

//����ĳ��ͨ�����Ľ���
DECODE_API BOOL CALL_METHOD DECODE_Start(int deviceID, int channel, int streamType);

//ָֹͣ��ͨ�������Ľ���
DECODE_API void CALL_METHOD DECODE_Stop(int deviceID, int channel, int streamType);

//����ָ��ͨ����������Ƶ��ʽ
DECODE_API BOOL CALL_METHOD DECODE_SetVideoFormat(int deviceID, int channel, int streamType, BITMAPINFOHEADER bmpInfoHeader);

//��ȡָ��ͨ�����������ĸ�ʽ
DECODE_API BOOL CALL_METHOD DECODE_GetDecVideoFormat(int deviceID, int channel, int streamType, BITMAPINFOHEADER *pBmpInfoHeader);

//���ý�����Ƿ�ΪYUV(0���ǣ�1��)
DECODE_API void CALL_METHOD DECODE_SetDecVideoFormat(BOOL enbaleYUV);

//����һ֡���ݣ����ؽ����VIDEO_DECODE_RET
DECODE_API LONG CALL_METHOD DECODE_DecodeOneFrame(int deviceID, int channel, int streamType, ENCODE_FRAME_INFO encodeFrame);

//���ý��������ݻص�
DECODE_API BOOL CALL_METHOD DECODE_SetDecDataCallback(int deviceID, int channel, int streamType, DecDataCallbackFun fDecCBFun, void *pParam);

DECODE_API BOOL CALL_METHOD DECODE_CapturePictureJPEG(DWORD &dwPicSize,int deviceID,DWORD dwChannel,int streamType, BYTE *pUserBuf,DWORD dwUserSize);


#ifdef __cplusplus
};
#endif

#endif
