/*输出多项式，按多项式指数大小依次输出每一项*/
void PrintPolynomial(LinkList L) {
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
