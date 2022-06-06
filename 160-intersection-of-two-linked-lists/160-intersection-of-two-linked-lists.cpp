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
        
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        
        int s1 = 0, s2 = 0, flag = 0;
        
        while(temp1 != NULL) {
            s1++;
            temp1 = temp1 -> next;
        }
        
        while(temp2 != NULL) {
            s2++;
            temp2 = temp2 -> next;
        }
        
        if(s1 > s2) {
            temp1 = headA;
            temp2 = headB;
        } else {
            temp2 = headA;
            temp1 = headB;
            flag = 1;
        }
        
        while(temp1 -> next != NULL) {
            
            temp2 = (flag)? headA : headB;
            
            while(temp2 -> next != NULL) {
                
                if(temp1 == temp2) 
                    return temp1;
                else
                    temp2 = temp2 -> next;
            }
            
            temp1 = temp1 -> next;
        }
        
        cout<<temp1 -> val<<" "<<temp2 -> val<<endl;
        
        if(temp1 -> next == NULL && temp2 -> next == NULL && temp1 == temp2)
            return temp1;
        else 
            return NULL;
    }
};