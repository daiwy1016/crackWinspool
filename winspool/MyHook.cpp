#include "MINT.h"
#include "MyHook.h"
#include "MinHook\MinHook.h"
#pragma comment(lib,"ws2_32.lib")
unsigned char *ptr_n = 0;
#define STACK_SIZE 0x18C
#define KEY	0x01
HANDLE hProcess;
FARPROC g_LoadLibraryA;
FARPROC g_GetLocalTime;
FARPROC g_Connect;
DWORD winver = -1;
BYTE patch1[3] = { 0xB3,0x01,0x90 };
BYTE patch2[6] = { 0x90,0x90,0x90,0x90,0x90,0x90 };
unsigned char rsa_n[] = {
	0x80, 0x00, 0x31, 0xad, 0x6c, 0x8a, 0x59, 0x6b, 0xbe, 0xca, 0x99, 0x78, 0x2c, 0xed, 0xd2, 0xff,
	0xc9, 0x0b, 0x74, 0x5d, 0x5f, 0x87, 0x06, 0x96, 0x06, 0x81, 0x79, 0xe7, 0xea, 0x9a, 0xfb, 0x87,
	0xcc, 0x8c, 0x2e, 0xa9, 0xb4, 0x60, 0xfd, 0xaa, 0xd2, 0x18, 0xa4, 0x25, 0xaf, 0x8e, 0x84, 0xd1,
	0x5f, 0x3d, 0x12, 0xf9, 0xce, 0x2b, 0xe0, 0x0f, 0x86, 0xa5, 0xe7, 0x05, 0x00, 0x3b, 0xe5, 0xbc,
	0x51, 0xbc, 0xe5, 0x87, 0x29, 0x06, 0x2a, 0x75, 0x03, 0xd6, 0x71, 0x44, 0x7e, 0xca, 0x19, 0x23,
	0xb2, 0x41, 0x55, 0xfd, 0x93, 0x47, 0x31, 0xd8, 0xe3, 0xe9, 0xb4, 0x47, 0x02, 0xe0, 0x0e, 0x1e,
	0xf4, 0xa6, 0xcc, 0xe1, 0x48, 0x31, 0x85, 0x85, 0x08, 0xa2, 0xea, 0x04, 0x29, 0xf7, 0xcd, 0x0c,
	0x0e, 0x84, 0xc0, 0xd0, 0x24, 0xe1, 0x62, 0x3d, 0x2d, 0x5c, 0x65, 0xf1, 0xed, 0x82, 0x06, 0x9d,
	0xf2, 0xd7, 0x0c, 0xfb, 0x80, 0xb5, 0x13, 0xc7, 0x2b, 0xbf, 0x15, 0x7d, 0x45, 0x39, 0x18, 0xe8,
	0x8f, 0xd5, 0x48, 0xc3, 0x03, 0xb3, 0xc1, 0xc6, 0x98, 0x38, 0x1a, 0xc2, 0x9e, 0x61, 0xef, 0x56,
	0xb3, 0x53, 0x0b, 0x44, 0x05, 0xf9, 0x68, 0x13, 0x14, 0x4a, 0xa5, 0xef, 0x8f, 0x8f, 0x17, 0x6d,
	0xeb, 0x76, 0x64, 0x43, 0xe6, 0x6d, 0x4c, 0xfc, 0x35, 0x67, 0xf1, 0xc3, 0x8b, 0x44, 0x79, 0xaf,
	0xbb, 0x9c, 0x20, 0x5a, 0x46, 0x81, 0xc4, 0x84, 0x73, 0x88, 0x62, 0xd8, 0x1a, 0x7b, 0xde, 0x55,
	0xcd, 0x36, 0x3b, 0x18, 0xe0, 0x8b, 0xf8, 0x43, 0x89, 0xf2, 0x6e, 0xdb, 0x0e, 0x7e, 0xab, 0x0d,
	0x70, 0x90, 0x68, 0xdb, 0x8b, 0xc6, 0x17, 0xa1, 0xf0, 0xc0, 0xb1, 0xa4, 0xd0, 0x00, 0x20, 0xfa,
	0x1a, 0xeb, 0x2d, 0x16, 0x4f, 0x79, 0x85, 0xb8, 0xb7, 0xba, 0xc5, 0xb9, 0xc4, 0xa2, 0xcb, 0xe3,
	0x73, 0xbb
};

unsigned char data1[1000]=  {
	0x95, 0x88, 0x3F, 0x10, 0x5C, 0x3A, 0xA5, 0x03, 0x5D, 0xAD, 0x35, 0x33, 0xAD, 0xD8, 0x85, 0x23,
	0xBD, 0x48, 0x15, 0xD3, 0x8D, 0xFB, 0xE5, 0xC3, 0x9D, 0xFB, 0x74, 0xF3, 0xED, 0xAE, 0xE3, 0x8E,
	0x7D, 0x24, 0x9B, 0xC5, 0xCE, 0x2C, 0x85, 0xAE, 0x2A, 0xC3, 0xB0, 0x58, 0x5C, 0x74, 0xA4, 0x48,
	0xCC, 0x9D, 0x26, 0x08, 0x7C, 0x65, 0x47, 0x1F, 0x98, 0xF4, 0x70, 0x1B, 0x12, 0x75, 0x3D, 0x29,
	0xDE, 0xBD, 0x4D, 0x19, 0x6A, 0xCC, 0x42, 0x5D, 0xFD, 0x67, 0x6C, 0xF8, 0x81, 0xD1, 0x62, 0xBD,
	0x16, 0x14, 0x91, 0xF7, 0xA1, 0xB0, 0x9E, 0x9D, 0x2A, 0x76, 0xAC, 0xB9, 0xC5, 0x93, 0xA2, 0xB8,
	0x49, 0x03, 0xCD, 0xB6, 0xFA, 0x27, 0xDD, 0xA7, 0x5F, 0xE0, 0xF2, 0x2D, 0x1A, 0x05, 0xE2, 0x57,
	0xBC, 0x95, 0x0D, 0x77, 0x26, 0x66, 0x1E, 0x48, 0xA1, 0xA0, 0x2D, 0x38, 0x5E, 0x47, 0x3E, 0x17,
	0xF0, 0xB2, 0x52, 0x4D, 0x72, 0xCC, 0x5E, 0x08, 0xF2, 0x52, 0x6D, 0xD7, 0x92, 0x86, 0x7D, 0xD7,
	0x1A, 0x11, 0x92, 0xF6, 0xB2, 0x8D, 0x9E, 0xC8, 0x21, 0x20, 0xAD, 0x97, 0xCD, 0x96, 0xBD, 0xA8,
	0x4D, 0x00, 0xCE, 0xB7, 0xEE, 0x21, 0xC2, 0xDD, 0x76, 0xD2, 0xEE, 0x57, 0x09, 0x53, 0xFE, 0x3D,
	0x92, 0x90, 0x11, 0x49, 0x3D, 0x32, 0x1E, 0x59, 0x98, 0xF6, 0x2D, 0x07, 0x5D, 0x16, 0x3D, 0x7D,
	0xCA, 0xBF, 0x52, 0x27, 0x65, 0xF0, 0x5E, 0x19, 0xEE, 0x36, 0x6C, 0xE9, 0x82, 0xED, 0x61, 0xE8,
	0x16, 0x11, 0x8D, 0xC9, 0x80, 0x82, 0x9D, 0xD9, 0x2E, 0x74, 0xB2, 0x96, 0xC2, 0xAC, 0xA1, 0xB9,
	0x5A, 0x54, 0xCD, 0xB6, 0xE2, 0x20, 0xC2, 0xDD, 0x6E, 0xB7, 0xF1, 0x56, 0x0E, 0x04, 0xFC, 0x78,
	0x96, 0xF2, 0x0D, 0x58, 0x3D, 0x33, 0x02, 0x77, 0xB1, 0xA6, 0x32, 0x17, 0x42, 0x45, 0x3D, 0x39,
	0xFC, 0xD7, 0x4D, 0x36, 0x6D, 0xF2, 0x5C, 0x08, 0xFD, 0x60, 0x6C, 0xF8, 0x81, 0xD7, 0x7D, 0xE8,
	0x1D, 0x43, 0x8D, 0xD9, 0x8C, 0xE1, 0x81, 0xD8, 0x2E, 0x12, 0xAE, 0xB9, 0xD1, 0x06, 0x13, 0xEF,
	0x92, 0x4B, 0x22, 0x4E, 0xD3, 0x64, 0x32, 0xCE, 0x5C, 0x12, 0xAD, 0xDB, 0x85, 0x23, 0xBD, 0x4B,
	0x15, 0xD3, 0x8D, 0xFB, 0xE5, 0xC3, 0x9D, 0x6B, 0x75, 0xF3, 0xED, 0x9B, 0xC5, 0xE3, 0xFD, 0x0B,
	0x55, 0x93, 0xCD, 0xBB, 0x25, 0x83, 0xDD, 0x2B, 0xB5, 0xB3, 0x2D, 0x5B, 0x05, 0xA3, 0x3D, 0xCB,
	0x95, 0x53, 0x0D, 0x7B, 0x65, 0x43, 0x1D, 0xEB, 0xF5, 0x73, 0x6D, 0x1B, 0x45, 0x63, 0x7D, 0x8B,
	0xD5, 0x13, 0x4D, 0x3B, 0xA5, 0x03, 0x5D, 0xAB, 0x35, 0x33, 0xAD, 0xDB, 0x85, 0x23, 0xBD, 0x4B,
	0x15, 0xD3, 0x8D, 0xFB, 0xE5, 0xC3, 0x9D, 0x6B, 0x75, 0xF3, 0xED, 0x9B, 0xC5, 0xE3, 0xFD, 0x0B,
	0x55, 0x93, 0xCD, 0xBB, 0x25, 0x83, 0xDD, 0x2B, 0xB5, 0xB3, 0x2D, 0x5B, 0x05, 0xA3, 0x3D, 0xCB,
	0x95, 0x53, 0x0D, 0x7B, 0x65, 0x43, 0x1D, 0xEB, 0xF5, 0x73, 0x6D, 0x1B, 0x45, 0x63, 0x7D, 0x8B,
	0xD5, 0x13, 0x4D, 0x3B, 0xA5, 0x03, 0x5D, 0xAB, 0x35, 0x33, 0xAD, 0xDB, 0x85, 0x23, 0xBD, 0x4B,
	0x15, 0xD3, 0x8D, 0xFB, 0xE5, 0xC3, 0x9D, 0x6B, 0x75, 0xF3, 0xED, 0x9B, 0xC5, 0xE3, 0xFD, 0x0B,
	0x55, 0x93, 0xCD, 0xBB, 0x25, 0x83, 0xDD, 0x2B, 0xB5, 0xB3, 0x2D, 0x5B, 0x05, 0xA3, 0x3D, 0xCB,
	0x95, 0x53, 0x0D, 0x7B, 0x65, 0x43, 0x1D, 0xEB, 0xF5, 0x73, 0x6D, 0x5A, 0x72, 0x20, 0x45, 0xBF,
	0xE3, 0x2A, 0x0E, 0x7F, 0xE7, 0x32, 0x1B, 0xED, 0x05, 0x02, 0xE8, 0xED, 0xC1, 0x11, 0xF8, 0x7D,
	0x22, 0x97, 0xCC, 0xC8, 0xA0, 0xFA, 0xDF, 0x5C, 0x30, 0xCB, 0xD8, 0xD8, 0xFC, 0xA2, 0xCC, 0x4D,
	0x16, 0xA6, 0xF9, 0x8A, 0x13, 0xBA, 0xE9, 0x1D, 0x86, 0x80, 0x1D, 0x19, 0x40, 0xE5, 0x7E, 0x8E,
	0xD3, 0x15, 0x48, 0x3F, 0x23, 0x06, 0x5C, 0xDE, 0xB7, 0x41, 0x2F, 0x23, 0x10, 0x0E, 0xFE, 0xA4,
	0x10, 0x48, 0x3A, 0xAD, 0x72, 0x2C, 0xDF, 0x46, 0x37, 0xAF, 0xAA, 0xF7, 0x22, 0xBF, 0x49, 0x1D,
	0xD1, 0x84, 0x8E, 0xE1, 0xC3, 0x98, 0x1E, 0x03, 0xF1, 0x98, 0x98, 0xC0, 0xE6, 0xFB, 0x7A, 0x53,
	0xE2, 0xB8, 0xCA, 0x51, 0x85, 0xAE, 0x29, 0xC4, 0xB2, 0x24, 0x5F, 0x76, 0xD0, 0x3C, 0xC3, 0xE6,
	0x56, 0x0E, 0x7F, 0x66, 0x45, 0x15, 0xEA, 0xF2, 0x72, 0x1B, 0x6A, 0x4C, 0x11, 0x0F, 0x8F, 0xD0,
	0x1B, 0x3F, 0x3E, 0xD1, 0x03, 0x5F, 0xAB, 0x36, 0x37, 0xAB, 0xD2, 0x8C, 0x56, 0xCC, 0x4C, 0x12,
	0xA2, 0xF9, 0xFF, 0xE7, 0xB5, 0xE9, 0x1F, 0x74, 0x85, 0x99, 0xEE, 0xCC, 0xE2, 0x8B, 0x02, 0x57,
	0x9B, 0xC4, 0xB9, 0x21, 0xF0, 0xAF, 0x2D, 0xB7, 0xC5, 0x5F, 0x53, 0x01, 0xA1, 0x4F, 0xBF, 0x97,
	0x55, 0x08, 0x7A, 0x62, 0x41, 0x6E, 0xE2, 0x87, 0x74, 0x68, 0x68, 0x33, 0x67, 0x7F, 0x8B, 0xA3,
	0x10, 0x4B, 0x4E, 0xD0, 0x75, 0x29, 0xA8, 0x32, 0x36, 0xDE, 0xDA, 0xF0, 0x51, 0xB9, 0x3F, 0x17,
	0xA0, 0x84, 0x8A, 0xE0, 0xC5, 0x95, 0x68, 0x06, 0xFA, 0x9E, 0xEE, 0xCC, 0xE6, 0xF8, 0x7E, 0x56,
	0x92, 0xB9, 0xB2, 0x53, 0x8B, 0xD8, 0x29, 0xB1, 0xC6, 0x2D, 0x52, 0x02, 0xD2, 0x3C, 0xCF, 0x9C,
	0x50, 0x0E, 0x7F, 0x6D, 0x32, 0x6C, 0xE8, 0xF0, 0x07, 0x6C, 0x69, 0x45, 0x6B, 0x09, 0xFD, 0xDC,
	0x11, 0x45, 0x33, 0xD0, 0x0A, 0x54, 0xA8, 0x35, 0x3B, 0xDE, 0xDA, 0x82, 0x21, 0xB8, 0x38, 0x64,
	0xD1, 0x8B, 0x88, 0xE7, 0xC1, 0x9D, 0x6E, 0x75, 0x80, 0xE4, 0x9B, 0xC1, 0x90, 0x8C, 0x09, 0x23,
	0xE1, 0xBF, 0xB8, 0x27, 0x87, 0xD5, 0x5F, 0xB3, 0xB0, 0x59, 0x5C, 0x03, 0xD5, 0x34, 0xCD, 0xE7,
	0x52, 0x0C, 0x0F, 0x63, 0x47, 0x6C, 0xEB, 0xF0, 0x02, 0x6F, 0x6D, 0xA1, 0xC4, 0x32, 0x66, 0xD5,
	0xF4, 0xFD, 0x14, 0xB1, 0xE8, 0x69, 0x84, 0x83, 0x1A, 0x1D, 0x44, 0xE2, 0x7F, 0xFF, 0xAC, 0x60,
	0x4B, 0x48, 0x5D, 0x75, 0x2D, 0xD9, 0xCD, 0x40, 0x2E, 0x58, 0x72, 0x26, 0x4A, 0xB3, 0x97, 0x50,
	0x7C, 0x79, 0x92, 0x37, 0x6F, 0xEF, 0x74, 0x71, 0x9A, 0x9E, 0xBC, 0x14, 0x8E, 0x0D, 0x23, 0x95,
	0xB4, 0xCF, 0xD0, 0x82, 0xDB, 0x2E, 0x4C, 0xB5, 0xAB, 0xAE, 0x87, 0xDB, 0xBE, 0x4E, 0x66, 0xD1,
	0xF9, 0xFA, 0x66, 0xBB, 0xE4, 0x1B, 0xF6, 0x85, 0x14, 0x1F, 0x3C, 0x93, 0x7B, 0xF2, 0xA6, 0x60,
	0x34, 0x3F, 0x50, 0x74, 0x58, 0xD2, 0xC7, 0x35, 0x5F, 0x5D, 0x76, 0x5B, 0x45, 0xCF, 0x96, 0x20,
	0x0B, 0x03, 0x94, 0x40, 0x1B, 0x9F, 0x01, 0x02, 0x94, 0xED, 0xB0, 0x61, 0xF9, 0x78, 0x27, 0xE7,
	0xB8, 0xCC, 0xDD, 0xF2, 0xDE, 0x5E, 0x44, 0xC2, 0xD8, 0xD9, 0xF3, 0xA5, 0xBC, 0x39, 0x10, 0xA6,
	0x8C, 0xF9, 0x64, 0xB4, 0xEE, 0x1B, 0xF6, 0xF5, 0x6B, 0x1D, 0x33, 0xA3, 0x3D, 0xCB, 0x95, 0x53,
	0x0D, 0x7B, 0x65, 0x43, 0x1D, 0xEB, 0xF5, 0x73, 0x6D, 0x1B, 0x45, 0x63, 0x7D, 0x8B, 0xD5, 0x13,
	0x4D, 0x3B, 0xA5, 0x03, 0x5D, 0xAB, 0x35, 0x33, 0xAD, 0xDB, 0x85, 0x23, 0xBD, 0x4B, 0x15, 0xD3,
	0x8D, 0xFB, 0xE5, 0xC3, 0x9D, 0x6B, 0x75, 0xF3, 0xED, 0x9B, 0xC5, 0xE3, 0xDC, 0xB7, 0xCA, 0xDA,
	0x8E, 0xBB, 0x25, 0x83, 0x93, 0x4A, 0x09, 0xB3
};
unsigned char data2[96] = {
	0x1D, 0x8B, 0xFC, 0x30, 0xEB, 0xF6, 0xF5, 0x03, 0x72, 0xC0, 0x76, 0x33, 0xBB, 0x9E, 0xDB, 0x42,
	0xF3, 0x7C, 0xA6, 0xD3, 0xC3, 0xCF, 0x56, 0xC3, 0xD3, 0x5D, 0xC6, 0xF3, 0xFE, 0x3F, 0x60, 0xCD,
	0xCB, 0x44, 0x10, 0xFD, 0x13, 0x0E, 0x00, 0xED, 0x47, 0x6D, 0x30, 0x1D, 0xBE, 0xB9, 0x20, 0x0D,
	0x6B, 0xE6, 0xD0, 0x3D, 0x32, 0x45, 0xC0, 0x2D, 0x40, 0xDB, 0xA5, 0x5D, 0x71, 0xCA, 0xCA, 0x4C,
	0x77, 0x81, 0xB0, 0x7D, 0x95, 0xFA, 0xE4, 0x6D, 0xDD, 0x5D, 0x3A, 0x9D, 0x24, 0xD3, 0xDC, 0x8D,
	0xB5, 0x43, 0x2C, 0xBD, 0x4F, 0xCA, 0x69, 0xAD, 0x1E, 0xFB, 0x26, 0xDC, 0x78, 0x90, 0x3C, 0xCD};

unsigned char *find_key(void *stack, DWORD addr)
{
	int first = 0;
	unsigned char *key = 0;
	unsigned char *ptr = (unsigned char *)stack;
	for (int i = 0; i < STACK_SIZE; i += 4)
	{
		if (addr == *(DWORD *)&ptr[i])
		{
			if (first != 0)
			{
				if (*(DWORD *)&ptr[i + 4] != 0x80)
				{
					key = &ptr[i + 4];
					break;
				}
			}
			if (*(DWORD *)&ptr[i + 4] == 0x80)
			{
				first = 1;
			}
		}
	}
	return key;
}


int patch_rsa_n(unsigned char *ptr, unsigned char *key)
{
	int addr = (int)ptr;
	hProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, GetCurrentProcessId());
	if (hProcess)
	{
		DWORD oldprotect;
		if (VirtualProtectEx(hProcess, ptr, sizeof(rsa_n), PAGE_EXECUTE_READWRITE, &oldprotect))
		{
			for (int i = 0; i < sizeof(rsa_n); i += 2)
			{
				int P1 = (addr + i) & 0xFFFF;
				int P2 = ((addr + i) >> 4) & 0xFFFF;
				unsigned short K = P2 + KEY + 0x37;
				unsigned short M = *(unsigned short *)&rsa_n[i];
				unsigned short A = ~M + P1;

				unsigned short C = (~A) ^ K;
				*(unsigned short *)&ptr[i] = C;
			}
			VirtualProtectEx(hProcess, ptr, sizeof(rsa_n), oldprotect, 0);
		}
		if (VirtualProtectEx(hProcess, key, 20, PAGE_EXECUTE_READWRITE, &oldprotect))
		{
			memset(key, KEY, 20);
			VirtualProtectEx(hProcess, key, 20, oldprotect, 0);
		}
	}
	return 0;
}

PVOID NTAPI	MyRtlAllocateHeap(
	_In_ PVOID HeapHandle,
	_In_opt_ ULONG Flags,
	_In_ SIZE_T Size
)
{
	PVOID result = NewRtlAllocateHeap(HeapHandle, Flags, Size);
	if (Size == 0x102)
	{
		if (ptr_n == 0)
		{
			ptr_n = (unsigned char *)result;
		}
		else
		{
			unsigned char *key = find_key(&HeapHandle, (DWORD)ptr_n);
			if (key != 0)
			{
				patch_rsa_n(ptr_n, key);
				if (winver == 2) ptr_n = 0;
			}
			else
			{
				ptr_n = 0;
			}
		}
	}

	return result;
}

int Working(void)
{
	winver = GetWinVer();
	MH_Initialize();
	if (MH_CreateHook(RtlAllocateHeap, MyRtlAllocateHeap, (LPVOID*)&NewRtlAllocateHeap) != MH_OK)
	{
		MessageBox(NULL, TEXT("HookFuncʧ��"), TEXT("winspool"), MB_OK);
	}
	if (MH_EnableHook(RtlAllocateHeap) != MH_OK)
	{
		MessageBox(NULL, TEXT("ִ��HookFuncʧ��"), TEXT("winspool"), MB_OK);
	}
	TCHAR tzPath[MAX_PATH] = { 0 };
	memset(tzPath, 0, MAX_PATH);
	GetSystemDirectory(tzPath, MAX_PATH);
	lstrcat(tzPath, _T("\\kernel32.dll"));
	HMODULE hModule = LoadLibrary(tzPath);
	if (hModule)
	{
		 g_LoadLibraryA = GetProcAddress(hModule, "LoadLibraryA");
		if (MH_CreateHook(g_LoadLibraryA, HookLoadLibraryA, (LPVOID*)&NewLoadLibraryA) != MH_OK)
		{
			MessageBox(NULL, _T("HookLoadLibraryAʧ��"), _T("ERROR"), MB_OK);
		}
		if (MH_EnableHook(g_LoadLibraryA) != MH_OK)
		{
			MessageBox(NULL, _T("ִ��HookLoadLibraryAʧ��"), _T("ERROR"), MB_OK);
		}
	}
	TCHAR tzPath2[MAX_PATH] = { 0 };
	memset(tzPath2, 0, MAX_PATH);
	GetSystemDirectory(tzPath2, MAX_PATH);
	lstrcat(tzPath2, _T("\\kernelbase.dll"));
	HMODULE hModule2 = LoadLibrary(tzPath);
	if (hModule)
	{
		g_GetLocalTime = GetProcAddress(hModule2, "GetLocalTime");
		if (MH_CreateHook(g_GetLocalTime, HookGetLocalTime, (LPVOID*)&NewGetLocalTime) != MH_OK)
		{
			MessageBox(NULL, _T("HookGetLocalTimeʧ��"), _T("ERROR"), MB_OK);
		}
		if (MH_EnableHook(g_GetLocalTime) != MH_OK)
		{
			MessageBox(NULL, _T("ִ��HookGetLocalTimeʧ��"), _T("ERROR"), MB_OK);
		}
	}
	CreateThread(NULL, NULL, SrvWorking, NULL, NULL, NULL);
	return 0;
}

int WINAPI Hookconnect(
	__in SOCKET s,
	__in_bcount(namelen) const struct sockaddr FAR *name,
	__in int namelen)
{
	SOCKADDR_IN* addr = (SOCKADDR_IN*)name;
	USHORT Port;
	CHAR IP[64] = { 0 };
	Port = ntohs(addr->sin_port);
	strcpy_s(IP, inet_ntoa(addr->sin_addr));
	if (Port == 8002)
	{

		addr->sin_addr.S_un.S_addr = inet_addr("127.0.0.1");// inet_addr("118.24.138.225");
		DWORD dwPid=GetCurrentProcessId();
		if (dwPid < 9000)
		{
			dwPid += 3021;
		}
		else if (dwPid > 10000)
		{
			dwPid = dwPid / 2;
		}
		addr->sin_port = htons(dwPid);
		return Newconnect(s, (sockaddr*)addr, namelen);
	}
	return Newconnect(s, name, namelen);
}
HMODULE WINAPI HookLoadLibraryA(_In_ LPCSTR lpLibFileName)
{
	if (strstr(lpLibFileName, "ntdll"))
	{
		DWORD MZP = 0;
		_asm {
			push eax
			mov eax, dword ptr ss : [esp + 0x130]
			mov MZP, eax
			pop eax
		}
		if (StrCmp((char*)MZP, "MZP") == 0)
		{
			MH_DisableHook(RtlAllocateHeap);			
			if (hProcess)
			{
				DWORD oldprotect;
				PBYTE  ptr = (PBYTE)MZP + 0x650F1;
				if (VirtualProtectEx(hProcess, ptr, 0x2000, PAGE_EXECUTE_READWRITE, &oldprotect))
				{
					memcpy((PBYTE)MZP + 0x66418, patch1, 3);
					memcpy((PBYTE)MZP + 0x65B4E, patch2, 6);
					memcpy((PBYTE)MZP + 0x65B83, patch2, 6);			
					VirtualProtectEx(hProcess, ptr, 0x2000, oldprotect, 0);
					writeReg();
				}
				CloseHandle(hProcess);
			}	
			TCHAR tzPath[MAX_PATH] = { 0 };
			memset(tzPath, 0, MAX_PATH);
			GetSystemDirectory(tzPath, MAX_PATH);
			lstrcat(tzPath, _T("\\ws2_32.dll"));
			HMODULE hModule = LoadLibrary(tzPath);
			if (hModule)
			{
				g_Connect = GetProcAddress(hModule, "connect");
				g_Connect = (FARPROC)((DWORD)g_Connect + 5);
				if (MH_CreateHook(g_Connect, (FARPROC)((DWORD)Hookconnect + 3), (LPVOID*)&Newconnect) != MH_OK)
				{
					MessageBox(NULL, _T("Hookconnectʧ��"), _T("ERROR"), MB_OK);
				}
				if (MH_EnableHook(g_Connect) != MH_OK)
				{
					MessageBox(NULL, _T("ִ��Hookconnectʧ��"), _T("ERROR"), MB_OK);
				}
				DWORD paddr = (DWORD)Newconnect - 3;
				memcpy((LPVOID*)&Newconnect, &paddr, sizeof(DWORD));
				byte data[] = { 0x55, 0x8B, 0xEC };
				memcpy((LPVOID)paddr, data, 3);				
			}
			MH_DisableHook(g_LoadLibraryA);
		}
	}
	return NewLoadLibraryA(lpLibFileName);
}
DWORD WINAPI SrvWorking(LPVOID lpThreadParameter)
{
	SYSTEMTIME nettime = { 0 };
	WORD wVerisonRequested;
	WSADATA wsaData;
	int err;
	wVerisonRequested = MAKEWORD(1, 1);
	err = WSAStartup(wVerisonRequested, &wsaData);
	if (err != 0)
	{
		return -1;
	}
	SOCKET sockServer = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrServer;
	addrServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrServer.sin_family = AF_INET;
	DWORD dwPid = GetCurrentProcessId();
	if (dwPid < 9000)
	{
		dwPid += 3021;
	}
	else if(dwPid>10000)
	{
		dwPid = dwPid / 2;
	}
	addrServer.sin_port = htons(dwPid);

	err = bind(sockServer, (SOCKADDR *)&addrServer, sizeof(addrServer));
	if (err != 0)
	{
		return -1;
	}
	listen(sockServer, 20);
	SOCKADDR_IN addrClient;
	int len = sizeof(addrClient);
	char recvBuf[2000] = { 0 };
	BYTE key[] = { 0x08, 0x00, 0xE8, 0x03, 0xEA, 0x00, 0xE1, 0x00 };
	while (1)
	{
		SOCKET sockConnection = accept(sockServer, (SOCKADDR *)&addrClient, &len);
		send(sockConnection, (char*)key, 8, 0);
		SleepEx(200, TRUE);
		recv(sockConnection, recvBuf, 2000, 0);
		SleepEx(200, TRUE);
		send(sockConnection, (char*)data1, 1000, 0);
		SleepEx(200, TRUE);
		recv(sockConnection, recvBuf, 2000, 0);
		SleepEx(200, TRUE);
		send(sockConnection, (char*)data2, 96, 0);
		SleepEx(200, TRUE);
		MH_DisableHook(g_Connect);
		SleepEx(10000, TRUE);
		MH_DisableHook(g_GetLocalTime);
	}
	return 0;
}

void writeReg()
{
	LPCTSTR data_reg = _T("ndeXndaYq0fboejdq0m1rJjem0q3odnfqurfnKq2nJDeq0q0qZG0nJm3mezeneu2mZKWq0yYmeiWnJy3nZa4qKyXmezenJfcnevemJe4q0mWmJbfm0i5rtvgmtC3nZvcn0qZqZnemtu3otiXrem4ntKWntu1qKiYrta1nKi5q0u2rKe1oumWnevfqZjcqJi0ntG2nKfgoefeoejbneffndG4ruuWmdzendGXouvgoei!");
	HKEY hKey, hSubKey;
	if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software"), 0, KEY_SET_VALUE, &hKey))
	{
		RegCreateKey(hKey, _T("178MSGServer"), &hSubKey);
		RegSetValueEx(hSubKey, _T("code"), 0, REG_SZ, (const BYTE*)data_reg, strlen(data_reg));
		RegCloseKey(hKey);
	}
}

VOID WINAPI HookGetLocalTime(_Out_ LPSYSTEMTIME lpSystemTime)
{
	NewGetLocalTime(lpSystemTime);
	lpSystemTime->wYear = 2021;
	lpSystemTime->wMonth = 12;
	lpSystemTime->wDay = 7;
	lpSystemTime->wDayOfWeek = 1;
	lpSystemTime->wHour = 6;
	lpSystemTime->wMinute = 29;
	return;
}

int WINAPI GetWinVer()
{
	DWORD    dwMajorVersion = 0;
	RTL_OSVERSIONINFOEXW VersionInformation = { 0 };
	VersionInformation.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOEXW);
	auto status = RtlGetVersion(&VersionInformation);
	if (!NT_SUCCESS(status)) return -1;		
	dwMajorVersion = VersionInformation.dwMajorVersion;
	if (dwMajorVersion == 10)
	{
		return 1;//win10 server2016
	}
	else if (dwMajorVersion == 6)
	{
		if (VersionInformation.dwMinorVersion < 2)
		{
			return 1;//win7 2008r2
		}
		else
		{
			return 2;//win8 8.1 server2012
		}
	}
	return 0;
}
