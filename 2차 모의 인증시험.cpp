/* ���� 1
���� �� ���� �ݺ��ؼ� �Է� �޵��� �Ͽ���. �Ź� �Է� ���� �� ���� ũ���� ���� ū ������ ���� ���� �� ������ ����ϵ��� �Ͽ���. ���� �� ���� ������ ��� 0�� ��쿡�� ���α׷��� �����Ѵ�.
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

/* ���� 2
�ݾ��� ��Ÿ���� ���� ���� n�� �Է¹ް�, �� �ݾ����� A(900), B(750), C(200)�� �� ���� ��ǰ�� �����ϰ� �ܵ��� ������ �ʴ� ���� ��� �� �Ʒ� ������ �����ϴ� ���� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
- A, B, C �� ��ǰ�� �ּ� �� �� �̻� ���� �Ǿ�� �Ѵ�
- B ��ǰ�� �׻� ¦�� ���� �����Ѵ�
- C ��ǰ�� ������ A ��ǰ�� �������� �۰ų�, B ��ǰ�� �������� �۴�.
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

/* ���� 3
n���� ���� ������ �迭�� �Է� ���� ��, �迭�� �� ��Ұ� �� �� �ݺ��� �Ǿ����� �迭�� �� ����� ������� �ݺ�Ƚ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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

/* ���� 4
ù ��° '*'�� �Էµ� ������ ���� �ҹ��ڸ� %c�� ��� �Է� �޾� �迭 x�� �����ϰ�, �� ��° '*'�� �Էµ� ������ ���� �ҹ��ڸ� %c�� ��� �Է� �޾� �迭 y�� �����Ѵ�.
-��, �� �ܾ ������ ���� �Է� �޴´�. first_word*second_word* 
-'*'�� �ܾ �������� �ʴ´�.
- ����� �� ���� �ܾ� �߿��� �������� ���� ��Ÿ���� �ܾ ����Ͻÿ�.
-�ԷµǴ� ���� ���� �ִ� 100 �̴�. �� �ܾ�� ���� 1�� �̻��̴�.
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

/* ���� 5
������ ��Ÿ���� ������ �Է¹޾� �� �� ������ ���� ������ ���� ���α׷��� �ۼ��Ͻÿ�.
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