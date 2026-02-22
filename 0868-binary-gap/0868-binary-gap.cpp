class Solution {
public:
    int binaryGap(int n) {
        string s = "";
        while(n > 0){
            s = char(n % 2 + '0') + s;
            n = n/2;
        }
        int ans = 0;
        int last = -1;
        for(int i=0; i<s.size(); i++){
            int count = 1;
            if(s[i] == '1'){
                if(last != -1){
                    ans = max(ans, i-last);
                }
                last = i;
            }
        }
        return ans;
    }
};