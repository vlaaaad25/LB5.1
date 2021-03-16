#include <iostream>
#include <math.h>
using namespace std;
double SubFunctionValue(double);
double FunctionValue(double, double, double);
double& SubFunctionReference(double&);
double FunctionReference(double&, double&, double&);
double* SubFunctionPointer(double*);
double FunctionPointer(double*, double*, double*);
int main()
{
	double x1(2.6), x2(8.7), x3(0.1);
	cout << "Our starting value: x1 = " << x1 << "  x2 = " << x2 << "  x3 = " << x3 << endl;
	cout << "\nTransmission by value: " << FunctionValue(x1, x2, x3) << endl;
	cout << "\nTransmission by reference: " << FunctionReference(x1, x2, x3) << endl;
	cout << "\nTransmission by pointer: " << FunctionPointer(&x1, &x2, &x3) << endl;
}
double SubFunctionValue(double x)
{
	return 6 * pow(x, 2) + tan(x);
}
double FunctionValue(double x1, double x2, double x3)
{
	return (SubFunctionValue(x1) * SubFunctionValue(x2) * SubFunctionValue(x3) / SubFunctionValue(x1) + SubFunctionValue(x2) + SubFunctionValue(x3));
}
double& SubFunctionReference(double& x)
{
	x = 6 * pow(x, 2) + tan(x);
	return x;
}
double FunctionReference(double& x1, double& x2, double& x3)
{
	return (SubFunctionReference(x1) * SubFunctionReference(x2) * SubFunctionReference(x3)) / (SubFunctionReference(x1) + SubFunctionReference(x2) + SubFunctionReference(x3));
}
double* SubFunctionPointer(double* x)
{
	*x = 6 * pow(*x, 2) + tan(*x);
	return x;
}
double FunctionPointer(double* x1, double* x2, double* x3)
{
	return (*SubFunctionPointer(x1) * *SubFunctionPointer(x2) * *SubFunctionPointer(x3)) / (*SubFunctionPointer(x1) + *SubFunctionPointer(x2) + *SubFunctionPointer(x3));
}
