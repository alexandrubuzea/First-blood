// 311CAb Buzea Alexandru-Mihai-Iulian
#include <stdio.h>

int is_special(int x, int y, int z)
{
	if (x < y && z < y)
		return 1;
	else
		return 0;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int x, y; // the first two trees
	scanf("%d%d", &x, &y);
	long sum_special = 0;
	int num_special_par = 0;
	int num_special_impar = 0;
	int xmax_impar;
	int xmin_par;
	int z; // the third tree
	for (int i = 2; i < n; ++i) {
		scanf("%d", &z);
		if (is_special(x, y, z) == 1) { // all possible cases
			if (i % 2 == 1) {
				num_special_par++;
				if (num_special_par == 1)
					xmin_par = y;
				else
					if (y < xmin_par)
						xmin_par = y;
			} else {
				num_special_impar++;
				if (num_special_impar == 1)
					xmax_impar = y;
				else
					if (y > xmax_impar)
						xmax_impar = y;
			}
			sum_special += (long)y;
		}
		x = y;
		y = z;
	}
	int num_special = num_special_par + num_special_impar;
	double m_a;
	if (num_special == 0)
		m_a = 0;
	else
		m_a = (double)sum_special / num_special;
	printf("%ld\n", sum_special);
	printf("%.7lf\n", m_a);
	if (num_special_impar == 0) // if we do not have any tree
		xmax_impar = -1;
	if (num_special_par == 0) // if we do not have any tree
		xmin_par = -1;
	if (n <= 2) { // corner case
		xmax_impar = 0;
		xmin_par = 0;
	}
	printf("%d\n", xmax_impar);
	printf("%d", xmin_par);
	return 0;
}

