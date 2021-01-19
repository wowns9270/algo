#include<bits/stdc++.h>
using namespace std;


int dp[100001][31]; // 최대는 log 100000 => 16정도 넉넉히 30
int depth[100001]; // 트리의 깊이

int n;

vector<vector<int> > arr;

void dfs(int idx, int cnt) {

	depth[idx] = cnt; // 현재 깊이

	for (int i = 0; i < arr[idx].size(); i++) {

		int k = arr[idx][i];

		if (depth[k] == -1) {

			dp[k][0] = idx;
			dfs(k, cnt + 1);

		}
	}
}

void go() {


	for (int j = 1; j <= 30; j++) {

		for (int i = 1; i <= n; i++) {

			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}

	}
}

int lca(int x, int y) {

	if (depth[x] < depth[y]) swap(x, y);


	int f = depth[x] - depth[y];

	int idx = 0;
	while (f) {

		if (f & 1) x = dp[x][idx];
		idx++;

		f >>= 1;
	}

	if (x == y) return x;

	for (int i = 30; i >= 0; i--) {

		if (dp[x][i] != dp[y][i]) {

			x = dp[x][i];
			y = dp[y][i];

		}

	}

	return dp[x][0];


}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;  //루트는 1 

	arr.resize(n + 1);

	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);

		//연결쌍을 저장
	}
	memset(depth, -1, sizeof(depth));
	dfs(1 , 0); // 1번정점부터 dp[x][0] 와 depth[x] 를 구한다. 


	go(); // 각 노드의 조상들을 구해준다.

	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		int a ,b ; cin >> a >> b;
		cout<< lca(a, b) <<"\n";
	}



}