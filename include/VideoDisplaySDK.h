
#ifndef _VIDEO_DISPLAY_SDK_H_
#define _VIDEO_DISPLAY_SDK_H_

#include "DisplayDefine.h"

#define CALL_METHOD __stdcall

#ifdef VIDEO_DISPLAY_SDK_EXPORTS
#define DISPLAY_API __declspec(dllexport)
#else
//#ifdef WIN32
//#define DISPLAY_API __declspec(dllimport)
//#else
#define DISPLAY_API
#endif
//#endif

#ifdef __cplusplus
extern "C"
{
#endif

//��ʼ����Ƶ��ʾ����ʼ��directdraw����
DISPLAY_API BOOL CALL_METHOD DISPLAY_Init(HWND hWnd, int maxPortNum);

//�ͷ���Դ
DISPLAY_API void CALL_METHOD DISPLAY_Quit(HWND hWnd);

//
DISPLAY_API void CALL_METHOD DISPLAY_SetDisplayPort(HWND hWnd, DISPLAY_PORT *pDisplayPort, int portNum);

//
DISPLAY_API BOOL CALL_METHOD DISPLAY_SetVideoInfo(HWND hWnd, unsigned int deviceID, unsigned short channel, unsigned short streamType, BITMAPINFOHEADER videoInfo);

//��ʾ����
DISPLAY_API void CALL_METHOD DISPLAY_VideoOut(HWND hWnd, unsigned int deviceID, unsigned short channel, unsigned short streamType, unsigned char *pData, int dataLen, LONGLONG llTime);

DISPLAY_API void CALL_METHOD DISPLAY_Start(HWND hWnd, int deviceID, int channel, int streamType);

DISPLAY_API void CALL_METHOD DISPLAY_Stop(HWND hWnd, int deviceID, int channel, int streamType);

DISPLAY_API void CALL_METHOD DISPLAY_HighLightWindow(HWND hWnd, int portIndex);
DISPLAY_API void CALL_METHOD DISPLAY_Refresh(HWND hWnd);

DISPLAY_API BOOL CALL_METHOD DISPLAY_TextOut(HWND hWnd, int deviceID, int channel, int streamType, short x, short y, const char *pText);

DISPLAY_API void CALL_METHOD DISPLAY_RegisterDrawFun(unsigned int deviceID, unsigned short channel, unsigned short streamType, HWND hWnd, DRAW_FUN_CALLBACK fDrawFun, void *pUser);

DISPLAY_API void CALL_METHOD DISPLAY_IsSupportYUV(HWND hWnd,BOOL *pSupport);

DISPLAY_API void CALL_METHOD DISPLAY_SetChannelStatus(HWND hWnd, LONG lDeviceID, int nChannel, CH_STATUS StatusIndex, bool IsSet);

//����SDK�ڲ���ʾ�����Ƿ�ÿ���ظ�������������Ǹ���������Ҫ�ڳ������ʱ����DISPLAY_ClearUp��Ĭ��Ϊ�ظ�����
DISPLAY_API void CALL_METHOD DISPLAY_SetDisplayObjCreateMode(BOOL bReCreate);

DISPLAY_API void CALL_METHOD DISPLAY_ClearUp();


#ifdef __cplusplus
};
#endif

#endif

