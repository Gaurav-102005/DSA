class Solution {
    vector<int> seg;

    void build(int idx, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[idx] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build(idx * 2, l, mid, arr);
        build(idx * 2 + 1, mid + 1, r, arr);

        seg[idx] = seg[idx * 2] ^ seg[idx * 2 + 1];
    }

    void update(int idx, int l, int r, int p, int val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (p <= mid)
            update(idx * 2, l, mid, p, val);
        else
            update(idx * 2 + 1, mid + 1, r, p, val);

        seg[idx] = seg[idx * 2] ^ seg[idx * 2 + 1];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[idx];

        if (r < ql || qr < l)
            return 0;

        int mid = l + (r - l) / 2;

        return query(idx * 2, l, mid, ql, qr) ^
               query(idx * 2 + 1, mid + 1, r, ql, qr);
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), depth(n, 0), order;
        vector<int> sz(n, 1), heavy(n, -1);

        vector<int> st = {0};
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            int largest = 0;

            for (int v : adj[u]) {
                if (parent[v] != u) continue;

                sz[u] += sz[v];

                if (sz[v] > largest) {
                    largest = sz[v];
                    heavy[u] = v;
                }
            }
        }

        vector<int> head(n), pos(n);
        int timer = 0;

        vector<pair<int, int>> chains = {{0, 0}};

        while (!chains.empty()) {
            auto [start, h] = chains.back();
            chains.pop_back();

            for (int u = start; u != -1; u = heavy[u]) {
                head[u] = h;
                pos[u] = timer++;

                for (int v : adj[u]) {
                    if (parent[v] == u && v != heavy[u])
                        chains.push_back({v, v});
                }
            }
        }

        vector<int> arr(n);

        for (int u = 0; u < n; u++)
            arr[pos[u]] = 1 << (s[u] - 'a');

        seg.assign(4 * n, 0);
        build(1, 0, n - 1, arr);

        vector<bool> answer;

        for (string& q : queries) {
            string type;
            int u;
            string third;

            stringstream ss(q);
            ss >> type >> u >> third;

            if (type == "update") {
                char c = third[0];
                s[u] = c;

                int mask = 1 << (c - 'a');
                update(1, 0, n - 1, pos[u], mask);
            } else {
                int v = stoi(third);
                int mask = 0;

                while (head[u] != head[v]) {
                    if (depth[head[u]] < depth[head[v]])
                        swap(u, v);

                    mask ^= query(
                        1, 0, n - 1,
                        pos[head[u]], pos[u]
                    );

                    u = parent[head[u]];
                }

                if (depth[u] > depth[v])
                    swap(u, v);

                mask ^= query(1, 0, n - 1, pos[u], pos[v]);

                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};