/*
 *  MinHook - The Minimalistic API Hooking Library for x64/x86
 *  Copyright (C) 2009-2017 Tsuda Kageyu.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 *  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 *  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 *  OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#if !(defined _M_IX86) && !(defined _M_X64) && !(defined __i386__) && !(defined __x86_64__)
    #error MinHook supports only x86 and x64 systems.
#endif

//#include <windows.h>

// MinHook Error Codes.
typedef enum MH_STATUS
{
    // δ֪�Ĵ��󡣲�Ӧ�÷���.
    MH_UNKNOWN = -1,

    // �ɹ���.
    MH_OK = 0,

    // MinHook�Ѿ���ʼ��.
    MH_ERROR_ALREADY_INITIALIZED,

    // MinHook��û�б���ʼ���������Ѿ�û�г�ʼ����.
    MH_ERROR_NOT_INITIALIZED,

    // ָ��Ŀ�꺯���Ĺ����Ѿ���������.
    MH_ERROR_ALREADY_CREATED,

    // ָ��Ŀ�꺯���Ĺ��ӻ�û�д���.
    MH_ERROR_NOT_CREATED,

    // ָ��Ŀ�꺯���Ĺ����Ѿ�������.
    MH_ERROR_ENABLED,

    // ָ��Ŀ�꺯���Ĺ��ӻ�û�����ã������Ѿ�������
    MH_ERROR_DISABLED,

    // ָ����ָ����Ч����ָ��Ƿ����/�򲻿�ִ������ĵ�ַ
    MH_ERROR_NOT_EXECUTABLE,

    // ָ����Ŀ�꺯�����ܱ���ס.
    MH_ERROR_UNSUPPORTED_FUNCTION,

    // �����ڴ�ʧ��.
    MH_ERROR_MEMORY_ALLOC,

    // �޷��ı���䱣��.
    MH_ERROR_MEMORY_PROTECT,

    // ָ����ģ��û�м���.
    MH_ERROR_MODULE_NOT_FOUND,

    // ָ���ĺ���û�б��ҵ�.
    MH_ERROR_FUNCTION_NOT_FOUND
}
MH_STATUS;

// ������Ϊһ���������ݸ� MH_EnableHook, MH_DisableHook,
// MH_QueueEnableHook or MH_QueueDisableHook.
#define MH_ALL_HOOKS NULL

#ifdef __cplusplus
extern "C" {
#endif
	//��ʼ��MinHook�⡣���������������һ��
	//����ĳ���ʼ��ʱ��
    MH_STATUS WINAPI MH_Initialize(VOID);

	//ȡ��MinHook�⡣�����׼ȷ�ص����������
	//����ĳ������ʱ.
    MH_STATUS WINAPI MH_Uninitialize(VOID);

    // ����1��Ϊָ����Ŀ�꺯������һ�����ӣ��ڽ���״̬��.
    // ����:
    //   pTarget    [in]  һ��ָ��HookĿ�꺯����ָ�루����Ŀ���ַ��
    //                    
    //   pDetour    [in]  ָ���Լ��ص�������ָ��
    //              
    //   ppOriginal [out] A pointer to the trampoline function, which will be
    //                    used to call the original target function.
    //                    ������������� NULL.
    MH_STATUS WINAPI MH_CreateHook(LPVOID pTarget, LPVOID pDetour, LPVOID *ppOriginal);

    // ����2��Ϊָ����API��������һ�����ӣ��ڽ���״̬��.
    // ����:
	//   pszModule  [in]  ��һ��ָ����ص�ģ�����Ƶ�ָ���У����а���
	//                    Ŀ�꺯��.�磨"user32"��
    //   pszTarget  [in]  ָ��HOOKĿ�꺯���ĵ�ַ
    //                    �磺��MessageBoxW��.
    //   pDetour    [in]  ָ���Լ��ص�������ָ��
    //                    ���ڵ���ԭʼĿ�꺯��.
    //   ppOriginal [out] һ��ָ��Ĵ�������ָ�룬��������������ԭʼ��Ŀ�꺯��.
    //                    ������������� NULL.
    MH_STATUS WINAPI MH_CreateHookApi(
        LPCWSTR pszModule, LPCSTR pszProcName, LPVOID pDetour, LPVOID *ppOriginal);

    // Ϊָ����API��������һ�����ӣ��ڽ���״̬�£�ǿ���棩.
    // ����:
	//   pszModule  [in]  ��һ��ָ����ص�ģ�����Ƶ�ָ���У����а���
	//                    Ŀ�꺯��.�磨"user32"��.
	//   pszTarget  [in]  ָ��HOOKĿ�꺯���ĵ�ַ
	//                    �磺��MessageBoxW��.
	//   pDetour    [in]  ָ���Լ��ص�������ָ��
	//                    ���ڵ���ԭʼĿ�꺯��.
    //   ppOriginal [out] A pointer to the trampoline function, which will be
    //                    used to call the original target function.
    //                    ������������� NULL.
    //   ppTarget   [out] һ��ָ��Ŀ�꺯����ָ�룬��������������һ��ʹ��.
    //                    ������������� NULL.
    MH_STATUS WINAPI MH_CreateHookApiEx(
        LPCWSTR pszModule, LPCSTR pszProcName, LPVOID pDetour, LPVOID *ppOriginal, LPVOID *ppTarget);

    // ɾ��һ���Ѿ������Ĺ���.
    // ����:
    // Target [in] ָ��Ŀ�꺯����ָ�루��Hook���ĵ�ַ��.
    MH_STATUS WINAPI MH_RemoveHook(LPVOID pTarget);

    // ʹ��һ���Ѿ������Ĺ���.
    // ����:
    //   pTarget [in] ָ��Ŀ�꺯����ָ��.
    //                ������������ MH_ALL_HOOKS, ���д����Ĺ��Ӷ�������һ��go������    
    MH_STATUS WINAPI MH_EnableHook(LPVOID pTarget);
    // �����Ѵ����� hook.
    // ����:
    //   pTarget [in] ָ��Ŀ�꺯����ָ��.
    //                ������������ MH_ALL_HOOKS, ���д����Ĺ��Ӷ�����һ��go�н��á�ooks��һ�������������õ�
    MH_STATUS WINAPI MH_DisableHook(LPVOID pTarget);

    // Queues to enable an already created hook.
    // Parameters:
    //   pTarget [in] A pointer to the target function.
    //                If this parameter is MH_ALL_HOOKS, all created hooks are
    //                queued to be enabled.
    MH_STATUS WINAPI MH_QueueEnableHook(LPVOID pTarget);

    // �����������Ѵ����Ĺҹ�.
    // ����:
    //   pTarget [in] ָ��Ŀ�꺯����ָ��.
    //                ������������ MH_ALL_HOOKS, ���д����Ĺ��Ӷ����Ŷӵȴ����õ�
    MH_STATUS WINAPI MH_QueueDisableHook(LPVOID pTarget);

    // Applies all queued changes in one go.
	//��һ��������Ӧ�����ж��и���
    MH_STATUS WINAPI MH_ApplyQueued(VOID);

    // Translates the MH_STATUS to its name as a string.
	//�� MH_STATUS ������ַ���
    const char * WINAPI MH_StatusToString(MH_STATUS status);

#ifdef __cplusplus
}
#endif

