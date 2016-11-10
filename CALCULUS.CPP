//============================================================================
//                          V S L   T E C H
//============================================================================


//============================================================================
//                          HEADER SECTION
//============================================================================
#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
//============================================================================
//                          PROTOTYPE SECTION
//============================================================================
void border();
void logo();
void load();
void home();
void diff();
void integ();
void about();
//============================================================================
//                            BODY SECTION
//============================================================================
void main()
{
  clrscr();
 int gm,gd=DETECT;
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  logo();
  cleardevice();
//  load();
  home();
  


  getch();
  closegraph();
}
void border()
{
  cleardevice();
 int i,j;
  setbkcolor(BLUE);
  setcolor(RED);
 for(i=0;i<5;i++) rectangle(i,i,getmaxx()-i,getmaxy()-i);
  setcolor(WHITE);
 for(i=6;i<25;i++) rectangle(i,i,getmaxx()-i,getmaxy()-i);
  setcolor(RED);
 for(i=26;i<30;i++) rectangle(i,i,getmaxx()-i,getmaxy()-i);
  settextstyle(SMALL_FONT,HORIZ_DIR,4);
 for(i=24,j=1;j<10;i+=67,j++) outtextxy(i,8,"VSL TECH");
 for(i=24,j=1;j<10;i+=67,j++) outtextxy(i,getmaxy()-20,"VSL TECH");
  settextstyle(SMALL_FONT,VERT_DIR,4);
 for(i=28,j=1;j<8;i+=62,j++) outtextxy(7,i,"VSL TECH");
 for(i=76,j=1;j<8;i+=62,j++) outtextxy(getmaxx()-22,getmaxy()-i,"VSL TECH");
}
void logo()
{
 int i,j;
  border();
  setcolor(WHITE);
  settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
  outtextxy(150,25,"******************");
  outtextxy(180,70,"CALCULUS");
  outtextxy(150,95,"  -------   ");
  outtextxy(160,120,"CALCULATOR");
  outtextxy(150,150,"*******************");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  outtextxy(80,300,"Loading Please Wait...");
  setcolor(RED);
 for(i=1;i<8;i++) rectangle(50+i,350+i,getmaxx()-50+i,getmaxy()-80+i);
  settextstyle(GOTHIC_FONT,HORIZ_DIR,5); setcolor(WHITE);
 for(i=1;i<500;i+=20)
 {
  delay(300);
  outtextxy(70+i,345,"*");
 }
}
void load()
{
  cleardevice();
 int j=0,i=(getmaxx()/4)+40;
  setbkcolor(WHITE);
  setcolor(RED);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  while(i>=0)
  {i--;i--;j+=2;
   setcolor(i);
   rectangle(j,j,getmaxx()-j,getmaxy()-j);
   rectangle(j,j,getmaxx()-j,getmaxy()-j);
   delay(200);
  }
   setcolor(RED);
   outtextxy((getmaxx()/2)-80,(getmaxy()/2)-10,"Please Wait...");
   delay(5000);
   cleardevice();
   setbkcolor(BLUE);
}
void home()
{
  cleardevice();
  setbkcolor(WHITE);
  setcolor(RED);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  outtextxy(10,10,"Welcome To Calculus Calci");
  setlinestyle(DOTTED_LINE,1,1);
  line(0,60,getmaxx(),60);
  line(0,63,getmaxx(),63);
  line(0,70,getmaxx(),70);
  line(0,73,getmaxx(),73);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  outtextxy(20,200,"1.DIFFERENTIATION");
  outtextxy(400,200,"2.INTEGRATION");
  line(0,250,getmaxx(),250);
  line(0,253,getmaxx(),253);
  outtextxy(520,450,"3.ABOUT");
  setcolor(BLUE);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  outtextxy(250,300,"q.QUIET");
  setcolor(RED);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  outtextxy(50,400,"Enter your choice(1/2/3/q)?");
  char ch=getch();
  switch(ch)
  {
   case '1':
    diff();
    break;
   case '2':
    integ();
    break;
   case '3':
    about();
    break;
   case 'q':
    exit(0);
   default:
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(BLUE);
    cleardevice();
    setbkcolor(RED);
    outtextxy(100,250,"INVALID ENTRY! TRY Again!");
    delay(2000);
    cleardevice();
    load();
    home();
  }
}
void diff()
{
 cleardevice();
 int i,j,size=0,coff[100];
 char ch='y',ch1,oprtr1[100],oprtr2[100],oprnd[100];
 setbkcolor(BLACK);
 cout<<"\t\t\tDIFFERENTIATION CALCULATOR\n";
 cout<<"\t\t\t==========================\n";
 cout<<"\n\tSAMPLE FUNCTION INPUT:-\n";
 cout<<"\tQ}Differentiate 5*x^5+4*y^4-2=0 w.r.t 'x'?\n";
 cout<<"\tAns}d/dx(5*x^5+4*y^4-2)= 25*x^4=0";
 cout<<"\n\n\tHow to ENTER:-\n";
 for(j=0; ;j++)
 {
 if(ch=='y')
 {
  cout<<"\nSKIP:OPERATOR1(y/n)?";
  cin>>ch1;
  cout<<"Operator=";
  if(ch1=='n')  cin>>oprtr1[j];
  cout<<"\nSKIP:COFFECIENT(y/n)?";
  cin>>ch1;
  cout<<"Coffecient=";
  if(ch1=='n')  cin>>coff[j];
  cout<<"\nSKIP:OPERATOR2(y/n)?";
  cin>>ch1;
  cout<<"Operator2=";
  if(ch1=='n')  cin>>oprtr2[j];
  cout<<"\nSKIP:OPERAND(y/n)?";
  cin>>ch1;
  cout<<"Operand=";
  if(ch1=='n')  cin>>oprnd[j];
  cout<<"\n\n\tCONTINUE YOUR FUNCTION(y/n)?";
  cin>>ch;
  size++;
 }
 else
  break;
 }
  cout<<"\n\n\tYour Function=";
 for(i=0;i<size;i++)
 {
  if(oprtr1[i]=='\0') oprtr1[i]=' ';
  if(oprtr2[i]=='\0') oprtr2[i]=' ';
  if(oprnd[i]=='\0')  oprnd[i]=' ';
 }
 for(i=0;i<size;i++)
  cout<<oprtr1[i]<<coff[i]<<oprtr2[i]<<oprnd[i];
/* for(i=0;i<size;i++)
 {
  oprtr1+

*/  cout<<"\n\n\n\n\t\t\tPlease Wait Differentiating...";
  delay(3000);
  clrscr();
  load();
  cleardevice();
  setbkcolor(BLACK);
  cout<<"\n\n\t\t";

}
void integ()
{
}
void about()
{
 int i,j;
  border();
  setbkcolor(WHITE);
  settextstyle(DEFAULT_FONT,0,1);
  setcolor(RED);
  outtextxy(90,50,"Software                                           Creater");
  setcolor(BLUE);
 for(i=1;i<5;i++)  rectangle(80-2*i,50-2*i,570-2*i,70-2*i);
  line(320,45,320,getmaxy()-120);
  line(323,45,323,getmaxy()-120);
  line(80,50,80,getmaxy()-120);
  line(570,50,570,getmaxy()-120);
  line(78,getmaxy()-120,570,getmaxy()-120);
  line(78,getmaxy()-117,570,getmaxy()-117);
  setcolor(BLUE);
  outtextxy(81,90," >>Easy and Graphics Oriented. >>Name:Vishal Aditya(creater)");
  outtextxy(81,110," >>Userfriendly.               >>B.Tech-CSE(AMITY UNIVERSITY)");
  outtextxy(81,130," >>Muti-Window Software.       >>Work:Programming N Coding");
  outtextxy(81,150," >>Less Errors(Files not used) >>Design and Create Objects");
  outtextxy(81,170," >>Less compilation time.      >>Working on Strange things");
  outtextxy(81,190," >>Faster execution.           >>Thinking like different");
  outtextxy(81,210," >>Usefull help menus.         >>Discovering what's N how's");
  outtextxy(81,230," >>Important info's.           >>Exploring new Technologies");
  outtextxy(81,250," >>Proper oriented program.    >>Searching Ques? N Ans!");
  outtextxy(81,270," >>Highlighted sections.       >>Experimenting on concepts.");
  outtextxy(81,290," >>Various embeded colors.     >>Lastly,i always goto ALL.");
  setcolor(RED);
  outtextxy(81,330,"                                              (@_@) (*_*)");
  outtextxy(60,400,"CONTACT:-");
  line(59,410,117,410);
  line(59,411,120,411);
  outtextxy(60,420,"EMAIL:");
  outtextxy(60,430,"MOB:");
  setcolor(BLUE);
  outtextxy(60,420,"       er.vishaladitya.tech@gmail.com");
  outtextxy(60,430,"       +919828614330");
  outtextxy(390,440,"Press ANY KEY to go BACK...");
  getch();
  load();
  home();

}