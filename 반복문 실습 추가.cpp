/*
[ 문제 1 ] 점이 입력될 때 까지 문자들을 읽어 들인다. do 와 re 가 몇 번 입력되는지 계산하시
오. 
*/

#include<stdio.h>

int main() {

	char ch1, ch2;
	int d = 0, r = 0;
	scanf("%c", &ch1);
	while (ch1 != '.') {
		scanf("%c", &ch2);
		if (ch1 == 'd' && ch2 == 'o')
			d++;
		if (ch1 == 'r' && ch2 == 'e')
			r++;
		ch1 = ch2;
	}
	printf("do=%d\nre=%d", d, r);

	return 0;
}

/*
[ 문제 2 ] 각각의 수에 대한, 약수를 출력하시오. 0 이 입력되면 종료한다.
*/

#include<stdio.h>

int main() {

	int n, i, cnt;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		for (i = 1; i <= n; i++) {
			if (n % i == 0)
				printf("%d ", i);
		}
		printf("\n");
	}

	return 0;
}

/*
[ 문제 3 ] 각각의 수에 대한, factorial을 출력하시오. 0 이 입력되면 종료한다.
*/

#include<stdio.h>

int main() {

	int n, i, fac;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		fac = 1;
		for (i = 1; i <= n; i++) {
			fac *= i;
		}
		printf("%d", fac);
		printf("\n");
	}

	return 0;
}

/*
[ 문제 4 ] 먼저 숫자 N을 입력받는다. 그 다름, N개의 수를 입력받는다. 이웃하는 두 수의 합을
출력하시오. 즉, 첫 번째 수와 두 번째 수의 합 출력, 그 다음 두 번째 수와 세 번째 수의 합 출
력, ...
*/

#include<stdio.h>

int main() {

	int n1, cnt, sum, n2;
	scanf("%d", &cnt);
	scanf("%d", &n1);
	while (cnt > 1) {
		scanf("%d", &n2);
		sum = n1 + n2;
		printf("%d\n", sum);
		n1 = n2;
		cnt--;
	}

	return 0;
}

/*
[ 문제 5 ] 각 줄의 최대공약수를 출력하시오. 두수 중 하나가 0 이 입력되면 종료한다.
*/

#include<stdio.h>

int main() {

	int n1, n2, gcd, i, n, m;
	while (1) {
		scanf("%d %d", &n1, &n2);
		if (n1 == 0 || n2 == 0)
			break;
		gcd = 1;
		if (n1 < n2) {
			n = n1;
			m = n2;
		}
		else if (n1 >= n2) {
			n = n2;
			m = n1;
		}
		for (i = 1; i <= n; i++) {
			if (n % i == 0)
				if (m % i == 0)
					gcd = i;
		}
		printf("%d\n", gcd);
	}

	return 0;
}

/*
[ 문제 7 ] 정수 N을 입력 받아 역순으로 만든 다음 제곱한 값을 출력하시오.
*/

#include<stdio.h>

int main() {

	int n, inv = 0;
	scanf("%d", &n);

	while (n > 0) {
		inv = inv * 10 + n % 10;
		n /= 10;
	}
	printf("%d", inv * inv);

	return 0;
}

/*
[ 문제 8 ] N을 입력 받아 주사위 두 개의 합이 N의 배수가 되는 경우를 차례대로 모두 출력.
*/

#include<stdio.h>

int main() {

	int sum, i, j, k;

	scanf("%d", &sum);

	for (i = 1; i <= 6; i++) {
		for (j = 1; j <= 6; j++) {
			for (k = sum; k <= 36; k += sum)
				if (k == i + j)
					printf("%d %d\n", i, j);
		}
	}

	return 0;
}

/*-------------------------------------------------------------------------------------------------------*/

/*
[ 문제 1 ] 첫 숫자 F 와 가장 가까운 숫자를 출력하시오. (벡5개) 
- 1.0 이하 숫자가 입력되면 중단하시오. 이 수는 가까운 수에 포함하지 않는다. 
- 세 번째 수부터 1.0 이하수가 입력된다. 
- 소수점 둘째자리까지 출력하시오. 
- 절대값 구할 때 조건연산자( ? )를 사용하시오. (코드가 간단해진다)
*/

#include<stdio.h>

int main() {

	float f, mingap, near, x, new_mingap;
	scanf("%f", &f);
	scanf("%f", &x);
	near = x;
	mingap = f - x;
	mingap = mingap < 0 ? -mingap : mingap;
	while (1) {
		scanf("%f", &x);
		if (x <= 1.00)
			break;
		new_mingap = f - x;
		new_mingap = new_mingap < 0 ? -new_mingap : new_mingap;
		if (mingap > new_mingap) {
			mingap = new_mingap;
			near = x;
		}
	}
	printf("%.2f", near);

	return 0;
}

/*
[ 문제 3 ] 양의 정수 N을 입력 받아, 그 정수에 대한 약수의 합을 역순으로 출력하시오. (단, N ≧ 10)
*/

#include<stdio.h>

int main() {

	int n, i, inv = 0, sum = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}

	while (sum > 0) {
		inv = inv * 10 + sum % 10;
		sum /= 10;
	}
	printf("%d", inv);

	return 0;
}

/*
[ 문제 4 ] 다음과 같이 출력하시오.
 1
212
32123
*/

#include<stdio.h>

int main() {

	int n, i, j;
	scanf("%d", &n);

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n - i; j++)
			printf("  ");
		for (j = 1; j <= i; j++)
			printf("%d", i - j + 1);
		for (j = i - 1; j > 0; j--)
			printf("%d", i - j + 1);
		printf("\n");
	}

	return 0;
}

/*
[ 문제 5 ] 양의 정수 N을 입력 받아, 그 수를 뒤집는다. 뒤집은 수까지 소수를 계산하여 출력하
시오.
*/

#include<stdio.h>

int main() {

	int n, i, inv = 0, d;
	scanf("%d", &n);

	while (n > 0) {
		inv = inv * 10 + n % 10;
		n /= 10;
	}

	for (i = 2; i <= inv; i++) {
		d = 2;
		while (d < i && i % d != 0)
			++d;
		if (d == i) {
			printf(" %d", i);
		}
	}

	return 0;
}

/*
[ 문제 6 ] 세 수 중에서 중앙값을 출력하시오. 중앙값이란 순서상 중앙에 오는 수. median
- 세 숫자 중에서 0 이하인 수가 있으면 종료한다.
*/

#include<stdio.h>

int main() {

	int a, b, c;

	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a <= 0 || b <= 0 || c <= 0)
			break;
		if ((b < a && b > c) || (b > a && b < c))
			printf("%d\n", b);
		else if ((a < b && a > c) || (a > b && a < c))
			printf("%d\n", a);
		else if ((c < a && c > b) || (c > a && c < b))
			printf("%d\n", c);
	}

	return 0;
}

/*-------------------------------------------------------------------------------------------------------*/

/*
[ 문제 1 ] 두 정수 M, N 사이의 소수를 모두 출력하시오. (두 수도 포함)
*/

#include<stdio.h>

int main() {

	int n1, n2, i, d, j;
	scanf("%d %d", &n1, &n2);

	for (i = n1; i <= n2; i++) {
		d = 2;
		while (d < i && i % d != 0)
			++d;
		if (d == i)
			printf(" %d", d);
	}

	return 0;
}

/*
[ 문제 2 ] 소인수분해하시오.
*/

#include<stdio.h>

int main() {

	int n, i;
	scanf("%d", &n);

	for (i = 2; i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			printf(" %d", i);
		}
	}

	return 0;
}

/*
[ 문제 3 ] 각 줄에 있는 숫자의 짝수의 평균, 홀수의 평균을 각각 출력하시오. 
- 0 이하가 입력되면 중단하시오. 이 수는 평균에 포함하지 않는다. 
- 소숫점 둘째자리까지 출력하시오.
*/

#include<stdio.h>

int main() {

	float e_avg = 0, o_avg = 0, e_sum = 0.0, o_sum = 0.0, e_cnt = 0.0, o_cnt = 0.0;
	int n;

	while (1) {
		scanf("%d", &n);
		if (n <= 0)
			break;
		if (n % 2 == 0) {
			e_sum += n;
			e_cnt++;
		}
		else {
			o_sum += n;
			o_cnt++;
		}
	}
	e_avg = e_sum / e_cnt;
	o_avg = o_sum / o_cnt;

	printf("%.2f %.2f", e_avg, o_avg);

	return 0;
}

/*
[ 문제 4 ] 자릿수 합을 출력하고, 자릿수 합이 10 이하이면 합을 출력하고 종료한다.
*/

#include<stdio.h>

int main() {

	int n, sum;
	while (1) {
		scanf("%d", &n);
		sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		printf("%d\n", sum);
		if (sum <= 10)
			break;
	}

	return 0;
}

/*
[ 문제 5 ] 정수 N에서 0을 제거하고 제곱을 출력하시오.
*/

#include<stdio.h>

int main() {

	int n, m, k = 0, inv = 0;
	scanf("%d", &n);
	while (n > 0) {
		m = n % 10;
		if (m == 0)
			n /= 10;
		else {
			k = n % 10 + k * 10;
			n /= 10;
		}
	}
	while (k > 0) {
		inv = k % 10 + inv * 10;
		k /= 10;
	}

	printf("%d", inv * inv);

	return 0;
}

/*
[ 문제 6 ] 이진수를 십진수로 바꾸어 출력하시오.
*/

#include<stdio.h>

int main() {

	int n, sum = 0, k = 1;
	scanf("%d", &n);

	while (n > 0) {
		if (n % 10 == 0)
			sum += 0;
		else
			sum += k;
		k *= 2;
		n /= 10;
	}
	printf("%d", sum);

	return 0;
}

/*
[ 문제 7 ] 십진수를 이진수로 바꾸어 출력하시오.
*/

#include<stdio.h>

int main() {

	long number, binary, sum = 0, i = 1;

	scanf("%ld", &number);

	while (number > 0)
	{
		binary = number % 2;
		sum += binary * i;
		number = number / 2;
		i *= 10;
	}
	printf("%ld", sum);

	return 0;
}

/*
[ 문제 8 ] 짝수 다음 수들의 합을 출력하시오. 0 이하 수가 입력되면 종료한다.
*/

#include<stdio.h>

int main() {

	int n, sum = 0, m = 0, prev;
	while (1) {
		scanf("%d", &n);
		if (n <= 0)
			break;
		if (m == 1)
			sum += n;
		if (n % 2 == 0) {
			m = 1;
			prev = n;
		}
		else
			m = 0;
	}
	printf("%d", sum);

	return 0;
}

/*-------------------------------------------------------------------------------------------------------*/

/*
[ 문제 1 ] 두 수를 각각 뒤집어서 큰 수에서 작은 수를 빼시오.
*/

#include<stdio.h>

int main() {

	int m, n, inv1 = 0, inv2 = 0, dif = 0;
	scanf("%d %d", &m, &n);
	while (m > 0) {
		inv1 = m % 10 + inv1 * 10;
		m /= 10;
	}
	while (n > 0) {
		inv2 = n % 10 + inv2 * 10;
		n /= 10;
	}
	dif = inv1 - inv2;
	if (dif < 0)
		dif = -dif;

	printf("%d", dif);

	return 0;
}

/*
[ 문제 2 ] 별표 문자 ‘*’ 가 나타날 때 까지 입력받아 그대로 출력하시오. 소문자이면 대문자로 바
꾸어 출력하시오.
*/

#include<stdio.h>

int main() {

	char ch;
	while (1) {
		scanf("%c", &ch);
		if (ch >= 'a' && ch <= 'z')
			ch -= 32;
		printf("%c", ch);
		if (ch == '*')
			break;
	}

	return 0;
}

/*
[ 문제 3 ] 다음과 같이 출력하시오.
□15 14 13
□12 11 10
□9 8 7
□6 5 4
□3 2 1
*/

#include<stdio.h>

int main() {

	int n, m, i, cnt = 0;
	scanf("%d %d", &m, &n);

	for (i = m * n; i >= 1; i--) {
		printf(" %d", i);
		cnt++;
		if (cnt % m == 0)
			printf("\n");
	}

	return 0;
}

/*
[ 문제 4 ] 입력된 수를 차례대로 합하여 합이 20 이하이면서 합이 최대 일 때 출력하시오. 0 이
하이면 종료한다. 마지막에도 합을 출력한다.
*/

#include<stdio.h>

int main() {

	int n, sum = 0;
	while (1) {
		scanf("%d", &n);
		if (n <= 0) {
			printf(" %d", sum);
			break;
		}
		if (sum + n > 20) {
			printf(" %d", sum);
			sum = n;
		}
		else
			sum += n;
	}

	return 0;
}

/*
[ 문제 5 ] 다음과 같이 출력하시오.
□1 2 3
□6 5 4
□7 8 9
*/

#include<stdio.h>

int main() {

	int n, i, j, cnt = 1;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			for (j = 1; j <= n; j++) {
				printf(" %d", cnt++);
			}
		}
		else {
			cnt = cnt + n - 1;
			for (j = 1; j <= n; j++) {
				printf(" %d", cnt--);
			}
			cnt = cnt + n + 1;
		}

		printf("\n");
	}

	return 0;
}

/*
[ 문제 6 ] 줄의 수 정수 N을 입력 받아서, 다음과 같이 출력하시오.
***** 
~***~
~~*~~
*/

#include<stdio.h>

int main() {

	int n, i, j;
	scanf("%d", &n);

	for (i = n - 1; i >= 0; i--) {
		for (j = n - i - 1; j > 0; j--)
			printf("~");
		for (j = 2 * i + 1; j > 0; j--)
			printf("*");
		for (j = n - i - 1; j > 0; j--)
			printf("~");

		printf("\n");
	}

	return 0;
}

/*
[ 문제 7 ] 주사위 3개를 굴려서, 합이 M 이상 N 이하 되는 경우를 모두 출력하시오. 
- 1 X X를 모두 출력 후 2 X X를 출력하고, 그다음 3 X X를 출력한다.
*/

#include<stdio.h>

int main() {

	int n, m, i, j, k;
	scanf("%d %d", &m, &n);

	for (i = 1; i <= 6; i++)
		for (j = 1; j <= 6; j++)
			for (k = 1; k <= 6; k++) {
				if ((i + j + k) >= m && (i + j + k) <= n)
					printf("%d %d %d\n", i, j, k);
			}

	return 0;
}

/*
[ 문제 8 ] 정수 N을 입력받는다. 소인수분해하시오.
*/

#include<stdio.h>

int main() {

	int n, i, a, cnt = 0;
	scanf("%d", &n);

	for (i = 2; i <= n; i++) {
		cnt = 0;
		a = n;
		while (n % i == 0) {
			cnt++;
			n /= i;
		}
		if (a % i == 0) {
			printf("%d %d\n", i, cnt);
		}
	}

	return 0;
}

/*-------------------------------------------------------------------------------------------------------*/

/*
[ 문제 1 ] 정수 N의 각 자릿수를 곱하시오.
*/

#include<stdio.h>

int main() {

	int n, mul = 1;
	scanf("%d", &n);

	while (n > 0) {
		mul = mul * (n % 10);
		n /= 10;
	}
	printf("%d", mul);

	return 0;
}

/*
[ 문제 2 ] 각 줄의 최대값과 최소값을 출력하시오. 각 줄에서 같은 수가 두 개 이상이면 종료하
시오. 각 줄에 정수 3개가 입력된다.
*/

#include<stdio.h>

int main() {

	int a, b, c, max = 0, min = 0;

	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == b || b == c || a == c)
			break;
		max = a;
		min = a;
		if (max < b)
			max = b;
		if (max < c)
			max = c;

		if (min > b)
			min = b;
		if (min > c)
			min = c;
		printf("%d %d\n", max, min);
	}

	return 0;
}

/*
[ 문제 3 ] 다음 제곱들의 합을 구하시오. 두 수 중에서 0 이하가 입력되면 종료하시오.
*/

#include<stdio.h>

int main() {

	int a, b, i, result, sum = 0;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a <= 0 || b <= 0)
			break;
		result = a;
		for (i = 1; i < b; i++)
			result *= a;
		sum += result;
	}
	printf("%d", sum);

	return 0;
}

/*
[ 문제 4 ] 각 줄의 최소공배수를 구하시오. 두 수 중에서 0 이하가 입력되면 종료하시오.
*/

#include<stdio.h>

int main() {

	int gcd, m, n, i, j, k, lcd;
	while (1) {
		scanf("%d %d", &m, &n);
		if (m <= 0 || n <= 0)
			break;
		j = (m < n) ? m : n;
		k = (m > n) ? m : n;

		for (i = 1; i <= j; i++)
			if (m % i == 0 && n % i == 0)
				gcd = i;
		lcd = (m * n) / gcd;
		printf("%d\n", lcd);
	}

	return 0;
}

/*
[ 문제 5 ] 다음과 같이 출력하시오.
1 3 5 7 9
3 5 7 9
5 7 9
7 9
9
*/

#include<stdio.h>

int main() {

	int n, i, j, line = 1, cnt;
	scanf("%d", &n);

	for (i = n; i > 0; i--) {
		cnt = line;
		for (j = 0; j < i; j++) {
			printf(" %d", cnt);
			cnt += 2;
		}
		line += 2;
		printf("\n");
	}

	return 0;
}

/*
[ 문제 6 ] 다음과 같이 출력하시오.
*
**
* *
* *
*****
*/

#include<stdio.h>

int main() {

	int n, i, j;
	scanf("%d", &n);

	printf("*");
	printf("\n");

	for (i = 0; i < n - 2; i++) {
		printf("*");
		for (j = 0; j < i; j++)
			printf(" ");
		printf("*");
		printf("\n");
	}
	for (i = 0; i < n; i++)
		printf("*");
	printf("\n");

	return 0;
}