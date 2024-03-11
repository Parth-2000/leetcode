class Solution {
public:
    string customSortString(string order, string s) {
        
        unordered_map<char,int> m;
        for(auto ch: s){
            m[ch]++;
        }
        string ans = "";
        for(auto ch: order){
            if(m[ch]){
                while(m[ch] > 0){
                    ans += ch;
                    m[ch]--;
                }
            }
        }
        
        for(auto e: m){
            if(e.second != 0){
                while(e.second > 0){
                    ans += e.first;
                    e.second--;
                }
            }
        }
        return ans;
    }
};