class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int frequency[101]={0};
        for(auto num : nums){
            frequency[num]++;
        }
        int sum =0;

        for(int i=0; i<101; i++){
            if(frequency[i] == 1){
                sum +=i;
            }
        
        }
        return sum;


        
    }
};