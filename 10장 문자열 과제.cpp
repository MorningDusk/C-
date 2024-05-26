/*
[ 문제 1-2 ][레벨 2] (100점) 두 개의 문자열(A, B)을 입력받아 위의 [문제 1-1] 규칙대로 A→B 또
는 B→A로 변경할 수 있는지 확인하시오. 
- 변경불가능하면 0, A→B로 변경가능하면 1, B→A로 변경가능하면 2, 둘 다 가능하면 3을 출
력하시오. 
- (설명) 즉, 정수 N을 이용하여 A→B로 변경가능하면 1을 출력한다.
*/

#include <stdio.h>
#include <string.h>

int change(char ch[], char b[]) {
	char ch2[201], t;
	int n, i, l, j = 0, k, l2, flag;
	l = strlen(ch);
	l2 = strlen(b);

	for (n = 1; n <= 10; n++) {
		flag = 0;
		j = 0;
		for (i = 0; i < l; i++) {
			if (ch[i] >= 'A' && ch[i] <= 'Z') {
				ch2[j] = ch[i] + n;
				j++;
			}
			else if (ch[i] >= 'a' && ch[i] <= 'z') {
				ch2[j] = ch[i] - n;
				j++;
			}
			else if (ch[i] >= '0' && ch[i] <= '9') {
				if (i + 1 < l && (ch[i + 1] >= '0' && ch[i + 1] <= '9')) {
					t = 'A' - l + (ch[i] - '0') * 10 + ch[i + 1] - '0';
					for (k = 0; k < n; k++) {
						ch2[j] = t;
						j++;
					}
					i++;
				}
				else {
					t = 'A' - 1 + ch[i] - '0';
					for (k = 0; k < n; k++) {
						ch2[j] = t;
						j++;
					}
				}
			}
			else {
				ch[j] = ' ';
				j++;
			}
		}
		ch2[j] = '\0';
		if (j == l2) {
			for (i = 0; i < l2; i++)
				if (ch2[i] != b[i]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				break;
		}
		else {
			flag = 1;
			continue;
		}
	}
	if (flag == 0)
		return 1;
	else if (flag == 1)
		return 0;
}

int main() {

	char A[201], B[201];
	int a, b;
	gets_s(A, 201);
	gets_s(B, 201);
	a = change(A, B);
	b = change(A, B);

	if (a == 1 && b == 1)
		printf("3");
	else if (a == 1 && b == 0)
		printf("1");
	else if (a == 0 && b == 1)
		printf("2");
	else if (a == 0 && b == 0)
		printf("0");


	return 0;
}

/*
[ 문제 2-3 ][레벨 2] (100점) 공백을 포함하는 하나의 문장을 입력받고, 이를 단어 단위로 분리하
여 출력하고, 단어 중에서 사전에서 가장 앞에 나오는 단어를 찾아서 출력하시오. 
- 문장을 단어 단위로 분리하기 위해 이중 배열을 사용한다. (위반 시 50% 감점) 
- 단어 단위로 분리하기 위해 strtok 함수를 사용하지 않는다. (위반 시 50% 감점) 
- 표준 문자열 처리함수 사용 가능하다. (단 strtok 함수를 제외한다) 
- 문장을 입력받기 위해 gets 함수를 활용한다. 
- 단어의 개수는 최대 10개이고, 각 단어의 최대길이는 (널 문자 포함하여) 100 이다
*/

#include <stdio.h>
#include <string.h>

int main() {

	char ch[100], str[10][100], tmp[100] = { 0 };		//문자열 선언
	int i, j = 0, k = 0, len = 0;		//변수 선언
		
	gets_s(ch, 100);		//문자열 입력

	for (i = 0; i < strlen(ch); i++) {		//문자열 길이 내
		if (ch[i] != ' ')		//공백이 아니라면
			str[j][k++] = ch[i];		//이중문자열로 옮긴다
		else if (ch[i] == ' ') {		//공백이라면
			str[j][k] = '\0';		//끝을 널 문자로 치환한다
			j++;		//j를 1 증가시킨다
			k = 0;		//k의 값을 초기화한다
		}
	}

	str[j][k] = '\0';		//이중문자열 끝을 널 문자로 치환한다
	k = 0;		

	for (i = 0; i <= j; i++)	//각 단어들을
		puts(str[i]);		//출력한다

	for (len = 0; len <= j; len++) {		//문자열 사전 순으로 정렬한다
		for (i = 0; i < j; i++) {		
			if (strcmp(str[i], str[i + 1]) > 0) {		//사전에서 앞서는 경우
				strcpy(tmp, str[i]);		//단어를
				strcpy(str[i], str[i + 1]);		//바꾼다
				strcpy(str[i + 1], tmp);
			}
		}
	}
	puts(str[0]);		//사전순 가장 앞에 있는 단어 출력

	return 0;
}

/*
[ 문제 3-2 ][레벨 2] (100점) 문자열 1에서 문자열 2와 정확하게 일치하는 단어의 개수를 출력하
시오. 즉 단어 속에 있는 단어가 아닌 독립된 단어로, 일치하는 단어의 개수를 출력하시오. 
1) 사용자로부터 문자열을 두 번에 걸쳐 입력받는다. 
2) 각 문자열의 전체 길이는 (널 문자 포함하여) 100을 넘지 않는다.
*/

#include <stdio.h>
#include <string.h>

int main() {

	char eng1[101] = { 0 }, eng2[101] = { 0 }, eng3[101] = { 0 };		//문자열 선언
	int i, j = 0, cnt = 0;		//변수 선언

	gets_s(eng1, 101);		//문자열 1 입력
	gets_s(eng2, 101);		//문자열 2 입력

	for (i = 0; i < 100; i++) {		//문자열 끝까지 조사
		if (eng1[i] == ' ' || eng1[i] == '.' || eng1[i] == '\0') {		//공백이거나 맡침표나 널 문자일 경우
			eng3[j] = '\0';		//처음을 널 문자로 초기화
			j = 0;		//0으로 초기화
			if (strcmp(eng3, eng2) == 0)		//단어가 일치할 경우
				cnt++;		//cnt 변수에 1 더한다
		}
		else		//단어일 경우
			eng3[j++] = eng1[i];		//단어를 저장한다
		if (eng1[i] == NULL)		//널일 경우
			break;		//반복문 종료
	}
	printf("%d", cnt);		//값 출력

	return 0;
}

/*
[ 문제 4-3 ][레벨2] (100점) ‘+’, ‘-’, ‘*’, ‘/’ 기호를 사용한 사칙연산 계산기 프로그램을 작성하시
오.
I) 사용자로부터 공백이 포함된 문자열을 한 번에 입력받는다. 문자열에는 숫자, 사칙연산 기호, 공백만 포함될 수 있다. (괄호 ‘(’, ‘)’는 사용하지 않음.)
2) 연산에 사용하는 숫자는 음이 아닌 정수이다. (단, 출력은 계산에 따라 실수값이 나올 수 있음. 예를 들면, 3/2=1.500000.)
3) 문자열의 전체 길이는 100을 넘지 않도록 하고, 연산에 사용하는 숫자의 개수는 10개 이내로
한다. 
4) ‘*’와 ‘/’는 사칙연산의 규칙에 따라 ‘+’와 ‘-’보다 우선적으로 계산되어야 한다. (예를 들면, 2+4*3=14.)
5) 출력에 사용하는 서식 지정자로는 ‘%lf’를 사용한다.
*/

#include <stdio.h>
#include <string.h>

int main() {

	int i = 0;		//변수 선언
	int ind = 0, arrind = -1;		//배열 위한 변수 선언
	int OperatorType = 0;		//기호 변수 선언
	double dnum = 0, dnum2 = 0;		//실수 선언
	double dnumArray[10] = { 0 };		//실수 배열 선언
	double dresult = 0.0;		//결과 실수 선언
	char strinput[100];		//문자열 선언

	gets_s(strinput, 100);		//숫자와 사칙연산 기호 입력
		
	OperatorType = '+';		//기호가 있을 경우
	while (strinput[ind] != '\0') {		//널 문자가 아닐 때
		dnum = 0;		//0으로 초기화
		while ((strinput[ind] >= '0' && strinput[ind] <= '9') || strinput[ind] == ' ') {		//문자가 숫자나 공백일 때
			if (strinput[ind] != ' ')		//공백이 아닐 때까지
				dnum = dnum * 10 + (int)strinput[ind] - '0';		//정수로 변경
			ind++;		//ind 변수에 1 더한다
		}

		switch (OperatorType) {		//기호 변수 구분
		case '+':		//덧셈일 경우
			dnumArray[++arrind] = dnum;		//수를 더한다
			break;		//종료
		case '-':		//뻴셈일 경우
			dnumArray[++arrind] = -dnum;		//수를 뺀다
			break;		//종료
		case '*':		//곱셈일 경우
			dnumArray[arrind] *= dnum;		//수를 곱한다
			break;		//종료
		case '/':		//나눗셈일 경우
			dnumArray[arrind] /= dnum;		//수를 나눈다
			break;		//종료
		}
		OperatorType = strinput[ind];		//기호를 이용한 결과값을 넣는다
		ind++;		//ind 변수에 1 더한다
	}

	dresult = 0.0;		//0으로 초기화
	for (i = 0; i < arrind + 1; i++)
		dresult += dnumArray[i];		//결과값을 저장한다
	printf("%lf\n", dresult);		//결과값 출력

	return 0;
}