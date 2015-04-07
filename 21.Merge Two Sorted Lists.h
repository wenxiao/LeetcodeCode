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
        
        //当两个序列均不为空的时候，选取较小的一个元素
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
        
        //将剩下的序列全部插入到尾部
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
        
        //返回
        //针对存在空序列的情况，程序恰好可以处理。
        //由于合并后的尾部元素一定是两个序列之一的尾部元素，因此也不需要特地将最后一个元素的next指针赋值为nullptr
        return head;
    }
};