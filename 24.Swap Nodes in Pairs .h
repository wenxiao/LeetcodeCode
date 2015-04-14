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
        
        //Ϊ���ܹ�ͳһ����ͷ��ָ�룬�������˼���һ��Node
        ListNode tmphead(0);tmphead.next=head;
        
        //p1,p2,p3Ϊ�������ڵĽڵ�
        //p1->p2->p3->..
        //ÿ�ν���p2��p3��λ�ã�ʹ֮��Ϊ
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
