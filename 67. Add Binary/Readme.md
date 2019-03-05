# 题目描述：二进制求和
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

    输入: a = "11", b = "1"

    输出: "100"

示例 2:

    输入: a = "1010", b = "1011"

    输出: "10101"
    
 # 算法
 从低位到高位，按位相加，考虑每位的得数和进位
 
    得数 = （此位两数相加+进位）% 2
    
    进位 = （此位两数相加+进位）/ 2
    
 注意：
 string转为vector从低位至高位存储