#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(k);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	// sort the replacement sequence in non-increasing order
	sort(b.rbegin(), b.rend());
	// place them accordingly to where zeroes are present in the original sequence
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			a[i] = b[cnt++];
		}
	}
	// check if the original sequence is non-increasing
	cout << (!is_sorted(a.begin(), a.end()) ? "Yes" : "No") << '\n';
	return 0;
}
