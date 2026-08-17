class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* prev = NULL;
        int carry = 0;

        while (t1 && t2) {
            int sum = t1->val + t2->val + carry;
            t1->val = sum % 10;
            carry = sum / 10;

            prev = t1;
            t1 = t1->next;
            t2 = t2->next;
        }

        while (t1) {
            int sum = t1->val + carry;
            t1->val = sum % 10;
            carry = sum / 10;

            prev = t1;
            t1 = t1->next;
        }

        if (t2) {
            prev->next = t2;          // remaining l2 attach

            while (t2) {
                int sum = t2->val + carry;
                t2->val = sum % 10;
                carry = sum / 10;

                prev = t2;
                t2 = t2->next;
            }
        }

        if (carry)
            prev->next = new ListNode(carry);

        return l1;
    }
};