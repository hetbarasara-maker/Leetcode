class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({dist[0][0], {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto [curr_safeness, cell] = pq.top();
            int r = cell.first;
            int c = cell.second;
            pq.pop();

            if (r == n - 1 && c == n - 1) {
                return curr_safeness;
            }

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    int next_safeness = min(curr_safeness, dist[nr][nc]);
                    pq.push({next_safeness, {nr, nc}});
                }
            }
        }

        return 0;
    }
};