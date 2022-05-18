/*
 * PrintStatus.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef PRINTSTATUS_HPP_
#define PRINTSTATUS_HPP_

#include "CompleteQueue.hpp"
#include "CompletedJobs.hpp"

void printStatus(int printTime);

void printStatus(int printTime){
	int tmpCurrentTime = currentTime;
	HoldQueue1 tmpCurrentHQ1 = HQ1;
	HoldQueue2 tmpCurrentHQ2 = HQ2;
	readyQueue tmpCurrentRQ = RQ;
	queue<Job> tmpCurrentWQ = WQ;
	CompletedQueue tmpCuurentCQ = CQ;
	System tmpCurrentSys = sys;

	int gapTime = printTime - currentTime;

	//Completed all quantum times until the gap time is shorter than one quantum
	while(gapTime >= QUANTUM){

		completedQuantum();
		if(sys.getIdle()) currentTime += QUANTUM;

		gapTime = printTime - currentTime;

	}

	if(!sys.getIdle() && sys.getCurrentJob().getRemainingTime() <= gapTime){
		currentJobFinished();
		distributeJobs();
	}

	if(!sys.getIdle()){
		Job j = sys.getCurrentJob();
		j.decreaseRemainingTime(printTime-currentTime);
		sys.setCurrentJob(j);
	}

	currentTime = printTime;

	printQueues();
	cout << endl;

	currentTime = tmpCurrentTime;
	HQ1 = tmpCurrentHQ1;
	HQ2 = tmpCurrentHQ2;
	RQ = tmpCurrentRQ;
	WQ = tmpCurrentWQ;
	sys = tmpCurrentSys;

}

#endif /* PRINTSTATUS_HPP_ */
