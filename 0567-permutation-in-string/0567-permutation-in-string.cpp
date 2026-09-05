// class Solution {
// public:
// bool isfreqsame(int freq1[], int freq2[]){
//     for(int i=0;i<26;i++){
//         if(freq1[i]!=freq2[i]){
//             return false;
//         }
//     }
//     return true;
// }
//     bool checkInclusion(string s1, string s2) {
// int freq[26]={0};
//         for(int i=0;i<s1.length();i++){
//              freq[s1[i]-'a']++;
//         }
//         int windsize=s1.length();
//         for(int i=0;i<s2.length();i++){
//             int windidx=0;
//             int idx=i;
//             int windfreq[26]={0};
//             while(windidx<windsize && idx<s2.length()){
//                 windfreq[s2[idx]-'a']++;
//                 windidx++,idx++;
//             }
//             if(isfreqsame(freq,windfreq)){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        // s1 ki frequency
        for(char c : s1) {
            need[c - 'a']++;
        }

        int k = s1.length();

        // First window
        for(int i = 0; i < k; i++) {
            window[s2[i] - 'a']++;
        }

        // Check first window
        if(need == window)
            return true;

        // Sliding window
        for(int right = k; right < s2.length(); right++) {
            window[s2[right] - 'a']++;
            window[s2[right - k] - 'a']--;
            if(need == window)
                return true;
        }

        return false;
    }
};