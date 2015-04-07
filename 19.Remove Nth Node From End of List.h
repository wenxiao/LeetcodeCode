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
	    //������p2ָ��head�����n��Ԫ�أ�Ȼ��ͬʱ����p1��p2����p2ָ��յ�ʱ��ɾ��p1��Ԫ�ؼ��ɡ�
		ListNode* p1 = head, *p2 = head;
		while (n-- && p2 != nullptr)
			p2 = p2->next;
			
		//һ������¶���Ҫ����ԭʼ��ͷ��ָ�룬��������Ҫɾ��ͷָ���ʱ��������⴦��
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