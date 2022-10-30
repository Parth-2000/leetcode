bool comp(pair<int, int> &p1, pair<int, int> &p2 ){

    return p1.first > p2.first;

}

 class Solution {

public:

    int earliestFullBloom(vector<int>& p, vector<int>& g) {

        int n = p.size();

        vector<pair<int, int>> v(n);

        for(int i=0;i<n;i++){

            v[i] = {g[i]+1, p[i]};//why g[i] + 1 ?bcz after growtime it will bloom growtime + 1  days onwards

        }

        sort(v.begin(), v.end(), comp);

        int prev = 0;

        int maxi = 0;

        for(int i=0;i<n;i++){

            maxi = max(maxi, prev+v[i].first+v[i].second);

            prev+=v[i].second; //maintain prev plant time

        }

        return maxi-1;

    }

};
        

