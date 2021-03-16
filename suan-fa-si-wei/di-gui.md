# 递归

> 大问题抽象成小问题然后递归解决，最后用大问题的范围

## 递归的重要三点

- 返回类型
- 终止条件
- 下一个递归

## 模板

```c++
type helper(list, left, right){
	if(){
        ...
        return type;
    }
    helper(...);
    do real thing....
    return ...
}
```



## Leetcode

![img](https://gblobscdn.gitbook.com/assets%2F-MViWMsSp3d0zPvsoEgt%2F-MVt0tFXJf_upO8tKeEw%2F-MVt0vVDf2Rw1--9s5f6%2Fimage.png?alt=media&token=01f885aa-ceea-49a7-9319-965bfa386329)

![img](https://gblobscdn.gitbook.com/assets%2F-MViWMsSp3d0zPvsoEgt%2F-MVt0tFXJf_upO8tKeEw%2F-MVt13KjYT9ICdRenQE4%2Fimage.png?alt=media&token=857d6e50-1712-41fd-9c3b-7a5bbf52ac5c)

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //终止条件
        if(head==NULL || head->next==NULL)
            return head;
        //递归
        head->next->next = swapPairs(head->next->next);
        //do real thing...
        return swapNode(head, head->next);
    }

    ListNode* swapNode(ListNode* p, ListNode* q){
        if(q == NULL)
            return p;
        p->next = q->next;
        q->next = p;
        return q;
    }
};
```

![img](https://gblobscdn.gitbook.com/assets%2F-MViWMsSp3d0zPvsoEgt%2F-MVt0tFXJf_upO8tKeEw%2F-MVt1dywsTeO8fqHhKK6%2Fimage.png?alt=media&token=8abd9387-e057-4581-8fa8-1f3d32a28e2e)

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        matrix.assign(n, vector<int>(n,0));
        //用题目给的大范围去递归
        helper(matrix, 0, 0, n, 1);
        return matrix;
    }

    //递归 不需要返回值，直接在引用上动手脚
    void helper(vector<vector<int>>& matrix, int i, int j, int n, int num){
        //终止条件
        if(n < 1)
            return;
        
        //do real thing...
        for(int col = j; col < j+n; col++){
            matrix[i][col] = num;
            num++;
        }
        for(int row = i+1; row < i+n; row++){
            matrix[row][j+n-1] = num;
            num++;
        }
        for(int col = i+n-2; col >= j; col--){
            matrix[i+n-1][col] = num;
            num++;
        }
        for(int row = i+n-2; row >= i+1; row--){
            matrix[row][j] = num;
            num++;
        }
        
        //do完real thing之后再递归
        helper(matrix, i+1, j+1, n-2, num);
    }
};
```

