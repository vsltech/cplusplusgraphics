#include<graphics.h>
#include<conio.h>
#include<dos.h>

void main()
{
 int gdriver=DETECT,gmode,i=0,j=0;
 initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");

 for(i;i<420;++i)
 {
  line(0,245,650,245);
  line(0+i,200,210+i,200);
  line(50+i,200,70+i,170);
  line(70+i,170,140+i,170);
  line(140+i,170,160+i,200);
  line(85+i,170,85+i,200);
  line(125+i,170,125+i,200);

  line(0+i,200,0+i,230);
  line(210+i,200,210+i,230);
  line(0+i,230,50+i,230);
  circle(65+i,230,15);
  line(80+i,230,130+i,230);
  circle(145+i,230,15);
  line(210+i,230,160+i,230);

  pieslice(65+i,230,359-j,360-j,15);
  pieslice(65+i,230,179-j,180-j,15);
  pieslice(65+i,230,89-j,90-j,15);
  pieslice(65+i,230,269-j,270-j,15);

  pieslice(145+i,230,359-j,360-j,15);
  pieslice(145+i,230,179-j,180-j,15);
  pieslice(145+i,230,89-j,90-j,15);
  pieslice(145+i,230,269-j,270-j,15);

  if(j==179)
   j=0;
  ++j;
  delay(30);
  cleardevice();
 }
 closegraph();
}
