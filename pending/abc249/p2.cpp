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

bool solve()
{
    string str;
    cin >> str;
    bool A = false, a = false;
    set<char> st;
    for (char ch : str)
    {
        st.insert(ch);
        if (ch >= 'A' && ch <= 'Z')
            A = true;
        else
            a = true;
    }
    return A && a && (int)str.length() == (int)st.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}