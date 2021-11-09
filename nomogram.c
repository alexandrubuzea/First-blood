// 311CAb Buzea Alexandru-Mihai-Iulian
#include <stdio.h>

#define NMAX 100 // the nomogram dimension

void scan_check(int n, int m, int v[NMAX * NMAX]) // we read the restrictions
{
	int k = 0;
	for (int i = 0; i < n + m; ++i) {
		int x; // number of blocks existing on a line
		scanf("%d", &x);
		for (int j = 0; j < x; ++j) {
			scanf("%d", &v[k]); // the length of every block
			++k;
		}
		v[k] = -1; // a separator between the block of every line
		++k;
	}
}

void scan_nmg(int n, int m, int nmg[NMAX][NMAX])
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &nmg[i][j]);
}

int check_nmg(int n, int m, int nmg[NMAX][NMAX], int v[NMAX * NMAX])
{
	int p = 0;
	for (int i = 0; i < n; ++i) { // check lines
		for (int j = 0; j < m; ++j) {
			if (nmg[i][j] == 1) {
				if (v[p] == -1) // Case 1
					return 0;
				int num = 0;
				while (j < m && nmg[i][j] == 1) {
					num++;
					++j;
				}
				if (num != v[p]) // Case 2
					return 0;
				++p;
			}
		}
		if (v[p] != -1) // Case 3
			return 0;
		++p;
	}
	for (int j = 0; j < m; ++j) { // check columns
		for (int i = 0; i < n; ++i) {
			if (nmg[i][j] == 1) {
				if (v[p] == -1) // Case 1
					return 0;
				int num = 0;
				while (i < n && nmg[i][j] == 1) {
					num++;
					++i;
				}
				if (num != v[p]) // Case 2
					return 0;
				++p;
			}
		}
		if (v[p] != -1) // Case 3
			return 0;
		++p;
	}
	return 1;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	int v[NMAX * NMAX];
	int nmg[NMAX][NMAX];
	for (int i = 0; i < t; ++i) {
		int n, m;
		scanf("%d%d", &n, &m);
		scan_check(n, m, v);
		scan_nmg(n, m, nmg);
		if (check_nmg(n, m, nmg, v) == 0)
			printf("Eroare\n");
		else
			printf("Corect\n");
	}
	return 0;
}
