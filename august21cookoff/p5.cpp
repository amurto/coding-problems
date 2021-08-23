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

const int N = 1005;
int arr[N];
void init()
{
    set<int> st;
    st.insert(0);
    int pre = 0;
    for (int i = 0; i < N; i++)
    {
        int tmp = pre;
        for (int j = 0; pre == tmp; j++)
            if (st.find(pre ^ (1 << j)) == st.end())
                tmp = pre ^ (1 << j);
        int x = pre ^ tmp;
        for (int j = 0; x > 0; x >>= 1, j++)
            if (x & 1)
                arr[i] = j + 1;
        pre = tmp;
        st.insert(pre);
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}
