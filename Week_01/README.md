# 递归

1. 堆栈容易溢出——代码中限制最大递归深度
2. 容易重复计算——通过散列表保存已求结果
3. 容易死循环——判断环



# 跳表

1. skiplist的复杂度和红黑树一样，而且实现起来更简单。
2. skiplist并发更容易。红黑树在插入和删除的时候可能需要做一些rebalance的操作，这样的操作可能会涉及到整个树的其他部分，而skiplist的操作显然更加局部性一些，锁需要盯住的节点更少，因此在这样的情况下性能好一些
3. 调整level的参数，可以比B树内存空间占用更少。

