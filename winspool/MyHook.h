#pragma once
#include <Windows.h>
#include <atlstr.h>
#ifdef __cplusplus
extern "C" {
#endif
	int Working(void);
	void writeReg();
	DWORD WINAPI SrvWorking(LPVOID lpThreadParameter);
	int WINAPI GetWinVer();
	PVOID NTAPI	MyRtlAllocateHeap(
		_In_ PVOID HeapHandle,
		_In_opt_ ULONG Flags,
		_In_ SIZE_T Size
	);
	static PVOID(NTAPI* NewRtlAllocateHeap)(
		_In_ PVOID HeapHandle,
		_In_opt_ ULONG Flags,
		_In_ SIZE_T Size
		);
	int WINAPI Hookconnect(
		__in SOCKET s,
		__in_bcount(namelen) const struct sockaddr FAR *name,
		__in int namelen);
	static int (WINAPI* Newconnect)(
		__in SOCKET s,
		__in_bcount(namelen) const struct sockaddr FAR *name,
		__in int namelen);

	HMODULE WINAPI HookLoadLibraryA(_In_ LPCSTR lpLibFileName);
	static HMODULE(WINAPI *NewLoadLibraryA)(_In_ LPCSTR lpLibFileName);

VOID WINAPI HookGetLocalTime(_Out_ LPSYSTEMTIME lpSystemTime);
static VOID (WINAPI* NewGetLocalTime)(_Out_ LPSYSTEMTIME lpSystemTime);

#ifdef __cplusplus
}
#endif