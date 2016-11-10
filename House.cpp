#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void dda( float xa, float ya, float xb, float yb);


void main()
{
clrscr();

int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
for(int i=16;i>=14; i--)
{

delay(900);
setcolor(i);
line(216,110,410,110);

}
for(int i1=16;i1>=14; i1--)
{

delay(900);
setcolor(i1);
line(216,110,216,250);

}

for(int i2=16;i2>=14; i2--)
{

delay(900);
setcolor(i2);
line(216,250,410,250);
}
for(int i3=16;i3>=14; i3--)
{

delay(900);
setcolor(i3);
line(410,110,410,250);
}
for(int i4=16;i4>=14; i4--)
{

delay(900);
setcolor(i4);
line(216,120,410,120);
               }for(int i5=16;i5>=14; i5--)
{

delay(900);
setcolor(i5);
line(216,110,313,10);   }
for(int i6=16;i6>=14; i6--)
{

delay(900);
setcolor(i6);
line(410,110,313,10);
}for(int i7=16;i7>=14; i7--)
{

delay(900);
setcolor(i7);
line(250,250,250,150);   }
for(int i8=16;i8>=14; i8--)
{

delay(900);
setcolor(i8);
line(300,250,300,150);
}for(int i9=16;i9>=14; i9--)
{

delay(900);
setcolor(i9);
line(250,150,300,150);
 }for(int i10=16;i10>=14; i10--)
{

delay(900);
setcolor(i10);

line(320,150,320,200);   }
for(int i11=16;i11>=14; i11--)
{

delay(900);
setcolor(i11);
line(390,150,390,200);  }for(int i111=16;i111>=14; i111--)
{

delay(900);
setcolor(i111);
line(320,150,390,200);   }
for(int i12=16;i12>=14; i12--)
{

delay(900);
setcolor(i12);
line(320,200,390,150);
}for(int i13=16;i13>=14; i13--)
{

delay(900);
setcolor(i13);
line(320,150,390,150);
}for(int i14=16;i14>=14; i14--)
{

delay(900);
setcolor(i14);
line(320,200,390,200);  }
for(int i15=16;i15>=14; i15--)
{

delay(900);
setcolor(i15);
circle(313,60,10);       }
for(int i16=16;i16>=14; i16--)
{

delay(900);
setcolor(i16);

line(410,120,480,90);
}
for(int i17=16;i17>=14; i17--)
{

delay(900);
setcolor(i17);
line(313,10,480,90);
}
for(int i18=16;i18>=14; i18--)
{
delay(900);
setcolor(i18);
line(410,250,480,220);
}
for(int i19=16;i19>=14; i19--)
{

delay(900);
setcolor(i19);
line(480,90,480,220);     }for(int i20=16;i20>=14; i20--)
{

delay(900);
setcolor(i20);

line(410,110,468,87);      }for(int i21=16;i21>=14; i21--)
{

delay(900);
setcolor(i21);

line(436,150,460,140);      }for(int i22=16;i22>=14; i22--)
{

delay(900);
setcolor(i22);
line(437,200,461,190);       }for(int i23=16;i23>=14; i23--)
{

delay(900);
setcolor(i23);
line(437,150,437,200);    }for(int i24=16;i24>=14; i24--)
{

delay(900);
setcolor(i24);
line(460,140,460,190);     }for(int i25=16;i25>=14; i25--)
{

delay(900);
setcolor(i25);

line(436,160,460,150);
}for(int i26=16;i26>=14; i26--)
{

delay(900);
setcolor(i26);
line(436,190,460,180);
}for(int i27=16;i27>=14; i27--)
{

delay(900);
setcolor(i27);
circle(448,170,12);
}for(int i28=16;i28>=14; i28--)
{

delay(900);
setcolor(i28);

arc(185,275,300,20,70);
}for(int i29=16;i29>=14; i29--)
{

delay(900);
setcolor(i29);
arc(235,275,300,20,70);
 }


getch();
}