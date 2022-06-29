/**
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        ListNode* merge = l1;
        if(l1->val < l2->val){
            l1 = l1->next;
        }
        else{
            merge = l2;
            l2 = l2->next;
        }
        
        ListNode* current = merge;
        while(l1 and l2){
            
            if(l1->val <= l2->val){
                current->next = l1;
                l1 = l1->next;
            }
            else{
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if(!l1)
            current->next = l2;
        else
            current->next = l1;
        return merge;
    }
};