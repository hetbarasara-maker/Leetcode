class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1);
        int maxLength = 0;
        int left = 0;

        for(int right = 0; right < s.length(); right++){
            char curr = s[right];

            if(lastIndex[curr] >= left){
                left = lastIndex[curr] + 1;
            }
            lastIndex[curr] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};