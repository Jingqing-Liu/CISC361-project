/*
 * Job.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef JOB_HPP_
#define JOB_HPP_

#include "MakeOutput.hpp"

class Job{
	int arrivalTime, jobID, memory, maxDevices, runTime, priority;

	int turnaroundTime;
	int startTime;   //start time
	int remainingTime; //remaining time
	int finishTime;  //finished time
	double waitedTurnaroundTime; // waited turnaround time

	int devicesAllocated;
	int devicesRequest; //requested devices

	bool start;

public:
	Job(){};
	Job(int s, int id, int m, int maxD, int rt, int p){
		arrivalTime = s;
		jobID = id;
		memory = m;
		maxDevices = maxD;
		runTime = rt;
		priority = p;

		//time
		start = false;
		startTime = -1;
		remainingTime = runTime;
		finishTime = -1;
		turnaroundTime = -1;
		waitedTurnaroundTime = -1;

		//devices
		devicesAllocated = 0;
		devicesRequest = 0;
	}

	int getArrivalTime(){
		return arrivalTime;
	}
	int getID(){
		return jobID;
	}
	int getMemory(){
		return memory;
	}
	int getMaxDevices(){
		return maxDevices;
	}
	int getRuntime(){
		return runTime;
	}
	int getPriority(){
		return priority;
	}
	int getDevicesAllocated(){
		return devicesAllocated;
	}
	int getTurnaroundTime(){
		return turnaroundTime;
	}
	int getRemainingTime(){
		return remainingTime;
	}
	int getDevicesRequest(){
		return devicesRequest;
	}
	int getStartTime(){
		return startTime;
	}


	//Time
	void setStartTime(int t){
		if(!start){
			start = true;
			startTime = t;
		}
	}
	void decreaseRemainingTime(int t){
		remainingTime -= t;
	}
	void setFinishTime(int f){
		finishTime = f;
		turnaroundTime = finishTime - arrivalTime; //turnaround time
		waitedTurnaroundTime = (double)turnaroundTime / runTime; //waited turnaround time
	}

	////Devices handling functions
	void setAllocatedDevices(int d){
		//give job devices
		devicesAllocated += d;
	}
	void releaseAllocatedDevices(int d){
		//release devices
		devicesAllocated -= d;
	}
	void releaseAllAllocatedDevices(){
		devicesAllocated = 0;
	}
	void increaseDevicesRequest(int d){
		devicesRequest += d;
	}
	void decreaseDevicesRequest(int d){
		devicesRequest -= d;
	}


	////print function
	void print(){
		cout << jobID << "           " << arrivalTime << "               " << finishTime << "              " << turnaroundTime << endl;

		output << jobID << "           " << arrivalTime << "               " << finishTime << "              " << turnaroundTime << endl;

	}

	void printHoldQueue(){
		cout << jobID << "           " << runTime << endl;

		output << jobID << "           " << runTime << endl;
	}

	void printReady(){
		cout << "  " << jobID << "         " << runTime << "             " << runTime - remainingTime << endl;

		output << "  " << jobID << "         " << runTime << "             " << runTime - remainingTime << endl;

	}

	void printProcess(){
		cout << "  " << jobID << "         " << runTime - remainingTime << "             " << remainingTime << endl;

		output << "  " << jobID << "         " << runTime - remainingTime << "             " << remainingTime << endl;

	}

	void printWaitQueue(){
		cout << "  " << jobID << "         " << runTime << "             " << runTime - remainingTime << endl;

		output << "  " << jobID << "         " << runTime << "             " << runTime - remainingTime << endl;

	}
};



#endif /* JOB_HPP_ */
