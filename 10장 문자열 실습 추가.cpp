/*
[ 문제 1 ] N은 최대 10인 정수이다. N개의 공백이 없는 단어를 입력받는다. 마지막 줄에 N개의
숫자를 읽어 들인다. 단어의 크기는 최대 100 이다. 순서대로 문자열을 만들어서 출력하시오
*/

#include <stdio.h>
#include <string.h>

int main() {

	int n, i, ar[10];
	char str[10][100];

	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; i++)
		scanf("%s", str[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &ar[i]);

	for (i = 0; i < n; i++)
		printf("%s ", str[ar[i] - 1]);

	return 0;
}

/*
[ 문제 2 ] 공백이 있는 문자열을 gets 로 읽어서 1차원 배열에 저장 후, 다시 2차원 배열에 저장
후, 단어별로 출력하시오. 입력되는 문자 수는 최대 100. 단어는 최대 10개.
*/

#include <stdio.h>
#include <string.h>

int main() {

	char ar[100], *p, *q;
	gets(ar);
	q = ar;

	for (p = ar; ; p++) {
		if (*p == ' ') {
			*p = '\0';
			printf("%s\n", q);
			q = p + 1;
		}
		else if (*p == 0) {
			printf("%s\n", q);
			break;
		}
	}

	return 0;
}

/*
[ 문제 3 ] 공백이 있는 문자열을 gets 로 읽어서 1차원 배열에 저장 후, 다시 2차원 배열에 저장
후, 길이 순 내림차순으로 정렬하시오. 입력되는 문자 수는 최대 100. 단어는 최대 10개.
*/

#include <stdio.h>
#include <string.h>

int main() {

	char ar[100], *p, *q, b[10][100], tmp[100] = { 0 };
	int i, j, k = 0, len[10] = { 0 }, ntmp;
	gets(ar);
	q = ar;

	for (p = ar; ; p++) {
		if (*p == ' ') {
			*p = '\0';
			len[k] = strlen(q);
			strcpy(b[k++], q);
			q = p + 1;
		}
		else if (*p == 0) {
			len[k] = strlen(q);
			strcpy(b[k++], q);
			break;
		}
		len[k] = strlen(b[k]);
	}

	for (i = 0; i < k - 1; i++)
		for (j = 0; j < k - i - 1; j++)
			if (len[j] < len[j + 1]) {
				strcpy(tmp, b[j]);
				strcpy(b[j], b[j + 1]);
				strcpy(b[j + 1], tmp);
				ntmp = len[j];
				len[j] = len[j + 1];
				len[j + 1] = ntmp;
			}

	for (i = 0; i < k; i++)
		printf("%s\n", b[i]);


	return 0;
}

/*
[ 문제 4 ] 공백이 있는 문자열을 gets 로 읽어서 1차원 배열에 저장 후, 다시 2차원 배열에 저장
후, 길이 순 내림차순으로 정렬하시오. 입력되는 문자 수는 최대 100. 단어는 최대 10개. 길이가 같으면 알파벳순으로 정렬하시오.
*/

#include<stdio.h>
#include <string.h>

int main() {

	char ar[100], *p, *q, b[10][100], tmp[100] = { 0 };
	int i, j, k = 0, len[10] = { 0 }, ntmp;
	gets(ar);
	q = ar;

	for (p = ar; ; p++) {
		if (*p == ' ') {
			*p = '\0';
			len[k] = strlen(q);
			strcpy(b[k++], q);
			q = p + 1;
		}
		else if (*p == 0) {
			len[k] = strlen(q);
			strcpy(b[k++], q);
			break;
		}
		len[k] = strlen(b[k]);
	}

	for (i = 0; i < k - 1; i++)
		for (j = 0; j < k - i - 1; j++) {
			if (len[j] < len[j + 1]) {
				strcpy(tmp, b[j]);
				strcpy(b[j], b[j + 1]);
				strcpy(b[j + 1], tmp);
				ntmp = len[j];
				len[j] = len[j + 1];
				len[j + 1] = ntmp;
			}
			else if (len[j] == len[j + 1] && strcmp(b[j], b[j + 1]) > 0) {
				strcpy(tmp, b[j]);
				strcpy(b[j], b[j + 1]);
				strcpy(b[j + 1], tmp);
				ntmp = len[j];
				len[j] = len[j + 1];
				len[j + 1] = ntmp;
			}
		}

	for (i = 0; i < k; i++)
		printf("%s\n", b[i]);

	return 0;
}

/*
[ 문제 5 ] 2개의 공백이 없는 단어를 입력받는다. 단어의 크기는 각각 최대 100 이다. 첫 번째 단
어를 출력하다가 모음이 나타나면 출력하고, 두 번째 단어 처음부터 출력한다. 두 번째 단어를 출
력하다 모음이 나타나면 모음을 출력하고 첫 번째 단어에서 아직 출력이 안 된 문자로 이동한다.
 - 이것을 반복한다.
 - 두 단어 중 하나가 먼저 끝나면, 다음 단어로 이동한다. <-- [ 문제 1-6 ]
 - vowel( ) 함수를 이용한다.
 ∘ 인자: 문자형 인자 한 개
 ∘ 입력된 문자가 모음이면 1을 반환하고, 아니면 0을 반환한다. 모음은 A, a, E, e, ...
 ∘ 반환값: 정수
*/

#include <stdio.h>
#include <string.h>

int vowel(char ch) {
	if (ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
		return 1;
	else
		return 0;
}

int main() {

	char str1[100], str2[100];
	int i = 0, j = 0, k, f = 1, L1, L2;

	scanf("%s", str1);
	scanf("%s", str2);

	while (1) {
		L1 = strlen(str1);
		L2 = strlen(str2);
		if (i == L1 && j == L2)
			break;
		else if (f == 1 && vowel(str1[i]) == 1 && i < L1 && j < L2) {
			f = 2;
			printf("%c", str1[i++]);
		}
		else if (f == 2 && vowel(str2[j]) == 1 && i < L1 && j < L2) {
			f = 1;
			printf("%c", str2[j++]);
		}
		else if (f == 1 && i < L1)
			printf("%c", str1[i++]);
		else if (f == 2 && j < L2)
			printf("%c", str2[j++]);
		else if (i == L1 && j < L2) {
			for (k = j; k < L2; k++)
				printf("%c", str2[k]);
			break;
		}
		else if (i < L1 && j == L2) {
			for (k = i; k < L1; k++)
				printf("%c", str1[k]);
			break;
		}
	}

	return 0;
}

/*
[ 문제 6 ] 문자가 3번 이상 반복될 때, 처음 문자와 마지막 문자를 제외하고 나머지 문자를 대문
자로 바꾸어 출력하시오. 입력되는 문자 수는 최대 100.
 - front 함수
 ∘ 인자: 배열을 나타내는 char형 포인터, 인덱스를 나타내는 정수형 변수 idx
 ∘ 반환값: 현재의 인덱스 앞에 반복되는 것이 있으면 1을 반환하고, 없으면 0을 반환
 ∘ 배열기호 사용하지 말고, 배열을 포인터로 훑어보기.
 - back 함수
 ∘ 인자: 배열을 나타내는 char형 포인터, 인덱스를 나타내는 정수형 변수 idx
 ∘ 반환값: 현재의 인덱스 뒤에 반복되는 것이 있으면 1을 반환하고, 없으면 0을 반환
 ∘ 배열기호 사용하지 말고, 배열을 포인터로 훑어보기.
 - main( ) 함수
 ∘ 문자열 입력받기
 ∘ 문자열 출력하기. %c 사용금지
*/

#include <stdio.h>
#include <string.h>

int front(char *c, int idx) {
	char *p;
	int cnt = 0, flag = 0;
	for (p = c; p <= c + idx; p++) {
		if (*p == *(c + idx))
			cnt++;
		if (cnt > 1)
			flag = 1;
	}
	return flag;
}

int back(char *c, int idx) {
	char *p;
	int cnt = 0, flag = 0;
	for (p = c + idx; p < c + strlen(c); p++) {
		if (*p == *(c + idx))
			cnt++;
		if (cnt > 1)
			flag = 1;
	}
	return flag;
}

int main() {

	char str[100];
	char *ps = str;
	int i;
	scanf("%s", str);

	for (i = 0; i < strlen(str); i++) {
		if (front(&str[0], i) == 1 && back(&str[0], i) == 1)
			str[i] -= 32;
	}

	for (i = 0; i < strlen(str); i++)
		printf("%c", str[i]);


	return 0;
}