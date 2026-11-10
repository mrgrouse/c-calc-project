#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define add2(X, Y) X + Y
#define sub2(X, Y) X - Y
#define mul2(X, Y) X * Y
#define div2(X, Y) X / Y
#define makepos(X) (X < 0) ? X * -1 : X

#define usage()                                                                \
  puts("Usage: calc # [ + | - | x | / ] #\n\tcalc # ^ # (argument 2 will be "  \
       "rounded)");
float_t pow2(float_t x, uint32_t y) {
  float_t hld = x;
  for (int i = 1; i < y; i++) {
    x *= hld;
  }
  return x;
}

int main(int argc, char *argv[]) {
  if (argc % 2 != 0 || argc < 4) { // if we have the right # of arguments
    puts("Wrong # of arguments.");
    usage() return EXIT_FAILURE;
  }

  if (strlen(argv[2]) != 1) { // if we have a `switch`-able operator
    puts("Wrong operator.");
    usage() return EXIT_FAILURE;
  }

  switch (argv[2][0]) {
  case '+':
    printf("%f\n", add2(atof(argv[1]), atof(argv[3])));
    break;
  case '-':
    printf("%f\n", sub2(atof(argv[1]), atof(argv[3])));
    break;
  case 'x':
    printf("%f\n", mul2(atof(argv[1]), atof(argv[3])));
    break;
  case '/':
    printf("%f\n", div2(atof(argv[1]), atof(argv[3])));
    break;
  case '^':
    if (atoll(argv[3]) < 0) {
      printf("%f\n", 1 / pow2(atof(argv[1]), makepos(atoll(argv[3]))));
      break;
    }
    printf("%f\n", pow2(atof(argv[1]), makepos(atoll(argv[3]))));
    break;
  default:
    puts("Unable to identify operator/operands.");
    usage() return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
