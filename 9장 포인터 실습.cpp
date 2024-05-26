/*
[ 문제 1][레벨 0] 다음과 같은 순서에 따라 프로그램을 작성하시오.
 1) 포인터 변수 px를 이용하여 사용자로부터 값을 입력받아 x에 저장 (즉, scanf 함수의 매개변
수로 포인터 변수 px 이용, 변수 x 사용 금지). 변수 y, z도 동일한 방법으로 값을 입력 받아
저장한다.
2) px, py, pz에 있는 주소들을 py, pz, px로 이동시킨다.
3) 순서가 바뀐 최종 값을 포인터를 이용하여 출력하시오.
4) 아래 코드를 사용하시오.
*/

#include <stdio.h>

int main() {

	int x, y, z;
	int *px = &x, *py = &y, *pz = &z, *tmp = NULL;
	scanf("%d %d %d", px, py, pz);

	tmp = px;
	px = pz;
	pz = py;
	py = tmp;

	printf("%d %d %d", *px, *py, *pz);
	
	return 0;
}

/*
[ 문제 2 ][레벨 1] 문자 #을 포함한 임의 개수(1 이상 20 이하)의 문자를 입력 받은 후, 첫 번째
# 이전까지의 문자들을 포인터를 사용하여 역순으로 출력하시오. (#이 두 개 있는 경우도 있음)
▶ 배열 표기 [ ] 는 사용 금지 (포인터 표기 사용) <-- 추가된 조건
즉, char ch[20]; 배열 선언하고, 이 다음부터 배열 표기 [ ] 사용 금지
*/

#include<stdio.h>

int main() {

	char ch[20];
	char *pch;
	int n = 0;

	for (pch = ch; pch < ch + 20; pch++) {
		scanf("%c", pch);
		if (*pch == '#')
			break;
		n++;
	}

	for (pch = ch + n - 1; pch >= ch; pch--) {
		printf("%c", *pch);
	}

	return 0;
}

/*
[ 문제 3 ][레벨 0] N개의 정수를 입력 받은 후 (N ≤ 50), 0 이 나오기 전까지의 정수 개수를 출
력하는 프로그램을 작성하시오. - 0 은 오직 한 번만 나타난다.
▶ 배열 선언 이후, 배열 표기 [ ] 는 사용 금지 (포인터 표기 사용)
▶ 반복문으로 배열 훑어볼 시, 주소를 이용하여 반복문 구현 (강의자료 2주차 2강, 9쪽) <-- 추
가 조건
*/

#include<stdio.h>

int main() {

	int ar[50] = { 0 }, N, cnt = 0;
	int *p;
	scanf("%d", &N);

	for (p = ar; p < ar + N; p++)
		scanf("%d", p);
	for (p = ar; p < ar + N; p++) {
		if (*p == 0)
			break;
		cnt++;
	}

	printf("%d", cnt);

	return 0;
}

/*
[ 문제 4 ][레벨 0] 크기 3의 int형 배열을 사용자 입력을 통해 초기화 한 후 중앙값을 출력하는
프로그램을 작성하시오.
▶ 배열 선언 이후, 배열 표기 [ ] 는 사용 금지 (포인터 표기 사용)
즉, int x[3]; 배열 선언하고, 이 다음부터 배열 표기 [ ] 사용 금지
▶ 반복문으로 배열 훑어볼 시, 주소를 이용하여 반복문 구현 (강의자료 p. 42 참조) <-- 추가 조
건
*/

#include<stdio.h>

int main() {

	int x[3];
	int *p;

	for (p = x; p < x + 3; p++)
		scanf("%d", p);

	int *px = x;

	if ((*px >= *(px + 1) && *px <= *(px + 2)) || (*px <= *(px + 1) && *px >= *(px + 2)))
		printf("%d\n", *px);
	else if ((*(px + 1) >= *px && *(px + 1) <= *(px + 2)) || (*(px + 1) <= *px && *(px + 1) >= *(px + 2)))
		printf("%d\n", *(px + 1));
	else if ((*(px + 2) >= *px && *(px + 2) <= *(px + 1)) || (*(px + 2) <= *px && *(px + 2) >= *(px + 1)))
		printf("%d\n", *(px + 2));

	return 0;
}

/*
[ 문제 5 ][레벨 1] 5개의 정수를 입력 받아 배열 arr[ ]에 저장하고, 각 정수들의 내림차순 상의
순서를 배열 rank[ ]에 저장 한 후 출력하는 프로그램을 작성 하시오.
▶ 배열 선언 이후, 배열 표기 [ ] 는 사용 금지 (포인터 표기 사용)
▶ 입출력 시에도 포인터 사용
▶ 반복문으로 배열 훑어볼 시, 주소를 이용하여 반복문 구현 (강의자료 p. 42 참조)
 - (예시 2)에서 1 6 4 9 6의 역순은 9 6 6 4 1 이 되고 2등이 2개이며, 2등이 2개인 경우 3등은 없고 4등부터 계속 된다. (즉 같은 등수가 여러 개 있는 경우이다)
*/

#include<stdio.h>

int main() {

	int arr[5], rank[5] = { 0 }, cnt;
	int *p;

	for (p = arr; p < arr + 5; p++)
		scanf("%d", p);

	int *pr1 = arr;
	int *pr2 = arr;
	int *prank = rank;

	for (pr1 = arr; pr1 < arr + 5; pr1++) {
		cnt = 1;
		for (pr2 = arr; pr2 < arr + 5; pr2++)
			if (*pr1 < *pr2) {
				cnt++;
			}
		printf("%d=r%d ", *pr1, cnt);
	}

	return 0;
}

/*
[ 문제 6 ][레벨 1] 10개의 영문자를 입력받은 후 가장 빈도수가 높은 문자와 그 문자의 빈도수를
출력하시오. 문자의 빈도수가 같은 경우 먼저 나오는 문자를 출력하시오.
▶ 배열 선언 이후, 배열 표기 [ ] 는 사용 금지 (포인터 표기 사용)
즉, char ch[10]; 배열 선언하고, 이다음부터 배열 표기 [ ] 사용 금지
▶ 반복문으로 배열 훑어볼 시, 주소를 이용하여 반복문 구현 (강의자료 p. 42 참조)
*/

#include<stdio.h>

int main() {

	char c[10], ch;
	int cnt, max = 0;
	char *p;
	for (p = c; p < c + 10; p++)
		scanf("%c", p);
	char *pc1 = c;
	char *pc2 = c;

	for (pc1 = c; pc1 < c + 10; pc1++) {
		cnt = 0;
		for (pc2 = c; pc2 < c + 10; pc2++)
			if (*pc1 == *pc2)
				cnt++;
		if (max < cnt) {
			max = cnt;
			ch = *pc1;
		}
	}
	printf("%c %d", ch, max);

	return 0;
}

/*
[ 문제 7 ][레벨 0] 정수 3개를 사용자로부터 입력 받아서, 화면에 출력하시오. - input( ) 함수를 정의하여 사용하시오. ◦ 인자: 세 개의 int형 포인터
 ◦ 정수 3개를 사용자로부터 입력 받는다. ◦ input( ) 함수에서는 함수 인자 이외에 어떤 변수도 사용하지 않는다. ◦ 반환 값: 없음
 - output( ) 함수를 정의하여 사용하시오. ◦ 인자: 세 개의 int형 포인터
*/

#include<stdio.h>

void input(int*, int*, int*);
void output(int*, int*, int*);

int main() {

	int x, y, z;
	input(&x, &y, &z);
	output(&x, &y, &z);

	return 0;
}

void input(int *px, int *py, int *pz) {
	scanf("%d %d %d", px, py, pz);
}

void output(int *px, int *py, int *pz) {
	printf("%d %d %d", *px, *py, *pz);
}

/*
[ 문제 8 ][레벨 1] N개의 정수를 입력 받아 배열에 저장한 후 (N ≤ 50), 다시 배열에서 값을 교
환하고 싶은 인덱스 a 와 b를 입력 받는다. 인덱스 a 와 b 위치의 요소 값들이 교환된 배열을 출
력하는 프로그램을 작성하시오. ※ 8번 문제는 함수를 연습하는 문제로 7번 문제와 달리 포인터 사용을 위한 제약 조건이 없다. ※ 포인터 사용을 연습하기 위하여 9장 포인터의 모든 함수 실습문제에서 전역변수 사용금지
 - 인덱스 a, b는 상대적 크기에 상관없다. a < b 혹은 a > b
 - swap( ) 함수를 정의하여 사용하시오. ◦ 인자: 두 개의 int 포인터
 ◦ 반환 값: 없음
 ◦ 인자가 가리키는 두 변수의 값 교환
 - 입출력은 main( ) 함수에서 수행
*/

#include<stdio.h>

void swap(int *pa, int *pb) {
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int main() {

	int x[50], n, a, b, tmp;
	int *p;
	scanf("%d", &n);

	for (p = x; p < x + n; p++)
		scanf("%d", p);
	getchar();
	int *px = x;
	scanf("%d %d", &a, &b);

	swap(px + a, px + b);

	for (p = x; p < x + n; p++)
		printf("%d ", *p);

	return 0;
}

/*
[ 문제 9 ][레벨 1] 크기 3의 int형 배열을 사용자 입력을 통해 초기화 한 후 중앙값을 출력하는
프로그램을 mid 함수를 사용하여 작성하시오. - mid( ) 함수를 다음과 같이 정의하여 사용하시오. ◦ 인자: int 배열
◦ 배열에 저장된 세 개의 정수 중 중앙값을 찾아내어 중앙값의 위치를 반환 (세 개의 정수
를 정렬하는 등 배열 내 정수의 이동 없이 중앙값을 찾아 낼 것)
◦ 반환 값: 중앙값이 저장된 배열 원소의 주소
 - 입출력은 main( ) 함수에서 수행
 - 중앙값(median)이란 오름차순으로 정렬했을 때 순서가 중앙에 해당하는 숫자이다.
 - (예시 1)에서 1 9 7인 경우 오름차순으로 정렬하면 1 7 9 가 되고 중앙에 있는 수는 7 이다. - 입력이 1 1 2인 경우 1을 출력한다. 입력이 1 2 2인 경우 2를 출력한다.
*/

#include<stdio.h>

void mid(int x[]) {
	int *px = x;

	if ((*px >= *(px + 1) && *px <= *(px + 2)) || (*px <= *(px + 1) && *px >= *(px + 2)))
		printf("%d\n", *px);
	else if ((*(px + 1) >= *px && *(px + 1) <= *(px + 2)) || (*(px + 1) <= *px && *(px + 1) >= *(px + 2)))
		printf("%d\n", *(px + 1));
	else if ((*(px + 2) >= *px && *(px + 2) <= *(px + 1)) || (*(px + 2) <= *px && *(px + 2) >= *(px + 1)))
		printf("%d\n", *(px + 2));
}

void main() {

	int x[3];
	int *p;

	for (p = x; p < x + 3; p++)
		scanf("%d", p);

	mid(x);

	return 0;
}

/*
[ 문제 10 ][레벨 1] 최대 공약수와 최소 공배수를 포인터를 사용하여 전달하는 프로그램을 작성
하시오. 1) gcdlcm( ) 함수
◦ 인자: int형 변수 두 개, int형 포인터 2개
함수(int형 변수, int형 변수, int형 포인터, int형 포인터)
◦ 정수값 2개를 넘겨받아 최대 공약수와 최소 공배수를 계산한 후, 포인터를 사용하여 전달
1도 최대공약수가 될 수 있음. 입력된 정수도 최대공약수가 될 수 있음
 ◦ 반환 값: 없음
2) main 함수
 ◦ 정수 두 개를 사용자로부터 입력 받는다. ◦ 함수를 호출한다. ◦ 최대 공약수와 최소 공배수를 화면에 출력한다.
*/

#include<stdio.h>

void gcdlcm(int m, int n, int *p) {
	int i, gcd = 0, lcd = 0;
	if (m > n)
		p = &m;
	else
		p = &n;
	for (i = 1; i <= *p; i++) {
		if (m % i == 0 && n % i == 0)
			gcd = i;
	}
	printf("%d %d", gcd, m * n / gcd);

}

int main() {

	int m, n;
	scanf("%d %d", &m, &n);

	int *p = &m;

	gcdlcm(m, n, p);

	return 0;
}

/*
[ 문제 11 ][레벨 1] 포인터를 사용하여 문자 6개를 복사하는 함수를 만들고 출력하시오.
▶ 배열 선언 이후, 배열 표기 [ ] 는 사용 금지 (포인터 표기 사용)
 - 문자열을 복사하는 함수 strcopy( )를 정의하여 사용하시오.
 ◦ 인자: 두 개의 문자 배열 a[ ] 와 b[ ]
 ◦ 배열 b[ ]에 담긴 문자 6개를 배열 a[ ]에 복사
 ◦ 반환 값: 없음
 - 입출력은 main( ) 함수에서 수행
 ◦ 입출력 시에 포인터 표기 사용
*/

#include<stdio.h>

void strcopy(char a[], char b[]) {
	char *pa = a;
	b = pa;
	char *pb = b;
	for (pb = b; pb < b + 6; pb++)
		printf("%c", *pb);
}

int main() {

	char a[6], b[6];
	char *p;
	for (p = a; p < a + 6; p++)
		scanf("%c", p);

	strcopy(a, b);

	return 0;
}

/*
[ 문제 12 ][레벨 1] N개의 정수를 두 번 입력받아 (N ≤ 20), 역방향으로 더하여 출력하는 프로그
램을 작성하시오.
▶ 배열 선언 이후, 배열 표기 [ ] 는 사용 금지 (포인터 표기 사용)
▶ 반복문으로 배열 훑어볼 시, 주소를 이용하여 반복문 구현 (강의자료 p. 42 참조)
*/

#include<stdio.h>

void addArray(int *px, int *py, int *psum, int n) {
	int i;
	for (i = 0; i < n; i++) {
		*(psum + i) = *(px + i) + *(py + n - i - 1);
	}
	for (i = 0; i < n; i++)
		printf(" %d", *(psum + i));
}

int main() {

	int n, x[20], y[20], sum[20] = { 0 };
	int *pn = &n, *px, *py;
	int *psum = sum;
	scanf("%d", pn);
	getchar();
	for (px = x; px < x + n; px++)
		scanf("%d", px);
	getchar();
	for (py = y; py < y + n; py++)
		scanf("%d", py);

	int *pa = x;
	int *pb = y;
	addArray(pa, pb, psum, n);

}

/*
[ 문제 13 ][레벨 1] 정수 N, S, E를 입력 받는다. N개의 정수를 입력 받아 (N ≤ 100) 배열에 저장
한다. 배열에 저장된 N개 중에서 인덱스 S에서 시작해서 인덱스 E까지 요소의 총 합을 출력하시오.
 ▶ 배열 선언 이후, 배열 표기 [ ] 는 사용 금지 (포인터 표기 사용)
 ▶ 반복문으로 배열 훑어볼 시, 주소를 이용하여 반복문 구현 (강의자료 p. 42 참조)
 - arrsum( ) 함수를 정의하여 사용하시오.
 ◦ 인자: 배열에서 구간 시작 원소와 구간 마지막 원소를 가리키는, int 형 포인터 두 개
 ◦ 반환 값: 구간에 해당되는 배열 요소의 총 합
 - 입출력은 main( ) 함수에서 수행
*/

#include<stdio.h>

int arrsum(int *p1, int *p2) {
	int *i, sum = 0;
	for (i = p1; i <= p2; i++)
		sum += *i;
	return sum;
}

int main() {

	int n, s, e, x[100];
	int *pn = &n, *ps = &s, *pe = &e;
	scanf("%d %d %d", pn, ps, pe);
	getchar();
	int *px = x;
	for (px = x; px < x + n; px++)
		scanf("%d", px);
	int *p = x;
	printf("%d", arrsum(p + *(ps), p + *(pe)));

}

/*
[ 문제 14 ][레벨 1] N개 정수를 입력 받아 (N≤100) int형 배열 d[100]에 저장하고, 다음 수식의
값을 출력하는 프로그램을 작성하시오.
*/

#include<stdio.h>

int add_to_k(int *pa, int *pb) {
	int *i, sum = 0;
	for (i = pa; i <= pb; i++)
		sum += *i;
	return sum;
}

int main() {

	int n, i, d[100], sum = 0;
	scanf("%d", &n);
	getchar();
	int *p;
	for (p = d; p < d + n; p++)
		scanf("%d", p);
	int *pd = d;

	for (i = 0; i < n; i++)
		sum += add_to_k(pd, pd + i);

	printf("%d", sum);

	return 0;
}

/*
[ 문제 15 ][레벨 1] 10개의 정수를 입력으로 받아, 가장 큰 수부터 내림차순으로 정렬하여 출력하
는 프로그램을 다음과 같은 방법으로 작성 하시오.
▶ 배열 선언 이후, 배열 표기 [ ] 는 사용 금지 (포인터 표기 사용)
▶ 반복문으로 배열 훑어볼 시, 주소를 이용하여 반복문 구현 (강의자료 p. 42 참조) (main( ) 함
수와 ABC( ) 함수에 이 조건이 적용됨)
*/

#include<stdio.h>

void ABC(int *p, int k) {
	int* i, max = *p;
	int *tmp = p;
	int tmp2;
	for (i = p; i < p + k; i++)
		if (max < *i) {
			max = *i;
			tmp = i;
		}

	printf(" %d", max);
	tmp2 = *p;
	*p = *tmp;
	*tmp = tmp2;
}

int main() {

	int x[10], i;
	int *p;
	for (p = x; p < x + 10; p++)
		scanf("%d", p);
	int *px = x;

	for (i = 0; i < 10; i++) {
		ABC(px + i, 10 - i);
	}

	return 0;
}