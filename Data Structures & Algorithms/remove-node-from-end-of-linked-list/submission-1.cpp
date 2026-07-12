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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int len = 0;

        while (curr) {
            len++;
            curr = curr->next;
        }

        ListNode* prev = nullptr;
        curr = head;

        int i = 0;
        while (curr) {
            cout << len-i << endl;
            if ((len-i) == n) {
                if (prev) {
                    prev->next = curr->next;
                    break;
                }
                
                head = curr->next;
            }

            i++;
            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};
