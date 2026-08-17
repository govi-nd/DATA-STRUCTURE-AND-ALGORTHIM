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
        ListNode* slow = head;
        ListNode* prevSlow = NULL;
        ListNode* fast = head;

        // fast ko n steps aage le ja
        while (n--) {
            fast = fast->next;
        }

        // Head delete case
        if (fast == NULL) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        // Dono ko saath chala
        while (fast != NULL) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next;
        }

        // Delete nth node
        prevSlow->next = slow->next;
        delete slow;

        return head;
    }
};
// optimal but 3 traversal
// class Solution {
    // public:
    //     ListNode* reverseLL(ListNode* head) {
    //         ListNode* prev = NULL;
    //         ListNode* curr = head;

    //         while (curr != NULL) {
    //             ListNode* forward = curr->next;
    //             curr->next = prev;
    //             prev = curr;
    //             curr = forward;
    //         }
    //         return prev;
    //     }

    //     ListNode* removeNthFromEnd(ListNode* head, int n) {
    //         ListNode* revLLhead = reverseLL(head);

    //         // delete first node of reversed LL
    //         if (n == 1) {
    //             ListNode* del = revLLhead;
    //             revLLhead = revLLhead->next;
    //             delete del;
    //             return reverseLL(revLLhead);
    //         }

    //         ListNode* temp = revLLhead;

    //         while (n - 2) {
    //             temp = temp->next;
    //             n--;
    //         }

    //         ListNode* toDelete = temp->next;
    //         temp->next = temp->next->next;
    //         delete toDelete;

    //         return reverseLL(revLLhead);
    //     }
    // };