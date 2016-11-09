/*
A simple type of graphics programme
that draw computer picture and two
screen saver.


Programme Name:COMPUTER
Programme Code:COMPUTER
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
void vp(int x,int tc,int bk,char *text);
void square(int x,int y,int size);

void my_computer()
{//===========================================================
  int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

vp(10,14,8,"   MY COMPUTER    ");
//------------------monitor--------------------
      setbkcolor(0);
      setcolor(15);
 square(300,160,150);square(300,160,148);square(300,160,130);square(300,160,131);
 setaspectratio(2,5);
 int stangle=0,endangle=180;int radius = 100;

 setcolor (2);        // This becomes drawing color
 square(300, 160, 128);    // Draw the circle
 setfillstyle(1, 2); // Set pattern to fill interior
 floodfill(300,160, 2);  // Fill the circle

  setcolor(15);   /* draw arc */
  arc(295+9, 353, stangle, endangle, radius);
  arc(295+9, 354, stangle, endangle, radius-1);
  arc(295+9, 355, stangle, endangle, radius-90); //y=500
  line(200-4+9,355,400-5+9,355);
  line(200-4+9,355+2,400-5+9,355+2);

//------------------keyboard--------------
     int a=0,b=0;
for(int kb=0;kb<3;kb++)
{moveto(150+a,370+b);lineto(450+a,370+b);lineto(400+a,430+b);lineto(100+a,430+b);
 lineto(150+a,370+b);a=a+2,b=b+2;
}
       square(300,360,8);
	int distance=0;
for(int key=0;key<13;key++){square(170+distance,380,7);distance=distance+20;}
	 int distance1=0;
for(int key1=0;key1<9;key1++){square(160+distance1,392,7);distance1=distance1+30;}
	int distance2=0;
for(int key2=0;key2<9;key2++){square(140+distance2,403,8); distance2=distance2+32;}
       int distance3=0;
for(int key3=0;key3<9;key3++){square(130+distance3,415,8); distance3=distance3+32;}


//----------------cpu------------------------------------------
   //setclor
  rectangle(490,60,600,350);rectangle(490-1,60-1,600-1,350-1);
  rectangle(490-2,60-2,600-2,350-2);
  square(540,120,40); square(520,100,12);square(555,100,12);
  square(520,100,5);square(555,100,5);square(560,120,6);
  circle(530,125,7);circle(530,125,6); //hard disk

 square(537,250,28); square(520,250,12);square(555,250,12);
 circle(560,273,7);circle(560,273,6); circle(540,300,12);circle(540,300,8);
 circle(540,300,4);//floppy drive

 line(425-1,370-1,425-1,340-1);line(425-1,340-1,487-1,340-1);
 line(425,370,425,340);line(425,340,487,340);

gotoxy(25,6); printf(" HI.. MY NAME IS KRISHNA.  ");
gotoxy(25,7); printf(" THIS COMPUTER CONTAIN TWO ");
gotoxy(25,8); printf(" SREEN SAVER PRESS ANY KEY "); setbkcolor(0);

 getch();
//------------------screen saver
setviewport(170,40,getmaxx()-200,getmaxy()-190,3);
randomize();
 while(!kbhit())
 {
    int x=random(700) ,y=random(500);//size=random(30);
     setcolor(random(13));
    for(int size=0;size<random(300);size=size+3)
    {
    rectangle((10+size)+x,(0+size)+y,(getmaxx()-640-size)+x,(getmaxy()-470-size)+y);
   rectangle((11+size)+x,(1+size)+y,(getmaxx()-641-size)+x,(getmaxy()-471-size)+y);

    delay(0);
   // clearviewport();
    }
 }

/********************************************************/
   getch();
    setfillstyle(SOLID_FILL, getmaxcolor());
  floodfill(200,300,2);
 //  setbkcolor(2);
  while(!kbhit())
  {
  int  r2=random(10);
  int  r3= 7;//random(7);
   settextstyle(r2,0,r3);
  int  Clr=random(16);
   setcolor(Clr);if(Clr==0){Clr=0;}

    for (int x=-140;x<350;x=x+10)
     {
    outtextxy(x,100,"KRISHNA");
    delay(50);
    clearviewport();
    if(kbhit()){break;}
     }
   delay(10);
   clearviewport();
  }

}//==========================================================end_main


void vp(int x,int tc,int bk,char *text)
{  setcolor(2);
  settextstyle(2,0,6);
  outtextxy(50,-4,"     MY COMPUETR  (PRESS ANY KEY TO EXIT)");
  setcolor(2);
  rectangle(6,13,getmaxx()-6,getmaxy()-6);
  }

 void square(int x,int y,int size)
    {
     rectangle((10+size)+x,(0+size)+y,(getmaxx()-640-size)+x,(getmaxy()-470-size)+y);
   rectangle((11+size)+x,(1+size)+y,(getmaxx()-641-size)+x,(getmaxy()-471-size)+y);
    }

 main()
 {
 my_computer();
 }