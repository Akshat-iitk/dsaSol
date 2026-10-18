class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int> pq;
        int day = 0;
        for (auto it : courses) {
            int comptime = it[0];
            int deadline = it[1];
            if (day + comptime <= deadline) {
                pq.push(comptime);
                day += comptime;
            } else if (!pq.empty()) {
                int mxcomptime = pq.top();
                if ((comptime < mxcomptime) &&
                    ((day - mxcomptime + comptime)<=deadline)) {
                    day -= mxcomptime;
                    day += comptime;
                    pq.push(comptime) ;
                    pq.pop();
                }
            }
        }
        return pq.size();
    }
};