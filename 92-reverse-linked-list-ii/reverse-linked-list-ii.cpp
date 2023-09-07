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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int pos = 0;
        ListNode *dummy = new ListNode(0, head);
        ListNode *tmp = dummy;

        while(pos + 1 < left) {
            tmp = tmp->next;
            pos++;
        }

        ListNode *p = NULL, *cur = tmp->next, *n = cur->next, *tail = cur;

        int cnt = 0;

        while(cnt <= right - left) {
            cur->next = p;
            p = cur;
            cur = n;
            if(n) n = n->next;
            cnt++;
        }

        if(tmp) tmp->next = p;
        if(tail) tail->next = cur;

        return dummy->next;
    }
};