#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void display(vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    if (a > b)
    {
        if (b == n / 2 && a == b + 1)
        {
            for (int i = 0, j = n; i < n; i++, j--)
                arr[i] = j;
            display(arr);
            return;
        }
        else
        {
            cout << "-1\n";
            return;
        }
    }
    stack<int> st1, st2;
    for (int i = 1; i < a; i++)
        st2.push(i);
    for (int i = b + 1; i <= n; i++)
        st1.push(i);
    st1.push(a);
    st2.push(b);
    if ((int)st1.size() > n / 2 || (int)st2.size() > n / 2)
    {
        cout << "-1\n";
        return;
    }
    for (int i = a + 1; i < b; i++)
    {
        if ((int)st1.size() < n / 2)
            st1.push(i);
        else
            st2.push(i);
    }
    for (int i = 0; i < n / 2; i++)
    {
        arr[i] = st1.top();
        st1.pop();
    }
    for (int i = n / 2; i < n; i++)
    {
        arr[i] = st2.top();
        st2.pop();
    }
    display(arr);
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