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
        int key, digit = 0, len = 0, press = 0;
        cin >> key;
        while (key > 0)
        {
            digit = key % 10;
            len++;
            press += len;
            key /= 10;
        }
        press += (digit - 1) * 10;
        cout << press << "\n";
    }
    return 0;
}