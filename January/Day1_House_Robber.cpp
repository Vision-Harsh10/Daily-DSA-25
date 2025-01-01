class Solution {
public:
    int helper(int i,  vector<int>& a , vector<int>& t){
        if(i == 0) return a[i];
        if(i<0) return 0;
        if(t[i] != -1) return t[i];

        int pick = a[i] + helper(i-2,a,t);
        int not_pick = 0 + helper(i-1,a,t);

        return t[i] = max(pick , not_pick);
     }
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> t (n+1,-1);
        return helper(n,nums,t);  
    }
};