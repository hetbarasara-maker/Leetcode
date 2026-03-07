class Solution {
public:
    bool checkOnesSegment(string s) {
        bool foundZero = false;
        for (char c : s) {
            if (c == '0')
                foundZero = true;
            if (c == '1' && foundZero)
                return false;
        }
        return true;
    }
};