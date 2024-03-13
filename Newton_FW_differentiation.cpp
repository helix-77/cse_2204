#include<bits/stdc++.h>
using namespace std;

// Numerical differentiation using the forward difference method
double forwardDifference(const vector<double>& x, const vector<double>& y, size_t index, double h) {
    if (index >= x.size() || index >= y.size()) {
        cerr << "Error: Invalid index." << endl;
        return 0.0;
    }

    if (index + 1 >= x.size() || index + 1 >= y.size()) {
        cerr << "Error: Not enough data points for forward difference." << endl;
        return 0.0;
    }

    return (y[index + 1] - y[index]) / (x[index + 1] - x[index]);
}

int main() {
    size_t dataSize;
    cout << "Enter the number of data points: ";
    cin >> dataSize;

    vector<double> x(dataSize);
    vector<double> y(dataSize);

    cout << "Enter the x and y values for each data point:" << endl;
    for (size_t i = 0; i < dataSize; ++i) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    size_t index;
    cout << "Enter the index of the point at which to compute the derivative: ";
    cin >> index;

    double h;
    cout << "Enter the step size (h) for numerical differentiation: ";
    cin >> h;

    double derivative = forwardDifference(x, y, index, h);

    cout << "Data point at index " << index << ": (" << x[index] << ", " << y[index] << ")" << endl;
    cout << "Numerical derivative at x = " << x[index] << ": " << derivative << endl;

    return 0;
}
