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
        sort(arr.begin(), arr.end(), greater<int>());
        arr[0]++;
        for (int i = 1; i < n; i++)
            if (arr[i - 1] - arr[i] > 1)
                arr[i]++;
        unordered_set<int> st(arr.begin(), arr.end());
        cout << st.size() << "\n";
    }
    return 0;
}