#include"UI.h"
#include"control.h"



//#include"draw.h"

int main(void)
{
	backgd(800, 600, ".\\image\\test.jpg");
	
	UI("BEGIN", {20,20,100,100 },20,15,"ºÚÌå",WHITE);
	int i=mskick(20, 20, 100, 100);
	if (i == 1) {
		closegraph();
		drawbj(800, 600, ".\\image\\test1.jpg");
		initcoll(800, 600);
		obj* bk = (obj*)malloc(sizeof(obj));

		obj *obj1 = (obj*)malloc(sizeof(obj));
		obj *cobj1= (obj*)malloc(sizeof(obj));

		obj* obj2 = (obj*)malloc(sizeof(obj));
		obj* cobj2 = (obj*)malloc(sizeof(obj));

		obj* obj3 = (obj*)malloc(sizeof(obj));
		obj* cobj3 = (obj*)malloc(sizeof(obj));

		obj* obj4 = (obj*)malloc(sizeof(obj));
		obj* cobj4 = (obj*)malloc(sizeof(obj));

		obj* obj5 = (obj*)malloc(sizeof(obj));
		obj* cobj5 = (obj*)malloc(sizeof(obj));

		obj* obje = (obj*)malloc(sizeof(obj));
		obj* cobje = (obj*)malloc(sizeof(obj));
		obj *me=(obj*)malloc(sizeof(obj));
		obj *floor= (obj*)malloc(sizeof(obj));

		floor->x = 800;
		floor->y = 590;
		floor->width = 1600;
		floor->heght = 20;
		//----------------------
		bk->x = 800;
		bk->y = 300;
		bk->width = 1600;
		bk->heght = 600;
		//------------------

		me->x = 50;
		me->y = 300;
		me->width = 50;
		me->heght = 100;
		//-----------------
		obj1->x = 70;
		obj1->y = 555;
		obj1->width = 60;
		obj1->heght = 60;
		cobj1->x = 60;
		cobj1->y = 555;
		cobj1->width = 50;
		cobj1->heght = 50;
		//--------------------
		obj2->x = 200;
		obj2->y = 525;
		obj2->width = 60;
		obj2->heght = 60;
		cobj2->x = 190;
		cobj2->y = 525;
		cobj2->width = 50;
		cobj2->heght = 50;
		//-----------------------
		obj3->x = 430;
		obj3->y = 400;
		obj3->width = 91;
		obj3->heght = 25;
		cobj3->x = 420;
		cobj3->y = 400;
		cobj3->width = 81;
		cobj3->heght = 15;
		//--------------------
		obj4->x = 720;
		obj4->y = 560;
		obj4->width = 256;
		obj4->heght = 30;
		cobj4->x = 710;
		cobj4->y = 570;
		cobj4->width = 256;
		cobj4->heght = 30;
		//------------------
		obj5->x = 1120;
		obj5->y = 460;
		obj5->width = 256;
		obj5->heght = 30;
		cobj5->x = 1110;
		cobj5->y = 460;
		cobj5->width = 256;
		cobj5->heght = 20;
		//-------------------------
		obje->x = 1120;
		obje->y = 360;
		obje->width = 50;
		obje->heght = 100;
		obje->hit = TRUE;
		obje->HP = 0;
		//drawobj(floor);
		//coll(floor);
		
		IMAGE src;
		loadimage(&src, _T(".\\image\\test.png"));
		IMAGE objone;
		loadimage(&objone, _T(".\\image\\obj1.png"));
		
		IMAGE objtwo;
		loadimage(&objtwo, _T(".\\image\\obj1.png"));
		
		IMAGE objthree;
		loadimage(&objthree, _T(".\\image\\obj2.png"));
		
		IMAGE bkg;
		loadimage(&bkg, _T(".\\image\\bk.png"));

		IMAGE objfour;
		loadimage(&objfour, _T(".\\image\\obj4.png"));

	
		while (1) {
			if (me->hit == FALSE) {
				drawbj(800, 600, ".\\image\\end.png");
				while (1) {

				}
			}
			if (obje->HP > 50) {
				drawbj(800, 600, ".\\image\\win.png");
				while (1) {

				}
			}
			BeginBatchDraw();
			
			key(me, 10);
			
			transparentimage_collobj(NULL, bk, &bkg, BLACK);
			//loadimage(NULL, _T(".\\image\\test1.jpg"), 800, 600);
			
			
			initcoll(800, 600);
			transparentimage_collobj(NULL, obj1, &objone, WHITE);
			coll(cobj1);
			transparentimage_collobj(NULL, obj2, &objtwo, WHITE);
			coll(cobj2);
			transparentimage_collobj(NULL, obj3, &objthree, WHITE);
			coll(cobj3);
			transparentimage_collobj(NULL, obj4, &objfour, WHITE);
			coll(cobj4);
			transparentimage_collobj(NULL, obj5, &objfour, WHITE);
			coll(cobj5);
			coll(floor);
		
			
			ttdraw(me,WHITE);	
			objg(me);
			hitjudge(me, obje);
			ttpaint(obje,me);
			objg(obje);
			obje->hit = TRUE;
			if (me->x < 400 && (GetAsyncKeyState(VK_LEFT) & 0x8000)) {
				bk->x += 5;
				me->x += 5;
				obj1->x += 5;
				cobj1->x += 5;
				obj2->x += 5;
				cobj2->x += 5;
				obj3->x += 5;
				cobj3->x += 5;
				obj4->x += 5;
				cobj4->x += 5;
				obj5->x += 5;
				cobj5->x += 5;
				obje->x += 5;
			}
			if (me->x>400 && (GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
				bk->x -= 5;
				me->x -= 5;
				obj1->x -= 5;
				cobj1->x -= 5;
				obj2->x -= 5;
				cobj2->x -= 5;
				obj3->x -= 5;
				cobj3->x -= 5;
				obj4->x -= 5;
				cobj4->x -= 5;
				obj5->x -= 5;
				cobj5->x -= 5;
				if (obje->x - 50 > 0) {
					obje->x -= 5;
				}
			}
			FlushBatchDraw();
			//cleardevice();
			Sleep(15);
			
			EndBatchDraw();
			cleardevice();
		}

		drawbj(800, 600, ".\\image\\end.png");
		while (1) {

		}
		
		
	}
	
	
}