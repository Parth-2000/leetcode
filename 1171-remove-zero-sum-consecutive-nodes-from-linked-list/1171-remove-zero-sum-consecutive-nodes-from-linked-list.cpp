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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp){
            if(temp->val)
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        for(int i =0; i < arr.size(); i++){
            int sum = arr[i];
            for(int j=i+1; j < arr.size(); j++){
                sum += arr[j];
                if(sum == 0){
                    arr.erase(arr.begin() + i, arr.begin() + i + (j-i) + 1);
                    i--;
                    break;
                }
            }
        }
        ListNode* t = new ListNode(0);
        ListNode* ans = t;
        for(auto n: arr){
            t->next = new ListNode(n);
            t = t->next;
        }
        return ans->next;
    }
};