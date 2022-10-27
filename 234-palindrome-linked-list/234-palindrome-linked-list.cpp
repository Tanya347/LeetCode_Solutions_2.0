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
    
    ListNode* reverse(ListNode* head) {
        
        ListNode* c = head;
        ListNode* p = NULL;
        ListNode* n = NULL;
        
        while(c != NULL) {
            n = c -> next;
            c -> next = p;
            p = c;
            c = n;
        }
        
        return p;
    }
    
    void middle(ListNode* head, ListNode** front, ListNode** back) {
        
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        *front = head;
        *back = slow -> next;
        slow -> next = NULL;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head -> next == NULL)
            return true;
        
        ListNode* front;
        ListNode* back;
        
        // array is split into two halves
        middle(head, &front, &back);
        
        // second one is reversed
        back = reverse(back);
        
        
        while(front != NULL && back != NULL) {
            if(front -> val != back -> val)
                return false;
            
            front = front -> next;
            back = back -> next;
        }
        
        return true;
    }
};