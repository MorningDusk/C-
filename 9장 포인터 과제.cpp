﻿/*
[ 문제 1-1 ][레벨 1] (50점) 입력될 줄 수에 해당하는 정수 N을 입력받는다. 각 줄에서 0 이 입력
될 때까지만 정수를 입력받는다. 각 줄에서 0 이후에는 숫자가 없다. 각 줄에서 0은 두 번째부터
입력될 수 있다. 각 줄에서 0을 제외한 최대값과 최소값을 출력하시오.
1) MAX( ) 함수 이용
- 인자: int형 배열 ar - 배열 표기 [ ] 사용금지
- 배열에서 최대값의 주소를 반환한다.
- 반환 값: int형 포인터 즉 주소
2) MIN( ) 함수 이용
- 인자: int형 배열 ar - 배열 표기 [ ] 사용금지
- 배열에서 최소값의 주소를 반환한다.
- 반환 값: 정수형
3) main 함수에서는
 - 사용자로부터 정수 N을 입력 받는다. 아래 과정을 N번 반복한다. ⚬사용자로부터 정수를 입력 받는다. 0이 되면 종료한다. 배열 ar의 크기는 100. ⚬MAX 함수를 호출한다. MIN 함수를 호출한다.
 ⚬두 함수에서 전달받은 정수를 화면에 출력한다.
 ⚬MAX 함수에서 전달받은 주소가 가리키는, 배열의 원소를 화면에 출력한다.
 ⚬MIN 함수에서 전달받은 주소가 가리키는, 배열의 원소를 화면에 출력한다. 
4) 함수 원형 선언을 하고, 함수들을 main 함수 아래에 작성하시오.
*/

#include<stdio.h>

int *MAX(int ar[]);		//MAX 함수 원형 선언
int *MIN(int ar[]);		//MIN 함수 원형 선언

int main() {		//메인 함수

	int n, ar[100];		//변수 선언
	scanf("%d", &n);		//줄 수 입력
	getchar();		//엔터키 제거
	int *par;		//포인터 변수 선언
	while (n != 0) {		//줄 수가 0으로 줄일때까지
		for (par = ar; par < ar + 100; par++) {		//배열의 최대 크기까지 반복
			scanf("%d", par);		//배열 내 원소 변수 입력
			if (*par == 0)		//0이 입력되면
				break;		//종료
		}
		int *pmax = MAX(ar);		//포인터 변수 선언 및 함수 불러오기
		int *pmin = MIN(ar);
		printf("%d %d\n", *pmax, *pmin);		//최대값 최소값 출력
		getchar();		//엔터키 제거
		n--;		//줄 수가 1 줄어든다
	}

	return 0;
}

int *MAX(int ar[]) {		//MAX 함수
	int *p, *pmax = ar;		//포인터 변수 선언
	for (p = ar; *p != 0; p++) {		//배열 내 수가 0이 아닐 때까지
		if (*p > *pmax)		//최대값보다 다음 수가 크면
			pmax = p;		//최대값 갱신
	}
	return pmax;		//최대값 주소 반환
}

int *MIN(int ar[]) {		//MIN 함수
	int *p, *pmin = ar;		//포인터 변수 선언
	for (p = ar; *p != 0; p++) {		//배열 내 수가 0이 아닐 때까지
		if (*p < *pmin)		//최소값보다 다음 수가 작으면
			pmin = p;		//최소값 갱신
	}
	return pmin;		//최소값 주소 반환
}

/*
[ 문제 2-1 ][레벨 1] (50점) 로또 번호를 입력하면 이의 유효성을 확인하는 프로그램을 작성하려
고 한다. 1~45까지의 숫자 6개를 입력 받은 후, 입력 결과에 중복되는 숫자가 존재하는 경우, 해
당 숫자와 그 숫자의 중복 횟수를 알려주는 프로그램을 작성하시오. 입력되는 숫자는 모두 1~45
사이라고 가정하며, 숫자가 출력되는 순서는 입력된 순서와 동일하다.
*/

#include<stdio.h>

int main() {

	int ar[6], cnt, flag = 0;		//변수 선언
	int *pa = ar, *pb = ar, *p = ar;		//포인터 변수 선언
	for (pa = ar; pa < ar + 6; pa++)		//배열 내 위치를 선정,
		scanf("%d", pa);		//배열 내 원소 삽입
	for (pa = ar; pa < ar + 6; pa++) {		//중복있는지 확인하기 위해
		cnt = 0;		//일단 cnt를 0으로 설정
		for (pb = ar; pb < ar + 6; pb++)
			if (*pa == *pb)		//중간에 만일 숫자가 겹칠 때
				cnt++;		//cnt는 늘어난다
		if (cnt > 1)		//1보다 많을 경우
			flag++;		//flag변수 1 증가
	}
	if (flag != 0) {		//flag가 0이 아닐 때
		for (pa = ar; pa < ar + 6; pa++) {		//배열을 검사
			pb = ar;		//포인터 변수 설정
			cnt = 0;		//중복 횟수는 0으로 설정
			while (pb < pa && *pa != *pb)		//중복이 아닐 때
				pb++;		//위치 1 증가
			for (p = ar; p < ar + 6; p++)		//배열 내
				if (*pa == *p)		//원소가 같으면
					cnt++;		//중복 1 증가
			if (pa == pb && cnt > 1)		//중복 횟수가 1보다 많으면
				printf("%d %d\n", *pa, cnt);		//출력
		}
	}
	else		//flag가 0일 때
		printf("0");		//0 출력

	return 0;
}

/*
[ 문제 3 ][레벨 2] (100점) 양의 정수 N을 입력받은 후, 그 다음 줄에 N개의 문자를 입력받는다. 입력되는 문자는 오직 영문자 혹은 0~9 사이의 문자들로만 구성된다. N개의 문자들 중에서 영문
자는 영문자끼리 합쳐서 출력하고, 0~9 사이의 숫자 문자들을 찾아 그들의 합을 출력하는 프로그
램을 작성하시오. 
- N은 100 이하의 양의 정수다.
*/

#include<stdio.h>

int main() {

	int n, num = 0, sum = 0;		//변수 선언
	char ch[100], *pch;		//문자 선언
	scanf("%d", &n);		//정수 입력
	getchar();		//엔터키 제거
	for (pch = ch; pch < ch + n; pch++)		//주소를 이용해 반복문 구현
		scanf("%c", pch);		//배열 내 문자 입력

	for (pch = ch; pch < ch + n; pch++) {		//배열 내 검사
		if ((*pch >= 'A' && *pch <= 'Z') || (*pch >= 'a' && *pch <= 'z'))		//배열 내 문자가 알파벳이면
			printf("%c", *pch);		//출력
	}
	printf("\n");		//엔터키 입력
	for (pch = ch; pch < ch + n; pch++) {		//배열 내 검사
		if (*pch >= '0' && *pch <= '9') {		//숫자가 있다면
			num = (*pch - '0') + num * 10;		//숫자를 만들어낸다
		}
		else {		//숫자가 아니면
			sum += num;		//합에 숫자를 더한다
			num = 0;		//숫자 정수 초기화
		}
	}
	printf("%d", sum + num);		//합 출력

	return 0;
}

/*
[ 문제 4 ][레벨 2] (100점) 두 개의 배열에 정수를 입력 받고 이를 적절히 정렬하는 프로그램을
작성한다. 
- 두 개의 배열 a와 b에 각각 정수를 n개와 m개 입력 받는다.
- 각 배열에 숫자를 입력 받을 때는 0이 들어오기 전까지만 입력 받으며, n과 m은 최소 1이고, 최대 10이다. 
- 입력되는 정수의 개수 n, m은 입력으로 주어지지 않으므로 계산해야 된다. - 배열 a에는 배열 a와 b에 저장된 정수들 중 가장 큰 n개를 내림차순으로 저장한다. 
- 배열 b에는 배열 a와 b에 저장된 정수들 중 가장 작은 m개를 오름차순으로 저장한다. * 단, 해당 프로그램이 적용될 시스템의 메모리 제한으로 인해 배열 a와 b 이외의 다른 배열은
 절대로 사용할 수 없다고 가정한다.
*/

#include<stdio.h>

int main() {
	// a와 b의 길이 n 과 m 선언
	int n = 0, m = 0;
	// 마지막에 0이 올수 있으므로 11까지 배열 구성
	int a[11], b[11];
	// 배열을 돌아줄 포인터
	int *p, *k;
	// 최대값 최소값 포인터 구성
	int *max, *min;
	// 최대 11번까지 입력받으면서
	for (p = a; p < a + 11; p++) {
		scanf("%d", p);
		// 0이 오면 멈춘다
		if (*p == 0) {
			break;
		}
		// a배열의 index 구하기
		n++;
	}
	// 마찬가지로 최대 11번까지 입력받으면서
	for (p = b; p < b + 11; p++) {
		scanf("%d", p);
		// 0이 오면 멈추고
		if (*p == 0) {
			break;
		}
		// b배열의 index 구한다.
		m++;
	}
	// a 배열을 내림차순하기 위하여 a 배열부터 돌면서
	for (p = a; p < a + n; p++) {
		// 우선 최대값을 a배열의 최초의 p라고 한 후
		max = p;
		// a배열을 돌며 최대값이 있으면 갱신해주고
		// 최대값을 갱신해서 제일 앞에 넣었으면 다음것부터 돌면 되므로 k=p에서 시작
		for (k = p; k < a + n; k++) {
			if (*k > *max) {
				max = k;
			}
		}
		// b배열을 돌며 최대값이 있으면 마찬가지로 갱신해준다.
		// b배열은 해당 a배열을 구성할 때 무조건적으로 모두 돌아줘야하므로 k=b에서 시작
		for (k = b; k < b + m; k++) {
			if (*k > *max) {
				max = k;
			}
		}
		// 최대값을 "주소가 아닌" 값으로 바꿔준다.
		int tmp = *p;
		*p = *max;
		*max = tmp;
		// n번 반복해준다.
	}
	// a 배열을 모두 구성하면 b 배열은 a 배열을 볼 필요가 없으므로 b배열만 돌면서
	for (p = b; p < b + m; p++) {
		// 최소값은 b 배열의 최초의 p로 한 후
		min = p;
		// b배열을 돌며 최소값을 갱신해준다.
		for (k = p; k < b + m; k++) {
			if (*k < *min) {
				min = k;
			}
		}
		// 마찬가지로 주소가 아닌 값으로 바꿔준다.
		int tmp = *p;
		*p = *min;
		*min = tmp;
	}
	// a배열 출력
	for (p = a; p < a + n; p++) {
		printf("%d ", *p);
	}
	printf("\n");
	// b배열 출력
	for (p = b; p < b + m; p++) {
		printf("%d ", *p);
	}
}