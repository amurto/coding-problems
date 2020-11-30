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
        int sum, diff;
        cin >> sum >> diff;
        if (diff > sum - 2)
        {
            cout << "Impossible\n";
            continue;
        }
        int low = 1, high = sum - 1;
        while (low <= high) {
            int mid = (low + high)/2;
            if (mid + sum-mid )
        }
    }
    return 0;
}