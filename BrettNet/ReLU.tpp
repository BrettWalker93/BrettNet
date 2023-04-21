#ifndef RELU_TPP
#define RELU_TPP

template<typename T>
T ReLU<T>::operator()(T x) const {
    if (x > 0) return x;

    return 0;
}

template<>
double ReLU<int>::operator()(int x) const {
    if (x > 0) return (double)x;

    return 0.0;
}

#endif
