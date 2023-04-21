#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include "WeightMatrix.h"


class SGD {
public:
    double learning_rate;

    SGD(double learning_rate);

    void operator()(WeightMatrix& weights, const WeightMatrix& gradients) const;

    //TODO: implement gradient descent algorithm
};

#endif
