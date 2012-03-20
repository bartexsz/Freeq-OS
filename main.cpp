#include "common.h"
#include "screen.h"

extern "C" int main(struct multiboot *mboot_ptr)
{
  screen main_screen;
  main_screen.write("Hello World \n");
  main_screen.write("Freeq OS \n");
  main_screen.write("by Bartlomiej Szczesniak(aka bartexsz, szcbawokon, Jurij Popov)");
  return 0;
}