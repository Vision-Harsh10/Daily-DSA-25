class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(2001,0);
        for(int i=0;i<n;i++){
            int added_num = 1000 + arr[i];
            temp[added_num]++; 
        }
        sort(temp.begin(),temp.end());

        for(int i=1 ; i<temp.size();i++){
            if(temp[i] != 0 && temp[i-1] == temp[i]){
                return false;
            }
        }
        return true;
    }
};