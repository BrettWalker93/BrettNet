#include "BrettNet.h"
#include <string>
#include <stdexcept>

BrettNet::BrettNet(std::string task) {
	task = task;
	out = 1;
}

BrettNet::BrettNet(std::string task, int output) {
	task = task;
	out = output;
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

		WeightMatrix newWeightMatrix = WeightMatrix(in, units);
		weights.push_back(newWeightMatrix);

	}

	layers.push_back(newLayer);

}


void BrettNet::teach(std::vector<std::vector<double>> input, std::vector<double> output) {

	int batch_size = optimizer.get_batch_size();

	// loop over epochs and batches
	for (int epoch = 0; epoch < num_epochs; epoch++) {
		for (int batch_start = 0; batch_start < input.size(); batch_start += batch_size) {
			// calculate gradients for batch
			std::vector<WeightMatrix> gradients = lossHandler(input, output, batch_start, batch_size);

			// apply optimizer to update weights
			optimizerHandler(weights, gradients);
		}
	}
}