/*
 * Values.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef VALUES_HPP_
#define VALUES_HPP_


#include "./Request.hpp"

int QUANTUM;
int currentTime;
HoldQueue1 HQ1;
HoldQueue2 HQ2;
readyQueue RQ;
queue<Job> WQ;
CompletedQueue CQ;
System sys;
queue<int> printTimes;


#endif /* VALUES_HPP_ */
