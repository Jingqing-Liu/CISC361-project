/*
 * ProcessCheck.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef PROCESSCHECK_HPP_
#define PROCESSCHECK_HPP_

#include "Values.hpp"

void calculateNeed(int processNum, int need[], int maxm[], int alloc[]);
bool isSafe(queue<Job> processes);
bool releaseBanker(queue<Job> processes);
bool requestBanker(queue<Job> processes, Request r);


bool isSafe(queue<Job> processes, System tmpSys){

	int processNum = processes.size();

	int processesID[processNum];
	int maxm[processNum];
	int alloc[processNum];
	int need[processNum];

	int i = 0;
	while(!processes.empty()){
		processesID[i] = processes.front().getID();

		maxm[i] = processes.front().getMaxDevices();

		alloc[i] = processes.front().getDevicesAllocated() ;

		need[i] = maxm[i] - alloc[i];

		processes.pop();

		i++ ;
	}

	int work = tmpSys.getAvailableDevices() ;

	// store safe sequence
	int safeSeq[processNum];


	// Mark all process unfinish
	bool finish[processNum];
	for(int i = 0; i < processNum; i++) {
		finish[i] = 0;
	}

	int count = 0;


	while (count < processNum) {
		bool found = false;
		for (int p = 0; p < processNum; p++)
		{
			if (finish[p] == 0){

				int j;
				for(j = 0; j < processNum; j++){
					if(need[p] > work) break;
				}
				if (j == processNum){
					work += alloc[p];
					safeSeq[count++] = processesID[p];
					finish[p] = 1;

					found = true;
				}
			}
 		}
		if (found == false)
		{
			return false;
		}
	}
    return true;
}

bool requestBanker(queue<Job> processes, Request r){

	if(r.getDeviceNum() > sys.getAvailableDevices()){
		return false;
	}

	processes.back().setAllocatedDevices(r.getDeviceNum());

	System tmpSys = sys;

	tmpSys.decreaseAvailableDevices(r.getDeviceNum());

	bool safe = isSafe(processes,tmpSys);

	return safe;
}

bool releaseBanker(queue<Job> processes){

	if(processes.back().getDevicesRequest() > sys.getAvailableDevices()){
		return false;
	}

	bool safe = isSafe(processes, sys);

	return safe;
}


#endif /* PROCESSCHECK_HPP_ */
