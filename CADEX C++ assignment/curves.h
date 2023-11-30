#pragma once
#define DLL_EXPORT __declspec(dllexport)
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>


//----------------------------------------------------------------------------------------------------------------------------------------------------------


DLL_EXPORT class Curve
{
public:
	
	virtual std::vector<double> getPoint(double t) = 0;
	virtual std::vector<double> getDerivative(double t) = 0;
	virtual ~Curve() {};


};


//----------------------------------------------------------------------------------------------------------------------------------------------------------


DLL_EXPORT class Circle : public Curve
{

public:
	Circle(double x, double y, double z, double r);


	std::vector<double> getPoint(double t) override;


	std::vector<double> getDerivative(double t) override;

	double getRadius();

private:
	double radius;

	double CenterX;
	double CenterY;
	const double CenterZ = 0.0;

};


//----------------------------------------------------------------------------------------------------------------------------------------------------------


DLL_EXPORT class Ellipse : public Curve
{
public:
	Ellipse(double x, double y, double z, double r1, double r2);


	std::vector<double> getPoint(double t) override;


	std::vector<double> getDerivative(double t) override;

private:
	double radiusX;
	double radiusY;

	double CenterX;
	double CenterY;
	const double CenterZ = 0.0;
};


//----------------------------------------------------------------------------------------------------------------------------------------------------------


DLL_EXPORT class Helix :public Curve
{
public:
	Helix(double x, double y, double z, double r, double s);


	std::vector<double> getPoint(double t) override;


	std::vector<double> getDerivative(double t) override;

private:
	double radius;
	double step;

	double CenterX;
	double CenterY;
	const double CenterZ = 0.0;

};


//----------------------------------------------------------------------------------------------------------------------------------------------------------


