/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head==nullptr)
            return head;
        
        //为了能够统一处理头部指针，在链表顶端加入一个Node
        ListNode tmphead(0);tmphead.next=head;
        
        //p1,p2,p3为三个相邻的节点
        //p1->p2->p3->..
        //每次交换p2与p3的位置，使之成为
        //p1->p3->p2->..
        ListNode* p1 = &tmphead,*p2,*p3;
        
        while(true){
            p2=p1->next;
            if(p2==nullptr)
                break;
            p3=p2->next;
            if(p3==nullptr)
                break;
                
            p2->next=p3->next;
            p3->next=p2;
            p1->next=p3;
            p1=p2;
        }
        
        return tmphead.next;
    }
};
