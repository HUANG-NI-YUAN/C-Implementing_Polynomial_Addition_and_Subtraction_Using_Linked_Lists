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

typedef int Status;//Status是函数的类型，其值是函数结果状态代码，如OK等
typedef struct Polynomial {
    int coefficient;//系数
    int exponential;//指数
} ElemType;//表的数据类型

/*线性表的单链表存储结构*/
typedef struct Node {
    ElemType data;//数据域
    struct Node *next;//指针域
} Node;//结点

typedef struct Node *LinkList;//定义LinkList头指针，指向头结点

/*操作结果：构造一个空的线性表L*/
Status InitList(LinkList *L) {
    *L = (LinkList) malloc(sizeof(Node));/*新建新结点作为头结点，用头指针L指向头结点*/
    (*L)->next = NULL;/*头结点的指针域置空*/
    return OK;
}

/*输出菜单并返回用户选择的操作*/
int Menu() {
    int a;
    printf("输入1创建两个多项式\t\t输入2输出两个多项式\n");
    printf("输入3将两个多项式相加 \t\t输入4将两个多项式相减\n");
    printf("输入5将两个多项式相乘 \t\t输入0退出\n");
    printf("请输入：");
    scanf("%d", &a);
    return a;
}

int main() {
    LinkList L1, L2;
    while (1) {
        switch (Menu()) {
            case 1:
                printf("\n请输入多项式 1 ：");
                CreateListTail(&L1);
                printf("\n多项式 1 为：\n");
                PrintPolynomial(L1);
                printf("\n请输入多项式 2 ：");
                CreateListTail(&L2);
                printf("\n多项式 2 为：\n");
                PrintPolynomial(L2);
                break;
            case 2:
                printf("\n多项式 1 为：\n");
                PrintPolynomial(L1);
                printf("\n多项式 2 为：\n");
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
                printf("谢谢使用！\n");
                exit(0);
            default:
                printf("暂无此功能\n");
        }
    }
}
