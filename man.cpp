Pari man walk and jump

#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<string.h>
#include<time.h>
float main(void)
 {
  int*p1,*p2,*p;
  clock_t start,end;
  time_t t,t1;
  int z=0,z1=0;
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "");


  int r=0;
  int ch,x=10,y=350;
  int poly[100],poly1[100],variable1;
  setcolor(14);
  ellipse(100,105,180,0,10,15);
  ellipse(93,125,320,50,3,7);
  ellipse(105,125,130,270,3,7);
  ellipse(110,112,250,90,3,2);
  line(93,128,108,133);
  putpixel(100,120,4);
  poly[0]=105;
  poly[1]=105;
  poly[2]=103;
  poly[3]=108;
  poly[4]=101;
  poly[5]=109;
  poly[6]=101;
  poly[7]=111;
  poly[8]=100;
  poly[9]=108;
  poly[10]=98;
  poly[11]=108;
  poly[12]=96;
  poly[13]=111;
  poly[14]=96;
  poly[15]=119;
  poly[16]=88;
  poly[17]=113;
  poly[18]=89;
  poly[19]=105;
  poly[20]=105;
  poly[21]=105;
  setcolor(8);
  drawpoly(11,poly);
  setfillstyle(1,8);
  floodfill(94,108,8);
  setcolor(14);
  poly1[0]=105;
  poly1[1]=105;
  poly1[2]=103;
  poly1[3]=108;
  poly1[4]=101;
  poly1[5]=109;
  poly1[6]=101;
  poly1[7]=111;
  poly1[8]=100;
  poly1[9]=108;
  poly1[10]=98;
  poly1[11]=108;
  poly1[12]=96;
  poly1[13]=111;
  poly1[14]=96;
  poly1[15]=119;
  drawpoly(8,poly1);
  line(105,105,110,105);
  setfillstyle(1,14);
  floodfill(106,110,14);
  floodfill(111,112,14);
  setcolor(2);
  for(variable1=0;variable1<=5;variable1+=2)
  ellipse(100,101,0,180,10,variable1);
  setcolor(4);
  for(variable1=0;variable1<=5;variable1+=3)
  ellipse(100,105,0,180,20,variable1);
  line(80,105,120,105);
  setfillstyle(1,0);
  fillellipse(107,111,1,2);
  setcolor(0);
  arc(107,111,70,160,3);
  setcolor(6);
  setfillstyle(1,6);
  fillellipse(99,112,1,3);
  setfillstyle(1,4);
  fillellipse(99,115,2,2);
  setcolor(8);
  for(variable1=0;variable1<=3;variable1++)
  ellipse(107,118,70,180,4,variable1);
  setcolor(4);
  line(93,128,108,133);
  line(108,133,110,138);
  line(110,138,93,133);
  line(93,133,93,128);
  setfillstyle(2,4);
  floodfill(96,131,4);
  setcolor(2);
  ellipse(100,193,20,70,15,60);
  ellipse(101,184,120,170,15,60);
  line(93,133,105,137);
  line(86,174,114,173);
  setfillstyle(1,2);
  floodfill(90,170,2);
  setcolor(3);
  line(104,140,102,150);
  line(94,140,94,151);
  line(94,140,103,140);
  line(100,150,108,165);
  line(100,165,108,165);
  line(94,151,100,165);
  setcolor(14);
  line(102,166,107,166);
  line(103,168,109,168);
  line(102,166,103,168);
  line(107,166,109,168);
  setfillstyle(1,14);
  floodfill(105,167,14);
  setcolor(0);
  line(102,169,110,169);
  setfillstyle(9,2);
  floodfill(100,145,3);
  setcolor(12);
  getimage(78,95,122,202,p1);
  line(108,175,106,195);
  line(92,175,94,195);
  line(108,175,92,175);
  line(106,195,94,195);
  setfillstyle(6,12);
  floodfill(100,180,12);
  setcolor(8);
  setfillstyle(6,8);
  ellipse(103,200,0,180,10,3);
  line(93,200,113,200);
  floodfill(103,199,8);
  getimage(78,95,122,202,p2);
  putimage(78,95,p2,1);
  putimage(78,95,p1,1);
  setcolor(12);
  setfillstyle(6,12);
  int po[100],pol[100];
  po[0]=110;
  po[1]=174;
  po[2]=120;
  po[3]=196;
  po[4]=108;
  po[5]=196;
  po[6]=96;
  po[7]=174;
  po[8]=110;
  po[9]=174;
  drawpoly(5,po);
  pol[0]=96;
  pol[1]=174;
  pol[2]=89;
  pol[3]=174;
  pol[4]=87;
  pol[5]=196;
  pol[6]=97;
  pol[7]=196;
  pol[8]=101;
  pol[9]=184;
  drawpoly(5,pol);
  floodfill(103,177,12);
  floodfill(93,177,12);
  setcolor(8);
  setfillstyle(6,8);
  ellipse(119,200,0,180,10,3);
  ellipse(97,200,0,180,10,3);
  line(109,200,129,200);
  line(107,200,87,200);
  floodfill(119,199,8);
  floodfill(97,199,8);
  getimage(78,95,130,202,p1);
  putimage(78,95,p1,1);
  putimage(x-5,350,p1,1);
  setcolor(15);
  rectangle(0,458,getmaxx()+10,getmaxy());
  setfillstyle(6,15);
  floodfill(10,464,15);
  setfillstyle(6,15);
  fillellipse(400,100,60,40);
  int v=0,v1=0,v2[1000],l1,l2,l3;
  here1:
  ch=getch();
  if(ch== 77)
     {
     x=x+5;
     //sound(3000);
     }
  else if (ch== 72)
     {
     v=350;
     for(int i=y,j=y-200,k=y+107;i>=y-200;i-=4,j+=4,k--)
	{
	if(i>=250)
	   {
	       if(x%2==0)
		  {
		    //sound(i+100);
		    delay(15);
		    if(i==y)
		    putimage(x,i+4,p1,1);
		    putimage(x,i+4,p1,1);
		    putimage(x,i,p1,2);
		    if(!kbhit())
		    z = 10;
		    while(kbhit())
			{
			    z+=2;
			    if (z>100)break;
			    v2[i]=getch();
			    delay(15);
			    switch(v2[i])
			       {
				 case 77:
				    x=x+10;
				    putimage(x,i,p1,1);
				    putimage(x-10,i,p1,1);
				    break;
				 case 75:
				    x=x-10;
				    putimage(x,i,p1,1);
				    putimage(x+10,i,p1,1);
				    break;
				 case 32:
				    l2=i;
				    for(l1=x+50;l1<=getmaxx();l1++)
				    {
				    while(kbhit())
				      {
					int t = getch();
					switch(t)
					  {
					    case 77:
					    x=x+10;
					    putimage(x,i,p1,1);
					    putimage(x-10,i,p1,1);
					    break;
					    case 75:
					    x=x-10;
					    putimage(x,i,p1,1);
					    putimage(x+10,i,p1,1);
					    break;
					  }
				      }
				    delay(3);
				    setcolor(0);
				    setfillstyle(1,4);
				    fillellipse(l1-2,l2,5,5);
				    if(!kbhit())ungetch(t);
				  }
				 default:
				   break;
				 case 27:
				    goto here2;
			       }
			     }

			ungetch(v2[i]);
		  }
	       else
		  {
		    ////sound(i+100);
		    delay(15);
		    if(i==y)
		    putimage(x,i+4,p2,1);
		    putimage(x,i+4,p2,1);
		    putimage(x,i,p2,2);
		  if(!kbhit())
		    z = 10;
		    while(kbhit())
			{
			    z+=2;
			    if (z>100)break;
			    v2[i]=getch();
			    delay(15);
			    switch(v2[i])
			       {
				 case 77:
				    x=x+10;
				    putimage(x,i,p2,1);
				    putimage(x-10,i,p2,1);
				    break;
				 case 75:
				    x=x-10;
				    putimage(x,i,p2,1);
				    putimage(x+10,i,p2,1);
				    break;
				 case 32:

				 default:
				   break;
				 case 27:
				    goto here2;
			     }
			}
		    ungetch(v2[i]);
		  }

		     }

	      if(i<250)
		  {
		      if(x%2==0)
			   {
			       ////sound(j+100);
			       delay(15);
			       if(j==y)
			       putimage(x,i-4,p,1);
			       putimage(x,j-4,p1,1);
			       putimage(x,j,p1,2);
			    }
		     else
			    {
			       ////sound(i+100);
			       delay(15);
			       if(j==y)
			       putimage(x,i-4,p,1);
			       putimage(x,j-4,p2,1);
			       putimage(x,j,p2,2);
			    }
		 }
	}
   }
else if (ch== 75)
{
   x=x-5;
   ////sound(3000);
}
else if (ch== 27)
goto here2;
else 	goto here;
if(ch==77||ch==75)
    {
    if(x%2==0)
       {
	   if(r==1)
	       {
		    if(ch==77)
		    putimage(x-5,y,p2,1);
		    if(ch==75)
		    putimage(x+5,y,p2,1);
	       }
	   putimage(x,y,p1,1);
       }
   else
       {
	   if(r==1)
	       {
		    if(ch==77)
		    putimage(x-5,y,p1,1);
		    if(ch==75)
		    putimage(x+5,y,p1,1);
		}
		    if(r==0)
		    putimage(x-10,350,p1,1);
		    putimage(x,y,p2,1);
	}
   r=1;
   }
   here:
   nosound();
   goto here1;
   here2:
   nosound();
}
