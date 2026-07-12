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
        if (!head || !head->next) {
            return;
        }

        
        ListNode *fast = head;
        ListNode *slow = head;


        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // slow is going to be our mid, reverse the list
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        cout << second->val << endl;


        while (second) {
            ListNode *temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        ListNode *head1 = head;
        ListNode *head2 = prev;

        while (head1 && head2) {
            ListNode *temp1 = head1->next;
            ListNode *temp2 = head2->next;
            head1->next = head2;
            head2->next = temp1;
            head1 = temp1;
            head2 = temp2;
        }


        // if head1 and not head2, add the remainder of head1 to head2
        // and vice versa
    }
};
