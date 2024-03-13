#include <bits/stdc++.h>
using namespace std;

int main()
{
    float trueValue, x1, x2, x3, e1, e2, e3, e, r;
    cout << "Enter true value: ";
    cin >> trueValue;
    cout << "Enter approximate values: " << endl;
    cout << "X1: ";
    cin >> x1;
    cout << "X2: ";
    cin >> x2;
    cout << "X3: ";
    cin >> x3;

    e1 = fabs(trueValue - x1);
    e2 = fabs(trueValue - x2);
    e3 = fabs(trueValue - x3);
    cout << "Closest Value: ";

    if (e1 <= e2 && e1 <= e3)
    {
        e = x1;
        r = e1;
    }

    else if (e2 <= e3 && e2 <= e1)
    {
        e = x2;
        r = e2;
    }

    else if (e3 <= e2 && e3 <= e1)
    {
        e = x3;
        r = e3;
    }

    cout << e << endl << endl;
    cout << "Absolute error: " << r << endl;
    cout << "Relative error: " << r / trueValue << endl;
    cout << "Percentage error: " << (r * 100) / e << "%" << endl;

    return 0;
}