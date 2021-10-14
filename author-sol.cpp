#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	int last_zero = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		// save the position of the last occurrence of zero within the sequence
		if (a[i] == 0) {
			last_zero = i;
		}
	}
	vector<int> b(k);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	if (k > 1) {
		// if 'k' is greater than 1, then automatically the answer is Yes, because
		// we can simply swap two elements and destroy the propert of increasing order
		cout << "Yes";
	} else {
		// otherwise, place the single replacement element within the sequence
		// and check if the sequence is non-increasing by finding out if at least one
		// element is less than or equal to the previous adjacent element
		a[last_zero] = b[0];
		bool valid = false;
		for (int i = 1; i < n; i++) {
			if (a[i] <= a[i - 1]) {
				valid = true;
				break;
			}
		}
		cout << (valid ? "Yes" : "No");
	}
	cout << '\n';
	return 0;
}
