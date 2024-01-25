#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    deque<int> d;

    int n;
    cin >> n;

    string command;
    int num;

    for (int i = 0; i < n; i++) {
        cin >> command;

        if (command == "push_front") {
            cin >> num;
            d.push_front(num);
        }
        else if (command == "push_back") {
            cin >> num;
            d.push_back(num);
        }
        else if (command == "size") {
            cout << d.size() << endl;
        }
        else if (command == "empty") {
            cout << d.empty() << endl;
        }
        else if (d.empty()) {
            cout << -1 << endl;
        }
        else if (command == "pop_front") {
            cout << d.front() << endl;
            d.pop_front();
        }
        else if (command == "pop_back") {
            cout << d.back() << endl;
            d.pop_back();
        }
        else if (command == "front") {
            cout << d.front() << endl;
        }
        else if (command == "back") {
            cout << d.back() << endl;
        }
    }

	return 0;
}

