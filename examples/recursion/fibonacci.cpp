#include<iostream>
#include<cstdlib>

using namespace std;

typedef unsigned int uint;

int stats;

//FIBONACCI NUMBERS
/** Recursive algorithm **/
uint fib(uint n) {
	stats++;
if (n==0 || n==1)
	return n;
else
	return fib(n-2) + fib(n-1); // Tree recursion (calls itself with 2 branches)
}

/** multi-argument recursive algorithm **/
//uint fib(uint n, uint first, uint second) {
//return n == 1 ? second : fib(n-1, second, first+second);
//}

//uint fib(uint n) {
//return n == 0 ? 0 : fib(n, 0, 1);
//}

/** iterative algorithm **/
//uint fib(uint n) {
//uint first = 0, second = 1;
//}

//while (n--) {
//uint tmp = first+second;
//first = second;
//second = tmp;
//}
//return first;


main(int argc, char *argv[]) {
uint N = argc == 1 ? 8 : atoi(argv[1]);

cout << "FIB = " << fib(N) << endl;

cout << " (" << stats << ")" << endl;

}
