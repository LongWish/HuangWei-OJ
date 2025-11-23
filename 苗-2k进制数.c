#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
#define ull unsigned long long
#define max_len 30010
#define max_digit 210

int a[max_len][max_digit], c[max_digit], ans[max_digit];
int k, w;

void add(int* a, int* b)
{
	int lenc = 0, x = 0;
	while (lenc < a[0] || lenc < b[0])
	{
		lenc++;
		a[lenc] = a[lenc] + b[lenc] + x;
		x = a[lenc] / 10;
		a[lenc] %= 10;
	}
	if (x > 0)
		a[++lenc] = x;
	a[0] = lenc;
}

int main()
{
	scanf("%d%d", &k, &w);
	int kk = w % k;
	int hh = w / k;
	int y = 0;
	int i, j;
	
	for (i = 1; i <= kk; i++)
		y += 1 << (i - 1);
		
	int minn = (1 << k) - 1;
	
	if (hh == 1 || (hh == 2 && kk == 0))
	{
		if (kk == 0)
			y = minn;
			
		int tot = 0;
		for (i = 1; i <= y; i++)
			tot += minn - i;
			
		printf("%d\n", tot);
		return 0;
	}
	
	for (i = 1; i <= minn - 1; i++)
	{
		a[i][1] = i;
		a[i][0] = 1;
		add(ans, a[i]);
	}
	
	for (i = 3; i <= hh; i++)
	{
		for (j = 1; j <= minn - i + 1; j++)
		{
			add(a[j], a[j - 1]);
			add(ans, a[j]);
		}
	}
	
	for (j = 1; j <= minn - hh; j++)
		add(a[j], a[j - 1]);
		
	for (j = minn - hh; j >= (minn - hh - y + 1 > 1 ? minn - hh - y + 1 : 1); j--)
		add(ans, a[j]);
		
	for (i = ans[0]; i >= 1; i--)
		printf("%d", ans[i]);
		
	return 0;
}
