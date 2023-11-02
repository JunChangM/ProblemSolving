#include <iostream>
using namespace std;
int main() {
    int n, a, b, c;
    b = 0; c = 0;
    for (int i = 1; i <= 9; i++) {
        cin >> a;
        if (a > b) {
            c = i;
            b = a;
        }
    }
    cout << b << "\n" << c;
    return 0;
}