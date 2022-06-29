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
    ListNode *equalize(ListNode *head, int size, int mn){
        ListNode *current = head;
        
        while(size > mn){
            current = current->next;
            size--;
        }
        return current;
    }
    
    int size(ListNode *head){
        int cnt = 0;
        ListNode *current = head;
        
        while(current != nullptr){
            cnt++;
            current = current->next;
        }
        return cnt;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = size(headA), sizeB = size(headB);
        int mn = sizeA < sizeB ? sizeA : sizeB;
        ListNode *currentA = equalize(headA, sizeA, mn);
        ListNode *currentB = equalize(headB, sizeB, mn);
        
        while(currentA != currentB){
            currentA = currentA->next;
            currentB = currentB->next;
        }
        return currentA;
    }
};