/* 
 * File:   kernel_main.h
 * Author: bartomiej
 *
 * Created on 31 marzec 2012, 17:35
 */

#ifndef KERNEL_MAIN_H
#define	KERNEL_MAIN_H

#include "screen.h"
#include "descrtables.h"

class kernel_main {
public:
    descrtables dt;
    kernel_main();
    ~kernel_main();
private:
    
protected:
      screen main_screen;

};

#endif	/* KERNEL_MAIN_H */

