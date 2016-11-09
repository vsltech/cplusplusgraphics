/*
The smallest and cutest programme
that draws different types of
pattern on screen.


Programme Name:PATTERN
Programme Code:GROUTH
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
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
main()
{//-----------------------------
clrscr();
int a=0;
int R=10;
randomize();
while(!kbhit())
{
if(a==100){ R=random(50); a=0;}

for(int i=0;i<R;i++)
{printf("   ");}
printf("");
delay(10);
a=a+1;
}
 }//-------------------------------