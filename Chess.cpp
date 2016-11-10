#include<stdio.h>
#include<conio.h>

#include<graphics.h>
#include<bios.h>
#include<dos.h>
#include<stdlib.h>

#define mx getmaxx()/2
#define my getmaxy()/2

enum press {LEFT=75,RIGHT=77,UP=72,DOWN=80,ENTER=28,EXIT=1}key;
enum slct {NONE=0,KNG=1,QN=2,ELE=3,HRSE=4,CML=5,SLDRS=6}players;

int whtx[2][8],whty[2][8],blky[2][8],blkx[2][8],k,x1,y1;
int sb=50;       //size of box
int posx=1,posy=1;
int sel_col;
int cl;               //current location 1for white 2 for black, 3 for none
int tur;       //turn of which player 1-White player 2-Black player 3-WHITE player 4-BLACK solder
int sm[3]={0,0,0};
int dlx=-1,dly=2;

void vset(void);
void bdesign(int cs,int num);
void warriors(void);
void ele(void);
void hrse(void);
void unt(void);
void king(void);
void queen(void);
void solders(void);
void curloc(int);
void turn(void);
void main_game(void);
void sol_move(int);
void check_solder(void);
void main()
{
            int i,j,grd=DETECT,grm;
            again:
            clrscr();
            printf("\nEnter 1 for WHITE or 2 for BLACK  : ");
            scanf("%d",&k);
            if(k>2||k<1)
            {
                        printf("\nYou can select from 1 or 2 only.");
                        getch();
                        goto again;
            }
            cl=k;
            tur=k;
            initgraph(&grd,&grm,"");
            vset();
            bdesign(0,0);
            warriors();
            turn();
            while(1)
            {
                        key=bioskey(0);
                        key=key>>8;
                        if(key==LEFT)
                        {
                                    if(posx!=1)
                                                posx--;
                                    else
                                                continue;
                        }
                        if(key==RIGHT)
                        {
                                    if(posx!=8)
                                                posx++;
                                    else
                                                continue;
                        }
                        else if(key==UP)
                        {
                                    if(posy!=8)
                                                posy++;
                                    else
                                                continue;
                        }
                        else if(key==DOWN)
                        {
                                    if(posy!=1)
                                                posy--;
                                    else
                                                continue;
                        }
                        else if(key==ENTER)
                        {
                                    main_game();
                                    continue;
                        }
                        else if(key==EXIT)
                                    break;
                        curloc(0);
                        clearviewport();
                        bdesign(0,0);
                        warriors();
                        turn();
            }
}
void vset(void)
{
            int i,j;
            for(i=-4;i<4;i++)
            {
                        for(j=-4;j<4;j++)
                        {
                                    if(i==-4)
                                    {
                                                whtx[0][j+4]=j+5;
                                                whtx[1][j+4]=j+5;
                                                blkx[0][j+4]=j+5;
                                                blkx[1][j+4]=j+5;
                                                if(k==2)
                                                {
                                                            whty[0][j+4]=i+12;
                                                            whty[1][j+4]=i+11;
                                                }
                                                if(k==1)
                                                {
                                                            blky[0][j+4]=i+12;
                                                            blky[1][j+4]=i+11;
                                                }
                                    }
                                    if(i==4-1)
                                    {
                                                if(k==1)
                                                {
                                                            whty[0][j+4]=i-2;
                                                            whty[1][j+4]=i-1;
                                                }
                                                if(k==2)
                                                {
                                                            blky[0][j+4]=i-2;
                                                            blky[1][j+4]=i-1;
                                                }
                                    }
                        }
            }
}
void bdesign(int cs,int num)
{
            int i,j;
            char num_str[5];
            itoa(num,num_str,10);
            if(cs==1)
                        sel_col=BLUE;
            else if(cs==2)
                        sel_col=GREEN;
            else if(cs==3)
                        sel_col=RED;
            else
                        sel_col=MAGENTA;
            int P1_COLOR=DARKGRAY;
            int P2_COLOR=WHITE;
            setbkcolor(CYAN);
            for(i=-4;i<4;i++)
            {
                        for(j=-4;j<4;j++)
                        {
                                    if(j==posx-5&&i==4-posy)
                                    {
                                                P1_COLOR=sel_col;
                                                P2_COLOR=sel_col;
                                    }
                                    else
                                    {
                                                P1_COLOR=DARKGRAY;
                                                P2_COLOR=WHITE;
                                    }
                                    if((i+j+k)%2)
                                                setcolor(P1_COLOR);
                                    else
                                                setcolor(P2_COLOR);
                                                rectangle(mx+j*sb,my+i*sb,mx+(j+1)*sb,my+(i+1)*sb);

                                    if((i+j+k)%2)
                                    {
                                                setfillstyle(SOLID_FILL,P1_COLOR);
                                                floodfill(mx+j*sb+3,my+i*sb+3,P1_COLOR);
                                    }
                                    else
                                    {
                                                setfillstyle(SOLID_FILL,P2_COLOR);
                                                floodfill(mx+j*sb+3,my+i*sb+3,P2_COLOR);
                                    }
                        }
            }
            if((sel_col==RED||sel_col==GREEN)&&(num!=0))
            {
                        setcolor(LIGHTCYAN);
                        settextstyle(2,0,5);
                        outtextxy(mx-4*sb+(posx-1)*sb+10,my+4*sb-(posy-1)*sb-10,num_str);
            }
}
void warriors(void)
{
            ele();
            hrse();
            unt();
            king();
            queen();
            solders();
}
void ele(void)
{
            int pc=getcolor();
            //----------------------WHITE--------------------------
            setcolor(YELLOW);
            rectangle(mx-4*sb+sb/2+(whtx[0][0]-1)*sb-12,2*my-(my-4*sb+sb/2+(whty[0][0]-1)*sb+10),mx-4*sb+sb/2+(whtx[0][0]-1)*sb+12,2*my-(my-4*sb+sb/2+(whty[0][0]-1)*sb+6));
            rectangle(mx-4*sb+sb/2+(whtx[0][0]-1)*sb-6,2*my-(my-4*sb+sb/2+(whty[0][0]-1)*sb+6),mx-4*sb+sb/2+(whtx[0][0]-1)*sb+6,2*my-(my-4*sb+sb/2+(whty[0][0]-1)*sb-10));
            rectangle(mx-4*sb+sb/2+(whtx[0][0]-1)*sb-12,2*my-(my-4*sb+sb/2+(whty[0][0]-1)*sb-10),mx-4*sb+sb/2+(whtx[0][0]-1)*sb+12,2*my-(my-4*sb+sb/2+(whty[0][0]-1)*sb-14));

            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][0]-1)*sb-12+2,2*my-(my-4*sb+sb/2+(whty[0][0]-1)*sb+10-2),YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][0]-1)*sb-6+2,2*my-(my-4*sb+sb/2+(whty[0][0]-1)*sb+6-2),YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][0]-1)*sb-12+2,2*my-(my-4*sb+sb/2+(whty[0][0]-1)*sb-10-2),YELLOW);

            rectangle(mx-4*sb+sb/2+(whtx[0][7]-1)*sb-12,2*my-(my-4*sb+sb/2+(whty[0][7]-1)*sb+10),mx-4*sb+sb/2+(whtx[0][7]-1)*sb+12,2*my-(my-4*sb+sb/2+(whty[0][7]-1)*sb+6));
            rectangle(mx-4*sb+sb/2+(whtx[0][7]-1)*sb-6,2*my-(my-4*sb+sb/2+(whty[0][7]-1)*sb+6),mx-4*sb+sb/2+(whtx[0][7]-1)*sb+6,2*my-(my-4*sb+sb/2+(whty[0][7]-1)*sb-10));
            rectangle(mx-4*sb+sb/2+(whtx[0][7]-1)*sb-12,2*my-(my-4*sb+sb/2+(whty[0][7]-1)*sb-10),mx-4*sb+sb/2+(whtx[0][7]-1)*sb+12,2*my-(my-4*sb+sb/2+(whty[0][7]-1)*sb-14));

            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][7]-1)*sb-12+2,2*my-(my-4*sb+sb/2+(whty[0][7]-1)*sb+10-2),YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][7]-1)*sb-6+2,2*my-(my-4*sb+sb/2+(whty[0][7]-1)*sb+6-2),YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][7]-1)*sb-12+2,2*my-(my-4*sb+sb/2+(whty[0][7]-1)*sb-10-2),YELLOW);

            //----------------------BLACK--------------------------
            setcolor(BROWN);
            rectangle(mx-4*sb+sb/2+(blkx[0][0]-1)*sb-12,2*my-(my-4*sb+sb/2+(blky[0][0]-1)*sb+10),mx-4*sb+sb/2+(blkx[0][0]-1)*sb+12,2*my-(my-4*sb+sb/2+(blky[0][0]-1)*sb+6));
            rectangle(mx-4*sb+sb/2+(blkx[0][0]-1)*sb-6,2*my-(my-4*sb+sb/2+(blky[0][0]-1)*sb+6),mx-4*sb+sb/2+(blkx[0][0]-1)*sb+6,2*my-(my-4*sb+sb/2+(blky[0][0]-1)*sb-10));
            rectangle(mx-4*sb+sb/2+(blkx[0][0]-1)*sb-12,2*my-(my-4*sb+sb/2+(blky[0][0]-1)*sb-10),mx-4*sb+sb/2+(blkx[0][0]-1)*sb+12,2*my-(my-4*sb+sb/2+(blky[0][0]-1)*sb-14));

            setfillstyle(SOLID_FILL,BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][0]-1)*sb-12+2,2*my-(my-4*sb+sb/2+(blky[0][0]-1)*sb+10-2),BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][0]-1)*sb-6+2,2*my-(my-4*sb+sb/2+(blky[0][0]-1)*sb+6-2),BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][0]-1)*sb-12+2,2*my-(my-4*sb+sb/2+(blky[0][0]-1)*sb-10-2),BROWN);

            rectangle(mx-4*sb+sb/2+(blkx[0][7]-1)*sb-12,2*my-(my-4*sb+sb/2+(blky[0][7]-1)*sb+10),mx-4*sb+sb/2+(blkx[0][7]-1)*sb+12,2*my-(my-4*sb+sb/2+(blky[0][7]-1)*sb+6));
            rectangle(mx-4*sb+sb/2+(blkx[0][7]-1)*sb-6,2*my-(my-4*sb+sb/2+(blky[0][7]-1)*sb+6),mx-4*sb+sb/2+(blkx[0][7]-1)*sb+6,2*my-(my-4*sb+sb/2+(blky[0][7]-1)*sb-10));
            rectangle(mx-4*sb+sb/2+(blkx[0][7]-1)*sb-12,2*my-(my-4*sb+sb/2+(blky[0][7]-1)*sb-10),mx-4*sb+sb/2+(blkx[0][7]-1)*sb+12,2*my-(my-4*sb+sb/2+(blky[0][7]-1)*sb-14));
            setfillstyle(SOLID_FILL,BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][7]-1)*sb-12+2,2*my-(my-4*sb+sb/2+(blky[0][7]-1)*sb+10-2),BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][7]-1)*sb-6+2,2*my-(my-4*sb+sb/2+(blky[0][7]-1)*sb+6-2),BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][7]-1)*sb-12+2,2*my-(my-4*sb+sb/2+(blky[0][7]-1)*sb-10-2),BROWN);
            setcolor(pc);
}
void hrse(void)
{
            int pc=getcolor();
            setcolor(YELLOW);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            settextstyle(4,0,5);
            outtextxy(mx-4*sb+sb/2+(whtx[0][1]-1)*sb,2*my-(my-4*sb+sb/2+(whty[0][1]-1)*sb+7),"1");
            settextstyle(4,0,5);
            outtextxy(mx-4*sb+sb/2+(whtx[0][6]-1)*sb,2*my-(my-4*sb+sb/2+(whty[0][6]-1)*sb+7),"1");

            setcolor(BROWN);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            settextstyle(4,0,5);
            outtextxy(mx-4*sb+sb/2+(blkx[0][1]-1)*sb,2*my-(my-4*sb+sb/2+(blky[0][1]-1)*sb+7),"1");
            settextstyle(4,0,5);
            outtextxy(mx-4*sb+sb/2+(blkx[0][6]-1)*sb,2*my-(my-4*sb+sb/2+(blky[0][6]-1)*sb+7),"1");

            setcolor(pc);
}
void unt(void)
{
            int pc=getcolor();
            setcolor(YELLOW);
            rectangle(mx-4*sb+sb/2+(whtx[0][2]-1)*sb-10,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb-10),mx-4*sb+sb/2+(whtx[0][2]-1)*sb+10,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb-6));
            rectangle(mx-4*sb+sb/2+(whtx[0][2]-1)*sb-3,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb-6),mx-4*sb+sb/2+(whtx[0][2]-1)*sb+3,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb+10));
            line(mx-4*sb+sb/2+(whtx[0][2]-1)*sb-6,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb+10),mx-4*sb+sb/2+(whtx[0][2]-1)*sb+6,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb+10));
            line(mx-4*sb+sb/2+(whtx[0][2]-1)*sb-6,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb+10),mx-4*sb+sb/2+(whtx[0][2]-1)*sb,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb+15));
            line(mx-4*sb+sb/2+(whtx[0][2]-1)*sb,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb+15),mx-4*sb+sb/2+(whtx[0][2]-1)*sb+6,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb+10));
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][2]-1)*sb-10+2,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb-10+2),YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][2]-1)*sb-3+2,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb-6+2),YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][2]-1)*sb,2*my-(my-4*sb+sb/2+(whty[0][2]-1)*sb+13),YELLOW);



            rectangle(mx-4*sb+sb/2+(whtx[0][5]-1)*sb-10,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb-10),mx-4*sb+sb/2+(whtx[0][5]-1)*sb+10,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb-6));
            rectangle(mx-4*sb+sb/2+(whtx[0][5]-1)*sb-3,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb-6),mx-4*sb+sb/2+(whtx[0][5]-1)*sb+3,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb+10));
            line(mx-4*sb+sb/2+(whtx[0][5]-1)*sb-6,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb+10),mx-4*sb+sb/2+(whtx[0][5]-1)*sb+6,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb+10));
            line(mx-4*sb+sb/2+(whtx[0][5]-1)*sb-6,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb+10),mx-4*sb+sb/2+(whtx[0][5]-1)*sb,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb+15));
            line(mx-4*sb+sb/2+(whtx[0][5]-1)*sb,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb+15),mx-4*sb+sb/2+(whtx[0][5]-1)*sb+6,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb+10));
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][5]-1)*sb-10+2,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb-10+2),YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][5]-1)*sb-3+2,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb-6+2),YELLOW);
            floodfill(mx-4*sb+sb/2+(whtx[0][5]-1)*sb,2*my-(my-4*sb+sb/2+(whty[0][5]-1)*sb+13),YELLOW);

            setcolor(BROWN);
            rectangle(mx-4*sb+sb/2+(blkx[0][2]-1)*sb-10,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb-10),mx-4*sb+sb/2+(blkx[0][2]-1)*sb+10,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb-6));
            rectangle(mx-4*sb+sb/2+(blkx[0][2]-1)*sb-3,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb-6),mx-4*sb+sb/2+(blkx[0][2]-1)*sb+3,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb+10));
            line(mx-4*sb+sb/2+(blkx[0][2]-1)*sb-6,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb+10),mx-4*sb+sb/2+(blkx[0][2]-1)*sb+6,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb+10));
            line(mx-4*sb+sb/2+(blkx[0][2]-1)*sb-6,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb+10),mx-4*sb+sb/2+(blkx[0][2]-1)*sb,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb+15));
            line(mx-4*sb+sb/2+(blkx[0][2]-1)*sb,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb+15),mx-4*sb+sb/2+(blkx[0][2]-1)*sb+6,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb+10));
            setfillstyle(SOLID_FILL,BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][2]-1)*sb-10+2,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb-10+2),BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][2]-1)*sb-3+2,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb-6+2),BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][2]-1)*sb,2*my-(my-4*sb+sb/2+(blky[0][2]-1)*sb+13),BROWN);

            rectangle(mx-4*sb+sb/2+(blkx[0][5]-1)*sb-10,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb-10),mx-4*sb+sb/2+(blkx[0][5]-1)*sb+10,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb-6));
            rectangle(mx-4*sb+sb/2+(blkx[0][5]-1)*sb-3,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb-6),mx-4*sb+sb/2+(blkx[0][5]-1)*sb+3,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb+10));
            line(mx-4*sb+sb/2+(blkx[0][5]-1)*sb-6,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb+10),mx-4*sb+sb/2+(blkx[0][5]-1)*sb+6,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb+10));
            line(mx-4*sb+sb/2+(blkx[0][5]-1)*sb-6,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb+10),mx-4*sb+sb/2+(blkx[0][5]-1)*sb,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb+15));
            line(mx-4*sb+sb/2+(blkx[0][5]-1)*sb,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb+15),mx-4*sb+sb/2+(blkx[0][5]-1)*sb+6,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb+10));
            setfillstyle(SOLID_FILL,BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][5]-1)*sb-10+2,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb-10+2),BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][5]-1)*sb-3+2,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb-6+2),BROWN);
            floodfill(mx-4*sb+sb/2+(blkx[0][5]-1)*sb,2*my-(my-4*sb+sb/2+(blky[0][5]-1)*sb+13),BROWN);

            setcolor(pc);
}
void king(void)
{
            int p1,p2,pc=getcolor();
            if(k==1)
            {
                        p1=3;
                        p2=4;
            }
            else
            {
                        p1=4;
                        p2=3;
            }
            setcolor(YELLOW);
            settextstyle(2,0,25);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            outtextxy(mx-4*sb+sb/2+(whtx[0][p1]-1)*sb,2*my-(my-4*sb+sb/2+(whty[0][p1]-1)*sb+7),"K");
            setcolor(BROWN);
            settextstyle(2,0,25);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            outtextxy(mx-4*sb+sb/2+(blkx[0][p2]-1)*sb,2*my-(my-4*sb+sb/2+(blky[0][p1]-1)*sb+7),"K");
            setcolor(pc);
}
void queen(void)
{
            int p1,p2,pc=getcolor();
            if(k==1)
            {
                        p1=4;
                        p2=3;
            }
            else
            {
                        p1=3;
                        p2=4;
            }
            setcolor(YELLOW);
            settextstyle(2,0,25);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            outtextxy(mx-4*sb+sb/2+(whtx[0][p1]-1)*sb,2*my-(my-4*sb+sb/2+(whty[0][p2]-1)*sb+7),"Q");
            setcolor(BROWN);
            settextstyle(2,0,25);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            outtextxy(mx-4*sb+sb/2+(blkx[0][p2]-1)*sb,2*my-(my-4*sb+sb/2+(blky[0][p2]-1)*sb+7),"Q");
            setcolor(pc);
}
void solders(void)
{
            int i,pc=getcolor();
            setcolor(YELLOW);
            settextstyle(3,0,5);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            for(i=0;i<8;i++)
            {
                        outtextxy(mx-4*sb+sb/2+(whtx[1][i]-1)*sb,2*my-(my-4*sb+sb/2+(whty[1][i]-1)*sb+7),"i");
                        outtextxy(mx-4*sb+sb/2+(whtx[1][i]-1)*sb,2*my-(my-4*sb+sb/2+(whty[1][i]-1)*sb+7),"i");
            }
            setcolor(BROWN);
            settextstyle(3,0,5);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            for(i=0;i<8;i++)
            {
                        outtextxy(mx-4*sb+sb/2+(blkx[1][i]-1)*sb,2*my-(my-4*sb+sb/2+(blky[1][i]-1)*sb+7),"i");
                        outtextxy(mx-4*sb+sb/2+(blkx[1][i]-1)*sb,2*my-(my-4*sb+sb/2+(blky[1][i]-1)*sb+7),"i");
            }
            setcolor(pc);
}
void curloc(int bit)
{
            int i,j;
            cl=5;
            setcolor(LIGHTGREEN);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
/*         for(j=0;j<8;j++)
            {*/
                        for(i=0;i<8;i++)
                        {
                                                            if(posx==whtx[0][i]&&posy==whty[0][i])
                                                            {
                                                                        cl=1;
                                                                        if(bit==1)
                                                                        {
                                                                                    whtx[0][i]=dlx;
                                                                                    whty[0][i]=dly--;
                                                                        }
                                                                        x1=i+1;
                 //                                                    printf("\nc1 1  posx:%d posy:%d  x1:%d  y1:%d",posx,posy,x1,y1);
                   //                                                  delay(1000);
                                                                        goto end;
                                                            }
                                                            else if(posx==whtx[1][i]&&posy==whty[1][i])
                                                            {
                                                                        cl=3;
                                                                        if(bit==1)
                                                                        {
                                                                                    whtx[1][i]=dlx;
                                                                                    whty[1][i]=dly--;
                                                                        }
                                                                        x1=i+1;
                                                                        y1=i+1;
                         //                                            printf("\nc1 2  x1:%d  y1:%d",x1,y1);
                           //                                          delay(1000);
                                                                        goto end;
                                                            }
                                                            else if(posx==blkx[0][i]&&posy==blky[0][i])
                                                            {
                                                                        cl=2;
                                                                        if(bit==1)
                                                                        {
                                                                                    blkx[0][i]=dlx;
                                                                                    blky[0][i]=dly--;
                                                                        }
                                                                        x1=i+1;
                                                                        y1=i+1;
                             //                                        printf("\nc1 3  x1:%d  y1:%d",x1,y1);
                               //                                      delay(1000);
                                                                        goto end;
                                                            }
                                                            else if(posx==blkx[1][i]&&posy==blky[1][i])
                                                            {
                                                                        cl=4;
                                                                        if(bit==1)
                                                                        {
                                                                                    blkx[1][i]=dlx;
                                                                                    blky[1][i]=dly--;
                                                                        }
                                                                        x1=i+1;
                                                                        y1=i+1;
                                     //                                printf("\nc1 4   x1:%d  y1:%d",x1,y1);
                                       //                              delay(1000);
                                                                        goto end;
                                                            }
                                                            else
                                                            {
                                                                        x1=i+1;
                                                                        y1=i+1;
                                         //                            printf("\n x1:%d  y1:%d",x1,y1);
                                           //                          delay(500);
                                                            }
                        }
            end:
}
void turn(void)
{
            int pc=getcolor();
            int rad=(my-4*sb)/3;
            setcolor(BLUE);
            settextstyle(4,0,4);
            outtextxy(mx,2*my-20,"Turn");
            if(tur==1||tur==3)
            {
                        setcolor(WHITE);
                        circle(mx-50,2*my-(my-4*sb)/2,rad);
                        setfillstyle(SOLID_FILL,WHITE);
                        floodfill(mx-50,2*my-(my-4*sb)/2,WHITE);
            }
            if(tur==2||tur==4)
            {
                        setcolor(DARKGRAY);
                        circle(mx+50,2*my-(my-4*sb)/2,rad);
                        setfillstyle(SOLID_FILL,DARKGRAY);
                        floodfill(mx+50,2*my-(my-4*sb)/2,DARKGRAY);
            }
            setcolor(pc);
}
void main_game(void)
{
            int s=0,j=0,i,l=0;
            curloc(0);
            if(((cl==1||cl==3)&&tur==1)||((cl==2||cl==4)&&tur==2))
            {
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            if(cl==3&&tur==1)
            {
                        check_solder();
                        s=bioskey(0);
                        s=s>>8;
                        if(s>1&&s<5)
                        {
                                    for(i=0;i<3;i++)
                                    {
                                                l++;
                                                if(sm[i]==1)
                                                            j++;
                                                if(s==j+1)
                                                            break;
                                    }
                        if(s==j+1&&((posy!=8&&k==1)||(posy!=1&&k==2)))
                                    sol_move(l);
                        }
            }
            j=0;
            l=0;
            if(cl==4&&tur==2)
            {
                        check_solder();
                        s=bioskey(0);
                        s=s>>8;
                        if(s>1&&s<5)
                        {
                                    for(i=0;i<3;i++)
                                    {
                                                l++;
                                                if(sm[i]==1)
                                                            j++;
                                                if(s==j+1)
                                                            break;
                                    }
                        if(s==j+1&&((posy!=8&&k==2)||(posy!=1&&k==1)))
                                    sol_move(l+3);
                        }
            }
}
void sol_move(int clr)
{
            if(clr==1&&k==1)
            {
                        posx--;
                        posy++;
                        curloc(1);
                        posx++;
                        posy--;
                        curloc(0);
                        whty[1][x1-1]=posy+1;
                        whtx[1][x1-1]=posx-1;
                        posx--;
                        posy++;
                        curloc(0);
                        tur=2;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            else if(clr==4&&k==1)
            {
                        posy--;
                        posx--;
                        curloc(1);
                        posy++;
                        posx++;
                        curloc(0);
                        blky[1][x1-1]=posy-1;
                        blkx[1][x1-1]=posx-1;
                        posy--;
                        posx--;
                        curloc(0);
                        tur=1;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            else if(clr==1&&k==2)
            {
                        posy--;
                        posx--;
                        curloc(1);
                        posy++;
                        posx++;
                        curloc(0);
                        whty[1][x1-1]=posy-1;
                        whtx[1][x1-1]=posx-1;
                        posy--;
                        posx--;
                        curloc(0);
                        tur=2;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            else if(clr==2&&k==1)
            {
                        whty[1][x1-1]=posy+1;
                        posy++;
                        curloc(0);
                        tur=2;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            else if(clr==5&&k==1)
            {
                        blky[1][x1-1]=posy-1;
                        posy--;
                        curloc(0);
                        tur=1;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            else if(clr==2&&k==2)
            {
                        whty[1][x1-1]=posy-1;
                        posy--;
                        curloc(0);
                        tur=2;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            else if(clr==4&&k==2)
            {
                        posx--;
                        posy++;
                        curloc(1);
                        posx++;
                        posy--;
                        curloc(0);
                        blky[1][x1-1]=posy+1;
                        blkx[1][x1-1]=posx-1;
                        posx--;
                        posy++;
                        curloc(0);
                        tur=1;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            else if(clr==5&&k==2)
            {
                        blky[1][x1-1]++;
                        posy++;
                        curloc(0);
                        tur=1;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            else if(clr==3&&k==1)
            {
                        posx++;
                        posy++;
                        curloc(1);
                        posx--;
                        posy--;
                        curloc(0);
                        whty[1][x1-1]=posy+1;
                        whtx[1][x1-1]=posx+1;
                        posx++;
                        posy++;
                        curloc(0);
                        tur=2;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            else if(clr==6&&k==1)
            {
                        posy--;
                        posx++;
                        curloc(1);
                        posy++;
                        posx--;
                        curloc(0);
                        blky[1][x1-1]=posy-1;
                        blkx[1][x1-1]=posx+1;
                        posy--;
                        posx++;
                        curloc(0);
                        tur=1;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            else if(clr==3&&k==2)
            {
                        posy--;
                        posx++;
                        curloc(1);
                        posy++;
                        posx--;
                        curloc(0);
                        whty[1][x1-1]=posy-1;
                        whtx[1][x1-1]=posx+1;
                        posy--;
                        posx++;
                        curloc(0);
                        tur=2;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
            else if(clr==6&&k==2)
            {
                        posy++;
                        posx++;
                        curloc(1);
                        posy--;
                        posx--;
                        curloc(0);
                        blky[1][x1-1]=posy+1;
                        blkx[1][x1-1]=posx+1;
                        posy++;
                        posx++;
                        curloc(0);
                        tur=1;
                        clearviewport();
                        bdesign(1,0);
                        warriors();
                        turn();
            }
}
void check_solder()
{
            int p=1,l=1;
            sm[0]=0;
            sm[1]=0;
            sm[2]=0;
            if(k==2)
                        p=-1;
            if(tur==1)
            {
                        posy+=p;
                        posx--;
                        curloc(0);
                        if(cl==2||cl==4)
                        {
                                    bdesign(3,l++);
                                    warriors();
                                    turn();
                                    delay(1000);
                                    sm[0]=1;
                        }
                        posx++;
                        curloc(0);
                        if(cl==5)
                        {
                                    bdesign(2,l++);
                                    warriors();
                                    turn();
                                    delay(1000);
                                    sm[1]=1;
                        }
                        posx++;
                        curloc(0);
                        if(cl==2||cl==4)
                        {
                                    bdesign(3,l++);
                                    warriors();
                                    turn();
                                    delay(1000);
                                    sm[2]=1;
                        }
                        posx--;
                        posy-=p;
                        curloc(0);
            }
            if(tur==2)
            {
                        posy-=p;
                        posx--;
                        curloc(0);
                        if(cl==1||cl==3)
                        {
                                    bdesign(3,l++);
                                    warriors();
                                    turn();
                                    delay(1000);
                                    sm[0]=1;
                        }
                        posx+=1;
                        curloc(0);
                        if(cl==5)
                        {
                                    bdesign(2,l++);
                                    warriors();
                                    turn();
                                    delay(1000);
                                    sm[1]=1;
                        }
                        posx+=1;
                        curloc(0);
                        if(cl==1||cl==3)
                        {
                                    bdesign(3,l++);
                                    warriors();
                                    turn();
                                    delay(1000);
                                    sm[2]=1;
                        }
                        posx--;
                        posy+=p;
                        curloc(0);
            }
            bdesign(1,0);
            warriors();
            turn();

}