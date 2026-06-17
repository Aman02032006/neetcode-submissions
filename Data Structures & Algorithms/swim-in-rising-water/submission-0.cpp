class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }

    int find(int i) {
        int root = i;
        
        while (root != parent[root]) {
            root = parent[root];
        }
        
        int curr = i;
        while (curr != root) {
            int next_node = parent[curr];
            parent[curr] = root;
            curr = next_node;
        }
        
        return root;
    }

    bool unite(int i, int j, vector<vector<int>>& grid, int n) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i == root_j) return false; 
        else if (grid[root_i / n][root_i % n] > grid[root_j / n][root_j % n]) parent[root_j] = root_i;
        else parent[root_i] = root_j;
        
        return true;
    }
    
    bool is_connected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
    int n;

    bool valid(int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < n);
    }

    int coord(int i, int j) {
        return i * n + j;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (valid(i + 1, j)) q.push({max(grid[i][j], grid[i + 1][j]), coord(i, j), coord(i + 1, j)});
                if (valid(i, j + 1)) q.push({max(grid[i][j], grid[i][j + 1]), coord(i, j), coord(i, j + 1)});
            }
        }

        int N = n * n;
        UnionFind dsu(N);

        int ans = max(grid[0][0], grid[n-1][n-1]);

        while (!dsu.is_connected(0, N - 1) && !q.empty()) {
            auto [t, u, v] = q.top();
            q.pop();

            dsu.unite(u, v, grid, n);

            if (dsu.is_connected(0, N - 1)) {
                ans = t;
                break;
            }
        }

        return ans;
    }
};
