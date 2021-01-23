// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=512
// 571 - Jugs

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ca, cb, n;
    while (cin >> ca >> cb >> n)
    {
        int a = 0, b = 0;
        char res[2] = {'A', 'B'};
        if (n < ca)
        {
            swap(ca, cb);
            swap(res[0], res[1]);
        }
        while (a != n && b != n)
        {
            if (a == ca)
            {
                cout << "empty " << res[0] << "\n";
                a = 0;
            }
            else if (b == 0)
            {
                cout << "fill " << res[1] << "\n";
                b = cb;
            }
            else
            {
                cout << "pour " << res[1] << " " << res[0] << "\n";
                int req = min(ca - a, b);
                b -= req;
                a += req;
            }
        }
        cout << "success\n";
    }
    return 0;
}