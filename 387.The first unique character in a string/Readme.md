# 题目描述：字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"

返回 0.

s = "loveleetcode",

返回 2.
 

注意事项：您可以假定该字符串只包含小写字母。

# 算法：
类似python字典，键对应26个字母，值对应在该字符串中出现次数，最后查找值等于1的即可。

注意：
a[s[i]]会自动将s[i]对应的字符转化为对应asicII码的整数。
