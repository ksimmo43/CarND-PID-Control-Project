#include "PID.h"
#include <iostream>
// using namespace std;

PID::PID() {
  Kp = Ki = Kd = 0;
  p_error = i_error = d_error = 0.0001;
  prev_cte = 0;
  max_i_error = 10;
}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
}

void PID::UpdateError(double cte) {
  p_error = cte;
  i_error += cte;
  // if (cte >= 0 && prev_cte <= 0) {
  //   i_error = 0;
  // }
  // if (cte <= 0 && prev_cte >= 0) {
  //   i_error = 0;
  // }
  if (i_error > max_i_error) {
    i_error = max_i_error;
  }
  if (i_error < -max_i_error) {
    i_error = -max_i_error;
  }
  d_error = cte - prev_cte;
  prev_cte = cte;

}

double PID::TotalError() {
  // std::cout << "Kp: " << Kp << " Ki: " << Ki << " Kd: " << Kd <<std::endl;
  // std::cout << "prev_cte: " << prev_cte << std::endl;
  // std::cout << "p_error: " << p_error << " i_error: " << i_error << "d_error: " << d_error << std::endl;
  double steer = -Kp * p_error - Kd * d_error - Ki * i_error;
  // std::cout << "steer: " << steer << std::endl;
  return steer;
}

void PID::Twiddle(double tol) {

}
