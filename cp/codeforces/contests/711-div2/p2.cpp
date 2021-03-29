#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, w;
    cin >> n >> w;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    multiset<int> ms(arr.begin(), arr.end());
    int ch = 1, cw = w;
    while (!ms.empty())
    {
        auto it = ms.upper_bound(cw);
        it--;
        if (it == ms.end() || *it > cw)
        {
            ch++;
            cw = w;
            continue;
        }
        int e = *it;
        cw -= e;
        ms.erase(ms.lower_bound(e));
    }
    return ch;
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