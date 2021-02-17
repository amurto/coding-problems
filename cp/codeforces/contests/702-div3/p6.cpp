#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e6;
int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), freq;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int cur = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            freq.pb(cur);
            cur = 1;
        }
        else
            cur++;
    }
    freq.pb(cur);
    sort(freq.begin(), freq.end());
    int sum = 0, pre = 0;
    for (int f : freq)
        sum += f;
    int res = inf, sz= freq.size();
    for (int i = 0; i < freq.size(); i++)
    {
        res = min(res, pre + sum - (freq[i] * (sz - i)));
        sum -= freq[i];
        pre += freq[i];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}