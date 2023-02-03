#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s21_sprintf(char *str, const char *format, ...);
char *swjaz(char n);
char *l_c_fun(wchar_t lc);
char *fun_d(int n);
char *fun_flagi(char *str);

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
  (void)setlocale(LC_ALL, "");

  char str[1024];
  // char str1[1024];
  const char *format = "%lc%-10d";  //%-12c%+35.24d%e
  // char uno_str = {'s'};
  wchar_t lc = L'd';
  int duo_str = -2;
  // double trio_str = 1.21;

  s21_sprintf(str, format, lc, duo_str /*uno_str  trio_str*/);
  // sprintf(str1, "%-12c", uno_str /*duo_str, trio_str*/);
  printf("%s\n", str);
  // printf("%s\n", str1);
}

char s21_sprintf(char *str, const char *format, ...) {
  int i = 1;
  char *str1 = NULL;
  *str = '\0';
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
          // i++;
          break;
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
        if (znach.dlina == 'l') {
          str1 = l_c_fun(va_arg(predarg, wchar_t));
        } else {
          str1 = swjaz(va_arg(predarg, int));
        }
        strcat(str, str1);
        memset(&znach, 0, sizeof(znach));
        if (str1 != NULL) {
          free(str1);
        }
        break;
      case 'd':
        znach.specificator = format[i];
        str1 = fun_d(va_arg(predarg, int));
        strcat(str, str1);
        memset(&znach, 0, sizeof(znach));
        if (str1 != NULL) {
          free(str1);
        }
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

char *fun_d(int n) {
  char *str_i = '\0';
  int len = 0, buf_n = 0, buf = 0;

  str_i = (char *)malloc(12 * sizeof(char));

  if (n > 0) {
    buf_n = n;
    while (buf_n > 9) {
      len++;
      buf_n /= 10;
    }
    buf_n = n;
    for (int a = 0; len >= 0; a++) {
      if (znach.flagi.plus == 1) {
        str_i[0] = '+';
        znach.shirina.col_simvolov--;
        a++;
      }
      if (znach.flagi.space == 1) {
        str_i[0] = ' ';
        znach.shirina.col_simvolov--;
        a++;
      }
      buf = pow(10, len);
      str_i[a] = (buf_n / buf) + '0';
      buf_n = buf_n - ((buf_n / buf) * buf);
      len--;
    }
  } else {
    // if (znach.flagi.minus == 1) {
    znach.shirina.col_simvolov--;
    // }
    buf_n = n * (-1);
    while (buf_n > 9) {
      len++;
      buf_n /= 10;
    }
    buf_n = n * (-1);
    str_i[0] = '-';
    for (int a = 1; len >= 0; a++) {
      buf = pow(10, len);
      str_i[a] = (buf_n / buf) + '0';
      buf_n = buf_n - ((buf_n / buf) * buf);
      len--;
    }
  }
  if (znach.shirina.col_simvolov > 0) {
    str_i = fun_flagi(str_i);
  }
  return str_i;
}

char *fun_flagi(char *str) {
  char *str2 = "w";
  char *str3 = "";
  int i = 0;

  str3 = (char *)malloc(1024 * sizeof(char));

  while (str[i] != '\0') {
    str3[i] = str[i];
    i++;
  }
  str2 = (char *)malloc(sizeof(znach.shirina.col_simvolov * 2));
  for (int i = 0; i < znach.shirina.col_simvolov - 1; i++) {
    str2[i] = ' ';
  }
  if (znach.flagi.minus == 0) {
    strcat(str2, str3);
    free(str3);
    return str2;
  } else {
    strcat(str3, str2);
    free(str2);
    return str3;
  }
}

char *l_c_fun(wchar_t lc) {
  char *pri = "q";
  char *pri2 = "w";
  int n = 10;
  wchar_t e_lc = '\0';
  wchar_t m_ls[3];

  if (znach.shirina.col_simvolov > 0) {
    n = znach.shirina.col_simvolov * 2;
  }
  m_ls[0] = lc;
  m_ls[1] = e_lc;

  pri = (char *)malloc(n * MB_CUR_MAX + 1);
  wcstombs(pri, m_ls, n);

  if (znach.shirina.col_simvolov > 0) {
    pri2 = (char *)malloc(sizeof(znach.shirina.col_simvolov * 2));
    for (int i = 0; i < znach.shirina.col_simvolov - 1; i++) {
      pri2[i] = ' ';
    }
    if (znach.flagi.minus == 0) {
      strcat(pri2, pri);
      free(pri);
      return pri2;
    } else {
      strcat(pri, pri2);
      free(pri2);
      return pri;
    }
  } else {
    return pri;
  }
}

char *swjaz(char dev) {
  char *pri = "q";
  if (znach.shirina.col_simvolov == 0) {
    pri = (char *)malloc(2 * sizeof(char));
    pri[0] = dev;
  } else {
    pri = (char *)malloc(sizeof(znach.shirina.col_simvolov + 1));
    if (znach.flagi.minus == 1) {
      pri[0] = dev;
      for (int i = 1; i < znach.shirina.col_simvolov; i++) {
        pri[i] = ' ';
      }
    } else {
      for (int i = 0; i < znach.shirina.col_simvolov - 1; i++) {
        pri[i] = ' ';
      }
      pri[znach.shirina.col_simvolov - 1] = dev;
    }
  }
  // printf("1=/=/==/=/ %c\n", dev);
  return pri;
}
