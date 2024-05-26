#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
struct s {
   string s;
}p[60];
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> p[i].s;
   }
   int l = p[0].s.size();
   string g = p[0].s;
   sort(g.begin(), g.end());
   int ans = INT_MAX;
   for (int i = 0; i < n; i++) {
      string t = p[i].s;
      int s1 = 0;
      for (int j = 0; j < n; j++) {
         if (j != i) {
            string k = p[j].s;
            int cnt = 0;
            while (k != t) {
               cnt++;
               if (cnt > l) {
                  cout << "-1" << "\n";
                  return 0;
               }
               char c = k.front();
               k.erase(k.begin());
               k.push_back(c);
               
            }
            s1 += cnt;
         }
      }
      ans = min(s1, ans);
   }
   cout << ans << endl;
   return 0;
}
