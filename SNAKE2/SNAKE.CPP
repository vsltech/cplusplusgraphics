// the Snake
// Copyright (c)1996 Fredrik Wangel (WaF)
//

#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "snake.h"

void waitretrace(void);
void waitdisplay(void);
int  keyhit(void);
void flushkbd(void);
void setborderc(byte color);
void show_display(void);
void hide_display(void);
void draw_score(void);
void fade_to_black(byte start, byte stop, byte steps);
void fade_to_color(byte start, byte stop, byte steps);

#define TRUE  '-'/'-'
#define FALSE '-'-'-'

#define KEY_SOUND 'S'
#define KEY_ESC   27

#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77

#define SCRSX  80
#define XSIZE  80
#define YSIZE  40
#define BLOCKS 20
#define LX2POS 44
#define LXPOS   1
#define LYPOS  YSIZE + 2
#define GP     ((YSIZE * BLOCKS) / XSIZE)    // Base points

#define ADDSNAKE   15 // random(x) at increase
#define LOOSESNAKE  4 // and decrease respectively
#define BEGINSNAKE  2 // starting length of the snake
#define FROGAMOUNT  5 // number of frogs

#define HI(a) (a & 0xff00) / 0x100
#define LO(a) (a & 0x00ff)
#define FOREVER for(;;)

byte key, firsttime = 1, ljud = 1;
byte grid[XSIZE][YSIZE];
byte frx[FROGAMOUNT], fry[FROGAMOUNT];
int  snx[1500], sny[1500];
int  length, head, tail;
int  grow, decline, frogtime[FROGAMOUNT];
int  millifemtio, tid;
long score;
long bestscore = 0;
int  besttid = 0, bestlength = 0;

const word Clear = 0x2000 + byte(' ');
const word Frog  = 0x2A00 + byte('ê');
const word Snake = 0x2C00 + byte('@');
const word Brick = 0x2600 + byte('ð');
const word Block = 0x2F00 + byte('Û');

void save_palette()
{
	for(word i = 0; i < 64; i++)
		getpalrgb(i, pal_orig[i].r, pal_orig[i].g, pal_orig[i].b);
}

void restore_palette()
{
	for(word i = 0; i < 64; i++)
		setpalrgb(i, pal_orig[i].r, pal_orig[i].g, pal_orig[i].b);
}

void clear_palette()
{
	for(word i = 0; i < 64; i++)
	{
		pal[i].r = 0;
		pal[i].g = 0;
		pal[i].b = 0;
		setpalrgb(i, 0, 0, 0);
	}
}
void waitforkey(void)
{
	gotoxy(LXPOS, LYPOS + 2);
	printf("** Press any key to begin **");
	clreol();
	printf("\r");
	flushkbd();
	while(!keyhit());
	clreol();
}

void notify(void)
{
	if(ljud)
	{
		buzz(2500); delay(25);
		buzz(1500); delay(25); buzz(750); delay(50);
		buzz(1000); delay(100); quiet();
	}
	draw_score();
	gotoxy(LXPOS, LYPOS + 1);
	printf("You played for %04d sec.", tid);
	clreol();
	delay(500);
}

void put_block(word x, word y, word item)
{
	asm {
		mov   ax, 0xb800
		mov   es, ax
		mov   ax, y
		mov   dl, SCRSX
		shl   dl, 1
		mul   dl
		mov   dx, x
		shl   dx, 1
		add   ax, dx
		mov   di, ax
		mov   ax, item
		mov   [es:di], ax
	}
}

void set_point(word x, word y, word item)
{
	put_block(x, y, item);
	grid[x][y] = HI(item);
}

void clear_grid(void)
{
	word x, y;

	hide_display();
	for(x=0; x < XSIZE; x++)
	{
		for(y=0; y < YSIZE; y++)
			if(grid[x][y] != HI(Clear))
				set_point(x, y, Clear);
		set_point(x, YSIZE - 1, Block);
		set_point(x, 0, Block);
	}
	for(y=0; y < YSIZE; y++)
	{
		set_point(XSIZE - 1, y, Block);
		set_point(0, y, Block);
	}
	for(x=0; x < BLOCKS; x++)
		set_point(random(XSIZE - 1) + 1, random(YSIZE - 1) + 1, Block);
	show_display();
}

void draw_score(void)
{
	gotoxy(LXPOS, LYPOS);
	printf("Length: %04d  Points: %010ld\r", length, score);
	if((score > bestscore) || (length > bestlength))
	{
		if(score > bestscore)
			bestscore = score;
		else
			bestlength = length;
		gotoxy(LX2POS, LYPOS);
		printf("Longest: %04d  Highscore: %010ld\r", bestlength, bestscore);
//		printf("Longest: %04d  Highscore: %010ld\r", bestlength, bestscore);
	}
}

void create_frog(int n)
{
	word x, y;
	do
	{
		x = random(XSIZE - 1) + 1;
		y = random(YSIZE - 1) + 1;
	}
	while (grid[x][y] != HI(Clear));
	frx[n] = x;
	fry[n] = y;
	set_point(x, y, Frog);
	frogtime[n] = 20 + random(50);
	if(ljud)
	{
		buzz(50); delay(5); quiet();
	}
}

void check_frogs(void)
{
	word n, x, y;
	for(n=0; n < FROGAMOUNT; n++)
		if(!frogtime[n]--)
		{
			x = frx[n];
			y = fry[n];
			create_frog(n);
			set_point(x, y, random(10)?Clear:Brick);
		}
}

void replace_frog(word x, word y)
{
	word n;
	for(n=0; n < FROGAMOUNT; n++)
		if(frx[n] == x && fry[n] == y)
			create_frog(n);
	set_point(x, y, Clear);
}

void setup_game(void)
{
	clear_grid();
	score = 0;
	millifemtio = 0;
	tid = 0;
	length = 1;
	grow = BEGINSNAKE - 1;
	decline = 0;
	head = tail = 0;
	snx[0] = XSIZE / 2;
	sny[0] = YSIZE / 2;
	set_point(snx[0], sny[0], Snake);
	key = KEY_RIGHT;
	for(word i=0; i < FROGAMOUNT; i++)
		create_frog(i);
	if(firsttime)
	{
		firsttime = 0;
		fade_to_color();
	}
	waitforkey();
	draw_score();
	gotoxy(LXPOS, LYPOS + 1);
	clreol();
}

bool play_one_game(void)
{
	byte item;
	int nx, ny;
	byte code;

	gotoxy(LX2POS, LYPOS);
	printf("Longest: %04d  Highscore: %010ld\r", bestlength, bestscore);
	gotoxy(LX2POS, LYPOS + 1);
	printf("Best Time: %04d\r", besttid);
	FOREVER
	{
		waitretrace();
		delay(50);
		millifemtio++;
		if(!(millifemtio % 20))
		{
			millifemtio = 0;
			tid++;
			gotoxy(LXPOS, LYPOS + 1);
			printf("Time: %04d\r", tid);
			if(tid > besttid)
			{
				besttid = tid;
				gotoxy(LX2POS, LYPOS + 1);
				printf("Best Time: %04d\r", besttid);
			}
		}
		if(keyhit())
		{
			code = getch();
			if(code == 0)
			{
				code = getch();
				switch(code)
				{
					case KEY_UP    :
					case KEY_DOWN  :
					case KEY_LEFT  :
					case KEY_RIGHT : key = code; break;
				}
			}
			else
				switch(toupper(code))
				{
					case KEY_ESC   :	return TRUE;
					case KEY_SOUND :	ljud = 1 - ljud;
											setborderc(ljud * 12);
											break;
				}
		}
		nx = snx[head];
		ny = sny[head];
		switch(key)
		{
			case KEY_UP    : ny -= 1; break;
			case KEY_DOWN  : ny += 1; break;
			case KEY_LEFT  : nx -= 1; break;
			case KEY_RIGHT : nx += 1; break;
		}
		item = grid[nx][ny];
		switch(item)
		{
			case HI(Block) :  return FALSE;
			case HI(Frog)  :  grow += 2 + random(ADDSNAKE);
									score += GP * (length + grow) * (1 + (tid * tid) / 300);
									replace_frog(nx, ny);
									if(ljud)
									{
										buzz(250); delay(10); buzz(500); delay(10); quiet();
                           }
			case HI(Clear) :  head = (head + 1) % 1500;
									snx[head] = nx;
									sny[head] = ny;
									set_point(nx, ny, Snake);
									if(decline)
									{
										decline--;
										length--;
										if(length < 1)
											return FALSE;
										draw_score();
										if(ljud)
										{
											buzz(1500); delay(5); quiet();
										}
										set_point(snx[tail], sny[tail], Clear);
										tail = (tail + 1) % 1500;
									}
									if(grow)
									{
										grow--;
										length++;
										draw_score();
									}
									else
									{
										set_point(snx[tail], sny[tail], Clear);
										tail = (tail + 1) % 1500;
									}
									break;
			case HI(Brick) :  decline += 1 + random(LOOSESNAKE);
									set_point(nx, ny, Clear);
									break;
			case HI(Snake) :  return FALSE;
		}
		check_frogs();
	}
}

void play_game(void)
{
	FOREVER
	{
		setup_game();
		if(play_one_game())
			return;
		notify();
	}
}

void set_up(void)
{
	randomize();
	textmode(C4350);
	clrscr();
}

void clean_up(void)
{
	textmode(C80);
	printf("the Snake (c)1996 Fredrik Wangel (WaF)\r\n");
	flushkbd();
}

int main(void)
{
	save_palette();
	fade_to_black();
	set_up();
	setborderc(12);
	play_game();
	setborderc(0);
	fade_to_black();
	hide_display();
	clean_up();
	clear_palette();
	show_display();
	fade_to_color();
	restore_palette();
	return 0;
}
