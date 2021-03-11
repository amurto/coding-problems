#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> upL(n), upR(n);
    int cur = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            upL[i] = upL[i - 1] + 1;
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > arr[i + 1])
            upR[i] = upR[i + 1] + 1;
    int mx = 0, cnt = 0, fnd = 0;
    for (int i = 0; i < n; i++)
        mx = max({mx, upL[i], upR[i]});
    for (int i = 0; i < n; i++)
    {
        cnt += (upL[i] == mx || upR[i] == mx);
        fnd += (upL[i] == mx && upL[i] == upR[i]);
    }
    return (cnt == 1 && fnd == 1 && mx % 2 == 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}