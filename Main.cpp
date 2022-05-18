/*
 * Run.cpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#include "Process.hpp"

int main(){
	ifstream infile;
	infile.open("input.txt");
	output.open("output.txt");
	process(infile);
	cout << "System Turnaround Time: " << total/num << endl;
	output << "System Turnaround Time: " << total/num << endl;
	infile.close();
	output.close();
	return 0;
}
