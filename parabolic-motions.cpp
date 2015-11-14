/*
Alamsyah Rizki Isroi (rizkiisroi@live.com)
Physics Department, Bandung Institute of Technology
Here is C++ code to determine the position (time deppended) of a particle 
in a parabolic motion.
Compile	: g++ parabolic-motions.cpp -o parabolic
Run	: ./parabolic
*/

#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <string.h>

using namespace std;
const double h = 56; //the maximum high of parabolic
const double g = 9.8; //gravity constant
const double PI = 3.141529; //phi constant
const double teta = PI/4; //elevation angle of initial velocity
const double v0 = (sqrt(2*g*h))/sin(teta); //initial velocity
//function of vertical position
double y(double t) {
	double y0 = 0;
	double f = y0 + v0 * sin(teta) * t - g * t * t / 2;
	return f;
}
//function of horizontal position
double x(double t) {
	double v0x = v0 * cos(teta);
	double x0 = 0;
	return x0 + v0x * t;
}
//main function
int main() {
	double tmax = 2 * v0 * sin(teta) / g;
	cout << "tmax is = " << tmax << endl; //time to reach maximum high of the parabolic
	ofstream fout;
	fout.open("parabolic.txt"); //output will be printed in file parabolic.txt
	if(fout.is_open()) {
		fout << "#rx\try" << endl; //header of the parabolic.txt
		fout << fixed;
		fout << setprecision(2); //setting output to maximum 2 decimal place
		double t = 0.0; //initializing time t
		double dt = 0.05; //time different
		while(t < tmax) {
			double ry = y(t);
			double rx = x(t);
			if(ry >= 0) {
				fout << rx << "\t";
				fout << ry << endl;
				t += dt;
			} else {
				t > tmax + 1;
			}
		}
		fout.close();
	}
	return 0;
}
