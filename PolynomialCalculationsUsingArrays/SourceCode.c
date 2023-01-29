#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

main() {
	for (int t = 0; t < 3; t++) {
		int A[10] = { 0, };
		int B[10] = { 0, };
		int a, b;

		typedef struct {
			int coef;
			int exp;
		} Term;
		Term D[8] = { 0 };


		printf("\nA(x)를 입력해주세요.");
		for (int i = 0; i < 3; i++) {//A(x)를 계수 배열로 저장
			scanf_s("%dx%d", &a, &b);
			A[b] = a;
		}

		printf("B(x)를 입력해주세요.");
		for (int i = 0; i < 3; i++) {//B(x)를 계수 배열로 저장
			scanf_s("%dx%d", &a, &b);
			B[b] = a;
		}

		int j = 0;//D(x)의 항 표현 위한 변수
		for (int k = 18; k > 9; k--) {//D(x) 안의 항의 지수가 9 초과일 경우
			for (int i = 9; i>=0; i--) {
				if (k - i < 10 && A[i] != 0 && B[k - i] != 0) {
					D[j].coef += A[i] * B[k - i];
					D[j].exp = k;
				}
			}
			if (D[j].exp == k) {
				j++;
			}
		}

		for (int k = 9; k >= 0; k--) {//D(x) 안의 항의 지수가 9 이하일 경우
			for (int i = k; i >= 0; i--) {
				if (A[i] != 0 && B[k - i] != 0) {
					D[j].coef += A[i] * B[k - i];
					D[j].exp = k;
				}
			}
			if (D[j].exp == k) {
				j++;
			}
		}

		printf("\nA(x)=");
		for (int i = 0; i < 10; i++) {
			printf("%dx%d", A[i], i);
			if (A[i + 1] >= 0) {
				printf("+");
			}
		}
		printf("\nB(x)=");
		for (int i = 0; i < 10; i++) {
			printf("%dx%d", B[i], i);
			if (B[i + 1] >= 0) {
				printf("+");
			}
		}

		printf("\nD(x)=");
		for (int i = 0; D[i].coef != 0; i++) {//D(x) 출력
			printf("%dx%d", D[i].coef, D[i].exp);
			if (D[i + 1].coef > 0) {
				printf("+");
			}
		}
	}
}
