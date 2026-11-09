class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        int n = arrival.size();

        set<int> freeServers;

        for (int i = 0; i < k; i++) {
            freeServers.insert(i);
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > busy;

        vector<int> count(k, 0);

        for (int i = 0; i < n; i++) {

            while (!busy.empty() &&
                   busy.top().first <= arrival[i]) {

                int server = busy.top().second;
                busy.pop();

                freeServers.insert(server);
            }

            if (freeServers.empty())
                continue;

            int start = i % k;

            auto it = freeServers.lower_bound(start);

            if (it == freeServers.end()) {
                it = freeServers.begin();
            }

            int server = *it;

            freeServers.erase(it);

            count[server]++;

            busy.push({
                arrival[i] + load[i],
                server
            });
        }

        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};