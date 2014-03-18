/* 
 * File:   gdtptr.h
 * Author: bartomiej
 *
 * Created on 25 marzec 2012, 13:31
 */

#ifndef GDTPTR_H
#define	GDTPTR_H

#include "common.h"

class gdtptr {
public:
    u16int limit;
    u32int base;

    gdtptr();
    ~gdtptr();
private:

}__attribute__((packed));

#endif	/* GDTPTR_H */

