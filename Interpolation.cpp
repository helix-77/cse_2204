#include<bits/stdc++.h>
using namespace std;

double forwardInterpolation(const vector<double>& x, const vector<double>& y, double targetX) {
    int n = x.size();
    double h = x[1] - x[0];


    // Calculate divided differences[forward table]
    vector<vector<double>> FWtable(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        FWtable[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            FWtable[i][j] = FWtable[i + 1][j - 1] - FWtable[i][j - 1];
        }
    }

    // Calculate the estimated value
    double u = (targetX - x[0]) / h;        // u = (x - a) / h
    double estimatedY_fw = FWtable[0][0];   // y = f(a)
    double term = 1.0;  

    for (int j = 1; j < n; j++) {
        term *= (u - j + 1) / j;    
        estimatedY_fw += term * FWtable[0][j];
    }

    return estimatedY_fw;
}


double backwardInterpolation(const vector<double>& x, const vector<double>& y, double targetX) {
    int n = x.size();
    double estimatedY_bw = y[n - 1];
    double term = 1.0;
    double h = x[1] - x[0];

    // Calculate divided differences[backward table]
    vector<vector<double>> BWtable(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        BWtable[i][0] = y[n - 1 - i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            BWtable[i][j] = BWtable[i + 1][j - 1] - BWtable[i][j - 1];
        }
    }

    // Calculate the estimated value
    for (int i = 1; i < n; i++) {
        term *= (targetX - x[n - 1 - i]) / h;
        estimatedY_bw += (term / i) * BWtable[0][i];
    }

    return estimatedY_bw;
}


double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double targetX) {
    int n=x.size();
    int i,j;
    double result=0, p;

    for(int i=1;i<=n;i++)
    {
        p=1;
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                p = p* (targetX - x[j])/(x[i] - x[j]);
            }
        }
        result = result + p * y[i];
    }

    return result;
}


int main() {
    //helix
    vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0};       // x-values
    vector<double> y = {1.0, 2.0, 4.0, 8.0, 16.0};      // y=f(x)

    double targetX = 5.0, targetX_FW=1.5, targetX_BW=3.5;           // The point where we want to estimate the function value


    cout << "Given Datapoints:" << endl;
    cout << "x\t\ty" << endl;
    for (size_t i = 0; i < x.size(); ++i) {
        cout << x[i] << "\t\t" << y[i] << endl;
    }
    cout << endl;
    cout << "[Forward Interpolation]  Interpolated value at x=" << targetX_FW << " is: " << forwardInterpolation(x, y, targetX_FW) << endl;
    cout << "[Backward Interpolation] Interpolated value at x=" << targetX_BW << " is: " << backwardInterpolation(x, y, targetX_BW) << endl;
    cout << "[Lagrange Interpolation] Interpolated value at x=" << targetX << " is: " << lagrangeInterpolation(x, y, targetX) << endl;
    
    return 0;
}
