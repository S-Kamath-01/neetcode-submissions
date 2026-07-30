class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(m>n) return false;

        vector<int>need(26,0), window(26,0);

        for(char c: s1){
            need[c-'a']++;
        }
        for(int i = 0; i<m; i++){
            window[s2[i]-'a']++;
        }
        if(window == need){
            return true;
        }
        for(int i = m; i<n; i++){
            window[s2[i]-'a']++;
            window[s2[i-m]-'a']--;
            if(window == need){
                return true;
            }
        }
        return false;
    }
};
