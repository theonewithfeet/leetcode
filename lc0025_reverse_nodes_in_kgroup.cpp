// https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k<2) return head;
        
        ListNode **ptr=&head, *list=head; 
        
        while (list) {
            ListNode *start=list, *last;
            
            int i = 0;
            for (; list && i<k; i++) {
                last = list;
                list = list->next;
            }
            if (i<k) break;
            
            ListNode *a=start; 
            ListNode *b=start->next; 
            ListNode *c=b->next;
            
            while (a != last) {
                b->next = a;
                a = b;
                b = c;
                c = c ? c->next : nullptr;
            }
            start->next = list;
           *ptr = last;
            ptr = &(start->next);
        }
        return head;
    }
};
