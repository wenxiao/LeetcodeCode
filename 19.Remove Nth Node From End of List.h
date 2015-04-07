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
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
	    //首先令p2指向head后面第n个元素，然后同时后移p1和p2，当p2指向空的时候删除p1的元素即可。
		ListNode* p1 = head, *p2 = head;
		while (n-- && p2 != nullptr)
			p2 = p2->next;
			
		//一般情况下都需要返回原始的头部指针，不过当需要删除头指针的时候可以特殊处理
        if(p2==nullptr){
            head=p1->next;
            delete p1;
            return head;
        }

		while (p2->next)
			p2 = p2->next, p1 = p1->next;

		ListNode* delete_node = p1->next;
		p1->next = p1->next->next;
		delete delete_node;
		return head;
	}
};