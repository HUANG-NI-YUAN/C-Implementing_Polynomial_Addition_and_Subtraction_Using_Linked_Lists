/*��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�β�巨��*/
/*��������ʽ�����û��������ʽ��ÿ��ϵ����ָ��*/
void CreateListTail(LinkList *L) {
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
    TidyPolynomial(L);
}
