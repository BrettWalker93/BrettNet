#ifndef BRETTNET_H
#define BRETTNET_H

#include "Layer.h"
#include "WeightMatrix.h"
#include "OptimizerHandler.h"
#include "LossHandler.h"
#include "Activator.h"
#include <string>
#include <vector>
#include <map>
#include <variant>

class BrettNet {
protected:
	std::vector<Layer> layers; //

	std::string task; //type of output, e.g., "binary classification", "probability", "real-value estimation", etc.

	using options = std::variant<int, double, std::string>;
	std::map<std::string, options> params;

	std::vector<WeightMatrix> weights;
	
	OptimizerHandler optimizerHandler;

	LossHandler lossHandler;

	Activator activator;

	std::string descriptor; //optional description of network

	void compile();

	//todo:: modularize output options
	double forward(std::vector<double>);

public:

	//constructor
	BrettNet();

	BrettNet(std::string, int); //one output

	BrettNet(std::string, int, int); //multiple output

	//methods
	std::string architecture();

	void addLayer(std::string, std::string, int);

	void teach(std::vector<std::vector<double>> input, std::vector<double> output);

};

#endif

#include "Optimizer.h"