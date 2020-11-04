#include <stdio.h>
#include <unistd.h>
int main()
{
	int m = 10, n = 5, count = 1, mult = 1;
	while (count < 3)
	{
		if (m != 0)
		{
			m = fork();
			n = n + 25;
		}
		else
		{
			m = fork();
			n = n + 20;
			mult = mult * n;
		}
		printf("m = %d \t n = %d \t mult = %d \n", m, n, mult);
		count = count + 1;
	}
}