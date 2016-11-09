/*
A simple type of graphics  
Programme that shows FLOWER like graphics.

Programme Name:FLOWER2 
Programme Code:WAVE1C
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
   int midx, midy;

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
     moveto(200,300);
   float x=0,  y=250,r=100, x1=300,y1=250, set=0;
   for(float i=0;i<1000;i=i+0.002)
     {

       if(kbhit()){exit(0);}
      // float a=x+r*sin(i);
       float b=y+r*cos(i*10);
	      //	putpixel(x,b,15);

	int a1=x1+(b)*sin(i);
	int b1=y1+(b)*cos(i); //cos(i/2);

       set=set+1;if(set==100){set=0; int clr=random(16);setcolor(clr);if(clr==0)setcolor(4);}
	       putpixel(a1,b1,15);

	       line(x1,y1,a1,b1);
	// printf("%f",b);
       //	 cleardevice();
	 x=x+0.5;
      delay(1);
     }
    getch();
 }