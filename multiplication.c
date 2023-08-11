/*两多项式相乘*/
void TwoPolynomialMul(LinkList L1, LinkList L2) {
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
    TidyPolynomial(&L3);//整理多项式
    printf("\n两多项式相乘结果：");
    PrintPolynomial(L3);
}
