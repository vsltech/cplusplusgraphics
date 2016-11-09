/*QUALIFICAION AT PROGRAMING THIS CODE-10TH PASS (CBSE )

E_MAIL-KRISHX007@YAHOO.COM

DATE OF LAUNCHING CODE -MARCH 2004



My interesting feild & hobbies
===============================
Electronics,programing,robotics,spoiled philosophies, etc.

>Believe in skills and not in qualification.




Some big programes created by me-
/*=================================
 TALK2ME - A simple graphics programe
 SG ZONE-  Special Graphics Zone containig 30 unique  animations.
 KRIOS  -  A simple prototype oprating system
 3D CUBE ANALYSIS -A GUI 3D programe for discribing 3D cube rotation,axcis etc.

  programing of new codes is goingon.

 Licence   : Freeware (Please give the credit of programming to author.)


Software Details
====================
Developed in   : C++
Compiler used : TC++ 3.0




======================================= */
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>



 /*--------------------------- load function --------------------------*/
void load()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)
   { clrscr();
   printf("GRAPHICS ERROR: %s\n", grapherrormsg(errorcode));
   printf(" PRESS ANY KEY TO EXIT or RESTART THE PROGRAME.");
   getch();
   }
}

/*-----------------------------veiwport--------------------------------*/
void vp(int x,int tc,int bk,char *text)
{

  setcolor(tc);
  settextstyle(2,0,6);
  outtextxy(x,-4,text);
  setcolor(bk);
  rectangle(7,14,getmaxx()-7,getmaxy()-7);
  rectangle(6,13,getmaxx()-6,getmaxy()-6);
  setviewport(8,15,getmaxx()-8,getmaxy()-8,3);
 }
/*-----------------------------------------------------------------------*/


c(a,b)
{
setcolor(random(16));
setaspectratio(3,1);
for(int i=0;i<30;i=i+1)
circle(a,b,i);
}


void piano()//---------------------------------------------


{
load(); vp(150,13,12,"WARNING: ONLY WORK IF PC HAVE AUDIBLE BELL.");
setbkcolor(0); int a=300;
setcolor(12);settextstyle(10,0,2);
outtextxy(10,50,"PIANO, PRESS 0 TO 9 KEY TO PLAY.");
outtextxy(10,90," PRESS X FOR EXIT.");
setcolor(9);settextstyle(0,0,2);
outtextxy(10,150," PRESS A,B & C FOR CHANGING TUNE.");
setcolor(14);outtextxy(180,420," PROGRAMED BY KRISHNA KUMAR.");
setcolor(4);
line(20,400,590,400);
line(20,401,590,401);
line(20,402,590,402);
int x=10;
int d=1;
while(1)
   {
 switch(toupper(getch()))
	 {
 case '1': sound(20*x);  c(40+d,300);  delay(a);  nosound(); break;
 case '2': sound(40*x);  c(100+d,300); delay(a);  nosound(); break;
 case '3': sound(60*x);  c(160+d,300); delay(a);  nosound(); break;
 case '4': sound(80*x);  c(220+d,300); delay(a);  nosound(); break;
 case '5': sound(100*x); c(280+d,300); delay(a);  nosound(); break;
 case '6': sound(120*x); c(340+d,300); delay(a);  nosound(); break;
 case '7': sound(140*x); c(400+d,300); delay(a);  nosound(); break;
 case '8': sound(160*x); c(460+d,300); delay(a);  nosound(); break;
 case '9': sound(180*x); c(520+d,300); delay(a);  nosound(); break;
 case '0': sound(200*x); c(580+d,300); delay(a);  nosound(); break;
 case 'A': x=1;                                              break;
 case 'B': x=5;                                              break;
 case 'C': x=40;                                             break;
 case 'X':for(int x=0;x<25;x++){delay(50); printf("\n\n\n");}closegraph();exit(0);
	 }
     }
 }
	 
main()
	 
{
load();
piano();

}
	 
	