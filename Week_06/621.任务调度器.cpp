/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int len = tasks.size();
        vector<int> taskCount(26);
        for(int i = 0;i<len;i++)
            taskCount[tasks[i]-'A']++;
        //按照任务出现次数，由大到小排序，先执行次数最多的
        sort(taskCount.begin(),taskCount.end(),[](int & x,int& y){return x>y;});

        //找出最后一行任务执行的个数,与A频率相同，否则在前几行已经执行完了。
        int lastTaskCount = 1;
        while(lastTaskCount<taskCount.size()&&taskCount[lastTaskCount] == taskCount[0] )
            lastTaskCount++;
        //如果任务的个数很多（大于n）,最大执行时间就为任务个数
        //如果任务的个数不多（小于n），最大执行时间为（n+1)*(maxTaskCount-1)+lastTaskCount
        //n+1：一个任务+n个冷却时间
        //maxTaskCount-1：除最后一行外，其余都是满执行（无空闲时间）
        //lastTaskCount最后一行任务
        return max(len,(n+1)*(taskCount[0]-1)+lastTaskCount);

    }
};
// @lc code=end

