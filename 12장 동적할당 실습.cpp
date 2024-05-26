/*
2절 [ 문제 1 ] N개의 정수를 입력 받아 동적 메모리 할당을 사용하여 배열에 저장한 후, 저장된
배열 요소들의 합을 출력하는 프로그램을 작성하시오.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int n, i, sum = 0, *p = NULL;
	scanf("%d", &n);
	getchar();

	p = (int *)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		sum += p[i];
	}
	printf("%d", sum);

	return 0;
}

/*
2절 [ 문제 2 ] N개의 실수(float형)를 입력 받아 동적 메모리 할당을 사용하여 배열에 저장한 후, 저장된 배열 요소들 중 가장 큰 값을 찾아 출력하는 프로그램을 작성하시오. 출력 시, 소수점 둘
째자리까지 출력하시오.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int n, i;
	float *p = NULL, max, tmp;
	scanf("%d", &n);
	getchar();

	p = (float *)malloc(n * sizeof(float));

	for (i = 0; i < n; i++) {
		scanf("%f", &p[i]);
	}
	max = p[0];
	for (i = 1; i < n; i++) {
		if (max < p[i]) {
			tmp = p[i];
			p[i] = max;
			max = tmp;
		}
	}
	printf("%.2f", max);

	return 0;
}

/*
4절 [ 문제 3 ] 다음과 같은 기능을 하는 학번관리 프로그램을 작성하시오. - 등록할 학번 수 N을 입력받고, N개의 학번을 동적할당을 이용해 입력 (int형 사용)
 - 삭제할 학번 개수 D(D<N)를 입력받고, D만큼 메모리 크기 조정 후 출력
 - 마지막에 입력한 학번부터 D 개를 삭제한다.
 - 프로그램 종료 시 할당한 메모리 해제
 - 힌트: malloc 함수 사용 후, realloc 함수를 사용하시오.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int n, d, i, *p = NULL;
	scanf("%d", &n);
	getchar();
	p = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	scanf("%d", &d);

	p = (int *)realloc(p, n * sizeof(int) - d * sizeof(int));
	for (i = 0; i < n - d; i++)
		printf("%d\n", p[i]);

	free(p);

	return 0;
}

/*
3절 [ 문제 4 ] 열과 행을 입력받아 2차원 문자열 배열을 동적할당하고, 2차원 배열 내에 알파벳
을 순서대로 채워 출력하는 프로그램을 작성하시오. - 알파벳은 소문자부터 출력
 - 소문자 z 다음문자는 대문자 A, 대문자 Z 다음문자는 소문자 a
 - 프로그램 종료 시 할당한 메모리 해제
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int m, n, i, j, cnt = 0;
	char **pch;

	scanf("%d %d", &m, &n);

	pch = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
		pch[i] = (char *)malloc(m * sizeof(char));

	pch[0][0] = 'a';

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			pch[i][j] = pch[0][0] + cnt;
			cnt++;
			if (pch[i][j] == 'z')
				cnt = -32;
			else if (pch[i][j] == 'Z')
				cnt = 0;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%c ", pch[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < n; i++)
		free(pch[i]);
	free(pch);

	return 0;
}

/*
2절 [ 문제 5 ] 사용자로부터 정수 N을 입력받고, 길이 N의 문자열을 동적할당을 이용해 입력 받
으시오. 그 후, 사용자로부터 검색할 문자 2개를 입력받고 각 문자가 입력된 문자열에 몇 번 포함
되어있는지 출력하는 프로그램을 작성하시오.
 - N은 3 이상
 - 프로그램 종료 시 할당한 메모리 해제
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int n, cnt1 = 0, cnt2 = 0, i;
	char *pch = NULL;
	char ch1, ch2;

	scanf("%d", &n);
	getchar();
	pch = (char *)malloc(n * sizeof(char));
	for (i = 0; i < n; i++)
		scanf("%c", &pch[i]);
	getchar();
	scanf("%c %c", &ch1, &ch2);
	for (i = 0; i < n; i++) {
		if (pch[i] == ch1)
			cnt1++;
		if (pch[i] == ch2)
			cnt2++;
	}
	printf("%d %d", cnt1, cnt2);

	free(pch);

	return 0;
}

/*
3절 [ 문제 6 ] N명의 학생에 대한 정보(이름, 국어 성적, 영어 성적, 수학 성적)를 동적 메모리 할
당을 사용하여 입력 받아, 각 학생의 평균 성적과 GREAT 혹은 BAD를 출력하는 프로그램을 작성
하시오.
 - 평균은 소수 첫째 자리까지 출력
 - GREAT 혹은 BAD는 다음 기준을 적용하여 출력:
 ◦ 국어, 영어, 수학 성적 중 어느 한 과목이라도 90 이상일 경우 GREAT 출력
 ◦ 국어, 영어, 수학 성적 중 어느 한 과목이라도 70 미만일 경우 BAD 출력
 ◦ GREAT 여부가 BAD 여부보다 먼저 출력되며, GREAT과 BAD 모두 출력될 경우 공백으로
구분됨
 - 다음 멤버를 가지는 student 구조체를 정의하여 사용하시오. ◦ 이름: 길이가 1 이상 7 이하인 공백을 포함하지 않는 문자열
 ◦ 국어 성적, 영어 성적, 수학 성적: 각각 정수형 변수. 성적은 0 이상 100 이하인 정수
 ◦ 평균 성적: 실수형 변수
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char name[8];
	int k, e, m;
	float mean;
}grade;

int main() {

	int n, i;
	grade *p = NULL;
	scanf("%d", &n);
	getchar();
	p = (grade *)malloc(n * sizeof(grade));
	for (i = 0; i < n; i++)
		scanf("%s %d %d %d", p[i].name, &p[i].k, &p[i].e, &p[i].m);

	for (i = 0; i < n; i++)
		p[i].mean = (float)(p[i].k + p[i].e + p[i].m) / 3;

	for (i = 0; i < n; i++) {
		printf("%s %.1f ", p[i].name, p[i].mean);
		if (p[i].k >= 90 || p[i].e >= 90 || p[i].m >= 90)
			printf("GREAT ");
		if (p[i].k < 70 || p[i].e < 70 || p[i].m < 70)
			printf("BAD");
		printf("\n");
	}

	return 0;
}

/*
3절 [ 문제 7 ] 사용자로부터 정수 N을 입력받고, N개의 정수를 동적할당을 이용해 입력 받으시
오.
 - 그 후, 첫 번째 원소와 두 번째 원소를 비교하여 첫 번째 원소가 두 번째 원소보다 크면 서
로 교환하여 저장 하시오.
 - 이 교환 연산(i번째 원소와 i+1번째 원소의 비교 후, 앞의 원소가 크면 교환)을 첫 번째 원소
부터 마지막 바로 전 원소까지 반복 하시오.
 - (동적할당된) 배열에 저장된 순서대로 정수를 출력 하시오.
 - 참고: 제일 큰 수가 맨 뒤로 이동한다.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, i, tmp;
	int *p = NULL;
	scanf("%d", &n);
	getchar();
	p = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);

	for (i = 0; i < n - 1; i++)
		if (p[i] > p[i + 1]) {
			tmp = p[i + 1];
			p[i + 1] = p[i];
			p[i] = tmp;
		}

	for (i = 0; i < n; i++)
		printf("%d\n", p[i]);

	return 0;
}

/*
3절 [ 문제 8 ] 사용자로부터 정수 N을 입력받고, N개의 문자를 동적할당을 이용해 입력 받으시
오. 문자 중에 “cat"가 몇 번 있는지 횟수를 출력 하시오.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, i, cnt = 0;
	char *p = NULL;
	scanf("%d", &n);
	getchar();
	p = (char *)malloc(n * sizeof(char));
	for (i = 0; i < n; i++)
		scanf("%c", &p[i]);

	for (i = 0; i < n; i++)
		if (p[i] == 'c' && p[i + 1] == 'a' && p[i + 2] == 't')
			cnt++;

	printf("%d", cnt);

	return 0;
}

/*
3절 [ 문제 9 ] 사용자로부터 정수 N을 입력받고, N 줄의 공백을 포함하는 문자열을 동적할당을
이용해 입력 받으시오. 그 후, 이 중 가장 길이가 작은 공백을 포함하는 문자열을 출력하는 프로
그램을 작성하시오.
 - 문자열의 길이는 최대 100 이다.
 - 문자열 처리 표준 함수를 사용해도 됨
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int n, i, len, min = 100;
	char minstr[100];
	char **p = NULL;
	scanf("%d", &n);
	getchar();
	p = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
		p[i] = (char *)malloc(100 * sizeof(char));

	for (i = 0; i < n; i++) {
		gets(p[i]);
		len = strlen(p[i]);
		if (len < min) {
			min = len;
			strcpy(minstr, p[i]);
		}
	}

	printf("%s", minstr);

	return 0;
}

/*
3절 [ 문제 10 ] 사용자로부터 정수 N을 입력받고, N 줄의 공백을 포함하는 문자열을 동적할당을
이용해 입력 받으시오. 그 후, 이 중 가장 길이가 긴 문자열부터 가장 길이가 작은 문자열까지 정
렬하고, 순서대로 출력하는 프로그램을 작성하시오.
 - 문자열의 길이는 최대 100 이다.
 - 문자열 처리 표준 함수를 사용해도 된다.
 - 같은 길이의 문자열은 없다고 가정한다.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int n, i, j;
	char *tmp;
	char **p = NULL;
	scanf("%d", &n);
	getchar();
	p = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
		p[i] = (char *)malloc(100 * sizeof(char));

	for (i = 0; i < n; i++) {
		gets(p[i]);
	}

	for (i = 0; i < n - 1; i++)
		for (j = i; j < n; j++)
			if (strlen(p[i]) < strlen(p[j])) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}

	for (i = 0; i < n; i++)
		printf("%s\n", p[i]);

	return 0;
}

/*
3절 [ 문제 11 ] 사용자로부터 -1을 입력받기 전까지 계속 정수를 입력받는다. 초기 배열의 크기
는 5로 설정하되, 사용자가 계속 입력하면 길이를 3씩 증가시킨다. 길이를 증가시킬 때, 새로운 배
열을 하나 만들어서 증가시킨다. 사용자가 -1을 입력하면 배열의 값을 모두 출력한다.
 - 동적할당(malloc함수)을 이용한다. realloc 쓰지 말 것.
 - 최대 증가 시킬 수 있는 배열의 크기는 20으로 제한한다.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int n = 5, i, flag = 0;
	int *p1 = NULL, *p2 = NULL;
	p1 = (int *)malloc(5 * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", &p1[i]);
		if (p1[i] == -1) {
			flag = 1;
			break;
		}
	}

	if (flag == 1)
		for (i = 0; i < 5; i++) {
			printf(" %d", p1[i]);
			if (p1[i] == -1)
				break;
		}
	else if (flag == 0) {
		for (i = 0; i < 5; i++)
			printf(" %d", p1[i]);
		while (flag == 0) {
			p2 = (int *)malloc(3 * sizeof(int));
			for (i = 0; i < 3; i++) {
				scanf("%d", &p2[i]);
				if (p2[i] == -1)
					flag = 1;
			}
			for (i = 0; i < 3; i++) {
				printf(" %d", p2[i]);
				if (p2[i] == -1)
					break;
			}
			free(p2);
		}
	}

	return 0;
}

/*
3절 [ 문제 12 ] 사용자로부터 정수 한 개를 입력받는다. 이것을 N 이라고 하자. N은 홀수라고 가
정한다. 정수 N개를 저장할 수 있는 메모리를 동적 할당한 후에, 이 메모리에 0부터 N-1 까지 정
수를 저장한다 (0 1 2 ... N-1). 이 배열의 중간에 위치한 값을 제외한 나머지 값들을 순서대로, M
(N-1)개 새로 동적할당된 메모리에 대입한 후 출력한다.
 - 예시 1에서 N이 5이므로 0에서 4까지의 정수, 0 1 2 3 4 를 저장한다. 배열의 중간에 위치
한 값을 제외하면 0 1 3 4가 된다. 
 - 크기 N 동적할당 메모리와, 크기 M 동적할당 메모리를 아용한다. M=N-1
 - N의 크기는 최대 20 이다.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int m, n, i;
	int *p = NULL;
	scanf("%d", &n);
	p = (int *)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		if (i >= (n - 1) / 2)
			p[i] = i + 1;
		else
			p[i] = i;
	}
	m = n - 1;
	p = (int *)realloc(p, (n - 1) * sizeof(int));

	for (i = 0; i < m; i++) {
		printf(" %d", p[i]);
	}
	free(p);

	return 0;
}

/*
3절 [ 문제 13 ] 정수 N을 입력받고 N개의 문자열을 입력받아 사전 순으로 출력하는 프로그램을
작성하시오.
 - malloc( ) 함수를 이용한다.
 - 배열을 미리 선언하지 않고 실행 중에 동적할당으로 메모리를 필요한 만큼만 만든다.
 - 문자열의 길이는 최대 100 이다.
 - 소문자만 입력된다고 가정한다.
 - 표준 문자열 함수를 사용해도 된다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int n, i, j;
	char *tmp;
	char **pch;
	scanf("%d", &n);
	getchar();
	pch = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
		pch[i] = (char *)malloc(100 * sizeof(char *));

	for (i = 0; i < n; i++)
		scanf("%s", pch[i]);

	for (i = 0; i < n - 1; i++)
		for (j = i; j < n; j++)
			if (strcmp(pch[i], pch[j]) > 0) {
				tmp = pch[i];
				pch[i] = pch[j];
				pch[j] = tmp;
			}

	for (i = 0; i < n; i++)
		printf("%s\n", pch[i]);

	return 0;
}