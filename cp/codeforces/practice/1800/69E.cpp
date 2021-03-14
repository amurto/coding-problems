// https://codeforces.com/contest/69/problem/E
// Subsegments

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] == 1)
            st.insert(arr[i]);
        else if (mp[arr[i]] == 2)
            st.erase(arr[i]);
    }
    !st.empty() ? cout << *st.rbegin() : cout << "Nothing";
    cout << "\n";
    for (int i = k; i < n; i++)
    {
        if (arr[i] != arr[i - k])
        {
            if (mp[arr[i - k]] == 1)
                st.erase(arr[i - k]);
            mp[arr[i - k]]--;
            if (mp[arr[i - k]] == 1)
                st.insert(arr[i - k]);
            mp[arr[i]]++;
            if (mp[arr[i]] == 1)
                st.insert(arr[i]);
            else if (mp[arr[i]] == 2)
                st.erase(arr[i]);
        }
        !st.empty() ? cout << *st.rbegin() : cout << "Nothing";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}