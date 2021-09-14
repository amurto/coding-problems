// https://codeforces.com/contest/1114/problem/E
// Arithmetic Progression

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

int query(int &q, int t, int x)
{
    q++;
    if (t == 1)
        cout << "? " << x << endl;
    else
        cout << "> " << x << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

void solve()
{
    int n, q = 0, g = 0;
    cin >> n;
    int low = 0, high = 1e9;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (query(q, 2, mid))
            low = mid + 1;
        else
            high = mid;
    }
    vector<int> arr, ids(n);
    iota(ids.begin(), ids.end(), 0);
    shuffle(ids.begin(), ids.end(), rng);
    for (int i = q, j = 0; j < n && i < 60; i++, j++)
        arr.pb(query(q, 1, ids[j] + 1));
    arr.pb(low);
    sort(arr.begin(), arr.end());
    for (int i = 1; i < (int)arr.size(); i++)
        g = __gcd(g, arr[i] - arr[i - 1]);
    cout << "! " << low - (n - 1) * g << " " << g << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}