#include <iostream>
#include <cmath>

using namespace std;

int min_actions(int x) {
    if (x == 0) {
        return 0;
    }
    int log = 0;
    while ((1 << (log + 1)) <= x) {
        log++;
    }
    return 2 * log + 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << min_actions(x) << '\n';
    }

    return 0;
}