/*
 * CompleteQueue.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef COMPLETEQUEUE_HPP_
#define COMPLETEQUEUE_HPP_


#include "Interface.hpp"
#include "Job.hpp"

void addJob(Job job);
void distributeJobs();
void currentJobFinished();
void currentJobUnfinishedInQuantum();
void completedQuantum();


void addJob(Job job){
	if(job.getMemory() > sys.getMemory() || job.getMaxDevices() > sys.getDeviceNum()){
		return;
	}

	if(job.getMemory() <= sys.getAvailableMemory()){
		RQ.push(job);
		sys.decreaseAvailableMemory(job);
	}else{
		if(job.getPriority() == 1){
			HQ1.push(job);
		} else {
			HQ2.push(job);
		}
	}

	if(sys.getIdle() && !RQ.empty()){
		int startTime = RQ.front().getArrivalTime();
		if(startTime > currentTime) currentTime = startTime;
		RQ.front().setStartTime(currentTime);
		sys.startJob(RQ.front(), currentTime);
		RQ.pop();
	}
	return;
}

void distributeJobs(){
	while(!HQ1.empty()){
		Job job = HQ1.front();
		if(sys.getMemory() <= sys.getAvailableMemory()){
			RQ.push(job);
			HQ1.pop();
		}else{
			break;
		}
	}

	while(!HQ2.empty()){
		Job job = HQ2.front(); // @suppress("Invalid arguments")
		if(sys.getMemory() <= sys.getAvailableMemory()){
			RQ.push(job);
			HQ2.pop();
		}else{
			break;
		}
	}

	if(!RQ.empty() && sys.getIdle()){
		sys.startJob(RQ.front(), currentTime);
		RQ.pop();
	}

}

void currentJobFinished(){
	Job currentJob = sys.getCurrentJob();
	currentTime += currentJob.getRemainingTime();
	currentJob.decreaseRemainingTime(currentJob.getRemainingTime());
	currentJob.setFinishTime(currentTime);
	currentJob.releaseAllAllocatedDevices();
	sys.terminateJob();
	sys.increaseAvailableDevices(currentJob.getDevicesRequest());
	CQ.push(currentJob);
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
			RQ.push(tmp);
		}else{
			tmpWQ.push(tmp);
		}
		WQ.pop();
	}
	WQ =tmpWQ;

}

void currentJobUnfinishedInQuantum(){
	Job currentJob = sys.getCurrentJob();
	currentTime += QUANTUM;
	currentJob.decreaseRemainingTime(QUANTUM);
	RQ.push(currentJob);
	sys.terminateJob();
}

void completedQuantum(){

	if(sys.getIdle() == false){

		Job currentJob = sys.getCurrentJob();

		if(currentJob.getRemainingTime() <= QUANTUM){
			currentJobFinished();
		}

		//current unfinished
		else{
			currentJobUnfinishedInQuantum();
		}
	}

	distributeJobs();
}


#endif /* COMPLETEQUEUE_HPP_ */
