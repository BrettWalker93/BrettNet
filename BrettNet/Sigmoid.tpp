#ifndef SIGMOID_TPP
#define SIGMOID_TPP

#include <cmath>

template<typename T>
T Sigmoid<T>::operator()(T x) const {
    return 1 / (1 + std::exp(-x));
}

template<>
double Sigmoid<int>::operator()(int x) const {
    return 1 / (1 + std::exp(-x));
}

#endif