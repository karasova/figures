#include <iostream>
#include "figures.h"
#include <locale.h>
#include <string>
#include<vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Circle<double>* circle = new Circle<double>(4);
	Rectangle<double>* rectangle = new Rectangle<double>(4, 9);
	Triangle<double>* triangle = new Triangle<double>(4, 9, 12);

	vector<Figure*>fig;
	fig.push_back(circle);
	fig.push_back(rectangle);
	fig.push_back(triangle);

	double area = 0, per = 0;
	cout << "������:" << endl;
	for (int i = 0; i < fig.size(); i++) {
		cout << fig[i]->name() << ": ������� = " << fig[i]->area() << ", �������� = " << fig[i]->per() << endl;
		area += fig[i]->area();
		per += fig[i]->per();
	}
	cout << endl;

	cout << "����� �������: " << area << endl;
	cout << "����� ��������: " << per << endl;

	system("pause");
	return 0;
}