/*������ʽ���*/
void TwoPolynomialSub(LinkList L1, LinkList L2) {
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
    TidyPolynomial(&L3);//�������ʽ
    printf("\n������ʽ��������");
    PrintPolynomial(L3);
}
