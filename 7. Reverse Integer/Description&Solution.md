# 题目描述
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321

示例 2:

输入: -123
输出: -321

示例 3:

输入: 120
输出: 21

注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

# 算法
简单的取余反转
## 注意范围：
对应4个字节的有符号int,数值范围为 [−2^31,  2^31 − 1]

INT_MIN=−2^31

INT_MAX=2^31 − 1

**记得要在溢出前判断是否将会溢出，否则溢出后值已经自动修改，无法判断**