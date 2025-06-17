#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to calculate gold in a rectangle using 2D prefix sums
int get_gold_in_rectangle(int r1, int c1, int r2, int c2, int n, int m, const vector<vector<int>>& prefix_gold) {
    // Clamp coordinates to be within grid bounds
    r1 = max(0, r1);
    c1 = max(0, c1);
    r2 = min(n - 1, r2);
    c2 = min(m - 1, c2);

    // If the rectangle is invalid after clamping (e.g., r1 > r2), return 0
    if (r1 > r2 || c1 > c2) {
        return 0;
    }

    // Using 1-indexed prefix sum array: prefix_gold[r+1][c+1] stores sum up to (r,c)
    int total_gold = prefix_gold[r2 + 1][c2 + 1] - prefix_gold[r1][c2 + 1] - prefix_gold[r2 + 1][c1] + prefix_gold[r1][c1];
    return total_gold;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    vector<vector<int>> gold_count(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'g') {
                gold_count[i][j] = 1;
            }
        }
    }

    // Compute 2D prefix sum array (1-indexed for easier calculations)
    vector<vector<int>> prefix_gold(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            prefix_gold[i + 1][j + 1] = gold_count[i][j] + prefix_gold[i][j + 1] + prefix_gold[i + 1][j] - prefix_gold[i][j];
        }
    }

    int max_gold = 0;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == '.') { // Only detonate in empty cells
                // Outer square coordinates (center (r,c), side 2k+1)
                int r_outer_top = r - k;
                int c_outer_left = c - k;
                int r_outer_bottom = r + k;
                int c_outer_right = c + k;

                int gold_outer = get_gold_in_rectangle(r_outer_top, c_outer_left, r_outer_bottom, c_outer_right, n, m, prefix_gold);

                // Inner square coordinates (center (r,c), side 2k+1 - 2 = 2k-1)
                // These are strictly inside, so they exclude the boundary cells
                int r_inner_top = r - k + 1;
                int c_inner_left = c - k + 1;
                int r_inner_bottom = r + k - 1;
                int c_inner_right = c + k - 1;
                
                int gold_inner = get_gold_in_rectangle(r_inner_top, c_inner_left, r_inner_bottom, c_inner_right, n, m, prefix_gold);
                
                max_gold = max(max_gold, gold_outer - gold_inner);
            }
        }
    }

    cout << max_gold << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}