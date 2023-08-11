/*�������ʽ����һ���������ʽ��ָ����С��������*/
void TidyPolynomial(LinkList *L) {
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
