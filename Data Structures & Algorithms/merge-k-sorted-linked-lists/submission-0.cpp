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
        // int numNonEmpty = lists.size();
        ListNode res(0);
        ListNode *curr = &res;

        while (1) {
            int minVal = 1000000;
            int minIndex = -1;
            ListNode* minList = nullptr;

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] && (lists[i]->val < minVal)) {
                    minVal = lists[i]->val;
                    minList = lists[i];
                    minIndex = i;
                }
            }

            if (minIndex >= 0) {
                lists[minIndex] = lists[minIndex]->next;
                minList->next = nullptr;
                curr->next = minList;
                curr = curr->next;
            }
            else {
                break;
            }
        }

        // if (curr) {
        //     curr->next = nullptr;
        // }

        return res.next;
    }
};
