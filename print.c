/*�������ʽ��������ʽָ����С�������ÿһ��*/
void PrintPolynomial(LinkList L) {
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
