typedef unsigned char byte;
typedef unsigned int  word;
typedef unsigned char bool;
typedef struct {
			byte r, g, b;
		} rgb;

rgb pal[64];
rgb pal_orig[64];

void waitretrace(void)
{
  while((inportb(0x3DA) & 0x08) != 0);
  while((inportb(0x3DA) & 0x08) == 0);
}

void waitdisplay(void)
{
  while((inportb(0x03DA) & 0x08) == 0);
  while((inportb(0x03DA) & 0x08) != 0);
}

void getpalrgb(byte c, byte &r, byte &g, byte &b)
{
	outportb(0x03c7, c);
	r = inportb(0x03c9);
	g = inportb(0x03c9);
	b = inportb(0x03c9);
}

void setpalrgb(byte c, byte r, byte g, byte b)
{
	outportb(0x03c8, c);
	outportb(0x03c9, r);
	outportb(0x03c9, g);
	outportb(0x03c9, b);
}

int keyhit(void)
{
	byte qq;
	asm {
		mov bx, 0x0040
		mov es, bx
		mov ax, es:[0x001C]
		sub ax, es:[0x001A]
		mov qq, al
	}
	return qq;
}

void flushkbd(void)
{
	l1:;
	asm {
		mov ah, 0x06
		mov dl, 0x0FF
		int 0x21
		jnz l1
	}
}

void buzz(word freq)
{
	asm {
		MOV     BX, [freq]
		MOV     AX, 0x34DD
		MOV     DX, 0x0012
		CMP     DX, BX
		JNB     l1
		DIV     BX
		MOV     BX, AX
		IN      AL, 0x61
		TEST    AL, 0x03
		JNE     l2
		OR      AL, 0x03
		OUT     0x61, AL
		MOV     AL, 0x0B6
		OUT     0x43, AL
	}
	l2:;
	asm {
		MOV     AL, BL
		OUT     0x42, AL
		MOV     AL, BH
		OUT     0x42, AL
	}
	l1:;
}

void quiet(void)
{
	asm {
		IN  AL, 0x61
		AND AL, 0x0FC
		OUT 0x61, AL
	}
}

void setborderc(byte color)
{
	asm {
		MOV AX, 0x1001
		MOV BH, [color]
		INT 0x10
	}
}

void show_display(void)
{
	asm {
		MOV AX, 0x1200
		MOV BL, 0x36
		INT 0x10
	}
}

void hide_display(void)
{
	asm {
		MOV AX, 0x1201
		MOV BL, 0x36
		INT 0x10
	}
}

void fade_to_black(byte start = 0, byte stop = 63, byte steps = 63)
{
	word i, j = 0;
	byte r, g, b, r2, g2, b2;
	do
	{
		j++;
		for(i = start; i <= stop; i++)
		{
			getpalrgb(i, r, g, b);
			r2 = r; g2 = g; b2 = b;
			if(r > 0) r--;
			if(g > 0) g--;
			if(b > 0) b--;
			if(r != r2 || g != g2 || b != b2)
				setpalrgb(i, r, g, b);
			if(!(i % 32))
				waitdisplay();
		}
	}
	while(j <= steps);
}

void fade_to_color(byte start = 0, byte stop = 63, byte steps = 63)
{
	word i, j = 0;
	byte r, g, b, r2, g2, b2;
	do
	{
		j++;
		for(i = start; i <= stop; i++)
		{
			getpalrgb(i, r, g, b);
			r2 = r; g2 = g; b2 = b;
			if(r < pal_orig[i].r) r++;
			if(g < pal_orig[i].g) g++;
			if(b < pal_orig[i].b) b++;
			if(r > pal_orig[i].r) r--;
			if(g > pal_orig[i].g) g--;
			if(b > pal_orig[i].b) b--;
			if(r != r2 || g != g2 || b != b2)
				setpalrgb(i, r, g, b);
			if(!(i % 32))
				waitdisplay();
		}
	}
	while(j <= steps);
}
