// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        
        auto compare = [](const ListNode* list1, const ListNode* list2) {
            return list1->val > list2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        
        for (ListNode* list: lists) 
            if (list)
                pq.push(list);

        ListNode head, *curr = &head;
        
        while (!pq.empty()) {
            curr->next = pq.top(); 
            pq.pop();
            curr = curr->next;
            if (curr && curr->next) 
                pq.push(curr->next);
        }
        return head.next;
    }
};