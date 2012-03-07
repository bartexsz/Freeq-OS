#include "common.h"
#include "screen.h"

int main(struct multiboot *mboot_ptr)
{
  screen_clear();
  screen_write("Hello World \n");
  screen_write("Freeq OS \n");
  screen_write("by Bartlomiej Szczesniak(aka bartexsz, szcbawokon, Jurij Popov)");
  return 0;
}