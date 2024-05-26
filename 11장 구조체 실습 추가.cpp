/*
[ 문제 1 ] 매일의 판매 물건 번호를 기록한 후, 날짜와 물건번호를 입력하면 몇 개 팔렸는지 출
력하는 프로그램을 작성하시오. 1≦N≦10
 - 매일의 판매기록은 0으로 끝이 난다.
 - 구조체 정의할 때 typedef을 사용하시오.
 - 구조체 record
 int month; int day; int sale[20]; // 물건 번호 기록, 최대 20개
*/

#include<stdio.h>

typedef struct record {
	int month, day, sale[20];
}r;

int main() {

	int n, i, j, cnt = 0, m, d, s, date;
	r list[10];
	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; i++) {
		scanf("%d", &date);
		list[i].month = date / 100;
		list[i].day = date % 100;
		for (j = 0; j < 20; j++) {
			scanf("%d", &list[i].sale[j]);
			if (list[i].sale[j] == 0)
				break;
		}
	}
	scanf("%d %d %d", &m, &d, &s);
	for (i = 0; i < n; i++) {
		if (m == list[i].month && d == list[i].day)
			for (j = 0; list[i].sale[j] != 0; j++)
				if (s == list[i].sale[j])
					cnt++;
	}
	printf("%d", cnt);

	return 0;
}

/*
[ 문제 2 ] 학번과 3과목 점수를 입력받는다. 학번 순서대로 평균을 소수 첫째자리까지 출력하시
오. 1≦N≦10
- 구조체 정의할 때 typedef을 사용하시오.
- student 구조체 멤버로 평균을 저장하는 avg를 정의하시오.
- 함수 average( )
o 입력: student 구조체 변수 한 개의 주소이며 배열이 입력되는 것이 아니다.
o 한 학생의 평균을 계산하여 학생 구조체 변수의 멤버 avg에 저장한다.
o 반환값: 없음
- 함수 원형 선언을 사용하시오. (함수 정의는 main() 함수 다음에 위치한다) (위반 시 50% 감점)
*/

#include<stdio.h>

typedef struct student {
	int id;
	float s1, s2, s3, avg;
}student;

void average(struct student *p);

int main() {

	int n, i, j, tmp;
	float atmp;
	student st[10];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%d %f %f %f", &st[i].id, &st[i].s1, &st[i].s2, &st[i].s3);

	for (i = 0; i < n; i++)
		average(&st[i]);

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (st[i].id > st[j].id) {
				tmp = st[j].id;
				st[j].id = st[i].id;
				st[i].id = tmp;
				atmp = st[j].avg;
				st[j].avg = st[i].avg;
				st[i].avg = atmp;
			}

	for (i = 0; i < n; i++)
		printf("%04d %.1f\n", st[i].id, st[i].avg);

	return 0;
}

void average(struct student *ps) {
	ps->avg = (ps->s1 + ps->s2 + ps->s3) / 3;
}

/*
[ 문제 3 ] 주어진 식대에 가장 근접해서 세끼를 먹을 수 있는 방법을 찾아 식당 이름을 출력하
고, 이때의 비용을 출력하시오. <-- [ 문제 2-5 ]
- 아침, 점심, 저녁 순이다. 각 끼 다른 식당에서 식사한다. 식당 이름은 최대 99 글자이다.
- rest 구조체에, name, breakfast, lunch, dinner를 멤버로 가진다. 
- 구조체 정의할 때 typedef을 사용하시오.
*/

#include <stdio.h>
#include <string.h>

typedef struct restaurant {
	char name[100];
	int b, l, d;
}rest;

int main() {

	rest r[10];
	int n, i, j, k, money, price = 0, diff;
	char breakfast[100] = { 0 }, lunch[100] = { 0 }, dinner[100] = { 0 };

	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%s %d %d %d", r[i].name, &r[i].b, &r[i].l, &r[i].d);
	scanf("%d", &money);
	diff = money;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				if (i != j && j != k && k != i && r[i].b + r[j].l + r[k].d <= money && money - (r[i].b + r[j].l + r[k].d) <= diff) {
					price = r[i].b + r[j].l + r[k].d;
					diff = money - price;
					strcpy(breakfast, r[i].name);
					strcpy(lunch, r[j].name);
					strcpy(dinner, r[k].name);
				}

	printf("%s\n", breakfast);
	printf("%s\n", lunch);
	printf("%s\n", dinner);
	printf("%d", price);

	return 0;
}

/*
[ 문제 4 ] 찾고자하는 이름을 가진 학생들의 평균 점수에 가장 가까운 학생의 full name과 점수
를 출력하시오. 첫째 줄에 평균을 소수 둘째자리까지 출력하시오. 1≦N≦10
- 예시 1에서 찾고자하는 kim 이름을 가진 학생은 4명이므로 평균은, (82+65+93+94)/4 = 83.50
- student 구조체는 name1, name2, score, flag를 멤버로 가진다. 이름은 최대 영문자 20글자이다.
- 찾고자하는 이름을 가진 학생에는 멤버 flag=1 을 저장하고, 아니 경우에는 멤버 flag=0을 저장
한다.
- 구조체 정의할 때 typedef을 사용하시오.
*/

#include <stdio.h>
#include <string.h>

typedef struct student {
	char name1[20], name2[20];
	float score;
	int flag;
}student;

int main() {

	student grade[10];
	int n, i;
	char name[20], a[20] = { 0 }, b[20] = { 0 };
	float avg = 0.0, cnt = 0, diff, fscore = 0.0;

	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%s %s %f", grade[i].name1, grade[i].name2, &grade[i].score);
	scanf("%s", name);

	for (i = 0; i < n; i++) {
		if (strcmp(name, grade[i].name1) == 0 || strcmp(name, grade[i].name2) == 0)
			grade[i].flag = 1;
		else
			grade[i].flag = 0;
	}

	for (i = 0; i < n; i++)
		if (grade[i].flag == 1) {
			avg += grade[i].score;
			cnt++;
		}
	avg /= cnt;
	diff = avg;

	for (i = 0; i < n; i++)
		if (grade[i].flag == 1) {
			if ((grade[i].score - avg <= diff && grade[i].score - avg >= 0) || (avg - grade[i].score <= diff && avg - grade[i].score >= 0)) {
				fscore = grade[i].score;
				strcpy(a, grade[i].name1);
				strcpy(b, grade[i].name2);
				diff = grade[i].score - avg;
				if (diff < 0)
					diff = -diff;
			}
		}

	printf("average = %.2f\n", avg);
	printf("%s %s %.0f", a, b, fscore);

	return 0;
}

/*
[ 문제 5 ] 파이팅 게임을 구현 한다. N명의 플레이어에 대한 이름과 공격력, 체력을 입력받아 구
조체 배열에 저장한 후 게임을 시작한다. 게임이 시작되면, 각 줄에서 플레이어 두 명의 이름을 입력받고 각자의 체력이 상대방의 공격력만
큼 깎이는 과정이 반복된다. (서로 체력이 깎인다)
반복횟수가 5가 되거나, 한 명의 플레이어라도 체력이 0 이하가 되면 게임이 종료되고 전체 플레
이어를 남은 체력 내림차순으로 출력한다. (2161)
 - 첫 입력 값은 정수 N이다. (N은 10이하의 양수)
 - 플레이어의 이름은 공백 없이 최대 10개의 영어 문자이다.
 - 체력의 최솟값은 0이다. (체력이 0 미만이 될 시 0으로 저장)
 - 내림차순 출력 시 체력이 같은 플레이어는 입력 받은 순으로 출력
*/

#include <stdio.h>
#include <string.h>

typedef struct player {
	char name[10];
	int attack, health;
}player;

int main() {

	struct player game[10], tmp;
	int n, i, j, cnt = 0, flag = 0;
	char p1[10], p2[10];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%s %d %d", game[i].name, &game[i].attack, &game[i].health);

	while (1) {
		if (flag == 1 || cnt == 5)
			break;
		cnt++;
		scanf("%s %s", p1, p2);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (strcmp(p1, game[i].name) == 0 && strcmp(p2, game[j].name) == 0) {
					game[i].health -= game[j].attack;
					game[j].health -= game[i].attack;
					if (game[i].health <= 0 || game[j].health <= 0) {
						flag = 1;
					}
				}
	}

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++) {
			if (game[j].health < game[j + 1].health) {
				tmp = game[j];
				game[j] = game[j + 1];
				game[j + 1] = tmp;
			}
		}

	for (i = 0; i < n; i++) {
		if (game[i].health < 0)
			game[i].health = 0;
		printf("%s %d\n", game[i].name, game[i].health);
	}

	return 0;
}

/*
[ 문제 6 ] 이름과 국영수 순으로 입력 받는다. 각 과목의 평균을 소수 첫째자리까지 출력하고, 최
고점 학생의 이름을 출력하시오. 이름은 최대 9 글자이다. 1≦N≦10 (2162)
- 구조체 정의할 때 typedef을 사용하시오.
- 함수 struct subject average(struct student st[ ] )
 혹은 struct subject average(struct student *pst )
 o 입력: student 구조체 배열
 o 과목별 평균을 계산하여 과목 구조체 변수의 멤버들에 저장한다.
 o 최고점 학생을 찾아서 과목 구조체 변수의 멤버 top 에 저장한다.
 o 구조체 포인터 멤버 연산자 -> 를 사용하시오.
 o 반환값: struct subject 자료형
- 함수 원형 선언을 사용하시오. (함수 정의는 main() 함수 다음에 위치한다) (위반 시 50% 감점)
struct student { 생략
 };
struct subject{
 double koravg, engavg, mathavg; char top[10]; };
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	double kor, eng, math;
	char name[10];
}student;

typedef struct subject {
	double koravg, engavg, mathavg;
	char top[10];
}subject;

struct subject average(struct student st[], int n);

int main() {

	student st[10];
	subject su;
	int n, i;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		scanf("%s %lf %lf %lf", st[i].name, &st[i].kor, &st[i].eng, &st[i].math);

	su = average(st, n);

	printf("kor=%.1lf\n", su.koravg);
	printf("eng=%.1lf\n", su.engavg);
	printf("math=%.1lf\n", su.mathavg);
	printf("top=%s", su.top);
	return 0;
}

struct subject average(struct student st[], int n) {
	struct subject sub, *q = &sub;
	struct student *p = st;
	int i;
	double max_eng;
	double max_math;
	double max_kor;

	q->engavg = 0;
	q->koravg = 0;
	q->mathavg = 0;
	strcpy(q->top, p->name);
	max_eng = p->kor;
	max_math = p->math;
	max_kor = p->kor;
	for (i = 0; i < n; i++) {
		q->koravg += (p + i)->kor;
		q->engavg += (p + i)->eng;
		q->mathavg += (p + i)->math;
	}

	q->koravg /= n;
	q->engavg /= n;
	q->mathavg /= n;

	for (i = 0; i < n; i++) {
		if ((p + i)->kor >= max_kor && (p + i)->eng >= max_eng && (p + i)->math >= max_math) {
			strcpy(q->top, (p + i)->name);
			max_eng = (p + i)->eng;
			max_kor = (p + i)->kor;
			max_math = (p + i)->math;
		}
	}
	return sub;
}

/*
[ 문제 7 ] 함수에서 이름을 뒤집어서 저장하시오. 뒤집어진 이름을 차례로 화면에 출력하고, 길
이가 가장 긴 이름을 화면에 출력하시오. 1≦N≦10 이름은 최대 20 글자이다. (1795)
- 함수 struct student * change( struct student st[ ] ) 혹은 struct student * change( struct student st* )
 o 입력: name 구조체 배열
 o 이름을 뒤집어 저장한다.
 o 화면 출력은 main 함수에서 처리한다.
 o 반환값: name 구조체 배열에서, 길이가 가장 긴 이름을 가지는 원소의 주소
 struct student{
 char name[21] ; // 원 이름
 char r_name[21]; }; // 뒤집어진 이름 저장
*/

#include<stdio.h>
#include<string.h>

typedef struct student {
	char name[21];
	char r_name[21];
}student;

struct student * change(struct student st[]);

int main() {

	student st[10], *p, *q;
	int n;
	scanf("%d", &n);
	getchar();
	q = st;
	for (p = st; p < st + n; p++) {
		gets(&p->name);
		if (strlen(p->name) > strlen(q->name))
			q = p;
	}
	for (p = st; p < st + n; p++)
		printf("%s\n", change(p)->r_name);
	printf("longest=%s\n", q->r_name);


	return 0;
}

struct student * change(struct student st[]) {
	char *q, *p, tmp[21];
	struct student *ps;
	q = st->name;

	for (p = st->name; *p; p++) {
		if (*p == ' ') {
			*p = '\0';
			strcpy(tmp, q);
			q = p + 1;
		}
		if (*p == '\0') {
			strcpy(st->r_name, q);
			strcat(st->r_name, " ");
			strcat(st->r_name, tmp);
		}
	}
	return st;
}