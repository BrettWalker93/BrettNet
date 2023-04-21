#include "Optimizer.h"

void SGD::operator()(WeightMatrix& weights, const WeightMatrix& gradients) const {
    for (size_t i = 0; i < weights.size(); i++) {
        weights[i] -= learning_rate * gradients[i];
    }
}