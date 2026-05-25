class Solution {
public:
    bool check(unordered_map<int, vector<int>>& adjList, vector<bool>& visited, int source, int destination)
    {
        if(source == destination) // basic termination condition of the recursive function
        {
            return true;
        }

        if(visited[source] == true) // if a node is already visited it means there's a cycle, so avoid it by returning false
        {
            return false;
        }

        visited[source] = true;

        for(auto &node : adjList[source])
        {
            if(check(adjList, visited, node, destination))
            {
                return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adjList;

        for(vector<int>& edge : edges) // making the adjacency list
        {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n, false);

        return check(adjList, visited, source, destination);
    }
};