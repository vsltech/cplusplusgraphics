PROGRAMMERS DETAILS

	Name : Nadar Karlmarx Rajabalan
	Date Of Birth : 04-05-1985
	Qualification : T.E. Computer
	College : A. C. Patil College Of Engg., Kharghar, Navi-mumbai.
	E-Mail Id : karl_balan@yahoo.co.in
		    karl_vli@rediffmail.com
		    karl.prog.vli@gmail.com
*/
#include"graphics.h"
#include"dos.h"
#include"conio.h"
#include"stdlib.h"
#define DELAY 1
#define SOUND 3500
void state(int x,int y,int mode);
int i;
void *ptr1[4],*ptr2[4];
/* 3d Ball */
char ball[20][20]=
{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,12,12,12,12,12,12,12,12,0,0,0,0,0,0},
{0,0,0,0,12,12,12,12,12,12,12,12,12,12,12,12,0,0},
{0,0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0,0,0},
{0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0,0},
{0,0,12,12,12,12,12,15,15,12,12,12,12,12,12,12,12,12,0,0},
{0,12,12,12,12,12,15,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,15,15,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,15,15,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,15,15,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0,0},
{0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0,0},
{0,0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0,0,0},
{0,0,0,0,12,12,12,12,12,12,12,12,12,12,12,12,0,0,0,0},
{0,0,0,0,0,0,12,12,12,12,12,12,12,12,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
/* Condition to check out of range */
int COND(int x,int y)
{
	if (x>10 && x<getmaxx()-10 && y>10 && y<getmaxy()-10)
		return 1;
	else
		return 0;
}
/* This sub-routine will check which path to follow on stiking the wall 
of
the container */
void state(int x,int y,int mode)
{
	while(COND(x,y)&&!kbhit())
	{
		putimage(x,y,ptr1[4],COPY_PUT);
		putimage(getmaxx()-x,getmaxy()-y,ptr1[4],COPY_PUT);
		switch(mode)
		{
			case 0:
				x++;
				y++;
				break;
			case 1:
				x++;
				y--;
				break;
			case 2:
				x--;
				y++;
				break;
			case 3:
				x--;
				y--;
				break;
		}
		delay(DELAY);
		nosound();
		putimage(x,y,ptr2[4],COPY_PUT);
		putimage(getmaxx()-x,getmaxy()-y,ptr2[4],COPY_PUT);
	}
	cleardevice();
	if(x>=(getmaxx()-10)||x<=10)
	{
		sound(SOUND);
		switch(mode)
		{
			case 0:
				state(--x,--y,2);
				break;
			case 1:
				state(--x,++y,3);
				break;
			case 2:
				state(++x,--y,0);
				break;
			case 3:
				state(++x,++y,1);
				break;
		}
	}
	else
	if(y>=getmaxy()-10||y<=10)
	{
		sound(SOUND);
		switch(mode)
		{
			case 0:
				state(--x,--y,1);
				break;
			case 1:
				state(--x,++y,0);
				break;
			case 2:
				state(++x,--y,3);
				break;
			case 3:
				state(++x,++y,2);
				break;
		}
	}
	else
		exit(0);
}
void main()
{
	int gm,gd=DETECT;
	int i,j;
	initgraph(&gd,&gm,"\tc\tc\bgi");
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			if(ball[i][j]!='0')
				putpixel(10+i,10+j,ball[j][i]);
	getimage(10,10,30,30,ptr1[4]);
	cleardevice();
	getimage(10,10,30,30,ptr2[4]);
	/* start with (20,20) */
	state(20,20,0);
	getch();
}