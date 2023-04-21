#ifndef ACTIVATIONFUNCTION_H
#define ACTIVATIONFUNCTION_H

template<typename T>
class ActivationFunction {
public:
    virtual T operator()(T x) const = 0;
    virtual double operator()(int x);
    virtual ~ActivationFunction() {}
};

template<typename InputType, typename ActivationFunction>
class Activation {
public:
	InputType apply(InputType);
};

#endif

#include "Activation.tpp"
