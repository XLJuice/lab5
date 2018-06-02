#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <tchar.h>
typedef double(*quad_func_t)(double);
double trapez(double, double, double, quad_func_t);
double f(double);
double res();

int main()
{
    setlocale(LC_ALL,"");
	double a = -2, b = 2, eps = 1e-5, S;
	S = trapez(a, b, eps, f);
	double I = res();
	printf("Вычисленный интеграл:\nI=%.5f\nСравниваемй результат\nI=%.5f\n", S, I);
	getchar();
	return 0;
}

double trapez(double a, double b, double eps, quad_func_t f)
{
	double S = 0, x, h = 0.01;
	x = a;
	while (x < b)
	{
		S = S + (f(x + h) + f(x))*h / 2;
		if (0.5*(f(x + h) + f(x))*h >= eps)
			x = x + h;
		else
			break;

	}
	return S;
}

double f(double x)
{
	return fabs(x+1)/sqrt(x+3);
}

double res()
{
	return (10*sqrt(5)-8*sqrt(2)-10)/3 +8*sqrt(2)-4*sqrt(5);
}
