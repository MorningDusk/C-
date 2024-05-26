/*
11장2절 [ 문제 1 ][레벨 0] 3차원 벡터를 저장할 구조체를 선언 후 두개의 3차원 벡터(V1, V2)를
입력 받으시오. 두 벡터의 원소별로 곱한 값을 새로운 3차원 벡터 (V3)에 입력 후 이를 출력하는
프로그램을 작성하시오. 그다음 두 벡터의 내적을 출력하시오.
- 3차원 벡터 V1={ x1, y1, z1 }, V2={ x2, y2, z2 } - 원소별 곱을 3차원 벡터에 저장: V3 = { x1 × x2 , y1 × y2 , z1 × z2 }
- 3차원 벡터 V1 과 V2 의 내적: V1 • V2 = x1×x2 + y1×y2 + z1×z2
*/

#include<stdio.h>

struct vector {
	int x, y, z;
};

int main() {
	struct vector v1, v2, v3;
	int total = 0;

	scanf("%d %d %d", &v1.x, &v1.y, &v1.z);
	scanf("%d %d %d", &v2.x, &v2.y, &v2.z);

	v3.x = v1.x * v2.x;
	v3.y = v1.y * v2.y;
	v3.z = v1.z * v2.z;
	total = v3.x + v3.y + v3.z;

	printf("%d %d %d\n", v3.x, v3.y, v3.z);
	printf("%d", total);

	return 0;
}

/*
11장2절 [ 문제 2 ][레벨 0] 구조체를 이용하여서 현재 시각을 표현한다. 사용자로부터 2개의 시각
을 입력 받아서 두 시각 사이의 차이를 계산하여 출력하는 프로그램을 작성하시오. 
- 두 번째 시각이 첫 번째 시각보다 항상 늦은 시각이라고 가정한다.
- 시간차가 없는 경우에 분과 초만 출력하는 것이 아니라 시 분 초, 0 10 20 으로 출력한다.
*/

#include<stdio.h>

struct time {
	int h, m, s;
};

int main() {
	struct time t1, t2;
	int hour, min, sec;

	scanf("%d %2d %2d", &t1.h, &t1.m, &t1.s);
	scanf("%d %2d %2d", &t2.h, &t2.m, &t2.s);

	hour = t2.h - t1.h;
	min = t2.m - t1.m;
	sec = t2.s - t1.s;

	if (min < 0) {
		hour -= 1;
		min = 60 - t1.m + t2.m;
	}
	if (sec < 0) {
		min -= 1;
		sec = 60 - t1.s + t2.s;
	}

	printf("%d %d %d", hour, min, sec);

	return 0;
}

/*
11장3절 [ 문제 3 ][레벨 0] 5명 학생의 이름과 기말고사 점수를 입력 받아, 구조체 배열에 저장
한 후, 평균 이하의 점수를 받은 학생의 이름을 출력하는 프로그램을 작성 하시오.
 - 학생의 이름은 공백 없이 최대 9개 영어 문자이다.
*/

#include<stdio.h>

struct student {
	char name[9];
	int grade;
};

int main() {

	struct student list[5];
	int i, avg, total = 0;

	for (i = 0; i < 5; i++) {
		scanf("%s %d", &list[i].name, &list[i].grade);
	}

	for (i = 0; i < 5; i++)
		total += list[i].grade;

	avg = total / 5;

	for (i = 0; i < 5; i++) {
		if (list[i].grade <= avg)
			printf("%s\n", list[i].name);
	}

	return 0;
}

/*
11장3절 [ 문제 4 ][레벨 0] N명의 학생에 대해 이름과 세 번 본 시험의 성적을 읽어 들여, 각 학
생의 이름과 평균점수(소수점이하 첫째자리 까지), 학점을 출력하는 프로그램을 작성하시오.
 - 학생수 N은 맨 처음 읽어 들이도록 하며, N은 20을 넘지 않는다.
 - 학생의 이름은 공백 없이 최대 19개 영어 문자이다.
 - 학점은 90점 이상이면 A
 - 학점은 80점 이상이면 B
 - 학점은 70점 이상이면 C
 - 학점은 70점 미만이면 F를 부여하시오.
*/

#include<stdio.h>

struct student {
	char name[19];
	float a, b, c;
};

int main() {

	struct student list[20];
	float total[20];
	int n, i;
	char score[20];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s %f %f %f", &list[i].name, &list[i].a, &list[i].b, &list[i].c);

	for (i = 0; i < n; i++) {
		total[i] = (list[i].a + list[i].b + list[i].c) / 3;
		if (total[i] >= 90)
			score[i] = 'A';
		else if (total[i] >= 80)
			score[i] = 'B';
		else if (total[i] >= 70)
			score[i] = 'C';
		else
			score[i] = 'F';
		printf("%s %.1f %c\n", list[i].name, total[i], score[i]);
	}

	return 0;
}

/*
11장4절 [ 문제 5 ][레벨 1] N 명의 학생에 대한 정보(이름, 국어 성적, 영어 성적, 수학 성적)를
입력 받아, 각 학생의 평균 성적에 따라 학점을 산출한 후, 각 학생의 이름과 평균 성적(소수점 이
하 첫째자리까지)과 학점을 출력하는 프로그램을 작성하시오. - N은 1 이상 50 이하. - 학생의 이름은 공백 없이 최대 7개 영어 문자이다.
- 이름은 길이가 1 이상 8 이하인 공백을 포함하지 않는 문자열
- 국어 성적, 영어 성적, 수학 성적은 0 이상 100 이하인 정수
- 평균은 소수 첫째 자리까지 출력
- 학점은 평균 성적으로 다음 기준을 적용하여 산출:
90 이상 100 이하: A
80 이상 90 미만: B
70 이상 80 미만: C
70 미만: D
- 전역 변수 사용 금지
- 반드시 구조체 포인터 사용 struct student st[50], *p=st ;
- 다음 멤버를 가지는 student 구조체를 정의하여 사용하시오. 이름을 저장하는 문자배열, 국어 성적을 저장하는 정수형 변수, 영어 성적을 저장하는 정수
형 변수, 수학 성적을 저장하는 정수형 변수, 평균 성적을 저장하는 실수형 변수, 학점을 저장하는 문자형 변수
*/

#include<stdio.h>

struct student {
	char name[7];
	float k, e, m;
};

int main() {

	struct student st[50], *p = st;
	float total;
	int n;
	char score;

	scanf("%d", &n);
	for (p = st; p < st + n; p++)
		scanf("%s %f %f %f", p->name, &p->k, &p->e, &p->m);

	for (p = st; p < st + n; p++) {
		total = (p->k + p->e + p->m) / 3;
		if (total >= 90)
			score = 'A';
		else if (total >= 80)
			score = 'B';
		else if (total >= 70)
			score = 'C';
		else if (total < 70)
			score = 'D';
		printf("%s %.1f %c\n", p->name, total, score);
	}

	return 0;
}

/*
11장3절 [ 문제 6 ][레벨 1] 학급 학생의 수를 입력 받은 후, 각 학생의 성별, 체중, 키를 입력 받
으시오. 아래 표에 따라 신체등급별 인원 수를 출력하는 프로그램을 작성하시오.
*/

#include<stdio.h>

struct student {
	int s, w, h;
};

int main() {

	struct student st[10];
	int n, i, first = 0, second = 0, third = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d %d", &st[i].s, &st[i].w, &st[i].h);

	for (i = 0; i < n; i++) {
		if (st[i].s == 1) {
			if ((st[i].w < 60 && st[i].h < 165) || (st[i].w >= 60 && st[i].w < 70 && st[i].h >= 165 && st[i].h < 175) || (st[i].w >= 70 && st[i].h >= 175))
				first++;
			else if ((st[i].w < 60 && st[i].h >= 165 && st[i].h < 175) || (st[i].w >= 60 && st[i].w < 70 && st[i].h >= 175) || (st[i].w >= 70 && st[i].h < 165))
				second++;
			else if ((st[i].w < 60 && st[i].h >= 165 && st[i].h > 175) || (st[i].w >= 60 && st[i].w < 70 && st[i].h < 165) || (st[i].w >= 70 && st[i].h >= 165 && st[i].h < 175))
				third++;
		}
		else if (st[i].s == 2) {
			if ((st[i].w < 50 && st[i].h < 165) || (st[i].w >= 50 && st[i].w < 60 && st[i].h >= 165 && st[i].h < 175) || (st[i].w >= 60 && st[i].h >= 175))
				first++;
			else if ((st[i].w < 50 && st[i].h >= 165 && st[i].h < 175) || (st[i].w >= 50 && st[i].w < 60 && st[i].h >= 175) || (st[i].w >= 60 && st[i].h < 165))
				second++;
			else if ((st[i].w < 50 && st[i].h >= 165 && st[i].h > 175) || (st[i].w >= 50 && st[i].w < 60 && st[i].h < 165) || (st[i].w >= 60 && st[i].h >= 165 && st[i].h < 175))
				third++;
		}
	}

	printf("%d %d %d", first, second, third);

	return 0;
}

/*
11장3절 [ 문제 7 ][레벨 1] 10 개의 정수를 입력 받고, 그 정수의 내림차순 상 순위를 계산하여, 정수와 순위를 함께 구조체 배열에 저장 한 후, 3번째 순위와 7번째 순위에 해당하는 정수를 출력
하는 프로그램을 작성 하시오.
 - 동일한 정수가 중복 입력되는 경우는 없다고 가정한다.
 - 정렬(sorting)하여 배열에 저장하지 말고, 입력된 순서대로 순위와 함께 저장 합니다.
*/

#include<stdio.h>

struct list {
	int num, rank;
};

int main() {

	struct list st[10];
	int i, j;

	for (i = 0; i < 10; i++)
		scanf("%d", &st[i].num);

	for (i = 0; i < 10; i++) {
		st[i].rank = 0;
		for (j = 0; j < 10; j++)
			if (st[i].num > st[j].num)
				st[i].rank++;
	}

	for (i = 0; i < 10; i++)
		if (st[i].rank == 7)
			printf("%d ", st[i].num);

	for (i = 0; i < 10; i++) {
		if (st[i].rank == 3)
			printf("%d ", st[i].num);
	}

	return 0;
}

/*
11장5절 [ 문제 8 ][레벨 0] 두 개의 복소수를 입력 받고, 두 복소수를 더한 결과값을 출력하는 프
로그램을 작성하시오.
- 전역 변수 사용 금지
- 복소수를 표현하는 complex 구조체를 정의하여 사용하시오.
◦ 실수부를 나타내는 실수형 변수, 허수부를 나타내는 실수형 변수
- add 함수를 정의하여 사용하시오.
◦ 인자: 두 개의 complex 구조체
◦ 반환 값: complex 구조체
- main 함수의 내용은 다음과 같다.
◦ 복소수를 저장할 complex 구조체 선언
◦ 복소수 2개를 사용자로부터 입력 받기
◦ add 함수를 호출하여, 입력 받은 두 복소수의 합 구하기
◦ 결과값으로, 입력 받은 두 복소수의 합, 소수점 이하 첫째자리까지 출력하기
*/

#include<stdio.h>

struct complex {
	float real, imag;
};

struct complex add_complex(struct complex a, struct complex b) {
	struct complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;

	return c;
}

int main() {
	struct complex c1, c2, c3;

	scanf("%f %f", &c1.real, &c1.imag);
	scanf("%f %f", &c2.real, &c2.imag);

	c3 = add_complex(c1, c2);

	printf("%.1f + %.1fi", c3.real, c3.imag);

	return 0;
}

/*
11장5절 [ 문제 9 ][레벨 1] 한 학생의 시험 결과 정보(가장 높은 점수, 가장 낮은 점수, 시험 통과
여부, 합격 기준 점수차, 점수차)를 입력 받는다. 이 학생의 점수차와 시험 통과 여부(P 혹은 F)를
출력하는 프로그램을 작성하시오. - 시험 통과 여부 판단 방법: 가장 높은 점수와 가장 낮은 점수의 차이가 합격 기준 점수차보다
작거나 같으면 시험 통과! - 가장 높은 점수와 가장 낮은 점수는 0 이상 100 이하인 정수
- 시험 통과 여부 항목은 통과일 경우 ‘P’를, 통과하지 못한 경우 ‘F’를 값으로 가짐
- 합격 기준 점수차는 0 이상 15 이하인 정수
- 시험 결과 정보를 나타내는 result 구조체를 정의하여 사용하시오.
◦ 가장 높은 점수를 저장하는 정수형 변수, 가장 낮은 점수를 저장하는 정수형 변수, 시험
통과 여부를 저장하는 문자형 변수, 합격 기준 점수차를 저장하는 정수형 변수, 가장 높은
점수와 가장 낮은 점수의 차이를 저장하는 정수형 변수
- 전역 변수 사용 금지
- passorfail 함수를 정의하여 사용하시오. ◦ 인자: 구조체 포인터
◦ 시험 통과 여부를 계산하여 ‘P’ 혹은 ‘F’를 저장
◦ 반환 값: 없음
- main 함수의 내용은 다음과 같다.
◦ 시험 결과 정보를 저장할 result 구조체 선언
◦ 사용자로부터 가장 높은 점수, 가장 낮은 점수, 합격 기준 점수 정보를 입력 받기
◦ passorfail 함수를 호출하여, 이 학생의 시험 통과 여부 판단하기
◦ 이 학생의 점수차와 시험 통과 여부를 출력하기
*/

#include<stdio.h>

struct result {
	int max, min, diff, mmdiff;
	char porf;
};

void passorfail(struct result *p) {
	p->mmdiff = p->max - p->min;
	if (p->diff >= p->mmdiff)
		p->porf = 'P';
	else
		p->porf = 'F';
}

int main() {
	struct result n, *p = &n;

	scanf("%d %d %d", &n.max, &n.min, &n.diff);
	passorfail(p);
	printf("%d %c", p->mmdiff, p->porf);

	return 0;
}

/*
11장5절 [ 문제 10 ][레벨 1] year/month/day 형식의 두 날짜를 입력 받아, 각각 구조체 변수에
저장하고, 두 날짜 중 더 빠른 날짜를 같은 형식으로 출력하는 프로그램을 작성 하시오.
 - 함수 select_min()을 다음과 같이 작성하여 사용 하시오.
 ◦ 인자: 두 개의 구조체 변수의 주소 (포인터)
 ◦ 반환 값: 두 날짜 중 더 빠른 날짜를 나타내는 구조체 변수의 주소 (값이 아님)
 - 입력과 출력은 main() 함수에서 실행된다.
*/

#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
};

struct date *select_min(struct date *n, struct date *m) {
	if (n->year < m->year)
		return n;
	else if (n->year > m->year)
		return m;
	else {
		if (n->month < m->month)
			return n;
		else if (n->month > m->month)
			return m;
		else {
			if (n->day < m->day)
				return n;
			else if (n->day >= m->day)
				return m;
		}
	}
}

int main() {

	struct date n, m, *k;
	scanf("%d/%d/%d", &n.year, &n.month, &n.day);
	scanf("%d/%d/%d", &m.year, &m.month, &m.day);
	k = select_min(&n, &m);
	printf("%d/%d/%d", k->year, k->month, k->day);

	return 0;
}

/*
11장5절 [ 문제 11 ][레벨 1] 5명 학생의 이름과 기말고사 점수를 입력 받아, 구조체 배열에 저장
한 후, 기말고사 점수가 최하위인 학생의 이름과 점수를 출력하는 프로그램을 작성 하시오.
 - 함수 select_min()을 다음과 같이 작성하여 사용 하시오.
 ◦ 인자: 구조체 배열의 주소 (포인터)
 ◦ 반환 값: 기말고사 점수가 최하위인 구조체 배열 원소의 주소 (값이 아님)
 - 학생의 이름은 공백 없이 최대 길이가 9인 영어 문자열이다.
 - 기말고사점수는 0과 100사이의 정수이다.
 - 같은 점수의 학생은 없다고 가정한다.
 - 출력은 main() 함수에서 실행된다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char name[9];
	int score;
};

struct student *select_min(struct student str[]) {
	int i;
	struct student *c = str;
	for (i = 0; i < 5; i++)
		if ((str + i)->score < c->score)
			c = (str + i);
	return c;
}

int main() {

	struct student str[5], *c;
	int i;
	for (i = 0; i < 5; i++)
		scanf("%s %d", str[i].name, &str[i].score);

	c = select_min(str);
	printf("%s %d", c->name, c->score);

	return 0;
}

/*
11장5절 [ 문제 12 ][레벨 2] 10명 학생의 이름과 3회 퀴즈 점수를 입력으로 받아 퀴즈 평균 점수
가 최고점과 최저점인 학생의 이름과 평균 점수를 출력하고, 퀴즈 평균 점수가 하위 30%에 속하
는 학생의 이름과 퀴즈 평균 점수를 출력하는 프로그램을 다음 함수들을 사용하여 작성합니다.
 - read_data( ) 함수
 ◦ 인자: 구조체 배열
 ◦ 10명 학생의 이름과 학생당 3회 퀴즈 점수를 입력 받아, 구조체 배열에 저장합니다.
 ◦ 학생의 이름은 공백 없이 최대 9개 영어 문자이다.
 ◦ 반환값: 없음
 - cal_avg( ) 함수
 ◦ 인자: 구조체 배열
 ◦ 각 학생의 퀴즈 점수 평균값을 계산합니다.
 ◦ 반환값: 없음
 - sort( ) 함수
 ◦ 인자: 구조체 배열
 ◦ 평균값에 따라 학생들의 이름과 퀴즈점수들을 내림차순으로 정렬하여 저장합니다.
 ◦ 반환값: 없음
 - print_score( ) 함수
 ◦ 인자: 구조체 배열
 ◦ 최고평균점, 최저평균점, 하위 30%의 평균점을 받은 학생들의 이름과 평균 점수를 출력
합니다. 평균은 소수점 이하 둘째자리까지 출력합니다.
 ◦ 반환값: 없음
 - 평균이 동점인 경우는 없는 것으로 한다.
*/

#include <stdio.h>

struct student {
	char name[9];
	double s1, s2, s3;
	double avg;
};

void read_date(struct student score[]) {
	int i;
	for (i = 0; i < 10; i++)
		scanf("%s %lf %lf %lf", (score + i)->name, &(score + i)->s1, &(score + i)->s2, &(score + i)->s3);
}

void cal_avg(struct student score[]) {
	int i;
	for (i = 0; i < 10; i++)
		(score + i)->avg = ((score + i)->s1 + (score + i)->s2 + (score + i)->s3) / 3;
}

void sort(struct student score[]) {
	int i, j;
	struct student tmp;
	for (i = 0; i < 9; i++)
		for (j = i + 1; j < 10; j++)
			if ((score + i)->avg < (score + j)->avg) {
				tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;
			}
}

void print_score(struct student score[]) {
	int i;
	printf("%s %.2lf\n", score->name, score->avg);
	printf("%s %.2lf\n", (score + 9)->name, (score + 9)->avg);
	for (i = 7; i < 10; i++)
		printf("%s %.2lf\n", (score + i)->name, (score + i)->avg);
}

int main() {

	struct student score[10];
	read_date(score);
	cal_avg(score);
	sort(score);
	print_score(score);

	return 0;
}