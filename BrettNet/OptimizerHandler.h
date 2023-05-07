#ifndef OPTIMIZERHANDLER_H
#define OPTIMIZERHANDLER_H

#include "Optimizer.h"
#include <string>

class OptimizerHandler
{
	template <typename Optimizer>
	void optimize_weights(Optimizer& optimizer, std::vector<WeightMatrix>& weights, const std::vector<WeightMatrix>& gradients);
	std::string optimizer;

public:
	void operator()(std::vector<WeightMatrix>, std::vector<WeightMatrix>);
	void set_optimizer(const std::string& opt);

};

#endif	