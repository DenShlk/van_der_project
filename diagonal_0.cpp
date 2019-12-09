#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;
#define MAXN 1000000
#define R 2
#define K 5

int m[MAXN];
int max_length = 1;

void step(int length) {
	length++;
	
	if (length > max_length)
		max_length = length;

	bool correct[R];
	for (int i = 0; i < R; i++)
		correct[i] = 1;
	
	int correct_n = R;
	int max_d = (length - 1) / (K - 1);
	for (int d = 1; correct_n != 0 && d <= max_d; d++)
	{
		int k = 2;
		for (; length - k * d > 0 && m[length - k * d] == m[length - d]; k++);
		if (k >= K && correct[m[length - d]]){
			correct_n--;
			correct[m[length - d]] = 0;
		}
	}

	if(correct_n != 0)
		for (int i = 0; i < R; i++)
		{
			m[length] = i;
			if (correct[i])
				step(length);
		}
}

int main()
{
	printf("W(%d,%d):\n", R, K);
	time_t start, finish;

	start = time(NULL);

	m[1] = 0;
	step(1);

	finish = time(NULL);

	printf("%d\n", max_length);
	printf("%lld seconds, %lld steps to solve\n", finish - start, counter);
	scanf("%*c");
}