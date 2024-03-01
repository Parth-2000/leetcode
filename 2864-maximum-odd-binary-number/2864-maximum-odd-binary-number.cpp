class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c = count(s.begin(), s.end(), '1');
        
        s[s.size()-1] = '1';
        c--;
        for(int i = 0; i < s.size()-1; i++){
            if(c > 0){
                s[i] = '1';
                c--;
            }else{
                s[i] = '0';
            }
        }
        
        return s;
    }
};