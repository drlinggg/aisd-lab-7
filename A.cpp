#include <bits/stdc++.h>
#define fast std::cin.tie(0);std::ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll RBN = 1e9+7;
const ll RSN = -(1e9+7);
const double PI = 3.141592653589793;
//mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); ll gen(){return rnd()%100;}

string to_bin(ll n, ll count){
    string ans;
    for (ll i = 0; i < count; i++) {
        ans += (char) (n%2+'0');
        n /= 2;
    }
    return ans;
}

signed main() {
    fast;
    ll n;
    cin >> n;
    ll number = pow(2,n);
    string array[number];
    for (ll i = 0; i < number; i++) {
        array[i] = to_bin(i, n);
        for (ll j = 0; j < n-1; j++) {
            array[i][j] = (char) (((ll) (array[i][j] - '0')) ^ ((ll) (array[i][j+1] - '0'))) + '0';
        }
    }
    for (ll i = 0; i < number; i++) {
        reverse(array[i].begin(), array[i].end());
        cout << array[i] << '\n';
    }
    return 0;
}

