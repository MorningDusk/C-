/*[ ���� 1 ] (100��) ���������� ������ ������ ������ �Է¹޴´�. �Է¹��� ������ ������ N����
������ �� �ִ�, �ּ�, ���, �迭 �߽� �� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. - �������� : 100�� �Է� �Ǵ� �����Է�
- ��հ� �߾Ӱ��� �Ҽ��� 2�ڸ����� ���
- N�� Ȧ���� ��� ����Ʈ �߽� �� : (N+1)/2��° ��
- N�� ¦���� ��� ����Ʈ �߽� �� : N/2��°�� 1+N/2��° ���� ���
- �Է��� ���� ��� none�� ���*/

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

/*[ ���� 2 ] (100��) ���������� ������ ������ ������ �Է¹޾� �迭�� �����ϰ�, ����� ���� ��
�� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
- �������� : 100�� �Է� �Ǵ� �����Է�
- ����� ���������� �������� ǥ����
- �� ������� ���� (���)�� ���
- �Է��� ���� ��� none�� ���*/

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

/*[ ���� 3-1 ] (50��) ���������� ������ ������ ������ �Է¹޾� �迭�� �����ϰ�, �Էµ� ������
�� ����� ���� ���� �󵵸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
- �������� : �Էµ� ���� ���� ���� �Ǵ� 100��° ���� �Է�
- �Է� ���� �� ���� (��)�� ���·� ��� ���
- �ѹ� ��µ� ���� ���� ��µ��� ����
- �Է��� ���� ��� none�� ���*/

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

/*[ ���� 3-2 ] (100��) ���������� ������ ������ ������ �Է¹޾� �迭�� �����ϰ�, ���� ���� ��
���� �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. - �������� : �Էµ� ���� ���� ���� �Ǵ� 100��° ���� �Է�
- �Է� ���� �� ���� (��)�� ���·� ��� ���
- �ѹ� ��µ� ���� ���� ��µ��� ����
- 1������ ��, 2������ ���� ������������ �����Ͽ� ���*/

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