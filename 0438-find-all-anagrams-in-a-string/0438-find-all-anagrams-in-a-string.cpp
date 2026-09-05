class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int freqS[26]={0};
        int freqP[26]={0};
        for(char c:p){
            freqP[c-'a']++;
        }
        int left=0;
        for(int right=0;right<s.length();right++){
            freqS[s[right]-'a']++;
            
            if(right-left+1>p.length()){
                freqS[s[left]-'a']--;
                left++;
            }

            if(right-left+1==p.length()){
                bool same=true;
                for(int  i=0;i<26;i++){
                if(freqP[i]!=freqS[i]){
                    same=false;
                    break;
                }
            }
            if(same){
                ans.push_back(left);
            }
        }
        }
        return ans;
        
    }
};