// 311CAb Buzea Alexandru-Mihai-Iulian
#include <stdio.h>

#define NMAX 100

void read_array(int n, int v[NMAX])
{
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
}

int update_array(int n, int v[NMAX], int p)
{
	int credits;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &credits);
		p += (v[i] * credits);
		v[i] = (credits * (10 - v[i]));
	}
	return p;
}

int find_max(int n, int v[NMAX]) // maximum value algorithm
{
	int k = 0;
	for (int i = 0; i < n; ++i)
		if (v[k] < v[i])
			k = i;
	return k;
}

int check_null(int n, int v[NMAX])
{
	for (int i = 0; i < n; ++i)
		if (v[i] != 0)
			return 0;
	return 1;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int v[NMAX];
	read_array(n, v); // reading the marks
	int p = 0; // initial score
	p = update_array(n, v, p); // getting the costs
	int p_min;
	scanf("%d", &p_min);
	int num = 0;
	while (p < p_min) {
		if (check_null(n, v) == 1) { // if we consumed all costs
			num = -1;
			break;
		}
		int k = find_max(n, v);
		p += v[k];
		v[k] = 0;
		++num;
	}
	printf("%d\n", num);
	return 0;
}
