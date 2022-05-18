/*
 * JobScheduling.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */



#ifndef JOBSCHEDULE_HPP_
#define JOBSCHEDULE_HPP_

#include "PrintStatus.hpp"
#include "CompleteQueue.hpp"

void jobSchedule(Job job);


void jobSchedule(Job job){
	int gapTime = job.getArrivalTime() - currentTime;

	//Completed all quantum times until the gap time is shorter than one quantum
	while(gapTime >= QUANTUM){

		completedQuantum(); // complete quantum

		if(sys.getIdle())
			currentTime += QUANTUM;

		gapTime = job.getArrivalTime() - currentTime; //update gapTime

	}

	if(sys.getIdle()){
		currentTime = job.getArrivalTime();
	}else{
		if(sys.getCurrentJob().getRemainingTime() <= gapTime){
			currentJobFinished();
			distributeJobs();
		}
	}

	addJob(job);

}



#endif /* JOBSCHEDULE_HPP_ */
