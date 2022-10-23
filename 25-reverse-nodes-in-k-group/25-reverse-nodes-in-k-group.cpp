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
    
    ListNode *reverseLinkedList(ListNode *head) {
    
        // Write your code here
        ListNode* c = head;
        ListNode* n = NULL;
        ListNode* p = NULL;

        while(c != NULL) {
            n = c -> next;
            c -> next = p;
            p = c;
            c = n;
        }

        return p;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int i = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* tempHead = NULL;
        
        while(temp != NULL) {
            
            // if i is zero i.e it is at start node then preserve it
            if(i == 0)
                tempHead = temp;
            
            // incement i which denotes node's curr number
            i++;
            
            // if after incrementing it becomes then reverse
            if(i == k) {
                
                ListNode* t = temp -> next;
                ListNode* a = temp;
                temp = temp -> next;
                a -> next = NULL;
                ListNode* newHead = reverseLinkedList(tempHead);
                
                if(prev == NULL)
                    head = newHead;
                else
                    prev -> next = newHead;
                
                tempHead -> next = t;
                prev = tempHead;
                i = 0;
            }
            else
                temp = temp -> next;
        }
        
        return head;
    }
};