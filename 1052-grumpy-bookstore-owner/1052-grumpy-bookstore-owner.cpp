class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initialSatisfied = 0;
        int currentExtra = 0;
        int maxExtra = 0;

        for(int i=0; i<customers.size(); i++){
            if(grumpy[i] == 0){
                initialSatisfied += customers[i];
            }else{
                currentExtra += customers[i];
            }

            if(i >= minutes){
                if(grumpy[i - minutes] == 1){
                    currentExtra -= customers[i - minutes];
                }
            }
            maxExtra = max(maxExtra, currentExtra);
        }
        return initialSatisfied + maxExtra;
    }
};