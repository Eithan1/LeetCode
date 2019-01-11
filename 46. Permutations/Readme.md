# 题目描述： 全排列
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]

输出:

[

    [1,2,3],

    [1,3,2],

    [2,1,3],

    [2,3,1],

    [3,1,2],

    [3,2,1]

]

# 算法
这里调用了C++ Algorithm中的next_permutation函数，该函数返回值为bool，且已对内部元素变换为了下一个全排列，自己实现的next_permutaion参见[31. Next Permutation](https://github.com/Eithan1/LeetCode/tree/master/31.%20Next%20Permutation)
