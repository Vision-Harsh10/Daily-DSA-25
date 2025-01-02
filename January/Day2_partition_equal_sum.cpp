class Solution {
public: 
    bool solve(int i ,  vector<int>& nums , int sum,vector<vector<int>>&t){
        if(sum == 0) return true;
        if(i==0) return nums[i] == sum;
        if(i<0 || sum < 0) return false;
        if(t[i][sum] != -1) return t[i][sum];
        if(nums[i] <= sum){
            return t[i][sum] = solve(i-1,nums,sum-nums[i],t) || solve(i-1,nums,sum,t);
        }
        else if(nums[i] > sum) {
            return t[i][sum] = solve(i-1,nums,sum,t);
        }
        return t[i][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum +=nums[i];
        }
        if(sum%2 != 0) return false;
        sum = sum / 2;
        vector<vector<int>> t(n+1,vector<int>(sum+1,-1));
        return solve(n-1,nums ,sum,t);
    }
};