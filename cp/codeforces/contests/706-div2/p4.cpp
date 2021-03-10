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
    vector<int> upL(n), upR(n), downL(n), downR(n);
    int cur = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            upL[i] = upL[i - 1] + 1;
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > arr[i + 1])
            upR[i] = upR[i + 1] + 1;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1])
            downL[i] = downL[i - 1] + 1;
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] < arr[i + 1])
            downR[i] = downR[i + 1] + 1;
    vector<int> preD(n), sufD(n);
    preD[0] = max(downL[0], downR[0]);
    for (int i = 1; i < n; i++)
        preD[i] = max({preD[i - 1], downL[i], downR[i]});
    sufD[n - 1] = max(downL[n - 1], downR[n - 1]);
    for (int i = n - 2; i >= 0; i--)
        preD[i] = max({preD[i + 1], downL[i], downR[i]});
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] > arr[i] || arr[i] < arr[i + 1])
            continue;
        bool sat1 = true, sat2 = true;
        // left
        int l = upL[i];
        int dl = sufD[i + 1];
        if (dl >= l)
            sat1 = false;
        // right
        int r = upR[i];
        int dr = preD[i - 1];
        if (dr >= r)
            sat2 = false;
        if (sat1 && sat2)
        {
            cout << i + 1 << "\n";
            res++;
        }
    }
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