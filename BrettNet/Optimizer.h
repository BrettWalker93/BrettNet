#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include "WeightMatrix.h"


class SGD {

protected:



public:

    SGD(double);

    double learning_rate;

    void operator()(std::vector<WeightMatrix>& weights, const std::vector<WeightMatrix>& gradients) const;


};

#endif
