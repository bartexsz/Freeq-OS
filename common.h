/* 
 * File:   common.h
 * Author: bartexsz
 *
 * Created on 4 marzec 2012, 18:19
 */

#ifndef COMMON_H
#define	COMMON_H

typedef unsigned int u32int;
typedef int s32int;
typedef unsigned short u16int;
typedef short s16int;
typedef unsigned char u8int;
typedef char s8int;

void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);


#endif	/* COMMON_H */

