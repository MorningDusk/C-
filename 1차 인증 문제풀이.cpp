#include<stdio.h> //1차 인증 2-2

int main() {

	char c, first = 'z', second = 'z';
	while (1) {
		scanf("%c", &c);
		if (c < 'a' || c > 'z')
			break;
		if (c < first) {
			second = first;
			first = c;
		}
		else if (c < second)
			second = c;
	}
	printf("%c%c", first, second);

	return 0;
}

#include<stdio.h> //1차 인증 3-2

int main() {

	int n, m, i, cnt, max, min;

	for (i = 0;; i++) {
		scanf("%d", &n);
		if (n == 0)
			break;

		m = n;
		cnt = 0;
		while (n > 0) {
			if (n % 10 == 3)
				cnt++;
			m = m * 10 + n % 10;
			n /= 10;
		}
		cnt *= 2;
		printf("%d %d ", m, cnt);

		if (i == 0) {
			max = m;
			min = m;
		}

		if (max < m)
			max = m;
		if (min > m)
			min = m;
	}
	printf("\n%d %d", min, max);

	return 0;
}

#include<stdio.h> //1차 인증 4-2

int main() {

	int n, m, t, l, i, j;
	int n_div, divi, flag, cnt, max = 0, max_i = 1;

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d ", &n, &t);

		n_div = 0;
		flag = 0;
		cnt = 0;

		for (j = 1; j <= n; j++) {
			if (n % j == 0)
				n_div++;
		}
		scanf("%d", &l);
		while (l > 0) {
			divi = 0;
			for (j = 1; j <= l; j++) {
				if (l % j == 0)
					divi++;
			}
			if (divi == n_div) {
				printf("%d ", l);
				cnt++;
			}
			else if (divi % t == 0 && flag == 0) {
				flag = 1;
				printf("%d ", l);
				cnt++;
			}
			scanf("%d", &l);
		}
		if (cnt == 0)
			printf("none");
		if (cnt > max) {
			max = cnt;
			max_i = i + 1;
		}
		printf("\n");
	}
	printf("%d %d", max_i, max);


	return 0;
}

#include<stdio.h> //1차 인증 5-3

int main() {

	int n, i, j, flag = 0, cnt;
	scanf("%d", &n);
	while (n > 0) {
		cnt = 0;
		for (i = 2; i < n; i++) {
			if (n % i == 0) cnt++;
		}
		if (cnt == 0) {
			printf("%d ", n);
			for (i = n + 1; ; i++) {
				cnt = 0;
				for (j = 2; j < i; j++) {
					if (i % j == 0)
						cnt++;
				}
				if (cnt == 0) {
					printf("%d\n", i);
					break;
				}
			}
			flag = 1;
		}
		scanf("%d", &n);
	}
	if (flag == 0) printf("none\n");

	return 0;
}