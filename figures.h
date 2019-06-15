#pragma once
#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.1415

using namespace std;

template <class T> struct Point {
	T x, y;
};

class Figure {
public:
	virtual string name() = 0;
	virtual double area() = 0;
	virtual double per() = 0;
};

template <class T> class Circle : public Figure {
public:
	Circle() {};

	Circle(T radius) {
		this->radius = radius;
	}

	string name(){
		return "Круг";
	}

	double area(){
		return PI * radius * radius;
	}

	double per() {
		return 2 * PI * radius;
	}

private:
	T radius;
};


template <class T> class Triangle : public Figure{
public:
	Triangle() {};

	Triangle(T a, T b, T c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	string name() {
		return "Треугольник";
	}

	double area() {
		double p = this->per() / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}

	double per() {
		return a + b + c;
	}

private:
	T a, b, c;
};

template <class T> class Rectangle : public Figure {
public:
	Rectangle(T a, T b) {
		this->a = a;
		this->b = b;
	}

	string name() {
		return "Прямоугольник";
	}

	double area() {
		return a * b;
	}

	double per() {
		return (a + b) * 2;
	}

private:
	T a, b;
};