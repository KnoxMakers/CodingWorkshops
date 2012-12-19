#include <stdio.h>

int main()
{
	int i = 0;
	int sum = 0;
	int end = 1000;

	for( i; i < end; i++)
	{
		if (!(i % 3) || !(i % 5))
		{
			sum += i;
		}
	}

	printf ("Sum is: %d\n", sum);

	return 0;
}
