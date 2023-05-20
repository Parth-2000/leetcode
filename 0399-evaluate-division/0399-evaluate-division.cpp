class Solution {
public:
    double dfs(string a, string b, unordered_map<string, unordered_map<string, double>> g, unordered_set<string> visited){
        if(g[a].find(b) != g[a].end()){
            return g[a][b];
        }
        
        for(auto n: g[a]){
            if(visited.find(n.first) == visited.end()){
                visited.insert(n.first);
                double t = dfs(n.first, b, g, visited);
                if(t){
                    g[a][b] = n.second * t;
                    return g[a][b];
                }
            }
        }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string, unordered_map<string, double>> g;
        for(int i = 0; i < equations.size(); i++){
            g[equations[i][0]][equations[i][1]] = values[i];
            g[equations[i][1]][equations[i][0]] = (double) 1/(values[i]);
        }
        
        for(int i = 0; i < queries.size(); i++){
            unordered_set<string> visited;
            double t = dfs(queries[i][0], queries[i][1], g, visited);
            if(!t){
                ans.push_back(-1.0);
            }else{
                ans.push_back(t);
            }
        }
        return ans;
    }
};