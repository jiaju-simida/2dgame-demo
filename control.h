
#include <easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <graphics.h>
#include<stdio.h>
#include "draw.h"


#pragma comment( lib, "MSIMG32.LIB")
extern int direct;
extern int i, k;
extern int j, l;
extern int a, b;
//���������
int mskick(int x1,int y1,int x2,int y2);
//���̲�������
void key(obj* obj,int v);
//��Ծ����
void jump(obj* obj, int v);
//��ƽ���ƶ�
void rmv(obj* obj, int v);
//��ƽ���ƶ�
void lmv(obj* obj, int v);
int ttdraw(obj* obj, COLORREF color);
//������ͼ
int ttpaint(obj* obj1,obj* player);
//���˶���
void enemymove(obj* obj,int left,int right);
// ͸����ͼ����
// ������
//		dstimg: Ŀ�� IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���
//		x, y:	Ŀ����ͼλ��
//		srcimg: Դ IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���
//		transparentcolor: ͸��ɫ��srcimg �ĸ���ɫ�����Ḵ�Ƶ� dstimg �ϣ��Ӷ�ʵ��͸����ͼ
void transparentimage_charactor(IMAGE* dstimg, obj *obj, IMAGE* srcimg);
//���վ��
void transparentimage_charactorLstand(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//����
void transparentimage_kill(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//��߹���
void transparentimage_Lkill(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//jump
void transparentimage_charactor_jump(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor);
//��ײobj͸����ͼ
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
//�˺��ж�
void hitjudge(obj* obj1, obj* obj2);//��һ�����������
//���˺��ж�
void killjudge(obj* obj1, obj* player,int kill,int directenemy);