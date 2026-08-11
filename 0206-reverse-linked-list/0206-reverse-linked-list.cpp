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
    ListNode* solve(ListNode* & head, ListNode*& prev, ListNode*& next,
                    ListNode* curr) {
        if (curr == NULL) {
            return prev;
        }
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr=next;
         return solve(head,prev,next , curr);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        return solve(head, prev, next, curr);

        // ListNode* prev = NULL;
        // ListNode* curr = head;
        // while (curr != NULL) {
        //     ListNode* next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        // return prev;
    }
};