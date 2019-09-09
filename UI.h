#include <easyx.h>			// 引用图形库头文件
#include <conio.h>
#include <graphics.h>
//背景图片函数
int backgd(int width,int height,const char *path);  
//ui函数
int UI(const char* text,
	RECT r,
	int height,
	int width,
	const char*word,
	COLORREF color);
