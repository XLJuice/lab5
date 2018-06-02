#include <math.h>
#include <stdio.h>
#include <tchar.h>
#include <locale.h>
#define SIGN_FUNC(f, x) ((f(x) > 0)? 1 : (f(x) < 0)? -1 : 0)
#define CHECK_ROOT_TOL(f, x, e)\
if (fabs(f(x)) <= (e))\
{\
return x;\
}
#define CHECK_DIFF_SIGN(s1, s2) s1 != s2
#define PRINT_MID_STAGE

typedef double(*funct_t)(double);
int localize_root(double, double, funct_t);
double bisection(double, double, double, funct_t);
double secant(double, double, double, funct_t);
double Newton(double, double, double, funct_t, funct_t);
double f(double);
double df(double);

int main() {
	setlocale(LC_ALL,"");
	double eps = 1e-6;
	double a=-10, b=10, x, h=0.01;
	for (x = a; x < b; x += h)
	{
		if (localize_root(x, x + h, f))
		{
			printf("Интервал:[%.3f, %.3f]\n", x, x + h);
			double x0 = bisection(x, x + h, eps, f);
			printf("Корень: %lf\n", x0);
			double x1 = secant(a, b, eps, f);
			printf("Корень: %lf\n", x1);
			double x2 = Newton(a, b, eps, f, df);
			printf("Корень: %lf\n", x2);
		}
	}
	getchar();
	return 0;
}

int localize_root(double a, double b, funct_t f)
{
	return SIGN_FUNC(f, a) != SIGN_FUNC(f, b);
}

double bisection(double a, double b, double eps, funct_t f) {
	double funcA, funcB, funcC, c=0;
	printf("---------------------Метод бисекции----------------------\n");
	while (fabs(a - b) > eps)
	{
		double c = (a + b) / 2;
		int sgn1 = SIGN_FUNC(f, a);
		int sgn2 = SIGN_FUNC(f, b);
		int sgn3 = SIGN_FUNC(f, c);
#ifdef PRINT_MID_STAGE
		printf("%.5f\t%.5f\t%.5f\n", a, c, b);
		printf("%d\t%d\t%d\n", sgn1, sgn3, sgn2);

#endif
			CHECK_ROOT_TOL(f, a, eps);
		CHECK_ROOT_TOL(f, c, eps);
		CHECK_ROOT_TOL(f, b, eps);
		if (CHECK_DIFF_SIGN(sgn1, sgn3))
		{
			b = c;
		}
		else {
			if (CHECK_DIFF_SIGN(sgn3, sgn2))
			{
				a = c;
			}
		}
	}
	return c;
}

double secant(double a, double b, double eps, funct_t f){
	printf("-----------------------Метод хорд------------------------\n");
	do{
		a = b - ((b - a) * f(b)) / (f(b) - f(a));
		b = a - ((a - b) * f(a)) / (f(a) - f(b));
	} while (fabs(f(b)) > eps);
	return b;
}

double Newton(double a, double b, double eps, funct_t f, funct_t df) {
	printf("--------------------Метод косательных--------------------\n");
	a = b + 2 * eps;
	do{
		a = b;
		b = b - f(b) / df(b);
	} while (fabs(b - a) > eps);
	return b;
}

double f(double x){
	return cos(x) - 2*x + 1.5;
}

double df(double x) {
	return - sin(x)- 2;
}
