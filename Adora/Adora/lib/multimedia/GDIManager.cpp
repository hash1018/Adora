

#include "GDIManager.h"


GDIManager::GDIManager()
	:initialized(false) {

}

GDIManager::~GDIManager() {

}

bool GDIManager::init(unsigned char* *bits, int destWidth, int destHeight) {

	if (this->initialized == true)
		return false;

	ZeroMemory(&this->bitmapInfo, sizeof(BITMAPINFO));
	this->bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	this->bitmapInfo.bmiHeader.biWidth = destWidth;
	this->bitmapInfo.bmiHeader.biHeight = -destHeight;  //this is the line that makes it draw upside down or not
	this->bitmapInfo.bmiHeader.biPlanes = 1;
	this->bitmapInfo.bmiHeader.biBitCount = 32;

	this->desktopHwnd = GetDesktopWindow();
	this->desktopDC = GetDC(this->desktopHwnd);
	this->captureDC = CreateCompatibleDC(this->desktopDC);

	this->captureBitmap = CreateDIBSection(this->captureDC, &this->bitmapInfo, DIB_RGB_COLORS, (void**)bits, NULL, 0);

	this->initialized = true;
	return true;
}

bool GDIManager::capture(int x, int y, int width, int height, bool drawCursor) {

	if (this->initialized == false)
		return false;

	this->desktopDC = GetDC(this->desktopHwnd);
	this->old = SelectObject(this->captureDC, this->captureBitmap);

	BitBlt(this->captureDC, -x, -y,
		width + x, height + y,
		this->desktopDC, 0, 0, SRCCOPY);


	if (drawCursor == true) {

		this->drawCursor(x, y, width, height);

	}

	SelectObject(this->captureDC, this->old);
	ReleaseDC(this->desktopHwnd, this->desktopDC);



	return true;
}

bool GDIManager::close() {

	if (this->initialized == false)
		return false;

	DeleteObject(this->captureBitmap);
	DeleteDC(this->captureDC);
	ReleaseDC(this->desktopHwnd, this->desktopDC);

	this->initialized = false;
	return true;
}

bool GDIManager::drawCursor(int x, int y, int width, int height) {

	CURSORINFO cursor = { sizeof(cursor) };
	if (GetCursorInfo(&cursor) && cursor.flags == CURSOR_SHOWING) {

		RECT rect;
		GetWindowRect(this->desktopHwnd, &rect);
		ICONINFO info = { sizeof(info) };
		GetIconInfo(cursor.hCursor, &info);
		const int cursorX = (cursor.ptScreenPos.x - x - info.xHotspot);
		const int cursorY = (cursor.ptScreenPos.y - y - info.yHotspot);
		BITMAP bmpCursor = { 0 };
		GetObject(info.hbmColor, sizeof(bmpCursor), &bmpCursor);
		DrawIconEx(this->captureDC, cursorX, cursorY, cursor.hCursor, bmpCursor.bmWidth, bmpCursor.bmHeight,
			0, NULL, DI_NORMAL);

		DeleteObject(info.hbmColor);
		DeleteObject(info.hbmMask);
	}

	return true;
}