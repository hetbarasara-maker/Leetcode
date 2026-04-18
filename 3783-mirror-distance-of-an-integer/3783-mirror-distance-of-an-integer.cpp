class Solution {
public:
    int mirrorDistance(int n) {
        int original = n;
        int reversedN = 0;
        int temp = n;
        
        while (temp > 0) {
            reversedN = reversedN * 10 + (temp % 10);
            temp /= 10;
        }
        
        return abs(original - reversedN);
    }
};