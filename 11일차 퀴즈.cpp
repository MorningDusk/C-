/*
[ 문제 1 ] (100점) N개 정수를 입력받는다. 모든 경우의 두 수 합중에서 최대값과 최소값을 출력
하시오.
*/

#include <stdio.h>

int main() {

	int i, j, max, min, x[100], n;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	max = x[0] + x[1];
	min = x[0] + x[1];

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (x[i] + x[j] > max && x[i] != x[j])
				max = x[i] + x[j];
			if (x[i] + x[j] < min && x[i] != x[j])
				min = x[i] + x[j];
		}
	}
	printf("%d %d", max, min);

	return 0;
}

/*
[ 문제 2 ] (100점) N개 정수를 입력받는다. 양쪽에서 두개씩 차례대로 출력하시오. (풀이 다양함)
N≦50
*/

#include<stdio.h>

int main() {

	int n, x[50], i, j, cnt = 0;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (i = 0, j = n - 1; i < n, j >= 0; i += 2, j -= 2) {
		printf(" %d", x[i]);
		cnt++;
		if (cnt == n)
			break;
		printf(" %d", x[i + 1]);
		cnt++;
		if (cnt == n)
			break;
		printf(" %d", x[j]);
		cnt++;
		if (cnt == n)
			break;
		printf(" %d", x[j - 1]);
		cnt++;
		if (cnt == n)
			break;
	}

	return 0;
}