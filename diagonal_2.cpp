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
int max_color_used = 0;

int step(int length) {

	length++;
	if (length > max_length)
		max_length = length;

	bool correct[R];
	for (int i = 0; i < R; i++)
		correct[i] = 1;
	int correct_n = max_color_used + 2 < R ? max_color_used + 2 : R;
	
	int max_d = (length - 1) / (K - 1);
	int min_d = max_d;
	for (int d = 1; correct_n != 0 && d <= max_d; d++)
		if (correct[m[length - d]]) {
			int k = 2;
			for (; length - k * d > 0 && m[length - k * d] == m[length - d]; k++);

			if (k >= K) {
				if (d < min_d)
					min_d = d;
				correct_n--;
				correct[m[length - d]] = 0;
			}
		}

	if (correct_n == 0)
		return length - min_d;
	
	int before = max_color_used;
	int max_color = before + 2 < R ? before + 2 : R;
	for (int i = 0; i < max_color; i++)
		if (correct[i]) {
			if (i > before)
				max_color_used = i;

			m[length] = i;
			int to_step = step(length);
			max_color_used = before;
			if (to_step < length)
				return to_step;
		}

	return length - 1;
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