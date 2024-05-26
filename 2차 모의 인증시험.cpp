/* 문제 1
정수 세 개를 반복해서 입력 받도록 하여라. 매번 입력 받은 세 수의 크기대로 가장 큰 수부터 가장 작은 수 순으로 출력하도록 하여라. 만약 세 개의 정수가 모두 0일 경우에는 프로그램을 종료한다.
*/

#include<stdio.h>
int main() {
	int n[5], tmp, i, j;
	while (1) {
		for (i = 0; i < 5; i++)
			scanf("%d", &n[i]);

		if (n[0] == 0 && n[1] == 0 && n[2] == 0)
			break;
		for (i = 0; i < 4; i++)
			for (j = i; j < 5; j++)
				if (n[i] < n[j]) {
					tmp = n[i];
					n[i] = n[j];
					n[j] = tmp;
				}
		for (i = 0; i < 3; i++)
			printf("%d ", n[i]);
	}
	return 0;
}

	/*-------------------------------------------------------------------------------------------*/

#include<stdio.h>

	void sort(int x[3]) {
		int i, j, tmp;
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2 - i; j++) {
				if (x[j] < x[j + 1]) {
					tmp = x[j + 1];
					x[j + 1] = x[j];
					x[j] = tmp;
				}
			}
		}
		for (i = 0; i < 3; i++) {
			printf("%d ", x[i]);
		}
	}

	int main() {
		int i, x[3];

		while (1) {
			for (i = 0; i < 3; i++) {
				scanf("%d", &x[i]);
			}
			if (x[0] == 0 && x[1] == 0 && x[2] == 0) {
				break;
			}
			sort(x);
			printf("\n");
		}


		return 0;
	}

/* 문제 2
금액을 나타내는 양의 정수 n을 입력받고, 이 금액으로 A(900), B(750), C(200)의 세 가지 상품을 구매하고 잔돈을 남기지 않는 구매 방법 중 아래 조건을 만족하는 구매 방법만을 출력하는 프로그램을 작성하시오.
- A, B, C 각 상품은 최소 한 개 이상 구매 되어야 한다
- B 상품은 항상 짝수 개로 구매한다
- C 상품의 수량은 A 상품의 수량보다 작거나, B 상품의 수량보다 작다.
*/

#include <stdio.h>

int main() {
	int n, A = 900, B = 750, C = 200, a, b, c;
	scanf("%d", &n);
	for (a = 1; a * A < n; a++)
		for (b = 2; a * A + b * B < n; b += 2)
			for (c = 1; a * A + b * B + c * C <= n; c++)
				if (a * A + b * B + c * C == n)
					if (c < a || c < b)
						printf("%d %d %d\n", a, b, c);
	return 0;
}

/*-------------------------------------------------------------------------------*/

#include<stdio.h>

int main() {

	int n, a = 900, b = 750, c = 200, i, j, k;
	scanf("%d", &n);


	for (i = 1; i < a; i++)
		for (j = 1; j < b; j++)
			for (k = 1; k < c; k++) {
				if ((i * a + j * b + k * c == n) && (j % 2 == 0 && (k < i || k < j)))
					printf("%d %d %d\n", i, j, k);
			}

	return 0;
}

/* 문제 3
n개의 양의 정수를 배열에 입력 받은 후, 배열의 각 요소가 몇 번 반복이 되었는지 배열의 각 요소의 순서대로 반복횟수를 출력하는 프로그램을 작성하시오.
*/

#include <stdio.h>

int main() {
	int n, arr[50], cnt[50] = { 0 }, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (arr[i] == arr[j])
				cnt[i]++;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if (arr[i] == arr[j])
				break;
		if (i == j)
			printf("%d %d\n", arr[i], cnt[i]);
	}

	return 0;
}
/*----------------------------------------------------------------*/

#include<stdio.h>

int main() {

	int n, i, j, x[50], freq[50];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);

	for (i = 0; i < n; i++) {
		freq[i] = 0;
		for (j = 0; j < n; j++) {
			if (x[i] == x[j]) {
				freq[i]++;
				if (i != j)
					x[j] = -1;
			}
		}
		if (x[i] != -1)
			printf("%d %d\n", x[i], freq[i]);
	}


	return 0;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main() {

	int n, x[100], i, j, cnt, k;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (i = 0; i < n; i++) {
		cnt = 0;
		k = 0;
		while (k < i && x[i] != x[k])
			++k;
		for (j = 0; j < n; j++) {
			if (x[i] == x[j])
				cnt++;
		}
		if (i == k)
			printf("%d %d\n", x[i], cnt);
	}

}

/* 문제 4
첫 번째 '*'가 입력될 때까지 영어 소문자를 %c로 계속 입력 받아 배열 x에 저장하고, 두 번째 '*'가 입력될 때까지 영어 소문자를 %c로 계속 입력 받아 배열 y에 저장한다.
-즉, 두 단어를 다음과 같이 입력 받는다. first_word*second_word* 
-'*'를 단어에 포함하지 않는다.
- 저장된 두 영어 단어 중에서 사전에서 먼저 나타나는 단어를 출력하시오.
-입력되는 문자 수는 최대 100 이다. 각 단어는 문자 1개 이상이다.
*/

#include <stdio.h>

int main() {

	char x[100], y[100];
	int i, j, k, xcnt = 0, ycnt = 0;
	for (i = 0; i < 100; i++) {
		scanf("%c", &x[i]);
		if (x[i] == '*') {
			xcnt = i;
			break;
		}
	}
	for (i = 0; i < 100; i++) {
		scanf("%c", &y[i]);
		if (y[i] == '*') {
			ycnt = i;
			break;
		}
	}

	j = 0;
	while (1) {
		if (x[j] < y[j] || xcnt <= j) {
			for (k = 0; k < xcnt; k++)
				printf("%c", x[k]);
			break;
		}
		else if (x[j] > y[j] || ycnt <= j) {
			for (k = 0; k < ycnt; k++)
				printf("%c", y[k]);
			break;
		}
		else
			j++;
	}
	
	return 0;
}

/* 문제 5
연도를 나타내는 정수를 입력받아 두 해 사이의 윤년 개수를 세는 프로그램을 작성하시오.
*/

#include <stdio.h>

int isLeapYear(int year);
int getTotalNumberOfLeapYear(int startYear, int endYear);

int main() {
	int startYear = 0, endYear = 0;
	scanf("%d%d", &startYear, &endYear);
	printf("%d", getTotalNumberOfLeapYear(startYear, endYear));
	return 0;
}

int isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	return 0;
}

int getTotalNumberOfLeapYear(int startYear, int endYear) {
	int cnt = 0;
	for (int i = startYear; i <= endYear; i++) {
		if (isLeapYear(i))
			cnt++;
	}
	return cnt;
}