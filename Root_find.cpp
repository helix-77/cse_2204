#include <bits/stdc++.h>
using namespace std;

#define f(x) pow(x, 2) - x - 1
#define g(x) sqrt(1 + x)  //f(x) as x = g(x)
#define df(x) 2 * x - 1  

double a = 0.0, b = 5.0, e = 0.0001; // Initial interval [a, b], e-> Tolerance
int max_iteration = 50;                         // Max iterations
double x0 = 1.0;                    // Initial guess

double bisectionMethod(double a, double b, double e){
    double c, fa, fb, fc;
    fa = f(a), fb = f(b);

    if (f(a) * f(b) >= 0)
    {
        cout << "Incorrect a and b";
        throw std::exception();
    }

    c = a;
    while (max_iteration--)
    {
        c = (a + b) / 2;
        fc = f(c);
        
        if (fc == 0.0)
        {
            // cout << "Root = " << c<<endl;
            break;
        }
        else if (fc * fa < 0)
        {
            // cout << "Root = " << c<<endl;
            b = c;
        }
        else
        {
            // cout << "Root = " << c<<endl;
            a = c;
        }
    }
    return c;
}

double falsePositionMethod(double a, double b, double e){
    double x, fa, fb, f;
    fa = f(a);
    fb = f(b);

    int it = 1;
    do
    {
        // x = a - (a - b) * fa / (fa - fb);
        x=(a*fb-b*fa)/(fb-fa);
        f = f(x);

        // cout << "Iteration-" << it << ":\t x = " << setw(10) << x << " and f(x) = " << setw(10) << f(x) << endl;

        if (fa * f < 0){
            b = x;
            fb = f;
        }
        else{
            a = x;
            fa = f;
        }
        it = it + 1;

    } while (fabs(f) > e);

    return x;
}

double iterativeMethod(double a, double b, double e){
    double c;
    int step=1, N;
    do
	 {
        c = g(a);
        // cout<<"Iteration-"<< step<<":\t c = "<< setw(10)<< c<<" and f(c) = "<< setw(10)<< f(c)<< endl;

        step = step + 1;

        if(step>N)
        {
            cout<<"Not Convergent.";
            exit(0);
        }

        a = c;

	 }while( fabs(f(c)) > e);

     return c;
}

double newtonRaphson(double x0, double e){
    double f1,f, df1;
    double x1=x0; // Initial guess
    int it = 1, max_it=50;
    do
    {
        f1 = f(x1);
        df1 = df(x1);

        if (df1 == 0.0){
            cout << "Divide by zero error!";
            exit(0);
        }

        x1 = x0 - f1 / df1;
        // cout << "Iteration-" << it << ":\t x = " << setw(10) << x1 << " and f(x) = " << setw(10) << f(x1) << endl;

        x0=x1;

        it = it + 1;

        if (it > max_it){
            cout << "Not Convergent.";
            exit(0);
        }
        f = f(x1);

    } while (fabs(f(x1)) > e);

    return x1;
}


int main()
{
    // helix
    cout << "The function used is x^2-x-1\n";
    cout << "Initial Interval[a,b]: " << a << " , " << b << endl;
    cout << "Tolerance(e): " << e << endl;
    cout << "Max Iterations: " << max_iteration << endl;
    cout << "\n";
    cout << "[Bisection Method] Root = " << bisectionMethod(a, b, e) << endl;
    cout << "[False Position Method] Root = " << falsePositionMethod(a, b, e) << endl;
    cout << "[Iterative Method] Root = " << iterativeMethod(a, b, e) << endl;
    cout << "[Newton Raphson Method] Root = " << newtonRaphson(x0,e) << endl;
    cout << "\n";
    
    return 0;
}