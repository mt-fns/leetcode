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
    void reorderList(ListNode* head) {
        ListNode* slowPrev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (slow && fast) {
            slowPrev = slow;
            slow = slow->next;
            if (fast->next) {
                fast = fast->next->next;
            } else {
                fast = fast->next;
            }
        }

        if (slowPrev) {
            slowPrev->next = nullptr;
        }

        // reverse mid onwards
        ListNode* prev = nullptr;

        while (slow) {
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        ListNode* head2 = prev;

        ListNode* curr1 = head;
        ListNode* curr2 = head2;

        // merge 2 lists
        while (curr1 && curr2) {
            ListNode* temp1Next = curr1->next;
            ListNode* temp2Next = curr2->next;

            curr1->next = curr2;
            curr2->next = temp1Next;

            curr1 = temp1Next;
            curr2 = temp2Next;
        }

        // if (curr1) {
        //     curr2->next = curr1;
        // }

        // if (curr2) {
        //     curr1->next = curr2;
        // }
    }
};
