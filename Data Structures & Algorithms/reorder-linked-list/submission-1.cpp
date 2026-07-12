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
        // try and find the midpoint

        ListNode *curr = head; 

        int len = 0;
        while (curr) {
            curr = curr->next;
            len++;
        }

        // point curr to mid
        ListNode* prev = nullptr;
        curr = head;

        for (int i = 0; i < len/2; i++) {
            if (!curr->next) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        // break up first part from second part
        if (prev) {
            prev->next = nullptr;
        }
        prev = nullptr;
        // reverse bottom half
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* prev1 = nullptr;
        ListNode* prev2 = nullptr;
        ListNode* curr1 = head;
        ListNode* curr2 = prev;

        // while (curr1) {
        //     cout << curr1->val << endl;
        //     curr1 = curr1->next;
        // }

        // while (curr2) {
        //     cout << curr2->val << endl;
        //     curr2 = curr2->next;
        // }

        while (curr2 && curr1) {
            ListNode* temp1 = curr1->next;
            ListNode* temp2 = curr2->next;

            curr1->next = curr2;
            curr2->next = temp1;
            // if (!temp1 && temp2) {
            //     cout << "TEST" << endl;
            //     curr1->next = curr2;
            //     break;
            // }
            // else if (!temp2 && temp1) {
            //     cout << "TEST2" << endl;

            //     curr2->next = curr1;
            //     break;
            // }
            
            prev1 = curr1;
            prev2 = curr2;
            curr1 = temp1;
            curr2 = temp2;
        }
        // cout << "TEST5" << endl;


        if (curr1) {
            cout << "TEST5" << endl;
            prev2->next = curr1;
        }   
        else if (curr2) {
            cout << "TEST5" << endl;
            prev2->next = curr2;
        }

        // cout << "TEST6" << endl;
    }
};
