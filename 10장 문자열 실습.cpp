/*
10장1절 [ 문제 1 ][레벨 0] 사용자로부터 공백을 포함하지 않는 문자열을 입력 받은 후 소문자만
출력하는 프로그램을 작성하시오.
 - 입력 받는 문자열 길이는 최대 20 이다.
*/

#include<stdio.h>

int main() {

	char str[20];
	int i;
	scanf("%s", str);
	for (i = 0; str[i]; i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			printf("%c", str[i]);

	return 0;
}

/*
10장3절 [ 문제 2 ][레벨 0] 임의의 정수를 입력으로 받아, 정수를 한 자리씩 문자로 변환시켜, 마
지막 자릿수부터 차례로 문자 배열에 저장한 후 출력하는 프로그램을 작성 하시오. 
▶ 출력 시 문자열 출력 %s 를 사용한다. (%c 사용금지) 
- 입력 받는 숫자는 최대 9 자리 수이다.
*/

#include<stdio.h>

int main() {

	char arr[9];
	char temp;
	int leng = 0;

	scanf("%s", arr, 9);

	while (arr[leng] != '\0')
		leng++;

	for (int i = 0; i < leng / 2; i++) {
		temp = arr[i];
		arr[i] = arr[leng - i - 1];
		arr[leng - i - 1] = temp;
	}

	printf("%s\n", arr);

	return 0;
}

/*
10장3절 [ 문제 3 ][레벨 0] 사용자로부터 공백을 포함하지 않는 문자열을 하나 입력 받아 예제와
같이 한 칸씩 미루며 출력하는 프로그램을 작성 하시오. 
- 입력 받는 문자열 길이는 최대 100 이다. 
▶ 출력 시 문자열 출력을 사용한다. (%c 사용금지)
*/

#include<stdio.h>

int main() {

	char arr[100], tmp;
	int i, j, cnt = 0;
	scanf("%s", arr, 100);
	while (arr[cnt] != '\0')
		cnt++;

	for (i = 0; i < cnt; i++) {
		printf("%s\n", arr);
		tmp = arr[0];
		for (j = 0; j < cnt; j++)
			arr[j] = arr[j + 1];
		arr[cnt - 1] = tmp;
	}

	return 0;
}

/*
10장3절 [ 문제 4 ][레벨 0] 사용자로부터 공백을 포함하지 않는 문자열 2개를 받아서, 이들 문자
열이 일치하는지를 검사하는 프로그램을 작성하시오.
 - 단, 표준 문자열 처리 함수 strlen( )와 strcmp( ) 사용금지
 - 입력 받는 2개의 문자열 길이는 최대 100이다. - 첫 번째 문자열의 길이를 출력하고, 일치하면 1 불일치하면 0을 출력하시오.
*/

#include<stdio.h>

int main() {

	char str1[100], str2[100];
	char *p1 = str1, *p2 = str2;
	int i, cnt = 0, flag = 0;
	scanf("%s", str1, 100);
	getchar();
	scanf("%s", str2, 100);

	while (str1[cnt] != '\0')
		cnt++;
	printf("%d", cnt);

	for (i = 0; i < cnt; i++)
		if (str1[i] == str2[i])
			flag++;
	if (flag == cnt)
		printf(" 1");
	else
		printf(" 0");

	return 0;
}

/*
10장3절 [ 문제 5 ][레벨 1] 사용자에게 공백을 포함하지 않는 영문 문자열 str1, str2와 삽입 위치
를 입력 받은 후, str1의 해당 위치에 str2를 삽입하는 프로그램을 작성하시오. - 입력 받는 각각의 문자열 길이는 최대 20 이다. 
- 삽입 위치는 str1의 길이 보다 항상 작거나 같다. 
- 삽입 위치 0은 첫 번째 위치에 삽입하라는 의미이다. (0, 1, 2, ...) 
- str1, str2 이외의 문자열을 선언하지 않고, str1에 결과를 저장 후 출력한다. 
▶ 출력 시 문자열 출력을 사용한다. (%c 사용금지)
*/

#include<stdio.h>

int main() {

	char str1[100], str2[100];
	int i, pos, cnt1 = 0, cnt2 = 0;
	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%d", &pos);
	while (str1[cnt1] != '\0')
		cnt1++;
	while (str2[cnt2] != '\0')
		cnt2++;

	for (i = cnt1 + cnt2; i >= cnt2 + pos; i--)
		str1[i] = str1[i - cnt2];

	for (i = 0; i < cnt2; i++) {
		str1[pos + i] = str2[i];
	}
	printf("%s", str1);

	return 0;
}

/*
10장3절 [ 문제 6 ][레벨 1] 앞의 [ 문제 5 ]에서 str2의 반전 여부를 추가로 입력 받은 후 입력값
에 따라 정순 또는 역순으로 문자열을 삽입하는 프로그램을 작성하시오. 
 - [ 문제 5 ]의 제한조건을 따른다.
 0: 정순 삽입, 1: 역순 삽입
▶ 출력 시 문자열 출력을 사용한다. (%c 사용금지)
*/

#include<stdio.h>

int main() {

	char str1[100], str2[100], tmp;
	int i, pos, inv = 0, order, cnt1 = 0, cnt2 = 0;
	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%d", &pos);
	scanf("%d", &order);

	while (str1[cnt1] != '\0')
		cnt1++;
	while (str2[cnt2] != '\0')
		cnt2++;

	if (order == 1) {
		for (i = 0; i < cnt2 / 2; i++) {
			tmp = str2[i];
			str2[i] = str2[cnt2 - i - 1];
			str2[cnt2 - i - 1] = tmp;
		}
	}

	for (i = cnt1 + cnt2; i >= cnt2 + pos; i--)
		str1[i] = str1[i - cnt2];

	for (i = 0; i < cnt2; i++) {
		str1[pos + i] = str2[i];
	}
	printf("%s", str1);

	return 0;
}

/*
10장3절 [ 문제 7 ][레벨 2] 사용자로부터 정수 N을 입력받아 그 값을 표현하는 문자열로 출력하
는 프로그램을 작성하시오. 
- 단, 10000 보다 작은 정수를 입력하시오
- 표기는 다음과 같다. ◦ 숫자 영어 표기: one two three four five six seven eight nine
◦ 십진수 자릿수 표기: 천 THO 백 HUN 십 TEN (일자리에는 숫자만 출력)
◦ 숫자 영에 해당하는 자릿수와 숫자 0은 출력하지 않는다.
*/

#include<stdio.h>

int main() {

	char eng[9][6] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char ten[4][4] = { "THO", "HUN", "TEN", "" };
	int i, n, cnt = 0, m, inv[5], x[5] = { 0 };

	scanf("%d", &n);
	m = n;
	while (m > 0) {
		inv[cnt++] = m % 10;
		m /= 10;
	}

	for (i = 0; i < cnt; i++)
		x[i] = inv[cnt - i - 1];

	for (i = 0; i < 4; i++) {
		if (x[i] != 0) {
			printf("%s ", eng[x[i] - 1]);
			printf("%s ", ten[4 - cnt + i]);
		}
	}

	return 0;
}

/*
10장4절 [ 문제 8 ][레벨 1] 두 개의 공백을 포함하지 않는 문자열을 scanf( ) 명령으로 읽어서, 두
문자의 크기(사전적 순서)를 비교 한 후, 크기가 큰 문자열 뒤에 크기가 작은 문자열이 오도록 연
결된 문자열을 만들고 출력하는 프로그램을 작성 하시오. 즉 사전의 역순. 
- 입력 문자열의 길이는 각각 최대 50 이다. 
- 입력 문자열은 소문자로만 구성된다. 
- 문자열 처리 표준 함수를 사용해도 됨.
*/

#include<stdio.h>

int main() {

	char str1[50], str2[50];
	int i, j;
	scanf("%s", str1);
	getchar();
	scanf("%s", str2);

	i = 0;
	while (1) {
		if (str1[i] > str2[i]) {
			printf("%s%s", str1, str2);
			break;
		}
		else if (str1[i] < str2[i]) {
			printf("%s%s", str2, str1);
			break;
		}
		else
			i++;
	}

	return 0;
}

/*
10장4절 [ 문제 9 ][레벨 1] 사용자로부터 공백을 포함하지 않는 문자열 하나를 입력 받아, 입력
받은 문자열의 회문 여부를 판단하는 프로그램을 작성하시오. 
- 회문이란 앞으로 읽어도 뒤로 읽어도 동일한 영어 단어를 의미한다. eve, level, madam, radar,
peep 등이 있다.
- check 함수를 정의하여 사용하시오.
◦ 인자: 문자열의 시작주소를 나타내는 포인터 변수
◦ 회문 여부를 판단한다.
◦ 대문자, 소문자 구별함 (즉 같은 문자이지만 대문자, 소문자인 경우 서로 다른 문자로 판단
함)
◦ 반환 값: 회문일 경우에는 정수 1, 회문이 아닐 경우에는 정수 0 을 반환한다.
- main 함수의 내용은 다음과 같다.
◦ 문자열 하나를 입력 받는다.
◦ 입력 받는 문자열의 길이는 최대 30 이다.
◦ 입력 받는 문자열의 길이를 출력한다.
◦ check 함수를 호출하여 입력 받은 문자열이 회문 여부를 판단하고 회문일 경우에는 1, 회
문이 아닐 경우에는 0 을 출력한다.
- 문자열 길이를 구하는 표준 문자열 함수를 사용해도 됨.
*/

#include<stdio.h>

int main() {

	char str[30], inv[30];
	int i, flag = 0, n = 0;
	scanf("%s", str);

	while (str[n] != '\0')
		n++;

	for (i = 0; i < n; i++)
		inv[i] = str[n - i - 1];
	for (i = 0; i < n; i++)
		if (str[i] == inv[i])
			flag++;

	if (flag == n)
		printf("%d 1", n);
	else
		printf("%d 0", n);

	return 0;
}

/*
10장5절 [ 문제 10 ][레벨 1] 사용자로부터 N 줄의 공백을 포함하는 문자열을 읽어서 이 중 가장
길이가 작은 공백을 포함하는 문자열을 출력하는 프로그램을 작성하시오. 문자열의 길이는 최대
100 이다. 
- N은 최대 100 이다.
- 표준 문자열 처리 함수를 사용해도 됨.
▶ 출력 시 문자열 출력을 사용한다. (%c 사용금지)
*/

#include<stdio.h>
#include<string.h>

int main() {

	int n, i, min = 100, len;
	char str[100][100], minstr[100] = { 0 };

	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		gets(str[i]);
		len = strlen(str[i]);
		if (len < min) {
			min = len;
			strcpy(minstr, str[i]);
		}
	}

	printf("%s", minstr);

	return 0;
}

/*
10장4절 [ 문제 11 ][레벨 2] 공백을 포함하지 않는 문자열 str1과 str2 두 개를 입력 받는다.
- 첫 번째 문자열의 길이를 출력하고, str2가 str1에 포함되어 있는 문자열이면 1을, 포함되어 있
지 않는 경우라면 0을 출력하시오.
- 입력 받는 str1의 문자열 길이는 최대 80 이다.
- 입력 받는 str2의 문자열 길이는 최대 10 이다.
- 표준 문자열 처리 함수 중에서 strlen 만 사용가능함.
*/

#include<stdio.h>

int main() {

	char str1[80], str2[10];
	int i, j, len1, len2, cnt = 0, flag;

	scanf("%s", str1);
	scanf("%s", str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	for (i = 0; i < len1; i++)
		for (j = 0; j < len2; j++) {
			if (str1[i + j] == str2[j])
				cnt++;
		}

	if (cnt < len2)
		flag = 0;
	else
		flag = 1;

	printf("%d %d", len1, flag);

	return 0;
}