#include <easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <graphics.h>
//����ͼƬ����
int backgd(int width,int height,const char *path);  
//ui����
int UI(const char* text,
	RECT r,
	int height,
	int width,
	const char*word,
	COLORREF color);
