// https://codeforces.com/contest/1304/problem/D
// Shortest and Longest LIS

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<int> f(string &str, int n)
{
    vector<int> arr;
    int i = 0, cur = n;
    stack<int> st;
    while (i < n - 1)
    {
        st.push(cur--);
        if (str[i] == '<')
        {
            while (i < n - 1 && str[i] == '<')
            {
                st.push(cur--);
                i++;
            }
        }
        i++;
        while (!st.empty())
        {
            arr.pb(st.top());
            st.pop();
        }
    }
    if (cur > 0)
        arr.pb(1);
    return arr;
}

void solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<int> mn = f(str, n);
    for (int i = 0; i < n - 1; i++)
        str[i] = (str[i] == '<') ? '>' : '<';
    reverse(str.begin(), str.end());
    vector<int> mx = f(str, n);
    reverse(mx.begin(), mx.end());
    for (int m : mn)
        cout << m << " ";
    cout << "\n";
    for (int m : mx)
        cout << m << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}