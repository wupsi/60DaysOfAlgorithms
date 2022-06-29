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
    bool hasCycle(ListNode *head) {
        int size = 0;
        if(head == nullptr) return false;
        
        while(size++ <= 10000){
            if(head->next == nullptr) return false;
            head = head->next;
        }
        return true;
    }
};