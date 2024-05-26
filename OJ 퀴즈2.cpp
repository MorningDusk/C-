/*[ 문제 1 ] (100점) 종료조건을 만족할 때까지 정수를 입력받는다. 입력받은 정수의 개수를 N으로
정의할 때 최대, 최소, 평균, 배열 중심 값 순서대로 출력하는 프로그램을 작성하시오. - 종료조건 : 100개 입력 또는 음수입력
- 평균과 중앙값은 소수점 2자리까지 출력
- N이 홀수일 경우 리스트 중심 값 : (N+1)/2번째 값
- N이 짝수일 경우 리스트 중심 값 : N/2번째와 1+N/2번째 값의 평균
- 입력이 없을 경우 none을 출력*/

#include<stdio.h>

int main() {
	
	int i, cnt = 0, min, max, x[100], n, sum, mean, median;
	for (i = 0; i < 100; i++) {
		scanf("%d", &n);
		if (n < 0)
			break;
		x[cnt] = n;
		cnt++;
	}

	if (cnt > 0) {
		min = x[0];
		max = x[0];
		sum = x[0];
		median = x[0] + x[0];
		for (i = 1; i < cnt; i++) {
			sum += x[i];
			if (min > x[i])
				min = x[i];
			if (max < x[i])
				max = x[i];
			median = x[i / 2] + x[(i + 1) / 2];
		}
		printf("%d %d %.2f %.2f", max, min, (float)(sum) / cnt, median / 2.0);
	}
	else
		printf("none");

	return 0;
}

/*[ 문제 2 ] (100점) 종료조건을 만족할 때까지 정수를 입력받아 배열에 저장하고, 저장된 값과 값
의 등수를 출력하는 프로그램을 작성하시오. 
- 종료조건 : 100개 입력 또는 음수입력
- 등수는 내림차순을 기준으로 표현됨
- 값 순서대로 ”값 (등수)“ 출력
- 입력이 없을 경우 none을 출력*/

#include<stdio.h>

int main() {

	int i, j, cnt = 0, min, max, x[100], n, rank[100];
	for (i = 0; i < 100; i++) {
		scanf("%d", &n);
		if (n < 0)
			break;
		x[cnt] = n;
		++cnt;
	}
	if (cnt > 0) {
		for (i = 0; i < cnt; i++) {
			rank[i] = 1;
			for (j = 0; j < cnt; j++)
				if (x[j] > x[i])
					++rank[i];
			printf("%d (%d)\n", x[i], rank[i]);
		}
		printf("end");
	}
	else
		printf("none");

	return 0;
}

/*[ 문제 3-1 ] (50점) 종료조건을 만족할 때까지 정수를 입력받아 배열에 저장하고, 입력된 순서대
로 저장된 값과 값의 빈도를 출력하는 프로그램을 작성하시오. 
- 종료조건 : 입력된 색인 값이 음수 또는 100번째 색인 입력
- 입력 종료 시 ”값 (빈도)“ 형태로 결과 출력
- 한번 출력된 값은 이후 출력되지 않음
- 입력이 없을 경우 none을 출력*/

#include<stdio.h>

int main() {

	int x[100], freq[100], i, j, n, cnt = 0;
	while (cnt < 100) {
		scanf("%d", &n);
		if (n < 0)
			break;
		x[cnt] = n;
		cnt++;
	}
	if (cnt > 0) {
		for (i = 0; i < cnt; i++) {
			freq[i] = 0;
			for (j = 0; j < cnt; j++) {
				if (x[i] == x[j]) {
					++freq[i];
					if (i != j)
						x[j] = -1;
				}
			}
			if (x[i] != -1)
				printf("%d (%d)\n", x[i], freq[i]);
		}
		printf("end");
	}
	else
		printf("none");

	return 0;
}

/*[ 문제 3-2 ] (100점) 종료조건을 만족할 때까지 정수를 입력받아 배열에 저장하고, 값과 값의 빈
도를 정렬하여 출력하는 프로그램을 작성하시오. - 종료조건 : 입력된 색인 값이 음수 또는 100번째 색인 입력
- 입력 종료 시 ”값 (빈도)“ 형태로 결과 출력
- 한번 출력된 값은 이후 출력되지 않음
- 1순위로 빈도, 2순위로 값을 내림차순으로 정렬하여 출력*/

#include<stdio.h>

int main() {

	int x[100], freq[100], i, j, n, cnt = 0, tmp;
	while (cnt < 100) {
		scanf("%d", &n);
		if (n < 0)
			break;
		x[cnt] = n;
		cnt++;
	}
	if (cnt > 0) {
		for (i = 0; i < cnt; i++) {
			freq[i] = 0;
			for (j = 0; j < cnt; j++) {
				if (x[i] == x[j]) {
					++freq[i];
					if (i != j)
						x[j] = -1;
				}
			}
		}
		for (i = 0; i < cnt - 1; i++) {
			for (j = 1; j < cnt - i; j++) {
				if (x[j - 1] > x[j]) {
					tmp = freq[j - 1];
					freq[j - 1] = freq[j];
					freq[j] = tmp;
					tmp = x[j - 1];
					x[j - 1] = x[j];
					x[j] = tmp;
				}
				if (freq[j - 1] > freq[j]) {
					tmp = freq[j - 1];
					freq[j - 1] = freq[j];
					freq[j] = tmp;
					tmp = x[j - 1];
					x[j - 1] = x[j];
					x[j] = tmp;
				}
			}
		}
		for (i = 0; i < cnt; i++)
			if (x[i] != -1)
				printf("%d (%d)\n", x[i], freq[i]);
		printf("end");
	}
	else
		printf("none");

	return 0;
}