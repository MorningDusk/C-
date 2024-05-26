/* 7장3절 [ 문제 1 ] 배열에 5개의 정수를 입력 받아서 저장하시오. 
- 5개의 평균보다 큰 정수를 모두 출력하시오. */

#include<stdio.h>

int main() {

	int x[5], sum = 0, mean = 0, i;

	for (i = 0; i < 5; i++)
		scanf("%d", &x[i]);

	for (i = 0; i < 5; i++)
		sum += x[i];

	mean = sum / 5;

	for (i = 0; i < 5; i++)
		if (x[i] > mean)
			printf("%d\n", x[i]);

	return 0;
}

/* 7장4절 [ 문제 2 ] 배열에 7개의 문자를 입력 받아서 저장하시오. 문자 중에서 cat가 몇 번 있는지 횟수를 출력하시오. cat 가 이어진 경우만 찾는다. */

#include<stdio.h>

int main() {

	char c[7];
	int i, cnt = 0;

	for (i = 0; i < 7; ++i)
		scanf("%c", &c[i]);

	for (i = 0; i < 7; ++i) {
		if (c[i] == 'c' && c[i + 1] == 'a' && c[i + 2] == 't')
			cnt++;
	}
	printf("%d", cnt);

	return 0;
}

/* 7장3절 [ 문제 3 ] 사용자에게서 정수 다섯 개를 입력 받는다. 첫 번째 큰 수와 두 번째 큰 수를
각각 출력하시오. */

#include<stdio.h>

int main() {

	int x[5], i, j, max1, max2, tmp;

	for (i = 0; i < 5; ++i) {
		scanf("%d", &x[i]);
		if (x[0] < x[1]) {
			max1 = x[1];
			max2 = x[0];
		}
		else {
			max1 = x[0];
			max2 = x[1];
		}
	}

	for (i = 2; i < 5; ++i) {
		if (x[i] > max1) {
			max2 = max1;
			max1 = x[i];
		}
		else if (x[i] > max2)
			max2 = x[i];
	}

	printf("%d\n%d", max1, max2);

	return 0;
}

/* 7장3절 [ 문제 4 ] 배열에 10개의 숫자를 입력 받아서 저장하시오. 
- 숫자는 1 혹은 2 혹은 3 중의 하나이다. 
- 각 숫자의 개수 만큼 별표를 출력하시오 */

#include<stdio.h>

int main() {

	int x[10], i;

	for (i = 0; i < 10; ++i)
		scanf("%d", &x[i]);

	printf("1:");
	for (i = 0; i < 10; ++i) {
		if (x[i] == 1) {
			printf("*");
			if (x[i] != 1) {
				break;
			}
		}
	}
	printf("\n");
	printf("2:");
	for (i = 0; i < 10; ++i) {
		if (x[i] == 2) {
			printf("*");
			if (x[i] != 2) {
				break;
			}
		}
	}
	printf("\n");
	printf("3:");
	for (i = 0; i < 10; ++i) {
		if (x[i] == 3) {
			printf("*");
			if (x[i] != 3) {
				break;
			}
		}
	}

	return 0;
}

/* 7장5절 [ 문제 5 ] 영어 문자 다섯 개를 입력 받아서, 예시와 같이 한 번에 한 칸씩 shift해서 출
력하는 프로그램을 작성하시오. */

#include<stdio.h>

int main() {

	char c[5], tmp;
	int i, j;

	for (i = 0; i < 5; ++i)
		scanf("%c", &c[i]);

	for (i = 0; i < 5; ++i) {
		printf("%c%c%c%c%c\n", c[0], c[1], c[2], c[3], c[4]);
		tmp = c[4];
		for (j = 3; j >= 0; j--)
			c[j + 1] = c[j];
		c[0] = tmp;
	}

	return 0;
}

/* 7장4절 [ 문제 6 ] (Hangman) 정답이 되는 3글자의 영단어를 입력한 후 엔터키를 누른다. 
- 정답을 맞추기 위하여 한 글자씩 입력한 후 엔터키를 누른다. 
- 5번까지 시도할 수 있다. 
- 글자를 입력할 때 마다 현재 상태를 화면에 출력한다. 
- 정답을 맞추거나, 5번이 경과하면 프로그램은 종료된다. 
Hint: 문자 입력 후에는 getchar( ) 함수를 추가하여 엔터 문자를 버퍼에서 제거해야, 다음에
 문자 입력이 정상적으로 실행된다. 
 즉 cat⏎ 입력 다음에 문자 입력이 있으므로, cat⏎ 입력 다음에 getchar( ) 추가해야 한다. */

#include<stdio.h>

int main() {

	char sol[3], ans[4] = "___", ch;
	int i, j, k, cnt = 0, n = 0;
	for (i = 0; i < 3; i++)
		scanf("%c", &sol[i]);

	while (1) {
		scanf("%c\n", &ch);
		ch = getchar();
		++cnt;
		for (i = 0; i < 3; i++)
			if (ch == sol[i]) {
				ans[i] = ch;
				++n;
			}
		printf("%c %c %c\n", ans[0], ans[1], ans[2]);
		if (cnt == 5 || n == 3)
			break;
	}

	return 0;
}

/* [ 문제 7 ] 10개의 정수를 입력 받는다. 각 정수가 몇 번 등장했는지를 입력받은 순서대로 출력하
시오. 입력 받은 숫자와 총 입력 횟수를 함께 출력하시오. 동일한 숫자에 대해서는 한번만 출력하
시오.  */

#include<stdio.h>

int main() {

	int x[10], i, j, k, cnt;
	for (i = 0; i < 10; ++i)
		scanf("%d", &x[i]);

	for (i = 0; i < 10; ++i) {
		j = 0;
		cnt = 0;
		while (j < i && x[i] != x[j])
			++j;
		for (k = 0; k < 10; ++k)
			if (x[i] == x[k])
				++cnt;
		if (j == i)
			printf("%d %d\n", x[i], cnt);
	}

	return 0;
}

/* 7장3절 [ 문제 8 ] 배열에 5개의 정수를 입력 받아서 저장하시오. 
- 첫 번째 원소와 두 번째 원소를 비교하여 첫 번째 원소가 두 번째 원소보다 크면 서로 교환
하여 저장하시오. 
- 이 교환 연산을 첫 번째 원소부터 마지막 바로 전 원소까지 반복하시오. 
- 참고 : 제일 큰 수가 맨 뒤로 이동한다.  */

#include<stdio.h>

int main() {

	int x[5], i, j, tmp;
	for (i = 0; i < 5; ++i)
		scanf("%d", &x[i]);

	for (i = 0; i < 4; ++i) {
		if (x[i] > x[i + 1]) {
			tmp = x[i + 1];
			x[i + 1] = x[i];
			x[i] = tmp;
		}
	}

	printf("%d\n%d\n%d\n%d\n%d\n", x[0], x[1], x[2], x[3], x[4]);

	return 0;
}

/* [ 문제 9 ] 배열에 5개의 정수를 입력 받아서 저장하시오. 
- [ 문제 8 ]의 작업을 N-1번 반복하여, 가장 작은 수부터 가장 큰 수까지 오름차순으로 정렬하
시오. 여기서 N=5 이다.  */

#include<stdio.h>

int main() {

	int x[5], i, j, tmp;
	for (i = 0; i < 5; ++i)
		scanf("%d", &x[i]);

	for (i = 0; i < 4; ++i) {
		for (j = i + 1; j < 5; ++j)
			if (x[j] < x[i]) {
				tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
			}
	}
	for (i = 0; i < 5; ++i)
		printf("%d\n", x[i]);

	return 0;
}