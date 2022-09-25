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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        ListNode* temp = head;
        while(true){
            if(temp == NULL) return NULL;
            if(s.find(temp) == s.end()) s.insert(temp);
            else if(s.find(temp) != s.end()) return temp;
            temp = temp->next;
        }
        
    }
};