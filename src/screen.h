/* 
 * File:   screen.h
 * Author: bartexsz
 *
 * Created on 4 marzec 2012, 18:39
 */

#ifndef SCREEN_H
#define	SCREEN_H

#include"common.h"

class screen
{
public:
    screen();
    ~screen();
    void put(char c);
    void clear();
    void write(char *c);
    void move_cursor();
private:
    u32int y;
    u32int x;
    u16int *video_memory;
    void scroll();
    

};
#endif	/* SCREEN_H */

