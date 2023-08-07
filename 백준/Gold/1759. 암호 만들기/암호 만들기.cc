#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int l, c;
char a;
vector<char> ch;
string ans;
void printc(int depth) {
	if (depth == l) {
		int count = depth;
		for (int i = 0; i < depth; i++) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') {
				count--;
			}
		}
		if (count < depth && count > 1)
			cout << ans << "\n";
	}
	else {
		for (int i = 0; i < c; i++) {
			int check = 1;
			for (int j = 0; j < depth; j++) {
				if (ch[i] <= ans[j]) {
					check = 0; 
					break;
				}
			}
			if (check) {
				ans[depth] = ch[i];
				printc(depth + 1);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l >> c;
	ans.assign(l, 0);
	for (int i = 0; i < c; i++) {
		cin >> a;
		ch.push_back(a);
	}
	sort(ch.begin(), ch.end());
	printc(0);
	return 0;
}