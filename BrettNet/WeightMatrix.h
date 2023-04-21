#ifndef WeightMatrix_H
#define WeightMatrix_H

#include <vector>

class WeightMatrix {
protected:
	int num_in;
	int num_out;
	std::vector<std::vector<double>> wts;


public:
	//constructor
	WeightMatrix();
	WeightMatrix(int);
	WeightMatrix(int, int);

	//get
	int get_dim();

	//set
	void set_dim(std::vector<int>);

	//methods
	int size();

	//index access
	double& operator()(int i, int j);

	std::vector<double>& operator[](int i);
};

#endif

