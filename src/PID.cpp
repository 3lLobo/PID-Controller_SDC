#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	prev_cte = 0;
	total_error = 0;
	
}

void PID::UpdateError(double cte) {
	p_error = cte;
	d_error = cte - prev_cte;
	prev_cte = cte;
	i_error += cte;
	steer = -Kp * p_error -Kd * d_error -Ki * i_error;
	
}

double PID::TotalError() {
	total_error = p_error + d_error + i_error;
	return total_error;
	
}
