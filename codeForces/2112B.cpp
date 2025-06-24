#include <bits/stdc++.h>
using namespace std;

bool is_beautiful(const vector<int>& a) {
    for (int i = 0; i + 1 < a.size(); ++i) {
        if (abs(a[i] - a[i + 1]) <= 1) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        if (is_beautiful(a)) {
            cout << 0 << '\n';
        } else if (n == 2) {
            cout << -1 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }

    return 0;
}
