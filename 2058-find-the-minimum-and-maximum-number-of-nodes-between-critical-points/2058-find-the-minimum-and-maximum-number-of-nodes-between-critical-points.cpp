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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1 , -1};
        if(!head || !head->next || !head->next->next){
            return ans;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;
        int first = -1;
        int last = -1;
        int mindist = INT_MAX;
        int maxdist = -1;
        while(curr->next){
            int next = curr->next->val;
            if((curr->val > prev->val && curr->val > next)||(curr->val < prev->val && curr->val < next)){
                if(first==-1){
                    first = index;
                }
                else{
                    mindist = min(mindist , index - last);
                    maxdist = index - first;

                }
                last = index;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        if(mindist == INT_MAX) return {-1 , -1};
        return {mindist , maxdist};
    }
};