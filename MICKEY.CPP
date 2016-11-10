#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void f(int,int,int);
void e(int,int,int);
void ey(int,int,int,int,int,int);
void n(int,int,int,int,int);
void m(int,int,int,int,int,int);
void s(int,int,int,int);
void ft(int,int,int,int,int,int);
void r(int,int,int,int);

void main()
{
/* request auto detection */
int gdriver = DETECT, gmode, errorcode;
int midx, midy;
int rad,sangle,endangle,xradius,yradius;
int right,left,top,bottom;
int ri,to,le,bo;

/* initialize graphics and local
variables */
initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");


e(midx,midy,rad);
f(midx,midy,rad);
n(midx,midy,sangle,endangle,rad);
m(midx,midy,sangle,endangle,xradius,yradius);
s(left,top,right,bottom);
ft(midx,midy,sangle,endangle,xradius,yradius);
r(le,to,ri,bo);
ey(midx,midy,sangle,endangle,xradius,yradius);

settextstyle(GOTHIC_FONT,0,4);
outtextxy(90,340,"Wanna");
settextstyle(GOTHIC_FONT,0,4);
outtextxy(90,370,"Play");
settextstyle(GOTHIC_FONT,0,4);
outtextxy(90,402,"Tennis...");


getch();
closegraph();
}

//function definition for cartoon's face

void f(int midx,int midy,int rad)
{
int a=getmaxx()/2;
int b=getmaxy()/4+18;

setfillstyle(1,14);
circle(a,b,70);
floodfill(a,b,15);
}

//function definition for cartoon's ear

void e(int midx,int midy,int rad)
{
midx = getmaxx() / 3+21;
midy = getmaxy() / 8+18;

setfillstyle(1,6);
circle(midx,midy,35);
floodfill(midx,midy,15);

midx=getmaxx()/3+191;
midy =getmaxy()/8+18;

setfillstyle(1,6);
circle(midx,midy,35);
floodfill(midx,midy,15);
}

//function definition for cartoon's eyes

void ey(int midx,int midy,int sangle,int endangle,int xradius,int yradius)
{
int e=getmaxx()/2-30;
int f=getmaxy()/5+18;

setfillstyle(1,8);
ellipse(e,f,0,360,15,25);
floodfill(e,f,15);

int A=getmaxy()/5+30;

setfillstyle(1,0);
ellipse(e,A,0,360,8,13);
floodfill(e,A,15);

e=getmaxx()/2+30;
f=getmaxy()/5+18;

setfillstyle(1,8);
ellipse(e,f,0,360,15,25);
floodfill(e,f,15);

int B=getmaxy()/5+30;

setfillstyle(1,0);
ellipse(e,B,0,360,8,13);
floodfill(e,A,15);
}

//function definition for cartoon's nose

void n(int midx,int midy,int sangle,int endangle,int rad)
{
int g=getmaxx()/3+107;
int h=getmaxy()/3;

setfillstyle(1,6);
pieslice(g,h,35,135, 20);
floodfill(midx,midy,15);
}

//function definition for cartoon's mouth

void m(int midx,int midy,int sangle,int endangle,int xradius,int yradius)
{
int i=getmaxx()/3+108;
int j=getmaxy()/3+20;

setfillstyle(1,6);
ellipse(i,j,0,360,20,8);
floodfill(i,j,15);

int k=getmaxx()/3+136;
int l=getmaxy()/3+12;

arc(k,l,180,270,10);

k=getmaxx()/3+80;
l=getmaxy()/3+12;

arc(k,l,265,0,10);
}

//function definition for cartoon's stomach

void s(int left,int top,int right,int bottom)
{

int x = getmaxx() / 2+1;
int y = getmaxy() / 2;

setfillstyle(1,6);
bar(x-30, y-34, x+28,y+9);

setfillstyle(2,1);
bar(x-44, y-7, x+42,y+89);

setfillstyle(2,4);
bar(x-44, y+170, x-18,y+90);

setfillstyle(2,4);
bar(x+16, y+170, x+42,y+90);

setfillstyle(2,4);
bar(x+78, y, x+95,y+40);

setfillstyle(2,4);
bar(x-45, y-9, x-85,y+9);

setfillstyle(2,4);
bar(x+42, y-9, x+95,y+9);

setfillstyle(2,4);
bar(x-98, y-9, x-82,y+40);
}

//function definition for cartoon's foots

void ft(int midx,int midy,int sangle,int endangle,int xradius,int yradius)
{
int r=getmaxx()/2-30;
int s=getmaxy()/2+185;

setfillstyle(7,1);
ellipse(r,s,0,360,24,16);
floodfill(r,s,15);
r=r+60;

setfillstyle(7,1);
ellipse(r,s,0,360,24,16);
floodfill(r,s,15);
setfillstyle(7,8);
ellipse(r+138,s-130,0,360,38,30);
floodfill(r+130,s-130,15);

r=r+58;
s=s-130;

setfillstyle(1,6);
ellipse(r,s,0,360,15,18);
floodfill(r,s,15);

r=r-178;

setfillstyle(1,6);
ellipse(r,s,0,360,15,18);
floodfill(r,s,15);

setfillstyle(1,15);
circle(r,s+13,10);
floodfill(r,s+22,15);
floodfill(r,s+15,15);
}

//function definition for cartoon's racket

void r(int le,int to,int ri, int bo)
{
le=getmaxx()/4-120;
to=getmaxy()/4-150;
ri=getmaxx()/2+280;
bo=getmaxy()/3-130;

setfillstyle(6,2);
bar(le,to,ri,bo);

to=to+480;
bo=bo+448;

setfillstyle(6,2);
bar(le,to,ri,bo);

setfillstyle(1,8);
bar(le+367,to-160,ri-147,bo-180);

ri=ri-532;
to=to-420;

setfillstyle(6,2);
bar(le,to,ri,bo);

le=getmaxx()/1-68;
to=getmaxy()/3-130;
ri=getmaxx()/2+280;
bo=getmaxy()/2+210;

setfillstyle(6,2);
bar(le,to,ri,bo);
}