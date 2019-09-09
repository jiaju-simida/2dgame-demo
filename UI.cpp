#include"UI.h"
//这是一个界面UI调用函数

int backgd(int width, int height,const char *path)
{
	initgraph(width, height );
	loadimage(NULL, _T(path),width,height);
	return 0;
}

int UI(const char* text, RECT r,int height,int width,const char*word, COLORREF color)
{
	settextstyle(height, width,_T(word));
	settextcolor(color);
	setbkmode(TRANSPARENT);
	drawtext(_T(text), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	return 0;
}
