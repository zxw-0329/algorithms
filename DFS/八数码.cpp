/*
  一个字符串对应一个状态点，从一个布局变到另一个布局对应走过一条边
  
  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   string s;
   cin >> s;
   string ed;
   cin >> ed;
   unordered_map<string, int>d;
   queue<string>q;
   q.push(s);
   d[s] = 0;
   while (!q.empty()) {
      string t = q.front();
      int p = d[t];
      q.pop();
      if (t == ed) {
         cout << d[t] << "\n";
         return 0;
      }
      int m = t.find('.');
      int x = m / 3;
      int y = m % 3;
      for (int i = 0; i < 4; i++) {
         int nx = x + dx[i];
         int ny = y + dy[i];
         if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)continue;
         
         swap(t[nx * 3 + ny], t[m]);
         if (!d.count(t)) {
            q.push(t);
            d[t] = p + 1;
         }
         swap(t[nx * 3 + ny], t[m]);
      }
   }
   cout << -1 << "\n";
   return 0;
}
