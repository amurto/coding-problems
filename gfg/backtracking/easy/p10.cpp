// Target Sum Subsets

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void TSS(vector<int> &arr, vector<int> &ans, int cur, int soFar, int tar)
{
    if (cur == arr.size()) {
        if (soFar == tar)
        {
            for (int v : ans)
                cout << v << ", ";
            cout << ".\n";
        }
        return;
    }
    if (soFar + arr[cur] <= tar)
    {
        ans.push_back(arr[cur]);
        TSS(arr, ans, cur + 1, soFar + arr[cur], tar);
        ans.pop_back();
    }
    TSS(arr, ans, cur + 1, soFar, tar);
}

int main()
{
    int n, tar;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> tar;
    vector<int> ans;
    TSS(arr, ans, 0, 0, tar);
    return 0;
}