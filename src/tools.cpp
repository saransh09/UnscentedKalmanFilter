#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse(4);
  rmse << 0,0,0,0;
	if(estimations.size()==0){
		cout << "CalculateRMSE() error, the estimations vector is empty" << endl;
		return rmse;
	}
	else if(ground_truth.size()==0){
		cout << "CalculateRMSE() error, the ground_truth vector is empty" << endl;
		return rmse;
	}
	else if(estimations.size() != ground_truth.size()){
		cout << "CalculateRMSE() error, the estimations and ground_truth vector are not of the same size" << endl;
	}
	for(unsigned int i = 0 ; i < estimations.size() ; ++i){
		VectorXd diff = estimations[i] - ground_truth[i];
		diff = diff.array() * diff.array();
		rmse += diff;
	}
	rmse /= estimations.size();
	rmse = rmse.array().sqrt();
	return rmse;
}