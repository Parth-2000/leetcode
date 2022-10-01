class Solution {
public:

    int numDecodings(string s) {
        int n=s.length();
        if(n==0||s[0]=='0')
            return 0;
        int cur,prev1=1,prev2=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')
                cur=0;
            else if(i!=n-1&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6')))
                cur=prev1+prev2;
            else
                cur=prev1;
            prev2=prev1;
            prev1=cur;
        }
        return cur;
    }
};