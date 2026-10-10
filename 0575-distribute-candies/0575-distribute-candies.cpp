class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>uniqueTypes(candyType.begin(), candyType.end());

        return min((int)candyType.size()/2, (int)uniqueTypes.size());
    }
};