
struct format_pritn {
    char flagi[10];
    int shir;
    int tochnost;
    char dlina;
    char specific;
};

struct format_print dano = {0};


int s21_sprintf(char *str, const char *format, ...);

int main() {
  char str[1024];
  const char *format;
  char uno[256] = "hello";
  int duo = 21;
  double trio = 2.1;
  char format[256] = "%*123lc";
  s21_sprintf(str, format, uno, duo, trio);
}

int s21_sprintf(char *str, const char *format, ...) {
  int i = 0;

  while ((format[i] != '%') && (format[i] != '\0')) {
    switch (format[i]) {
      case '-':
        /* code */
        break;
      case '+':
        /* code */
        break;
      case ' ':
        /* code */
        break;
      case '#':
        /* code */
        break;
      case '0':
        if 
        break;
      case '-':
        /* code */
        break;
      case '-':
        /* code */
        break;
      case '-':
        /* code */
        break;
      case '-':
        /* code */
        break;
      case '-':
        /* code */
        break;
      case '-':
        /* code */
        break;

      default:
        break;
    }
  }
}