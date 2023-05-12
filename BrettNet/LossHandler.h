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

	std::vector<WeightMatrix> backpropagate(
		std::vector<std::vector<double>>, 
		double, 
		std::vector<WeightMatrix>, 
		std::vector<std::string>,
		Activator&);

	WeightMatrix outerProduct(
		const std::vector<double>&,
		const std::vector<double>&);

public:

	std::vector<WeightMatrix> operator()(
		const std::vector<std::vector<double>>&, //X
		const std::vector<std::vector<std::vector<double>>>, //activations
		const std::vector<double>&, //Y
		std::vector<WeightMatrix>, //weights
		int, 
		int,
		std::vector<std::string>,
		Activator&);

	void set_loss(std::string);
};

#endif