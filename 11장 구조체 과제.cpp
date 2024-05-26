/*
[ ���� 1-2 ] [���� 1] (100��) 5�� �л��� �̸��� �� �л��� �й� �� �����б� ��������� �Է¹�
�´�. �״��� ã���� �ϴ� �л��� �̸��� �Է��ϸ�, �� �л��� ���� ������ ���� ���г⵵�� ����
�ٸ� �л����� �̸��� (�Է� �������) ����Ͻÿ�. ���ǿ� �´� �л��� ���ٸ� 0�� ����Ͻÿ�.
*/

#include <stdio.h>
#include <string.h>

struct student {
	char name[10], id[10], grade;		//����ü student ����
};

int main() {

	struct student list[5];		//����ü ���� ����
	int i, j, cmp[5], flag = 0;		//���� ����
	char stname[10];		//���ڿ� ����

	for (i = 0; i < 5; i++)		//5���� �л� ����
		scanf("%s %s %c", list[i].name, list[i].id, &list[i].grade);		//�Է� �ޱ�

	scanf("%s", stname);		//ã���� �ϴ� �л��� ���� �Է�

	for (i = 0; i < 5; i++) {
		cmp[i] = strcmp(stname, list[i].name);		//strcmp �Լ� �̿��� ��ġ�ϴ� �̸� ã��
	}

	for (i = 0; i < 5; i++)
		if (cmp[i] == 0) {		//�̸��� ��ġ�ϸ�
			for (j = 0; j < 5; j++)		//�л��� ��
				if (strncmp(list[i].id, list[j].id, 4) == 0 && (list[i].grade == list[j].grade))		//���п����� ������ ������
					flag++;		//ǥ�ø� �صд�
		}

	if (flag > 1) {		//flag ������ 1���� ũ��
		for (i = 0; i < 5; i++)
			if (cmp[i] == 0) {		//��ġ�ϴ� �̸� �� ã��
				for (j = 0; j < 5; j++)
					if (strncmp(list[i].id, list[j].id, 4) == 0 && (list[i].grade == list[j].grade) && (list[i].name != list[j].name))		//���п����� ���� ���� �л� ã��
						printf(" %s", list[j].name);		//����Ѵ�
			}
	}
	else if (flag == 1)		//���� ���п����� ������ ���ٸ�
		printf("0");		//0�� ����Ѵ�

	return 0;
}

/*
[ ���� 2 ] [���� 2] (100��) ���࿡�� â���� �ϳ��� �ְ�, �� â���� N���� ���� �ڱ����(��
��)�� ��ٸ��� ����ϰ� �ִ�. N�� ���� ��� ���ð�(waiting time)�� ���ϴ� ���α׷��� ��
���Ͻÿ�. (�� �ϴ� ��� ������ �Ϸ�Ǳ� ������ �������� �߰��� ������ ����� �� ����.)
��)
������ ǥ�� ���� T1�� ����ڰ� 0�ÿ� �����ؼ� 7�ð��� ���񽺸� �޴´�. T1�� ����ڴ� ����
�� ���ð��� 0�̴�. T2�� ����ڴ� 2�ÿ� ���������� T1�� ����ڰ� 7�ð��� ���񽺸� ��ġ��
������ ����ؾ��Ѵ�. ��, T2�� ���ð��� 5�ð� (=7-2)�̴�. T3�� ����ڴ� 1���� 2���� ����
�ð��� ���� �ð����� �ڽ��� ���� �ð��� 4�� ����(��) 7�ð��� ����Ѵ�.
*/

#include <stdio.h>

struct _bank {
	int id; // ���̵�, T1, T2, T3 ���, 1, 2, 3, ... ���� �Ѵ�. 
	int arrival_time; // �����ð�
	int service_time; // ���񽺽ð�
	int waiting_time; // ���ð�
};

void waitingtime(struct _bank* guest, int n);		//�Լ� ����
double avgtime(struct _bank* guest, int n);

int main() {

	struct _bank guest[100];		//����ü ����
	int n, i;		//���� ����

	scanf("%d", &n);		//�� �� �Է�
	getchar();		//����Ű ����
	for (i = 0; i < n; i++)
		scanf("%d %d %d", &guest[i].id, &guest[i].arrival_time, &guest[i].service_time);		//���̵�, �����ð�, ���񽺽ð� �Է�

	waitingtime(guest, n);		//waitingtime �Լ� �ҷ�����
	printf("%.2lf", avgtime(guest, n));		//��� ���ð� ���

	return 0;
}

void waitingtime(struct _bank* guest, int n) {		//���ð� �Լ� ����
	int i, stime_sum = 0;		//���� ����
	guest->waiting_time = 0;

	for (i = 1; i < n; i++) {
		stime_sum += (guest + i - 1)->service_time;		//���� �ð� ���Ѵ�
		(guest + i)->waiting_time = stime_sum - (guest + i)->arrival_time;		//���� ���� �ð��� �����ð��� ���� ���ð� ���Ѵ�
	}
}

double avgtime(struct _bank* guest, int n) {		//��սð� �Լ� ����
	int i;		//���� ����
	double sum = 0.00;		//���� ����
	for (i = 0; i < n; i++)		//n���� �ݺ�
		sum += (guest + i)->waiting_time;		//���ð����� �� ���Ѵ�

	return sum / n;		//��հ� ��ȯ
}

/*
[ ���� 3-2 ] [���� 2] (100��) ��� ������ ȣ�ڵ鿡 ���� ������ �Է¹ް�, ���ϴ� ȣ�� ��� G
�� ���� �߽����κ��� ȣ�ڱ����� �Ÿ� D�� �Է��ϸ�, �Էµ� ȣ�� ��, ����� G �̻��̰�, ȣ��
������ �Ÿ��� D ������ ��� ȣ���� ȣ�� ������ ����ϴ� ���α׷��� in_hotel_info��
out_hotel_info �� �Լ��� ����Ͽ� �ۼ� �Ͻÿ�. ��, ȣ�� ������ ���ǵ��� ���� ���� ȣ�ں���
����Ѵ�. ���ǵ��� ������ ȣ���� ���, ȣ�� �̸��� ���� ���� �� ���� ȣ���� ������ ���� ��
���Ѵ�. ������ �����ϴ� ȣ���� ���� ���� ���ٰ� �����Ѵ�.
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
[ ���� 4-2 ] [���� 3] (100��) �տ��� ���� �Է°��� �̿��Ͽ�, �ش� ���� ��ȣ�� �Է��ϸ�, ��
�ݽ� ����� ����Ͻÿ�. ������� ������ ���� ��Ģ���� �����ȴ�. 
- ���ǻ� ���� ����ý����� 1�� ��ϸ� ����Ѵ�. (�Ʒ� ���� 1�� 9�� 3��) 
- ���� 1�ð��� 3,000��
- ���� 1�ð� �� 10�д� 1000�� (1���� �Ѿ 10������ ���Ǿ� 1000��) 
- �Ϸ� �ִ� �����ð��� 3������ ���� �ʴ´�. 
- [ ���� 4-2 ]���� ���� �����̿��ڿ��Դ� 100000���� ������ �ΰ��Ѵ�. 
- ��� �Է� �� �ԷµǴ� ���ڴ� ��� ���� �� ������ ����̴�. 
- ����� �Էµ� ���� ������� ����Ѵ�.
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