#include <iostream>
#include <math.h>
#include <iomanip>


double getTaylor(double x, double absError, int numberMax)
{
	long double res = 1.0, temp = 1.0;
	int i = 2, factorial = 1;

	while (std::abs(temp) > absError && i / 2 < numberMax)
	{

		temp *= (-x) * x / (i * (i + 1));
		res += temp;
		i += 2;
	}
	if (i >= numberMax && temp > absError)
	{
		throw -1; // генерация исключения  && типичный стейтмент throw
	}
	return res;
}


int main()
{
	setlocale(0, "");

	std::cout << "Введите интервал x (-1;1), шаг интервала, погрешность и количество слагаемых  \n";

	double a, b, alfa, absError;
	int numberMax;

	std::cin >> a >> b >> alfa >> absError >> numberMax;
	if (std::cin.fail())
	{
		std::cerr << "Введены некорректные данные\n";
		return 1;
	}
	if (alfa <= -1 || alfa >= 1)
	{
		std::cerr << "Шаг интервала задан некорректно\n";
		return 1;
	}
	if (a <= -1 || b >= 1)
	{
		std::cerr << "Интервала задан некорректно\n";
		return 1;
	}
	if (absError <= 0)
	{
		std::cerr << "Абсолютная погрешность вычисления задана некорректно\n";
		return 1;
	}
	if (numberMax <= 0)
	{
		std::cerr << "Количество слагаемых должно быть натуральным числом\n";
		return 1;
	}

	for (double x = a; x <= b; x += alfa)
	{
		try
		{
			double res = getTaylor(x, absError, numberMax);

			std::cout << "Для x = " << std::setw(25) << x << std::setw(40) << std::endl;

			if (res > 0)
				std::cout << " Результат равен " << std::setw(25) << res << std::setw(40) << std::endl;
			else
				std::cout << " Недостаточная точность, результат равен " << std::setw(25) << -res << std::setw(40) << std::endl;
			std::cout << "Результат функции библиотеки math.h = " << std::setw(25) << (sin(x)) / (x) << std::setw(40) << std::endl;
		}
		catch (const std::exception& err)
		{

			std::cerr << err.what() << std::endl;
		}
	}


	return 0;
}
