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

bool is_present(vector<string> &arr, string &str)
{
    for (string s : arr)
        if (s == str)
            return true;
    return false;
}

void addOne(string &str, int n)
{
    int cur = n - 1;
    while (str[cur] != '0')
        cur--;
    str[cur] = '1';
    for (int i = cur + 1; i < n; i++)
        str[i] = '0';
}

string solve()
{
    int n;
    cin >> n;
    string str(n, '0');
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (is_present(arr, str))
        addOne(str, n);
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}