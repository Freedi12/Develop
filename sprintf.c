#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char str1[1024];
  const char *format = "%12c";  //%-12c%+35.24d%e
  char uno_str = {'s'};
//   int duo_str = 2;
  // double trio_str = 1.21;

  sprintf(str1, format, uno_str/* duo_str,, trio_str*/);
  printf("%s\n", str1);
}