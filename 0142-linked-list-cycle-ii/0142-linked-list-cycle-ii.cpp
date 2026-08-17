/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * tortoise = head ;
        ListNode * hare = head ;
        while(hare!=NULL){
            hare=hare->next;
            if(hare!=NULL){
                hare=hare->next;
                tortoise=tortoise->next;
            }
            if(hare==tortoise){
                // cycle found 
                tortoise = head ;
                while(tortoise!=hare){
                    tortoise=tortoise->next;
                    hare=hare->next;
                }
                return tortoise;
            }
        }
        return NULL;
    }
};