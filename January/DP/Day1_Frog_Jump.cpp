class Solution {
public: 
    unordered_map<int,int>mp;
    bool helper(int i , int k , vector<int>& stones, 
    vector<vector<int>>&t){
        if(i == stones.size()-1) return true;

        if(t[i][k] != -1) return t[i][k];

        bool k0 = false;
        bool k1 = false;
        bool k2 = false;

        if(mp.find(stones[i]+k) != mp.end()){
            k0 = helper(mp[stones[i]+k],k,stones,t);
        }
        if(k > 1 && mp.find(stones[i]+k-1) != mp.end()){
            k1 = helper(mp[stones[i]+k-1],k-1,stones,t);
        }
        if(mp.find(stones[i]+k+1) != mp.end()){
            k2 = helper(mp[stones[i]+k+1],k+1,stones,t);
        }
        t[i][k] = k0 || k1 || k2 ;
        return t[i][k];
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1) return false;
        vector<vector<int>>t(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            mp.insert({stones[i],i});
        }
       return helper(1,1,stones,t);
    }
};