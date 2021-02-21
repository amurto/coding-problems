#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<int> minOperations(string boxes)
{
    int n = boxes.length();
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (boxes[j] == '1')
                cnt += abs(i - j);
        res[i] = cnt;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string boxes;
    cin >> boxes;
    vector<int> res = minOperations(boxes);
    return 0;
}