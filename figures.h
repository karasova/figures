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
		return "Êðóã";
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
		return "Òðåóãîëüíèê";
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
		return "Ïðÿìîóãîëüíèê";
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

template <class T> class Poligon : public Figure {
public:
	Poligon() {}

	void setDot(T x, T y) {
		Point<T> d;
		d.x = x;
		d.y = y;

		dots.push_back(d);
	}

	string name() {
		return "Полигон";
	}

	double area() {
		double area = 0;

		for (int i = 0; i < dots.size() - 2; i++) {
			area += ((dots[i + 1].x - dots[0].x) * (dots[i + 2].y - dots[0].y)) - ((dots[i + 1].y - dots[0].y) * (dots[i + 2].x - dots[0].x));
		}

		return abs(area) / 2;
	}

	double per() {
		double per = 0;

		for (int i = 0; i < dots.size() - 1; i++) {
			per += sqrt((dots[i + 1].x - dots[i].x) * (dots[i + 1].x - dots[i].x) + (dots[i + 1].y - dots[i].y) * (dots[i + 1].y - dots[i].y));
		}

		per += sqrt((dots[dots.size() - 1].x - dots[0].x) * (dots[dots.size() - 1].x - dots[0].x) + (dots[dots.size() - 1].y - dots[0].y) * (dots[dots.size() - 1].y - dots[0].y));

		return per;
	}


private:
	vector<Point<T>> dots;
};
