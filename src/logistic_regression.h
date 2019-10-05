#include <vector>

class Regressor
{
	int num_feats, num_classes;
	std::vector<float> bias;
	std::vector<std::vector<float>> weights;
public:
	float predictValue(std::vector<float> features, int label);
	int predictLabel(std::vector<float> features);
	std::vector<float> softmax(std::vector<float> features);
};


float
Regressor::predictValue(std::vector<float> features, int label)
{
	float result = bias[label];
	for (int i=0; i < num_feats; i++)
		result += features[i] * weights[label][i];
	return result ;
}

std::vector<float> 
Regressor::softmax(std::vector<float> features)
{
	std::vector<float> scores;
	float total = 0;
	float new_score;
	for (int i=0; i < num_classes; i++)
	{
		new_score = predictValue(features, i);
		scores.push_back(new_score);
		total += new_score;
	}
	for (int i=0; i < num_classes; i++)
	{
		scores[i] = scores[i] / total;
	}
	return scores;
}

int
Regressor::predictLabel(std::vector<float> features){
	int label = -1;
	float current_score = -1;
	std::vector<float> scores = softmax(features);
	for (int i=0; i < num_classes; i++)
	{
		if (current_score < scores[i])
		{
			current_score = scores[i];
			label = i;
		}
	}
	return label;
}
