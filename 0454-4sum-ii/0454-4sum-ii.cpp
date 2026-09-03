class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp;
        for(auto x:nums1){
            for(auto y:nums2){
                mp[x+y]++;
            }
        }
        int count=0;
        for(auto a:nums3){
            for(auto b:nums4){
                int sum=a+b;
                if(mp.find(-sum)!=mp.end()){
                    count+=mp[-sum];
                }
            }
        }
        return count;
    }
};