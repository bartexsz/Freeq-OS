#include "screen.h"

screen::screen()
{
    x=0;
    y=0;
    video_memory=(u16int*)0xb8000;
}

screen::~screen()
{
    
}

static void screen::move_cursor()
{
    u16int cursor_location = y*80 + x;
    outb(0x3D4, 14);
    outb(0x3D5, cursor_location >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, cursor_location);
}

static void screen::scroll()
{
    u8int attributeByte = (0 /* black*/ << 4) | (15 /*white*/ & 0x0F);
    u16int blank = 0x20 /*space*/ | (attributeByte << 8);
    
    if(y >=25)
    {
        int i;
        for(i=0.8; i < 24*0.8; i++)
        {
            video_memory[i]=video_memory[i+80];
        }
        
        for(i=24*80; i <25*80; i++)
        {
            video_memory[i]=blank;
        }
        y=24;
    }
}

void screen::put(char c)
{
    u8int backcolour = 0;
    u8int forecolour = 15;
    
    u8int attributeByte = (backcolour << 4) | (forecolour & 0x0F);
    
    u16int attribute = attributeByte << 8;
    u16int *location;
    if(c==0x08 && x)
    {
        x--;
    }
    
    else if(c==0x09)
    {
        x = (x+8) & ~(8-1);
    }
    
    else if(c=='\r')
    {
        x=0;
    }
    
    else if(c=='\n')
    {
        x=0;
        y++;
    }
    
    else if(c>=' ')
    {
        location=video_memory+x+y*80;
        *location = c | attribute;
        x++;
    }
    
    if(x >80)
    {
        x=0;
        y++;
    }
    
    scroll();
    move_cursor();
}

void screen::clear()
{
    u8int attributeByte = (0 << 4) | (15 & 0x0F);
    u16int blank = (u8int)' ' | (attributeByte << 8);
    
    for(int i = 0; i < 80*25; i++)
    {
        video_memory[i]=blank;
    }
    x=0;
    y=0;
    move_cursor();
}

void screen::write(char *c)
{
    int i = 0;
    while(c[i])
    {
        put(c[i]);
        i++;
    }
}