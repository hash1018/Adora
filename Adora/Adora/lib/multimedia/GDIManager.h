

#ifndef _GDIMANAGER_H
#define _GDIMANAGER_H

#include <Windows.h>

class GDIManager {

private:
	HWND desktopHwnd;
	HDC desktopDC;
	HDC captureDC;
	HBITMAP captureBitmap;
	HGDIOBJ old;


	BITMAPINFO bitmapInfo;

	bool initialized;

public:
	GDIManager();
	~GDIManager();

	bool init(unsigned char* *bits, int destWidth, int destHeight);
	bool capture(int x, int y, int width, int height, bool drawCursor = false);
	bool close();

private:
	bool drawCursor(int x, int y, int width, int height);
};



#endif //_GDIMANAGER_H
