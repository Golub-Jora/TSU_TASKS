﻿#include <iostream>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b == d + c || a + d == b + c) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}