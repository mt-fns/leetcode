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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<pair<ListNode*,ListNode*>> head_and_tails;

        int i = 0;

        pair<ListNode*, ListNode*> curr_tail_and_head;
        ListNode* leftover_head = head;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            // this is the tail
            if ((i % k) == 0) {
                curr_tail_and_head.second = curr;
            }
            // this is the head
            if ((i % k) == (k-1)) {
                curr_tail_and_head.first = curr;
                head_and_tails.push_back(curr_tail_and_head);
                leftover_head = curr->next;
            }

            curr = curr->next;
            i++;
        }

        if (!head_and_tails.size()) {
            return leftover_head;
        }
        
        curr = head;
        prev = nullptr;

        for (const auto & node_pair : head_and_tails) {
            // cout << "first: " << node_pair.first->val << endl;
            // cout << "second: " << node_pair.second->val << endl;

            curr = node_pair.second;
            prev = nullptr;
            
            while (curr != node_pair.first) {
                ListNode* temp = curr->next;
                curr->next = prev;

                prev = curr;
                curr = temp;
            }

            // new head node
            curr->next = prev;
        }

        // append
        ListNode* res = head_and_tails[0].first;
        ListNode* prev_tail = nullptr;

        for (const auto & node_pair : head_and_tails) {
            if (prev_tail) {
                prev_tail->next = node_pair.first;
            }

            prev_tail = node_pair.second;
        }

        if (leftover_head) {
            prev_tail->next = leftover_head;
        }

        return res;

    }
};
