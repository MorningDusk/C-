/*
[ 문제 1-2 ] [레벨 1] (100점) 5명 학생의 이름과 각 학생의 학번 및 지난학기 평균학점을 입력받
는다. 그다음 찾고자 하는 학생의 이름을 입력하면, 이 학생과 같은 학점을 받은 입학년도가 같은
다른 학생들의 이름을 (입력 순서대로) 출력하시오. 조건에 맞는 학생이 없다면 0을 출력하시오.
*/

#include <stdio.h>
#include <string.h>

struct student {
	char name[10], id[10], grade;		//구조체 student 정의
};

int main() {

	struct student list[5];		//구조체 변수 선언
	int i, j, cmp[5], flag = 0;		//변수 선언
	char stname[10];		//문자열 선언

	for (i = 0; i < 5; i++)		//5명의 학생 정보
		scanf("%s %s %c", list[i].name, list[i].id, &list[i].grade);		//입력 받기

	scanf("%s", stname);		//찾고자 하는 학생의 정보 입력

	for (i = 0; i < 5; i++) {
		cmp[i] = strcmp(stname, list[i].name);		//strcmp 함수 이용해 일치하는 이름 찾기
	}

	for (i = 0; i < 5; i++)
		if (cmp[i] == 0) {		//이름이 일치하면
			for (j = 0; j < 5; j++)		//학생들 중
				if (strncmp(list[i].id, list[j].id, 4) == 0 && (list[i].grade == list[j].grade))		//입학연도와 학점이 같으면
					flag++;		//표시를 해둔다
		}

	if (flag > 1) {		//flag 변수가 1보다 크면
		for (i = 0; i < 5; i++)
			if (cmp[i] == 0) {		//일치하는 이름 중 찾아
				for (j = 0; j < 5; j++)
					if (strncmp(list[i].id, list[j].id, 4) == 0 && (list[i].grade == list[j].grade) && (list[i].name != list[j].name))		//입학연도와 학점 같은 학생 찾아
						printf(" %s", list[j].name);		//출력한다
			}
	}
	else if (flag == 1)		//같은 입학연도와 학점이 없다면
		printf("0");		//0을 출력한다

	return 0;
}

/*
[ 문제 2 ] [레벨 2] (100점) 은행에는 창구가 하나가 있고, 이 창구에 N명의 고객이 자기순서(순
번)를 기다리며 대기하고 있다. N명에 대한 평균 대기시간(waiting time)을 구하는 프로그램을 작
성하시오. (단 일단 모든 업무가 완료되기 전까지 대기행렬의 중간에 누구든 끼어들 수 없다.)
예)
다음의 표와 같이 T1번 대기자가 0시에 도착해서 7시간의 서비스를 받는다. T1번 대기자는 따라
서 대기시간이 0이다. T2번 대기자는 2시에 도착했으나 T1번 대기자가 7시간이 서비스를 마치기
전까지 대기해야한다. 즉, T2의 대기시간은 5시간 (=7-2)이다. T3번 대기자는 1번과 2번의 서비스
시간을 합한 시간에서 자신의 도착 시간인 4를 제한(뺀) 7시간을 대기한다.
*/

#include <stdio.h>

struct _bank {
	int id; // 아이디, T1, T2, T3 대신, 1, 2, 3, ... 으로 한다. 
	int arrival_time; // 도착시간
	int service_time; // 서비스시간
	int waiting_time; // 대기시간
};

void waitingtime(struct _bank* guest, int n);		//함수 선언
double avgtime(struct _bank* guest, int n);

int main() {

	struct _bank guest[100];		//구조체 선언
	int n, i;		//변수 선언

	scanf("%d", &n);		//고객 수 입력
	getchar();		//엔터키 제거
	for (i = 0; i < n; i++)
		scanf("%d %d %d", &guest[i].id, &guest[i].arrival_time, &guest[i].service_time);		//아이디, 도착시간, 서비스시간 입력

	waitingtime(guest, n);		//waitingtime 함수 불러오기
	printf("%.2lf", avgtime(guest, n));		//평균 대기시간 출력

	return 0;
}

void waitingtime(struct _bank* guest, int n) {		//대기시간 함수 정의
	int i, stime_sum = 0;		//변수 선언
	guest->waiting_time = 0;

	for (i = 1; i < n; i++) {
		stime_sum += (guest + i - 1)->service_time;		//서비스 시간 합한다
		(guest + i)->waiting_time = stime_sum - (guest + i)->arrival_time;		//합한 서비스 시간을 도착시간에 빼서 대기시간 구한다
	}
}

double avgtime(struct _bank* guest, int n) {		//평균시간 함수 정의
	int i;		//변수 선언
	double sum = 0.00;		//변수 선언
	for (i = 0; i < n; i++)		//n까지 반복
		sum += (guest + i)->waiting_time;		//대기시간들을 다 합한다

	return sum / n;		//평균값 반환
}

/*
[ 문제 3-2 ] [레벨 2] (100점) 어느 도시의 호텔들에 대한 정보를 입력받고, 원하는 호텔 등급 G
와 도시 중심으로부터 호텔까지의 거리 D를 입력하면, 입력된 호텔 중, 등급이 G 이상이고, 호텔
까지의 거리가 D 이하인 모든 호텔의 호텔 정보를 출력하는 프로그램을 in_hotel_info와
out_hotel_info 두 함수를 사용하여 작성 하시오. 단, 호텔 정보는 평판도가 가장 높은 호텔부터
출력한다. 평판도가 동일한 호텔의 경우, 호텔 이름이 사전 순서 상 빠른 호텔의 정보를 먼저 출
력한다. 조건을 만족하는 호텔이 없는 경우는 없다고 가정한다.
*/

#include <stdio.h>
#include <string.h>

struct hotel_info {
	char name[30];
	int gr;
	double rep;
	double dis;
	char br;
};

int in_hotel_info(struct hotel_info *p);
void out_hotel_info(struct hotel_info *p, int N, int G, double D);

int main() {

	struct hotel_info hotels[100];

	int G, N;
	double D;

	N = in_hotel_info(hotels);
	scanf("%d %lf", &G, &D);

	out_hotel_info(hotels, N, G, D);

	return 0;
}

int in_hotel_info(struct hotel_info *p) {
	int n = 0;
	while (1) {
		scanf("%s", p->name);
		if (strcmp(p->name, "0") == 0)
			break;
		n++;
		scanf("%d %lf %lf %c", &p->gr, &p->rep, &p->dis, &p->br);
		getchar();
		p++;
	}
	return n;
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D) {
	struct hotel_info *q, ho_GD[100], *r = ho_GD, t;
	int n = 0;
	q = p;

	for (p = q; p < q + N; p++) {
		if (p->gr >= G && p->dis <= D) {
			*r = *p;
			r++;
			n++;
		}
	}

	for (q = ho_GD; q = ho_GD + n; q++)
		for (p = q + 1; p < ho_GD + n; p++) {
			if (q->rep < p->rep) {
				t = *p;
				*p = *q;
				*q = t;
			}
			else if (q->rep == p->rep) {
				if (strcmp(q->name, p->name) > 0) {
					t = *p;
					*p = *q;
					*q = t;
				}
			}
		}

	for (p = ho_GD; p < ho_GD + n; p++)
		printf("%s %d %.1lf %.1lf %c\n", p->name, p->gr, p->rep, p->dis, p->br);
}

/*
[ 문제 4-2 ] [레벨 3] (100점) 앞에서 사용된 입력값을 이용하여, 해당 차량 번호를 입력하면, 출
금시 요금을 계산하시오. 주차료는 다음과 같은 규칙으로 산정된다. 
- 편의상 주차 전산시스템은 1일 기록만 기록한다. (아래 예시 1은 9월 3일) 
- 최초 1시간은 3,000원
- 최초 1시간 후 10분당 1000원 (1분이 넘어도 10분으로 계산되어 1000원) 
- 하루 최대 주차시간은 3만원을 넘지 않는다. 
- [ 문제 4-2 ]에서 얻은 부정이용자에게는 100000원의 벌금을 부과한다. 
- 기록 입력 후 입력되는 숫자는 요금 산정 시 차량의 대수이다. 
- 요금은 입력된 차량 순서대로 출력한다.
*/

#include <stdio.h>
#include <string.h>

struct car {
	int number;
	int id;
	int year1, month1, day1, hour1, minute1;
	int year2, month2, day2, hour2, minute2;
};

int main() {

	struct car str[100];
	int result[100], n1, cnt = 0, a = 0, flag1 = 0, i, j, k;
	int n2, num_car = 0, flag2 = 0, ch, cm, total_time, bill = 0, fcnt;

	scanf("%d", &n1);
	for (i = 0; i < n1; i++)
		scanf("%d %d %d-%d-%d %d:%d %d-%d-%d %d:%d", &str[i].number, &str[i].id, &str[i].year1, &str[i].month1, &str[i].day1, &str[i].hour1, &str[i].minute1, &str[i].year2, &str[i].month2, &str[i].day2, &str[i].hour2, &str[i].minute2);

	for (i = 0; i < n1; i++) {
		for (j = 0; j < n1; j++)
			if (str[i].id == str[i].id)
				cnt++;
		if (cnt > 1) {
			for (k = 0; k < i; k++)
				if (str[i].id == result[k])
					flag1 = 1;
			if (flag1 != 1) {
				result[a] = str[i].id;
				a++;
			}
			flag1 = 0;
		}
		cnt = 0;
	}

	scanf("%d", &n2);

	for (i = 0; i < n2; i++) {
		scanf("%d", &str[i].number);
		for (j = 0; j < n2; j++)
			if (num_car == str[j].number)
				for (k = 0; k < i; k++)
					if (result[k] == str[j].id)
						flag2 = 1;

		if (flag2 == 0) {
			for (i = 0; i < n1; i++) {
				if (str[i].number == num_car) {
					ch = str[i].hour2 - str[i].hour1;
					cm = str[i].minute2 - str[i].minute1;
					if (cm < 0) {
						ch--;
						cm += 60;
					}
					total_time = (ch * 60) + cm;
					if (total_time <= 60) {
						printf("%d\n", 3000);
						break;
					}
					else {
						total_time -= 60;
						bill += 3000;
						fcnt = total_time / 10;
						if (total_time > 0)
							fcnt++;
						bill = 1000 * fcnt;

						if (bill > 30000) {
							printf("%d\n", 30000);
							break;
						}
						else {
							printf("%d\n", bill);
							break;
						}
					}
				}
			}
		}
		else
			printf("%d\n", 100000);
		flag2 = 0;
		bill = 0;
	}

	return 0;
}

/*
7
5321 160123 2017-09-03 07:00 2017-09-03 15:12
1234 151237 2017-09-03 08:00 2017-09-03 13:42
8623 158762 2017-09-03 06:00 2017-09-03 23:59
9752 171893 2017-09-03 13:55 2017-09-03 15:22
5715 151237 2017-09-03 15:43 2017-09-03 17:31
7473 160123 2017-09-03 16:41 2017-09-03 19:00
6309 174099 2017-09-03 15:33 2017-09-03 16:12
3
6309
5715
8623
*/