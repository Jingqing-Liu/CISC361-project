/*
 * HoldQueueTwo.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef HOLDQUEUETWO_HPP_
#define HOLDQUEUETWO_HPP_

#include "ReadyQueue.hpp"

using namespace std;

class HoldQueue2{
	std::list<Job> q;

public:

	HoldQueue2(){}

	bool empty(){
		return q.empty();
	}

	Job front(){
		return q.front();
	}

	void pop(){
		q.pop_front();
	}

	void print(){
		for(Job job : q) {
			job.printHoldQueue();
		}
	}

	void push(Job in){
		q.push_back(in);
	}
};




#endif /* HOLDQUEUETWO_HPP_ */
