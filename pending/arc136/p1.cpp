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

string solve()
{
    int n;
    string str, res = "";
    cin >> n >> str;
    for (int i = 0; i < n;)
    {
        if (str[i] == 'C')
        {
            res.pb('C');
            i++;
        }
        else
        {
            int r = i, cnt = 0;
            while (r < n && str[r] != 'C')
            {
                if (str[r] == 'A')
                    cnt += 2;
                else
                    cnt++;
                r++;
            }
            int h = cnt / 2;
            while (h > 0)
            {
                res.pb('A');
                h--;
            }
            if (cnt & 1)
                res.pb('B');
            i = r;
        }
    }
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