/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    //自定义比较函数，根据区间的start来排序
    static bool comp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {

        vector<Interval> res;

        if(intervals.empty())
            return res;

        sort(intervals.begin(), intervals.end(), comp);

        res.push_back(intervals[0]); //先将第一个区间放入结果

        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start <= res.back().end) //新的区间与结果中存放的最后一个区间重合
                res.back().end = max(intervals[i].end, res.back().end); //合并区间，因为区间按start递增排列，start不变，end变为两个区间的较大者
            else
                res.push_back(intervals[i]);  //否则无需合并，直接存入结果
        }

        return res;
    }
};
