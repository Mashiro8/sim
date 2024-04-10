#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template<class Fun> class y_combinator_result {
	Fun fun_;
public:
	template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this)),  std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct functional_graph {
	int n = 0;
	vector<int> F;
	vector<bool> in_cycle;
	vector<int> which_cycle;
	vector<int> cycle_root;
	vector<int> cycle_position;
	vector<int> depth;
	vector<vector<int>> children;
	vector<vector<int>> cycles;
	vector<int> jump, jump_dist;

	functional_graph(const vector<int> &f = {}) {
		if (!f.empty())
			build(f);
	}

	void build(const vector<int> &f) {
		F = f;
		n = int(F.size());
		in_cycle.assign(n, false);
		which_cycle.assign(n, -1);
		cycle_root.assign(n, -1);
		cycle_position.assign(n, -1);
		depth.assign(n, -1);
		children.assign(n, {});
		cycles.clear();

		vector<int> seen(n ,-1);

		for (int i = 0; i < n; i++) {
			if (seen[i] >= 0)
				continue;

			int x = i;

			do {
				seen[x] = i;
				x = F[x];
			} while (seen[x] < 0);

			if (seen[x] != i)
				continue;
			vector<int> cycle;
			int y = x;

			do {
				in_cycle[y] = true;
				cycle_position[y] = int(cycle.size());
				which_cycle[y] = int(cycle.size());
				cycle.push_back(y);
				y = F[y];
			} while (y != x);
              cycles.push_back(cycle);
		}

		seen.assign(n, 0);

		for (int i = 0; i < n; i++)
			seen[F[i]] += !in_cycle[i];

		for (int i = 0; i < n; i++)
		{
			children[i].reserve(seen[i]);
		}

		seen.clear();

		for (int i = 0; i < n; i++)
			if (!in_cycle[i])
				children[F[i]].push_back(i);

		jump.assign(n, -1);
		jump_dist.assign(n, -1);
		int cyc_root = -1, which_cyc = -1;

		auto dfs = y_combinator([&](auto self, int node, int parent) -> void) {
			depth[node] = parent < 0 ? 0 : depth[parent] + 1;
			cycle_root[node] = cyc_root;
			which_cycle[node] = which_cyc;
			jump[node] = parent < 0 ? node : jump_dist[parent] == jump_dist[jump[parent]] ? jump[jump[parent]] : parent;
			jump_dist[node] = depth[node] - depth[jump[node]];

			for (int child : children[node])
				self(child, node);
		};

		for (int i = 0; i < n; i++)
			if (in_cycle[i]) {
				cyc_root = i;
				which_cyc = which_cycle[i];
				dfs(i, -1);
			}
	}

	int cycle_length(int node) const {
		return int(cycles[which_cycle[node]].size());
	}

	int go_forward(int v, int64_t k) const {
		if (k >= depth[v]) {
			int root = cycle_root[v];
			k -=depth[v];
			int cyc = which_cycle[root];
			int64_t position = (cycle_position[root] + k) % cycles[cyc].size();
			return cycles[cyc][position];
		}

		while (k > 0)
			if(jump_dist[v] <= k) {
				k -= jump_dist[v];
				v = jump[v];
			} else {
				k--;
				v = F[v];
			}

		return v;
	}
};

int main() 
{
	int N;
	cin >> N;
	vector<int> F(N);

	for (auto &f : F) {
		cin>> f;
		f--;
	}

	functional_graph graph(F);

	vector<int> distinct_ans(N);

	for(int i = 0; i < N; i++) {
		distinct_ans[i] = graph.depth[i] + graph.cycle_length(i);
		cout << distinct_ans[i] << (i < N - 1 ? ' ' : '\n'); 
	}

	cerr << *min_element(distinct_ans.begin(), distinct_ans.end()) << ' ' << *max_element(distinct_ans.begin(), distinct_ans.end());

	int Q;
	cin >> Q;

	for (int q = 0; q < Q; q++) {
		int x;
		int64_t k;
		cin >> x >> k;
		x--;
		cout << graph.go_forward(x, k) + 1 << '\n';
	}
}
