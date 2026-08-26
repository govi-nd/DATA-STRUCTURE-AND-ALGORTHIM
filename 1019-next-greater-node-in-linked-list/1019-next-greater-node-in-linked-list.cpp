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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll ;
        while(head){
            ll.push_back(head->val);
            head=head->next;
        }
        stack<int> s;
        for(int i = 0 ; i < ll.size();i++){
            while(!s.empty()&&ll[i]>ll[s.top()]){
                int kids = s.top(); // index for which u have to store the NGE
                s.pop();
                ll[kids]=ll[i]; // store the NGE in the ans 

            }
            // smaller than the previous ll[i]<ll[s.top()]
            s.push(i); // push the index
        }
        while(!s.empty()){
            ll[s.top()]=0;
            s.pop();
        }
        return ll;
    }
};