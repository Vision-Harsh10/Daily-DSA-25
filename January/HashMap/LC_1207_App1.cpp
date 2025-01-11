class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> wins , losses;
        vector<int> row1 , row2;
        vector<vector<int>> ans;
        for(auto &it : matches){
            wins[it[0]]++;
            losses[it[1]]++;
        }

        for(auto &player : wins){
            if(losses.find(player.first) == losses.end()){
                row1.push_back(player.first);
            }
        }
        for(auto &player : losses){
            if(player.second == 1){
                row2.push_back(player.first);
            }
        }
        sort(row1.begin(),row1.end());
        sort(row2.begin(),row2.end());


        ans.push_back(row1);
        ans.push_back(row2);

        return ans;
    }
};