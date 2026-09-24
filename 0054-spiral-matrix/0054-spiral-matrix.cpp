class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0;
        int right = matrix[0].size();
        int top = 0;
        int bottom = matrix.size();
        int elements = right * bottom;

        while (elements > 0) {
            for (int i = left; i < right; i++) {
                ans.push_back(matrix[top][i]);
                elements--;
            }
            if (elements == 0) {
                break;
            }
            top++;

            for (int i = top; i < bottom; i++) {
                ans.push_back(matrix[i][right - 1]);
                elements--;
            }
            if (elements == 0) {
                break;
            }
            right--;

            for (int i = right; i > left; i--) {
                ans.push_back(matrix[bottom - 1][i - 1]);
                elements--;
            }
            if (elements == 0) {
                break;
            }
            bottom--;

            for (int i = bottom; i > top; i--) {
                ans.push_back(matrix[i - 1][left]);
                elements--;
            }
            if (elements == 0) {
                break;
            }
            left++;
        }
        return ans;
    }
};