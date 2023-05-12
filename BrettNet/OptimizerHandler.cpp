#include "OptimizerHandler.h"

void OptimizerHandler::optimize_weights(std::vector<WeightMatrix>& weights, const std::vector<WeightMatrix>& gradients) {
    
    optimizer(weights, gradients);

}

void OptimizerHandler::set_optimizer(const std::string& optimizerName, double _rate) {
    if (optimizerName == "SGD") {
        optimizer = SGD(_rate);
    }
    else {
        // handle unsupported optimizer name
    }
}