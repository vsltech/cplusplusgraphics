/*
A graphics programme
that shows Solar System.

Programme Name:SOLAR_SYSTEM
Programme Code:WAVB_PLA3
Programmer:krishx007

WEBSITE:gfxguru.net
E-MAIL: krishx007@yahoo.com

Check Out other graphics programmes at www.gfxguru.net

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
 void square(int x,int y,int size)
{//-------------------------------------------------------------------
rectangle((10+size)+x,(0+size)+y,(getmaxx()-640-size)+x,(getmaxy()-470-size)+y);
rectangle((11+size)+x,(1+size)+y,(getmaxx()-641-size)+x,(getmaxy()-471-size)+y);
}//---------------------------------------------------------------------


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

 /*  if(x>680)
 { x=300;}
  if(y>680)
 { y=350;} */


//////////////
int x=300,y=220;
  int time=50;
moveto(x,y);
//for(int r=50;r<410;r=r+5)
   float r=170;  int show_path=1;int stop=0;
  {
  for(float i=1;;i=i+0.03)

    {

 setcolor(13);
 setcolor(13);
  settextstyle(2,0,4);
  outtextxy(10,0,"  (======= SOLAR SYSTEM ========)           PRESS P TO SHOW PATH.   PRESS C TO CLEAR PATH.");setcolor(14);
  outtextxy(10,13,"PRESS 1 TO 7 FOR CHANGING SPEED.  PRESS S FOR STOP.   PRESS X FOR EXIT.      	PROGRAMED BY KRISHNA KUMAR(C).");
  setcolor(2);  rectangle(7,25,getmaxx()-7,getmaxy()-7);
//  setviewport(8,26,getmaxx()-8,getmaxy()-8,3);
//vp(18,14,12,"SOLAR SYSTEM (krishna268@rediffmail.com)  Press any key ");
	setcolor (15);        // This becomes drawing color
	circle(300,220, 35);    // Draw the circle
	setfillstyle(9, 15); // Set pattern to fill interior
	floodfill(300,220, 15);  // Fill the circle
	setcolor (11 );

       setaspectratio(2,4.01);
     setcolor(7);

  if(kbhit())
{char a=getch();if(a=='1')time=10;if(a=='2')time=40;if(a=='3')time=50; if(a=='4')time=70;
if(a=='5')time=100;if(a=='6')time=150;  if(a=='7')time=200;
if(a=='x'||a=='X'){closegraph();exit(0);}if(a=='s'||a=='S')stop=1;
if(a=='C'||a=='c')show_path=0; if(a=='p'||a=='P')show_path=1;
}


  int a=x+(r+100)*sin(i);
  int b=y+(r+100)*cos(i)/1.5; //x,y axis for earth

  int a1=x+(220)*sin(i*3);
  int b1=y+(220)*cos(i); //x,y axis for venus


  int a2=x+(190)*sin(i*3);
  int b2=y+(190)*(cos(i*3)/2);
			 //int MaxX=getmaxx();  int MaxY=getmaxy();for (int i=0 ;i<100;++i){ setcolor(15);circle(random(MaxX), random(MaxY),1);putpixel(random(MaxX), random(MaxY),15 );}
  int moon_x=a+(40)*sin(i*18);
  int moon_y=b+(40)*(cos(i*18));//x,y axis for moon  line(x,y,a,b);

  int a3=x+(115)*(sin(i*5));
  int b3=y+(115)*(cos(i*5)/2);//x,y axis for mercury
	 if(show_path==1){
	 circle(300,220, 280);//earth path
	 circle(300,220, 190);//venus path
	 circle(300,220, 110);
	 //circle(a,b, 40);
	 }//mercury path


	 setaspectratio(1,1);
	setcolor (6);        // This becomes drawing color
	circle(moon_x,moon_y, 5);    // Draw the circle
	setfillstyle(6,6); // Set pattern to fill interior
	floodfill(moon_x,moon_y,6);  // Fill the circle


	setcolor (9);        // This becomes drawing color
	circle(a, b, 13);    // Draw the circle
	setfillstyle(6, 9); // Set pattern to fill interior
	floodfill(a,b, 9);  // Fill the circle
				    //setcolor (random(15));

	 setcolor (2);        // This becomes drawing color
	circle(a2, b2, 10);    // Draw the circle
	setfillstyle(6, 2); // Set pattern to fill interior
	floodfill(a2,b2, 2);  // Fill the circle					      // if(i>5){cleardevice();}

      setcolor (6);        // This becomes drawing color
	circle(a3, b3, 10);    // Draw the circle
	setfillstyle(6, 6); // Set pattern to fill interior
	floodfill(a3,b3, 6);  // Fill the circle					  // line(300,220,a,b);
	putpixel(a3,b3,15);
int x=a1,y=b1;
 setcolor (12);
//solar panal
 square(x+10,y+25,8);square(x+10,y+25,5); square(x+85,y+25,8);square(x+85,y+25,5);
 square(x+25,y+25,4); square(x+70,y+25,4);
 //middle box
 moveto(x+40,y+20); lineto(x+40,y+40); lineto(x+65,y+40); lineto(x+65,y+20); lineto(x+40,y+20);
 moveto(x+40+1,y+20); lineto(x+40+1,y+40-1); lineto(x+65-1,y+40-1); lineto(x+65-1,y+20+1); lineto(x+40+1,y+20+1);
 circle(x+45,y+32,1); circle(x+58,y+32,1);  circle(x+52,y+27,1);  circle(x+52,y+27,3);
// anntina
  line(x+40,y+10,x+50,y+20);circle(x+40,y+10,2);    line(x+65,y+10,x+55,y+20);circle(x+65,y+10,2);

  delay(time);
 // r=r+0.05;
 if(stop==1){getch();stop=0;}
  cleardevice();
     }
  }

}//_main

