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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> seq(n);
        int itr = 0;
        for (int i = 0; itr < n; i++, itr += 2)
            seq[itr] = arr[i];
        itr = 1;
        for (int i = n - 1; itr < n; i--, itr += 2)
            seq[itr] = arr[i];
        for (int s: seq)
            cout << s << " ";
        cout << "\n";
    }
    return 0;
}