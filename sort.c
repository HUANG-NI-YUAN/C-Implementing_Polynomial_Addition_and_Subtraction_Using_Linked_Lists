/*整理多项式，将一个无序多项式按指数从小到大排序*/
void TidyPolynomial(LinkList *L) {
    Node *pre_p, *p, *pre_same, *same;

    /*合并同类项*/
    pre_p = *L;//pre_p为p的前驱结点
    p = (*L)->next;
    while (p) {
        pre_same = p;//pre_same为same的前驱
        same = p->next;//same为要与p比较的结点
        while (same)//扫描p结点之后的结点
        {
            if (same->data.exponential == p->data.exponential)//如果有与p项同指数的多项式，则合并两项
            {
                p->data.coefficient += same->data.coefficient;//系数相加
                pre_same->next = same->next;//删除same结点
                free(same);
            } else//若不同指数，则same的前驱指针后移
                pre_same = pre_same->next;

            same = pre_same->next;//定位same为pre_same的后继结点
        }

        /*删除系数项为0的结点*/
        if (p->data.coefficient == 0)//若出现两项合并后系数为0，则删除该结点
        {
            pre_p->next = p->next;
            free(p);
        } else//若不为0，则pre_p指针后移
            pre_p = pre_p->next;

        p = pre_p->next;//p指针定位为pre_p结点的后继
    }

    /*使用冒泡排序方法，将指数项从小到大排序*/
    Node *tail;//pre_p为p的前驱
    tail = NULL;//tail为最后一个结点
    while ((*L)->next != tail) {
        pre_p = *L;//定位pre_p为p的前驱
        p = (*L)->next;
        while (p->next != tail)//如果p未运行到已排好序的部分，则继续循环
        {
            if (p->data.exponential > p->next->data.exponential)//如果p的指数比p的后继的指数大，则交换p与p的后继的位置
            {
                pre_p->next = p->next;
                p->next = pre_p->next->next;
                pre_p->next->next = p;
            } else//若无交换则p指针直接后移
                p = p->next;

            pre_p = pre_p->next;//pre_p指针跟随p结点后移
        }
        tail = p;//尾指针后为排好序的部分
    }
}
