// https://codeforces.com/contest/1506/problem/F
// Triangular Paths

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int dis(int r1, int c1, int r2, int c2)
{
    int d = r2 - r1, res = 0;
    res += d / 2;
    if (d & 1 && ((r1 + c1) & 1))
        res++;
    return res;
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<pii> arr(n + 1);
    arr[0].first = arr[0].second = 1;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].first;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].second;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int r1 = arr[i].first, c1 = arr[i].second, r2 = arr[i + 1].first, c2 = arr[i + 1].second;
        // (r1,c1) -> (r2,c2)
        int d = r2 - r1;
        if (d == c2 - c1)
        {
            if ((r1 + c1) % 2 == 0)
                res += d;
            continue;
        }
        if (c1 == c2)
        {
            res += dis(r1, c1, r2, c2);
            continue;
        }
        if ((r1 + c1) % 2 == 0)
            r1++;
        if ((r2 + c2) % 2 == 0)
        {
            res++;
            r2--;
        }
        res += dis(r1, c1, r2 - (c2 - c1), c1);
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