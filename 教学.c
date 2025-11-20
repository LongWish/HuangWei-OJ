#include <stdio.h>
double area(long long, long long, long long, long long);

int main() {
	int n;
	long long x[100005] = {0}, y[100005] = {0}, a1, b1, c1, d1, a2, b2, c2, d2;
	double result = 0;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		scanf("(%lld,%lld)", &x[i], &y[i]);
        // printf("check:%02x", getchar());
	}
	int j;
	for (j = 1; j < n - 1; j += 2) {
		a1 = x[j + 1] - x[j];
		b1 = y[j + 1] - y[j];
		c1 = x[j + 2] - x[j];
		d1 = y[j + 2] - y[j];
		result += area(a1, b1, c1, d1);
	}
	if (j == n - 1) {
		a2 = x[n - 1] - x[1];
		b2 = y[n - 1] - y[1];
		c2 = x[n] - x[1];
		d2 = y[n] - y[1];
		result += area(a2, b2, c2, d2);
		for (int t = 3; t <= j - 2; t += 2) {
			a1 = x[t] - x[t - 2];
			b1 = y[t] - y[t - 2];
			c1 = x[t + 2] - x[t - 2];
			d1 = y[t + 2] - y[t - 2];
			result += area(a1, b1, c1, d1);
		}
	} else if (j == n) {
		for (int r = j; r >= 5; r -= 2) {
			a1 = x[r - 2] - x[r];
			b1 = y[r - 2] - y[r];
			c1 = x[r - 4] - x[r];
			d1 = y[r - 4] - y[r];
			result += area(a1, b1, c1, d1);
		}
	}
	printf("%.1f", result);
}

double area(long long a, long long b, long long c, long long d) {
	long long result;
	double final;
	result = a * d - b * c;
	if (result < 0) {
		result = -result;
	}
	final = (double)result / 2;
	return final;
}