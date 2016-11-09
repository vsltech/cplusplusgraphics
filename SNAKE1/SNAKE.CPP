 /*
 A simple type of graphics programme
that draw Snake like picture. 


Programme Name:SNAKE
Programme Code:TE_SNAKE
Programmer:krishx007

WEBSITE:gfxguru.net
E-MAIL: krishx007@yahoo.com

Check Out other programmes at www.gfxguru.net

Software Details
====================
Developed in   : C++
Compiler used : TC++ 3.0
OS            :Window 98,2000,XP  
               Vista,Windows7(only safemode)
			   
Licence   : Freeware, Please give the credit of programming to author.
 */
 
 #include <graphics.h>
 #include <stdlib.h>
 #include <time.h>
 #include <math.h>
 #include <conio.h>
 #include <dos.h>

/*==============================*/


main()
{

int gdriver = DETECT, gmode=0, errorcode;
     initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
 int XO       = 320;
  int YO       = 240;
  float PI     = 3.14159;
  int NUME     = 30;
  int DENOM    = 100;
  int NUMBER   = 9;
  float RAD    = 4.5;
  float DELTHETA = 0.1;
  int SEGS     = 60  ;
  int REDUX    = 3   ;
  int MIN      = 1   ;


while(!kbhit())
  {
 int color=random(16);
 if(color==0){color=1;}
 setcolor(color);
int size=1000;
float theta=100 ;
int x=300;
int y=300;

for(int j=0;j<size;j++)
   {
   int chng=(random(DENOM)<NUME)? -1:1;
   theta = theta+chng*DELTHETA;
   x=x+RAD*sin(theta);
   y=y+RAD*cos(theta);

   lineto (x,y);
   circle(x,y,30);
   delay(2);
   }

delay(10);
cleardevice();
  }
getch();
closegraph();
}



























