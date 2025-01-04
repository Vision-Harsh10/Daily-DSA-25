class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int prevMax = INT_MIN;
        int distinctCnt = 0;
        for(auto num : nums){
            int lowerBound = num - k;
            int upperBound = num + k;
            
            if(prevMax < lowerBound){
                prevMax = lowerBound;
                distinctCnt++;
            }
            else if(prevMax < upperBound){
                prevMax++;
                distinctCnt++;
            }
        }
        return distinctCnt;
    }
};