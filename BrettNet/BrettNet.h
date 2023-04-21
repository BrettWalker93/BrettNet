#ifndef BRETTNET_H
#define BRETTNET_H

#include "Layer.h"
#include "WeightMatrix.h"
#include "OptimizerHandler.h"
#include "LossHandler.h"
#include <string>
#include <vector>

class BrettNet {
protected:
	std::vector<Layer> layers; //

	std::string task; //type of output, e.g., "binary classification", "probability", "real-value estimation", etc.

	int in; //size of input
	int length; //number of hidden layers
	int out; //size of output

	std::vector<WeightMatrix> weights;
	
	std::string optimizer;
	OptimizerHandler optimizerHandler;

	LossHandler lossHandler;

	std::string descriptor; //optional description of network

public:

	//constructor
	BrettNet();

	BrettNet(std::string); //one output

	BrettNet(std::string, int); //multiple output

	//methods
	std::string architecture();

	void addLayer(std::string, std::string, int);

	void teach(std::vector<std::vector<double>> input, std::vector<double> output, Optimizer optimizer);

};

#endif

#include "Optimizer.h"