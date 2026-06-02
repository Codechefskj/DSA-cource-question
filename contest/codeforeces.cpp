#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<queue>
using namespace std;

void prim(vector<vector<pair<int,int>>>& adj,vector<bool>& ismst,int src,int& ans){
    priority_queue<pair<int,int>, vector<pair<int,int>> , vector<pair<int,int>>> q ;
    q.push({0 , src});  // weight , node
    while(!q.empty()){
        int wt = q.top().first ; 
        int node = q.top().second ; 

        ismst[node]= true ; 
        ans += wt ; 
        for(auto x : adj[node]){
            int adjnode = x.first;
            int cost = x.second;
            if(ismst[adjnode]== false){
                q.push({cost,adjnode});
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<bool> ismst(n, false);
    int ans = 0;
    prim(adj, ismst, 0, ans);
    cout << ans << endl;
}
