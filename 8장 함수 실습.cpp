/* 8장3절[문제 1] 양의 정수 N을 입력 받아, 1부터 N까지의 합을 출력하는 프로그램을 작성하시
오. - add 함수 정의 및 사용
- 인자는 두 개의 정수 x와 y, 반환형은 int - x와 y의 합을 반환
- main 함수
- N값을 입력 받고, add 함수를 반복 호출하여 N까지의 합 계산
- main 함수에서는 더하기 연산자(+) 사용 금지.단, 증감연산자(++ or --)는 사용 가능 */

#include<stdio.h>

int add(int n) {
	int s = 0;
	for (int i = 1; i <= n; i++)
		s += i;
	return s;

}

int main() {
	int n, s;
	scanf("%d", &n);

	s = add(n);
	printf("%d", s);

	return 0;
}

/* 8장3절 [ 문제 2 ] 두 개의 양의 정수 A과 B을 입력 받아, A부터 B까지의 합을 계산하는 프로그
램을 작성하시오. - A ≤ B인 입력만 들어온다고 가정하시오. - sum 함수 정의 및 사용
 - 인자는 하나의 정수 n, 반환형은 int - 1부터 n까지의 합 반환, n(n+1)/2 공식 이용 */

#include<stdio.h>

int add(int a, int b) {
	int s = 0;
	for (int i = a; i <= b; i++)
		s += i;
	return s;

}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d", add(a, b));

	return 0;
}

/* 8장3절 [ 문제 3 ] 하나의 양의 정수 N을 입력 받아 다음 수식의 결과를 출력하는 프로그램을 작
성하시오. 1 + (1+2) + (1+2+3) + (1+2+3+4) + … + (1+2+…+N) - sum 함수 정의 및 사용
 - 문제 2와 동일 */

#include<stdio.h>

int add(int n) {
	int s = 0;
	for (int i = 1; i <= n; i++)
		s += i;
	return s;

}

int main() {
	int n, i, s = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		s += add(i);
	printf("%d", s);

	return 0;
}

/* 8장3절 [ 문제 4 ] 2~9 사이의 정수 N을 입력 받아, 예시와 같이 숫자 N으로 사각형을 출력하는
프로그램을 작성하시오. - print_row1 함수 정의 및 사용
 - 인자 2~9사이의 정수 x, 반환형은 void
 - 하나의 줄에 x를 x번 출력
 - print_row2 함수 정의 및 사용
 - 인자 2~9사이의 정수 x, 반환형은 void
 - 하나의 줄에 x를 2번 출력, 중간에 공백 적절히 삽입 */

#include<stdio.h>

void print_row1(int n) {
	for (int i = 1; i <= n; i++)
		printf("%d", n);
}

void print_row2(int n) {
	printf("%d", n);
	for (int i = 1; i <= n - 2; i++)
		printf(" ");
	printf("%d", n);
	printf("\n");
}

int main() {
	int n, i;
	scanf("%d", &n);
	print_row1(n);
	printf("\n");
	for (i = 2; i < n; i++)
		print_row2(n);
	print_row1(n);

	return 0;
}

/* 8장3절 [ 문제 5 ] 양의 정수를 반복해서 입력 받아(종료 조건 시까지), 예시와 같이 트리 모양을
출력하는 프로그램을 작성하시오. - 종료조건: 0 또는 음수 입력
 - print_triangle 함수
 - 인자는 하나의 정수 x, 반환형은 void
 - 높이가 x인 삼각형 출력 */

#include<stdio.h>

void print_triangle(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j)
			printf("*");
		printf("\n");
	}
}

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		print_triangle(n);
		if (n <= 0)
			break;
	}

	return 0;
}

/* 8장3절 [ 문제 6 ] 하나의 정수 x를 입력 받아 다음 함수의 결과를 출력하는 프로그램을 작성하시
오. f(x) = 2x2 -5x + 1
 - func1 함수 정의 및 사용
 - 인자는 하나의 정수 x, 반환형은 int - f(x)의 결과값 반환
 - main 함수
 - 정수를 입력 받고, func1 함수 호출 및 결과 출력 */

#include<stdio.h>

int func(int n) {
	int f = 2 * n * n - 5 * n + 1;
	return f;
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%d", func(n));

	return 0;
}

/* 8장3절 [ 문제 7 ] 하나의 정수 x와 2차 함수 f(x)의 계수를 나타내는 3개의 정수를 입력 받아, 예
시와 같이 함수 값을 계산하는 프로그램을 작성하시오. - func2 함수 정의 및 사용
 o 인자는 4개의 정수, x, a, b, c, 반환형은 int o ax2 + bx + c 의 결과 값 반환
 - main 함수
 o 정수들을 입력 받고, func2 함수 호출 및 결과 출력 */

#include<stdio.h>

int func(int n, int a, int b, int c) {
	int f;
	f = a * n * n + b * n + c;
	return f;
}

int main() {
	int n, a, b, c;
	scanf("%d\n", &n);
	scanf("%d %d %d", &a, &b, &c);

	printf("%d", func(n, a, b, c));

	return 0;
}

/* 8장3절 [ 문제 8 ] 하나의 정수 x와 2차 함수 f(x)와 g(x)의 계수를 나타내는 6개의 정수를 입력
받아, 합성함수 g(f(x))를 계산하는 프로그램을 작성하시오. 
 - func2 함수 정의 및 사용
 - 문제 7과 동일
 - main 함수
 - 정수들을 입력 받고, func2 함수 호출 및 결과 출력 */

#include<stdio.h>

int func1(int n, int a, int b, int c) {
	int f;
	f = a * n * n + b * n + c;
	return f;
}

int func2(int n, int a, int b, int c) {
	int f;
	f = a * n * n + b * n + c;
	return f;
}

int main() {
	int n, a, b, c, d, e, f;
	scanf("%d\n", &n);
	scanf("%d %d %d\n", &a, &b, &c);
	scanf("%d %d %d", &d, &e, &f);

	printf("%d", func2(func1(n, a, b, c), d, e, f));

	return 0;
}

/* 8장4절 [ 문제 9 ] 정수를 반복해서 입력 받아(종료 조건 시까지), 가장 큰 값과 두 번째로 큰 값
을 출력하는 프로그램을 작성하시오. - 종료조건: 0 입력 (종료조건 전에 최소 2개의 정수는 입력된다고 가정) - 전역변수 max1, max2 사용
 - update_max 함수 정의 및 사용
 - 인자는 하나의 정수 x, 반환형은 void
 - max1, max2, x 중 가장 큰 값은 max1에, 두 번째로 큰 값은 max2에 저장 */

#include<stdio.h>

int main() {

	int n, i, cnt = 0, x[100], max1, max2;
	for (i = 0; i < 100; i++) {
		scanf("%d", &n);
		if (n == 0)
			break;
		x[cnt] = n;
		cnt++;
		if (x[0] < x[1]) {
			max1 = x[1];
			max2 = x[0];
		}
		else {
			max1 = x[0];
			max2 = x[1];
		}
	}

	for (i = 2; i < cnt; i++) {
		if (max1 < x[i]) {
			max2 = max1;
			max1 = x[i];
		}
		else if (x[i] > max2)
			max2 = x[i];
	}
	printf("%d %d", max1, max2);

	return 0;
}

/* 8장4절 [ 문제 10 ] 3~18 사이의 정수 N을 입력 받아, 3개 주사위의 총 합이 N이 되는 모든 경
우를 출력하는 프로그램을 작성하시오. - 전역변수 N 사용: 입력 받은 정수 저장
 - die1 함수 정의 및 사용
 - 인자는 하나의 정수 x, 반환형은 void
 - 첫 번째 주사위 수가 x인 모든 경우 고려
 - 내부에서 die2 함수 호출
 - die2 함수 정의 및 사용
 - 인자는 정수 x와 y, 반환형은 void
 - 첫 번째 주사위 수가 x, 두 번째 주사위의 수가 y인 모든 경우 고려
 - 내부에서 die3 함수 호출
 - die3 함수 정의 및 사용
 - 인자는 정수 x, y, z, 반환형은 void
 - 첫 번째, 두 번째, 세 번째 주사위 수가 x, y, z 인 경우 고려, 즉, 주사위 합이 N이 되면,
 x y z 값 출력
 - main 함수
 - 정수를 입력 받고, die1 함수를 6번 반복 호출 */

#include<stdio.h>

int main() {

	int n, i, j, k;
	scanf("%d", &n);

	for (i = 1; i <= 6; ++i) {
		for (j = 1; j <= 6; ++j) {
			for (k = 1; k <= 6; ++k) {
				if (i + j + k == n)
					printf("%d %d %d\n", i, j, k);
			}
		}
	}

	return 0;
}

/* 8장4절 [ 문제 11 ] (야구 게임) 다음 프로그램을 작성하시오. 1) 정답을 나타내는 0~9 사이의 서로 다른 정수 3개를 입력 받음
 2) 정답을 추측한 0~9 사이의 서로 다른 정수 3개를 입력 받아 스트라이크 개수와 볼의 개수를
 출력 (정답을 맞출 때까지 반복) - 스트라이크 개수: 값도 맞추고 위치도 맞춘 숫자의 개수
 - 볼 개수: 값은 맞췄지만, 위치는 틀린 숫자의 개수
 - 전역 변수 및 함수
 - 정답은 전역변수에 저장
 - count_strike 함수 정의 및 사용
 - 인자는 추측 값을 나타내는 세 개의 정수, 반환형은 int - 정답과 추측을 비교하여 strike 개수를 반환
 - count_ball 함수 정의 및 사용
 - 인자는 추측 값을 나타내는 세 개의 정수, 반환형은 int - 정답과 추측을 비교하여 ball 개수를 반환
 - main 함수
 - 각각의 추측에 대해 위 함수를 이용하여 strike와 ball의 개수를 얻고, 결과값 출력 */

#include<stdio.h>

int main() {

	int a, b, c, x, y, z, S, B;
	scanf("%d %d %d\n", &a, &b, &c);

	while (1) {
		scanf("%d %d %d", &x, &y, &z);
		S = 0;
		B = 0;

		if (x == a)
			S++;
		else if (x == b || x == c)
			B++;

		if (y == b)
			S++;
		else if (y == a || y == c)
			B++;

		if (z == c)
			S++;
		else if (z == a || z == b)
			B++;

		printf("%dS%dB\n", S, B);

		if (x == a && y == b && z == c) {
			break;
		}
	}

	return 0;
}

/* 8장4절 [ 문제 13 ] 하나의 양의 정수 N을 입력 받아, 1부터 N까지의 정수에서 숫자 3이 총 몇
번 나타나는지를 출력하는 프로그램 작성하시오. - N=33 일 때, 3, 13, 23, 30, 31, 32, 33, 총 7개의 수에서 8개의 3이 나타난다. (∵ 숫자 33에는 3이 두 개 있으므로)
 - count_3 함수 정의 및 사용
 - 인자는 하나의 정수 x, 반환형은 int - 하나의 정수 x에 숫자 3이 나타나는 횟수 반환 */

#include<stdio.h>

int count3(int n) {
	int m, cnt = 0;
	while (n != 0) {
		m = n % 10;
		n /= 10;
		if (m == 3)
			cnt++;
	}
	return cnt;
}

int main() {

	int n, i, cnt = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		cnt += count3(i);
	printf("%d", cnt);

	return 0;
}

/* 8장4절 [ 문제 14 ] 두 양의 정수 N과 M을 입력 받아, N보다 큰 소수를 작은 것부터 차례로 M
개 출력하는 프로그램을 작성하시오. - is_prime 함수
 - 인자는 하나의 정수 x, 반환형은 int - 정수 x가 소수이면 1 반환, 소수가 아니면 0 반환
 - next_prime 함수
 - 인자는 하나의 정수 x, 반환형은 int - 정수 x 보다 크면서 가장 작은 소수를 반환 (is_prime 함수 사용) - main 함수
 - next_prime 함수를 반복 호출하여, M개의 소수를 출력 */

#include<stdio.h>

int is_prime(int n) {
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int next_prime(int n) {
	for (int i = n + 1;; i++) {
		if (is_prime(i))
			return i;
	}
}

int main() {

	int n, cnt, i;
	scanf("%d %d", &n, &cnt);

	while (cnt > 0) {
		printf(" %d", next_prime(n));
		n = next_prime(n);
		cnt--;
	}

	return 0;
}