int mod = 1e9+7;
int solve(int i, vector<int>& arr, int sum, vector<vector<int>>& t) {
    // Base cases
    if (sum == 0) return 1; // Found a valid subset.
    if (i == 0) return (arr[0] == sum); // Only one element left to check.
    if (i < 0 || sum < 0) return 0; // Out of bounds or invalid sum.

    // Check if the value is already computed.
    if (t[i][sum] != -1) return t[i][sum];

    // Include the current element if it doesn't exceed the sum.
    int pick = 0;
    if (arr[i] <= sum) {
        pick = solve(i - 1, arr, sum - arr[i], t);
    }

    // Exclude the current element.
    int not_pick = solve(i - 1, arr, sum, t);

    return t[i][sum] = (pick + not_pick)% mod;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> t(n, vector<int>(k + 1, -1)); // Initialize DP table to -1.
    return solve(n - 1, arr, k, t);
}
