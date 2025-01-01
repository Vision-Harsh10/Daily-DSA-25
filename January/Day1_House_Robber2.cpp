class Solution {
public:
    int helper(int i, vector<int>& a, vector<int>& t) {
        if (i == 0) return a[0];
        if (i < 0) return 0;
        if (t[i] != -1) return t[i];

        int pick = a[i] + helper(i - 2, a, t);
        int not_pick = helper(i - 1, a, t);

        return t[i] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int n = nums.size();

        // Case 1: Exclude the last house (0 to n-2)
        vector<int> a1(nums.begin(), nums.end() - 1);
        int n1 = a1.size();
        vector<int> t1(n1, -1);
        int ans1 = helper(n1 - 1, a1, t1);

        // Case 2: Exclude the first house (1 to n-1)
        vector<int> a2(nums.begin() + 1, nums.end());
        int n2 = a2.size();
        vector<int> t2(n2, -1);
        int ans2 = helper(n2 - 1, a2, t2);

        return max(ans1, ans2);
    }
};
