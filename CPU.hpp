/*
 * CPU.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef CPU_HPP_
#define CPU_HPP_

#include "CompletedJobs.hpp"

class CPU{

private:
	Job currentJob;
	bool idle;

	friend class System;


	CPU(){
		currentJob = Job();
		idle = true;
	}

	CPU(int s, int m, int dn, int q){
		currentJob = Job();
		idle = true;
	}

	Job getCurrentJob() {
		return currentJob;
	}

	bool getIdle() {
		return idle;
	}

	void print(){
		if (!idle){
			currentJob.print();
		}
	}

	void setCurrentJob(Job j) {
		currentJob = j;
	}

	void startJob(Job job, int currentTime){
		idle = false;
		currentJob = job;
		currentJob.setStartTime(currentTime);
	}

	void terminateJob() {
		idle = true;
		currentJob = Job();
	}
};

#endif /* CPU_HPP_ */
