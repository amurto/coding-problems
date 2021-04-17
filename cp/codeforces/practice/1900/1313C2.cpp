// https://codeforces.com/contest/1313/problem/C2
// Skyscrapers (hard version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int j = 0; j < 2; j++)
    {
        vector<ll> sum(n);
        vector<int> close(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                close[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int d = (close[i] == -1) ? n : close[i];
            sum[i] += 1ll * (d - i) * arr[i];
            if (d < n)
                sum[i] += sum[d];
        }
        for (int i = 0; i < n; i++)
            val[i] += sum[i];
        reverse(arr.begin(), arr.end());
        reverse(val.begin(), val.end());
    }
    for (int i = 0; i < n; i++)
        val[i] -= arr[i];
    int mx = 0;
    for (int i = 0; i < n; i++)
        if (val[i] >= val[mx])
            mx = i;
    vector<ll> res(n);
    res[mx] = arr[mx];
    for (int i = mx - 1; i >= 0; i--)
        res[i] = min(res[i + 1], arr[i]);
    for (int i = mx + 1; i < n; i++)
        res[i] = min(res[i - 1], arr[i]);
    for (ll r : res)
        cout << r << " ";
    cout << "\n";
    return 0;
}