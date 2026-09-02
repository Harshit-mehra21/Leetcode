class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int x: nums){
            st.insert(x);
        }
        int longest=0;
        for(int x: st){
            if(st.find(x-1)==st.end()){
                int  current=x;
                int count=1;
                while(st.find(current+1)!=st.end()){
                    count++;
                    current++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};