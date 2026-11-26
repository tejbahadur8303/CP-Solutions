class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int>freq;
        for( auto num : nums){
            freq[num]++;

        if(freq[num] >2){
            return false;
        }
        }

        

        return true;
    }
};