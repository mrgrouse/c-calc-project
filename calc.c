#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define add2(X, Y) X + Y
#define sub2(X, Y) X - Y
#define mul2(X, Y) X * Y
#define div2(X, Y) X / Y

#define usage() puts("calc # [ + | - | * | / | ^ ] #")

float_t pow2(float_t x, float_t y) {
  for (int i = 1; i < (int)y; i++) {
    x *= x;
  }
  return x;
}


int main(int argc, char *argv[]) {
  if (argc % 2 != 0 || argc < 4) { // if we have the right # of arguments
    puts("Wrong # of arguments.");
    usage();
    return EXIT_FAILURE;
  }

  if (strlen(argv[2]) != 1) { // if we have a `switch`-able operator
    puts("Wrong operator.");
    usage();
    return EXIT_FAILURE;
  }
	/* we know argc is even, argc > 4 .
	 * we need to find which operator is of highest precedence
	 * and operate on it's two operands
	 * operators are even # > 1 in argv[]
	 * operands are the odd numbered elements in argv[]
	 */

	 for (int i = 2; i < argc; i += 2) {
	 	if (argv[i][0] == '^') {
	 		continue;
	 	}
	 }



  return EXIT_SUCCESS;
}












/*
  switch (argv[2][0]) {
  case '+':
    printf("%f\n", add2(atof(argv[1]), atof(argv[3])));
    break;
  case '-':
    printf("%f\n", sub2(atof(argv[1]), atof(argv[3])));
    break;
  case '*':
    printf("%f\n", mul2(atof(argv[1]), atof(argv[3])));
    break;
  case 'x':
    printf("%f\n", mul2(atof(argv[1]), atof(argv[3])));
    break;
  case '/':
    printf("%f\n", div2(atof(argv[1]), atof(argv[3])));
    break;
  case '^':
    printf("%f\n", pow2(atof(argv[1]), atof(argv[3])));
    break;
  default:
    puts("Unable to identify operator/operands.");
    return EXIT_FAILURE;
  }
  */
