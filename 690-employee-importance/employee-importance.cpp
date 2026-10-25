
class Solution {
public:
    int func(int id,
             unordered_map<int, vector<int>>& graph,
             unordered_map<int, int>& importance) {

        int ans = importance[id];

        for (int child : graph[id]) {
            ans += func(child, graph, importance);
        }

        return ans;
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> importance;

        for (auto employee : employees) {
            importance[employee->id] = employee->importance;
            graph[employee->id] = employee->subordinates;
        }

        return func(id, graph, importance);
    }
};
