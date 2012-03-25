#include "screen.h"
#include "descrtables.h"

int main(struct multiboot *mboot_ptr)
{
  screen main_screen;
  descrtables dt;
  main_screen.write("Hello World \n");
  main_screen.write("Freeq OS \n");
  main_screen.write("by Bartlomiej Szczesniak(aka bartexsz, szcbawokon, Jurij Popov)");
  return 0;
}