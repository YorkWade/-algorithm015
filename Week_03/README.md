### 分治 和 回溯 本质上都是的递归

### 最优重复性就是动态规划

# 递归

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







# 分治

``` python
defdivide_conquer(problem, param1, param2, ...):  
	# recursion terminator 
	if problem is None:    
		print_result  return
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

# 回溯

 回溯一般有reserse the current level status
    
```python
defrecursion(level, param1, param2, ...): 
# recursion terminator 
if level > MAX_LEVEL:    process_result  return

# process logic in current level 
process(level, data...)  

# drill down 
self.recursion(level +1, p1, ...)  

# reverse the current level status if needed 
```