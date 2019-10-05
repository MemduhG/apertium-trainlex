all: bin/logistic_regression 
	
test: data/iris.data

bin/logistic_regression: src/logistic_regression.cc src/logistic_regression.h
	g++ src/logistic_regression.cc -o bin/logistic_regression

data/iris.data:
	mkdir -p data
	curl https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data -o data/iris.data
