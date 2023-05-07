#include "Activator.h"
#include <algorithm>
#include <cmath>

double Activator::activate(std::string fun, double input) {

	if (fun == "relu") {

		return std::max(0.0, input);

	}

	else if (fun == "sigmoid") {

		return 1.0 / (1.0 + std::exp(-input));

	}
}