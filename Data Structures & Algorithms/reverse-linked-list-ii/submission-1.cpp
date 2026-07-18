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
        // 1 <= left <= right <= n
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *segmentHead = head;
        ListNode *segmentTail = head;
        ListNode *start = nullptr;
        ListNode *end = nullptr;

        for (int i = 1; i <= right; i++) {
            if (i >= left && i <= right) {
                if (i == left) {
                    segmentHead = curr;
                    start = prev;
                }
                if (i == right) {
                    segmentTail = curr;
                    end = curr->next;
                }

                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        if (start) {
            start->next = segmentTail;
        }

        segmentHead->next = end;

        if (!start) {
            return segmentTail;
        }

        return head;
    }
};