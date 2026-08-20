class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int operation = 2; operation < nums.size(); operation++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[operation]);
            } else {
                arr2.push_back(nums[operation]);
            }
        }
        vector<int> ans;
        for (int x : arr1) {
            ans.push_back(x);
        }
        for (int x : arr2) {
            ans.push_back(x);
        }
        return ans;
    }
};
