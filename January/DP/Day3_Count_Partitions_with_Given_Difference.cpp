//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
        int solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(ind==0){
            if(target==0 && arr[0]==0)  return 2;
            if(target==0||target==arr[0])   return 1;
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int notTaken=solve(ind-1,target,arr,dp);
        int taken=0;  
        if(arr[ind]<=target)
            taken=solve(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target]=(notTaken+taken)%1000000007;
    }
    int countPartitions(vector<int>& arr, int d) {
          int mod = 1e9+7;
          int n = arr.size();
          long long total=0;
        for(int i=0; i<n; i++){
            total+=arr[i];
        }
        if(total-d<0||(total-d)%2==1){
            return 0;
        }
        long long sum=(total-d)/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends