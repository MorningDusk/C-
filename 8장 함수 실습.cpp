/* 8��3��[���� 1] ���� ���� N�� �Է� �޾�, 1���� N������ ���� ����ϴ� ���α׷��� �ۼ��Ͻ�
��. - add �Լ� ���� �� ���
- ���ڴ� �� ���� ���� x�� y, ��ȯ���� int - x�� y�� ���� ��ȯ
- main �Լ�
- N���� �Է� �ް�, add �Լ��� �ݺ� ȣ���Ͽ� N������ �� ���
- main �Լ������� ���ϱ� ������(+) ��� ����.��, ����������(++ or --)�� ��� ���� */

#include<stdio.h>

int add(int n) {
	int s = 0;
	for (int i = 1; i <= n; i++)
		s += i;
	return s;

}

int main() {
	int n, s;
	scanf("%d", &n);

	s = add(n);
	printf("%d", s);

	return 0;
}

/* 8��3�� [ ���� 2 ] �� ���� ���� ���� A�� B�� �Է� �޾�, A���� B������ ���� ����ϴ� ���α�
���� �ۼ��Ͻÿ�. - A �� B�� �Է¸� ���´ٰ� �����Ͻÿ�. - sum �Լ� ���� �� ���
 - ���ڴ� �ϳ��� ���� n, ��ȯ���� int - 1���� n������ �� ��ȯ, n(n+1)/2 ���� �̿� */

#include<stdio.h>

int add(int a, int b) {
	int s = 0;
	for (int i = a; i <= b; i++)
		s += i;
	return s;

}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d", add(a, b));

	return 0;
}

/* 8��3�� [ ���� 3 ] �ϳ��� ���� ���� N�� �Է� �޾� ���� ������ ����� ����ϴ� ���α׷��� ��
���Ͻÿ�. 1 + (1+2) + (1+2+3) + (1+2+3+4) + �� + (1+2+��+N) - sum �Լ� ���� �� ���
 - ���� 2�� ���� */

#include<stdio.h>

int add(int n) {
	int s = 0;
	for (int i = 1; i <= n; i++)
		s += i;
	return s;

}

int main() {
	int n, i, s = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		s += add(i);
	printf("%d", s);

	return 0;
}

/* 8��3�� [ ���� 4 ] 2~9 ������ ���� N�� �Է� �޾�, ���ÿ� ���� ���� N���� �簢���� ����ϴ�
���α׷��� �ۼ��Ͻÿ�. - print_row1 �Լ� ���� �� ���
 - ���� 2~9������ ���� x, ��ȯ���� void
 - �ϳ��� �ٿ� x�� x�� ���
 - print_row2 �Լ� ���� �� ���
 - ���� 2~9������ ���� x, ��ȯ���� void
 - �ϳ��� �ٿ� x�� 2�� ���, �߰��� ���� ������ ���� */

#include<stdio.h>

void print_row1(int n) {
	for (int i = 1; i <= n; i++)
		printf("%d", n);
}

void print_row2(int n) {
	printf("%d", n);
	for (int i = 1; i <= n - 2; i++)
		printf(" ");
	printf("%d", n);
	printf("\n");
}

int main() {
	int n, i;
	scanf("%d", &n);
	print_row1(n);
	printf("\n");
	for (i = 2; i < n; i++)
		print_row2(n);
	print_row1(n);

	return 0;
}

/* 8��3�� [ ���� 5 ] ���� ������ �ݺ��ؼ� �Է� �޾�(���� ���� �ñ���), ���ÿ� ���� Ʈ�� �����
����ϴ� ���α׷��� �ۼ��Ͻÿ�. - ��������: 0 �Ǵ� ���� �Է�
 - print_triangle �Լ�
 - ���ڴ� �ϳ��� ���� x, ��ȯ���� void
 - ���̰� x�� �ﰢ�� ��� */

#include<stdio.h>

void print_triangle(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j)
			printf("*");
		printf("\n");
	}
}

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		print_triangle(n);
		if (n <= 0)
			break;
	}

	return 0;
}

/* 8��3�� [ ���� 6 ] �ϳ��� ���� x�� �Է� �޾� ���� �Լ��� ����� ����ϴ� ���α׷��� �ۼ��Ͻ�
��. f(x) = 2x2 -5x + 1
 - func1 �Լ� ���� �� ���
 - ���ڴ� �ϳ��� ���� x, ��ȯ���� int - f(x)�� ����� ��ȯ
 - main �Լ�
 - ������ �Է� �ް�, func1 �Լ� ȣ�� �� ��� ��� */

#include<stdio.h>

int func(int n) {
	int f = 2 * n * n - 5 * n + 1;
	return f;
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%d", func(n));

	return 0;
}

/* 8��3�� [ ���� 7 ] �ϳ��� ���� x�� 2�� �Լ� f(x)�� ����� ��Ÿ���� 3���� ������ �Է� �޾�, ��
�ÿ� ���� �Լ� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. - func2 �Լ� ���� �� ���
 o ���ڴ� 4���� ����, x, a, b, c, ��ȯ���� int o ax2 + bx + c �� ��� �� ��ȯ
 - main �Լ�
 o �������� �Է� �ް�, func2 �Լ� ȣ�� �� ��� ��� */

#include<stdio.h>

int func(int n, int a, int b, int c) {
	int f;
	f = a * n * n + b * n + c;
	return f;
}

int main() {
	int n, a, b, c;
	scanf("%d\n", &n);
	scanf("%d %d %d", &a, &b, &c);

	printf("%d", func(n, a, b, c));

	return 0;
}

/* 8��3�� [ ���� 8 ] �ϳ��� ���� x�� 2�� �Լ� f(x)�� g(x)�� ����� ��Ÿ���� 6���� ������ �Է�
�޾�, �ռ��Լ� g(f(x))�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
 - func2 �Լ� ���� �� ���
 - ���� 7�� ����
 - main �Լ�
 - �������� �Է� �ް�, func2 �Լ� ȣ�� �� ��� ��� */

#include<stdio.h>

int func1(int n, int a, int b, int c) {
	int f;
	f = a * n * n + b * n + c;
	return f;
}

int func2(int n, int a, int b, int c) {
	int f;
	f = a * n * n + b * n + c;
	return f;
}

int main() {
	int n, a, b, c, d, e, f;
	scanf("%d\n", &n);
	scanf("%d %d %d\n", &a, &b, &c);
	scanf("%d %d %d", &d, &e, &f);

	printf("%d", func2(func1(n, a, b, c), d, e, f));

	return 0;
}

/* 8��4�� [ ���� 9 ] ������ �ݺ��ؼ� �Է� �޾�(���� ���� �ñ���), ���� ū ���� �� ��°�� ū ��
�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. - ��������: 0 �Է� (�������� ���� �ּ� 2���� ������ �Էµȴٰ� ����) - �������� max1, max2 ���
 - update_max �Լ� ���� �� ���
 - ���ڴ� �ϳ��� ���� x, ��ȯ���� void
 - max1, max2, x �� ���� ū ���� max1��, �� ��°�� ū ���� max2�� ���� */

#include<stdio.h>

int main() {

	int n, i, cnt = 0, x[100], max1, max2;
	for (i = 0; i < 100; i++) {
		scanf("%d", &n);
		if (n == 0)
			break;
		x[cnt] = n;
		cnt++;
		if (x[0] < x[1]) {
			max1 = x[1];
			max2 = x[0];
		}
		else {
			max1 = x[0];
			max2 = x[1];
		}
	}

	for (i = 2; i < cnt; i++) {
		if (max1 < x[i]) {
			max2 = max1;
			max1 = x[i];
		}
		else if (x[i] > max2)
			max2 = x[i];
	}
	printf("%d %d", max1, max2);

	return 0;
}

/* 8��4�� [ ���� 10 ] 3~18 ������ ���� N�� �Է� �޾�, 3�� �ֻ����� �� ���� N�� �Ǵ� ��� ��
�츦 ����ϴ� ���α׷��� �ۼ��Ͻÿ�. - �������� N ���: �Է� ���� ���� ����
 - die1 �Լ� ���� �� ���
 - ���ڴ� �ϳ��� ���� x, ��ȯ���� void
 - ù ��° �ֻ��� ���� x�� ��� ��� ���
 - ���ο��� die2 �Լ� ȣ��
 - die2 �Լ� ���� �� ���
 - ���ڴ� ���� x�� y, ��ȯ���� void
 - ù ��° �ֻ��� ���� x, �� ��° �ֻ����� ���� y�� ��� ��� ���
 - ���ο��� die3 �Լ� ȣ��
 - die3 �Լ� ���� �� ���
 - ���ڴ� ���� x, y, z, ��ȯ���� void
 - ù ��°, �� ��°, �� ��° �ֻ��� ���� x, y, z �� ��� ���, ��, �ֻ��� ���� N�� �Ǹ�,
 x y z �� ���
 - main �Լ�
 - ������ �Է� �ް�, die1 �Լ��� 6�� �ݺ� ȣ�� */

#include<stdio.h>

int main() {

	int n, i, j, k;
	scanf("%d", &n);

	for (i = 1; i <= 6; ++i) {
		for (j = 1; j <= 6; ++j) {
			for (k = 1; k <= 6; ++k) {
				if (i + j + k == n)
					printf("%d %d %d\n", i, j, k);
			}
		}
	}

	return 0;
}

/* 8��4�� [ ���� 11 ] (�߱� ����) ���� ���α׷��� �ۼ��Ͻÿ�. 1) ������ ��Ÿ���� 0~9 ������ ���� �ٸ� ���� 3���� �Է� ����
 2) ������ ������ 0~9 ������ ���� �ٸ� ���� 3���� �Է� �޾� ��Ʈ����ũ ������ ���� ������
 ��� (������ ���� ������ �ݺ�) - ��Ʈ����ũ ����: ���� ���߰� ��ġ�� ���� ������ ����
 - �� ����: ���� ��������, ��ġ�� Ʋ�� ������ ����
 - ���� ���� �� �Լ�
 - ������ ���������� ����
 - count_strike �Լ� ���� �� ���
 - ���ڴ� ���� ���� ��Ÿ���� �� ���� ����, ��ȯ���� int - ����� ������ ���Ͽ� strike ������ ��ȯ
 - count_ball �Լ� ���� �� ���
 - ���ڴ� ���� ���� ��Ÿ���� �� ���� ����, ��ȯ���� int - ����� ������ ���Ͽ� ball ������ ��ȯ
 - main �Լ�
 - ������ ������ ���� �� �Լ��� �̿��Ͽ� strike�� ball�� ������ ���, ����� ��� */

#include<stdio.h>

int main() {

	int a, b, c, x, y, z, S, B;
	scanf("%d %d %d\n", &a, &b, &c);

	while (1) {
		scanf("%d %d %d", &x, &y, &z);
		S = 0;
		B = 0;

		if (x == a)
			S++;
		else if (x == b || x == c)
			B++;

		if (y == b)
			S++;
		else if (y == a || y == c)
			B++;

		if (z == c)
			S++;
		else if (z == a || z == b)
			B++;

		printf("%dS%dB\n", S, B);

		if (x == a && y == b && z == c) {
			break;
		}
	}

	return 0;
}

/* 8��4�� [ ���� 13 ] �ϳ��� ���� ���� N�� �Է� �޾�, 1���� N������ �������� ���� 3�� �� ��
�� ��Ÿ�������� ����ϴ� ���α׷� �ۼ��Ͻÿ�. - N=33 �� ��, 3, 13, 23, 30, 31, 32, 33, �� 7���� ������ 8���� 3�� ��Ÿ����. (�� ���� 33���� 3�� �� �� �����Ƿ�)
 - count_3 �Լ� ���� �� ���
 - ���ڴ� �ϳ��� ���� x, ��ȯ���� int - �ϳ��� ���� x�� ���� 3�� ��Ÿ���� Ƚ�� ��ȯ */

#include<stdio.h>

int count3(int n) {
	int m, cnt = 0;
	while (n != 0) {
		m = n % 10;
		n /= 10;
		if (m == 3)
			cnt++;
	}
	return cnt;
}

int main() {

	int n, i, cnt = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		cnt += count3(i);
	printf("%d", cnt);

	return 0;
}

/* 8��4�� [ ���� 14 ] �� ���� ���� N�� M�� �Է� �޾�, N���� ū �Ҽ��� ���� �ͺ��� ���ʷ� M
�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. - is_prime �Լ�
 - ���ڴ� �ϳ��� ���� x, ��ȯ���� int - ���� x�� �Ҽ��̸� 1 ��ȯ, �Ҽ��� �ƴϸ� 0 ��ȯ
 - next_prime �Լ�
 - ���ڴ� �ϳ��� ���� x, ��ȯ���� int - ���� x ���� ũ�鼭 ���� ���� �Ҽ��� ��ȯ (is_prime �Լ� ���) - main �Լ�
 - next_prime �Լ��� �ݺ� ȣ���Ͽ�, M���� �Ҽ��� ��� */

#include<stdio.h>

int is_prime(int n) {
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int next_prime(int n) {
	for (int i = n + 1;; i++) {
		if (is_prime(i))
			return i;
	}
}

int main() {

	int n, cnt, i;
	scanf("%d %d", &n, &cnt);

	while (cnt > 0) {
		printf(" %d", next_prime(n));
		n = next_prime(n);
		cnt--;
	}

	return 0;
}