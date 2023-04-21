#include "OptimizerHandler.h"

template <typename Optimizer>
void OptimizerHandler::optimize_weights(Optimizer& optimizer, std::vector<WeightMatrix>& weights, const std::vector<WeightMatrix>& gradients) {
    optimizer.optimize(weights, gradients);
}

void OptimizerHandler::set_optimizer(const std::string& optimizerName) {
    if (optimizerName == "SGD") {
        SGD(0.1);
    }
    else {
        // handle unsupported optimizer name
    }
}