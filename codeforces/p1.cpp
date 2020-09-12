#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
int MAP[101];

int main() {
    int t;
    cin>>t;
    vector<int> ansv;
    while (t-->0) {
        int n;
        cin>>n;
        int a[n], ans=0, numbers_used=0, num=0;
        memset(MAP, 0, sizeof(MAP));
        for (int i=0; i<n; i++) {
            cin>>a[i];
            MAP[a[i]]++;
        }
        while (num<101 && numbers_used < 2) {
            if (MAP[num]==0) {
                while (numbers_used < 2) {
                    ans+=num;
                    numbers_used++;
                }   
            } else if (MAP[num] % 2 == 1) {
                if (numbers_used < 1) {
                    ans+=num;
                    numbers_used++;
                }
            }
            num++;
        }
        cout<<ans<<endl;
    }
    return 0;
}