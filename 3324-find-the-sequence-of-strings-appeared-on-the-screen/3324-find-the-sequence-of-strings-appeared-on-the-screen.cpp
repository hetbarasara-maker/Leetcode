class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string s = "";

        for (int i = 0; i < target.length(); i++) {
            s += 'a';
            ans.push_back(s);
            while (s.back() < target[i]) {
                s.back()++;
                ans.push_back(s);
            }
        }
        return ans;
    }
};