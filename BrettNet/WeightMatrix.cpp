#include "WeightMatrix.h"
#include <random>
#include <vector>

WeightMatrix::WeightMatrix(int nin, int nout) : num_in(nin), num_out(nout) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    std::vector<std::vector<double>> random_vector(num_in + 1, std::vector<double>(num_out, 0.0));
    for (int i = 0; i < num_in + 1; i++) {
        for (int j = 0; j < num_out; j++) {
            random_vector[i][j] = dist(gen);
        }
    }

    wts = random_vector;
}

double& WeightMatrix::operator()(int i, int j) {
    return wts[i][j];
}

std::vector<double>& WeightMatrix::operator[](int i) {
    return wts[i];
}

void WeightMatrix::addTo(WeightMatrix addend) {

    for (int i = 0; i < num_in; i++) {

        for (int j = 0; j < num_out; j++) {

            wts[i][j] += addend[i][j];

        }

    }

}

WeightMatrix WeightMatrix::operator/(double scalar) const {

    WeightMatrix copy(*this);

    for (int i = 0; i < num_in; i++) {
        for (int j = 0; j < num_out; j++) {
            copy[i][j] /= scalar;
        }
    }

    return copy;
}

WeightMatrix& WeightMatrix::operator/=(double scalar) {

    for (int i = 0; i < num_in; i++) {
        for (int j = 0; j < num_out; j++) {
            wts[i][j] /= scalar;
        }
    }

    return *this;
}

WeightMatrix WeightMatrix::operator*(double scalar) const {

    WeightMatrix copy(*this);

    for (int i = 0; i < num_in; i++) {
        for (int j = 0; j < num_out; j++) {
            copy[i][j] *= scalar;
        }
    }

    return copy;
}

int WeightMatrix::nrows() {

    return num_in;
}

int WeightMatrix::ncols() {

    return num_out;
}