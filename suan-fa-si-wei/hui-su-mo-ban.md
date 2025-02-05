# 回溯

## leetcode131.分割回文串

```text
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
```

### 解决方法：回溯（recursion）+dp

**枚举--&gt;回溯--&gt;dfs**

对于此类要枚举所有方案的题目，我们都应该先想到「回溯算法」。

「回溯算法」从算法定义上来说，不一定要用 DFS 实现，但通常结合 DFS 来做，难度是最低的。

「回溯算法」根据当前决策有多少种选择，对应了两套模板。

每一次独立的决策只对应 选择 和 不选 两种情况：

确定结束回溯过程的 base case

遍历每个位置，对每个位置进行决策（做选择 -&gt; 递归 -&gt; 撤销选择）

```text
void dfs(当前位置, 路径(当前结果), 结果集) {
    if (当前位置 == 结束位置) {
        结果集.add(路径);
        return;
    }选择当前位置;    
    dfs(下一位置, 路径(当前结果), 结果集);
    撤销选择当前位置;
    dfs(下一位置, 路径(当前结果), 结果集);
}
```

每一次独立的决策都对应了多种选择（通常对应了每次决策能选择什么，或者每次决策能选择多少个 ...）:

确定结束回溯过程的 base case

遍历所有的「选择」

对选择进行决策 \(做选择 -&gt; 递归 -&gt; 撤销选择\)

```cpp
void dfs(选择列表, 路径(当前结果), 结果集) {
    if (满足结束条件) {
        结果集.add(路径);
        return;
    }

    for (选择 in 选择列表) {
        做选择;
        dfs(路径’, 选择列表, 结果集);
        撤销选择;
    }
}
```

这里的dp的定义：

```text
def:
    dp[i][j]   字符串s[i...j]是否是回文串
    当且仅当s[i]==s[j]&&dp[i+1][j-1]为true
```

```cpp
void dfs(字符串, 路径(当前结果), 结果集) {
    if (末尾指针超出数组) {
        结果集.add(路径);
        return;
    }

    for (选择s[i..j] in 选择列表) {
        if(当前s[i..j]是回文串)
            dfs(路径’, 选择列表-当前s[i..j], 结果集);
            撤销选择;
    }
}
```

## leetcode17.电话号码的字母组合

![](../.gitbook/assets/image%20%282%29.png)

![](../.gitbook/assets/image%20%283%29.png)

同样是通过回溯，我们来使用模板

```cpp
void dfs(整个区域){
    if(当前答案ans和电话号一样长){
        result.add(ans);
        return;
    }
    for(在整个区域里的号码:选一个数字){
        for(数字代表的字母:字母){
            ans.add
            dfs(下一个数字)
            ans.pop_back    //撤销
        }
    }
}
```

```cpp
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    private:
        string ans;
        vector<string> result;
        vector<vector<char>> alphaList;
        int n;
    public:
        vector<string> letterCombinations(string digits) {
            n = digits.size();
            if(n == 0)
                return result;
            //init alphaList
            for(int i = 0; i < 7; i++){
                vector<char> temp;
                if(i == 0 || i == 1 ){
                    alphaList.push_back(temp);
                    continue;
                }
                temp.push_back('a'+3*(i-2)+0);
                temp.push_back('a'+3*(i-2)+1);
                temp.push_back('a'+3*(i-2)+2);
                alphaList.push_back(temp);
            }
            vector<char> temp1;
            temp1.push_back('p');
            temp1.push_back('q');
            temp1.push_back('r');
            temp1.push_back('s');
            alphaList.push_back(temp1);
            vector<char> temp2;
            temp2.push_back('t');
            temp2.push_back('u');
            temp2.push_back('v');
            alphaList.push_back(temp2);
            vector<char> temp;
            temp.push_back('w');
            temp.push_back('x');
            temp.push_back('y');
            temp.push_back('z');
            alphaList.push_back(temp);
            dfs(digits, 0);
            return result;
        }

        void dfs(string s, int i){
            if(ans.size() == n){
                result.push_back(ans);
                return;
            }
            for(int j = i; j < n; j++){
                int num = s[j]-'0';
                for(int k = 0; k < alphaList[num].size(); k++){
                    ans = ans+alphaList[num][k];
                    dfs(s, j+1);
                    ans.pop_back();
                }
            }
        }

        void print(){
            for(int i = 0; i < result.size(); i++){
                cout<<result[i]<<" ";
            }
        }
};

int main(){
    Solution solution;
    string digits = "23";
    solution.letterCombinations(digits);
    solution.print();
    return 0;
}
```

