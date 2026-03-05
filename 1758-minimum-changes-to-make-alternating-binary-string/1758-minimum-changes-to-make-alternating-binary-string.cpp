class Solution {
public:
    int minOperations(string s) {
        int change0 = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] != '0'){
                    change0++;
                }
            } else {
                if (s[i] != '1'){
                    change0++;
                }
            }
        }

        int change1 = n - change0;

        return min(change0, change1);
    }
};