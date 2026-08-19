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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        auto it = head;
        int n = 0;
        while (it != NULL) {
            n++;
            it = it->next;
        }
        int partSize = n / k;  // kinta part size hoga
        int extraSize = n % k; // extra elements remain

        vector<ListNode*> ans(k, nullptr); // intialize the ans for storing ans
        it = head;
        for (int i = 0; i < k && it ; i++) {
            ans[i] = it;

            int currPartSize =
            partSize +(extraSize > 0 ? 1 : 0); // size find for how much elements to insert
            extraSize--;
            for (int j = 0; j < currPartSize - 1; j++) {
                it = it->next;
            }
            auto nextStartPointOfLL = it->next;
            it->next = NULL;
            it = nextStartPointOfLL;
        }
        return ans;
    }
};