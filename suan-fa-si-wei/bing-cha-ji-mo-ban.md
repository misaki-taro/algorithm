# 并查集

## 针对题型

图的连通性

图的环

元素分组

leetcode-1631

## 操作

1、合并Union

2、查询Find

## 模板（Java）

```java
class Bingchaji{
    private int[] parent;
    private int[] size;
    private int n;
    //当前连通分量个数
    private int setCount;

    Bingchaji(int n){
        this.n = n;
        parent = new int[n];
        size = new int[n];
        for(int i = 0; i < n; i++){
            size[i] = 1;
            parent[i] = i;
        }
    }

    int find(int n){
        if(parent[n] == n)
            return n;
        return findRoot(parent[n]);
    }

    boolean union(int x, int y){
        x = findRoot(x);
        y = findRoot(y);
        if(x == y)
            return false;
        //把小的连到大的上
        if(size[x] < size[y]){
            int temp = x;
            x = y;
            y = temp;
        }
        parent[y] = x;
        size[x] += size[y];
        setCount--;
        return true;
    }

    boolean isConnect(int x, int y){
        x = findRoot(x);
        y = findRoot(y);
        return x == y;
    }
}
```
