int main () {

int n=5;
int accumulator;

int  factorial1(n, accumulator) {
    if (n == 0) return accumulator;
    return factorial1(n - 1, n * accumulator);
  }

int factorial(n) {
    return factorial1(n, 1);
} 

n = factorial(n);

printf("Total is: %d\n",n);

}
