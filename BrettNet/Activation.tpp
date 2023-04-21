#ifndef ACTIVATION_TPP
#define ACTIVATION_TPP

template<typename InputType, typename ActivationFunction>
InputType Activation<InputType, ActivationFunction>::apply(InputType input) {
	ActivationFunction activationFunction;
	return activationFunction(input);
}



#endif