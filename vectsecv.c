// 311CAb Buzea Alexandru-Mihai-Iulian
#include <stdio.h>

#define N 10
#define NMAX 100

void init_null(int v[N]) // filling our array with zeros
{
	for (int i = 0; i < N; ++i)
		v[i] = 0;
}

// v helps us to find the frequence of every digit
void find_digits(int v[N], int n)
{
	init_null(v);
	while (n > 0) {
		int c = n % 10;
		v[c]++;
		n /= 10;
	}
}

// building the maximum number
int build_desc(int v[N]) 
{
	int n = 0;
	for (int i = 9; i >= 0; --i) {
		while (v[i] != 0) {
			n *= 10;
			n += i;
			--v[i];
		}
	}
	return n;
}

// reverse number algorithm
int build_cresc(int n) 
{
	int m = 0;
	while (n != 0) {
		m *= 10;
		m += (n % 10);
		n /= 10;
	}
	return m;
}

int check_rep(int n, int v[NMAX])
{
	for (int i = 0; i < n - 1; ++i)
		if (v[i] == v[n - 1])
			return i;
	return -1;
}

void print_numbers(int n, int m, int number[NMAX])
{
	for (int i = n; i < m - 1; ++i)
		printf("%d ", number[i]);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int digits[N], number[NMAX];
	find_digits(digits, n);
	int desc = build_desc(digits);
	number[0] = desc - build_cresc(desc); // we put the first element in v
	int k;
	for (k = 1; check_rep(k, number) == -1; ++k) {
		find_digits(digits, number[k - 1]);
		desc = build_desc(digits);
		number[k] = desc - build_cresc(desc);
	}
	int i = check_rep(k, number); // checking the repetition period
	printf("%d\n", i);
	print_numbers(i, k, number); // print the numbers included in the period.
	return 0;
}
