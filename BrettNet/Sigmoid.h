#ifndef SIGMOID_H
#define SIGMOID_H

#include "ActivationFunction.h"

template<typename T>
class Sigmoid : public ActivationFunction<T> {
public:
    T operator()(T x) const;
};

template<>
class Sigmoid<int> : public ActivationFunction<int> {
public:
    double operator()(int x) const;
};

#endif

#include "Sigmoid.tpp"