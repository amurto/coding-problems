#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void dfs(vector<ll> &arr, vector<ll> &pre, unordered_set<ll> &req, unordered_set<ll> &found, int L, int R)
{
    if (L == R)
    {
        if (req.find(arr[L]) != req.end())
            found.insert(arr[L]);
        return;
    }
    ll sum = 0;
    if (L == 0)
        sum = pre[R];
    else
        sum = pre[R] - pre[L - 1];
    if (req.find(sum) != req.end())
        found.insert(sum);
    if (arr[L] == arr[R])
        return;
    ll m = (arr[L] + arr[R]) / 2;
    int low = L, high = R;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (m >= arr[mid])
            low = mid + 1;
        else
            high = mid;
    }
    dfs(arr, pre, req, found, L, low - 1);
    dfs(arr, pre, req, found, low, R);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, q;
        cin >> n >> q;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        vector<ll> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++)
            pre[i] += pre[i - 1] + arr[i];
        vector<ll> query(q);
        for (int i = 0; i < q; i++)
            cin >> query[i];
        unordered_set<ll> req(query.begin(), query.end());

        unordered_set<ll> found;
        dfs(arr, pre, req, found, 0, n - 1);
        for (int qu : query)
            found.find(qu) != found.end() ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}