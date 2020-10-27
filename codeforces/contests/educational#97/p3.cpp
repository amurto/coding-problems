#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q-- > 0)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        // sort(arr.begin(), arr.end());
        unordered_set<int> SET;
        int ans = 0;
        for (int val : arr)
        {
            int t1 = val, t2 = val;
            while (t1 > 0 && SET.find(t1) != SET.end())
                t1--;
            while (t2 > 0 && SET.find(t2) != SET.end())
                t2++;
            if (t1 == 0 || t2 - val < val - t1)
            {
                SET.insert(t2);
                ans += t2 - val;
            }
            else
            {
                SET.insert(t1);
                ans += val - t1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}