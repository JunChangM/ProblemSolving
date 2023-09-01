#include <iostream>
using namespace std;
int n, t;
pair<int, int> ans;
int num[41][2];
pair<int,int> find(int x) {
    if (x == 0) return { 1,0 };
    else if (x == 1) return { 0,1 };
    else {
        if (num[x][0] != 0 || num[x][1] != 0) return { num[x][0],num[x][1] };
        pair<int, int> a = find(x - 2);
        pair<int, int> b = find(x - 1);
        pair<int, int> c = { a.first + b.first , a.second + b.second };
        num[x][0] = c.first;
        num[x][1] = c.second;
        return c;
    }
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
    num[0][0] = 1;
    num[1][1] = 1;
	while (t--) {
		cin >> n;
        ans = find(n);
        cout << ans.first << ' ' << ans.second << "\n";
	}
    return 0;
}