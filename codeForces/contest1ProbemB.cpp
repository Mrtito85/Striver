#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        // Generate Fibonacci sequence up to n terms
        vector<int> fib(n + 1);
        fib[1] = 1;
        fib[2] = 2;
        for (int i = 3; i <= n; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        
        // Extract cubes and sort in descending order
        vector<int> cubes;
        for (int i = 1; i <= n; ++i) {
            cubes.push_back(fib[i]);
        }
        sort(cubes.rbegin(), cubes.rend());
        
        // Calculate total height
        int total_height = 0;
        for (int cube : cubes) {
            total_height += cube;
        }
        
        string res;
        for (int i = 0; i < m; ++i) {
            int w, l, h;
            cin >> w >> l >> h;
            
            int largest = cubes[0];
            bool canFit = false;
            
            // Check if the largest cube can fit in any orientation
            if ((w >= largest && l >= largest && h >= total_height) ||
                (w >= largest && h >= largest && l >= total_height) ||
                (l >= largest && h >= largest && w >= total_height) ||
                (w >= largest && l >= total_height && h >= largest) ||
                (w >= total_height && l >= largest && h >= largest) ||
                (l >= total_height && w >= largest && h >= largest)) {
                canFit = true;
            }
            
            res.push_back(canFit ? '1' : '0');
        }
        
        cout << res << '\n';
    }
}

int main() {
    solve();
    return 0;
}