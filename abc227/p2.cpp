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

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    set<int> st;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int a = 1; a <= 1000; a++)
        for (int b = 1; b <= 1000; b++)
            st.insert(4 * a * b + 3 * a + 3 * b);
    for (int x : arr)
        if (st.find(x) == st.end())
            res++;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}