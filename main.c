#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0


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

/*�������ʽ����һ���������ʽ��ָ����С��������*/
void Tidy_Polynomial(LinkList *L) {
    Node *pre_p, *p, *pre_same, *same;

    /*�ϲ�ͬ����*/
    pre_p = *L;//pre_pΪp��ǰ�����
    p = (*L)->next;
    while (p) {
        pre_same = p;//pre_sameΪsame��ǰ��
        same = p->next;//sameΪҪ��p�ȽϵĽ��
        while (same)//ɨ��p���֮��Ľ��
        {
            if (same->data.exponential == p->data.exponential)//�������p��ָͬ���Ķ���ʽ����ϲ�����
            {
                p->data.coefficient += same->data.coefficient;//ϵ�����
                pre_same->next = same->next;//ɾ��same���
                free(same);
            } else//����ָͬ������same��ǰ��ָ�����
                pre_same = pre_same->next;

            same = pre_same->next;//��λsameΪpre_same�ĺ�̽��
        }

        /*ɾ��ϵ����Ϊ0�Ľ��*/
        if (p->data.coefficient == 0)//����������ϲ���ϵ��Ϊ0����ɾ���ý��
        {
            pre_p->next = p->next;
            free(p);
        } else//����Ϊ0����pre_pָ�����
            pre_p = pre_p->next;

        p = pre_p->next;//pָ�붨λΪpre_p���ĺ��
    }

    /*ʹ��ð�����򷽷�����ָ�����С��������*/
    Node *tail;//pre_pΪp��ǰ��
    tail = NULL;//tailΪ���һ�����
    while ((*L)->next != tail) {
        pre_p = *L;//��λpre_pΪp��ǰ��
        p = (*L)->next;
        while (p->next != tail)//���pδ���е����ź���Ĳ��֣������ѭ��
        {
            if (p->data.exponential > p->next->data.exponential)//���p��ָ����p�ĺ�̵�ָ�����򽻻�p��p�ĺ�̵�λ��
            {
                pre_p->next = p->next;
                p->next = pre_p->next->next;
                pre_p->next->next = p;
            } else//���޽�����pָ��ֱ�Ӻ���
                p = p->next;

            pre_p = pre_p->next;//pre_pָ�����p������
        }
        tail = p;//βָ���Ϊ�ź���Ĳ���
    }
}

/*��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�β�巨��*/
/*��������ʽ�����û��������ʽ��ÿ��ϵ����ָ��*/
void Create_ListTail(LinkList *L) {
    Node *p, *r;
    InitList(L);/*�Ƚ���һ����ͷ���Ŀ�����*/
    r = *L;/*rΪָ��β���Ľ��ָ�룬��βָ��*/
    int i = 0;//������
    while (TRUE) {
        p = (Node *) malloc(sizeof(Node));/*�����½��*/
        printf("\n�������%d���ϵ����ָ��,����-1 -1�������룺", ++i);
        scanf("%d%d", &(p->data.coefficient), &(p->data.exponential));//������Ԫ��ֵ�����½��*p��������
        if (p->data.exponential != -1)//�ж��Ƿ��������
        {
            r->next = p;/*����β�ն˽���ָ��ָ���½�㣬�����½��*p����β���*r֮��*/
            r = p;/*rָ���µ�β���*p��������ǰ���½�㶨��Ϊ��β�ն˽��*/
        } else {
            free(p);//�ͷ����ý��
            break;
        }
    }
    r->next = NULL;/*��ǰ���������*/
    Tidy_Polynomial(L);
}

/*�������ʽ��������ʽָ����С�������ÿһ��*/
void Print_Polynomial(LinkList L) {
    Node *p;
    p = L->next;
    printf("����ʽΪ:");

    /*��һ��ϵ��Ϊ��������Ӻ�*/
    if (p->data.exponential == 0)//ָ��Ϊ0�����x
        printf("%d", p->data.coefficient);
    else if (p->data.exponential == 1)//ָ��Ϊ1�������ָ����
        if (p->data.coefficient == 1)//ϵ��Ϊ1�����x�����ϵ��
            printf("x");
        else
            printf("%dx", p->data.coefficient);
    else //��һ��ָ�������1���������ָ����
        if (p->data.coefficient == 1)//ָ����Ϊ0��1�����ָ����ϵ����Ϊ1�����ϵ��
            printf("x^%d", p->data.exponential);
        else
            printf("%dx^%d", p->data.coefficient, p->data.exponential);
    p = p->next;

    /*�ڶ����ָ����Ϊ1�����ָ��*/
    if (p->data.exponential == 1)//�ж�ָ���Ƿ�Ϊ1,���������ָ��Ϊ1*/
        if (p->data.coefficient == 1)//�����ϵ��Ϊ1
            printf("+x");
        else if (p->data.coefficient > 1)//��ϵ��Ϊ���Ҵ���1������Ӻ�
            printf("+%dx", p->data.coefficient);
        else
            printf("%dx", p->data.coefficient);
    else//�����������ָ��
        if (p->data.coefficient == 1)//�����ϵ��Ϊ1
            printf("+x^%d", p->data.exponential);
        else if (p->data.coefficient > 1)//��ϵ��Ϊ���Ҵ���1������Ӻ�
            printf("+%dx^%d", p->data.coefficient, p->data.exponential);
        else
            printf("%dx^%d", p->data.coefficient, p->data.exponential);
    p = p->next;

    /*������Ժ��ָ���������1���������ָ����*/
    while (p) {
        if (p->data.coefficient == 1)//��ϵ��Ϊ1�������ϵ��
            printf("+x^%d", p->data.exponential);
        else if (p->data.coefficient > 1)
            printf("+%dx^%d", p->data.coefficient, p->data.exponential);
        else
            printf("%dx^%d", p->data.coefficient, p->data.exponential);
        p = p->next;
    }
    printf("\n");
}

/*������ʽ���*/
void Polynomial_Add(LinkList L1, LinkList L2) {
    LinkList L3;
    Node *r, *p, *s;
    InitList(&L3);
    r = L3;//rָ��L3��β����ʹ��β�巨�����½��

    p = L1->next;//�Ƚ�L1�ڵĶ���ʽ���Ƶ�L3��
    while (p) {
        s = (Node *) malloc(sizeof(Node));
        s->data.coefficient = p->data.coefficient;
        s->data.exponential = p->data.exponential;
        r->next = s;//r�ĺ��ָ�������Ľ��
        r = s;//rָ�����һ��
        p = p->next;//pָ�����ָ����һ��
    }

    p = L2->next;//�ٽ�L2�Ķ���ʽ���Ʋ����뵽L3��
    while (p) {
        s = (Node *) malloc(sizeof(Node));
        s->data.coefficient = p->data.coefficient;//�˴�����ӹ�ֱ�Ӹ��Ƽ���
        s->data.exponential = p->data.exponential;
        r->next = s;//r�ĺ��ָ�������Ľ��
        r = s;//rָ�����һ��
        p = p->next;//pָ�����ָ����һ��
    }

    r->next = NULL;/*L3�������*/
    Tidy_Polynomial(&L3);//����L3����ʽ
    printf("\n������ʽ��ӽ����");
    Print_Polynomial(L3);
}

/*������ʽ���*/
void Polynomial_Sub(LinkList L1, LinkList L2) {
    LinkList L3;
    Node *r, *p, *s;
    InitList(&L3);
    r = L3;//rָ��L3��β��

    p = L1->next;//�Ƚ�L1�ڵĶ���ʽ���Ƶ�L3��
    while (p) {
        s = (Node *) malloc(sizeof(Node));
        s->data.coefficient = p->data.coefficient;
        s->data.exponential = p->data.exponential;
        r->next = s;//r�ĺ��ָ�������Ľ��
        r = s;//rָ�����һ��
        p = p->next;//pָ�����ָ����һ��
    }

    p = L2->next;//�ٽ�L2�Ķ���ʽȡ�෴�������뵽L3��
    while (p) {
        s = (Node *) malloc(sizeof(Node));
        s->data.coefficient = -1 * (p->data.coefficient);//�˴����������ϵ��ȡ�෴��
        s->data.exponential = p->data.exponential;
        r->next = s;//r�ĺ��ָ�������Ľ��
        r = s;//rָ�����һ��
        p = p->next;//pָ�����ָ����һ��
    }

    r->next = NULL;/*L3�������*/
    Tidy_Polynomial(&L3);//�������ʽ
    printf("\n������ʽ��������");
    Print_Polynomial(L3);
}

/*������ʽ���*/
void Polynomial_Mul(LinkList L1, LinkList L2) {
    LinkList L3;
    Node *p1, *p2, *r, *s;//p1ָ��L1��p2ָ��L2��rָ��L3��β����sΪ��ʱ���ָ��
    InitList(&L3);
    r = L3;//rΪL3��βָ�룬������β�巨���ɶ���ʽ

    /*L1ÿ����L2�����������*/
    p1 = L1->next;//��p1��λ��L1�ĵ�һ��
    while (p1) {
        p2 = L2->next;//ÿ�α任L1�����Ҫ���¶�λp2ָ��ָ��L2�ĵ�һ��
        while (p2) {
            s = (Node *) malloc(sizeof(Node));
            s->data.coefficient = p1->data.coefficient * p2->data.coefficient;//ϵ�����
            s->data.exponential = p1->data.exponential + p2->data.exponential;//ָ�����
            r->next = s;//r�ĺ��ָ�������Ľ��
            r = s;//rָ�����һ��
            p2 = p2->next;//p2ָ�����ָ��L2����һ��
        }
        p1 = p1->next;//p1ָ�����ָ��L1����һ��
    }

    r->next = NULL;/*L3�������*/
    Tidy_Polynomial(&L3);//�������ʽ
    printf("\n������ʽ��˽����");
    Print_Polynomial(L3);
}

/*����˵��������û�ѡ��Ĳ���*/
int Menu() {
    int a;
    printf("����1������������ʽ\t\t����2����������ʽ���\n");
    printf("����3����������ʽ��� \t\t����4����������ʽ���\n");
    printf("����5�����������ʽ \t\t����0�˳�\n");
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
                Create_ListTail(&L1);
                printf("\n����ʽ 1 Ϊ��\n");
                Print_Polynomial(L1);
                printf("\n���������ʽ 2 ��");
                Create_ListTail(&L2);
                printf("\n����ʽ 2 Ϊ��\n");
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
                printf("\n����ʽ 1 Ϊ��\n");
                Print_Polynomial(L1);
                printf("\n����ʽ 2 Ϊ��\n");
                Print_Polynomial(L2);
                break;
            case 0:
                printf("ллʹ�ã�\n");
                exit(0);
            default:
                printf("���޴˹���\n");
        }
    }
}

