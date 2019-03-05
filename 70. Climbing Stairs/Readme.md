# 题目描述：爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

    输入： 2

    输出： 2

    解释： 有两种方法可以爬到楼顶。

    1.  1 阶 + 1 阶

    2.  2 阶

示例 2：

    输入： 3

    输出： 3

    解释： 有三种方法可以爬到楼顶。
  
    1.  1 阶 + 1 阶 + 1 阶

    2.  1 阶 + 2 阶

    3.  2 阶 + 1 阶
    
# 算法
设f(n)为n阶台阶的不同方法数，则f(n)=f(n-1)+f(n-2)

可依次递推求出f(n)，实为斐波那契数列