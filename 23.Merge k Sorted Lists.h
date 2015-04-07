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
    //构造一个优先队列
    //优先队列顶部的元素就是下一个需要加入到队列中的元素。
    //每次取出顶部元素的时候判断一下原序列是否还有后继元素，如果有的话加入到优先队列中
    
    typedef pair<int,ListNode*> value_node_pair;
    
    //令优先队列顶部元素为value最小的元素，因此采用greater<value_node_pair>作为比较函数
    priority_queue<value_node_pair,vector<value_node_pair>,greater<value_node_pair>> remain_queue;
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* head=nullptr,*p;
        
        //初始化优先队列
        for(ListNode *p:lists){
            if(p!=nullptr)
                remain_queue.push(value_node_pair(p->val,p));
        }
        
        
        while(!remain_queue.empty()){
            //取出顶部元素并加入到当前列表中
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