//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

// } Driver Code Ends
//User function template for C++

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        //code here
        unordered_map<int, int> m;
        for(auto a: A){
            if(m.find(a) == m.end()){
                m[a] = 1;
            }else{
                m[a] = m[a] + 1;
            }
        }
        for(auto b: B){
            if(m.find(b) == m.end()){
                return false;
            }else{
                m[b]--;
            }
        }
        for(auto i = m.begin(); i != m.end(); i++){
            if(i->second!= 0){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<ll> arr(n,0),brr(n,0);
        
        // increase the count of elements in first array
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        
        
        // iterate through another array
        // and decrement the count of elements
        // in the map in which frequency of elements
        // is stored for first array
        for(ll i=0;i<n;i++)
            cin >> brr[i];
        Solution ob;
        cout << ob.check(arr,brr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends