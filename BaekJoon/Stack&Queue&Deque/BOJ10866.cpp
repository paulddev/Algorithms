#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	deque<int> dq;
	while (n--) {
		string cmd; cin >> cmd;
		if (cmd == "push_front") {
			int x; cin >> x;
			dq.push_front(x);
		}else if (cmd == "push_back") {
			int x; cin >> x;
			dq.push_back(x);
		}
		else if (cmd == "pop_front") {
			if (dq.empty())cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (dq.empty())cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (cmd == "front") {
			if (dq.empty())cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else if (cmd == "back") {
			if (dq.empty())cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
	}
	return 0;
}