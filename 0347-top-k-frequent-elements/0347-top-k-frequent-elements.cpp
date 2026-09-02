class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        vector<pair<int,int>> v;
         for(auto x : mp){
            v.push_back({x.first, x.second});
        }
          sort(v.begin(), v.end(), [](auto &a, auto &b){ return a.second > b.second; });
         vector<int> ans;

        for(int i = 0; i < k; i++){
            ans.push_back(v[i].first);
        }

        return ans;
    }
};