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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode res(0);
        ListNode* node = &res;

        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                node->next = curr1;
                curr1 = curr1->next;
            }
            else {
                node->next = curr2;
                curr2 = curr2->next;
            }
            node = node->next;
        }

        if (curr1) {
            node->next = curr1;
        }
        else if (curr2) {
            node->next = curr2;
        }


        return res.next;
    }
};
