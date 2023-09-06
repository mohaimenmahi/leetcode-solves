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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int len = 0;

        ListNode* tmp = head;

        while(tmp) {
            len++;
            tmp = tmp->next;
        }

        int part = len / k;
        int rem = len % k;

        ListNode* curHead = head;
        ListNode* cur = head;
        ListNode* prev = NULL;

        int pos = 0;
        while(pos < k) {
            int need = part;
            if(pos < rem) need++;
            int curLen = 0;
            while(cur && curLen < need) {
                curLen++;
                prev = cur;
                cur = cur->next;
            }
            if(prev) prev->next = NULL;
            ans.push_back(curHead);
            curHead = cur;
            pos++;
        }

        return ans;
    }
};