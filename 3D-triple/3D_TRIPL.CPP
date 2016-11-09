/*
==================================
NAME - KRISHNA KUMAR

AGE AT PROGRAMING THIS CODE - 17 YEARS

QUALIFICAION AT PROGRAMING THIS CODE-10TH PASS (NCERT)

E-MAIL: krishx007@yahoo.com

Use the following link given below to download my other programs.
http://www.programmersheaven.com/user/krishna268code/contributions

DATE OF LOUNCHING CODE -MARCH 2004




Some big programes created by me-
=================================
 TALK2ME - A simple graphics programe
 SG ZONE-  Special Graphics Zone containig 30 unique  animations.
 KRIOS  -  A simple prototype oprating system
 3D CUBE ANALYSIS -A GUI 3D programe for discribing 3D cube rotation,axcis etc.

  programing of new codes is goingon

 Licence   : Freeware (Please give the credit of programming to author.)


Software Details
====================
Developed in   : C++
Compiler used : TC++ 3.0



====================================== */


#include<iostream.h>
#include<dos.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

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

  double x1,x2,y1,y2;
  void draw_cube(double edge[20][3])
	  {
       for(int i=0;i<19;i++)
	      {
	       x1=edge[i][0]+edge[i][2]*(cos(2.3562));
	       y1=edge[i][1]-edge[i][2]*(sin(2.3562));
	       x2=edge[i+1][0]+edge[i+1][2]*(cos(2.3562));
	       y2=edge[i+1][1]-edge[i+1][2]*(sin(2.3562));
	line(x1+100,150-y1,x2+100,150-y2);
	     }

	  }

   void draw_cube2(double edge[20][3])
	  {
       for(int i=0;i<19;i++)
	      {
	       x1=edge[i][0]+edge[i][2]*(cos(2.3562));
	       y1=edge[i][1]-edge[i][2]*(sin(2.3562));
	       x2=edge[i+1][0]+edge[i+1][2]*(cos(2.3562));
	       y2=edge[i+1][1]-edge[i+1][2]*(sin(2.3562));
	line(x1+450,150-y1,x2+450,150-y2);
	     }

	  }

   void draw_cube3(double edge[20][3])
	  {
       for(int i=0;i<19;i++)
	      {
	       x1=edge[i][0]+edge[i][2]*(cos(2.3562));
	       y1=edge[i][1]-edge[i][2]*(sin(2.3562));
	       x2=edge[i+1][0]+edge[i+1][2]*(cos(2.3562));
	       y2=edge[i+1][1]-edge[i+1][2]*(sin(2.3562));
	line(x1+250,340-y1,x2+250,340-y2);
	     }

	  }


    double edge[20][3]=
		 {
	    100,0,0,
	    100,100,0,
	    0,100,0,
	    0,100,100,
	    0,0,100,
	    0,0,0,
	    100,0,0,
	    100,0,100,
	    100,75,100,
	    75,100,100,
	    100,100,75,
	    100,100,0,
	    100,100,75,
	    100,75,100,
	    75,100,100,
	    0,100,100,
	    0,100,0,
	    0,0,0,
	    0,0,100,
	    100,0,100
		 };

 void rotate(double edge[20][3])
      {
	  double temp,theta=0,temp1;

	     while(!kbhit())
	      {

	     setcolor(14);
	    circle(280,160,40);
	     theta=(theta*3.14)/180;
	      setcolor(11);
	    for(int i=0;i<20;i++)
		  {
		    edge[i][0]=edge[i][0];
		      temp=edge[i][1];
		      temp1=edge[i][2];
		    edge[i][1]=temp*cos(theta)-temp1*sin(theta);
		    edge[i][2]=temp*sin(theta)+temp1*cos(theta);
		  }
	    draw_cube(edge);
	    //------------
	      setcolor(15);
	     for(int ii=0;ii<20;ii++)
		  {
		    edge[ii][1]=edge[ii][1];
		      temp=edge[ii][0];
		      temp1=edge[ii][2];
		    edge[ii][0]=temp*cos(theta)+temp1*sin(theta);
		    edge[ii][2]=-temp*sin(theta)+temp1*cos(theta);
                  }
	    draw_cube2(edge);
	   //-------------

	    setcolor(13);
	     for(i=0;i<20;i++)
                  {
                    edge[i][2]=edge[i][2];
		      temp=edge[i][0];
                      temp1=edge[i][1];
                    edge[i][0]=temp*cos(theta)-temp1*sin(theta);
                    edge[i][1]=temp*sin(theta)+temp1*cos(theta);
                  }
	    draw_cube3(edge);

	      delay(10);
	      theta=theta+1;
	      clearviewport();
	      } //for kbhit
	     }

main()
{

 int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");
vp(18,2,12,"3-DIMENTIONAL CUBE (krishx007@yahoo.com)  Press any key ");
   draw_cube(edge);

   rotate(edge);
 }