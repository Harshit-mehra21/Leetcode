class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        map<char, int> common;
        for(char c : words[0]) {
            common[c]++;
        }
        for(int i = 1; i < words.size(); i++) {
            map<char, int> current;
            for(char c : words[i]) {
                current[c]++;
            }
            for(auto x : common) {
                char letter = x.first;
                if(current.count(letter)) {
                    common[letter] = min(common[letter],current[letter]);
                }
                else {

                    common[letter] = 0;
                }
            }
        }
        for(auto x : common) {

            while(x.second > 0) {

                ans.push_back(string(1, x.first));

                x.second--;
            }
        }
        return ans;
    }
};