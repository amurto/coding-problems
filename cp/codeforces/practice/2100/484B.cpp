// https://codeforces.com/contest/484/problem/B
// Maximum Value

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5;
int solve()
{
    int n, v, res = 0;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        if (v > 1)
            arr.pb(v);
    }
    if (arr.empty())
        return 0;
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    vector<int> freq(2 * N), seq(2 * N);
    for (int x : arr)
        freq[x]++;
    int last = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        seq[i] = last;
        if (freq[i])
            last = i;
    }
    for (int x : arr)
        for (int j = 2 * x; j < 2 * N; j += x)
            if (seq[j] >= x)
                res = max(res, seq[j] % x);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}