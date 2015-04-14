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

        //每次要反序的时候
        //如对p1->p2->p3->...反序
        //构造一个新的链表，并不断将后面的数字加入
        //p1,
        //p2->p1,
        //依此类推

        //为了能够统一处理头部指针，在链表顶端加入一个Node
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
        //正在反序的链表开始和结束指针
        ListNode *reversing_list_start, *reversing_list_end;
        //已经完成反序的链表的指针
        ListNode *reversed_list_ed;

        reversed_list_ed = p = &tmphead;
        p = p->next;
        
        while (list_size >= k)
        {
            //每次将后面k个元素组合为新的链表reversing_list
            //然后加入到链表reversed_list中
            
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