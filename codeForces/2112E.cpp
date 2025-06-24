#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> qs(t);
    int M = 1;
    for(int i = 0; i < t; i++){
        cin >> qs[i];
        M = max(M, qs[i]);
    }
    vector<int> spf(M+1);
    vector<int> primes;
    for(int i = 2; i <= M; i++){
        if(spf[i] == 0){
            spf[i] = i;
            primes.push_back(i);
        }
        for(int p: primes){
            long long v = 1LL * p * i;
            if(p > spf[i] || v > M) break;
            spf[v] = p;
        }
    }

    const int INF = 1e9;
    vector<int> h(M+1, INF);
    h[1] = 0;

    vector<pair<int,int>> fac;
    vector<int> divs;
    function<void(int,int)> gen = [&](int idx, int val){
        if(idx == (int)fac.size()){
            divs.push_back(val);
            return;
        }
        int p = fac[idx].first, c = fac[idx].second;
        int v = val;
        for(int e = 0; e <= c; e++){
            gen(idx+1, v);
            v *= p;
        }
    };

    for(int x = 2; x <= M; x++){
        fac.clear();
        int y = x;
        while(y > 1){
            int p = spf[y], cnt = 0;
            while(y % p == 0){
                y /= p;
                cnt++;
            }
            fac.emplace_back(p, cnt);
        }
        divs.clear();
        gen(0, 1);
        int best = INF;
        for(int d: divs){
            if(d >= 3){
                int s1 = d - 2;
                int other = x / d;
                int cand = h[s1] + h[other] + 1;
                if(cand < best) best = cand;
            }
        }
        h[x] = best;
    }

    for(int m: qs){
        if(m == 1){
            cout << 1 << "\n";
        } else if(h[m] >= INF){
            cout << -1 << "\n";
        } else {
            cout << (h[m] + 1) << "\n";
        }
    }
    return 0;
}