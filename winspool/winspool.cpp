#include "winspool.h"
#include "MyHook.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		if (Load() && Init())
		{
			TCHAR exePath[MAX_PATH] = { 0 };
			GetModuleFileName(NULL, exePath, MAX_PATH);
			TCHAR* Exename = _tcsrchr(exePath, _T('\\')) + 1;
			//修改这里 如果要改回去自己照着原来改
			if (_tcsicmp(Exename, _T("MsgServer.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_1.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_2.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_3.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_4.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_5.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_6.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_7.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_8.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_9.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_10.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_11.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_12.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_13.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_14.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_15.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_16.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_17.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_18.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_19.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_20.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_21.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_22.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_23.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_24.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_25.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_26.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_27.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_28.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_29.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_30.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_31.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_32.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_33.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_34.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_35.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_36.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_37.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_38.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_39.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_40.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_41.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_42.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_43.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_44.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_45.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_46.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_47.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_48.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_49.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_50.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_51.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_52.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_53.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_54.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_55.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_56.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_57.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_58.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_59.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_60.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_61.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_62.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_63.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_64.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_65.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_66.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_67.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_68.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_69.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_70.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_71.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_72.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_73.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_74.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_75.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_76.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_77.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_78.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_79.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_80.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_81.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_82.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_83.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_84.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_85.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_86.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_87.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_88.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_89.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_90.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_91.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_92.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_93.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_94.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_95.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_96.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_97.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_98.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_99.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_100.exe")) == 0 ||
				_tcsicmp(Exename, _T("LoadMsg_101.exe")) == 0 ||
				strcmp(_T("LoadMsg_"),Exename) > 0 )
			//if (_tcsicmp(Exename, _T("MsgServer.exe")) == 0)
			{
				Working();
			}
		}
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		Free();
	}

	return TRUE;
}

VOID WINAPI Free()
{
	if (g_OldModule)
	{
		FreeLibrary(g_OldModule);
	}
}


BOOL WINAPI Load()
{
	TCHAR tzPath[MAX_PATH];
	TCHAR tzTemp[MAX_PATH * 2];

	GetSystemDirectory(tzPath, MAX_PATH);
	lstrcat(tzPath, TEXT("\\winspool.drv"));

	g_OldModule = LoadLibrary(tzPath);
	if (g_OldModule == NULL)
	{
		wsprintf(tzTemp, TEXT("无法找到模块 %s,程序无法正常运行"), tzPath);
		MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
	}

	return (g_OldModule != NULL);

}


FARPROC WINAPI GetAddress(PCSTR pszProcName)
{
	FARPROC fpAddress;
	CHAR szProcName[64];
	TCHAR tzTemp[MAX_PATH];

	fpAddress = GetProcAddress(g_OldModule, pszProcName);
	if (fpAddress == NULL)
	{
		if (HIWORD(pszProcName) == 0)
		{
			wsprintfA(szProcName, "#%d", pszProcName);
			pszProcName = szProcName;
		}

		wsprintf(tzTemp, TEXT("无法找到函数 %hs,程序无法正常运行"), pszProcName);
		MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
		ExitProcess(-2);
	}
	return fpAddress;
}

BOOL WINAPI Init()
{
	pfnAheadLib_Unnamed100 = GetAddress(MAKEINTRESOURCEA(100));
	pfnAheadLib_Unnamed101 = GetAddress(MAKEINTRESOURCEA(101));
	pfnAheadLib_Unnamed102 = GetAddress(MAKEINTRESOURCEA(102));
	pfnAheadLib_Unnamed103 = GetAddress(MAKEINTRESOURCEA(103));
	pfnAheadLib_ADVANCEDSETUPDIALOG = GetAddress("ADVANCEDSETUPDIALOG");
	pfnAheadLib_AdvancedSetupDialog = GetAddress("AdvancedSetupDialog");
	pfnAheadLib_ConvertAnsiDevModeToUnicodeDevmode = GetAddress("ConvertAnsiDevModeToUnicodeDevmode");
	pfnAheadLib_ConvertUnicodeDevModeToAnsiDevmode = GetAddress("ConvertUnicodeDevModeToAnsiDevmode");
	pfnAheadLib_DEVICEMODE = GetAddress("DEVICEMODE");
	pfnAheadLib_DeviceMode = GetAddress("DeviceMode");
	pfnAheadLib_DocumentEvent = GetAddress("DocumentEvent");
	pfnAheadLib_PerfClose = GetAddress("PerfClose");
	pfnAheadLib_PerfCollect = GetAddress("PerfCollect");
	pfnAheadLib_PerfOpen = GetAddress("PerfOpen");
	pfnAheadLib_QueryColorProfile = GetAddress("QueryColorProfile");
	pfnAheadLib_QueryRemoteFonts = GetAddress("QueryRemoteFonts");
	pfnAheadLib_QuerySpoolMode = GetAddress("QuerySpoolMode");
	pfnAheadLib_SpoolerDevQueryPrintW = GetAddress("SpoolerDevQueryPrintW");
	pfnAheadLib_StartDocDlgW = GetAddress("StartDocDlgW");
	pfnAheadLib_AbortPrinter = GetAddress("AbortPrinter");
	pfnAheadLib_AddFormA = GetAddress("AddFormA");
	pfnAheadLib_AddFormW = GetAddress("AddFormW");
	pfnAheadLib_AddJobA = GetAddress("AddJobA");
	pfnAheadLib_AddJobW = GetAddress("AddJobW");
	pfnAheadLib_AddMonitorA = GetAddress("AddMonitorA");
	pfnAheadLib_AddMonitorW = GetAddress("AddMonitorW");
	pfnAheadLib_AddPortA = GetAddress("AddPortA");
	pfnAheadLib_AddPortExA = GetAddress("AddPortExA");
	pfnAheadLib_AddPortExW = GetAddress("AddPortExW");
	pfnAheadLib_AddPortW = GetAddress("AddPortW");
	pfnAheadLib_AddPrintProcessorA = GetAddress("AddPrintProcessorA");
	pfnAheadLib_AddPrintProcessorW = GetAddress("AddPrintProcessorW");
	pfnAheadLib_AddPrintProvidorA = GetAddress("AddPrintProvidorA");
	pfnAheadLib_AddPrintProvidorW = GetAddress("AddPrintProvidorW");
	pfnAheadLib_AddPrinterA = GetAddress("AddPrinterA");
	pfnAheadLib_AddPrinterConnection2A = GetAddress("AddPrinterConnection2A");
	pfnAheadLib_AddPrinterConnection2W = GetAddress("AddPrinterConnection2W");
	pfnAheadLib_AddPrinterConnectionA = GetAddress("AddPrinterConnectionA");
	pfnAheadLib_AddPrinterConnectionW = GetAddress("AddPrinterConnectionW");
	pfnAheadLib_AddPrinterDriverA = GetAddress("AddPrinterDriverA");
	pfnAheadLib_AddPrinterDriverExA = GetAddress("AddPrinterDriverExA");
	pfnAheadLib_AddPrinterDriverExW = GetAddress("AddPrinterDriverExW");
	pfnAheadLib_AddPrinterDriverW = GetAddress("AddPrinterDriverW");
	pfnAheadLib_AddPrinterW = GetAddress("AddPrinterW");
	pfnAheadLib_AdvancedDocumentPropertiesA = GetAddress("AdvancedDocumentPropertiesA");
	pfnAheadLib_AdvancedDocumentPropertiesW = GetAddress("AdvancedDocumentPropertiesW");
	pfnAheadLib_ClosePrinter = GetAddress("ClosePrinter");
	pfnAheadLib_CloseSpoolFileHandle = GetAddress("CloseSpoolFileHandle");
	pfnAheadLib_CommitSpoolData = GetAddress("CommitSpoolData");
	pfnAheadLib_ConfigurePortA = GetAddress("ConfigurePortA");
	pfnAheadLib_ConfigurePortW = GetAddress("ConfigurePortW");
	pfnAheadLib_ConnectToPrinterDlg = GetAddress("ConnectToPrinterDlg");
	pfnAheadLib_CorePrinterDriverInstalledA = GetAddress("CorePrinterDriverInstalledA");
	pfnAheadLib_CorePrinterDriverInstalledW = GetAddress("CorePrinterDriverInstalledW");
	pfnAheadLib_CreatePrintAsyncNotifyChannel = GetAddress("CreatePrintAsyncNotifyChannel");
	pfnAheadLib_CreatePrinterIC = GetAddress("CreatePrinterIC");
	pfnAheadLib_DEVICECAPABILITIES = GetAddress("DEVICECAPABILITIES");
	pfnAheadLib_DeleteFormA = GetAddress("DeleteFormA");
	pfnAheadLib_DeleteFormW = GetAddress("DeleteFormW");
	pfnAheadLib_DeleteMonitorA = GetAddress("DeleteMonitorA");
	pfnAheadLib_DeleteMonitorW = GetAddress("DeleteMonitorW");
	pfnAheadLib_DeletePortA = GetAddress("DeletePortA");
	pfnAheadLib_DeletePortW = GetAddress("DeletePortW");
	pfnAheadLib_DeletePrintProcessorA = GetAddress("DeletePrintProcessorA");
	pfnAheadLib_DeletePrintProcessorW = GetAddress("DeletePrintProcessorW");
	pfnAheadLib_DeletePrintProvidorA = GetAddress("DeletePrintProvidorA");
	pfnAheadLib_DeletePrintProvidorW = GetAddress("DeletePrintProvidorW");
	pfnAheadLib_DeletePrinter = GetAddress("DeletePrinter");
	pfnAheadLib_DeletePrinterConnectionA = GetAddress("DeletePrinterConnectionA");
	pfnAheadLib_DeletePrinterConnectionW = GetAddress("DeletePrinterConnectionW");
	pfnAheadLib_DeletePrinterDataA = GetAddress("DeletePrinterDataA");
	pfnAheadLib_DeletePrinterDataExA = GetAddress("DeletePrinterDataExA");
	pfnAheadLib_DeletePrinterDataExW = GetAddress("DeletePrinterDataExW");
	pfnAheadLib_DeletePrinterDataW = GetAddress("DeletePrinterDataW");
	pfnAheadLib_DeletePrinterDriverA = GetAddress("DeletePrinterDriverA");
	pfnAheadLib_DeletePrinterDriverExA = GetAddress("DeletePrinterDriverExA");
	pfnAheadLib_DeletePrinterDriverExW = GetAddress("DeletePrinterDriverExW");
	pfnAheadLib_DeletePrinterDriverPackageA = GetAddress("DeletePrinterDriverPackageA");
	pfnAheadLib_DeletePrinterDriverPackageW = GetAddress("DeletePrinterDriverPackageW");
	pfnAheadLib_DeletePrinterDriverW = GetAddress("DeletePrinterDriverW");
	pfnAheadLib_DeletePrinterIC = GetAddress("DeletePrinterIC");
	pfnAheadLib_DeletePrinterKeyA = GetAddress("DeletePrinterKeyA");
	pfnAheadLib_DeletePrinterKeyW = GetAddress("DeletePrinterKeyW");
	pfnAheadLib_DevQueryPrint = GetAddress("DevQueryPrint");
	pfnAheadLib_DevQueryPrintEx = GetAddress("DevQueryPrintEx");
	pfnAheadLib_DeviceCapabilities = GetAddress("DeviceCapabilities");
	pfnAheadLib_DeviceCapabilitiesA = GetAddress("DeviceCapabilitiesA");
	pfnAheadLib_DeviceCapabilitiesW = GetAddress("DeviceCapabilitiesW");
	pfnAheadLib_DevicePropertySheets = GetAddress("DevicePropertySheets");
	pfnAheadLib_DocumentPropertiesA = GetAddress("DocumentPropertiesA");
	pfnAheadLib_DocumentPropertiesW = GetAddress("DocumentPropertiesW");
	pfnAheadLib_DocumentPropertySheets = GetAddress("DocumentPropertySheets");
	pfnAheadLib_EXTDEVICEMODE = GetAddress("EXTDEVICEMODE");
	pfnAheadLib_EndDocPrinter = GetAddress("EndDocPrinter");
	pfnAheadLib_EndPagePrinter = GetAddress("EndPagePrinter");
	pfnAheadLib_EnumFormsA = GetAddress("EnumFormsA");
	pfnAheadLib_EnumFormsW = GetAddress("EnumFormsW");
	pfnAheadLib_EnumJobsA = GetAddress("EnumJobsA");
	pfnAheadLib_EnumJobsW = GetAddress("EnumJobsW");
	pfnAheadLib_EnumMonitorsA = GetAddress("EnumMonitorsA");
	pfnAheadLib_EnumMonitorsW = GetAddress("EnumMonitorsW");
	pfnAheadLib_GetDefaultPrinterA = GetAddress("GetDefaultPrinterA");
	pfnAheadLib_SetDefaultPrinterA = GetAddress("SetDefaultPrinterA");
	pfnAheadLib_GetDefaultPrinterW = GetAddress("GetDefaultPrinterW");
	pfnAheadLib_SetDefaultPrinterW = GetAddress("SetDefaultPrinterW");
	pfnAheadLib_Unnamed205 = GetAddress(MAKEINTRESOURCEA(205));
	pfnAheadLib_Unnamed206 = GetAddress(MAKEINTRESOURCEA(206));
	pfnAheadLib_Unnamed207 = GetAddress(MAKEINTRESOURCEA(207));
	pfnAheadLib_Unnamed208 = GetAddress(MAKEINTRESOURCEA(208));
	pfnAheadLib_Unnamed209 = GetAddress(MAKEINTRESOURCEA(209));
	pfnAheadLib_Unnamed210 = GetAddress(MAKEINTRESOURCEA(210));
	pfnAheadLib_Unnamed211 = GetAddress(MAKEINTRESOURCEA(211));
	pfnAheadLib_Unnamed212 = GetAddress(MAKEINTRESOURCEA(212));
	pfnAheadLib_Unnamed213 = GetAddress(MAKEINTRESOURCEA(213));
	pfnAheadLib_Unnamed214 = GetAddress(MAKEINTRESOURCEA(214));
	pfnAheadLib_Unnamed215 = GetAddress(MAKEINTRESOURCEA(215));
	pfnAheadLib_Unnamed216 = GetAddress(MAKEINTRESOURCEA(216));
	pfnAheadLib_Unnamed217 = GetAddress(MAKEINTRESOURCEA(217));
	pfnAheadLib_Unnamed218 = GetAddress(MAKEINTRESOURCEA(218));
	pfnAheadLib_Unnamed219 = GetAddress(MAKEINTRESOURCEA(219));
	pfnAheadLib_Unnamed220 = GetAddress(MAKEINTRESOURCEA(220));
	pfnAheadLib_Unnamed221 = GetAddress(MAKEINTRESOURCEA(221));
	pfnAheadLib_Unnamed222 = GetAddress(MAKEINTRESOURCEA(222));
	pfnAheadLib_Unnamed223 = GetAddress(MAKEINTRESOURCEA(223));
	pfnAheadLib_Unnamed224 = GetAddress(MAKEINTRESOURCEA(224));
	pfnAheadLib_EnumPortsA = GetAddress("EnumPortsA");
	pfnAheadLib_Unnamed226 = GetAddress(MAKEINTRESOURCEA(226));
	pfnAheadLib_Unnamed227 = GetAddress(MAKEINTRESOURCEA(227));
	pfnAheadLib_Unnamed228 = GetAddress(MAKEINTRESOURCEA(228));
	pfnAheadLib_Unnamed229 = GetAddress(MAKEINTRESOURCEA(229));
	pfnAheadLib_Unnamed230 = GetAddress(MAKEINTRESOURCEA(230));
	pfnAheadLib_Unnamed231 = GetAddress(MAKEINTRESOURCEA(231));
	pfnAheadLib_EnumPortsW = GetAddress("EnumPortsW");
	pfnAheadLib_Unnamed233 = GetAddress(MAKEINTRESOURCEA(233));
	pfnAheadLib_Unnamed234 = GetAddress(MAKEINTRESOURCEA(234));
	pfnAheadLib_EnumPrintProcessorDatatypesA = GetAddress("EnumPrintProcessorDatatypesA");
	pfnAheadLib_EnumPrintProcessorDatatypesW = GetAddress("EnumPrintProcessorDatatypesW");
	pfnAheadLib_EnumPrintProcessorsA = GetAddress("EnumPrintProcessorsA");
	pfnAheadLib_EnumPrintProcessorsW = GetAddress("EnumPrintProcessorsW");
	pfnAheadLib_EnumPrinterDataA = GetAddress("EnumPrinterDataA");
	pfnAheadLib_EnumPrinterDataExA = GetAddress("EnumPrinterDataExA");
	pfnAheadLib_EnumPrinterDataExW = GetAddress("EnumPrinterDataExW");
	pfnAheadLib_EnumPrinterDataW = GetAddress("EnumPrinterDataW");
	pfnAheadLib_EnumPrinterDriversA = GetAddress("EnumPrinterDriversA");
	pfnAheadLib_EnumPrinterDriversW = GetAddress("EnumPrinterDriversW");
	pfnAheadLib_EnumPrinterKeyA = GetAddress("EnumPrinterKeyA");
	pfnAheadLib_EnumPrinterKeyW = GetAddress("EnumPrinterKeyW");
	pfnAheadLib_EnumPrintersA = GetAddress("EnumPrintersA");
	pfnAheadLib_EnumPrintersW = GetAddress("EnumPrintersW");
	pfnAheadLib_ExtDeviceMode = GetAddress("ExtDeviceMode");
	pfnAheadLib_Unnamed250 = GetAddress(MAKEINTRESOURCEA(250));
	pfnAheadLib_Unnamed251 = GetAddress(MAKEINTRESOURCEA(251));
	pfnAheadLib_Unnamed252 = GetAddress(MAKEINTRESOURCEA(252));
	pfnAheadLib_Unnamed253 = GetAddress(MAKEINTRESOURCEA(253));
	pfnAheadLib_Unnamed254 = GetAddress(MAKEINTRESOURCEA(254));
	pfnAheadLib_Unnamed255 = GetAddress(MAKEINTRESOURCEA(255));
	pfnAheadLib_Unnamed256 = GetAddress(MAKEINTRESOURCEA(256));
	pfnAheadLib_FindClosePrinterChangeNotification = GetAddress("FindClosePrinterChangeNotification");
	pfnAheadLib_FindFirstPrinterChangeNotification = GetAddress("FindFirstPrinterChangeNotification");
	pfnAheadLib_FindNextPrinterChangeNotification = GetAddress("FindNextPrinterChangeNotification");
	pfnAheadLib_FlushPrinter = GetAddress("FlushPrinter");
	pfnAheadLib_FreePrinterNotifyInfo = GetAddress("FreePrinterNotifyInfo");
	pfnAheadLib_GetCorePrinterDriversA = GetAddress("GetCorePrinterDriversA");
	pfnAheadLib_GetCorePrinterDriversW = GetAddress("GetCorePrinterDriversW");
	pfnAheadLib_GetFormA = GetAddress("GetFormA");
	pfnAheadLib_GetFormW = GetAddress("GetFormW");
	pfnAheadLib_GetJobA = GetAddress("GetJobA");
	pfnAheadLib_GetJobW = GetAddress("GetJobW");
	pfnAheadLib_GetPrintExecutionData = GetAddress("GetPrintExecutionData");
	pfnAheadLib_GetPrintProcessorDirectoryA = GetAddress("GetPrintProcessorDirectoryA");
	pfnAheadLib_GetPrintProcessorDirectoryW = GetAddress("GetPrintProcessorDirectoryW");
	pfnAheadLib_GetPrinterA = GetAddress("GetPrinterA");
	pfnAheadLib_GetPrinterDataA = GetAddress("GetPrinterDataA");
	pfnAheadLib_GetPrinterDataExA = GetAddress("GetPrinterDataExA");
	pfnAheadLib_GetPrinterDataExW = GetAddress("GetPrinterDataExW");
	pfnAheadLib_GetPrinterDataW = GetAddress("GetPrinterDataW");
	pfnAheadLib_GetPrinterDriver2A = GetAddress("GetPrinterDriver2A");
	pfnAheadLib_GetPrinterDriver2W = GetAddress("GetPrinterDriver2W");
	pfnAheadLib_GetPrinterDriverA = GetAddress("GetPrinterDriverA");
	pfnAheadLib_GetPrinterDriverDirectoryA = GetAddress("GetPrinterDriverDirectoryA");
	pfnAheadLib_GetPrinterDriverDirectoryW = GetAddress("GetPrinterDriverDirectoryW");
	pfnAheadLib_GetPrinterDriverPackagePathA = GetAddress("GetPrinterDriverPackagePathA");
	pfnAheadLib_GetPrinterDriverPackagePathW = GetAddress("GetPrinterDriverPackagePathW");
	pfnAheadLib_GetPrinterDriverW = GetAddress("GetPrinterDriverW");
	pfnAheadLib_GetPrinterW = GetAddress("GetPrinterW");
	pfnAheadLib_GetSpoolFileHandle = GetAddress("GetSpoolFileHandle");
	pfnAheadLib_InstallPrinterDriverFromPackageA = GetAddress("InstallPrinterDriverFromPackageA");
	pfnAheadLib_InstallPrinterDriverFromPackageW = GetAddress("InstallPrinterDriverFromPackageW");
	pfnAheadLib_IsValidDevmodeA = GetAddress("IsValidDevmodeA");
	pfnAheadLib_IsValidDevmodeW = GetAddress("IsValidDevmodeW");
	pfnAheadLib_OpenPrinter2A = GetAddress("OpenPrinter2A");
	pfnAheadLib_OpenPrinter2W = GetAddress("OpenPrinter2W");
	pfnAheadLib_OpenPrinterA = GetAddress("OpenPrinterA");
	pfnAheadLib_OpenPrinterW = GetAddress("OpenPrinterW");
	pfnAheadLib_PlayGdiScriptOnPrinterIC = GetAddress("PlayGdiScriptOnPrinterIC");
	pfnAheadLib_PrinterMessageBoxA = GetAddress("PrinterMessageBoxA");
	pfnAheadLib_PrinterMessageBoxW = GetAddress("PrinterMessageBoxW");
	pfnAheadLib_PrinterProperties = GetAddress("PrinterProperties");
	pfnAheadLib_ReadPrinter = GetAddress("ReadPrinter");
	pfnAheadLib_RegisterForPrintAsyncNotifications = GetAddress("RegisterForPrintAsyncNotifications");
	pfnAheadLib_ReportJobProcessingProgress = GetAddress("ReportJobProcessingProgress");
	pfnAheadLib_ResetPrinterA = GetAddress("ResetPrinterA");
	pfnAheadLib_ResetPrinterW = GetAddress("ResetPrinterW");
	pfnAheadLib_ScheduleJob = GetAddress("ScheduleJob");
	pfnAheadLib_SeekPrinter = GetAddress("SeekPrinter");
	pfnAheadLib_SetFormA = GetAddress("SetFormA");
	pfnAheadLib_SetFormW = GetAddress("SetFormW");
	pfnAheadLib_SetJobA = GetAddress("SetJobA");
	pfnAheadLib_SetJobW = GetAddress("SetJobW");
	pfnAheadLib_SetPortA = GetAddress("SetPortA");
	pfnAheadLib_SetPortW = GetAddress("SetPortW");
	pfnAheadLib_SetPrinterA = GetAddress("SetPrinterA");
	pfnAheadLib_SetPrinterDataA = GetAddress("SetPrinterDataA");
	pfnAheadLib_SetPrinterDataExA = GetAddress("SetPrinterDataExA");
	pfnAheadLib_SetPrinterDataExW = GetAddress("SetPrinterDataExW");
	pfnAheadLib_SetPrinterDataW = GetAddress("SetPrinterDataW");
	pfnAheadLib_SetPrinterW = GetAddress("SetPrinterW");
	pfnAheadLib_SplDriverUnloadComplete = GetAddress("SplDriverUnloadComplete");
	pfnAheadLib_SpoolerPrinterEvent = GetAddress("SpoolerPrinterEvent");
	pfnAheadLib_StartDocDlgA = GetAddress("StartDocDlgA");
	pfnAheadLib_StartDocPrinterA = GetAddress("StartDocPrinterA");
	pfnAheadLib_StartDocPrinterW = GetAddress("StartDocPrinterW");
	pfnAheadLib_StartPagePrinter = GetAddress("StartPagePrinter");
	pfnAheadLib_UnRegisterForPrintAsyncNotifications = GetAddress("UnRegisterForPrintAsyncNotifications");
	pfnAheadLib_UploadPrinterDriverPackageA = GetAddress("UploadPrinterDriverPackageA");
	pfnAheadLib_UploadPrinterDriverPackageW = GetAddress("UploadPrinterDriverPackageW");
	pfnAheadLib_WaitForPrinterChange = GetAddress("WaitForPrinterChange");
	pfnAheadLib_WritePrinter = GetAddress("WritePrinter");
	pfnAheadLib_XcvDataW = GetAddress("XcvDataW");
	return TRUE;
}	
