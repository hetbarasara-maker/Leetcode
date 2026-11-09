class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        for (string word : words) {
            string temp = word;

            for (char& c : temp) {
                c = tolower(c);
            }

            string row;

            if (row1.find(temp[0]) != string::npos) {
                row = row1;
            } else if (row2.find(temp[0]) != string::npos) {
                row = row2;
            } else {
                row = row3;
            }

            bool valid = true;

            for (char c : temp) {
                if (row.find(c) == string::npos) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};