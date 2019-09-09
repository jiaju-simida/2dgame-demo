
#include <easyx.h>			// 引用图形库头文件
#include <conio.h>
#include <graphics.h>


extern int cxy[10000][10000] ;
//对象属性

typedef struct object {
	bool coll;  //是否为碰撞体
	int x;      //中心坐标
	int y;      //中心坐标
	int width;	//宽
	int heght;	//高
	bool hit;//是否被攻击
	int HP;//伤害计数
}obj;

//渲染背景
void drawbj(int width, int height, const char* path);
//碰撞体系统
void coll(obj* obj);
//碰撞初始化
void initcoll(int width, int height);
//重力系统
void objg(obj *obj);
//渲染对象
void drawobj(obj *obj);
//void ttdraw(obj* obj, COLORREF color);
