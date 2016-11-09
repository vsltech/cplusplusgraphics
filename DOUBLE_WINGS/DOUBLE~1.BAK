/*
A graphics programme
that shows a cool wings like graphics.

Programme Name:DOUBLE_WINGS
Programme Code:WING_1A
Programmer:krishx007

WEBSITE:www.gfxguru.net
E-MAIL: krishx007@yahoo.com

Check Out other graphics programmes at www.gfxguru.net

Software Details
====================
Developed in   : C++
Compiler used : TC++ 3.0
OS            :Window 98,2000,XP  
               Vista,Windows7(only safemode)
			   
Licence   : Freeware, Please give the credit of programming to author
*/


#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics and local
      variables */
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error  code */
    }

 int x=180,y=320,r=110;
for(float i=0;;i=i+0.15)
  {
 setcolor(14);
 if(kbhit()) exit(0);
 float cc=200*cos(i*4);

int a=x+r*cos(i);
int b=y+r*(sin(i));   line(x,y,a,b);line(x+1,y+1,a+1,b+1);

setcolor(4);circle(a,b,25); setcolor(2);circle(a,b,20);
setcolor(1);circle(a,b,15);setcolor(13);circle(a,b,10);
setcolor(15);circle(a,b,5);/**/setcolor(2);circle(a,b,2);


int x1=420,y1=320,r1=110;float vv=1.6;
int a1=x1+r1*sin(i-vv);
int b1=y1+r1*(cos(i-vv));   line(x1,y1,a1,b1);line(x1+1,y1+1,a1+1,b1+1);

setcolor(4);circle(a1,b1,25); setcolor(2);circle(a1,b1,20);
setcolor(1);circle(a1,b1,15);setcolor(13);circle(a1,b1,10);
setcolor(15);circle(a1,b1,5);/**/setcolor(2);circle(a1,b1,2);
delay(10); printf("\n");

//cleardevice();
    }
}