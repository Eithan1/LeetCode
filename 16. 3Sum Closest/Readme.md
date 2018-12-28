# 题目描述：最接近的三数之和
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

# 算法
方法一： 暴力求解

方法二： 这道题目给了我们一个nums vector 和一个 target， 让我们找到一组三数之和，并且是最接近于target的。由于我们做过了三数之和，所以差不多是一样方法来做这道题（这里充分说明了，要老老实实顺着题号做下去，较先的题目都可以被用来辅助之后的题）。方法就是先sort一下vector，为啥要sort呢，因为要用到two pointers 来遍历找两数之和，只有在从小到大排序之后的结果上，才能根据情况移动head 和tail。 当确定好了第一个数字后，就在剩下的vector里找两数之和，在加上第一个数字，用这个temp_sum减去target 来得到temp_diff，如果temp_diff比之前的小，那么更新min_diff 和 sumClosest。 利用two pointers 特性， 如果temp_sum 比target 小的话，说明我们需要更大的sum，所以要让head++以便得到更大的sum。 如果temp_sum 比target 大的话，我们就需要更小的sum。如果相等的话，直接return 就可以了。因为都相等了，那么差值就等于0，不会有差值再小的了。
