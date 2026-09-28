class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;

        for(char ch : s){
            if(ch == '('){
                depth++;
                maxDepth = max(maxDepth, depth);
            }
            if (ch == ')'){
                depth--;
            }
        }
        return maxDepth;
    }
};