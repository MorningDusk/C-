/* [ 문제 1 ] 배열에 10개의 양의 정수를 입력 받아서 저장하고, 저장된 정수 중 짝수만 출력하시오. */

#include<stdio.h>

int main() {

	int x[10], i;
	for (i = 0; i < 10; ++i) {
		scanf("%d", &x[i]);
		if (x[i] % 2 == 0)
			printf(" %d", x[i]);
	}

	return 0;
}

/* [ 문제 2 ] 배열에 10개의 정수를 입력 받아서 저장하고, 저장된 정수의 합을 출력하시오.  */

#include<stdio.h>

int main() {

	int x[10], i, sum = 0;
	for (i = 0; i < 10; ++i) {
		scanf("%d", &x[i]);
		sum += x[i];
	}
	printf("%d", sum);

	return 0;
}

/* [ 문제 3 ] 배열 X와 배열 Y에 각각 10개의 정수를 입력 받아서 저장하고, 두 배열의 k번째 원소
의 합을 배열 Z의 k번째 원소로 저장한 후 배열 Z의 원소를 출력하시오. 단, k=0, 1, 2, ..., 9임. */

#include<stdio.h>

int main() {

	int x[10], y[10], i, sum[10] = { 0 };
	for (i = 0; i < 10; ++i) {
		scanf("%d", &x[i]);
	}
	scanf("\n");
	for (i = 0; i < 10; ++i)
		scanf("%d", &y[i]);

	for (i = 0; i < 10; ++i) {
		sum[i] += x[i] + y[i];
		printf(" %d", sum[i]);
	}

	return 0;
}

/* [ 문제 4 ] 배열 X와 배열 Y에 각각 10개의 정수를 입력 받아서 저장한다. 배열 X의 0번 원소와
배열 Y의 9번 원소의 합을 배열 Z의 0번 원소로, 배열 X의 1번 원소와 배열 Y의 8번 원소의 합
을 배열 Z의 1번 원소로, ..., 배열 X의 9번 원소와 배열 Y의 0번 원소의 합을 배열 Z의 9번 원소
로 저장한 후, 배열 Z의 원소를 출력하시오. 단, k=0, 1, 2, ..., 9임. */

#include<stdio.h>

int main() {

	int x[10], y[10], i, sum[10] = { 0 };
	for (i = 0; i < 10; ++i) {
		scanf("%d", &x[i]);
	}
	scanf("\n");
	for (i = 0; i < 10; ++i)
		scanf("%d", &y[i]);

	for (i = 0; i < 10; ++i) {
		sum[i] += x[i] + y[9 - i];
		printf(" %d", sum[i]);
	}

	return 0;
}

/* [ 문제 5 ] 배열에 10개의 정수를 입력 받아서 저장하고, 저장된 정수 중 가장 큰 수를 출력하시
오. */

#include<stdio.h>

int main() {

	int x[10], i, j, max = 0;
	for (i = 0; i < 10; ++i)
		scanf("%d", &x[i]);

	max = x[0];

	for (j = 0; j < 10; ++j) {
		if (x[j] > max)
			max = x[j];
	}

	printf("%d", max);

	return 0;
}

/* [ 문제 6 ] 배열에 10개의 정수를 입력 받아서 저장하고, 각 정수보다 큰 정수의 개수를 출력하시
오. */

#include<stdio.h>

int main() {

	int x[10], cnt[10] = { 0 }, i, j;
	for (i = 0; i < 10; i++)
		scanf("%d", &x[i]);

	for (i = 0; i < 10; ++i) {
		for (j = 0; j < 10; ++j)
			if (x[j] > x[i])
				++cnt[i];
	}

	for (i = 0; i < 10; ++i)
		printf(" %d", cnt[i]);

	return 0;
}

/* [ 문제 7 ] 배열에 10개의 정수를 입력 받아서 저장하고 (동일 정수가 반복 입력 될 수 있음), 저
장된 정수를 중복 없이 한 번씩만 출력 하시오. 중복 입력된 정수의 출력 순서는 처음 입력된 위
치입니다. */

#include<stdio.h>

int main() {

	int x[10], i, j;
	for (i = 0; i < 10; ++i)
		scanf("%d", &x[i]);

	for (i = 0; i < 10; ++i) {
		j = 0;
		while (j < i && x[i] != x[j])
			++j;
		if (i == j)
			printf(" %d", x[i]);
	}

	return 0;
}

/* [ 문제 8 ] 정수 N을 입력 받아 한 자리씩 나누어 역순으로 배열 X에 저장 한 후, 배열 X의 원소
들을 출력 하시오. 단, N은 최대 10 자리 수임.  */

#include<stdio.h>

int main() {

	int i, cnt = 0, n, x[10];
	scanf("%d", &n);

	while (n > 0) {
		x[cnt++] = n % 10;
		n /= 10;
	}

	for (i = 0; i < cnt; i++) {
		printf(" %d", x[i]);
	}

	return 0;
}

/* [ 문제 9 ] 정수 N을 입력 받는다. 0을 포함하여 한 자리 양의 정수를 N개 입력 받아 배열 X에
저장 한 후, 입력된 정수들로 이루어진 정수 M을 만들어 출력 하시오. 단, 1≦N≦10. 
- 입력 정수가 중복될 수도 있다.  */

#include<stdio.h>

int main() {

	int n, m = 0, x[10], i, j;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; ++i)
		scanf("%d", &x[i]);

	for (j = 0; j < n; ++j) {
		m = x[j] + m * 10;
	}
	printf("%d", m);

	return 0;
}

/* [ 문제 10 ] 배열에 10개의 실수를 입력 받아서 저장하고, 저장된 실수 중 0보다 큰 실수만 출력
하시오. 소수점 아래 첫째자리까지 출력하시오. */

#include<stdio.h>

int main() {

	float x[10];
	int i;
	for (i = 0; i < 10; ++i) {
		scanf("%f", &x[i]);
	}

	for (i = 0; i < 10; ++i) {
		if (x[i] > 0)
			printf(" %.1f", x[i]);
	}

	return 0;
}

/* [ 문제 11 ] 배열에 10개의 실수를 입력 받아서 저장하고, 저장된 실수 중 가장 작은 수를 출력하
시오. 소수점 아래 첫째자리까지 출력하시오. */

#include<stdio.h>

int main() {

	float x[10], min;
	int i;
	for (i = 0; i < 10; ++i) {
		scanf("%f", &x[i]);
	}

	min = x[0];
	for (i = 1; i < 10; ++i) {
		if (min > x[i])
			min = x[i];
	}
	printf("%.1f", min);

	return 0;
}

/* [ 문제 12 ] 배열에 10개의 실수를 입력 받아서 저장하고, 각 실수보다 작은 실수의 개수를 출력
하시오. */

#include<stdio.h>

int main() {

	float x[10];
	int i, j, cnt[10] = { 0 };
	for (i = 0; i < 10; ++i) {
		scanf("%f", &x[i]);
	}

	for (i = 0; i < 10; ++i) {
		for (j = 0; j < 10; ++j)
			if (x[j] < x[i])
				++cnt[i];
	}
	for (i = 0; i < 10; ++i)
		printf(" %d", cnt[i]);

	return 0;
}

/* [ 문제 13 ] 배열에 10개의 문자를 입력 받아서 저장하고, 저장된 문자 중 대문자만 출력하시오. */

#include<stdio.h>

int main() {

	char ch[10];
	int i, j;
	for (i = 0; i < 10; i++)
		scanf("%c", &ch[i]);

	for (i = 0; i < 10; i++)
		if (ch[i] >= 'A' && ch[i] <= 'Z')
			printf(" %c", ch[i]);

	return 0;
}

/* [ 문제 14 ] 배열 x 와 배열 y에 각각 10개의 문자를 입력 받아서 저장하고, 두 배열에 저장된 문
자를 번갈아가며 출력 하시오. 단, 배열 x 에 저장된 문자를 먼저 출력하기 시작 한다. 
- 엔터키를 입력받아서, 버리기 위하여 getchar( ); 를 사용하시오. */

#include<stdio.h>

int main() {

	char x[10], y[10], z[20] = { 'a' };
	int i, j;
	for (i = 0; i < 10; ++i)
		scanf("%c", &x[i]);
	getchar();
	for (i = 0; i < 10; ++i)
		scanf("%c", &y[i]);

	for (i = 0; i < 10; ++i) {
		printf(" %c", x[i]);
		printf(" %c", y[i]);
	}

	return 0;
}

/* [ 문제 15 ] 배열에 10개의 문자를 입력 받아서 저장하고 (동일 문자가 반복 입력 될 수 있음), 저
장된 문자 중 중복이 없는 문자만 출력 하시오.  */

#include<stdio.h>

int main() {

	char ch[10];
	int i, j, cnt;
	for (i = 0; i < 10; ++i)
		scanf("%c", &ch[i]);

	for (i = 0; i < 10; ++i) {
		cnt = 0;
		for (j = 0; j < 10; ++j) {
			if (ch[i] == ch[j])
				cnt++;
		}
		if (cnt == 1)
			printf(" %c", ch[i]);
	}

	return 0;
}

/* [ 문제 16 ] N개의 문자와 정수를 입력 받는다. 정수를 N으로 나눈 나머지를 배열의 인덱스로 하
여서, 인덱스가 가리키는 원소를 예시와 같이 출력하시오. N ≦ 10 */

#include<stdio.h>

int main() {

	int n, i, x[10];
	char s[10];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; ++i)
		scanf("%c", &s[i]);
	getchar();
	for (i = 0; i < n; ++i)
		scanf("%d", &x[i]);

	for (i = 0; i < n; ++i) {
		printf("x[%d%%%d]=x[%d]=%c\n", x[i], n, x[i] % n, s[x[i] % n]);
	}

	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

/*
[ 문제 1 ] 0 이하의 수가 입력될 때 까지 입력받는다. 짝수를 역순으로 출력하고, 그다음 홀수를
역순으로 출력하시오. 최대로 입력되는 정수는 100개 이다. (2-2)
*/

#include<stdio.h>

int main() {

	int x[100], i, cnt = 0, cnt1 = 0, cnt2 = 0, even[100], odd[100], inv_e[100], inv_o[100], n;
	for (i = 0; i < 100; i++) {
		scanf("%d", &n);
		if (n <= 0)
			break;
		x[cnt] = n;
		cnt++;
	}

	for (i = 0; i < cnt; i++) {
		if (x[i] % 2 == 0) {
			even[cnt1] = x[i];
			cnt1++;
		}
		else {
			odd[cnt2] = x[i];
			cnt2++;
		}
	}


	for (i = 0; i < cnt1; i++)
		inv_e[i] = even[cnt1 - i - 1];
	for (i = 0; i < cnt2; i++)
		inv_o[i] = odd[cnt2 - i - 1];

	for (i = 0; i < cnt1; i++)
		printf(" %d", inv_e[i]);
	printf("\n");
	for (i = 0; i < cnt2; i++)
		printf(" %d", inv_o[i]);

	return 0;
}

/*
[ 문제 2 ] 이웃하는 두 글자로 된 단어 중에서 가장 빈번하게 나오는 두 글자 단어를 출력하고
횟수도 출력하시오. 배열의 크기는 100, 3 ≦N ≦ 100. 소문자만 입력된다. (1-3)
*/

#include<stdio.h>

int main() {

	char c[100], a = 'z', b = 'z';
	int i, j, n, cnt, m[100], tmp = 0, max = 0;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%c", &c[i]);

	for (i = 0; i < n - 1; i++) {
		cnt = 1;
		for (j = i + 1; j < n; j++) {
			if ((c[i] == c[j]) && (c[i + 1] == c[j + 1])) {
				cnt++;
			}
		}
		if (max < cnt)
			max = cnt;
		m[tmp] = cnt;
		tmp++;
	}

	for (i = 0; i < tmp; i++)
		if (max == m[i]) {
			a = c[i];
			b = c[i + 1];
		}
	printf("%c%c %d", a, b, max);

	return 0;
}

/*
[ 문제 3 ] N개 정수를 입력받는다. 입력받은 각 숫자에 대해서 자신 보다 크거나 같은 정수의 개
수를 출력하시오. (자신도 포함) N≦100
*/

#include<stdio.h>

int main() {

	int n, x[100], i, j, cnt[100] = { 0 };
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j)
			if (x[j] >= x[i])
				++cnt[i];
	}
	for (i = 0; i < n; i++)
		printf(" %d", cnt[i]);

	return 0;
}

/*
[ 문제 4 ] 길이가 N인, 영어 단어 두 개를 입력 받아서 사전에서 먼저 나오는 단어를 출력하시
오. 엔터키를 버퍼에서 제거하기 위해서 getchar( ) 사용한다. N≦100
*/

#include<stdio.h>

int main() {

	char x[100], y[100];
	int i, j, k, n;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%c", &x[i]);
	}
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%c", &y[i]);
	}

	j = 0;
	while (1) {
		if (x[j] < y[j]) {
			for (k = 0; k < n; k++)
				printf("%c", x[k]);
			break;
		}
		else if (x[j] > y[j]) {
			for (k = 0; k < n; k++)
				printf("%c", y[k]);
			break;
		}
		else
			j++;
	}

	return 0;
}

/*
[ 문제 5 ] 단어가 회문인지 조사하시오. 회문 예: level 회문이면 앞에서 반만 출력하고, 아니면
none 이라고 출력하시오. N≦100
*/

#include<stdio.h>

int main() {

	char c[100], inv[100];
	int i, n, flag = 0;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%c", &c[i]);

	for (i = 0; i < n; i++) {
		inv[i] = c[n - i - 1];
	}
	for (i = 0; i < n; i++) {
		if (inv[i] == c[i])
			flag++;
	}

	if (flag == n) {
		if (n % 2 == 0)
			for (i = 0; i < n / 2; i++)
				printf("%c", c[i]);
		else
			for (i = 0; i < n / 2 + 1; i++)
				printf("%c", c[i]);
	}
	else
		printf("none");

	return 0;
}

/*
[ 문제 6 ] 0까지 입력받아, 0부터 최대수 사이 빠진 수를 차례로 모두 출력하시오. (1-7)
 - 입력되는 정수는 최대 100개 이다.
*/

#include<stdio.h>

int main() {

	int x[100], y[100], n, i, j, max = 0, cnt = 0, flag;
	for (i = 0; i < 100; i++) {
		scanf("%d", &n);
		if (max < n)
			max = n;
		x[cnt] = n;
		cnt++;
		if (n == 0)
			break;
	}

	for (i = 0; i <= max; i++)
		y[i] = i;

	for (i = 0; i <= max; i++) {
		flag = 0;
		for (j = 0; j < cnt; j++) {
			if (x[j] == y[i])
				flag++;
		}
		if (flag == 0)
			printf("%d ", y[i]);
	}

	return 0;
}

/*
[ 문제 7 ] '*'까지 읽어 들여서, 2번 이상 반복되는 문자와 개수를 출력하시오. (3-3) 
 - 입력되는 문자 순서로 출력하시오. 입력 문자는 최대 100개 이다. 
 - 2번 이상 반복되는 문자와 개수를, 문자별 한번만 출력한다.
*/

#include<stdio.h>

int main() {

	char c[100], ch;
	int cnt = 0, i, j, k, r;
	for (i = 0; i < 100; i++) {
		scanf("%c", &ch);
		c[cnt] = ch;
		cnt++;
		if (ch == '*')
			break;
	}

	for (i = 0; i < cnt; i++) {
		j = 0;
		r = 0;
		while (j < i && c[i] != c[j])
			j++;
		for (k = 0; k < cnt; k++)
			if (c[i] == c[k])
				r++;
		if (i == j && r >= 2)
			printf("%c %d\n", c[i], r);
	}

	return 0;
}

/*
[ 문제 8 ] 국어 영어 수학 성적 각각 N개씩 입력받으시오. 즉 N명의 학생이 있다. 세 과목 합에
대한 평균 미만은 B를 평균 이상은 A를 출력하시오. N은 최대 20명이다.
*/

#include<stdio.h>

int main() {

	float n, sum = 0.0, k[20], e[20], m[20], avg = 0.0;
	int i, j;
	scanf("%f", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%f", &k[i]);
		sum += k[i];
	}
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%f", &e[i]);
		sum += e[i];
	}
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%f", &m[i]);
		sum += m[i];
	}

	avg = sum / n;
	printf("%.2f\n", avg);

	for (i = 0; i < n; i++) {
		if (k[i] + e[i] + m[i] >= avg)
			printf(" A");
		else
			printf(" B");
	}

	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

/*
[ 문제 1 ] 정수 N개씩 두 번 입력 받는다. 차집합을 출력하시오. 즉 집합 x에만 있고 집합 y에는
없는 원소를 출력하시오
*/

