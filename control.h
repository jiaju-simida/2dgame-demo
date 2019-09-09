
#include <easyx.h>			// 引用图形库头文件
#include <conio.h>
#include <graphics.h>
#include<stdio.h>
#include "draw.h"


#pragma comment( lib, "MSIMG32.LIB")
extern int direct;
extern int i, k;
extern int j, l;
extern int a, b;
//鼠标点击函数
int mskick(int x1,int y1,int x2,int y2);
//键盘操作函数
void key(obj* obj,int v);
//跳跃操作
void jump(obj* obj, int v);
//右平滑移动
void rmv(obj* obj, int v);
//右平滑移动
void lmv(obj* obj, int v);
int ttdraw(obj* obj, COLORREF color);
//敌人贴图
int ttpaint(obj* obj1,obj* player);
//敌人动作
void enemymove(obj* obj,int left,int right);
// 透明贴图函数
// 参数：
//		dstimg: 目标 IMAGE 对象指针。NULL 表示默认窗体
//		x, y:	目标贴图位置
//		srcimg: 源 IMAGE 对象指针。NULL 表示默认窗体
//		transparentcolor: 透明色。srcimg 的该颜色并不会复制到 dstimg 上，从而实现透明贴图
void transparentimage_charactor(IMAGE* dstimg, obj *obj, IMAGE* srcimg);
//左边站立
void transparentimage_charactorLstand(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//攻击
void transparentimage_kill(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//左边攻击
void transparentimage_Lkill(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//jump
void transparentimage_charactor_jump(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//碰撞obj透明贴图
void transparentimage_collobj(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//enemy
void transparentimage_Renemy(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//enemyRmove
void transparentimage_Renemymove(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//enemyLmove
void transparentimage_Lenemymove(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//Renemykill
void transparentimage_Renemykill(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//Lenemykill
void transparentimage_Lenemykill(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//伤害判定
void hitjudge(obj* obj1, obj* obj2);//第一个参数是玩家
//被伤害判定
void killjudge(obj* obj1, obj* player,int kill,int directenemy);