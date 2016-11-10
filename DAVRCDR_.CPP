
 /*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
   ||      Name:- Vishal Aditya		   Mob.:-9576103956	           ||
   ||                                                                      ||
   ||      Class:- XII'C'		   Email:-adityavishal.16@gmail.com||
   ||                                                                      ||
   ||      Class Roll:-70                                                  ||
   ||                                                                      ||
   ||      Board Roll:-                                                    ||
   ||                                                                      ||
   ||      School:-DAV Sr. Sec. Public School                              ||
   ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
									     */
 #include<iostream.h>
 #include<fstream.h>
 #include<conio.h>
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<dos.h>
 #include<graphics.h>
 class Control_Pannel
 {
  private:
   char admnam[25];
   char admeid[20];
   long admmob;
   char tpass[20];
  public:
   char admpass[25];
   void adm_input();
   void adm_output();
  }A;
  class Payment
  {
   private:
   float amnt;
   char mnth[13],omnth[13];
   int nmnth;
   int clas;
   char stream[25];
   public:
   int f_admno;
   int tcost1,tcost2,tcost3,tcost4,tcost5,tcost6;
   int cost11,cost12,cost13,cost14,cost15,cost16;
   int cost21,cost22,cost23,cost24,cost25,cost26;
   int cost31,cost32,cost33,cost34,cost35,cost36;
   int cost41,cost42,cost43,cost44,cost45,cost46;
   int cost51,cost52,cost53,cost54,cost55,cost56;
   void view_fee();
   void pay_fee();
  }F;
//********class{Control_Pannel}menu_input*********{Administrator.txt}*********
 void Control_Pannel::adm_input()
 {
  cout<<"Name: ";
  gets(admnam);
  cout<<"Email: ";
  gets(admeid);
  cout<<"Mobile No.: ";
  cin>>admmob;
  B:                   //goto label
  outtextxy(0,10,"Password: ");
  gets(admpass);
  outtextxy(0,30,"Confirm Password: ");
  gets(tpass);
  if(strcmp(admpass,tpass)!=0)
  {
   cout<<"\n";
   outtextxy(0,50,"Password not match!Renter password?");
   getch();
   goto B;
  }
 }
//********class{Control_Pannel}menu_output*********{Administrator.txt}*********
 void Control_Pannel::adm_output()
 {
  cout<<"Name: ";
  puts(admnam);
  cout<<"\nEmail: ";
  puts(admeid);
  cout<<"\nMobile No.: "<<admmob;
 }

 class Book                                     //For managing Book.txt
 {
  private:
   char bnam[25];
   int bid;
   char bathr[25];
   int bprice;
  public:
   void book_input();
   void book_output();
   int getbid(){return bid;}
  }B;                           //class Book!
//***********class{Book}menu_input+output************{Book.txt}***************
 void Book::book_input()
 {
  cout<<"Book name: ";
  gets(bnam);
  cout<<"Book id: ";
  cin>>bid;
  cout<<"Book author: ";
  gets(bathr);
  cout<<"Book price: ";
  cin>>bprice;
 }
 void Book::book_output()
 {
  cout<<"Book name: ";
  puts(bnam);
  cout<<"\nBook id: "<<bid;
  cout<<"\nBook author: ";
  puts(bathr);
  cout<<"\nBook price: "<<bprice;
 }

 class School:public Control_Pannel,public Book   //For Managing Admission.txt
 {
  public:
   char nam[25],fnam[25],mnam[25];
   char dob[11];
   int clas;
   int marks;
   char addr[50];
   float mobno;
   char eid[25];
   char gndr;
   char catgry[10];
   char bldgrp[3];
   char sub1[25],sub2[25];
   int admno;
   void process_admno();
   void view_admno();
 };           //class School!
 class Student:public School             //For Managing S_RECORDS.txt
 {
  private:
   char doadm[11];
   char oldschl[50],schladdr[50];
   int rclas;
   char rsub1[25],rsub2[25];
  public:
   char stream[25];
   void student_input();
   void update_s_input();
   void student_output();
   int returnclass(){return rclas;}
 }Y;            //class Student!
 class Teacher:public School             //For Managing T_RECORDS.txt
 {
  private:
   char doadm[11];
   char stream[25];
   int expyr;
   char qualfns[50];
   int r1clas;
   char r1sub1[25],r1sub2[25];
  public:
   void teacher_input();
   void update_t_input();
   void teacher_output();
  }Z;           //class Teachers!

//***********class{School}menu_input***********{Records.txt}******************

  void School::process_admno()
  {
   ifstream fin;
   ofstream fout;
   int o_admno=1;
   fin.open("P_ADMNO.txt",ios::in|ios::app);
   fin.seekg(0);
   fin>>o_admno;
   admno=o_admno;
   fin.close();
   fout.open("P_ADMNO.txt",ios::out|ios::trunc);
   fout<<o_admno+1;
   fout.close();
  }
  void School::view_admno()
  {
   ifstream fin;
   int o_admno=1;
   fin.open("P_ADMNO.txt",ios::in|ios::app);
   fin.seekg(0);
   fin>>o_admno;
   admno=o_admno-1;
   fin.close();
  }

//******class{Student}menu_input*********{RECORDS.txt}************************
  void Student::student_input()
  {
   cout<<"Name: ";
   gets(nam);
   cout<<"Father's name: ";
   gets(fnam);
   cout<<"Mother's name: ";
   gets(mnam);
   cout<<"Date of birth(dd/mm/yyyy): ";
   gets(dob);
   cout<<"Class: ";
   cin>>clas;
   cout<<"Marks: ";
   cin>>marks;
   cout<<"Your address: ";
   gets(addr);
   cout<<"Mobile number: ";
   cin>>mobno;
   cout<<"Email id: ";
   gets(eid);
   cout<<"Gender: ";
   cin>>gndr;
   cout<<"Category(General/OBC/SC-ST):";
   gets(catgry);
   cout<<"Blood group: ";
   gets(bldgrp);
   cout<<"Date of admission: ";
   gets(doadm);
   cout<<"Seeking admission in class(For LKG & UKG enter 13 & 14): ";
   cin>>rclas;
   if(rclas==11||rclas==12)
   {
    cout<<"Previous school: ";
    gets(oldschl);
    cout<<"Address of previous school: ";
    gets(schladdr);
   if(rclas==11)
   {
    cout<<"Stream:-";
    cout<<"\n1.Science(Maths)   2.Science(Biology)   3.Commerce\n";
    char ch;
    cin>>ch;
    switch(ch)
     {
      case'1':
	strcpy(stream,"Science");
	cout<<"Compulsory subjects:-";
	cout<<"\n*******************";
	cout<<"\n1.English    2.Physics\n";
	cout<<"\n3.Chemistry  4.Maths\n";
	break;
      case'2':
	strcpy(stream,"Science");
	cout<<"Compulsory subjects:-";
	cout<<"\n*******************";
	cout<<"\n1.English    2.Physics\n";
	cout<<"\n3.Chemistry  4.Biology\n";
	break;
      case'3':
	strcpy(stream,"Commerce");
	cout<<"Compulsory subjects:-";
	cout<<"\n*******************";
	cout<<"\n1.English    2.Accountancy\n";
	cout<<"\n3.B.s.t      4.Economics\n";
	break;
      default:
	cout<<"Invalid entry!";
     }           //switch!
    }            //else if(clas)!
    cout<<"\nOptional Subjects:-\n";
    cout<<"*******************\n";
    cout<<"1.Computer Science    2.I.P       3.Economics\n";
    cout<<"4.Painting            5.PHE       6.Hindi\n";
    cout<<"Subject1=";
    gets(rsub1);
    cout<<"Subject2=";
    gets(rsub2);
   }
   process_admno();
  }                                   //student_input()!
  void Student::update_s_input()
  {
   cout<<"Name: ";
   gets(nam);
   cout<<"Father's name: ";
   gets(fnam);
   cout<<"Mother's name: ";
   gets(mnam);
   cout<<"Date of birth(dd/mm/yyyy): ";
   gets(dob);
   cout<<"Class: ";
   cin>>clas;
   cout<<"Marks: ";
   cin>>marks;
   cout<<"Your address: ";
   gets(addr);
   cout<<"Mobile number: ";
   cin>>mobno;
   cout<<"Email id: ";
   gets(eid);
    cout<<"\nOptional Subjects:-\n";
    cout<<"*******************\n";
    cout<<"1.Computer Science    2.I.P       3.Economics\n";
    cout<<"4.Painting            5.PHE       6.Hindi\n";
    cout<<"Subject1=";
    gets(rsub1);
    cout<<"Subject2=";
    gets(rsub2);
   view_admno();
  }                                //update_s_input()!

//******class{Teacher}menu_input********{RECORDS.txt}***********************

  void Teacher::teacher_input()
  {
   cout<<"Name: ";
   gets(nam);
   cout<<"Father's name: ";
   gets(fnam);
   cout<<"Mother's name: ";
   gets(mnam);
   cout<<"Date of birth(dd/mm/yyyy): ";
   gets(dob);
   cout<<"Class teacher of class: ";
   cin>>clas;
   cout<<"Marks(of further qualifications): ";
   cin>>marks;
   cout<<"Your address: ";
   gets(addr);
   cout<<"Mobile number: ";
   cin>>mobno;
   cout<<"Email id: ";
   gets(eid);
   cout<<"Gender: ";
   cin>>gndr;
   cout<<"Category(General/OBC/SC-ST):";
   gets(catgry);
   cout<<"Blood group: ";
   gets(bldgrp);
   cout<<"Date of admission: ";
   gets(doadm);
   cout<<"Seeking to teach in class(For LKG & UKG enter 13 & 14): ";
   cin>>r1clas;
   if((r1clas==11)||(r1clas==12))
   {
   cout<<"Your stream:-";
   cout<<"\n1.Science(Maths)   2.Science(Biology)   3.Commerce\n";
   gets(stream);
   }
   cout<<"Work experience(in years): ";
   cin>>expyr;
   cout<<"Qualifications: ";
   gets(qualfns);
   cout<<"Speciality in subjects(any two):-\n";
   cout<<"Subject 1:";
   gets(r1sub1);
   cout<<"Subject 1:";
   gets(r1sub2);
  }                               //teacher_input()!
  void Teacher::update_t_input()
  {
   cout<<"Name: ";
   gets(nam);
   cout<<"Father's name: ";
   gets(fnam);
   cout<<"Mother's name: ";
   gets(mnam);
   cout<<"Date of birth(dd/mm/yyyy): ";
   gets(dob);
   cout<<"Class: ";
   cin>>clas;
   cout<<"Marks: ";
   cin>>marks;
   cout<<"Your address: ";
   gets(addr);
   cout<<"Mobile number: ";
   cin>>mobno;
   cout<<"Email id: ";
   gets(eid);
    cout<<"\nOptional Subjects:-\n";
    cout<<"*******************\n";
    cout<<"1.Computer Science    2.I.P       3.Economics\n";
    cout<<"4.Painting            5.PHE       6.Hindi\n";
    cout<<"Subject1=";
    gets(r1sub1);
    cout<<"Subject2=";
    gets(r1sub2);
   view_admno();
  }                                //update_t_input()!
//******class{Student}menu_output********{RECORDS.txt}**********************

 void Student::student_output()
  {
   cout<<"Name: "<<nam;
   cout<<"\nFather's name: "<<fnam;
   cout<<"\nMother's name: "<<mnam;
   cout<<"\nDate of birth(dd/mm/yyyy): "<<dob;
   cout<<"\nClass: "<<clas;
   cout<<"\nMarks: "<<marks;
   cout<<"\nYour address: "<<addr;
   cout<<"\nMobile number: "<<mobno;
   cout<<"\nEmail id: "<<eid;
   cout<<"\nBlood group: "<<bldgrp;
   cout<<"\nGender: "<<gndr;
   cout<<"\nCategory(General/OBC/SC-ST):"<<catgry;
   cout<<"\nDate of admission: "<<doadm;
   cout<<"\nSeeking admission in class(For LKG & UKG enter 13 & 14: "<<rclas;
    if(rclas==11||rclas==12)
    {
    cout<<"\nPrevious school: "<<oldschl;
    cout<<"\nAddress of school: "<<schladdr;
    }
    if(rclas==11||rclas==12)
     {
      cout<<"\nStream: "<<stream;
      cout<<"\nOptional Subjects:-\n";
      cout<<"Subject1="<<rsub1;
      cout<<"\nSubject2="<<rsub2;
      }         //if(clas)!
  }                                   //student_output()!

//******class{Teacher}menu_output********{T_RECORDS.txt}**********************

  void Teacher::teacher_output()
  {
   cout<<"Name: "<<nam;
   cout<<"\nFather's name: "<<fnam;
   cout<<"\nMother's name: "<<mnam;
   cout<<"\nDate of birth(dd/mm/yyyy): "<<dob;
   cout<<"\nClass teacher of class: "<<clas;
   cout<<"\nMarks(in further qualifications): "<<marks;
   cout<<"\nYour address: "<<addr;
   cout<<"\nMobile number: "<<mobno;
   cout<<"\nEmail id: "<<eid;
   cout<<"\nGender(M/F): "<<gndr;
   cout<<"\nBlood group: "<<bldgrp;
   cout<<"\nCategory(General/OBC/SC-ST):"<<catgry;
   cout<<"\nDate of admission: "<<doadm;
   cout<<"\nSeeking to teach in class(For LKG & UKG enter 13 & 14): "<<r1clas;
   cout<<"\nQualifications in stream: "<<stream;
   cout<<"\nWork experience(in years):"<<expyr;
   cout<<"\nQualifications: "<<qualfns;
   cout<<"\nSpeciality in subjects(any two):-\n";
   cout<<"Subject 1:"<<r1sub1;
   cout<<"\nSubject 1:"<<r1sub2;
  }                               //teacher_output()!

//******class{Student}menu_Fee-Section********{Fees.txt}**********************

 void Payment::pay_fee()
 {
  char temp[13],ch;
  cout<<"Months(J,F,M,...D): ";
  gets(mnth);
  strcpy(omnth,mnth);
  nmnth=sizeof(mnth)-1;
  clas=Y.returnclass();
  strcpy(stream,Y.stream);
  if(clas==13||clas==14)
  {
   cout<<"\nMonthly fee: "<<tcost1;
   cout<<"\nTotal fee: "<<nmnth*tcost1;
   cout<<"\nConfirm pay now(y/n)?";
   cin>>ch;
   if(ch=='y'||ch=='Y')
   {
    temp[0]=mnth[nmnth];
    strcpy(mnth,temp);
   }
  }
  else if(clas>=3||clas<=5)
  {
   cout<<"\nMonthly fee: "<<tcost2;
   cout<<"\nTotal fee: "<<nmnth*tcost2;
   cout<<"\nConfirm pay now(y/n)?";
   cin>>ch;
   if(ch=='y'||ch=='Y')
   {
    temp[0]=mnth[nmnth];
    strcpy(mnth,temp);
   }
  }
  else if(clas>=6||clas<=8)
  {
   cout<<"\nMonthly fee: "<<tcost3;
   cout<<"\nTotal fee: "<<nmnth*tcost3;
   cout<<"\nConfirm pay now(y/n)?";
   cin>>ch;
   if(ch=='y'||ch=='Y')
   {
    temp[0]=mnth[nmnth];
    strcpy(mnth,temp);
   }
  }
  else if(clas>=9||clas<=10)
  {
   cout<<"\nMonthly fee: "<<tcost4;
   cout<<"\nTotal fee: "<<nmnth*tcost4;
   cout<<"\nConfirm pay now(y/n)?";
   cin>>ch;
   if(ch=='y'||ch=='Y')
   {
    temp[0]=mnth[nmnth];
    strcpy(mnth,temp);
   }
  }
  else if(clas>=11||clas<=12)
  {
   if(stream=="Science")
   {
    cout<<"\nMonthly fee: 1630";
    cout<<"\nTotal fee: "<<nmnth*1630;
    cout<<"\nConfirm pay now(y/n)?";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
     temp[0]=mnth[nmnth];
     strcpy(mnth,temp);
    }
   }
   else if(stream=="Commerce")
   {
    cout<<"\nMonthly fee: 1530";
    cout<<"\nTotal fee: "<<nmnth*1530;
    cout<<"\nconfirm pay now(y/n)?";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
     temp[0]=mnth[nmnth];
     strcpy(mnth,temp);
    }
   }
  }
  else
   cout<<"\nInvalid Entry!";
 }                         //pay_fee()!
 void Payment::view_fee()
 {
  cout<<"Admission no: "<<f_admno;
  char temp[13],ch;
  cout<<"Paid Months(J,F,M,...D): ";
  puts(omnth);
 }

//***************************{Managing_Functions}*****************************

//*****************************{Prototypes}***********************************
//                                                     Coordinates
  void clock();                                    // 758:3
  void control_panel();                            // 744:3
  void update_fees();                              //1028:3
  void admission();                                //1721:3
  void records();                                  //1790:3
  void fees();                                     //2096:3
  void book();                                     //1160:3
  void help();                                     //1336:3
  void update();                                   //1531:3
  void feedback();                                 //2231:3
  void creater();                                  //1611:3
//**********************************{Body}**********************************
void Design()
{
 clrscr();
 int gd=DETECT,gm,i=24,j=20;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 setbkcolor(14);
 setcolor(BLUE);
 rectangle(1,1,getmaxx()-1,getmaxy()-1);
 rectangle(2,2,getmaxx()-2,getmaxy()-2);
 rectangle(3,3,getmaxx()-3,getmaxy()-3);
 rectangle(4,4,getmaxx()-4,getmaxy()-4);
 rectangle(5,5,getmaxx()-5,getmaxy()-5);
 rectangle(6,6,getmaxx()-6,getmaxy()-6);
 rectangle(7,7,getmaxx()-7,getmaxy()-7);
 rectangle(208,10,365,23);
 setcolor(RED);
 settextstyle(SMALL_FONT,HORIZ_DIR,4);
 outtextxy(210,10,"Davrecord_Manager(ver.1.0)");
 setcolor(RED);
 settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
 outtextxy(70,14,"Dav Sr. Sec. Public School");
 setcolor(BLUE);
 setlinestyle(DOTTED_LINE,1,1);
 line(570,70,70,70);
 line(570,73,70,73);
 setcolor(CYAN);
 while(i!=0)
 {i--;i--;
 circle(150,130,i); circle(450,130,i);
 delay(200);
 }
 setcolor(RED);
 settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
 outtextxy(240,100,"!Bariatu!");
 setcolor(BLUE);
 setlinestyle(DASHED_LINE,1,1);
 line(379,150,250,150);
 line(379,153,250,153);
 setcolor(CYAN);
 i=50;j=190;
 while(i>=40&&j>=180)
 {--i;--i;--i;--j;--j;--j;
 ellipse(320,235,0,360,j,i);
 delay(200);
 }
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 setcolor(CYAN);
 outtextxy(535,460,"@programming");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 setcolor(BLUE);
 outtextxy(15,400,"Creater:-");
 setcolor(RED);
 outtextxy(25,430,"Vishal");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
 outtextxy(190,218,"Press any key to continue !");
 settextstyle(DEFAULT_FONT,0,2);
 getch();
}
  void Home()
  {
   clrscr();
   int gd=DETECT,gm,i;
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   char ch;
   setbkcolor(WHITE);
   setcolor(RED);
   outtextxy(10,10,"View Clock(@)?");
   for(i=1;i<3;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   setcolor(CYAN);
   for(i=5;i<8;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   setcolor(RED);
   setcolor(CYAN);setlinestyle(DOTTED_LINE,1,3);
   line(355,20,235,20);line(355,20,355,70);line(235,20,235,70);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);setcolor(RED);
   outtextxy(250,35,"Home");
   setcolor(CYAN);line(355,70,235,70);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
   setlinestyle(DASHED_LINE,1,2);
   rectangle(385,95,190,125); setcolor(RED);
   outtextxy(210,100,"Control Panel(*)");
   for(i=1;i<5;i++)
   {setcolor(3*i);
    ellipse(100,190,0,360,60+3*i,20+3*i);
    ellipse(550,190,0,360,60+3*i,20+3*i);
    ellipse(100,270,0,360,60+3*i,20+3*i);
    ellipse(550,270,0,360,60+3*i,20+3*i);
    ellipse(100,350,0,360,60+3*i,20+3*i);
    ellipse(550,350,0,360,60+3*i,20+3*i);
    ellipse(100,430,0,360,60+3*i,20+3*i);
    ellipse(550,430,0,360,60+3*i,20+3*i);
   }
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   setcolor(RED);
   outtextxy(55,192,"1}Addmission");        outtextxy(510,192,"2}Records");
   outtextxy(55,267,"3}Fees");              outtextxy(510,267,"4}Help");
   outtextxy(55,342,"5}Update");            outtextxy(510,342,"6}Feedback");
   outtextxy(52,422,"7}Books Library");     outtextxy(510,422,"8}Creater");
   for(i=1;i<5;i++)
   {
   setcolor(3*i);
   circle(305,225,83-3*i);
   }
   setcolor(BLUE);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(236,220,"Choice(@/*/1../8)?");
   cin>>ch;
    switch(ch)
    {
     case'@':
      cleardevice();
      setbkcolor(BLACK);
      gotoxy(0,0);
      clock();
      break;
     case'*':
      cleardevice();
      setbkcolor(BLACK);
      gotoxy(0,0);
      control_panel();
      break;
     case'1':
      cleardevice();
      setbkcolor(BLACK);
      gotoxy(0,0);
      admission();
      break;
     case'2':
      cleardevice();
      setbkcolor(BLACK);
      gotoxy(0,0);
      records();
      break;
     case'3':
      cleardevice();
      setbkcolor(BLACK);
      gotoxy(0,0);
      fees();
      break;
     case'4':
      cleardevice();
      setbkcolor(BLACK);
      gotoxy(0,0);
      help();
      break;
     case'5':
      char pass[25];
      cleardevice();
      setbkcolor(RED);
      ifstream f;
      char found;
      f.open("Administrator.txt",ios::out|ios::binary);
      gotoxy(0,0);
      cout<<"This menu is confidential so please enter administrator password";
      cout<<"to proceed!\n\n";
      char ch;
      cout<<"1}Enter Password                          2}Help\n" ;
      cin>>ch;
      if(ch=='1')
      {
	cout<<"\nAdmininstrator Password: ";
	gets(pass);
	while(!f.eof())
	{
	 f.read((char*)&A,sizeof(A));
	 if(strcmp(A.admpass,pass)==0)
	  {
	   cleardevice();
	   update();
	   found='y';
	   break;
	  }
	}              //while(eof)!
	 if(found!='y')
	    cout<<"\nInvalid Password!";
	f.close();
      }               //if(ch)!
      else if(ch=='2')
      {
       cleardevice();
       help();
      }
      else
       cout<<"\nInvalid entry!";
      break;
     case'6':
      cleardevice();
      setbkcolor(BLACK);
      gotoxy(0,0);
      feedback();
      break;
     case'7':
      cleardevice();
      book();
      break;
     case'8':
      cleardevice();
      creater();
      break;
     default:
      cout<<"Invalid Entry!";
    }          //switch1!
    getch();
    closegraph();
  }                      //Home()!
  void clock()
  {
   struct dostime_t t;
   _dos_gettime(&t);
   printf("CLOCK=%2d:%02d:%02d\n", t.hour, t.minute, t.second);
  struct dosdate_t d;
  _dos_getdate(&d);
  printf("Day: %d\n", d.day);
  printf("Month: %d\n", d.month);
  printf("Year: %d\n", d.year);
   cout<<"\nWant to go home menu(y/n)";
   char ch5;
   ch5=getch();
   if(ch5=='y')
    Home();
  }                       //clock()!
  void control_panel()
  {
   fstream f;
   f.open("Administrator.txt",ios::in|ios::out|ios::binary);
   char ch;
   setbkcolor(WHITE);
   setcolor(RED);
   for(int i=1;i<3;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   setcolor(CYAN);
   for(i=5;i<8;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   for(i=1;i<5;i++)
   {
    setcolor(8);
    rectangle(400-2*i,20-2*i,190-2*i,50-2*i);
   }
   settextstyle(DEFAULT_FONT,0,2); setcolor(RED);
   outtextxy(190,25,"Control Panel");
   settextstyle(DEFAULT_FONT,0,1); setcolor(BLUE);
   for(i=1;i<5;i++)
   {
    setcolor(3*i);
    ellipse(150,100,0,360,110+3*i,25+3*i);
    ellipse(500,100,0,360,110+3*i,25+3*i);
   }
   setcolor(RED);
   outtextxy(55,95,"1.}Administrator Settings");
   outtextxy(420,95,"2.}Update Software");
   for(i=1;i<5;i++)
   {
   setcolor(CYAN);
   circle(305,225,63-3*i);
   }
   setcolor(BLUE);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(256,220,"Choice(1/2)?");
   cin>>ch;
   if(ch=='1')
   {
     cleardevice();
     setbkcolor(CYAN);
     for(i=1;i<5;i++)
     {
     setcolor(3*i);
     ellipse(330,50,0,360,190+3*i,25+3*i);
     }
     setcolor(RED);settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
     outtextxy(165,45,"Administrator Settings");
     settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
     outtextxy(70,150,"1}Add");
     outtextxy(250,150,"2}View");
     outtextxy(380,150,"3}Update");
     setcolor(BLUE);
     for(i=1;i<5;i++)
     {
      setcolor(2*i);
      circle(305,225,63-3*i);
     }
     char ch1,ch2;
     settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
     outtextxy(256,220,"Choice(1/2/3)?");
     cin>>ch1;
     switch(ch1)
     {
      case'1':
       setcolor(RED);settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
       outtextxy(165,45,"Add Administrator");
       outtextxy(256,220,"Press any key to enter data");
       cleardevice();
       setbkcolor(BLACK);
       A.adm_input();
       f.write((char*)&A,sizeof(A));
       cout<<"\n\n\t\tCongratulations you are sucessfully administrator!";
       cout<<"\n\t\tTo view your password goto Control Panel-1}Adm. Settings";
       cout<<"\t\t-2}View";
       A:                                        //goto label
       cout<<"\n\n\t\tPress (*/@) for Control Panel or Home";
       cin>>ch2;
       if(ch2=='*')
       {
	cleardevice();
	control_panel();
	}
       else if(ch2=='@')
       {
	cleardevice();
	Home();
       }
       else
       {
	cout<<"\n\tInvalid Entry?Try again!";
	goto A;
       }
       break;
      case'2':
       setcolor(RED);settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
       outtextxy(165,45,"View Administrator");
       outtextxy(256,220,"Press any key to view data");
       cleardevice();
       setbkcolor(BLACK);
	 f.read((char*)&A,sizeof(A));
	 A.adm_output();
       break;
      case'3':
       cleardevice();
       char found;
       setcolor(RED);settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
       outtextxy(165,45,"Update Administrator");
       outtextxy(256,220,"Press any key to update data");
       cleardevice();
       setbkcolor(BLACK);
       gotoxy(0,0);
       cout<<"\n\n\nInitial password: ";
       char tempass[25];
       gets(tempass);
       int pos;
       while(!f.eof())
       {
	pos=f.tellg();
	f.read((char*)&A,sizeof(A));
	if(strcmp((A.admpass),tempass)==0)
	{
	 A.adm_output();
	 cout<<"\nWant to change?(y/n)";
	 char ch3;
	 cin>>ch3;
	 if(ch3=='y')
	 {
	 clrscr();
	 A.adm_input();
	 f.seekg(pos);
	 f.write((char*)&A,sizeof(A));
	 cout<<"\nCongrats update succeded!";
	 found='1';
	 break;
	}
       }                        //while(eof)!
	 }
       if(found!='1')
	cout<<"\nInvalid admission no.!";
       f.close();
	 A1:
	 cout<<"\n\n\t\tPress (*/@) for Control Panel or Home";
	 cin>>ch2;
	 if(ch2=='*')
	 {
	  cleardevice();
	  control_panel();
	 }
	 else if(ch2=='@')
	 {
	  cleardevice();
	  Home();
	 }
	 else
	 {
	  cout<<"\n\tInvalid Entry?Try again!";
	  goto A1;
	 }
	break;
      default:
	cout<<"\nInvalid Entry!";
     }                 //switch(ch1)!
    }                 //if(ch)!
    else if(ch=='2')
    {
     cleardevice();
     setbkcolor(CYAN);
     for(i=1;i<5;i++)
     {
     setcolor(3*i);
     ellipse(330,50,0,360,190+3*i,25+3*i);
     }
     setcolor(RED);settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
     outtextxy(165,45,"Update Software");
     settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
     outtextxy(70,150,"1}Fees");
     outtextxy(250,150,"2}Books Library");
     setcolor(BLUE);
     for(i=1;i<5;i++)
     {
      setcolor(2*i);
      circle(305,225,63-3*i);
     }
     char ch3;
     settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
     outtextxy(256,220,"Choice(1/2)?");
     cin>>ch3;
     switch(ch3)
     {
      case'1':
       char ch2;
       cleardevice();
       setbkcolor(BLACK);
       gotoxy(0,0);
       update_fees();
       cout<<"\nCongrats fees_update succeded!";
       A2:
	 cout<<"\n\n\t\tPress (*/@) for Control Panel or Home";
	 cin>>ch2;
	 if(ch2=='*')
	 {
	  cleardevice();
	  control_panel();
	 }
	 else if(ch2=='@')
	 {
	  cleardevice();
	  Home();
	 }
	 else
	 {
	  cout<<"\n\tInvalid Entry?Try again!";
	  goto A2;
	 }
       break;
      case'2':
       cleardevice();
       setbkcolor(BLACK);
       gotoxy(0,0);
       book();
	A3:
	 cout<<"\n\n\t\tPress (*/@) for Control Panel or Home";
	 cin>>ch2;
	 if(ch2=='*')
	 {clrscr();
	  cleardevice();
	  control_panel();
	 }
	 else if(ch2=='@')
	 {clrscr();
	  cleardevice();
	  Home();
	 }
	 else
	 {
	  cout<<"\n\tInvalid Entry?Try again!";
	  goto A3;
	 }
       break;
      default:
       cout<<"\nInvalid Entry!";
      }                     //switch(ch3)!
    }                       //elseif(ch2)!
    else
     cout<<"\nInvalid entry!";
   cout<<"\nWant to go home menu(y/n)";
   char ch5;
   ch5=getch();
   if(ch5=='y')
    Home();

  }                    //control_panel()!
  void update_fees()
  {
   fstream f("Fees.txt",ios::in|ios::out|ios::binary);
   f.seekg(0);
   setbkcolor(CYAN);
   for(int i=1;i<5;i++)
   {
   setcolor(3*i);
   ellipse(330,50,0,360,190+3*i,25+3*i);
   }
   setcolor(RED);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(165,45,"Update Fees");
   cout<<"\n\n\n\n\n\tClass(for LKG&UKG-13&14: ";
   int clas;
   cin>>clas;
   if(clas==13||clas==14||clas==1||clas==2)
   {
    clrscr();
    setbkcolor(RED);
    gotoxy(0,0);
    cout<<"Tuition Fee: ";
    cin>>F.cost11;
    cout<<"Examination Fee: ";
    cin>>F.cost21;
    cout<<"Computer Fee: ";
    cin>>F.cost31;
    cout<<"Science Fee: ";
    cin>>F.cost41;
    cout<<"Transport Fee: ";
    cin>>F.cost51;
    F.tcost1=F.cost11+F.cost21+F.cost31+F.cost41+F.cost51;
    cout<<"Total Fee: "<<F.tcost1;
   }
   else if(clas>=3||clas<=5)
   {
    clrscr();
    setbkcolor(RED);
    gotoxy(0,0);
    cout<<"Tuition Fee: ";
    cin>>F.cost12;
    cout<<"Examination Fee: ";
    cin>>F.cost22;
    cout<<"Computer Fee: ";
    cin>>F.cost32;
    cout<<"Science Fee: ";
    cin>>F.cost42;
    cout<<"Transport Fee: ";
    cin>>F.cost52;
    F.tcost2=F.cost12+F.cost22+F.cost32+F.cost42+F.cost52;
    cout<<"Total Fee: "<<F.tcost2;
   }
   else if(clas>=6||clas<=8)
   {
    clrscr();
    setbkcolor(RED);
    gotoxy(0,0);
    cout<<"Tuition Fee: ";
    cin>>F.cost13;
    cout<<"Examination Fee: ";
    cin>>F.cost23;
    cout<<"Computer Fee: ";
    cin>>F.cost33;
    cout<<"Science Fee: ";
    cin>>F.cost43;
    cout<<"Transport Fee: ";
    cin>>F.cost53;
    F.tcost3=F.cost13+F.cost23+F.cost33+F.cost43+F.cost53;
    cout<<"Total Fee: "<<F.tcost3;
   }
   else if(clas>=9||clas<=10)
   {
    clrscr();
    setbkcolor(RED);
    gotoxy(0,0);
    cout<<"Tuition Fee: ";
    cin>>F.cost14;
    cout<<"Examination Fee: ";
    cin>>F.cost24;
    cout<<"Computer Fee: ";
    cin>>F.cost34;
    cout<<"Science Fee: ";
    cin>>F.cost44;
    cout<<"Transport Fee: ";
    cin>>F.cost54;
    F.tcost4=F.cost14+F.cost24+F.cost34+F.cost44+F.cost54;
    cout<<"Total Fee: "<<F.tcost4;
   }
   else if(clas==11||clas==12)
   {
    clrscr();
    setbkcolor(RED);
    gotoxy(0,0);
    char stream[25];
    cout<<"Stream: ";
    gets(stream);
    if(strcmp(stream,"Science")==0)
    {
    cout<<"Tuition Fee: ";
    cin>>F.cost15;
    cout<<"Examination Fee: ";
    cin>>F.cost25;
    cout<<"Computer Fee: ";
    cin>>F.cost35;
    cout<<"Science Fee: ";
    cin>>F.cost45;
    cout<<"Transport Fee: ";
    cin>>F.cost55;
    F.tcost5=F.cost15+F.cost25+F.cost35+F.cost45+F.cost55;
    cout<<"Total Fee: "<<F.tcost5;
    }
    else if(strcmp(stream,"Commerce")==0)
    {
    cout<<"Tuition Fee: ";
    cin>>F.cost16;
    cout<<"Examination Fee: ";
    cin>>F.cost26;
    cout<<"Computer Fee: ";
    cin>>F.cost36;
    cout<<"Science Fee: ";
    cin>>F.cost46;
    cout<<"Transport Fee: ";
    cin>>F.cost56;
    F.tcost6=F.cost16+F.cost26+F.cost36+F.cost46+F.cost56;
    cout<<"Total Fee: "<<F.tcost6;
    }
   }
   else
    cout<<"\nInvalid Entry!";
   f.write((char*)&F,sizeof(F));
   f.close();
  }                       //update_fees()!
  void book()
  {
     fstream f;
     f.open("Book.txt",ios::in|ios::out|ios::app|ios::binary);
   char ch,ch1,ch2,found;
   setbkcolor(WHITE);
   setcolor(RED);
   for(int i=1;i<3;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   setcolor(CYAN);
   for(i=5;i<8;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   for(i=1;i<5;i++)
   {
    setcolor(8);
    rectangle(400-2*i,20-2*i,190-2*i,50-2*i);
   }
   settextstyle(DEFAULT_FONT,0,2); setcolor(RED);
   outtextxy(190,25,"Books Library");
   settextstyle(DEFAULT_FONT,0,1); setcolor(BLUE);
   for(i=1;i<5;i++)
   {
    setcolor(3*i);
    ellipse(150,100,0,360,90+3*i,25+3*i);
    ellipse(500,100,0,360,90+3*i,25+3*i);
    ellipse(150,300,0,360,90+3*i,25+3*i);
    ellipse(500,300,0,360,90+3*i,25+3*i);
   }
   setcolor(RED);
   outtextxy(80,95,"1}Add");
   outtextxy(430,95,"2}View");
   outtextxy(80,295,"3}Purchase");
   outtextxy(430,295,"4}Update");
   for(i=1;i<5;i++)
   {
      setcolor(3*i);
      rectangle(400-2*i,240-2*i,250-2*i,220-2*i);
   }
   setcolor(RED);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(250,220,"Choice(@/1/2/3/4)?");
   cin>>ch1;
   switch(ch1)
   {
    case'@':
     cleardevice();
     Home();
     break;
    case'1':
     clrscr();
     cleardevice();
     setbkcolor(BLACK);
     gotoxy(0,0);
     ofstream fin;
     fin.open("Book.txt",ios::in|ios::app|ios::binary);
     ch='y';
     while(ch=='y')
     {
     B.book_input();
     fin.write((char*)&B,sizeof(B));
     cout<<"\n\n\t\tWant to enter more(y/n)?";
     ch=getch();
     clrscr();
     cleardevice();
     gotoxy(0,0);
     if(ch=='n')
      break;
     }
     fin.close();
     break;

    case'2':
     clrscr();
     cleardevice();
     setbkcolor(BLACK);
     gotoxy(0,0);
     ifstream fout;
     fout.open("Book.txt",ios::out|ios::app|ios::binary);
     ch='y';
     while(ch=='y')
     {
     fout.read((char*)&B,sizeof(B));
     B.book_output();
     cout<<"\n\n\t\tWant to view more(y/n)?";
     ch=getch();
     clrscr();
     cleardevice();
     gotoxy(0,0);
     if(ch=='n')
      break;
     }                 //while(ch)!
     fout.close();
     break;
    case'3':
     clrscr();
     cleardevice();
     setbkcolor(WHITE);gotoxy(0,0);
     for(int i=1;i<3;i++)
      rectangle(i,i,getmaxx()-(i),getmaxy()-i);
     setcolor(CYAN);
     for(i=5;i<8;i++)
      rectangle(i,i,getmaxx()-(i),getmaxy()-i);
     for(i=1;i<5;i++)
     {
     setcolor(8);
     rectangle(420-2*i,20-2*i,180-2*i,50-2*i);
     }
     settextstyle(DEFAULT_FONT,0,2); setcolor(RED);
     outtextxy(190,25,"Purchase Books");
     int prchseb_id,pos;
     char ch3='y';
     settextstyle(DEFAULT_FONT,0,1); setcolor(BLUE);
     outtextxy(200,150,"Press any key to continue");
     getch();
     cleardevice();
     setbkcolor(BLUE);
     while(ch3=='y')
     {
     cout<<"\n\n\n\n\tBook ID: ";
     cin>>prchseb_id;
     while(!f.eof())
     {
     f.read((char*)&B,sizeof(B));
     if(B.getbid()==prchseb_id)
     {
      cout<<"\n\tBook found!\n";
      B.book_output();
      cout<<"\n\tWant to purchase?(y/n)";
      ch2=getch();
      if(ch2=='y'||ch2=='Y')
      {
       cout<<"\n\tCongrats book sold!";
       break;
      }
     }            //if(check)!
     }             //while(eof)!
     f.seekg(0);     //to original pos
     cout<<"\n\n\t\tWant to buy more(y/n)?";
     ch3=getch();
     cleardevice();
     clrscr();
     gotoxy(0,0);
     setbkcolor(BLUE);
     if(ch3=='n')
      break;
    }                 //while(ch3)!
     break;
    case'4':
      cleardevice();
      setbkcolor(RED);
      int tempid;
      cout<<"Update books library:-\n";
     while(ch3=='y')
     {
      cout<<"\nBook id: ";
      cin>>tempid;
      while(!f.eof())
      {
       pos=f.tellg();
       f.read((char*)&B,sizeof(B));
       if(B.getbid()==tempid)
       {
	B.book_output();
	found='y';
	f.seekg(pos);
       cout<<"\nUpdate:-\n";
       B.book_input();
       f.write((char*)&B,sizeof(B));
       cout<<"\nCongrats book details updated!";
       break;
      }
      else
       {
	found='n';
	break;
       }
     }                //while(eof)!
     if(found=='n')
     {
       cout<<"\nInvalid admission no.!";
     }
     cout<<"\n\n\t\tWant to update more(y/n)?";
     cin>>ch3;
     clrscr();
     cleardevice();
     gotoxy(0,0);
     if(ch3=='n')
       break;
     }                //while(ch3)!
      break;
    default:
     cout<<"\nInvalid Entry!";
   }               //switch(ch1)!
   cleardevice();
   setbkcolor(BLUE);
   cout<<"\n\t\t\tWant to go home menu(y/n)";
   char ch5;
   cin>>ch5;
   if(ch5=='y')
    Home();
  }                //book()!
  void help()
  {
   clrscr();
   int gd=DETECT,gm,i;
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   setbkcolor(WHITE);
   setcolor(RED);
   for(i=1;i<3;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   setcolor(CYAN);
   for(i=5;i<8;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   for(i=1;i<5;i++)
   {
    setcolor(8);
    rectangle(400-2*i,20-2*i,190-2*i,50-2*i);
   }
   settextstyle(DEFAULT_FONT,0,2);
   setcolor(RED);
   outtextxy(250,25,"Help");
   settextstyle(DEFAULT_FONT,0,1);
   setcolor(BLUE);
   outtextxy(50,60,"This help menu contains important information about Dav_rcdr_manager.");
   outtextxy(50,85,"For the latest information and its accompanying programs and manuals,");
   outtextxy(50,105,"read this menu in its entirety.Follow all instructions strictly");
   setcolor(RED);
   outtextxy(50,150,"TABLE OF CONTENTS");
   outtextxy(50,155,"-----------------");
   setcolor(BLUE);
   outtextxy(50,175,"1}How to Get Help");
   outtextxy(50,195,"2}Installation");
   outtextxy(50,215,"3}Features");
   outtextxy(50,235,"4}Important Information");
   outtextxy(50,255,"5}Testing Your Expanded Memory");
   outtextxy(50,275,"6}CORRECTIONS TO THE ON-LINE HELP");
   outtextxy(50,295,"7}How to enter data");
   outtextxy(50,315,"8}How to manage administrator");
   for(i=1;i<5;i++)
   {
   setcolor(CYAN);
   rectangle(450-2*i,210-2*i,630-2*i,240-2*i);
   }
   setcolor(BLUE);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(456,220,"Choice(1/2/3/4/5/6/7/8)?");
   char ch;
   ch=getch();
   switch(ch)
   {
    case'1':
     clrscr();
     cleardevice();
     setbkcolor(BLACK);
     cout<<" 1. HOW TO GET HELP\n";
     cout<<" ------------------";
     cout<<"\n\n";
     cout<<"If you have any problems, please read this menu, the HELPME! and other files in your DOC subdirectory, and the Turbo C++ manuals first. If you still have a question and need";
     cout<<"assistance, help is available from the following sources:\n\n";
     cout<<"1. Check with your local software dealer or users' group.\n";
     cout<<"3. Borland's TECHFAX service. Call (800) 822-4269 for a FAX catalog of entries.\n";
     cout<<"4. If you have an urgent problem that cannot wait and you have sent in the license agreement that came with the package, you may call the Borland Technical Support Department at";
     cout<<"(408) 438-5300. Please have the following information ready before calling:\n";
     cout<<"\n a. Product name and serial number on your original distribution disk.  Please have your serial number ready or we will be unable to process your call.";
     cout<<"\nb. Product version number. The version number for TurboC++ can be displayed by pressing Alt-H/A.";
     cout<<"\nc. Computer brand, model, and the brands and model numbers of any additional hardware.";
     cout<<"\nd. Operating system and version number. (The version number can be determined by typing VER at the DOS prompt.)";
     cout<<"\ne. Contents of your DAV_RCDR_MANAGER.CPP file.";
     cout<<"\nf. Contents of your CONFIG.SYS file.";
     cout<<"\n\n\t\t\tPress any key for Help menu";
     getch();
     help();
     break;
    case'2':
     clrscr();
     cleardevice();
     setbkcolor(BLACK);
     cout<<" 2. Installation\n";
     cout<<" ---------------";
     cout<<"\n\nIMPORTANT!";
     cout<<" Must install Borland TurboC++ to compile cpp file\n";
     cout<<"\n\nIf you want to create backup copies of your disks, make sure";
     cout<<"that you put the backup on the same type of disk as the source.";
     cout<<" If you're backing up the 5 1/4 inch 1.2 Mb disk set, use only";
     cout<<" blank 5 1/4 inch 1.2 Mb disks for backup, etc. The installation";
     cout<<" will not work correctly if you do not use the same media type for the backup disks.";
     cout<<"\n\n\t\tCompile program and enjoy!";
     cout<<"\n\n\t\t\tPress any key for Help menu";
     getch();
     help();
     break;
    case'3':
     clrscr();
     cleardevice();
     setbkcolor(BLACK);
     cout<<"3. FEATURES\n";
     cout<<"-----------";
     cout<<"\n\nDAV_RCDR_MNGR(ver.1.0) includes big speed and capacity gains.Here are ";
     cout<<"some important features found in this version:\n";
     cout<<"- DPMI services for increased capacity\n";
     cout<<"- support, including the new nested class specifications,";
     cout<<"and support of C++ 3.0 templates.\n";
     cout<<"- Support for pre-compiled headers for substantial time savings";
     cout<<"during subsequent recompiles.\n";
     cout<<"- Color syntax highlighting\n";
     cout<<"- Unlimited Undo/Redo replacing previous 'restore line'";
     cout<<"capability\n";
     cout<<"- Added library functions for compatibility with other runtime";
     cout<<"libraries, and addition of support for long double parameters";
     cout<<"in math functions. (Please refer to On-line Help for details.)";
     cout<<"\n\n\t\t\twebsite:www.adityaprogramming.neatu.net\n";
     cout<<"- New MAKE features(Please see the MAKE chapter in the User's";
     cout<<"Guide for details).\n";
     cout<<"- Added BGI (Borland Graphics Interface) fonts and support.\n";
     cout<<"- A resident DPMI kernel program.\n";
     cout<<"\n\n\t\t\tPress any key for Help menu";
     getch();
     help();
     break;
    case'4':
     clrscr();
     cleardevice();
     setbkcolor(BLACK);
     cout<<"4. IMPORTANT INFORMATION\n";
     cout<<"------------------------";
     cout<<"\n\n- We recommend that you use the following mouse drivers with this product:\n";
     cout<<"\t\tMicrosoft Mouse version 7.04 or later;";
     cout<<"\n\t\tLogitech Mouse version 5.01 or later;";
     cout<<"\n\t\tGenius Mouse version 9.06 or later;";
     cout<<"\n\n\t\t\tPress any key for Help menu";
     getch();
     help();
     break;
    case'5':
     clrscr();
     setbkcolor(BLACK);
     cout<<"5. TESTING YOUR EXPANDED MEMORY:";
     cout<<"\n-------------------------------";
     cout<<"\n\nIncluded with Turbo C++ is a program to test your Expanded";
     cout<<"Memory hardware and software. If you have problems using Turbo C++";
     cout<<"with your EMS, type EMSTEST at the DOS prompt and follow the instructions.";
     cout<<"\n\n\t\t\tPress any key for Help menu";
     getch();
     help();
     break;
    case'6':
     clrscr();
     cleardevice();
     setbkcolor(BLACK);
     cout<<"6. CORRECTIONS TO THE ON-LINE HELP\n";
     cout<<"----------------------------------";
     cout<<"\n\nFor more assistance visit website:www.adityaprogramming.neatu.net";
     cout<<"\n\n\t\t\tPress any key for Help menu";
     getch();
     help();
     break;
    case'7':
     clrscr();
     cleardevice();
     setbkcolor(BLACK);
     cout<<"7. HOW TO ENTER DATA\n";
     cout<<"--------------------\n";
     cout<<"\n1.Somewhere only press key provided in the software";
     cout<<"\n2.Somewhere press key then press enter provided in the software";
     cout<<"\n3.In input menus enter all data with their original data type";
     cout<<"\n4.In case of currently deleted data relod program then view next data";
     cout<<"\n\n\t\t\tPress any key for Help menu";
     getch();
     help();
     break;
    case'8':
     clrscr();
     cleardevice();
     setbkcolor(BLACK);
     cout<<"8. HOW TO MANAGE ADMINISTRATOR\n";
     cout<<"------------------------------\n";
     cout<<"\n1.For security reasons don't disclose your password";
     cout<<"\n2.Hide ADMINIST.txt from TC\BIN";
     cout<<"\n3.Don't update your password suddenly";
     cout<<"\n\n\t\t\tPress any key for Help menu";
     getch();
     help();
     break;
    default:
     clrscr();
     cleardevice();
     setbkcolor(BLACK);
     cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tInvalid Entry!";
    }                //switch(ch)!
   getch();
   cout<<"\nWant to go home menu(y/n)";
   char ch5;
   ch5=getch();
   if(ch5=='y')
    Home();
  }                 //help()!
  void update()
  {
   clrscr();
   int gd=DETECT,gm,i;
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   setbkcolor(WHITE);
   setcolor(RED);
   for(i=1;i<3;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   setcolor(CYAN);
   for(i=5;i<8;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   for(i=1;i<5;i++)
   {
    setcolor(8);
    rectangle(400-2*i,20-2*i,190-2*i,50-2*i);
   }
   settextstyle(DEFAULT_FONT,0,2);
   setcolor(RED);
   outtextxy(250,25,"Update");
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(70,150,"1}Fees");
   outtextxy(250,150,"2}Books Library");
   setcolor(BLUE);
   for(i=1;i<5;i++)
   {
    setcolor(2*i);
    circle(305,225,63-3*i);
   }
   char ch3;
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(256,220,"Choice(1/2)?");
   cin>>ch3;
   switch(ch3)
   {
    case'1':
     char ch2;
     clrscr();
     cleardevice();
     update_fees();
     cout<<"\nCongrats fees_update succeded!";
     A7:
      cout<<"\n\n\t\tPress (@) for Home";
      cin>>ch2;
      if(ch2=='@')
      {
       Home();
      }
      else
      {
       cout<<"\n\tInvalid Entry?Try again!";
       goto A7;
      }
      break;
     case'2':
       cleardevice();
       book();
	A8:
	 cout<<"\n\n\t\tPress (@) for Home";
	 cin>>ch2;
	 if(ch2=='@')
	 {cleardevice();
	  Home();
	 }
	 else
	 {
	  cout<<"\n\tInvalid Entry?Try again!";
	  goto A8;
	 }
      break;
     default:
       cout<<"\nInvalid Entry!";
    }                     //switch(ch3)!
   getch();
   cout<<"\nWant to go home menu(y/n)";
   char ch5;
   ch5=getch();
   if(ch5=='y')
    Home();
  }                     //update()!

  void creater()
  {
   clrscr();
   int gd=DETECT,gm,i;
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   setbkcolor(WHITE);
   setcolor(RED);
   for(i=1;i<3;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   setcolor(CYAN);
   for(i=5;i<8;i++)
    rectangle(i,i,getmaxx()-(i),getmaxy()-i);
   setbkcolor(RED);
   settextstyle(DEFAULT_FONT,0,1);
   setcolor(CYAN);
   outtextxy(230,20,"About Software");
   for(i=1;i<5;i++)
   {
    setcolor(8);
    rectangle(400-2*i,20-2*i,190-2*i,50-2*i);
   }
   cout<<"\n\n\n\nPress any key to continue!";
   getch();
   clrscr();
   cleardevice();
   gotoxy(0,0);
   cout<<"\n\n\n\n\n";
   cout<<"From independent software developers to the enterprise, everyone";
   cout<<" is looking for ways to improve software development, increasing";
   cout<<" productivity while not sacrificing performance. Software technologies";
   cout<<" continue to change, but have programmers really found the real ";
   cout<<"keys to faster development cycles, more reliable software and";
   cout<<" improved performance?\nWhile it is obvious we have more powerful";
   cout<<" software today, this does not mean we have better software today.";
   cout<<" As it becomes more complex, there are more things that can go";
   cout<<"\nPress any key to scroll down";
   getch();
   cout<<" wrong. In the old days, software was often written by a single";
   cout<<" programmer, while today software often is written by teams.";
   cout<<" The complexity alone of trying to get a team of programmers to";
   cout<<" work together is challenging enough, but add to this the size";
   cout<<" and scope of some applications that can be hundreds of thousands";
   cout<<" of lines of code, if not possibly in the millions of lines of ";
   cout<<"code, and you can have a veritible nightmare trying to put it all";
   cout<<" together. Few trades today require so much attention to details";
   cout<<" at such a large scope as does programming.";
   cout<<"\n";
   cout<<"...is an open ISO-standardized language.For a time, C++ had no";
   cout<<" official standard and was maintained by a de-facto standard, ";
   cout<<"however since 1998, C++ is standardized by a committee of the ISO.";
   cout<<" Their page may be accessed here\n....is a compiled language.C++ ";
   cout<<"compiles directly to a machine s native code, allowing it to be";
   cout<<" one of the fastest languages in the world, if optimized\n....is";
   cout<<" a strongly-typed unsafe language.C++ is a language that expects";
   cout<<" the programmer to know what he or she is doing, but allows for ";
   cout<<"incredible amounts of control as a result.";
   cout<<"\nPress any key to scroll down";
   getch();
   cout<<"\n...supports both manifest and inferred typing.As of the latest";
   cout<<" C++ standard, C++ supports both manifest and inferred typing,";
   cout<<" allowing flexibility and a means of avoiding verbosity where";
   cout<<" desired\n....supports both static and dynamic type checking.";
   cout<<"C++ allows type conversions to be checked either at compile-time";
   cout<<" or at run-time, again offering another degree of flexibility. ";
   cout<<"Most C++ type checking is, however, static.\n...offers many ";
   cout<<"paradigm choices.";
   cout<<"C++ offers remarkable support for procedural, generic, and ";
   cout<<"object-oriented programming paradigms, with many other paradigms ";
   cout<<"being possible as well.\n...is portable.As one of the most ";
   cout<<"frequently used languages in the world and as an open language,";
   cout<<" C++ has a wide range of compilers that run on many different";
   cout<<" platforms that support it. Code that exclusively uses C++'s ";
   cout<<"standard library will run on many platforms with few to no";
   cout<<" changes..";
   cout<<"\nPress any key to scroll down";
   getch();
   cout<<"\n...is upwards compatible with C C++, being a language that";
   cout<<" directly builds off C, is compatible with almost all C code.";
   cout<<" C++ can use C libraries with few to no modifications of the C";
   cout<<" library code.\n...has incredible library support.A search for ";
   cout<<"library on the popular project-management website SourceForge will";
   cout<<" yield over 3000 results for C++ libraries. A link to the results";
   cout<<" of the search may be found here.";
   cleardevice();
   clrscr();
   setbkcolor(BLUE);
   gotoxy(0,0);
   setcolor(RED);
   outtextxy(230,25,"About us");
   for(i=1;i<5;i++)
   {
    setcolor(8);
    rectangle(400-2*i,20-2*i,190-2*i,50-2*i);
   }
   cout<<"\n\n\n\n\tIt was a tragic end to a life that had so deeply affected the ";
   cout<<"\tcourse of C++ of the United States. Meriwether Lewis, a driven";
   cout<<"\tand often tormented soul, led an expedition of discovery that";
   cout<<"\texpanded a young nation s economic potential, increased its ";
   cout<<"\tscientific understanding, and enhanced its worldwide reputation.";
   cout<<"\tFriends, as software developing is a updation process with a Work in";
   cout<<"\tProgress tag with it.We have tried our level best to make this software";
   cout<<"\ta complete product and it is gratifying to know that a lot of people";
   cout<<"\tsatisfied!";
   getch();
   cout<<"\nWant to go home menu(y/n)";
   char ch5;
   cin>>ch5;
   if(ch5=='y')
    Home();
  }                                //creater()!
  void admission()
  {
   ofstream fin;
   char ch5;
   clrscr();
   cleardevice();
   setbkcolor(BLUE);
   gotoxy(0,0);
   char ch3,ch2='y';
   cout<<"\n\t\t\tAdmission Section:-";
   cout<<"\n\t\t\t******************\n";
   cout<<"\n1.Students                    2.Teachers\n";
   ch3=getch();
   switch(ch3)
   {
    case'1':
    fin.open("S_RECORD.txt",ios::in|ios::app|ios::binary);
    while(ch2=='y')
    {
      cout<<"Fill up your details:-";
      cout<<"\n--------------------\n";
      Y.student_input();
      fin.write((char*)&Y,sizeof(Y));
      cout<<"\n\t\tCongratulations you are sucessfully admitted!";
      cout<<"\n\tYou can view your data in 'Records-Student-View' menu";
      cout<<"\n\t\tYour addmission no: "<<Y.admno;
      cout<<"\n\n\t\tWant to admit more(y/n)=";
      cin>>ch2;
      if(ch2=='n'||ch2=='N')
       break;
      clrscr();
      cleardevice();
      gotoxy(0,0);
      setbkcolor(BLUE);
     }                   //while(ch2)!
    fin.close();
    break;

   case'2':
    char found;
    fin.open("T_RECORD.txt",ios::in|ios::app|ios::binary);
    while(ch2=='y')
    {
     cout<<"Fill up your details:-";
     cout<<"\n--------------------\n";
     Z.teacher_input();
     fin.write((char*)&Z,sizeof(Z));
     cout<<"\n\t\tCongratulations you are sucessfully admitted!";
     cout<<"\n\tYou can view your data in 'Records-Teacher-View' menu";
     cout<<"\n\n\t\tWant to admit more(y/n)=";
     cin>>ch2;
     clrscr();
     if(ch2=='n'||ch2=='N')
       break;
      cleardevice();
      gotoxy(0,0);
      setbkcolor(BLUE);
    }                 //while(ch2)!
     fin.close();
    break;
   default:
    cout<<"\nInvalid Entry!";
   }                       //switch(ch3)!
   cout<<"\n\n\t\tWant to go Home(y/n)?";
   ch5=getch();
   if(ch5=='y')
    Home();
  }           //admission()!

  void records()
  {
   clrscr();
   cleardevice();
   setbkcolor(BLUE);
   int pos,tempadmno;
   char ch1,ch2,ch3='y',ch4,found;
   fstream finout;
   finout.open("S_RECORDS.txt",ios::in|ios::out|ios::app|ios::binary);
   cout<<"\n\t\t\tRecords Section:-";
   cout<<"\n\t\t\t******************\n";
   cout<<"\n1.Students                    2.Teachers\n";
   ch1=getch();
   for(int i=0;i<80;i++)
    cout<<"*";
   cout<<"\n";
   if(ch1=='1')
   {
    cout<<"\t1.View        2.Update        3.Delete\n";
    ch2=getch();
    cout<<"\n";
    for(int i=0;i<80;i++)
      cout<<"*";
   switch(ch2)
   {
   case'1':
    cleardevice();
    clrscr();
    gotoxy(0,0);
    finout.seekg(0);
     while(ch3=='y')
     {
      cout<<"\nAdmission no.: ";
      cin>>tempadmno;
      while(!finout.eof())
      {
       finout.read((char*)&Y,sizeof(Y));
       if(Y.admno==tempadmno)
	{
	 for(int j=0;j<80;j++)
	  cout<<"*";
	 Y.student_output();
	 found='y';
	 break;
	}
      }		     //while(eof)!
      if(found!='y')
       cout<<"\nInvalid admission no.!";
     cout<<"\nWant to view more records(y/n)?";
     ch3=getch();
     if(ch3=='n'||ch3=='N')
      break;
     clrscr();
     cleardevice();
     setbkcolor(BLUE);
     gotoxy(0,0);
     finout.seekg(0);
     }                      //while(ch3)!
     break;
   case'2':
    cleardevice();
    clrscr();
    gotoxy(0,0);
    setbkcolor(RED);
    finout.seekg(0);
     while(ch3=='y')
     {
     cout<<"\nAdmission no.: ";
     cin>>tempadmno;
     while(!finout.eof())
     {
	pos=finout.tellg();
      finout.read((char*)&Y,sizeof(Y));
      if(Y.admno==tempadmno)
       {
	for(i=0;i<80;i++)
	  cout<<"*";
	Y.student_output();
       cout<<"\nWant to update your record(y/n)?";
       cin>>ch4;
       if(ch4=='y'||ch4=='Y')
       {
	cout<<"\n-----------------------------------\n";
	Y.update_s_input();
	finout.seekg(pos);
	finout.write((char*)&Y,sizeof(Y));
	cout<<"\n\t\tCongrats your record updated!";
	found='y';
	break;
       }
     }               //while(eof)!
     if(found!='y')
      cout<<"\nInvalid admission no.!";
     cout<<"\nWant to update more records(y/n)?";
     cin>>ch3;
     clrscr();
     cleardevice();
     gotoxy(0,0);
     setbkcolor(RED);
     finout.seekg(0);
     if(ch3=='n'||ch3=='N')
      break;
     }                        //while(ch3)!
    break;
   case'3':
    cleardevice();
    setcolor(RED);
    gotoxy(0,0);
    clrscr();
    fstream fin;
    finout.seekg(0);
    fin.open("Stemp.txt",ios::in|ios::out|ios::app|ios::binary);
    while(ch3=='y')
    {
     cout<<"\nAdmission no.: ";
     cin>>tempadmno;
     while(!finout.eof())
     {
      finout.read((char*)&Y,sizeof(Y));
      if(Y.admno==tempadmno)
       {
	for(i=0;i<80;i++)
	 cout<<"*";
	Y.student_output();
	found='y';
	cout<<"\nConfirm want to delete?(y/n)";
	cin>>ch4;
	if(ch4=='n'||ch4=='N')
	{
	 fin.write((char*)&Y,sizeof(Y));
	}
       }        //if(Y.admno)!
      else
	fin.write((char*)&Y,sizeof(Y));
     }                  //while(eof)!
     if(found!='y')
      cout<<"\nRecord not found!";
     finout.seekg(0);
     fin.seekg(0);
     fin.close();
     finout.close();
     remove("S_RECORDS.txt");
     rename("Stemp.txt","S_RECORDS.txt");
     cout<<"\n\tCongrats your record deleted";
     cout<<"\nWant to delete more records(y/n)?";
     cin>>ch3;
     clrscr();
     cleardevice();
     setbkcolor(RED);
     gotoxy(0,0);
     if(ch3=='n'||ch3=='N')
      break;
     }              //while(ch3)!
    break;
   default:
    cout<<"\nInvalid Entry!";
   }               //switch(ch2)!
   }
  }                //if(ch1)!
 else if(ch1=='2')
  {
   cout<<"\t1.View         2.Update         3.Delete\n";
   cin>>ch2;
   cout<<"\n";
   for(int i=0;i<80;i++)
      cout<<"*";
   fstream finout;
   char tempnam[25];
   finout.open("T_RECORDS.txt",ios::in|ios::out|ios::app|ios::binary);
   switch(ch2)
   {
   case'1':
    cleardevice();
    gotoxy(0,0);
    setbkcolor(BLUE);
    while(ch3=='y')
    {
     cout<<"Teacher name: ";
     gets(tempnam);
      while(!finout.eof())
      {
       finout.read((char*)&Z,sizeof(Z));
       if(strcmpi(Z.nam,tempnam)==0)
	{
	 for(i=0;i<80;i++)
	  cout<<"*";
	 Z.teacher_output();
	 found='y';
	 break;
	}
      }		     //while(eof)!
      finout.seekg(0);
       if(found!='y')
	cout<<"\nInvalid admission no.!";
     cout<<"\nWant to view more records(y/n)?";
     cin>>ch3;
     if(ch3=='n'||ch3=='N')
      break;
     clrscr();
     cleardevice();
     setbkcolor(BLUE);
     gotoxy(0,0);
     }                      //while(ch3)!
    break;
   case'2':
   cleardevice();
   gotoxy(0,0);
   setbkcolor(RED);
    while(ch3=='y')
    {
     cout<<"Teacher name: ";
     gets(tempnam);
     while(!finout.eof())
     {
      pos=finout.tellg();
      finout.read((char*)&Z,sizeof(Z));
      if(strcmpi(Z.nam,tempnam)==0)
       {
	for(i=0;i<80;i++)
	 cout<<"*";
	Z.teacher_output();
	found='y';
	cout<<"\nWant to update your record(y/n)?";
	cin>>ch4;
	if(ch4=='y'||ch4=='Y')
	{
	 finout.seekg(pos);
	 Z.update_t_input();
	 finout.write((char*)&Z,sizeof(Z));
	 break;
	}
       }
      }             //while(eof)
      if(found!='y')
       cout<<"\nInvalid admission no.!";
      cout<<"\nWant to update more records(y/n)?";
     cin>>ch3;
     if(ch3=='n'||ch3=='N')
      break;
     clrscr();
     cleardevice();
     setbkcolor(RED);
     gotoxy(0,0);
    }                //while(ch3)!
    break;
   case'3':
    cleardevice();
    gotoxy(0,0);
    setbkcolor(RED);
    fstream fin;
    fin.open("Ttemp.txt",ios::in|ios::out|ios::app|ios::binary);
    while(ch3=='y')
    {
     cout<<"\nAdmission no.: ";
     gets(tempnam);
     while(!finout.eof())
     {
      finout.read((char*)&Z,sizeof(Z));
      if(strcmpi(Z.nam,tempnam)==0)
       {
	for(i=0;i<80;i++)
	 cout<<"*";
	Z.teacher_output();
	found='y';
	cout<<"\nConfirm want to delete?(y/n)";
	cin>>ch4;
	if(ch4=='n'||ch4=='N')
	{
	 fin.write((char*)&Z,sizeof(Z));
	}
       }        //if(Z.admno)!
      else
	fin.write((char*)&Y,sizeof(Y));
     }                  //while(eof)!
     if(found!='y'||found!='Y')
      cout<<"\nRecord not found!";
     finout.seekg(0);
     fin.seekg(0);
     fin.close();
     finout.close();
     remove("T_RECORDS.txt");
     rename("Ttemp.txt","T_RECORDS.txt");
     cout<<"\n\tCongrats your record deleted";
     cout<<"\nWant to delete more records(y/n)?";
     cin>>ch3;
     if(ch3=='n'||ch3=='N')
      break;
     clrscr();
     cleardevice();
     gotoxy(0,0);
     setbkcolor(RED);
     }              //while(ch3)!
    break;
   default:
    cout<<"\nInvalid Entry!";
   }                  //switch(ch2)!
  }                //else if(ch1)!
  else
   cout<<"\nInvalid Entry!";
   cout<<"\n\n\t\tWant to go Home(y/n)?";
   char ch5;
   cin>>ch5;
   if(ch5=='y')
    Home();
 }                                   //records()!

  void fees()
  {
   clrscr();
   cleardevice();
   setbkcolor(BLACK);
   gotoxy(0,0);
   ifstream fout;
   fstream f;
   char chkmnth,strm,ch='y',ch1,ch2,found;
   int tempadmno;
   fout.open("S_RECORDS.txt",ios::binary|ios::out);
   f.open("Fees.txt",ios::in|ios::out|ios::binary);
   cout<<"\t\tWelcome to Fee-Section\n";
   cout<<"\t\t**********************\n";
   cout<<"\n1.View(Fee Structure)     2.Pay            3.View Paid(fees)\n";
   ch1=getch();
   f.read((char*)&F,sizeof(F));
   F.tcost1=F.cost11+F.cost21+F.cost31+F.cost41+F.cost51;
   F.tcost2=F.cost12+F.cost22+F.cost32+F.cost42+F.cost52;
   F.tcost3=F.cost13+F.cost23+F.cost33+F.cost43+F.cost53;
   F.tcost4=F.cost14+F.cost24+F.cost34+F.cost44+F.cost54;
   F.tcost5=F.cost15+F.cost25+F.cost35+F.cost45+F.cost55;
   F.tcost6=F.cost16+F.cost26+F.cost36+F.cost46+F.cost56;
   switch(ch1)
   {
   case'1':
   clrscr();
   cleardevice();
   gotoxy(0,0);
   cout<<"\t\t\tFee Structure:-\n";
   cout<<"\t\t\t*************\n";
   cout<<"Particulars    LKG-II    III-V    VI-VIII   IX-X    XI-XII(Sc.)    XI-XII(Comm.)\n";
   cout<<"*******************************************************************************\n";
   cout<<"Tuition Fee      "<<F.cost11<<"      "<<F.cost12<<"        "<<F.cost13<<"    "<<F.cost14<<"           "<<F.cost15<<"              "<<F.cost16<<"\n";
   cout<<"Building Fee       20       20         20      20            20               20\n";
   cout<<"Examination Fee      "<<F.cost21<<"       "<<F.cost22<<"        "<<F.cost23<<"      "<<F.cost24<<"           "<<F.cost25<<"              "<<F.cost26<<"\n";
   cout<<"Pupil Fund Fee     30       30         30      30            30               30\n";
   cout<<"Computer Fee     "<<F.cost31<<"      "<<F.cost32<<"         "<<F.cost33<<"           "<<F.cost34<<"         "<<F.cost35<<"             "<<F.cost36<<"   \n";
   cout<<"Science Fee      "<<F.cost41<<"      "<<F.cost42<<"         "<<F.cost43<<"           "<<F.cost44<<"         "<<F.cost45<<"             "<<F.cost46<<" \n";
   cout<<"***************************************************************************\n";
   cout<<"Total Fee        "<<F.tcost1<<"      "<<F.tcost2<<"         "<<F.tcost1<<"           "<<F.tcost4<<"         "<<F.tcost5<<"             "<<F.tcost6<<"    \n";
   cout<<"Transport Fee    "<<F.cost51<<"      "<<F.cost52<<"         "<<F.cost53<<"           "<<F.cost54<<"         "<<F.cost55<<"             "<<F.cost56<<"   \n";
   break;
   case'2':
   clrscr();
   cleardevice();
   gotoxy(0,0);
   setbkcolor(BLUE);
    cout<<"\n\t\t\tPay fees(For students)\n";
    cout<<"\t\t\t***********************\n";
    while(ch=='y'||ch=='Y')
    {
    setbkcolor(BLUE);
    cout<<"Admission no.: ";
    cin>>tempadmno;
     while(!fout.eof())
     {
      fout.read((char*)&Y,sizeof(Y));
      if(Y.admno==tempadmno)
      {
       Y.student_output();
       cout<<"\nPay  fees(y/n)?";
       cin>>ch2;
       F.f_admno=Y.admno;
       F.pay_fee();
       f.write((char*)&F,sizeof(F));
       found='y';
       break;
      }
      else
      {
       found='n';
       break;
      }
     }          //while(eof)!
     fout.seekg(0);
     cout<<"\n\n\t\tWant to pay more fees?(y/n)";
     cin>>ch;
     clrscr();
     cleardevice();
     gotoxy(0,0);
     if(ch=='n')
      break;
   }            //while(ch)!
   fout.seekg(0);
   fout.close();
   if(found=='n')
     cout<<"\nInvalid admission no.!";
   break;
   case'3':
   clrscr();
   gotoxy(0,0);
   cleardevice();
   setbkcolor(BLACK);
    cout<<"\n\t\t\tView Paid(fees)\n";
    cout<<"\t\t\t*****************\n";
    while(ch=='y'||ch=='Y')
    {
    cout<<"Admission no.: ";
    cin>>tempadmno;
     while(!fout.eof())
     {
      fout.read((char*)&Y,sizeof(Y));
      if(Y.admno==tempadmno)
      {
       Y.student_output();
       break;
      }
     }
     fout.seekg(0);
     cout<<"\nFees Paid upto:-";
     while(!f.eof())
     {
      f.read((char*)&F,sizeof(F));
      if(F.f_admno==tempadmno)
      {
       F.view_fee();
       break;
      }
     }
     f.seekg(0);
     cout<<"\n\n\t\tWant to view more paid fees?(y/n)";
     cin>>ch;
     clrscr();
     gotoxy(0,0);
     if(ch=='n')
      break;
   }            //while(ch)!
   break;
   default:
    cout<<"\nInvalid Entry!";
  }                     //switch(ch1)!
   cout<<"\nWant to go home menu(y/n)";
   char ch5;
   cin>>ch5;
   if(ch5=='y')
    Home();
  f.close();
  fout.close();
  }                    //fees()!
  void feedback()
  {
   class feed_back
   {
    public:
    char nam[25];
    char dgn[20];
    char eid[20];
    char rite[];
   }f_b;
   char ch,ch1='y';
   fstream finout;
   finout.open("Feedback.txt",ios::in|ios::out|ios::binary|ios::app|ios::ate);
   cout<<"\t\tWelcome to Feedback menu\n";
   cout<<"\t\t************************\n";
   cout<<"\n1.Add                          2.View\n";
   ch=getch();
   if(ch=='1')
   {
    while(ch1=='y')
    {
    cout<<"Name: ";
    gets(f_b.nam);
    cout<<"Designation: ";
    gets(f_b.dgn);
    cout<<"Email: ";
    gets(f_b.eid);
    cout<<"Feedback: ";
    gets(f_b.rite);
    finout.write((char*)&f_b,sizeof(f_b));
    cout<<"\n\n\t\tWant to write more feedbacks?(y/n)";
    cin>>ch1;
    if(ch1=='n')
     break;
    clrscr();
    }
   }
   else if(ch=='2')
   {
    ch1='y';
    finout.seekg(0);
    while(!finout.eof())
    {
     finout.read((char*)&f_b,sizeof(f_b));
     cout<<"Name: ";
     puts(f_b.nam);
     cout<<"\nDesignation: ";
     puts(f_b.dgn);
     cout<<"\nEmail: ";
     puts(f_b.eid);
     cout<<"\nFeedback: ";
     puts(f_b.rite);
     for(int i=0;i<20;i++)
      cout<<"*";
     cout<<"\n";
    }
   }
   else
    cout<<"\nInvalid Entry!";
   finout.close();
   cout<<"\nWant to go home menu(y/n)";
   char ch5;
   cin>>ch5;
   if(ch5=='y')
    Home();
  }            //feedback()!
  void main()
  {
   Design();
   fstream f;
   char found;
   f.open("Administrator.txt",ios::in|ios::out|ios::binary);
   f.seekg(0);
   char pass[25],ch;
   cleardevice();
   setbkcolor(RED);
   gotoxy(0,0);
   cout<<"1}Enter Password                              2}Help";
   ch=getch();
   if(ch=='1')
   {
    A5:
    cout<<"\nAdmininstrator Password:";
   gets(pass);
   while(!f.eof())
   {
    f.read((char*)&A,sizeof(A));
    if(strcmp(A.admpass,pass)==0)
    {
     Home();
     found='y';
     break;
    }
   }         //while(eof)!
   if(found!='y')
   {
     cout<<"\n\n\t\t\tInvalid Password!";
     cout<<"\n\t\t\tWant to try again?(y/n)";
     char ch6;
     ch6=getch();
     if(ch6=='y')
     { cleardevice();
       gotoxy(0,0);
       clrscr();
      goto A5;
     }
   }
   }               //if(ch)!
   else if(ch=='2')
   {
    help();
    clrscr();
    cleardevice();
    setbkcolor(BLACK);
    cout<<"\nPress any key to enter password?";
    getch();
    cleardevice();
    clrscr();
    goto A5;
   }
   else
    cout<<"\nInvalid entry!";
   f.close();
   getch();
  }














