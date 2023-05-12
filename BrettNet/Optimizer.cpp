#include "Optimizer.h"

void SGD::operator()(std::vector<WeightMatrix>& weights, const std::vector<WeightMatrix>& gradients) const {
    for (size_t i = 0; i < weights.size(); i++) {
        weights[i] -= gradients[i] * learning_rate;
    }
}

SGD::SGD(double _rate) {
    learning_rate = _rate;
}