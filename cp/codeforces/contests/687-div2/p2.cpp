#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        vector<int> MAP(101);
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            MAP[arr[i]]++;
        }
        int res = INT_MAX;
        for (int i = 1; i <= 100; i++)
        {
            if (MAP[i] == 0)
                continue;
            int cnt = 0, itr = 0;
            while (itr < n)
            {
                if (arr[itr] == i)
                {
                    itr++;
                    continue;
                }
                cnt++;
                itr += k;
            }
            res = min(res, cnt);
        }
        cout << res << "\n";
    }
    return 0;
}