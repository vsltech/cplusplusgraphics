 #include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
          int mx,my,grd=DETECT,grm=CGA;
          int i,j,rad=10;
	  initgraph(&grd,&grm,"c://turboc3//bgi");
          mx=getmaxx()/2;
          my=getmaxy()/2;
          setbkcolor(GREEN);
          setcolor(RED);
       /*         for(i=0;i<=315;i+=45)
                   pieslice(mx,my,i,i+45,100);  */
	  while(getch()!=0)
          {
                   for(i=0;i<=100;i+=3)
                   {
                             clearviewport();
                             line(0,my+rad+1,2*mx,my+rad+1);
                             circle(mx+j,my+i-100,rad);
                             setfillstyle(1,4);
                             floodfill(mx+j,my+i-100,RED);
                             delay(10);
                   }
		/*   for(;i>=0;i-=3)
		   {
			     clearviewport();
			     line(0,my+rad+1,2*mx,my+rad+1);
			     circle(mx+j,my+i-100,rad);
			     setfillstyle(1,4);
			     floodfill(mx+j,my+i-100,RED);
			     delay(10);
		   } */
          }
          getch();
}