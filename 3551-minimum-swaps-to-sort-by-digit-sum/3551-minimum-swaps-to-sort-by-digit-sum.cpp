class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            arr.push_back({sum, nums[i]});
        }

        vector<pair<int, int>> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[sorted[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i] == sorted[i])
                continue;

            int j = i;
            int cycle = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = pos[arr[j].second];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};