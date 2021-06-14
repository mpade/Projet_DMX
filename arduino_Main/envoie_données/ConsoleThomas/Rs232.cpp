#include "Rs232.h"

Rs232::Rs232() {

}

bool Rs232::OpenPort() {
	hcom =  CreateFileA("COM8", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, NULL);
	if (hcom == INVALID_HANDLE_VALUE) {
		return false;
	}
	else 
	{
		GetCommState(hcom, &dcb);
		dcb.BaudRate = CBR_9600;
		dcb.ByteSize = 8;
		dcb.Parity = NOPARITY;
		dcb.StopBits = ONESTOPBIT;

		SetCommState(hcom, &dcb);
		com.ReadIntervalTimeout = MAXDWORD;
		com.ReadTotalTimeoutMultiplier = 0;
		com.ReadTotalTimeoutConstant = 0;
		com.WriteTotalTimeoutMultiplier = 0;
		com.WriteTotalTimeoutConstant = 0;

		SetCommTimeouts(hcom, &com);

		return true;
	}

}
bool Rs232::ReadPort(char *buffer) {
	int n = 0;
	unsigned long d = 0;
	char buffers[1024] = { 0 };
	
	if((n = ReadFile(this->hcom, buffer, 1,&d,NULL)) < 0){
		return false;
	}
	buffer[n] = '\0';
	return true;
} 
bool Rs232::WritePort(char * buffer) {
	unsigned long sendLenght;
	if (!WriteFile(this->hcom, buffer, strlen(buffer), &sendLenght, NULL)) {
		return false;
	}
	return true;
}
void Rs232::ClosePort() {
	CloseHandle(hcom);
}