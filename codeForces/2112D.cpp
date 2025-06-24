#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for(int i = 1; i < n; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(n == 2){
            cout << "NO\n";
            continue;
        }
        int center = -1;
        for(int i = 1; i <= n; i++){
            if((int)adj[i].size() == 2){
                center = i;
                break;
            }
        }
        if(center == -1){
            cout << "NO\n";
            continue;
        }
        int u = adj[center][0];
        int w = adj[center][1];
        cout << "YES\n";
        vector<pii> ans;
        ans.emplace_back(u, center);
        ans.emplace_back(center, w);
        function<void(int,int,int)> dfsU = [&](int x, int p, int d){
            for(int y: adj[x]){
                if(y == p) continue;
                if(x==u && y==center) continue;
                if(x==center && y==u) continue;
                if(d % 2 == 0) ans.emplace_back(x, y);
                else          ans.emplace_back(y, x);
                dfsU(y, x, d+1);
            }
        };
        dfsU(u, center, 0);
        function<void(int,int,int)> dfsW = [&](int x, int p, int d){
            for(int y: adj[x]){
                if(y == p) continue;
                if(x==w && y==center) continue;
                if(x==center && y==w) continue;
                if(d % 2 == 0) ans.emplace_back(y, x);
                else          ans.emplace_back(x, y);
                dfsW(y, x, d+1);
            }
        };
        dfsW(w, center, 0);
        for(auto &e: ans){
            cout << e.first << " " << e.second << "\n";
        }
    }
    return 0;
}

