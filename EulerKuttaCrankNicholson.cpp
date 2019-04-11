#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>
#define n 100
using namespace std;


double function(double,double);
double function1(double);
double backwardEuler();
vector<double> forwardEuler(double,double,double);
double richardsonExtrapolation();
double crankNicholson();
double directIteration();
double improvedEuler();
double rungeKutta();

int main()
{

	vector<double> fE = forwardEuler(0, 0, 0.1);
	int j = 0;
	for (double i : fE) { if (j % 10 == 0) cout << j << " " << i << endl; j++; }

	getchar();
	return 0;
}

double function1(double x)
{
	return 2 * x;
}

vector<double> forwardEuler(double xn, double yn, double dx)
{
	vector<double> y;
	y.push_back(yn);
	for (int i = 0; i < n; i++)
	{
		double y_tmp = function1(xn)*dx + yn;
		y.push_back(y_tmp);
		yn = y_tmp;
		xn++;
	}
	return y;
}