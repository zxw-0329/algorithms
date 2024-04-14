/*
  例如 nums=[4,3,1,2,1]，在从左到右遍历的过程中，由于 2 的出现，左边的 1 永远不可能与右边的 1 组成一个题目要求的子数组。
  所以当遍历到 2 时，左边的 1 就是无用数据了，可以清除。清除后我们会得到一个从左到右递减的数据结构。

  1.初始化答案等于 n，因为每个元素可以单独组成一个长为 1 的子数组，满足题目要求。
  2.维护一个底大顶小的单调栈，记录元素及其出现次数。
  3.从左到右遍历 nums。
  4.只要 x=nums[i] 大于栈顶，就把栈顶出栈。
  5.如果 x 小于栈顶，把 x及其出现次数 1 入栈。
  6.如果 x 等于栈顶，设栈顶记录的出现次数为 cnt，那么 x可以和左边 cnt 个 x 组成 cnt个满足要求的子数组，把答案增加 cnt，然后把 cnt 加一。

  https://leetcode.cn/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/
*/
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = n;
        stack<pair<int, int>> st;
        st.push({INT_MAX, 0});
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] > st.top().first) {
                st.pop();
            }
            if (nums[i] == st.top().first) {
                ans += st.top().second++;
            } else {
                st.push({nums[i], 1});
            }
        }
        return ans;
    }
};
