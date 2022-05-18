/*
 * CompletedJobs.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef COMPLETEDJOBS_HPP_
#define COMPLETEDJOBS_HPP_

#include "Job.hpp"

double total;
int num;

class CompletedQueue{
	std::list<Job> q;

public:
	CompletedQueue(){};
	void push(Job job){
		q.push_back(job);
	}
	void print(){
		for(Job job : q) {
			job.print();
			total += job.getTurnaroundTime();
			num++;
		}
	}
};

#endif /* COMPLETEDJOBS_HPP_ */
