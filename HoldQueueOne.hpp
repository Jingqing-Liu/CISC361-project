/*
 * HoldQueueOne.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef HOLDQUEUEONE_HPP_
#define HOLDQUEUEONE_HPP_

#include "HoldQueueTwo.hpp"

class HoldQueue1{
	std::list<Job> q;

public:

	HoldQueue1(){}

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
		for(Job j : q){
			j.printHoldQueue();
		}
	}

	void push(Job in){
		if(q.empty()){
			q.push_back(in);
			return;
		}
		list<Job>::iterator it;
		it = q.begin();
		while(it != q.end()){
			if(in.getRuntime() < it->getRuntime()){
				q.insert(it, in);
				return;
			}
			it++;
		}

		if(in.getRuntime() < it->getRuntime()){
			q.insert(it, in);
			return;
		}

		q.push_back(in);
		return;

	}
};



#endif /* HOLDQUEUEONE_HPP_ */
