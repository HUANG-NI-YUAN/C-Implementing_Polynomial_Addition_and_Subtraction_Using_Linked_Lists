/*������ʽ���*/
void TwoPolynomialMul(LinkList L1, LinkList L2) {
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
    TidyPolynomial(&L3);//�������ʽ
    printf("\n������ʽ��˽����");
    PrintPolynomial(L3);
}
