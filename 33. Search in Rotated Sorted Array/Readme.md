# 题目描述：搜索旋转排序数组
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:


输入: nums = [4,5,6,7,0,1,2], target = 0

输出: 4

示例 2:


输入: nums = [4,5,6,7,0,1,2], target = 3

输出: -1

# 算法
二分搜索法

二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段，如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，
则左半段是有序的，我们只要在有序的半段里用首尾两个数来判断目标值是否在这一区域内，这样就可以确定保留哪半边了，循环递归，直到target落在有序部分使用二分法完成搜索
