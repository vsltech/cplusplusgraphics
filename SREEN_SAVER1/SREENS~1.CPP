/*
A simple type of graphics programme
shows Screen Saver
like graphics .

Programme Name:Screen Saver1
Programme Code:RECT_3A
Programmer:krishx007

WEBSITE:-gfxguru.net
E-MAIL:-krishx007@yahoo.com

Check Out other programmes at www.gfxguru.net

Software Details
====================
Developed in   : C++
Compiler used : TC++ 3.0
OS            :Window 98,2000,XP  
               Vista,Windows7(only safemode)
			   
Licence   : Freeware (Please give the credit of programming to author.)
*/



#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, i;

   /* initialize graphics, local variables*/
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with error code */
   }

while(!kbhit())
{
 int x= getmaxx();
 int y= getmaxy();
 setcolor(random(10));
 for(int k=0;k<random(19900);k=k+2)

 {
  rectangle(0+k,0+k,x-k,y-k);
 delay(5);
 }
}
}