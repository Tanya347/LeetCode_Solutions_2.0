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
    
    void middle(ListNode* head, ListNode** back) {
        
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        *back = slow -> next;
        slow -> next = NULL;
    }
    
    void reorderList(ListNode* head) {
    
        if(head -> next == NULL)
            return;
        
        ListNode* front = head;
        ListNode* back;
        
        // array is split into two halves
        middle(head, &back);
        
        // second one is reversed
        back = reverse(back);
        
        while(back != NULL) {
            
            ListNode* newNode = new ListNode(back -> val);
            ListNode* temp = front -> next;
            front -> next = newNode;
            newNode -> next = temp;
            
            front = front -> next -> next;
            back = back -> next;
        }
    }
};