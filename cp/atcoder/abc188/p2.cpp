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
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += (A[i] * 1ll * B[i]);
    res == 0 ? cout << "Yes\n" : cout << "No\n";
    return 0;
}