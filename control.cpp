#include "control.h"


int i = 0, k = 0;
int j = 0, l = 0;
int a = 0, b = 0;
//方向
int direct = 0; //0为右 1为左
//enemy跳跃状态
int up = 0;
int mskick(int x1,int y1,int x2,int y2)
{
	while (1)
	{
		MOUSEMSG msg;
		msg = GetMouseMsg();
		if (msg.x > x1 && msg.x<x2 && msg.x>y1 && msg.y < y2)
		{
			switch(msg.uMsg) {
			case WM_LBUTTONDOWN:
				msg = GetMouseMsg();
				if (msg.uMsg == WM_LBUTTONUP)
					return 1;
			
			default:
				break;
			}
		}
	}
	
}

void key(obj* obj,int v)
{
	if ((GetAsyncKeyState(VK_UP) & 0x8000) && (GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
		if (cxy[obj->x][obj->y + obj->heght / 2 + 10] != 0 || cxy[obj->x + obj->width / 2][obj->y + obj->heght / 2 + 10] != 0 || cxy[obj->x - obj->width / 2][obj->y + obj->heght / 2 + 10] != 0)
		{
			l = 1;
			k = 1;
			direct = 0;
		}
	}
	if ((GetAsyncKeyState(VK_UP) & 0x8000) && (GetAsyncKeyState(VK_LEFT) & 0x8000)) {
		if (cxy[obj->x][obj->y + obj->heght / 2 + 10] != 0 || cxy[obj->x + obj->width / 2][obj->y + obj->heght / 2 + 10] != 0 || cxy[obj->x - obj->width / 2][obj->y + obj->heght / 2 + 10] != 0)
		{
			k = 1;
			b = 1;
			direct = 1;
		}
	}
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
		l = 1;
		direct = 0;
	}
	if ((GetAsyncKeyState(VK_LEFT) & 0x8000)) {
		b = 1;
		direct = 1;
	}
	if ((GetAsyncKeyState(VK_UP) & 0x8000)) {
		if (cxy[obj->x][obj->y + obj->heght / 2 + 10] != 0 || cxy[obj->x + obj->width / 2][obj->y + obj->heght / 2 + 10] != 0 || cxy[obj->x - obj->width / 2][obj->y + obj->heght / 2 + 10] != 0)
		k = 1;
	}
	
	rmv(obj, v);
	lmv(obj, v);
	jump(obj, v);
	//rmv(obj, v);
}

void jump(obj* obj, int v)
{
	

	if (k == 1) {
		if (cxy[obj->x][obj->y - obj->heght / 2 - v] == 0 && cxy[obj->x + obj->width / 2][obj->y - obj->heght / 2 - v] == 0 && cxy[obj->x - obj->width / 2][obj->y - obj->heght / 2 - v] == 0)
		{
			
			obj->y -= v * 9/(i+1);
			i++;
			if (i == 20||(cxy[obj->x][obj->y - obj->heght / 2 - v] != 0 || cxy[obj->x + obj->width / 2][obj->y - obj->heght / 2 - v] != 0 || cxy[obj->x - obj->width / 2][obj->y - obj->heght / 2 - v] != 0)) {
				i = 0;
				k = 0;
				}
			
		}
	}
}

void rmv(obj* obj, int v)
{
	if (l == 1) {
		if (cxy[obj->x + obj->width / 2 + v][obj->y] == 0 && cxy[obj->x + obj->width / 2 + v][obj->y - obj->heght / 2] == 0 && cxy[obj->x + obj->width / 2 + v][obj->y + obj->heght / 2] == 0)
		{
			obj->x += v/2; 
			j++;
			if (j == 3) {
				j = 0;
				l = 0;
			}
		}
	}
}

void lmv(obj* obj, int v)
{
	if (b == 1) {
		if (cxy[obj->x - obj->width / 2 - v][obj->y] == 0 && cxy[obj->x - obj->width / 2 - v][obj->y - obj->heght / 2] == 0 && cxy[obj->x - obj->width / 2 - v][obj->y + obj->heght / 2] == 0)
		{
			obj->x -= v/2;
			a++;
			if (a == 3) {
				a = 0;
				b = 0;
			}
		}
	}
}




int ttdraw(obj* obj, COLORREF color)
{
	static int g = 0;
	
	setlinecolor(color);
	setlinestyle(10);

	IMAGE me1;loadimage(&me1, _T(".\\image\\me1.png"));
	IMAGE me2;loadimage(&me2, _T(".\\image\\me2.png"));
	IMAGE me3;loadimage(&me3, _T(".\\image\\me3.png"));
	IMAGE me4;loadimage(&me4, _T(".\\image\\me4.png"));
	IMAGE me5;loadimage(&me5, _T(".\\image\\me5.png"));
	IMAGE me6;loadimage(&me6, _T(".\\image\\me6.png"));
	IMAGE me7;loadimage(&me7, _T(".\\image\\me7.png"));
	IMAGE Lme1;loadimage(&Lme1, _T(".\\image\\Lme1.png"));
	IMAGE Lme2;loadimage(&Lme2, _T(".\\image\\Lme2.png"));
	IMAGE Lme3;loadimage(&Lme3, _T(".\\image\\Lme3.png"));
	IMAGE Lme4;loadimage(&Lme4, _T(".\\image\\Lme4.png"));
	IMAGE Lme5;loadimage(&Lme5, _T(".\\image\\Lme5.png"));
	IMAGE Lme6;loadimage(&Lme6, _T(".\\image\\Lme6.png"));
	IMAGE Lme7;loadimage(&Lme7, _T(".\\image\\Lme7.png"));
	IMAGE jump;loadimage(&jump, _T(".\\image\\jump.png"));
	IMAGE Ljump;loadimage(&Ljump, _T(".\\image\\Ljump.png"));
	IMAGE kill1;loadimage(&kill1, _T(".\\image\\kill1.png"));
	IMAGE Lkill1;loadimage(&Lkill1, _T(".\\image\\Lkill1.png"));
	IMAGE kill2;loadimage(&kill2, _T(".\\image\\kill2.png"));
	IMAGE Lkill2;loadimage(&Lkill2, _T(".\\image\\Lkill2.png"));
	
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		static int kill = 0;
		kill++;

		if (direct == 0) {
			if (kill > 0 && kill < 2) {
				transparentimage_kill(NULL, obj, &kill1, WHITE);
			}
			if (kill >= 2 && kill < 4) {
				transparentimage_kill(NULL, obj, &kill2, WHITE);
			}
			if (kill == 4) {
				transparentimage_kill(NULL, obj, &kill2, WHITE);
				kill = 0;
			}

		}
		else {
			if (kill > 0 && kill < 2) {
				transparentimage_Lkill(NULL, obj, &Lkill1, WHITE);
			}
			if (kill >= 2 && kill < 4) {
				transparentimage_Lkill(NULL, obj, &Lkill2, WHITE);
			}
			if (kill == 4) {
				transparentimage_Lkill(NULL, obj, &Lkill2, WHITE);
				kill = 0;
			}

		}
		return 0;
	}
	if (k == 1) {
		if ((GetAsyncKeyState(VK_LEFT) & 0x8000)) {
			transparentimage_charactor_jump(NULL, obj, &Ljump, WHITE);
			
		}
		else {
			transparentimage_charactor_jump(NULL, obj, &jump, WHITE);
		}
		
		return 0;

	}
	if (((GetAsyncKeyState(VK_RIGHT) & 0x8000) ) && k == 0) {
		g++;
		
	
			if (g > 0 && g < 3) {
				
				transparentimage_charactor(NULL, obj, &me1);
				
			}
			if (g >= 3 && g < 6) {
			
				transparentimage_charactor(NULL, obj, &me2);
				
			}
			if (g >= 6 && g < 9) {
				
				transparentimage_charactor(NULL, obj, &me3);
			}
			if(g>=9&&g<12)
				transparentimage_charactor(NULL, obj, &me4);
			if (g >= 12 && g < 15) {
				transparentimage_charactor(NULL, obj, &me5);
			}
			if (g >= 15 && g < 18) {
				transparentimage_charactor(NULL, obj, &me6);
			}
			if (g >= 18 && g < 21) {
				transparentimage_charactor(NULL, obj, &me7);
			}
			if (g == 21) { 
				transparentimage_charactor(NULL, obj, &me7);
				g = 0; 
			}
		return 0;
	}
	if (((GetAsyncKeyState(VK_LEFT) & 0x8000)) && k == 0) {
		g++;
		
	
			if (g > 0 && g < 3) {
				transparentimage_charactor(NULL, obj, &Lme1);
				
			}
		
	
			if (g >= 3 && g < 6) {
				transparentimage_charactor(NULL, obj, &Lme2);
				
			}
			if (g >= 6 && g < 9) {
				transparentimage_charactor(NULL, obj, &Lme3);
			}
			if (g >= 9 && g< 12) {
				transparentimage_charactor(NULL, obj, &Lme4);
			}
			if (g >= 12 && g < 15) {
				transparentimage_charactor(NULL, obj, &Lme5);
			}
			if (g >= 15 && g < 18) {
				transparentimage_charactor(NULL, obj, &Lme6);
			}
			if (g >= 18 && g < 21) {
				transparentimage_charactor(NULL, obj, &Lme7);
			}
			if (g == 21) {
				transparentimage_charactor(NULL, obj, &Lme7);
				g = 0;
			}
				
		return 0;
	}


	IMAGE img;
	loadimage(&img, _T(".\\image\\me.png"));
	IMAGE Limg;
	loadimage(&Limg, _T(".\\image\\Lme.png"));
	if (direct == 0) {
		transparentimage_charactor(NULL, obj, &img);
	}
	else {
		transparentimage_charactorLstand(NULL, obj, &Limg, WHITE);
	}
	g = 0;
	return 0;

}

int ttpaint(obj* obj1,obj* player)
{
	int directenemy = 0;
	int left = 0, right = 0, kill = 0;
	
	static int m = 0;//每一帧
	IMAGE Renemy;loadimage(&Renemy, _T(".\\image\\Renemy.png"));
	IMAGE Renemy1;loadimage(&Renemy1, _T(".\\image\\Renemy1.png"));
	IMAGE Renemy2;loadimage(&Renemy2, _T(".\\image\\Renemy2.png"));
	IMAGE Renemy3;loadimage(&Renemy3, _T(".\\image\\Renemy3.png"));
	IMAGE Renemy4;loadimage(&Renemy4, _T(".\\image\\Renemy4.png"));
	IMAGE Renemy5;loadimage(&Renemy5, _T(".\\image\\Renemy5.png"));
	IMAGE Renemyhit;loadimage(&Renemyhit, _T(".\\image\\Renemyhit.png"));
	IMAGE Renemykill;loadimage(&Renemykill, _T(".\\image\\Renemykill.png"));
	IMAGE Lenemy;loadimage(&Lenemy, _T(".\\image\\Lenemy.png"));
	IMAGE Lenemy1;loadimage(&Lenemy1, _T(".\\image\\Lenemy1.png"));
	IMAGE Lenemy2;loadimage(&Lenemy2, _T(".\\image\\Lenemy2.png"));
	IMAGE Lenemy3;loadimage(&Lenemy3, _T(".\\image\\Lenemy3.png"));
	IMAGE Lenemy4;loadimage(&Lenemy4, _T(".\\image\\Lenemy4.png"));
	IMAGE Lenemy5;loadimage(&Lenemy5, _T(".\\image\\Lenemy5.png"));
	IMAGE Lenemyhit;loadimage(&Lenemyhit, _T(".\\image\\Lenemyhit.png"));
	IMAGE Lenemykill;loadimage(&Lenemykill, _T(".\\image\\Lenemykill.png"));
	
	
	if (player->x > obj1->x) {
		directenemy = 0;
	}
	else {
		directenemy = 1;
	}

	if (directenemy == 0) {
		if (obj1->hit == TRUE) {
			//transparentimage_Renemy(NULL, obj1, &Renemy, WHITE);
		}
		else {
			transparentimage_Renemy(NULL, obj1, &Renemyhit, WHITE);
			obj1->HP++;
			return 0;
		}
		right = 1;
		if (player->x - player->width / 2 > obj1->x + obj1->width / 2 && player->x - player->width / 2 < obj1->x + obj1->width / 2 + 55) {
			
			kill = 1;
			transparentimage_Renemykill(NULL, obj1, &Renemykill, WHITE);
			killjudge(obj1, player, kill, directenemy);
			return 0;
		}
		if (right == 1) {
			m++;
			if (m > 0 && m < 4) {
				transparentimage_Renemymove(NULL, obj1, &Renemy1, WHITE);
			}
			if (m >= 4 && m < 8) {
				transparentimage_Renemymove(NULL, obj1, &Renemy2, WHITE);
			}
			if (m >= 8 && m < 12) {
				transparentimage_Renemymove(NULL, obj1, &Renemy3, WHITE);
			}
			if (m >= 12 && m < 16) {
				transparentimage_Renemymove(NULL, obj1, &Renemy4, WHITE);
			}
			if (m >= 16 && m < 20) {
				transparentimage_Renemymove(NULL, obj1, &Renemy5, WHITE);
			}
			if (m == 20) {
				transparentimage_Renemymove(NULL, obj1, &Renemy5, WHITE);
				m = 0;
			}
		}
	}
	else {
		if (obj1->hit == TRUE) {
			//transparentimage_Renemy(NULL, obj1, &Lenemy, WHITE);
		}
		else {
			transparentimage_Renemy(NULL, obj1, &Lenemyhit, WHITE);
			obj1->HP++;
			return 0;
		}
		left = 1;
		if (player->x + player->width / 2 > obj1->x - obj1->width / 2-55 && player->x + player->width / 2 < obj1->x + obj1->width / 2 + 60) {
			kill = 1;
			transparentimage_Lenemykill(NULL, obj1, &Lenemykill, WHITE);
			killjudge(obj1, player, kill, directenemy);
			return 0;
		}
		if (left == 1) {
			m++;
			if (m > 0 && m < 4) {
				transparentimage_Lenemymove(NULL, obj1, &Lenemy1, WHITE);
			}
			if (m >= 4 && m < 8) {
				transparentimage_Lenemymove(NULL, obj1, &Lenemy2, WHITE);
			}
			if (m >= 8 && m < 12) {
				transparentimage_Lenemymove(NULL, obj1, &Lenemy3, WHITE);
			}
			if (m >= 12 && m < 16) {
				transparentimage_Lenemymove(NULL, obj1, &Lenemy4, WHITE);
			}
			if (m >= 16 && m < 20) {
				transparentimage_Lenemymove(NULL, obj1, &Lenemy5, WHITE);
			}
			if (m == 20) {
				transparentimage_Lenemymove(NULL, obj1, &Lenemy5, WHITE);
				m = 0;
			}
		}
	}
	enemymove(obj1,  left, right);
}

void enemymove(obj* obj,  int left, int right)
{
	static int z = 0;
	if (up == 1) {
		if (cxy[obj->x][obj->y - obj->heght / 2 - 10] == 0 && cxy[obj->x + obj->width / 2][obj->y - obj->heght / 2 - 10] == 0 && cxy[obj->x - obj->width / 2][obj->y - obj->heght / 2 - 10] == 0) {
			obj->y -= 20;
			z++;
			if (z == 20 || (cxy[obj->x][obj->y - obj->heght / 2 - 10] != 0 || cxy[obj->x + obj->width / 2][obj->y - obj->heght / 2 - 10] != 0 || cxy[obj->x - obj->width / 2][obj->y - obj->heght / 2 - 10] != 0)) {
				z = 0;
				up = 0;
			}
		}
	}
	if (left == 1) {
		if (cxy[obj->x - obj->width / 2 - 5][obj->y] == 0 && cxy[obj->x - obj->width / 2 - 5][obj->y - obj->heght / 2] == 0 && cxy[obj->x - obj->width / 2 - 5][obj->y + obj->heght / 2] == 0) {
			obj->x -= 2;
		}
		else {
			if (cxy[obj->x][obj->y + obj->heght / 2 + 10] != 0 || cxy[obj->x + obj->width / 2][obj->y + obj->heght / 2 + 10] != 0 || cxy[obj->x - obj->width / 2][obj->y + obj->heght / 2 + 10] != 0)
			up = 1;
		}
		

	}
	if (right == 1) {
		if (cxy[obj->x + obj->width / 2 + 5][obj->y] == 0 && cxy[obj->x + obj->width / 2 + 5][obj->y - obj->heght / 2] == 0 && cxy[obj->x + obj->width / 2 + 5][obj->y + obj->heght / 2] == 0) {
			obj->x += 2;
		}
		else {
			if (cxy[obj->x][obj->y + obj->heght / 2 + 10] != 0 || cxy[obj->x + obj->width / 2][obj->y + obj->heght / 2 + 10] != 0 || cxy[obj->x - obj->width / 2][obj->y + obj->heght / 2 + 10] != 0)
			up = 1;
		}
		
	}
	
}

void transparentimage_charactor(IMAGE* dstimg, obj *obj, IMAGE* srcimg)
{
	// 变量初始化
	int x = obj->x - obj->width *2;
	int y = obj->y - obj->heght / 2;
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

void transparentimage_charactorLstand(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor)
{
// 变量初始化
	int x = obj->x - obj->width /2;
	int y = obj->y - obj->heght / 2;
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

void transparentimage_kill(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor)
{
	// 变量初始化
	int x = obj->x - obj->width / 2-50;
	int y = obj->y - obj->heght / 2;
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

void transparentimage_Lkill(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor)
{
	// 变量初始化
	int x = obj->x - obj->width / 2 - 140;
	int y = obj->y - obj->heght / 2;
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

void transparentimage_charactor_jump(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor)
{
	// 变量初始化
	int x = obj->x - obj->width / 2 ;
	int y = obj->y - obj->heght / 2-obj->heght;
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

void transparentimage_collobj(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();

	// 使用 Windows GDI 函数实现透明位图
	TransparentBlt(dstDC, obj->x - obj->width /2, obj->y - obj->heght / 2, w, h, srcDC, 0, 0, w, h, transparentcolor);
}

void transparentimage_Renemy(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor)
{
	// 变量初始化
	int x = obj->x - obj->width / 2-20;
	int y = obj->y - obj->heght / 2-10;
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

void transparentimage_Renemymove(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor)
{
	// 变量初始化
	int x = obj->x - obj->width / 2-53;
	int y = obj->y - obj->heght / 2-10;
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

void transparentimage_Lenemymove(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor)
{

	// 变量初始化
	int x = obj->x - obj->width / 2;
	int y = obj->y - obj->heght / 2-10;
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

void transparentimage_Renemykill(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor)
{
	// 变量初始化
	int x = obj->x - obj->width / 2-60;
	int y = obj->y - obj->heght / 2-10;
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

void transparentimage_Lenemykill(IMAGE* dstimg, obj* obj, IMAGE* srcimg, UINT transparentcolor)
{
	// 变量初始化
	int x = obj->x - obj->width / 2-95;
	int y = obj->y - obj->heght / 2-10;
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

void hitjudge(obj* obj1, obj* obj2)
{
	if ((GetAsyncKeyState(VK_SPACE) & 0x8000 && (obj1->x + obj1->width / 2 + 115 > obj2->x - obj2->width / 2) &&
		(obj1->x + obj1->width / 2 < obj2->x - obj2->width / 2) && (obj1->y > obj2->y - obj2->heght / 2 && obj1->y < obj2->y + obj2->heght / 2) && direct == 0) ||
		(GetAsyncKeyState(VK_SPACE) & 0x8000 && (obj1->x - obj1->width / 2 - 115 < obj2->x + obj2->width / 2) &&
		(obj1->x - obj1->width / 2 > obj2->x + obj2->width / 2) && (obj1->y > obj2->y - obj2->heght / 2 && obj1->y < obj2->y + obj2->heght / 2) && direct == 1)) {
		obj2->hit = FALSE;
	}
}

void killjudge(obj* obj1, obj* player,int kill,int directenemy)
{
	if ((kill==1 && (obj1->x + obj1->width / 2 + 58 > player->x - player->width / 2) &&
		(obj1->x + obj1->width / 2 < player->x - player->width / 2) && (obj1->y > player->y - player->heght / 2 && obj1->y < player->y + player->heght / 2) && directenemy == 0) ||
		(kill==1 && (obj1->x - obj1->width / 2 - 58 < player->x + player->width / 2) &&
		(obj1->x - obj1->width / 2 > player->x + player->width / 2) && (obj1->y > player->y - player->heght / 2 && obj1->y < player->y + player->heght / 2) && directenemy == 1)) {
		player->hit = FALSE;
	}
	
}
