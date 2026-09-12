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
        int pos = 1;
        ListNode* prev = head;
        ListNode* curr = head -> next;

        int firstCritical = -1;
        int lastCritical = -1;
        int minDist = INT_MAX;

        while(curr ->next != NULL){
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                    if (firstCritical == -1) {
                    firstCritical = pos;
                }
                else {
                    minDist = min(minDist, pos - lastCritical);
                }
                
                lastCritical = pos;
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }
        if (firstCritical == lastCritical) {
            return {-1, -1};
        }
        int maxDist = lastCritical - firstCritical;
        return {minDist, maxDist};
    }
};