/* 
 * File:   descrtables.h
 * Author: Bartłomiej Szcześniak
 *
 * Created on 25 marzec 2012, 13:24
 */

#ifndef DESCRTABLES_H
#define	DESCRTABLES_H

#include "gdt_entry.h"
#include "gdtptr.h"
#include "common.h"
#include "screen.h"

class descrtables
{
public:
    
    screen console;
    gdt_entry gdt_entries[5];
    gdtptr gdt_pointer;
    void init_gdt();
    void gdt_set_gate(s32int, u32int, u32int, u8int, u8int );
    void gdt_flush(u32int);
    descrtables();
    ~descrtables();
private:

};

#endif	/* DESCRTABLES_H */

