#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> seq(3);
    cin >> seq[0] >> seq[1] >> seq[2];
    sort(seq.begin(), seq.end());
    if (seq[0] != seq[1] && seq[1] != seq[2])
        cout << 0 << "\n";
    else if (seq[0] != seq[1])
        cout << seq[0] << "\n";
    else if (seq.back() != seq[1])
        cout << seq.back() << "\n";
    else 
        cout << seq[0] << "\n";
    return 0;
}