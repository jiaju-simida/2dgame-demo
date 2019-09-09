#include "draw.h"



//this
 int cxy[10000][10000];
void drawbj(int width, int height, const char* path)
{
	
	initgraph(width, height);
	loadimage(NULL, _T(path), width, height);
	
}

void coll(obj *obj)
{
	
	for (int i = obj->x - obj->width / 2+1;i < (obj->x + obj->width / 2);i++) {
		for (int k = obj->y - obj->heght / 2+1;k < (obj->y + obj->heght / 2);k++) {
			if (i > 0 && k > 0) {
				cxy[i][k] = 1;
			}
		}
	}
}

void initcoll(int width, int height)
{
	for (int i = 0;i < width;i++) {
		for (int k = 0;k < height;k++) {
			cxy[i][k] = 0;
		}
	}
}

void objg(obj *obj)
{
	if (cxy[obj->x][obj->y + obj->heght / 2 + 10] == 0 && cxy[obj->x + obj->width / 2][obj->y + obj->heght / 2 + 10] == 0 && cxy[obj->x - obj->width / 2][obj->y + obj->heght / 2 + 10] == 0)
		obj->y += 10;
}

void drawobj(obj *obj)
{
	fillrectangle(obj->x - obj->width / 2-5, obj->y - obj->heght / 2-5, obj->x + obj->width / 2, obj->y + obj->heght / 2);
}

