/*
 * Interface.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#include "ProcessCheck.hpp"

void printQueues();

void printQueues() {

	cout << "At time:  " << currentTime << endl;
	output << "At time:  " << currentTime << endl;

	sys.print();

	cout << "Completed Jobs:" << endl;
	output << "Completed Jobs:" << endl;

	cout << "--------------------------------------------------------" << endl;
	output << "--------------------------------------------------------" << endl;

	cout << "Job ID    Arrival Time    Finish Time    Turnaround Time" << endl;
	output << "Job ID    Arrival Time    Finish Time    Turnaround Time" << endl;

	cout << "========================================================" << endl;
	output << "========================================================" << endl;

	CQ.print();

	cout << endl;
	output << endl;

	cout << "Hold Queue 1:" << endl;
	output << "Hold Queue 1:" << endl;

	cout << "-------------------------" << endl;
	output << "-------------------------" << endl;

	cout << "Job ID    Run Time" << endl;
	output << "Job ID    Run Time" << endl;

	cout << "=========================" << endl;
	output << "=========================" << endl;

	HQ1.print();

	cout << endl;
	output << endl;

	cout << "Hold Queue 2:" << endl;
	output << "Hold Queue 2:" << endl;

	cout << "-------------------------" << endl;
	output << "-------------------------" << endl;

	cout << "Job ID    Run Time" << endl;
	output << "Job ID    Run Time" << endl;

	cout << "=========================" << endl;
	output << "=========================" << endl;

	HQ2.print();

	cout << endl;
	output << endl;

	cout << "Ready Queue:" << endl;
	output << "Ready Queue:" << endl;

	cout << "----------------------------------" << endl;
	output << "----------------------------------" << endl;

	cout << "Job ID    Run Time    Time Accrued" << endl;
	output << "Job ID    Run Time    Time Accrued" << endl;

	cout << "==================================" << endl;
	output << "==================================" << endl;

	RQ.print();

	cout << endl;
	output << endl;

	cout << "Process running on CPU:" << endl;
	output << "Process running on CPU:" << endl;

	cout << "-----------------------------------" << endl;
	output << "-----------------------------------" << endl;

	cout << "Job ID    Time Accrued    Time Left" << endl;
	output << "Job ID    Time Accrued    Time Left" << endl;

	cout << "===================================" << endl;
	output << "===================================" << endl;

	if(!sys.getIdle()){
		sys.getCurrentJob().printProcess();
	}

	cout << endl;
	output << endl;

	cout << "Wait Queue:" << endl;
	output << "Wait Queue:" << endl;

	cout << "----------------------------------" << endl;
	output << "----------------------------------" << endl;

	cout << "Job ID    Run Time    Time Accrued" << endl;
	output << "Job ID    Run Time    Time Accrued" << endl;

	cout << "==================================" << endl;
	output << "==================================" << endl;

	queue<Job> tmpWQ = WQ;

	for(int i = 0; i < tmpWQ.size(); i++) {
		tmpWQ.front().printWaitQueue();
		tmpWQ.pop();
	}

	cout << endl;
	output << endl;

	cout << "\n**********************************************************\n" << endl;
	output << "\n**********************************************************\n" << endl;


}


#endif /* INTERFACE_HPP_ */
