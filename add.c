/*两多项式相加*/
extern struct Node *LinkList;
void TwoPolynomialAdd(struct Node *LinkList L1, struct Node *LinkList L2) {
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
    TidyPolynomial(&L3);//整理L3多项式
    printf("\n两多项式相加结果：");
    PrintPolynomial(L3);
}
