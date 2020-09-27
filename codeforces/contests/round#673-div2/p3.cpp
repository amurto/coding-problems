#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        vector<int> ans(n,-1);
        int v, MAX=0;
        unordered_map<int, int> MAP;
        for (int i=0; i<n; i++) {
            cin>>v;
            MAP[v]++;
            MAX=max(MAX, v);
        }
        for (int i=n-1; i>=0; i--) {
            int MIN=-1;
            for (int j=1; j<=MAX; j++) {
                if (MAP[j] >= n/(i+1))
                    if (MIN < 0)
                        MIN = j;
                    else
                        MIN = min(MIN, j);
            }
            if (MIN >= 0 && (MAP[MIN] == n/(i+1)))
                MAP[MIN]--;
            ans[i] = MIN;
        }
        for (int val: ans)
            cout<<val<<" ";
        cout<<endl;
    }
    return 0;
}