```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

/*汉诺塔(Tower of Hanoi)，又称河内塔，是一个源于印度古老传说的益智玩具。
大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。
大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。
并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。*/

int Hannuota(int n)
{
	if (n <= 1)
		return 1;
	else
		return Hannuota(n - 1) * 2 + 1;
}

int main()
{
	int n;
	int ans;
	scanf("%d", &n);
	ans = Hannuota(n);
	printf("%d", ans);
	return 0;
}
```
