﻿#include <iostream>

using namespace std;
int a, b, c, d;
int main()
{
    cin >> a >> b >> c >> d;
    for (int i = 1000; i >= 0; i-=1) {
        if (a * i * i * i + b * i * i + c * i + d == 0)cout << i << " ";
    }
}
