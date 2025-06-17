#include <iostream>
using namespace std;
//#define int long long
void solve() {
    long long k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    if (x > y) {
        swap(a, b);
        swap(x, y);
    }
    long long cnt1 = 0;
    if (k >= a) {
        cnt1 = (k - a) / x + 1;
    }
    k -= cnt1 * x;
    long long cnt2 = 0;
    if (k >= b) {
        cnt2 = (k - b) / y + 1;
    }
    cout << (cnt1 + cnt2) << endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}