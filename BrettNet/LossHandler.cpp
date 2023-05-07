#include "LossHandler.h"
#include <vector>

LossHandler::LossHandler() {

    history = std::vector<double>(0);

}

std::vector<WeightMatrix> LossHandler::operator()(const std::vector<std::vector<double>>& X, const std::vector<double>& Y, const std::vector<double>& Y_hat, int batch_start, int batch_size) {
    // Initialize a vector to store the gradients for each weight matrix.
    std::vector<WeightMatrix> gradients;

    double loss = 0.0;

    // Loop through the batch.
    for (int i = batch_start; i < batch_start + batch_size && i < X.size(); ++i) {

        //MSE
        double this_loss = compute_loss(Y[i], Y_hat[i - batch_start]);

        double this_grad = backpropagate(X[i], Y[i], Y_hat[i - batch_start], this_loss);


        // Calculate the gradients of the loss function with respect to each weight.
        // You will need to implement the backpropagation algorithm here, computing
        // the gradient for each weight matrix in the network.

        // Accumulate the gradients for each weight matrix in the gradients vector.
        // Note that you should divide the accumulated gradients by the batch size
        // before returning the final gradients vector.
    }

    history.push_back(loss);

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