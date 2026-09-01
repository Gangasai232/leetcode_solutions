class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int startX = 0, startY = 0;

        // Give every litter an index
        vector<vector<int>> litterIndex(m, vector<int>(n, -1));

        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                }

                if (classroom[i][j] == 'L') {
                    litterIndex[i][j] = litterCount++;
                }
            }
        }

        // If there is no litter
        if (litterCount == 0)
            return 0;

        int allCollected = (1 << litterCount) - 1;

        queue<tuple<int, int, int, int>> q;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        q.push({startX, startY, energy, 0});

        visited[startX][startY][energy][0] = true;

        int moves = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [x, y, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == allCollected)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // Outside grid
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    // Obstacle
                    if (classroom[nx][ny] == 'X')
                        continue;

                    // Need one energy to make the move
                    if (currEnergy == 0)
                        continue;

                    int newEnergy = currEnergy - 1;

                    int newMask = mask;

                    // Collect litter
                    if (classroom[nx][ny] == 'L') {

                        int id = litterIndex[nx][ny];

                        newMask |= (1 << id);
                    }

                    // Reset energy
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    if (!visited[nx][ny][newEnergy][newMask]) {

                        visited[nx][ny][newEnergy][newMask] = true;

                        q.push({
                            nx,
                            ny,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};