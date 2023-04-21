#ifndef RELU_H
#define RELU_H

#include "ActivationFunction.h"

template<typename T>
class ReLU : public ActivationFunction<T> {
public:
    T operator()(T x) const;
};

template<>
class ReLU<int> : public ActivationFunction<int> {
public:
    double operator()(int x) const;
};

#endif
