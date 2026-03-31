class Solution {
public:
    int countElements(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for (int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
        }
        int count = 0;
        for (int num : nums) {
            if (num > mn && num < mx) {
                count++;
            }
        }
        return count;
    }
};