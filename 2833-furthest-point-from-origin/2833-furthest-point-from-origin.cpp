class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0;
        int countR = 0;
        int count_ = 0;

        for (char c : moves) {
            if (c == 'L') {
                countL++;
            } else if (c == 'R') {
                countR++;
            } else {
                count_++;
            }
        }
        return abs(countL - countR) + count_;
    }
};