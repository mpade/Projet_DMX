#pragma once
#include <windows.h>
class Rs232
{
	HANDLE hcom;
	DCB dcb;
	COMMTIMEOUTS com;
public:
	Rs232();
	bool OpenPort();
	bool ReadPort(char *);
	bool WritePort(char *);
	void ClosePort();
};

