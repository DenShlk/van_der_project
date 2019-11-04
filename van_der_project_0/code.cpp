#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAXN 1000000
#define K 5
#define R 2

bool m[MAXN];
int primes[MAXN];
int max_length = 1;

void step(int length) {
	length++;
	if (length > max_length)
		max_length = length;

	m[length] = 0;
	bool correct0 = 1, correct1 = 1;
	int max_d = (length - 1) / (K - 1);
	for (int d = 1; (correct0 || correct1) && d <= max_d; d++)
	{
		int k = 2;
		for (; length - k * d > 0 && m[length - k * d] == m[length - d]; k++);
		if (k >= K)
			if (m[length - d])
				correct1 = 0;
			else
				correct0 = 0;
	}
	if (correct0)
		step(length);

	m[length] = 1;
	if (correct1)
		step(length);

	if (length > MAXN){
		printf("overflow!\n");
		scanf("%*s");
	}
}

void 

int main()
{
	m[1] = 0;
	step(1);

	printf("%d\n", max_length);
	scanf("%*c");
}
