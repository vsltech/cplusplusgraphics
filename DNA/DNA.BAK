
/*A simple type of graphics programme
shows DNA (Deoxyribonucleic acid )
like graphics .

Programme Name:DNA
Programme Code:W_LINES
Programmer:krishx007

WEBSITE:gfxguru.net
E-MAIL: krishx007@yahoo.com

Check Out my other programes at www.gfxguru.net

Software Details
====================
Developed in   : C++
Compiler used : TC++ 3.0
OS            :Window 98,2000,XP  
               Vista,Windows7(only safemode)
			   
Licence   : Freeware (Please give the credit of programming to author.)
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


int x=400,y=220;
   float r=200;

  for(float i=1;;i=i+0.04)
   {
  setcolor(14);
  if(kbhit())
  exit(0);

  int a=x+r*sin(i); int b=y+r*cos(i);
  int a1=x+r*sin(i*2); int b1=y+r*cos(i);//cos(i/2);
  int a2=x+r*sin(i); int b2=y+r*(cos(i)/2);//cos(i*2);


	setcolor (4);        // This becomes drawing color
	circle(a1, b1, 8);    // Draw the circle
	setfillstyle(6, 4); // Set pattern to fill interior
	floodfill(a1,b1, 4);  // Fill the circle					  // line(300,220,a,b);

	setcolor (4);        // This becomes drawing color
	circle(a2, b2, 8);    // Draw the circle
	setfillstyle(6, 4); // Set pattern to fill interior
	floodfill(a2,b2, 4);  // Fill the circle*/					      // if(i>5){cleardevice();}

   line(a1,b1,a2,b2);  line(a1,b1+1,a2,b2+1);

	setcolor(2);
	int sz=-180;

	setcolor (2);        // This becomes drawing color
	circle(a+sz, b, 8);    // Draw the circle
	setfillstyle(6, 2); // Set pattern to fill interior
	floodfill(a+sz,b, 2);  // Fill the circle */

	circle(a1+sz, b2, 8);    // Draw the circle
	setfillstyle(6, 2); // Set pattern to fill interior
	floodfill(a1+sz,b2, 2);  // Fill the circle */

line(a+sz,b,a1+sz,b2);line(a+sz,b+1,a1+sz,b2+1);  printf("\n"); delay(2);
   }//'for'loop

}//_main

