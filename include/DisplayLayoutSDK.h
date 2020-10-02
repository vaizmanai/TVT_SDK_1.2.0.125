
#ifndef _DISPLAY_LAYOUT_SDK_H_
#define _DISPLAY_LAYOUT_SDK_H_

#include "DisplayDefine.h"

#ifdef WIN32

#define CALL_METHOD __stdcall

#ifdef LAYOUT_SDK_EXPORTS
#define LAYOUT_API __declspec(dllexport)
#else
//#define LAYOUT_API __declspec(dllimport)
#define LAYOUT_API
#endif

#else

#define CALL_METHOD
#define LAYOUT_API
#endif

enum
{
	LAYOUT_RET_SUCCESS,
	LAYOUT_RET_CHANNEL_BINDED,
	LAYOUT_RET_PORT_BINDED,
	LAYOUT_RET_PORT_EXCEED,
};

//maxPortNum,������õķָ���������������л��ĸ���
LAYOUT_API bool CALL_METHOD LAYOUT_Init(unsigned short maxPortNum);
LAYOUT_API void CALL_METHOD LAYOUT_Cleanup();

//��������ʾ�����С
LAYOUT_API void CALL_METHOD LAYOUT_SetDisplayArea(unsigned short x, unsigned short y, unsigned short width, unsigned short height);

//���ñ�׼��ķָ��,bAutoNext��ʾ���������ϴ���ͬ�ָ�ģʽʱ�Ƿ�Ҫ������һ��ҳ��
LAYOUT_API void CALL_METHOD LAYOUT_SetSplitMode(unsigned int splitMode, bool bAutoNext, unsigned int firstVisiblePort=0);

//�ϲ���ʾ���ڣ���ɾֲ��󴰿�
LAYOUT_API void CALL_METHOD LAYOUT_CombinePort(unsigned short startPort, unsigned short horizSpan, unsigned short vertSpan);

//���ݵ����λ�õõ����򣬷��ص�����������ţ����û�е�����κ����򣬷���-1
LAYOUT_API int CALL_METHOD LAYOUT_GetHitPort(unsigned short x, unsigned short y, DISPLAY_PORT *pHitPort);

//���豸ͨ����ָ��������ʾ����
LAYOUT_API int CALL_METHOD LAYOUT_BindPortVideoStream(unsigned short portIndex, int deviceID, short channel, short streamType);

//���û��л�ͨ��
LAYOUT_API int CALL_METHOD LAYOUT_BindPIPVideoStream(LAYOUT_PIP_POSITION pipPosition, int deviceID, short channel, short streamType);

//���ĳ���豸ͨ����
LAYOUT_API void CALL_METHOD LAYOUT_UnbindVideoStream(int deviceID, short channel, short streamType);

//���ĳ����ʾ���ڣ����portIndexΪ0xffff������������ʾ����,�������л�����
LAYOUT_API void CALL_METHOD LAYOUT_UnbindPort(unsigned short portIndex);

//���ĳ�����л�����
LAYOUT_API void CALL_METHOD LAYOUT_UnbindPIPPort(LAYOUT_PIP_POSITION pipPosition);

//���ص�ǰ������ʾ�������Ϣ
LAYOUT_API int CALL_METHOD LAYOUT_GetLayoutInfo(DISPLAY_PORT *pDisplayPort, int portNum);

#endif

