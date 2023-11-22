#pragma once

#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>


//----------------------------------------------------------------------------------------------------------------------------------------------------------

class Curve
{
public:
	virtual ~Curve() {};
	virtual std::vector<double> getPoint(double t) = 0;
	virtual std::vector<double> getDerivative(double t) = 0;



};


//----------------------------------------------------------------------------------------------------------------------------------------------------------


class Circle : public Curve
{

public:
	Circle(double x, double y, double z, double r)
	{
		CenterX = x;
		CenterY = y;

		radius = r;
	}


	std::vector<double> getPoint(double t) override
	{
		return { radius * std::cos(t) + CenterX, radius * std::sin(t) + CenterY, 0.0 };
	};

	std::vector<double> getDerivative(double t) override
	{
		return { -radius * std::sin(t), radius * std::cos(t), 0.0 };
	};

	double radius;

	double CenterX;
	double CenterY;
	const double CenterZ = 0.0;

};


//----------------------------------------------------------------------------------------------------------------------------------------------------------

class Ellipse : public Curve
{
public:
	Ellipse(double x, double y, double z, double r1, double r2)
	{
		CenterX = x;
		CenterY = y;

		radiusX = r1;
		radiusY = r2;
	}

	std::vector<double> getPoint(double t) override
	{
		return { radiusX * std::cos(t) + CenterX, radiusY * std::sin(t) + CenterY, 0.0 };
	};

	std::vector<double> getDerivative(double t) override
	{
		return { -radiusX * std::sin(t), radiusY * std::cos(t), 0.0 };
	};

	double radiusX;
	double radiusY;

	double CenterX;
	double CenterY;
	const double CenterZ = 0.0;

};


//----------------------------------------------------------------------------------------------------------------------------------------------------------


class Helix :public Curve
{
public:
	Helix(double x, double y, double z, double r, double s)
	{
		CenterX = x;
		CenterY = y;

		radius = r;
		step = s;
	}

	std::vector<double> getPoint(double t) override
	{
		return { radius * std::cos(t) + CenterX, radius * std::sin(t) + CenterY, step * t / (2.0 * M_PI) };
	};

	std::vector<double> getDerivative(double t) override
	{
		return { -radius * std::sin(t), radius * std::cos(t), step / (2.0 * M_PI) };
	};

	double radius;
	double step;

	double CenterX;
	double CenterY;
	const double CenterZ = 0.0;
	
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------