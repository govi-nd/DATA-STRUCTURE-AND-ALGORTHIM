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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        int pos = count / 2;
        // cout<<pos<<endl;
        ListNode* temp2 = head;
        for (int i = 1; i < pos + 1; i++) {
            // cout << i << " " << temp2->val << " "<<endl;
            temp2 = temp2->next;
            
        }
        // cout<<endl;
        // cout<<"temp->stopped at"<<temp2->val<<endl;
        return temp2;
    }
};