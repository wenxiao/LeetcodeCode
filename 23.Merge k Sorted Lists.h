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
    //����һ�����ȶ���
    //���ȶ��ж�����Ԫ�ؾ�����һ����Ҫ���뵽�����е�Ԫ�ء�
    //ÿ��ȡ������Ԫ�ص�ʱ���ж�һ��ԭ�����Ƿ��к��Ԫ�أ�����еĻ����뵽���ȶ�����
    
    typedef pair<int,ListNode*> value_node_pair;
    
    //�����ȶ��ж���Ԫ��Ϊvalue��С��Ԫ�أ���˲���greater<value_node_pair>��Ϊ�ȽϺ���
    priority_queue<value_node_pair,vector<value_node_pair>,greater<value_node_pair>> remain_queue;
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* head=nullptr,*p;
        
        //��ʼ�����ȶ���
        for(ListNode *p:lists){
            if(p!=nullptr)
                remain_queue.push(value_node_pair(p->val,p));
        }
        
        
        while(!remain_queue.empty()){
            //ȡ������Ԫ�ز����뵽��ǰ�б���
            value_node_pair top=remain_queue.top();
            remain_queue.pop();
            
            if(head==nullptr){
                p=head=top.second;
            }else{
                p->next=top.second;
                p=p->next;
            }
            
            if(p->next!=nullptr)
                remain_queue.push(value_node_pair(p->next->val,p->next));
        }
        return head;
    }
};