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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = 0, lenB = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        
        while (tempA != nullptr) {
            lenA++;
            tempA = tempA->next;
        }
        
        while (tempB != nullptr) {
            lenB++;
            tempB = tempB->next;
        }
        
        tempA = headA;
        tempB = headB;
        
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; ++i) {
                tempA = tempA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; ++i) {
                tempB = tempB->next;
            }
        }

        while (tempA != nullptr && tempB != nullptr) {
            if (tempA == tempB) {
                return tempA;  
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return nullptr; 
    }
};