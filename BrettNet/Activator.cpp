#include "Activator.h"
#include <algorithm>
#include <cmath>

double Activator::activate(std::string fun, double input) {

	if (fun == "relu") {

		return relu(input);

	}

	else if (fun == "sigmoid") {

		return sigmoid(input);

	}
}

double Activator::derivative(std::string fun, double activation) {

	if (fun == "relu") {

		return activation > 0.0 ? 1.0 : 0.0;

	}

	else if (fun == "sigmoid") {

		double s = sigmoid(activation);

		return s * (1.0 - s);

	}

}

double Activator::sigmoid(double x) {

	return 1.0 / (1.0 + std::exp(-x));

}

double Activator::relu(double x) {

	return x > 0.0 ? x : 0.0; // std::max(0.0, x);

}