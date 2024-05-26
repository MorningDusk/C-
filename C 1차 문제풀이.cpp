/*
[ 문제 1 ] (100점) 자연수 Y을 입력받아 세로 Y, 가로 Y * Y의 크기를 가지는 그래프를 그리는 프
로그램을 작성하시오. 
- 그리고자 하는 그래프 : x = y^2
- 그래프 내 별의 위치는 다음과 같이 정의된다. 
- x가 1일 경우 y는 1
- x가 4일 때까지 y는 2
- x가 n^2일 때까지 y는 n
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
[ 문제 2 ] (100점) 자연수 N을 입력하여 자연수가 아닌 값을 입력받을 때까지 N번째의 피보나치
수를 출력하는 프로그램을 작성하시오. 
- 피보나치 수 a(n+2) = a(n+1) + a(n)
- a(1) = a(2) = 1
- 종료조건 : 0 또는 음수입력
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
[ 문제 3-1 ] (50점) 종료조건까지 자연수 N을 입력 받아, N번째의 소수 M을 구하여 출력하는 프
로그램을 작성하시오. 
- 종료조건 : 0 또는 음수입력
- N번째 소수 M : 1번째는 1을 반환, 이후 순서대로 소수 반환
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
[ 문제 3-2 ] (100점) 입력받은 정보의 암호화를 위해 종료조건까지 자연수 N을 반복해서 입력 받
으며, 이러한 암호화 과정에서 N번째의 소수 M이 사용된다. 암호화코드는 입력받은 자연수 N의
개수와 같은 크기의 암호화코드 데이터로 구성되며, 첫 번째 암호화코드 데이터는 소수 M1의 제
곱, n이 2보다 큰 경우의 n번째 암호화코드 데이터는 소수 M(n)과 소수 M(n-1)의 곱으로 나타낸다. 입
력받은 자연수를 암호화하기 위한 수식이 아래와 같을 때 암호화코드 데이터를 출력하는 프로그
램을 작성하시오. 
- 종료조건 : 0 또는 음수입력
- N번째 소수 M : 1번째는 1을 반환, 이후 순서대로 소수 반환
- 암호화코드 데이터 수식
- data(1) = M(1)^2 (첫 번째 데이터)
- data(n) = M(n) * M(n-1) (n번째 데이터)
- 입력이 없을 경우 none을 출력
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