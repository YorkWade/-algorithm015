# 广度优先

``` python
def BFS(graph, start, end):  
    queue = []   
    queue.append([start])   
    visited.add(start) 
    while queue:    
        node = queue.pop()    
        visited.add(node)   
        process(node)    
        nodes = generate_related_nodes(node)    
        queue.push(nodes) 
        
    # other processing work 
```

### 广度优先，需要队列保存同层节点，从而广度遍历

# 深度优先

``` python
visited = set() 
def dfs(node, visited):   
    visited.add(node)  
    # process current node here. 
    ...
    for next_node in node.children():  
        ifnot next_node in visited:     
            dfs(next node, visited) 
```

### 深度优先，一般需要记录访问过得节点

# 贪心算法

1. 每一步选最优
2. 结果不一定最优，现实中一般也不是最优结果
3. 不能回退（动态规划保存之前状态，并可根据状态回退）



# 二分查找

``` python
left, right =0, len(array) -1
while left <= right:   
    mid = left + (left - right) /2
    if array[mid] == target:# find the target!!  
        break or return result     
    elif array[mid] < target:      
        left = mid +1
    else:     right = mid -1
```

1. （left + right）/2防止越界，更骚的操作是:left + （(left - right) >>1） 注意优先级和括号