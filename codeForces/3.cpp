#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n+1);
        unordered_map<int, vector<int>> pos;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }

        long long ans = LLONG_MAX;

        for (auto& entry : pos) {
            int v = entry.first;
            vector<int>& indices = entry.second;

            long long min_left = LLONG_MAX;
            long long min_right = LLONG_MAX;

            for (int idx : indices) {
                long long left_cost = (long long)(idx - 1) * v;
                long long right_cost = (long long)(n - idx) * v;

                if (left_cost < min_left) min_left = left_cost;
                if (right_cost < min_right) min_right = right_cost;
            }

            ans = min(ans, min_left + min_right);
        }

        cout << ans << "\n";
    }
    return 0;
}
