#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int s21_sprintf(char *str, const char *format, ...);
int pars_format(const char *format, int i);

struct danno_format {
  struct {
    int plus, minus, hesh, nool, space;
  } flagi;
  struct {
    int zwezda;
    long int col_simvolov;
  } shirina;

  struct {
    unsigned int chislo;
    int zwezda;
  } tochnost;
  char dlina;
  char specificator;
};

struct danno_format znach;

int main() {
  char *str = NULL;
  // char *str1 = NULL;
  const char *format = "%+234.31c%35.24d%*c%%";  //+0102.*d
  char *uno_str = "d";
  int duo_str = 2;
  double trio_str = 1.21;

  s21_sprintf(str, format, uno_str, duo_str, trio_str);

  // sprintf(str1, "%s%d%f", uno_str, duo_str, trio_str);

  printf("s21_f= %s\n", str);
  // printf("stand_f= %s", str1);
}

int s21_sprintf(char *str, const char *format, ...) {
  int i = 1;
  printf("str%s\n", str);
  // это все в цикле
  while (i >= 0) {
    i = pars_format(format, i);
    printf("i = %d\n", i);
    str = "lol";
    va_list predarg;
    va_start(predarg, format);
    // printf("zwezda-2===$$$ %d\n", znach.shirina.zwezda);
    printf("bukva4  === %c\n", znach.specificator);
    printf("dlina=1= %ld\n", znach.shirina.col_simvolov);

    // znach.shirina.col_simvolov = 0;
    printf("zwezda-2===12 %d\n", znach.shirina.zwezda);
    printf("dlina== %ld\n", znach.shirina.col_simvolov);
    printf("bukva3  = %c\n", znach.specificator);
    printf("struct %d\n", znach.flagi.plus);
  }
  return 1;
}

int pars_format(const char *format, int i) {
  printf("zwezda-1===$$$ %d\n", znach.shirina.zwezda);
  struct danno_format znach = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, 0, 0};
  printf("zwezda-2===$$$ %d\n", znach.shirina.zwezda);
  int wixod = 0;
  // i++;
  printf("pizda\n");
  while (/*(format[i] != '%')*/ (wixod == 0) && (format[i] != '\0')) {
    printf("pizda2\n");
    switch (format[i]) {
      case '-':
        znach.flagi.minus = 1;
        break;
      case '+':
        znach.flagi.plus = 1;
        printf("struct123=== %d\n", znach.flagi.plus);
        break;
      case ' ':
        znach.flagi.space = 1;
        break;
      case '#':
        znach.flagi.hesh = 1;
        break;
      case '0':
        if ((format[i - 1] >= '0') && (format[i - 1] <= '9')) {
          znach.shirina.col_simvolov =
              (znach.shirina.col_simvolov * 10) + (format[i] - '0');
          printf("dlina2;' %ld\n", znach.shirina.col_simvolov);
          i++;
        } else {
          znach.flagi.nool = 1;
          printf("struct22 %d\n", znach.flagi.nool);
          break;
        }
      case '1' ... '9':
        znach.shirina.col_simvolov =
            (znach.shirina.col_simvolov * 10) + (format[i] - '0');
        printf("dlina %ld\n", znach.shirina.col_simvolov);
        break;
      case '*':
        znach.shirina.zwezda = 1;
        printf("zwezda-2=== %d\n", znach.shirina.zwezda);
        break;
      case '.':
        i++;
        if (format[i] == '*') {
          znach.tochnost.zwezda = 1;

        } else {
          while ((format[i] >= '0') && (format[i] <= '9')) {
            znach.tochnost.chislo =
                (znach.tochnost.chislo * 10) + (format[i] - '0');
            i++;
          }
          i--;
        }
        printf("chislo %d\n", znach.tochnost.chislo);
        printf("zwezda %d\n", znach.tochnost.zwezda);
        break;
      case 'h':
        znach.dlina = format[i];
        break;
      case 'l':
        znach.dlina = format[i];
        break;
      case 'L':
        znach.dlina = format[i];
        break;
      case 'c':
        znach.specificator = format[i];
        printf("bukva %c\n", znach.specificator);
        break;
      case 'd':
        znach.specificator = format[i];
        printf("bukva2 %c\n", znach.specificator);
        break;
      case 'i':
        znach.specificator = format[i];
        break;
      case 'e':
        znach.specificator = format[i];
        break;
      case 'E':
        znach.specificator = format[i];
        break;
      case 'f':
        znach.specificator = format[i];
        break;
      case 'g':
        znach.specificator = format[i];
        break;
      case 'G':
        znach.specificator = format[i];
        break;
      case 'o':
        znach.specificator = format[i];
        break;
      case 's':
        znach.specificator = format[i];
        break;
      case 'u':
        znach.specificator = format[i];
        break;
      case 'x':
        znach.specificator = format[i];
        break;
      case 'X':
        znach.specificator = format[i];
        break;
      case 'p':
        znach.specificator = format[i];
        break;
      case 'n':
        znach.specificator = format[i];
        break;
      case '%':
        if (format[i - 1] == '%') {
          znach.specificator = format[i];
          // i++;
          printf("i2%d\n", i);
          printf("prozent %c\n", znach.specificator);
        }
        wixod = 1;
        // проnисать обнуление переменной колличества символов
        /* code */
        break;
      default:
        break;
    }
    i++;
  }
  if (format[i] == '\0') {
    i = -1;
  }
  return i;
}
