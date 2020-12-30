#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string xx(int v)
{
    return "x" + to_string(v + 1);
}

ll solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll res = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         for (int k = 0; k < n; k++)
    //         {
    //             cout << "(" << xx(i) << "&" << xx(j) << " * " << xx(j) << "|" << xx(k) << ") + ";
    //             res += ((arr[i] & arr[j]) * (arr[j] | arr[k]));
    //         }
    //     }
    // }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            res += arr[i] | arr[j];
    cout << "\n";
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