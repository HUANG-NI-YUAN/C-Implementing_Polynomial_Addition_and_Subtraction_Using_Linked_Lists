/*正位序输入n个元素的值，建立带表头结点的单链线性表（尾插法）*/
/*创建多项式：由用户输入多项式的每项系数与指数*/
void CreateListTail(LinkList *L) {
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
    TidyPolynomial(L);
}
