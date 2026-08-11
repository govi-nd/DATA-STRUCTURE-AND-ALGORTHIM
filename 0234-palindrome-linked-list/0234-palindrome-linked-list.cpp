class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return true;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* secondHalf = reverseList(slow->next);

        // 3. Compare both halves
        ListNode* first = head;
        ListNode* second = secondHalf;

        bool palindrome = true;

        while (second != NULL) {
            if (first->val != second->val) {
                palindrome = false;
                break;
            }

            first = first->next;
            second = second->next;
        }

        // 4. Restore original linked list
        // slow->next = reverseList(secondHalf);

        return palindrome;
    }
};