#include "LossHandler.h"
#include <vector>
#include "Activator.h"

LossHandler::LossHandler() {

    history = std::vector<double>(0);

}

std::vector<WeightMatrix> LossHandler::operator()(
    const std::vector<std::vector<double>>& X, 
    const std::vector<std::vector<std::vector<double>>> activations,
    const std::vector<double>& Y,
    const std::vector<WeightMatrix> weights,
    int batch_start,
    int batch_size,
    std::vector<std::string> activation_funs,
    Activator& activator) {

    // Initialize a vector to store the gradients for each weight matrix.
    std::vector<WeightMatrix> gradients;

    // cumulative loss for batch
    double loss = 0.0;

    // loop batch
    for (int i = batch_start; i < batch_start + batch_size && i < X.size(); ++i) {

        // backpropagate
        std::vector<WeightMatrix> cur_gradients = backpropagate(activations[i], Y[i], weights, activation_funs);

        if (gradients.empty()) gradients = cur_gradients;
        else {
            for (int j = 0; j < gradients.size(); j++) {
                gradients[j].addTo(cur_gradients[j]);
            }
        }

        loss += compute_loss(Y[i], activations[i].back()[0]);

    }

    history.push_back(loss);

    for (auto& gradient : gradients) {
        gradient /= (double)batch_size;
    }

    return gradients;

}

double LossHandler::compute_loss(double y, double y_hat) {

    if (loss_fun == "mse") {

        double delta = y - y_hat;
        return (delta * delta);

    }

    else if (loss_fun == "binary_cross_entropy") {

        return y * log(y_hat) + (1 - y) * log(1 - y_hat);

    }

}

std::vector<WeightMatrix> LossHandler::backpropagate(
    std::vector<std::vector<double>> activations, 
    double Y,
    std::vector<WeightMatrix> weights,
    std::vector<std::string> activation_funs,
    Activator& activator) {

    
    std::vector<WeightMatrix> gradients = weights;


    // output error
    std::vector<double> out_e = std::vector<double>();

    // last gradient
    out_e.push_back(activations.back()[0] - Y);
    gradients.back() = outerProduct(out_e, activations[activations.size() - 2]);

    for (int layer = activations.size() - 3; layer >= 0; layer--) {

        // current layer error
        std::vector<double> layer_e(weights[layer + 1].nrows());

        for (int i = 0; i < layer_e.size(); i++) {

            double s = 0.0;
            for (int j = 0; j < weights[layer + 1].ncols(); j++) {

                s += weights[layer + 1][i][j] * out_e[j];

            }
            layer_e[i] += s;

        }

        // derivative of activation function
        for (int i = 0; i < layer_e.size(); i++) {

            layer_e[i] *= activator.derivative(activation_funs[layer], activations[layer + 1][i]);

        }

        gradients[layer] = outerProduct(layer_e, activations[layer]);

        out_e = layer_e;

    }

    return gradients;

}

WeightMatrix LossHandler::outerProduct(
    const std::vector<double>& v,
    const std::vector<double>& u) {

    WeightMatrix product(v.size(), u.size());
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < u.size(); j++) {
            product(i, j) = v[i] * u[j];
        }
    }
    return product;
}
