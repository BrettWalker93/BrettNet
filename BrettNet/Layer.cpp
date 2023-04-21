#include "Layer.h"
#include <string>

//constructors
//default
Layer::Layer() {}

Layer::Layer(std::string n, std::string aF, int units) {
	name = n;
	activationFunction = aF;
	layer_units = units;
}

//setters
void Layer::set_activation_function(std::string set_to) {
	activationFunction = set_to;
}

void Layer::set_name(std::string set_to) {
	name = set_to;
}

//getters
std::string Layer::get_activation_function() {
	return activationFunction;
}

std::string Layer::get_name() {
	return name;
}

int Layer::get_units() {
	return layer_units;
}

