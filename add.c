/*������ʽ���*/
extern struct Node *LinkList;
void TwoPolynomialAdd(struct Node *LinkList L1, struct Node *LinkList L2) {
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
    TidyPolynomial(&L3);//����L3����ʽ
    printf("\n������ʽ��ӽ����");
    PrintPolynomial(L3);
}
