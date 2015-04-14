/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        //ÿ��Ҫ�����ʱ��
        //���p1->p2->p3->...����
        //����һ���µ����������Ͻ���������ּ���
        //p1,
        //p2->p1,
        //��������

        //Ϊ���ܹ�ͳһ����ͷ��ָ�룬�������˼���һ��Node
        ListNode tmphead(0); tmphead.next = head;

        int list_size = 0;
        ListNode*p = head;
        while (p != nullptr)
        {
            list_size++;
            p = p->next;
        }

        if (list_size < k)
            return head;

        ListNode *p_next;
        //���ڷ��������ʼ�ͽ���ָ��
        ListNode *reversing_list_start, *reversing_list_end;
        //�Ѿ���ɷ���������ָ��
        ListNode *reversed_list_ed;

        reversed_list_ed = p = &tmphead;
        p = p->next;
        
        while (list_size >= k)
        {
            //ÿ�ν�����k��Ԫ�����Ϊ�µ�����reversing_list
            //Ȼ����뵽����reversed_list��
            
            reversing_list_start = reversing_list_end = p;
            p = p->next;

            for (int i = 1; i < k; i++)
            {
                p_next = p->next;

                p->next = reversing_list_start;
                reversing_list_start = p;
                p = p_next;
            }

            reversing_list_end->next = p;

            reversed_list_ed->next = reversing_list_start;
            reversed_list_ed = reversing_list_end;

            list_size -= k;
        }
        return tmphead.next;
    }
};