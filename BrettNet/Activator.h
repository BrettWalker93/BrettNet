#ifndef ACTIAVATOR_H
#define ACTIVATOR_H

#include <string>
#include <vector>

class Activator
{
protected:
	double sigmoid(double);
	double relu(double);

public:

	double activate(std::string, double);

	double derivative(std::string, double);
};

#endif