#include <bits/stdc++.h>
using namespace std;

#define f(x) 1 / (1 + pow(x, 2))

float trapezoidal(float a, float b, float h, int n)
{
	float integral = 0.0, k, term = 0.0;
	for (int i = 1; i <= n - 1; i++)
	{
		k = a + i * h;
		term = term + 2 * (f(k)); // sum of 2 * f(k)
	}
	integral = h / 2 * (term + f(a) + f(b));
	return integral;
}

float simpson1_3(float a, float b, float h, int n)
{
	float k;
	float term = 0.0;

	for (int i = 1; i <= n - 1; i++)
	{
		k = a + i * h;

		if (i % 2 == 0)
		{
			term = term + 2 * (f(k));
		}
		else
		{
			term = term + 4 * (f(k));
		}
	}

	float integral = h / 3 * (term + f(a) + f(b));
	return integral;
}

float simpson3_8(float a, float b, float h, int n)
{
	float k, term = 0.0;

	for (int i = 1; i <= n - 1; i++)
	{
		k = a + i * h;

		if (i % 3 == 0)
		{
			term = term + 2 * (f(k));
		}
		else
		{
			term = term + 3 * (f(k));
		}
	}

	float integral = (3.0 * h / 8.0) * (term + f(a) + f(b));
	return integral;
}

float exact_value(float a, float b)
{
	float integral = 0.0;
	float f_a = atan(a), f_b = atan(b);
	integral = f_b - f_a;
	return integral;
}

void compareRules(float t, float s13, float s38, float e)
{

	float trapezoidalError = abs((t - e) / e) * 100;
	float simpson1_3Error = abs((s13 - e) / e) * 100;
	float simpson3_8Error = abs((s38 - e) / e) * 100;

	cout << endl;
	cout << "Error percentage for Trapezoidal rule: " << trapezoidalError << "%" << endl;
	cout << "Error percentage for Simpson 1/3rd rule: " << simpson1_3Error << "%" << endl;
	cout << "Error percentage for Simpson 3/8th rule: " << simpson3_8Error << "%" << endl;
}

int main()
{
	// helix
	float a, b, integral = 0.0, h, k;
	int i, n;

	cout << "Enter lower limit: ";
	cin >> a;
	cout << "Enter upper limit: ";
	cin >> b;
	cout << "Enter number of sub intervals: ";
	cin >> n;

	h = (b - a) / n;

	float trapezoidal_Result = trapezoidal(a, b, h, n);
	float simpson1_3Result = simpson1_3(a, b, h, n);
	float simpson3_8Result = simpson3_8(a, b, h, n);
	float exact_Result = exact_value(a, b);

	cout << endl;

	cout << "Integral using Trapezoidal rule: " << trapezoidal_Result << endl;

	cout << "Integral using Simpson 1/3rd: " << simpson1_3Result << endl;

	cout << "Integral using Simpson 3/8th: " << simpson3_8Result << endl;

	cout << "Absolute integral: " << exact_Result << endl;

	compareRules(trapezoidal_Result, simpson1_3Result, simpson3_8Result, exact_Result);

	return 0;
}
