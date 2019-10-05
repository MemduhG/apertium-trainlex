#include <vector>

class regressor{
	int num_feats, num_classes;
	float bias;
	std::vector<std::vector<float>> weights;
public:
	float predict_value(std::vector<float> features, int label);
};


float regressor::predict_value(std::vector<float> features, int label){
	float result = bias ;
	for (int i=0; i < num_feats; i++)
		result += features[i] * weights[label][i] ;
	return result ;
}
