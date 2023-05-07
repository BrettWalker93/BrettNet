#ifndef LOSSHANDLER_H
#define LOSSHANDLER_H

#include "WeightMatrix.h"
#include <string>
#include <vector>

class LossHandler
{
protected:

	std::string loss_fun;

	std::vector<double> history;

	//todo modularize
	double compute_loss(double, double);

public:
	std::vector<WeightMatrix> operator()(const std::vector<std::vector<double>>&, const std::vector<double>&, const std::vector<double>&, int batch_start, int batch_size);
	void set_loss(std::string);
};

#endif