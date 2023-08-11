#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0


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

/*整理多项式，将一个无序多项式按指数从小到大排序*/
void Tidy_Polynomial(LinkList *L) {
    Node *pre_p, *p, *pre_same, *same;

    /*合并同类项*/
    pre_p = *L;//pre_p为p的前驱结点
    p = (*L)->next;
    while (p) {
        pre_same = p;//pre_same为same的前驱
        same = p->next;//same为要与p比较的结点
        while (same)//扫描p结点之后的结点
        {
            if (same->data.exponential == p->data.exponential)//如果有与p项同指数的多项式，则合并两项
            {
                p->data.coefficient += same->data.coefficient;//系数相加
                pre_same->next = same->next;//删除same结点
                free(same);
            } else//若不同指数，则same的前驱指针后移
                pre_same = pre_same->next;

            same = pre_same->next;//定位same为pre_same的后继结点
        }

        /*删除系数项为0的结点*/
        if (p->data.coefficient == 0)//若出现两项合并后系数为0，则删除该结点
        {
            pre_p->next = p->next;
            free(p);
        } else//若不为0，则pre_p指针后移
            pre_p = pre_p->next;

        p = pre_p->next;//p指针定位为pre_p结点的后继
    }

    /*使用冒泡排序方法，将指数项从小到大排序*/
    Node *tail;//pre_p为p的前驱
    tail = NULL;//tail为最后一个结点
    while ((*L)->next != tail) {
        pre_p = *L;//定位pre_p为p的前驱
        p = (*L)->next;
        while (p->next != tail)//如果p未运行到已排好序的部分，则继续循环
        {
            if (p->data.exponential > p->next->data.exponential)//如果p的指数比p的后继的指数大，则交换p与p的后继的位置
            {
                pre_p->next = p->next;
                p->next = pre_p->next->next;
                pre_p->next->next = p;
            } else//若无交换则p指针直接后移
                p = p->next;

            pre_p = pre_p->next;//pre_p指针跟随p结点后移
        }
        tail = p;//尾指针后为排好序的部分
    }
}

/*正位序输入n个元素的值，建立带表头结点的单链线性表（尾插法）*/
/*创建多项式：由用户输入多项式的每项系数与指数*/
void Create_ListTail(LinkList *L) {
    Node *p, *r;
    InitList(L);/*先建立一个带头结点的空链表*/
    r = *L;/*r为指向尾部的结点指针，即尾指针*/
    int i = 0;//计数器
    while (TRUE) {
        p = (Node *) malloc(sizeof(Node));/*生成新结点*/
        printf("\n请输入第%d项的系数与指数,输入-1 -1结束输入：", ++i);
        scanf("%d%d", &(p->data.coefficient), &(p->data.exponential));//将输入元素值赋给新结点*p的数据域
        if (p->data.exponential != -1)//判断是否输入结束
        {
            r->next = p;/*将表尾终端结点的指针指向新结点，即将新结点*p插入尾结点*r之后*/
            r = p;/*r指向新的尾结点*p，即将当前的新结点定义为表尾终端结点*/
        } else {
            free(p);//释放无用结点
            break;
        }
    }
    r->next = NULL;/*当前链表创建完成*/
    Tidy_Polynomial(L);
}

/*输出多项式，按多项式指数大小依次输出每一项*/
void Print_Polynomial(LinkList L) {
    Node *p;
    p = L->next;
    printf("多项式为:");

    /*第一项系数为正不输出加号*/
    if (p->data.exponential == 0)//指数为0不输出x
        printf("%d", p->data.coefficient);
    else if (p->data.exponential == 1)//指数为1，不输出指数项
        if (p->data.coefficient == 1)//系数为1仅输出x不输出系数
            printf("x");
        else
            printf("%dx", p->data.coefficient);
    else //第一项指数项大于1，正常输出指数项
        if (p->data.coefficient == 1)//指数不为0或1，输出指数和系数不为1的项的系数
            printf("x^%d", p->data.exponential);
        else
            printf("%dx^%d", p->data.coefficient, p->data.exponential);
    p = p->next;

    /*第二项，若指数项为1则不输出指数*/
    if (p->data.exponential == 1)//判断指数是否为1,若是则不输出指数为1*/
        if (p->data.coefficient == 1)//不输出系数为1
            printf("+x");
        else if (p->data.coefficient > 1)//若系数为正且大于1，输出加号
            printf("+%dx", p->data.coefficient);
        else
            printf("%dx", p->data.coefficient);
    else//若不是则输出指数
        if (p->data.coefficient == 1)//不输出系数为1
            printf("+x^%d", p->data.exponential);
        else if (p->data.coefficient > 1)//若系数为正且大于1，输出加号
            printf("+%dx^%d", p->data.coefficient, p->data.exponential);
        else
            printf("%dx^%d", p->data.coefficient, p->data.exponential);
    p = p->next;

    /*第三项及以后的指数项均大于1，正常输出指数项*/
    while (p) {
        if (p->data.coefficient == 1)//若系数为1则不输出该系数
            printf("+x^%d", p->data.exponential);
        else if (p->data.coefficient > 1)
            printf("+%dx^%d", p->data.coefficient, p->data.exponential);
        else
            printf("%dx^%d", p->data.coefficient, p->data.exponential);
        p = p->next;
    }
    printf("\n");
}

/*两多项式相加*/
void Polynomial_Add(LinkList L1, LinkList L2) {
    LinkList L3;
    Node *r, *p, *s;
    InitList(&L3);
    r = L3;//r指向L3的尾部，使用尾插法插入新结点

    p = L1->next;//先将L1内的多项式复制到L3内
    while (p) {
        s = (Node *) malloc(sizeof(Node));
        s->data.coefficient = p->data.coefficient;
        s->data.exponential = p->data.exponential;
        r->next = s;//r的后继指向新增的结点
        r = s;//r指向最后一项
        p = p->next;//p指针后移指向下一项
    }

    p = L2->next;//再将L2的多项式复制并插入到L3后
    while (p) {
        s = (Node *) malloc(sizeof(Node));
        s->data.coefficient = p->data.coefficient;//此处是相加故直接复制即可
        s->data.exponential = p->data.exponential;
        r->next = s;//r的后继指向新增的结点
        r = s;//r指向最后一项
        p = p->next;//p指针后移指向下一项
    }

    r->next = NULL;/*L3创建完毕*/
    Tidy_Polynomial(&L3);//整理L3多项式
    printf("\n两多项式相加结果：");
    Print_Polynomial(L3);
}

/*两多项式相减*/
void Polynomial_Sub(LinkList L1, LinkList L2) {
    LinkList L3;
    Node *r, *p, *s;
    InitList(&L3);
    r = L3;//r指向L3的尾部

    p = L1->next;//先将L1内的多项式复制到L3内
    while (p) {
        s = (Node *) malloc(sizeof(Node));
        s->data.coefficient = p->data.coefficient;
        s->data.exponential = p->data.exponential;
        r->next = s;//r的后继指向新增的结点
        r = s;//r指向最后一项
        p = p->next;//p指针后移指向下一项
    }

    p = L2->next;//再将L2的多项式取相反数并插入到L3后
    while (p) {
        s = (Node *) malloc(sizeof(Node));
        s->data.coefficient = -1 * (p->data.coefficient);//此处是相减，故系数取相反数
        s->data.exponential = p->data.exponential;
        r->next = s;//r的后继指向新增的结点
        r = s;//r指向最后一项
        p = p->next;//p指针后移指向下一项
    }

    r->next = NULL;/*L3创建完毕*/
    Tidy_Polynomial(&L3);//整理多项式
    printf("\n两多项式相减结果：");
    Print_Polynomial(L3);
}

/*两多项式相乘*/
void Polynomial_Mul(LinkList L1, LinkList L2) {
    LinkList L3;
    Node *p1, *p2, *r, *s;//p1指向L1，p2指向L2，r指向L3的尾部，s为临时结点指针
    InitList(&L3);
    r = L3;//r为L3的尾指针，即采用尾插法生成多项式

    /*L1每项与L2各项依次相乘*/
    p1 = L1->next;//将p1定位到L1的第一项
    while (p1) {
        p2 = L2->next;//每次变换L1的项都需要重新定位p2指针指向L2的第一项
        while (p2) {
            s = (Node *) malloc(sizeof(Node));
            s->data.coefficient = p1->data.coefficient * p2->data.coefficient;//系数相乘
            s->data.exponential = p1->data.exponential + p2->data.exponential;//指数相加
            r->next = s;//r的后继指向新增的结点
            r = s;//r指向最后一项
            p2 = p2->next;//p2指针后移指向L2的下一项
        }
        p1 = p1->next;//p1指针后移指向L1的下一项
    }

    r->next = NULL;/*L3创建完毕*/
    Tidy_Polynomial(&L3);//整理多项式
    printf("\n两多项式相乘结果：");
    Print_Polynomial(L3);
}

/*输出菜单并返回用户选择的操作*/
int Menu() {
    int a;
    printf("输入1创建两个多项式\t\t输入2将两个多项式相加\n");
    printf("输入3将两个多项式相减 \t\t输入4将两个多项式相乘\n");
    printf("输入5输出两个多项式 \t\t输入0退出\n");
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
                Create_ListTail(&L1);
                printf("\n多项式 1 为：\n");
                Print_Polynomial(L1);
                printf("\n请输入多项式 2 ：");
                Create_ListTail(&L2);
                printf("\n多项式 2 为：\n");
                Print_Polynomial(L2);
                break;
            case 2:
                Polynomial_Add(L1, L2);
                break;
            case 3:
                Polynomial_Sub(L1, L2);
                break;
            case 4:
                Polynomial_Mul(L1, L2);
                break;
            case 5:
                printf("\n多项式 1 为：\n");
                Print_Polynomial(L1);
                printf("\n多项式 2 为：\n");
                Print_Polynomial(L2);
                break;
            case 0:
                printf("谢谢使用！\n");
                exit(0);
            default:
                printf("暂无此功能\n");
        }
    }
}

