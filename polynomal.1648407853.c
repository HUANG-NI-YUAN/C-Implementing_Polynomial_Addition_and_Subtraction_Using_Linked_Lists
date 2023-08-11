#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0

#include"add.c"
#include"create.c"
#include"minus.c"
#include"multiplication.c"
#include"print.c"
#include"sort.c"

typedef int Status;//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��
typedef struct Polynomial {
    int coefficient;//ϵ��
    int exponential;//ָ��
} ElemType;//�����������

/*���Ա�ĵ�����洢�ṹ*/
typedef struct Node {
    ElemType data;//������
    struct Node *next;//ָ����
} Node;//���

typedef struct Node *LinkList;//����LinkListͷָ�룬ָ��ͷ���

/*�������������һ���յ����Ա�L*/
Status InitList(LinkList *L) {
    *L = (LinkList) malloc(sizeof(Node));/*�½��½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���*/
    (*L)->next = NULL;/*ͷ����ָ�����ÿ�*/
    return OK;
}

/*����˵��������û�ѡ��Ĳ���*/
int Menu() {
    int a;
    printf("����1������������ʽ\t\t����2�����������ʽ\n");
    printf("����3����������ʽ��� \t\t����4����������ʽ���\n");
    printf("����5����������ʽ��� \t\t����0�˳�\n");
    printf("�����룺");
    scanf("%d", &a);
    return a;
}

int main() {
    LinkList L1, L2;
    while (1) {
        switch (Menu()) {
            case 1:
                printf("\n���������ʽ 1 ��");
                CreateListTail(&L1);
                printf("\n����ʽ 1 Ϊ��\n");
                PrintPolynomial(L1);
                printf("\n���������ʽ 2 ��");
                CreateListTail(&L2);
                printf("\n����ʽ 2 Ϊ��\n");
                PrintPolynomial(L2);
                break;
            case 2:
                printf("\n����ʽ 1 Ϊ��\n");
                PrintPolynomial(L1);
                printf("\n����ʽ 2 Ϊ��\n");
                PrintPolynomial(L2);
                break;
            case 3:
                TwoPolynomialAdd(L1, L2);
                break;
            case 4:
                TwoPolynomialSub(L1, L2);
                break;
            case 5:
                TwoPolynomialMul(L1, L2);
                break;
            case 0:
                printf("ллʹ�ã�\n");
                exit(0);
            default:
                printf("���޴˹���\n");
        }
    }
}
