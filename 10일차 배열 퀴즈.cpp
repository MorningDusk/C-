/*
[ 문제 1-1 ] (50점) 정수 N 입력받고, N개의 정수 읽어 들여, 입력된 정수들을 앞에서 부터 3개씩
묶어서 합을 출력하는 프로그램을 작성하시오. 마지막에 3개 이하이면 남은 정수들의 합을 계산
한다. Hint: 배열 안 써도 됨
*/

#include <stdio.h>

int main() {

	int n, m, i, sum = 0, cnt = 0;
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &n);
		sum += n;
		cnt++;
		if (cnt % 3 == 0 || i == m - 1) {
			printf("%d ", sum);
			sum = 0;
		}
	}

	return 0;
}

/*
[ 문제 1-2 ] (100점) 정수 N 입력받고, N개의 정수 읽어 들여, 입력된 정수들을 앞에서 부터 3개
씩 묶어서 합을 출력한다. 정수 1개만 남을 때까지 이 과정을 반복한다. (출력 예시2를 보시오)
각 줄에서 마지막에 3개 이하이면 남은 정수들의 합을 계산한다. 
Hint: 배열 x에 입력된 정수 N개를 저장 후, 3개씩 묶어서 합을 구한 후, 다시 배열 x에 저장한다. N개 정수가 M개 정수로 개수가 줄어든다. 이 과정을 M=1 이 될 때까지 반복한다.
*/

#include <stdio.h>

int main() {
	int n, m, i, j, sum, cnt, x[100];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);

	while (n > 1) {
		cnt = 0;
		sum = 0;
		j = 0;
		for (i = 0; i < n; i++) {
			sum += x[i];
			cnt++;
			if (cnt % 3 == 0 || i == n - 1) {
				x[j] = sum;
				j++;
				printf("%d ", sum);
				sum = 0;
			}
			m = j;
		}
		printf("\n");
		n = m;
	}
	
	return 0;
}