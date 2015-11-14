/*
Alamsyah Rizki Isroi
10211056
Berikut merupakan program untuk menentukan posisi dari suatu benda
dalam simulasi gerak parabola dari ketinggian 56 meter
*/

#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <string.h>

using namespace std;
//inisialisasi beberapa konstanta dan kondisi awal
const double h = 56; //tinggi maksimum
const double g = 9.8; //konstanta gravitasi
const double PI = 3.141529;
const double teta = PI/4; //kondisi awal elevasi parabola
const double v0 = (sqrt(2*g*h))/sin(teta);
//fungsi posisi vertikal
double y(double t) {
	double y0 = 0;
	double f = y0 + v0 * sin(teta) * t - g * t * t / 2;
	return f;
}

//fungsi posisi horizontal
double x(double t) {
	double v0x = v0 * cos(teta);
	double x0 = 0;
	return x0 + v0x * t;
}

int main() {
	double tmax = 2 * v0 * sin(teta) / g;
	cout << "tmax adalah = " << tmax << endl;
	ofstream fout;
	fout.open("tugasparabola.txt");
	if(fout.is_open()) {
		fout << "#rx\try" << endl;
		fout << fixed;
		fout << setprecision(2); 
		double t = 0.0;
		double dt = 0.05;
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
