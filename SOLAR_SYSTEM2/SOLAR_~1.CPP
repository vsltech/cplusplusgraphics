/*
A simple type of graphics programme
that draw SOLAR SYSTEM.

Programme Name:SOLAR_SYSTEM2
Programme Code:WEB_PLA4
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

 int main_x=320,main_y=240,r=50,rp=250;
int x1=180,y1=320,r1=70;float vv=3.15;
for(float i=0,ip=1;;i=i+0.15,ip=ip+0.02)
  {
 setcolor(14);
 if(kbhit()) exit(0);
 float cc=200*cos(i*4);

 int x=main_x+rp*sin(ip);
 int y=main_y+rp*(cos(ip)/2); //cos(i*2);

	setcolor (9);        // This becomes drawing color
	circle(x, y, 15);    // Draw the circle
	setfillstyle(6, 9); // Set pattern to fill interior
	floodfill(x,y, 9);  // Fill the circle					      // if(i>5){cleardevice();}

		setcolor (15);
		     setaspectratio(1,2);

		circle(300,220, 200);    // Draw the circle
		     setaspectratio(1,1);
 int x1=x;int y1=y;

	setcolor (15);        // This becomes drawing color
	circle(300,220, 35);    // Draw the circle
	setfillstyle(9, 15); // Set pattern to fill interior
	floodfill(300,220, 15);  // Fill the circle
	setcolor (11 );

int a=x+r*sin(i);
int b=y+r*(cos(i));  // line(x,y,a,b);line(x+1,y+1,a+1,b+1);



	setcolor (2);        // This becomes drawing color
	circle(a, b, 9);    // Draw the circle
	setfillstyle(6, 2); // Set pattern to fill interior
	floodfill(a,b, 2);  // Fill the circle


delay(20);// printf("\n");

cleardevice();
    }
}
