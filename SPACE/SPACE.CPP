/*
A simple type of graphics 
Programme shows space like graphics.

Programme Name:SPACE
Programme Code:W_LINE2
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
// vp(int x,int tc,int bk,char *text);

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



int x=300,y=300;
moveto(x,y);
   float r=170;
  {
  for(float i=1;;i=i+0.05)

    {
  setcolor(random(15));
 int MaxX=getmaxx();  int MaxY=getmaxy();
for (int zi=0 ;zi<10;++zi)
{
circle(random(MaxX), random(MaxY),1 );
putpixel(random(MaxX), random(MaxY),random(15) );
}
setcolor((12));  if(kbhit())  exit(0);
int b=y+r*cos(i);int a1=x+r*sin(i*2);int b2=y+r*(cos(i)/8);line(a1,b,a1,b2);
  printf("\n");
  delay(10);
   }
 }
}//_main

