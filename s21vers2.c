#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int s21_sprintf(char *str, const char *format, ...);
void pars_format(const char *format);

struct danno_format {
  struct {
    int plus, minus, hesh, nool, space;
  }flagi;
struct {
  int zwezda;
  long int col_simvolov;
}shirina;

  int chir_polja;
  int tochnost;
};

struct danno_format znach;

int main() {
  char *str = NULL;
  // char *str1 = NULL;
  const char *format = "%+0d";
  char *uno_str = "d";
  int duo_str = 2;
  double trio_str = 1.21;

  s21_sprintf(str, format, uno_str, duo_str, trio_str);

  // sprintf(str1, "%s%d%f", uno_str, duo_str, trio_str);

  printf("s21_f= %s\n", str);
  // printf("stand_f= %s", str1);
}

int s21_sprintf(char *str, const char *format, ...) {
  printf("str%s\n", str);
  pars_format(format);
str = "lol";
  va_list predarg;
  va_start(predarg, format);
  return 1;
}

void pars_format(const char *format) {
  int i = 0;
  while (/*(format[i] != '%') && */(format[i] != '\0')) {
    switch (format[i]) {
        case '-':
          znach.flagi.minus = 1;
          break;
        case '+':
          znach.flagi.plus = 1;
          printf ("struct %d\n", znach.flagi.plus);
          break;
        case ' ':
          znach.flagi.space = 1;
          break;
        case '#':
          znach.flagi.hesh = 1;
          break;
        case '0':
        if ((format[i-1] >= '0') && (format[i-1] <='9')) {
          znach.shirina.col_simvolov = (znach.shirina.col_simvolov *10)+(format[i]-'0');
        } else {
          znach.flagi.nool = 1;
          printf ("struct22 %d\n", znach.flagi.nool);
          break;
        }

        case '1' ... '9':
          /* code */
          break;
        case '*':
          /* code */
          break;
        case '.':
          /* code */
          break;
        case 'h':
          /* code */
          break;
        case 'I':
          /* code */
          break;
        case 'L':
          /* code */
          break;
        case 'c':
          /* code */
          break;
        case 'd':
          /* code */
          break;
        case 'i':
          /* code */
          break;
        case 'e':
          /* code */
          break;
        case 'E':
          /* code */
          break;
        case 'f':
          /* code */
          break;
        case 'g':
          /* code */
          break;
        case 'G':
          /* code */
          break;
        case 'o':
          /* code */
          break;
        case 's':
          /* code */
          break;
        case 'u':
          /* code */
          break;
        case 'x':
          /* code */
          break;
        case 'X':
          /* code */
          break;
        case 'p':
          /* code */
          break;
        case 'n':
          /* code */
          break;
        case '%':
          /* code */
          break;
        default:
          break;
      }
      i++;
  }
}
