
#include <easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <graphics.h>


extern int cxy[10000][10000] ;
//��������

typedef struct object {
	bool coll;  //�Ƿ�Ϊ��ײ��
	int x;      //��������
	int y;      //��������
	int width;	//��
	int heght;	//��
	bool hit;//�Ƿ񱻹���
	int HP;//�˺�����
}obj;

//��Ⱦ����
void drawbj(int width, int height, const char* path);
//��ײ��ϵͳ
void coll(obj* obj);
//��ײ��ʼ��
void initcoll(int width, int height);
//����ϵͳ
void objg(obj *obj);
//��Ⱦ����
void drawobj(obj *obj);
//void ttdraw(obj* obj, COLORREF color);
