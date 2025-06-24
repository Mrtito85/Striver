#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) cin >> a[i];

        ll count = 0;

        // Iterate over third red element (rightmost of the three)
        for (int k = 2; k < n; ++k) {
            int T = max(a[k], a[n - 1] - a[k]);

            int l = 0, r = k - 1;
            while (l < r) {
                if (a[l] + a[r] > T) {
                    count += (r - l);
                    r--;
                } else {
                    l++;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}

