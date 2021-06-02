class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>(0));
        vector<int> visited;
        vector<int> visiting;
        for (int i = 0; i < prerequisites.size(); i++) {
            int prereq = prerequisites[i][1];
            int course = prerequisites[i][0];
            if (course == prereq) return false;
            if (find(adj[course].begin(), adj[course].end(), prereq) != adj[course].end()) return false;
            if (find(adj[prereq].begin(), adj[prereq].end(), course) == adj[prereq].end()) adj[prereq].push_back(course);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (find(visited.begin(), visited.end(), i) == visited.end()) {
                if (!doDFS(adj, visited, visiting, i)) {
                    cout << "fail at main with course#: " << i << endl;
                    return false;
                }
            }
        }
        return true;
    }
    
    bool doDFS(vector<vector<int>>& adj, vector<int>& visited, vector<int>& visiting, int courseNumber) {
        cout << "dfs called on course #: " << courseNumber << endl;
        if (find(visiting.begin(), visiting.end(), courseNumber) != visiting.end()) {
            cout << "already visited course#: " << courseNumber << endl;
            return false; 
        }
        else if (find(visited.begin(), visited.end(), courseNumber) == visited.end()) {
            visiting.push_back(courseNumber);
            cout << "visiting " << courseNumber << endl;
            if (adj[courseNumber].size() > 0) {
                for (auto num : adj[courseNumber]) {
                    if (!doDFS(adj, visited, visiting, num)) {
                        cout << "error when visiting course#: " << num << endl;
                        return false;
                    }
                }
            }
            cout << "done visiting " << courseNumber << endl;
            auto it = find(visiting.begin(), visiting.end(), courseNumber);
            visiting.erase(it);
            for (auto i : visiting) cout << i << " ";
            cout << endl;
            visited.push_back(courseNumber);
        }
        return true;
    }
};