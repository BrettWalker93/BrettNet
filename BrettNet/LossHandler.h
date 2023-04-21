#ifndef LOSSHANDLER_H
#define LOSSHANDLER_H



class LossHandler
{
protected:


public:
	std::vector<WeightMatrix> operator()(std::vector<std::vector<double>> X, std::vector<double> Y, int batch_start, int batch_size);

};

#endif