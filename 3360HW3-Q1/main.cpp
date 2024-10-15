#include <iostream>
using namespace std;

/*
  function multiples start[*, *, *] times the matrix and saves new results in updated[*, *, *]. 
*/
void function_b(const double matrix[3][3], double start[], double updated[], int size) {
	double temp[3];
	for (int i = 0; i < 3; i++) {
		temp[i] = start[i];
	}
	double sum;
	for (int i = 0; i < 3; i++) {
		sum = 0.0;
		for (int j = 0; j < 3; j++) {
			sum += temp[j] * matrix[j][i];
		}
		updated[i] = sum;
	}
}
int main() {
	double matrix[3][3] = { {.8, .2, .0},
				{.1, .1, .8},
				{.2, .0, .8} };//initial matrix with probabilites
	double start_state[3] = { 1, 0, 0 };//start state represented by 1
	double new_state[3];
	function_b(matrix, start_state, new_state, 3);
	for (int i = 0; i < 6; i++) {
		function_b(matrix, new_state, new_state, 3);
	}
	cout << "For question (b): after 7 steps, the probability of a process being in the Running state is: " << new_state[1] << endl;
	for (int i = 0; i < 44; i++) {
		function_b(matrix, new_state, new_state, 3);
	}
	cout << "For question (c): after 50 steps, the probability of finding this process in the Running state is: " << new_state[1] << endl;
	cout << "For question (d): after 50 steps, the probability of finding this process in the Blocked state is: " << new_state[2] << endl;
	return 0;
}
