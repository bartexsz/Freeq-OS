/* 
 * File:   gdt_entry.h
 * Author: bartomiej
 *
 * Created on 20 marzec 2012, 22:44
 */

#ifndef GDT_ENTRY_H
#define	GDT_ENTRY_H

#include "common.h"

class gdt_entry {
public:
    
    u16int limit_low;
    u16int base_low;
    u8int base_middle;
    u8int access;
    u8int granularity;
    u8int base_high;
    
    gdt_entry();
    ~gdt_entry();
private:

}__attribute__((packed));

#endif	/* GDT_ENTRY_H */

