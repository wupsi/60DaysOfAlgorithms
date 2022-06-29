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
    bool isPalindrome(ListNode* head) {
        
        ListNode *current = head;
        int size = 0, cnt = 0;
        
        while(current){
            size++;
            current = current->next;
        }
        current = head;
        ListNode *prev = nullptr;
        
        while(cnt < size / 2){
            ListNode *forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
            cnt++;
        }
        if(size % 2) current = current->next;
        
        while(prev){
            if(prev->val != current->val)
                return false;
            prev = prev->next;
            current = current->next;
        }
        return true;
    }
};
