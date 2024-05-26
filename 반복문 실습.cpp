/*
6장2절 [ 문제 1 ] 하나의 양의 정수 N을 입력 받아 N의 약수를 출력하는 프로그램을 작성하시
오.
 - while 문 이용
 - 출력의 각 수는 하나의 공백으로 구분하고, 맨 마지막에는 공백 없음
*/

#include <stdio.h>

int main() {

	int n, i, j, cnt = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		if (n % i == 0)
			printf("%d ", i);

	return 0;
}

/*
6장3절 [ 문제 2 ] 하나의 정수 N을 반복해서(종료 조건 시까지) 입력 받아 N의 합을 출력하는
프로그램을 작성하시오.
 - 종료 조건: 0 입력
 - while 문 이용
*/

#include<stdio.h>

int main() {

	int n, sum = 0;
	scanf("%d", &n);

	while (n != 0) {
		sum += n;
		scanf("%d", &n);
	}
	printf("%d", sum);

	return 0;
}

/*
6장3절 [ 문제 3 ] 하나의 기준 정수를 입력 받고, 다음 예시와 같이 정답을 맞힐 때 까지 정수를
입력 받아 대소 관계를 출력하는 숫자 맞추기 게임 프로그램을 작성하시오. - do while 문 이용
*/

#include<stdio.h>

int main() {

	int ans, n, cnt = 0;
	scanf("%d", &ans);

	scanf("%d", &n);
	while (1) {
		cnt++;
		if (n > ans) {
			printf("%d>?\n", n);
			scanf("%d", &n);
		}
		else if (n < ans) {
			printf("%d<?\n", n);
			scanf("%d", &n);
		}
		else if (n == ans) {
			printf("%d==?\n", n);
			break;
		}
	}
	printf("%d", cnt);

	return 0;
}

/*
6장4절 [ 문제 4 ] 두 개의 양의 정수 N과 M을 입력 받아 두 정수의 최대공약수를 출력하는 프
로그램을 for 문을 이용해서 작성해보고, 다시 while 문을 이용하여 작성해보시오.
*/

#include<stdio.h>

int main() {

	int gcd, m, n, i, j;
	scanf("%d %d", &m, &n);
	j = (m < n) ? m : n;

	for (i = 1; i <= j; i++)
		if (m % i == 0 && n % i == 0)
			gcd = i;

	printf("%d\n", gcd);

	return 0;
}

/*
6장5절 [ 문제 5 ] 양의 정수 N을 입력 받아, 아래 예시와 같이 높이가 N인 삼각형을 출력하는
프로그램을 for 문을 중첩 이용하여 작성하시오.
 - 자릿수에 맞게 공백문자 출력
*/

#include<stdio.h>

int main() {

	int i, j, n;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i; j++)
			printf(" ");
		for (j = 0; j < (2 * i + 1); j++)
			printf("*");
		printf("\n");
	}

	return 0;
}

/*
6장5절 [ 문제 6 ] 양의 정수 N을 입력받아, 아래와 같이 N줄을 출력하시오. for 문과 while 문을
중첩 이용하여 작성하시오. - 중첩 반복문
 - 각 줄 첫 숫자 앞에는 공백 하나가 있음. 각 수 사이는 하나의 공백으로 구분, 맨 마지막에는
 공백 없음
 예) □1□2□3□4□5□6□7□8□9□0
*/

#include<stdio.h>

int main() {

	int N, i, j, k, ind, tmp;
	scanf("%d", &N);
	i = 0;
	while (i < N) {
		for (j = i + 1; j <= N + i; j++)printf(" %d", j % 10);
		printf("\n");
		i++;
	}

	return 0;
}

/*
[ 문제 6-1 ] 양의 정수 N을 입력받아, 아래와 같이 N줄을 출력하시오.
 - 중첩 반복문. N은 홀수이다. 즉 짝수에 대해서는 고려하지 않아도 잘 됨
 - 각 줄 첫 문자 앞에는 공백 하나가 있음. 각 문자 사이는 하나의 공백으로 구분, 맨 마지막에
 는 공백 없음. X O 는 대문자 이다. 예) □O□O□O□O□O□O□O□O□O
*/

#include<stdio.h>

int main() {

	int i, j, n;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j || i == n - j - 1)
				printf("X ");
			else
				printf("O ");
		}
		printf("\n");
	}

	return 0;
}

/*
[ 문제 6-2 ] 양의 정수 N을 입력받아, 아래와 같이 N줄을 출력하시오.
 - 중첩 반복문
 - 각 줄 첫 숫자 앞에는 공백 하나가 있음. 각 수 사이는 하나의 공백으로 구분, 맨 마지막에는
 공백 없음
 예) □1□2□3□4□5□6□7□8□9□0
*/

#include<stdio.h>

int main() {

	int i, j, n, cnt = 1;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf(" %d", cnt++);
			if (cnt > 9)
				cnt = 0;
		}
		printf("\n");
	}

	return 0;
}

/*
6장5절 [ 문제 7 ] 하나의 양의 정수 N을 받아 아래와 같이 출력하는 프로그램을 작성하시오.
 - 숫자는 1, 2, 3, 4, …. 9, 0으로 순환하면서 출력
 - 각 줄의 수는 하나의 공백을 사이에 두고 출력. 맨 마지막에는 공백 없음. 각 줄의 첫 숫자 앞
 에 공백 하나 있음.
*/

#include<stdio.h>

int main() {

	int i, j, n, cnt = 1;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 0; j < i; j++) {
			printf(" %d", cnt++);
			if (cnt > 9)
				cnt = 0;
		}
		printf("\n");
	}

	return 0;
}

/*
6장4절 [ 문제 8 ] 정수 M, N을 입력받는다. for 문을 사용하여 M!(펙토리얼) 부터 N!(펙토리얼)까
지 출력하는 프로그램을 작성하시오. - 2중 for 문 이용
- 1단계: 먼저 5!=120 출력을 완성한다.
- 2단계: 그다음 5!=1*2*3*4*5=120 출력을 완성한다.
- 3단계: 그다음 출력 예시1 과 같이 출력한다.
*/

#include<stdio.h>

int main() {

	int i, j, n, m, fac;
	scanf("%d %d", &m, &n);

	for (i = m; i <= n; i++) {
		printf("%d!=", i);
		fac = i;
		for (j = 1; j < i; j++) {
			printf("%d*", j);
			fac *= j;
		}
		printf("%d=%d\n", i, fac);
	}

	return 0;
}

/*
6장5절 [ 문제 9 ] 하나의 양의 정수 N을 입력 받아, 1부터 N까지의 정수에서 숫자 3이 총 몇 번
나타나는지를 출력하는 프로그램 작성하시오.
 - 중첩 반복문 (for 문, while 문 사용) 
 - N=33 일 때, 3, 13, 23, 30, 31, 32, 33, 총 7개의 수에서 8개의 3이 나타난다. (∵ 숫자 33에는 3이 두 개 있으므로)
*/

#include<stdio.h>

int main() {

	int i, n, m, cnt = 0, result;
	scanf("%d", &m);

	for (i = 1; i <= m; i++) {
		n = i;
		while (n > 0) {
			result = n % 10;
			if (result == 3)
				cnt++;
			n /= 10;
		}
	}
	printf("%d", cnt);

	return 0;
}

/*
6장5절 [ 문제 10 ] 10이상의 양의 정수 N을 입력 받아 디지털근을 출력하는 프로그램을 작성하
시오. N의 각 자리수를 더한다. 한 자리 수가 될 때까지 반복한다. - 디지털근, 예) 6234 à 6+2+3+4 = 15 à 1+5 = 6
 예) 52561 -> 5+2+5+6+1 = 19 -> 1+9 = 10 -> 1+0 = 1
 - 중첩 while 문 이용해야 해결됩니다.
*/

#include<stdio.h>

int main() {

	int N, a = 1, b = 0;
	scanf("%d", &N);
	while (a <= 10 * N)
	{
		if (b <= 9)
		{
			b = b + (N / a) % 10;
		}

		while (b >= 10)
		{
			b = b % 10 + b / 10;
		}
		a = a * 10;
	}
	printf("%d", b);

	return 0;
}

/*
6장5절 [ 문제 11 ] 3~18사이의 정수 N을 입력 받아, 3개의 주사위의 총 합이 N이 되는 모든 경
우를 출력하는 프로그램을 작성하시오.
 - 중첩 반복문
 - 각 줄의 수는 하나의 공백을 사이에 두고 출력, 맨 마지막에는 공백 없음
 1□3□6
*/

#include<stdio.h>

int main() {

	int n, i, j, k;
	scanf("%d", &n);

	for (i = 1; i <= 6; i++) {
		for (j = 1; j <= 6; j++)
			for (k = 1; k <= 6; k++)
				if (i + j + k == n)
					printf("%d %d %d\n", i, j, k);
	}

	return 0;
}

/*
6장6절 [ 문제 12 ] 하나의 양의 정수 N을 입력 받아 1부터 N까지의 합을 출력하는 프로그램을
작성하시오. - for 문의 무한루프 이용
 - break 문 이용
*/

#include<stdio.h>

int main() {

	int n, i, sum = 0;
	scanf("%d", &n);

	for (i = 1;; i++) {
		sum += i;
		if (i == n)
			break;
	}

	printf("%d", sum);

	return 0;
}

/*
6장7절 [ 문제 13 ] 정수 N을 반복해서(종료 조건 시까지) 입력받아 N의 합계, 평균, 개수를 출력
하는 프로그램을 작성하시오. - 종료 조건: 0 이하 정수 입력 (합계, 평균, 개수 계산에는 제외) - 입력된 수 중에서 100을 넘는 수는 계산에서 제외 한다 (예시2를 보시오)
 - while 문, if 문, break 문, continue 문 이용
 - 실수는 소수점 이하 둘째 자리까지만 출력하시오.
*/

#include<stdio.h>

int main() {

	int n, cnt = 0;
	float avg, sum = 0.0;
	scanf("%d", &n);

	while (n > 0) {
		if (n <= 100) {
			sum += n;
			cnt++;
		}
		scanf("%d", &n);
	}
	avg = sum / cnt;

	printf("%.0f %.2f %d", sum, avg, cnt);

	return 0;
}