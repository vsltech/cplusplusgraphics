/*
A simple type of graphics programme
shows WAVE formation using cos()
math function.

Programme Name:WAVE
Programme Code:WAVE1A
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

void main(void)
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

/////////////
  setcolor(13);
  settextstyle(2,0,4);
  outtextxy(200,0,"(======= WAVE PRESENTATION ========)        PROGRAMED BY KRISHNA KUMAR(C).");setcolor(14);
  outtextxy(10,13,"PRESS 1,2,3,4,5,6 AND 7 FOR CHANGING WAVE.     PRESS S FOR STOP    PRESS X FOR EXIT.");
  setcolor(2);  rectangle(7,25,getmaxx()-7,getmaxy()-7);
  setviewport(8,26,getmaxx()-8,getmaxy()-8,3);
//////////////

float qn= 0.1;
while(1)
{
float x=0,  y=250,r=50;
   for(float i=0;;i=i+qn)
     {
  setcolor(6);
  settextstyle(2,0,5);
  outtextxy(20,50,"SORT WAVE_________________________________________.");
  outtextxy(20,210,"LONG WAVE________________________________________.");
  outtextxy(20,360,"DUAL WAVE________________________________________.");
  outtextxy(20,430,"LINE_____________________________________________.");
if(kbhit())
{char a=getch();if(a=='1')qn=0.2;if(a=='2')qn=0.1;if(a=='3')qn=0.07; if(a=='4')qn=0.05;
if(a=='5')qn=0.03;if(a=='6')qn=0.02;  if(a=='7')qn=0.009;
if(a=='x'||a=='X')exit(0);if(a=='s'||a=='S')getch();}

       float b=y+r*cos(i); //cos(i/2);
       float bb=b/5;  //moveto(350,0);lineto(x,b);

putpixel(x,bb-20,12);/*upper wave*/putpixel(x,b-100,11);/* second wave*/
putpixel(x,bb+250,15);/*middle wave*/putpixel(x,b+50,15);//middle wave
putpixel(x,420,14);//line

  if(x>680){delay(500);clearviewport();break;} 	 x=x+1;  delay(2);
     }//for"for"loop
}//for while

 }