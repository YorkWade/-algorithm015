

## 总结

### 数据结构

* 数据结构底层都是由数组（连续）或者链表（非连续）组成

* 跳表是有序的链表，且额外增加了几层链表，用于索引。具有实现简单，并发性好的特点，常用来替代二叉搜索树。

* 树是特殊的链表，不在是一个分支，而是多个分支

* 二叉树是有两个分支的链表。二叉搜索树，左右子树严格排序（左子树小于根节点，右子树大于根节点。

* 二叉搜索树的搜索性能，跟树的高度有关，且为了查找插入删除操作更有效率，有平衡二叉树、B树、红黑树等

* 图是特殊的树，树的子节点连通。

* 栈是先进后出，队列是先进先出，底层可以使用数组（连续），也可以使用链表（非连续）实现

* 堆是特殊的二叉树，对顶是最大值（最小值），左右子不需要严格排序（区别于二叉搜索树），但保证小于（大于）根节点。常用来实现优先级队列。

  

  ![](https://raw.githubusercontent.com/YorkWade/-algorithm015/master/Week_010/image/data_structure.bmp)

  

## 算法



* 计算机的逻辑里，只有if else 分支，for/while循环，递归。

* 分治、回溯、DFS、BFS、贪心、二分查找、动态规划等算法实现，本质上使用递归。

* 递归，需要找最近重复子问题，数据归纳法

  ``` python
  defrecursion(level, param1, param2, ...):  
      # recursion terminator 
      if level > MAX_LEVEL:    process_result  return
      # process logic in current level 
      process(level, data...)  
      # drill down 
      self.recursion(level +1, p1, ...)  
      # reverse the current level status if needed
  ```

		* 分治算法主要是分组递归，且范围互不重叠，最后合并结果

``` python
defdivide_conquer(problem, param1, param2, ...):  
    # recursion terminator 
    if problem is None:    
        print_result  
        return
    # prepare data  
    data = prepare_data(problem)   
    subproblems = split_problem(problem, data)  
    # conquer subproblems  
    subresult1 = self.divide_conquer(subproblems[0], p1, ...)   
    subresult2 = self.divide_conquer(subproblems[1], p1, ...)   
    subresult3 = self.divide_conquer(subproblems[2], p1, ...)  
    ...
    # process and generate the final result  
    result = process_result(subresult1, subresult2, subresult3, ...) 
    # revert the current level states
```

* 回溯，试错思想，如果得不到正确答案，返回上面一步或几步。
* DFS 深度优先，适合计算每条分治的过程答案，但不便于计算同一层其他分治中最优答案。

```python
visited = set() 
defdfs(node, visited):   
    visited.add(node)  
    # process current node here. 
    ...
    for next_node in node.children():  
        ifnot next_node in visited:     
            dfs(next node, visited) 
```



* BFS 广度优先，适合计算每层所有分治的最优值，但不便于记录最终节点的过程答案。实现时，需要使用队列记录当前层所有节点

```python
defBFS(graph, start, end):  
    queue = []   
    queue.append([start])   
    visited.add(start) 
    while queue:    
        node = queue.pop()    
        visited.add(node)   
        process(node)    
        nodes = generate_related_nodes(node)    
        queue.push(nodes) 
```

* 贪心算法 每次都选当前最优，且不能回退。可以解决一些最优化问题，如：求图中的最小生成树、求哈夫曼编码等。然而对于工程和生活中的问题，贪心法一般不能得到我们所要求的答案
* 二分查找  必须是已排序、内存连续（数组），可用索引取值。注意（left+right)越界技巧

```python
left, right =0, len(array) -1
while left <= right:   
    mid = (left + right) /2
    if array[mid] == target:
        # find the target!!  
        break or return result     
    elif array[mid] < target:      
        left = mid +1
    else:      
        right = mid -1
```

* 动态规划 需要单独记录状态，根据前后相邻的状态规律（动态方程），计算出最值（最值为统计值，不是达成最值得所有过程最优解）。无需遍历所有分支进行计算。字符串+动态规划，可以计算出最值时，计算出最优解。  动态规划的步骤：1 定义状态数组 2定义动态方程 3初始化动态数组。

* 字典树（Trie树） 是一种树形结构。典型应用是用于统计和排序大量的字符串。最大限度地减少无谓的字符串比较

  ```python
  class Trie(object): 
      def __init__(self):    
          self.root = {}    
          self.end_of_word ="#"
      def insert(self, word):    
          node = self.root  
          for char in word:     
              node = node.setdefault(char, {})    
              node[self.end_of_word] = self.end_of_word  
      def search(self, word):    
          node = self.root  
          for char in word:  
              if char notin node:  return False     
              node = node[char]  
              return self.end_of_word in node  
      def startsWith(self, prefix):    
          node = self.root  
          for char in prefix:  
              if char notin node:  
                  return False     
              node = node[char]  
              return True
  ```

  

* 并查集 应用场景：组团、配对问题 Group or not ?

  ```python
  def init(p):  # for i = 0 .. n: p[i] = i;
      p = [i for i in range(n)]  
  def union(self, p, i, j):   
      p1 = self.parent(p, i)   
      p2 = self.parent(p, j)   
      p[p1] = p2  
  def parent(self, p, i):   
      root = i  
      while p[root] != root:    
          root = p[root]  
      while p[i] != i: # 路径压缩 ?   
          x = i; i = p[i]; p[x] = root  
          return root
  ```

  

* 剪枝，遇到确定不是最优解，提前结束回退计算。避免不必要的计算。
* 双向搜索 可以从起点和终点两个方向同时搜索，那边代价小，优先搜索哪边。
* 搜索方向：广度优先搜索、深度优先搜索
* 启发式搜索 A*搜索 启发式函数是一种告知搜索方向的方法

* 位运算 是八皇后等算法的最优算法。
  1. 将x 最右边的n 位清零：x& (~0 << n）
  2. 获取x 的第n 位值（0 或者1）：(x >> n) & 1
  3. 获取x 的第n 位的幂值：x& (1 <<n）
  4. 仅将第n 位置为1：x | (1 << n)
  5. 仅将第n 位置为0：x & (~ (1 << n))
  6. 将x 最高位至第n 位（含）清零：x& ((1 << n) -1)

* 布隆过滤器 一个很长的二进制向量和一系列随机映射函数。布隆过滤器可以用于检索一个元素是否在一个集合中。 优点是空间效率和查询时间都远远超过一般的算法， 缺点是有一定的误识别率和删除困难。

* LRU缓存 Hash Table + Double LinkedList  O(1) 查询 O(1) 修改、更新

  ```python
  class LRUCache(object): 
      def __init__(self, capacity): 
          self.dic = collections.OrderedDict() 
          self.remain = capacity
      def get(self, key): 
          if key notin self.dic: 
              return-1
          v = self.dic.pop(key) 
          self.dic[key] = v   
          # key as the newest one 
          return v 
      def put(self, key, value): 
          if key in self.dic: 
              self.dic.pop(key) 
          else: if self.remain >0: 
                  self.remain -=1
          else:   # self.dic is full
              self.dic.popitem(last=False) 
              self.dic[key] = value
          
  ```

* 排序

  ![](https://raw.githubusercontent.com/YorkWade/-algorithm015/master/Week_010/image/sort.bmp)

* 字符串 常常和动态规划联系一起
