﻿#ifndef __COMMON_FUNCTION__
#define __COMMON_FUNCTION__

#define GET_BIT(X,Y) (((X) >> (Y-1)) & 1)
#define SET_BIT(X,Y) ((X) |= (1 << (Y-1)))
#define CLR_BIT(X,Y) ((X) &= (~(1<<Y-1)))

namespace CommonFunc
{
INT32           GetProcessorNum();

std::string     GetCurrentWorkDir();

BOOL            SetCurrentWorkDir(std::string strPath);

std::string     GetCurrentExeDir();

BOOL            CreateDir(std::string& strDir);

BOOL            GetDirFiles(const char* pszDir, char* pszFileType, std::vector<std::string>& vtFileList, BOOL bRecursion);

BOOL            GetSubDirNames(const char* pszDir, const char* pszBegin, std::vector<std::string>& vtDirList, BOOL bRecursion);

BOOL            IsSameDay(UINT64 uTime);

BOOL            IsSameWeek(UINT64 uTime);

BOOL            IsSameMonth(UINT64 uTime);

INT32           DiffWeeks(UINT64 uTimeSrc, UINT64 uTimeDest);

INT32           DiffDays(UINT64 uTimeSrc, UINT64 uTimeDest);

UINT64          GetCurrTime(); //获取当前的秒数

UINT64          GetCurMsTime(); //获取当前的毫秒数

tm              GetCurrTmTime();

UINT64          GetDayBeginTime(UINT64 uTime = 0); //获取当天起点的秒数

UINT64          GetWeekBeginTime(UINT64 uTime = 0); //获取当周起点的秒数

UINT64          GetMonthBeginTime(UINT64 uTime = 0);//获取当月起点的秒数

UINT64          GetMonthRemainTime(UINT64 uTime = 0);   //获取当月剩余的秒数

time_t          YearTimeToSec(INT32 nYear, INT32 nMonth, INT32 nDay, INT32 nHour, INT32 nMin, INT32 nSec);

std::string     TimeToString(time_t tTime);

time_t          DateStringToTime(std::string strDate);

UINT64          GetTickCount();

INT32           GetCurThreadID();

INT32           GetCurProcessID();

VOID            Sleep(INT32 nMilliseconds);

INT32           GetFreePhysMemory();

INT32           GetRandNum(INT32 nType);

INT32           GetLastError();

std::string     GetLastErrorStr(INT32 nError);

// HANDLE       CreateShareMemory(std::string strName, INT32 nSize);
//
// HANDLE       OpenShareMemory(std::string strName);

HANDLE          CreateShareMemory(INT32 nModuleID, INT32 nPage, INT32 nSize);

HANDLE          OpenShareMemory(INT32 nModuleID, INT32 nPage);

CHAR*           GetShareMemory(HANDLE hShm);

BOOL            ReleaseShareMemory(CHAR* pMem);

BOOL            CloseShareMemory(HANDLE hShm);

BOOL            KillProcess(INT32 nPid);

BOOL            IsProcessExist(INT32 nPid);

INT32           GetProcessID(const char* pszProcName);

BOOL            StartProcess(const char* pszProcName, const char* pszCommandLine = NULL, const char*  pszWorkPath = NULL);

BOOL            IsAlreadyRun(std::string strSignName);

BOOL            PrintColorText(CHAR* pSzText, INT32 nColor);

BOOL            GetBitValue(UINT64 nValue, INT32 nPos);

BOOL            SetBitValue(UINT64& nValue, INT32 nPos, BOOL bValue);
}


#endif /* __COMMON_FUNCTION__*/
