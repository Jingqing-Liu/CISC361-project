/*
 * ReleaseScheduling.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef RELEASESCHEDULING_HPP_
#define RELEASESCHEDULING_HPP_

#include "JobScheduling.hpp"
#include "ProcessCheck.hpp"

void doRelease(Release r);
void releaseSchedule(Release r);

void doRelease(Release r){

	if(sys.getIdle() == false && r.getID() == sys.getCurrentJob().getID()) {

		Job currentJob = sys.getCurrentJob();
		sys.terminateJob();
		sys.increaseAvailableDevices(r.getDeviceNum());
		currentJob.releaseAllocatedDevices(r.getDeviceNum());
		currentJob.decreaseDevicesRequest(r.getDeviceNum());
		currentJob.decreaseRemainingTime(r.getReleaseTime() - currentTime);
		RQ.push(currentJob);
		queue<Job> processes;
		readyQueue tq = RQ;
		while(!tq.empty()){
			processes.push(tq.front());
			tq.pop();
		}

		queue<Job> tmpWQ;
		while(!WQ.empty()){
			Job tmp = WQ.front();
			processes.push(tmp);
			if(releaseBanker(processes)){
				tmp.setAllocatedDevices(tmp.getDevicesRequest());
				RQ.push(tmp);
				sys.decreaseAvailableDevices(tmp.getDevicesRequest());
			}else{
				tmpWQ.push(tmp);
			}
			WQ.pop();
		}

		WQ =tmpWQ;

		if(!RQ.empty()){
			currentTime = r.getReleaseTime();
			sys.startJob(RQ.front(), currentTime);
			RQ.pop();
		}
	} else {
		return;
	}
}

void releaseSchedule(Release r){
	int gapTime = r.getReleaseTime() - currentTime;
	while(gapTime >= QUANTUM){
		completedQuantum();
		if(sys.getIdle()) currentTime += QUANTUM;
		gapTime = r.getReleaseTime() - currentTime;
	}
	if(!sys.getIdle() && sys.getCurrentJob().getRemainingTime() <= gapTime){
		currentJobFinished();
		distributeJobs();
	}
	doRelease(r);
}


#endif /* RELEASESCHEDULING_HPP_ */
