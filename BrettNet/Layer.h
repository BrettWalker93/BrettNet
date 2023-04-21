#ifndef LAYER_H
#define LAYER_H

#include <string>

class Layer {
protected:
	std::string name;
	std::string activationFunction;
	int layer_units;

public:
	//constructors
	Layer();
	Layer(std::string, std::string, int);

	//setters
	void set_activation_function(std::string set_af);
	void set_name(std::string set_name);

	//getters
	std::string get_activation_function();
	std::string get_name();
	int get_units();
};

#endif