#include <iostream>
#include <vector>
using namespace std;

long long norm(long long x, long long m) {
    long long r = x % m;
    if (r < 0) r += m;
    return r;
}

bool can_tile(long long w, long long h, long long a, long long b,
              long long x1, long long y1, long long x2, long long y2) {
    // normalize remainders so they match Python's behavior
    long long rx1 = norm(x1, a);
    long long rx2 = norm(x2, a);
    long long ry1 = norm(y1, b);
    long long ry2 = norm(y2, b);

    bool vert_ok  = (rx1 == rx2) && ((x1 != x2) || (ry1 == ry2));
    bool horiz_ok = (ry1 == ry2) && (y1 != y2);

    return vert_ok || horiz_ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<string> out;
    out.reserve(t);

    while (t--) {
        long long w, h, a, b, x1, y1, x2, y2;
        cin >> w >> h >> a >> b;
        cin >> x1 >> y1 >> x2 >> y2;

        out.push_back(can_tile(w, h, a, b, x1, y1, x2, y2) ? "Yes" : "No");
    }

    for (auto &s : out) {
        cout << s << "\n";
    }
    return 0;
}
