/*
A simple type of graphics 
Programme shows flag or cloth like graphics.

Programme Name:FLAG
Programme Code:TENDRIL7
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
 #include <math.h>
 #include <conio.h>
 #include <dos.h>

/*==============================*/
void display(int size,float theta ,int x,int y)
{

  int NUME     = 30;
  int DENOM    = 100;

  float RAD    = 4.5;
  float DELTHETA = 0.1;


for(int j=0;j<size;j++)
   {
   if(kbhit()){break;}
   int chng=(random(DENOM)<NUME)? -1:1;
   theta = theta+chng*DELTHETA;
   x=x+RAD*sin(theta);
   y=y+RAD*cos(theta);

   moveto(300,200);
   lineto (x,y);
   putpixel(x-1,y,15);
   putpixel(x,y,15);
   circle(x,y,3);
   delay(3);
  }

}


main()
{//----------------------------------------------
 /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics and local
      variables */
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

while(1)
  {
 if(kbhit()){ char A=getch(); if(A=='s'||A=='S'){getch();} else closegraph(); break; }
 int color=random(16);
 if(color==0){color=1;}
 setcolor(color);

 randomize();
 display(1000,100 ,450,400);
 delay(1000);
cleardevice();
  }
closegraph();
return 0;
}//--------------------------------



























