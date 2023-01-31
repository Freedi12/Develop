#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s21_sprintf(char *str, const char *format, ...);
char *swjaz(char n);

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
  char str[1024];
  // char str1[1024];
  const char *format = "%12c";  //%-12c%+35.24d%e
  char uno_str = {'s'};
  // int duo_str = 2;
  // double trio_str = 1.21;

  s21_sprintf(str, format,  uno_str/*duo_str,, trio_str*/);
  // sprintf(str1, "%-12c", uno_str /*duo_str, trio_str*/);
  printf("%s\n", str);
  // printf("%s\n", str1);
}

char s21_sprintf(char *str, const char *format, ...) {
  int i = 1;
  char *str1;
  va_list predarg;
  va_start(predarg, format);
  while (format[i] != '\0') {
    switch (format[i]) {
      case '-':
        znach.flagi.minus = 1;
        break;
      case '+':
        znach.flagi.plus = 1;
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
          i++;
        } else {
          znach.flagi.nool = 1;
          break;
        }
      case '1' ... '9':
        znach.shirina.col_simvolov =
            (znach.shirina.col_simvolov * 10) + (format[i] - '0');
        break;
      case '*':
        znach.shirina.zwezda = 1;
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
        znach.specificator =
            format[i];  // нужно ли заполнение спецификатора !?!?!?!?
        int bol = 0;
        if (znach.shirina.zwezda == 1) {
          bol = va_arg(predarg, int);
          if (bol < 0) {
            znach.flagi.minus = 1;
            znach.shirina.col_simvolov = (-1 * bol);
          } else {
            znach.shirina.col_simvolov = bol;
          }
        }
        str1 = swjaz(va_arg(predarg, int));
        strcat(str, str1);
        memset(&znach, 0, sizeof(znach));
        free(str1);
        break;
      case 'd':
        znach.specificator = format[i];
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
        }

        break;
      default:
        break;
    }
    i++;
  }
  if (format[i] == '\0') {
    i = -1;
  }
  va_end(predarg);
  return *str;
}

char *swjaz(char dev) {
  char *pri = '\0';
  if (znach.shirina.col_simvolov == 0) {
    pri = (char *)malloc(sizeof(10));
    pri[0] = dev;
  } else {
    pri = (char *)malloc(sizeof(znach.shirina.col_simvolov + 1));
    if (znach.flagi.minus == 1) {
      pri[0] = dev;
      for (int i = 1; i < znach.shirina.col_simvolov; i++) {
        pri[i] = ' ';
      }
    } else {
      for (int i = 0; i < znach.shirina.col_simvolov-1; i++) {
        pri[i] = ' ';
      }
      pri[znach.shirina.col_simvolov-1] = dev;
    }
  }
  // printf("1=/=/==/=/ %c\n", dev);
  return pri;
}
