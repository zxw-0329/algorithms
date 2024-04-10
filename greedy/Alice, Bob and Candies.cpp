/*
  模拟
  这只是一个实现问题，可以在 O(n)
  时间内解决，但我们并没有要求这样的解决方案，所以你可以在 O(n^2)
  甚至 O(n^2logn)内解决它。不管怎样，我还是要介绍一下 O(n)的解决方案。
  首先，我们需要维护几个变量： cnt(最初为 0，已走过的步数)、
  l(最左边剩余糖果的位置，最初为 0)、
  r(最右边剩余糖果的位置，最初为 n−1)、 
  ansl(爱丽丝吃掉的糖果总数、最初为 0)、 
  ansr(鲍勃吃掉的糖果总和，最初为 0)、 
  suml(爱丽丝最后一次移动时吃掉的糖果总和，最初为 0 )和 sumr (鲍勃最后一次移动时吃掉的糖果总和，最初为 0)。
  因此，让我们在 l≤r时模拟下面的过程：
  如果 cnt的步数是偶数，那么现在是爱丽丝的一步棋，我们需要再保留一个变量 nsuml=0--爱丽丝在这一步棋中吃掉的糖果的总和。如何计算呢？
  在 l≤r 和 nsuml≤sumr之间，让我们吃掉最左边的一颗糖果，因此变量会这样变化： nsuml:=nsuml+al,l:=l+1.之后，
  我们在 ansl中加入 nsuml，用 nsuml替换 suml(分配 suml:=nsuml)，并在 cnt中增加 1
 。如果 cnt的步数是奇数，那么下棋过程相同，只是从鲍勃一方下

  也可以用双端队列做
  https://codeforces.com/contest/1352/problem/D
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   vector<int>a(n);
   deque<int>d;
   for (int i = 0; i < n; i++) {
      //cin >> a[i];
      int x;
      cin >> x;
      d.push_back(x);
   }
   int cnt = 1;
   int sa = d.front();
   d.pop_front();
   int sb = 0;
   int pa = sa;
   int pb = 0;
   while (d.size()) {
      int ssb = 0;
      while (!d.empty() && ssb <= pa) {
         ssb += d.back();
         d.pop_back();
      }
      cnt++;
      //copy(d.begin(), d.end(), ostream_iterator<int>(cerr, " "));
      //cerr << "\n";
      sb += ssb;
      if (ssb <= pa) {
         break;
      }
      else {
         pb = ssb;
      }
      if (d.empty())break;
      int ssa = 0;
      while (!d.empty() && ssa <= pb) {
         ssa += d.front();
         d.pop_front();
      }
      //copy(d.begin(), d.end(), ostream_iterator<int>(cerr, " "));
     // cerr << "\n";
      sa += ssa; cnt++;
      if (ssa <= pb) {
         break;
      }
      //  if (d.empty())break;
      else {
        
         pa = ssa;
      }

   }
   cout << cnt << " " << sa << " " << sb << "\n";
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
