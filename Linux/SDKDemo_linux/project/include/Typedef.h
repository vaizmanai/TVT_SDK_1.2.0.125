//�����������ͣ�Ϊ��ƽ̨�����������
#ifndef _DVRTYPEDEFINE_
#define _DVRTYPEDEFINE_

#ifdef __ENVIRONMENT_WIN32__ ////////////////////�����Windowsƽ̨
#include "stdafx.h"

//����PACKED ��Ҫ���ڽ����Windows�������һ��ʹ��#pragma pack(n)��Linux��һ��ʹ��__attribute__((packed))
//�ڴ˽ṹ��Ҫд���ļ������ڿ�ƽ̨֮�����ʱ����Ҫ���¶��壬ע��__attribute__((packed))ֻ���ڵ��ֽڶ���
#define PACKED
typedef DWORD				THREAD_ID;
#else ////////////////////linuxƽ̨
#include <sys/types.h>
#include <unistd.h>

#define PACKED __attribute__((packed))
typedef pid_t				THREAD_ID;

typedef unsigned int       DWORD;
typedef DWORD				*LPDWORD;
typedef unsigned int       ULONG;
typedef int                LONG;

typedef short				SHORT;
typedef unsigned short      WORD;

typedef int                 INT;
typedef unsigned int        UINT;

typedef long long           LONGLONG;
typedef unsigned long long  ULONGLONG;

//������Ϊ��������Ķ���ʹ�÷���
typedef	signed char			SBYTE;

typedef signed char			CHAR;
typedef unsigned char       BYTE;

typedef bool				BOOL;
#include <sys/time.h>
typedef timeval				DVRDATETIME;

typedef void *				LPVOID;

typedef void *				HWND;
typedef void *				HDC;

#define TRUE				true
#define FALSE				false

#define CALLBACK

#endif ////////#ifdef __ENVIRONMENT_WIN32__ //�����Windowsƽ̨

#endif ////////#ifndef _DVRTYPEDEFINE_





