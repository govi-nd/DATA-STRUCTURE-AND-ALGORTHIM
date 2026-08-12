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
bool hasCycle(ListNode* head) {
    ListNode* kachuva = head;
    ListNode* rabbit = head;

    while (rabbit != NULL && rabbit->next != NULL) {
        kachuva = kachuva->next;
        rabbit = rabbit->next->next;

        if (kachuva == rabbit) {
            return true;
        }
    }

    return false;
}
    // bool hasCycle(ListNode *head) {
    //     ListNode * kachuva = head ;
    //     ListNode * rabbit = head ;
    //     while(rabbit!=NULL){
    //         rabbit= rabbit->next;
    //         if(rabbit!=NULL){
    //             rabbit=rabbit->next;
    //             kachuva=kachuva->next;
    //         }
    //         if(kachuva==rabbit){
    //             return true ;
    //         }
    //     }
    //     return false;
    // }
};