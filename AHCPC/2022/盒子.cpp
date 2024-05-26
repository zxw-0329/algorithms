#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 5000011;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int x, y, z;
   cin >> x >> y >> z;
   int x1, y1, z1;
   cin >> x1 >> y1 >> z1;
   vector<int>a(6);
   for (int i = 0; i < 6; i++) {
      cin >> a[i];
   }
   if (x < 0) {
      if (y < 0) {
         if (z < 0) {
            cout << a[0] + a[2] + a[4] << "\n";
         }
         else if (z <= z1) {
            cout << a[0] + a[4] << "\n";
         }
         else {
            cout << a[0] + a[3] + a[4] << "\n";
         }
      }
      else if (y <= y1) {
         if (z < 0) {
            cout << a[2] + a[4] << "\n";
         }
         else if (z <= z1) {
            cout << a[4] << "\n";
         }
         else {
            cout << a[3] + a[4] << "\n";
         }
      }
      else {
         if (z < 0) {
            cout << a[1] + a[2] + a[4] << "\n";
         }
         else if (z <= z1) {
            cout << a[1] + a[4] << "\n";
         }
         else {
            cout << a[1] + a[3] + a[4] << "\n";
         }
      }
   }
   else if (x <= x1) {
      if (y < 0) {
         if (z < 0) {
            cout << a[0] + a[2] << "\n";
         }
         else if (z <= z1) {
            cout << a[0] << "\n";
         }
         else {
            cout << a[0] + a[3] << "\n";
         }
      }
      else if (y <= y1) {
         if (z < 0) {
            cout << a[2] << "\n";
         }
         else if (z <= z1) {
            cout << a[0] + a[2] + a[4] + a[1] + a[3] + a[5] << "\n";
         }
         else {
            cout << a[3] << "\n";
         }
      }
      else {
         if (z < 0) {
            cout << a[1] + a[2] << "\n";
         }
         else if (z <= z1) {
            cout << a[1] << "\n";
         }
         else {
            cout << a[1] + a[3] << "\n";
         }
      }
   }
   else {
      if (y < 0) {
         if (z < 0) {
            cout << a[0] + a[5] + a[2] << "\n";
         }
         else if (z <= z1) {
            cout << a[0] + a[5] << "\n";
         }
         else {
            cout << a[0] + a[3] + a[5] << "\n";
         }
      }
      else if (y <= y1) {
         if (z < 0) {
            cout << a[2] + a[5] << "\n";
         }
         else if (z <= z1) {
            cout << a[5] << "\n";
         }
         else {
            cout << a[3] + a[5] << "\n";
         }
      }
      else {
         if (z < 0) {
            cout << a[1] + a[2] << "\n";
         }
         else if (z <= z1) {
            cout << a[5] + a[1] << "\n";
         }
         else {
            cout << a[5] + a[1] + a[3] << "\n";
         }
      }
   }
   return 0;
}
