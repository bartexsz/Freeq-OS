/* 
 * File:   descrtables.cpp
 * Author: Bartłomiej Szcześniak
 * 
 * Created on 25 marzec 2012, 13:24
 */

#include "descrtables.h"


descrtables::descrtables() {
    console.write("Initialising GDT\n");
    init_gdt();
}

descrtables::~descrtables() {
}

void descrtables::init_gdt(){
    console.write("setting pointer\n");
    gdt_pointer.limit = (sizeof(gdt_entry) *5) -1;
    gdt_pointer.base = (u64int)&gdt_entries;
    
    console.write("setting gates");
    gdt_set_gate(0,0,0,0,0);
    gdt_set_gate(1,0,0xFFFFFFFF, 0x9A, 0xCF);
    gdt_set_gate(2,0,0xFFFFFFFF, 0x92, 0xCF);
    gdt_set_gate(3,0,0xFFFFFFFF, 0xFA, 0xCF);
    gdt_set_gate(4,0,0xFFFFFFFF, 0xF2, 0xCF);
    
    console.write("flushing gdt\n");
    gdt_flush((u64int)&gdt_pointer);
}

void descrtables::gdt_set_gate(s32int num, u32int base, u32int limit, u8int access, u8int gran)
{
    gdt_entries[num].base_low = (base & 0xFFFF);
    gdt_entries[num].base_middle = (base >> 16) & 0xFF;
    gdt_entries[num].base_high = (base >> 24) & 0xFF;
    
    gdt_entries[num].limit_low = (limit & 0xFFFF);
    gdt_entries[num].granularity = (limit >> 16) & 0x0F;
    gdt_entries[num].granularity |= gran & 0xF0;
    gdt_entries[num].access = access;
}
