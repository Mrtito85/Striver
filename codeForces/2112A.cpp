#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, x, y;
        cin >> a >> x >> y;

        // Alice's distances to both possible prize positions
        int da1 = abs(a - x);
        int da2 = abs(a - y);

        bool found = false;

        for (int bob = 1; bob <= 100; ++bob) {
            if (bob == a) continue;

            int db1 = abs(bob - x);
            int db2 = abs(bob - y);

            if (db1 < da1 && db2 < da2) {
                found = true;
                break;
            }
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}