#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, v;
        cin >> n;
        vector<int> ans(n + 1, -1), GAP(n + 1, 0), LAST(n + 1, 0);

        // Calculate Max Gaps for each value in the array
        for (int i = 1; i <= n; i++)
        {
            cin >> v;
            GAP[v] = max(GAP[v], i - LAST[v]);
            LAST[v] = i;
        }

        // Step remaining from last loop. Check for gap from last occurence to boundary
        for (int x = 1; x <= n; x++)
            GAP[x] = max(GAP[x], n - LAST[x] + 1);

        // Iterate from the smallest element and update k for all gaps >= GAP[current element]
        // If gap is already updated, that is, a smaller element is already found so go to next element
        for (int x = 1; x <= n; x++)
            for (int i = GAP[x]; i <= n && ans[i] == -1; i++)
                ans[i] = x;
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}