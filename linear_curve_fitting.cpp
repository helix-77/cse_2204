#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i, j, k, n;
	cout << "Enter the no. of data pairs :";
	cin >> n;

	double x[n], y[n], a, b;
	cout << "Enter the x-axis values:";
	for (i = 0; i < n; i++)
		cin >> x[i];

	cout << "Enter the y-axis values:";
	for (i = 0; i < n; i++)
		cin >> y[i];


	double xsum = 0, x2sum = 0, ysum = 0, xysum = 0; 
	for (i = 0; i < n; i++)
	{
		xsum = xsum + x[i];			 
		ysum = ysum + y[i];			 
		x2sum = x2sum + pow(x[i], 2);
		xysum = xysum + x[i] * y[i]; 
	}

	a = (n * xysum - xsum * ysum) / (n * x2sum - xsum * xsum);	   // calculate slope
	b = (x2sum * ysum - xsum * xysum) / (x2sum * n - xsum * xsum); // calculate intercept

	double y_fit[n];					// array to store the new fitted values of y
	for (i = 0; i < n; i++){
		y_fit[i] = a * x[i] + b; 
	}

    cout<<"\nS.no"<<setw(6)<<"x"<<setw(20)<<"y(observed)"<<setw(19)<<"y(fitted)"<<endl;
    cout<<"----------------------------------------------------\n";

	for (i = 0; i < n; i++){
		cout << i + 1 << "." << setw(8) << x[i] << setw(15) << y[i] << setw(18) << y_fit[i] << endl;
	}


	cout << "\nThe linear fit line is of the form: \t"  << a << "x + " << b << endl;
	
	return 0;
}