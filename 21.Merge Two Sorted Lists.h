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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* head=nullptr,*p1=nullptr,*p2;
        
        //���������о���Ϊ�յ�ʱ��ѡȡ��С��һ��Ԫ��
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val)
                p2=l1,l1=l1->next;
            else
                p2=l2,l2=l2->next;
            
            if(head==nullptr)
                head=p1=p2;
            else
                p1->next=p2,p1=p2;
        }
        
        //��ʣ�µ�����ȫ�����뵽β��
        while(l1!=nullptr){
            if(head==nullptr)
                head=p1=l1;
            else
                p1->next=l1,p1=l1;
            l1=l1->next;
        }
        
        while(l2!=nullptr){
            if(head==nullptr)
                head=p1=l2;
            else
                p1->next=l2,p1=l2;
            l2=l2->next;
        }
        
        //����
        //��Դ��ڿ����е����������ǡ�ÿ��Դ���
        //���ںϲ����β��Ԫ��һ������������֮һ��β��Ԫ�أ����Ҳ����Ҫ�صؽ����һ��Ԫ�ص�nextָ�븳ֵΪnullptr
        return head;
    }
};