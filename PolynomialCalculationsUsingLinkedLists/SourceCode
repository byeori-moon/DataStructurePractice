#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct listNode* polyPointer;
typedef struct listNode{
	int coef;
	int exp;
	polyPointer link;
} listNode;

void attach(int coefficient, int exponent, polyPointer *ptr) {
	polyPointer temp= malloc(sizeof(*temp));
	temp->coef = coefficient;
	temp->exp = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}

main() {

	for (int t = 0; t < 3; t++) {
		int A[10] = { 0, };
		int B[10] = { 0, };
		int a, b;
		

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

		polyPointer D = NULL;
		polyPointer rear=malloc(sizeof(*rear));
		D = rear;

		for (int k = 18; k > 9; k--) {//D(x) 안의 항의 지수가 9 초과일 경우
			int coef = 0;
			int exp = -1;
			for (int i = 9; i>=0; i--) {
				if (k - i < 10 && A[i] != 0 && B[k - i] != 0) {
					coef += A[i] * B[k - i];
					int exp = k;
				}
			}
			if (exp!=-1&&coef!=0) {
				attach(coef, exp, &rear);
			}
		}

		for (int k = 9; k >= 0; k--) {//D(x) 안의 항의 지수가 9 이하일 경우
			int coef = 0;
			int exp = -1;
			for (int i = k; i >= 0; i--) {
				if (A[i] != 0 && B[k - i] != 0) {
					coef += A[i] * B[k - i];
					exp = k;
				}
			}
			if (exp!=-1&&coef!=0) {
				attach(coef,exp,&rear);
			}
		}
		rear->link = NULL;
		D = D->link;

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
		for (int i=0;D;D=D->link,i++) {//D(x) 출력
			int coef = D->coef;
			int exp = D->exp;
			if (coef > 0 &&i!=0) {
				printf("+");
			}
			printf("%dx%d", D->coef, D->exp);
		}
	}
	
}

