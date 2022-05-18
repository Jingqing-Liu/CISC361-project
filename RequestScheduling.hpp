/*
 * RequestScheduling.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef REQUESTSCHEDULING_HPP_
#define REQUESTSCHEDULING_HPP_

#include "ReleaseScheduling.hpp"

void doRequest(Request r);
void requestSchedule(Request r);

void doRequest(Request r){

	if(!sys.getIdle() && r.getID() == sys.getCurrentJob().getID()) {
		Job currentJob = sys.getCurrentJob();
		sys.terminateJob();

		currentJob.increaseDevicesRequest(r.getDeviceNum());

		currentJob.decreaseRemainingTime(r.getRequestTime() - currentTime);

		queue<Job> processes;
		readyQueue tq = RQ;
		while(!tq.empty()){
			processes.push(tq.front());
			tq.pop();
		}
		processes.push(currentJob);

		int currentJobD = currentJob.getDevicesAllocated();

		if(requestBanker(processes, r) && sys.getAvailableDevices() >= 0) {
			currentJob.setAllocatedDevices(r.getDeviceNum());
			sys.decreaseAvailableDevices(r.getDeviceNum());
			RQ.push(currentJob);
		} else {
			currentJob.releaseAllAllocatedDevices();
			sys.increaseAvailableDevices(currentJobD);
			WQ.push(currentJob);
		}
		if(!RQ.empty()){
			currentTime = r.getRequestTime();
			sys.startJob(RQ.front(), currentTime);
			RQ.pop();
		}

	} else {
		return;
	}
}

void requestSchedule(Request r){
	int gapTime = r.getRequestTime() - currentTime;
	while(gapTime >= QUANTUM){
		completedQuantum();
		if(sys.getIdle())
			currentTime += QUANTUM;
		gapTime = r.getRequestTime() - currentTime; //update gapTime

	}
	if(!sys.getIdle() && sys.getCurrentJob().getRemainingTime() <= gapTime){
		currentJobFinished();
		distributeJobs();
	}
	doRequest(r);
}


#endif /* REQUESTSCHEDULING_HPP_ */
