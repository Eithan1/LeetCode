# 题目描述：在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8

输出: [3,4]

示例 2:

输入: nums = [5,7,7,8,8,10], target = 6

输出: [-1,-1]

# 算法
使用两次二分查找，分别找到第一次出现target和最后一次出现target的索引

找第一次出现的方法是：当nums[mid] == target时，我们仍认为要找的target还可能在左边，与之前在左边的条件合成为 nums[mid] >= target。
判断找到条件不只是nums[mid] == target，还要满足nums[mid - 1] != target，保证找到的是第一个target

找最后一次的同理

