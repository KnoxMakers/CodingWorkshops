#include <stdio.h>

int main( int argc, char *argv[] )
{
        int fib0 = 0, fib1 = 1; /* start the sequence 2 steps early, with elements just prior to the actual 1st term */
        int sum = 0; /* actual fibonacci number */
        int sumEven = 0;  /* sum of the even terms */ 
        int numTerms = 0;
        int i;
        const int maxValue = 4000000; /* four million */
        
        for( i=0; sum <= maxValue; i++ )
        {               
                sum = fib0 + fib1;
                printf ("element[%5d]  %8d;  sumEven = %8d \n", i, sum, sumEven);
                if ( (sum%2)==0)   /* increment sumEven when computing an even-numbered element */
                  {
                  sumEven += sum;
                  }
                fib0 = fib1;
                fib1 = sum;
        }

        return (0);
}

