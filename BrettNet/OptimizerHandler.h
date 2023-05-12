#ifndef OPTIMIZERHANDLER_H
#define OPTIMIZERHANDLER_H

#include "Optimizer.h"
#include <string>
#include <variant>

class OptimizerHandler
{
	using Optimizer = std::variant<SGD>;
	Optimizer optimizer;

	void optimize_weights(std::vector<WeightMatrix>& weights, const std::vector<WeightMatrix>& gradients);

public:
	void operator()(std::vector<WeightMatrix>, std::vector<WeightMatrix>);
	void set_optimizer(const std::string& opt, double);

};

#endif	