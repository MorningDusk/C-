/*
[ ���� 1 ] (100��) �ڿ��� Y�� �Է¹޾� ���� Y, ���� Y * Y�� ũ�⸦ ������ �׷����� �׸��� ��
�α׷��� �ۼ��Ͻÿ�. 
- �׸����� �ϴ� �׷��� : x = y^2
- �׷��� �� ���� ��ġ�� ������ ���� ���ǵȴ�. 
- x�� 1�� ��� y�� 1
- x�� 4�� ������ y�� 2
- x�� n^2�� ������ y�� n
*/

#include<stdio.h>

int main() {

	int input, inv, x, y;
	scanf("%d", &input);
	for (y = 0; y < input; y++) {
		inv = input - y;
		for (x = 0; x < (inv - 1) * (inv - 1); x++)
			printf(".");
		for (x = (inv - 1) * (inv - 1); x < inv*inv; x++)
			printf("*");
		for (x = (input - y) * (input - y); x < input * input; x++)
			printf(".");
		printf("\n");
	}

	return 0;
}

/*
[ ���� 2 ] (100��) �ڿ��� N�� �Է��Ͽ� �ڿ����� �ƴ� ���� �Է¹��� ������ N��°�� �Ǻ���ġ
���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
- �Ǻ���ġ �� a(n+2) = a(n+1) + a(n)
- a(1) = a(2) = 1
- �������� : 0 �Ǵ� �����Է�
*/

#include <stdio.h>

int main() {

	while (1) {
		int a0 = 0;
		int a1 = 0;
		int a2 = 1;
		int input;
		int loop;
		scanf("%d", &input);
		if (input > 0) {
			for (loop = 0; loop < input; loop++) {
				a0 = a1;
				a1 = a2;
				a2 = a0 + a1;
			}
			printf("%d ", a1);
		}
		else {
			printf("end");
			break;
		}
	}
	return 0;
}

/*
[ ���� 3-1 ] (50��) �������Ǳ��� �ڿ��� N�� �Է� �޾�, N��°�� �Ҽ� M�� ���Ͽ� ����ϴ� ��
�α׷��� �ۼ��Ͻÿ�. 
- �������� : 0 �Ǵ� �����Է�
- N��° �Ҽ� M : 1��°�� 1�� ��ȯ, ���� ������� �Ҽ� ��ȯ
*/

#include <stdio.h>

int main() {

	int input;
	int index;
	int div;
	int prime = 1;
	while (1) {
		scanf("%d", &input);
		if (input <= 0) {
			break;
		}
		prime = 1;
		for (index = 1; index < input; index++) {
			while (1) {
				++prime;
				for (div = 2; div < prime; div++) {
					if (prime % div == 0)
						break;
					if (prime == div)
						break;
					printf("%d ", prime);
					printf("end");
				}
			}
		}
	}
	
	return 0;
}

/*
[ ���� 3-2 ] (100��) �Է¹��� ������ ��ȣȭ�� ���� �������Ǳ��� �ڿ��� N�� �ݺ��ؼ� �Է� ��
����, �̷��� ��ȣȭ �������� N��°�� �Ҽ� M�� ���ȴ�. ��ȣȭ�ڵ�� �Է¹��� �ڿ��� N��
������ ���� ũ���� ��ȣȭ�ڵ� �����ͷ� �����Ǹ�, ù ��° ��ȣȭ�ڵ� �����ʹ� �Ҽ� M1�� ��
��, n�� 2���� ū ����� n��° ��ȣȭ�ڵ� �����ʹ� �Ҽ� M(n)�� �Ҽ� M(n-1)�� ������ ��Ÿ����. ��
�¹��� �ڿ����� ��ȣȭ�ϱ� ���� ������ �Ʒ��� ���� �� ��ȣȭ�ڵ� �����͸� ����ϴ� ���α�
���� �ۼ��Ͻÿ�. 
- �������� : 0 �Ǵ� �����Է�
- N��° �Ҽ� M : 1��°�� 1�� ��ȯ, ���� ������� �Ҽ� ��ȯ
- ��ȣȭ�ڵ� ������ ����
- data(1) = M(1)^2 (ù ��° ������)
- data(n) = M(n) * M(n-1) (n��° ������)
- �Է��� ���� ��� none�� ���
*/

#include <stdio.h>

int main() {

	int index;
	int input;
	int div;
	int prime_prev;
	int flag = 0;
	int prime;
	while (1) {
		scanf("%d", &input);
		if (input <= 0)
			break;
		prime = 1;
		for (index = 1; index < input; index++) {
			while (1) {
				++prime;
				for (div = 2; div < prime; div++) {
					if (prime % div == 0)
						break;
				}
				if (prime == div)
					break;
			}
		}
		if (flag == 1)
			printf("%d ", prime * prime_prev);
		else
			printf("%d ", prime * prime);
		flag = 1;
		prime_prev = prime;
	}
	if (flag == 1)
		printf("end");
	else
		printf("none");

	return 0;
}