#include <stdio.h>

int main() {


	int x[100], i, j, input, max, standard, tmp = 0, cnt = 0, ch[100];

	scanf("%d", &input);

	for (i = 0; i < input; i++) {
		scanf("%d", &x[i]);
	}

	standard = x[input - 1];
	max = x[0];
	printf("standard: %d\n", standard);
	printf("max: %d\n", max);

	for (i = 0; i < input; i++) {
		ch[i] = standard - x[i];
		if (ch[i] < 0)
			ch[i] = -ch[i];
	}

	for (i = 0; i < input - 1; i++)

			

	printf("ch: ");
	for (i = 0; i < input; i++)
		printf("%d ", ch[i]);
	printf("\n");

	printf("%d\n", max);


	return 0; 
}