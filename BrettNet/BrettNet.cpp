#include "BrettNet.h"
#include <string>
#include <stdexcept>

BrettNet::BrettNet(std::string task, int in_, int out_) {
	params["task"] = task;
	params["out"] = out_;
	params["in"] = in_;
	params["len"] = (int)0;
}

BrettNet::BrettNet(std::string task, int in_) {
	params["task"] = task;
	params["out"] = (int)1;
	params["in"] = in_;
	params["len"] = (int)0;
}

BrettNet::BrettNet() {
	params["task"] = nullptr;
	params["out"] = (int)0;
	params["in"] = (int)0;
	params["len"] = (int)0;
}

void BrettNet::addLayer(std::string name, std::string aF, int units) {

	Layer newLayer = Layer(name, aF, units);

	try {
		int previous_units = layers.back().get_units();

		WeightMatrix newWeightMatrix = WeightMatrix(previous_units, units);
		weights.push_back(newWeightMatrix);

		throw 1;
	}
	catch (std::exception e) {

		WeightMatrix newWeightMatrix = WeightMatrix(std::get<int>(params["in"]), units);
		weights.push_back(newWeightMatrix);

	}

	layers.push_back(newLayer);
	params["len"] = std::get<int>(params["len"]) + 1;
}

void BrettNet::compile() {

	Layer newLayer = Layer("output", "sigmoid", 1);

	int previous_units = layers.back().get_units();

	WeightMatrix newWeightMatrix = WeightMatrix(previous_units, 1);
	weights.push_back(newWeightMatrix);

	layers.push_back(newLayer);
	params["len"] = std::get<int>(params["len"]) + 1;
}

void BrettNet::teach(std::vector<std::vector<double>> input, std::vector<double> output) {

	int num_epochs = std::get<int>(params["num_epochs"]);
	int batch_size = std::get<int>(params["batch_size"]);

	// loop over epochs and batches
	for (int epoch = 0; epoch < num_epochs; epoch++) {
		for (int batch_start = 0; batch_start < input.size(); batch_start += batch_size) {

			// calculate gradients for batch
			// calculate forward activations for each input

			std::vector<std::vector<std::vector<double>>> activations = std::vector<std::vector<std::vector<double>>>();

			for (int i = batch_start; i - batch_start < batch_size; i++) {

				activations.push_back(forward(input[i]));

			}

			// activation functions of each layer
			std::vector<std::string> activation_funs(0);
			for (Layer l : layers) {
				activation_funs.push_back(l.get_activation_function());
			}

			// send to loss handler to calculate gradients
			std::vector<WeightMatrix> gradients = lossHandler(input, activations, output, weights, batch_start, batch_size, activation_funs, activator);

			// apply optimizer to update weights
			optimizerHandler(weights, gradients);
		}
	}
}

std::vector<std::vector<double>> BrettNet::forward(std::vector<double> input) {

	//todo: optimize linear algebra operations

	std::vector<std::vector<double>> activations = std::vector<std::vector<double>>();

	int num_l = std::get<int>(params["len"]);

	for (int layer_iter = 0; layer_iter < num_l; layer_iter++) {

		int layer_units = layers[layer_iter].get_units();

		std::vector<double> layer_activation(layer_units);
		

		//weights[layer_iter] is current weightmatrix

		for (int cur_unit = 0; cur_unit < layer_units; cur_unit++) {

			//weights[layer_iter][cur_unit] is current weight vector

			double unit_activation = 0.0;

			for (int inp = 0; inp < input.size(); inp++) {

				unit_activation += weights[layer_iter][cur_unit][inp] * input[inp];

			}
			layer_activation[cur_unit] = activator.activate(layers[layer_iter].get_activation_function(), unit_activation);

		}

		activations.push_back(layer_activation);
		
	}

	return activations;

}