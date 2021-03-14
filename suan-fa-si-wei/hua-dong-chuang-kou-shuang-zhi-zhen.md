# 滑动窗口&双指针

## 1、滑动窗口

维护一个子区间，使之符合一定条件

有两个操作

* 扩张 
* 平移 ---&gt; 整个区间平移

### 模板

```cpp
int left = 0;
int right = 0;
int sum = 0;
while(right<n){
    //判断是否平移
    if(){
        //平移附带的东西
        //平移
        left++;
    }
    //如果上述条件没平移就相当于扩张
    right++
}
```

### leetcode

#### [424. 替换后的最长重复字符](https://leetcode-cn.com/problems/longest-repeating-character-replacement/)

![](../.gitbook/assets/image%20%286%29.png)

![](../.gitbook/assets/image%20%287%29.png)

本题可以先退化成考虑 K=0_K_=0 的情况，此时题目就变成了求解字符串中最长连续子串长度问题了。 我们先可以通过这个特例先了解一下滑动窗口的求解过程

而当k&gt;0的时候

如果窗口大小大于当前窗口最长连续子串个数max加上可替换的k即max+k

right-left+1 &gt; max+k

这说明是不肯能的，所以left++，要平移

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
  if (s.size() <= 0)
        {
            return 0;
        }

        // 用一个数组来保存当前窗口内每个字符的最大的长度
        int *cnt = new int[26];
        memset(cnt, 0, sizeof(int) * 26);

        // 滑动窗口的最左侧
        int left = 0;
        // 记录当前相同的单个字符的最大个数
        int maxCharCnt = 0;
        for (int right = 0; right < s.size(); ++right)
        {
            int charInt = s[right]-'A';
            ++cnt[charInt];
            maxCharCnt = max(maxCharCnt, cnt[charInt]);
            // 当前窗口即使通过修改也无法满足了，那就要移动窗口left
            if (right - left + 1 > maxCharCnt + k)
            {
                // 最左边字符
                --cnt[s[left]-'A'];
                ++left;
            }
            // 否则left不变，移动right，窗口加大 1
        }

        return s.size() - left;
    }
};
```

#### [1208. 尽可能使字符串相等](https://leetcode-cn.com/problems/get-equal-substrings-within-budget/)

```text
给你两个长度相同的字符串，s 和 t。

将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。

用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。

如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。

如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。



示例 1：

输入：s = "abcd", t = "bcdf", cost = 3
输出：3
解释：s 中的 "abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。
示例 2：

输入：s = "abcd", t = "cdef", cost = 3
输出：1
解释：s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为 1。
示例 3：

输入：s = "abcd", t = "acde", cost = 0
输出：1
解释：你无法作出任何改动，所以最大长度为 1。


提示：

1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s 和 t 都只含小写英文字母。
```

同样用滑动窗口

* 扩张：maxCost&gt;0
* 平移：maxCost&lt;0

```cpp
int equalSubstring(string s, string t, int maxCost) {
    int n = s.size();
    int left = 0;
    int right = 0;
    int* dis = new int[n];
    for (int i = 0; i < n; i++)
    {
        dis[i] = abs(s[i]-t[i]);
    }
    while(right < n){
        maxCost -= dis[right];
        //平移
        if(maxCost<0){
            maxCost += dis[left];
            left++;
        }
        right++;
    }
    delete[] dis;
    return right-left;
}
```

