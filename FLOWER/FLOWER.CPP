/*
A simple type of graphics  
Programme that shows FLOWER like graphics.

Programme Name:FLOWER 
Programme Code:WAVE1E
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

   float x=0,  r=100, x1=200,y1=100 , set=0 ;
   for(float i=0;i<1000;i=i+0.003)
     {

       if(kbhit()){exit(0);}
		       // float a=x+r*sin(i);
       float b=+100*cos(i*10);
		      // putpixel(x,b,15);
	int a1=x1+r+(b)*sin(i);
	int b1=y1+r+(b)*cos(i); //cos(i/2);
	 int clr;
	 set=set+1;if(set==4000){set=0;  clr=random(16);}
	       putpixel(a1,b1-100,random(15));
	       putpixel(a1-200,b1-100,(clr+1));
	       putpixel(a1+200,b1-100,(clr+2));

	       putpixel(a1,b1+150,(clr+5));
	       putpixel(a1-200,b1+150,(clr-1));
	       putpixel(a1+200,b1+150,(clr-2));

       // printf("\n"); // printf("%f",b);  cleardevice();

	 x=x+0.5;//r=r+0.401;
      delay(1.5);
     }
    getch();
 }