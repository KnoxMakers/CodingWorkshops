// Non tail recursive factorial function. 
// compile with: gcc -g notailfactorial.c
// Examine in gdb: gdb a.out 
// gdb>break 14 
// gdb>n (repeatedly)
// gdb>bt (repeatedly)

// gcc -g -foptimize-sibling-calls ntrecursion.c

int main () {

int n = 5;

int factorial(n) {
    if (n == 0) return 1;
    printf ("n is %d\n",n);
    return n * factorial(n - 1);
  }

n = factorial(n);

printf ("Total is: %d\n",n);

}
