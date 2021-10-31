#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(const double x);
double fuctorial(double num);

int main()
{
	double tp, tk, z;
	int n;

	cout << "tp = "; cin >> tp;
	cout << "tk = "; cin >> tk;
	cout << "n = "; cin >> n;

	double dt = (tk - tp) / n;

	cout << fixed;
	cout << "----------------------" << endl;
	cout << "|" << setw(7) << "t" << " |"
		<< setw(10) << "z" << " |"
		<< endl;
	cout << "----------------------" << endl;

	double t = tp;

	while (t <= tk)
	{
		z = f(t * t) + 2 * f(2 * t + 1);

		cout << "|" << setw(7) << setprecision(2) << t << " |"
		<< setw(10) << setprecision(5) << z << " |"
		<< endl;

		t += dt;
	}

	cout << "----------------------" << endl;
	return 0;
}

double f(const double x)
{
	if (abs(x) >= 1)
		return (sin(x) + 1) / (sin(x) + cos(x));
	else
	{
		double S = 0;
		int i = 0;
		double a = pow(x, 1 + 2 * i) / fuctorial(1 + 2 * i);

		S = a;
		
		do
		{
			i++;
			double R = (x * x * fuctorial(2 * i - 1)) / fuctorial(2 * i + 1);
			a *= R;
			S += a;
		} while (i < 8);

		return S;
	}
}

double fuctorial(double num) {
	double factorial = 1.0;
	for (int i = 1; i <= num; ++i) {
		factorial *= i;
	}
	return factorial;
}