/*
A simple type of graphics programme. 


Programme Name:BUBBLE
Programme Code:W_CIRCLE
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
   initgraph(&gdriver, &gmode, "");

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

   int r=200, x1=100,y1=50;
   for(float i=0;;i=i+0.01)
     {

       if(kbhit()){nosound();closegraph();break;}
       float b=r*cos(i*4);
	int a1=x1+r+(b)*sin(i);
	int b1=y1+r+(b)*cos(i); //cos(i/2);

  moveto(100+b,50); lineto(100,300);lineto(200+b,50); lineto(200,300); lineto(300+b,50); lineto(300,300);
	circle(360, 200,200-b );
	setcolor (14);        // This becomes drawing color
	circle(a1, b1, 10);    // Draw the circle
		setcolor (14);
		line(0,300,b*3,300);
		line(300,0,300,b*3);
		circle(300, 200,b*2 );circle(300, 200,b/4 );
		circle(400, 300,b/2 );circle(300, 200,b*3 );
		circle(260, 400,100-b );circle(300, 200,b*3 );
		circle(260, 400,200-b );circle(300, 200,100*b );
      sound(b*10);
      delay(10);
      cleardevice();
     }

 }