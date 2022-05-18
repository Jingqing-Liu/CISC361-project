/*
 * Process.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef PROCESS_HPP_
#define PROCESS_HPP_

#include "RequestScheduling.hpp"


System systemSensor(ifstream &infile);
Job jobSensor(ifstream &infile);
Request requestSensor(ifstream &infile);
Release releaseSensor(ifstream &infile);

void process(ifstream &infile);

void process(ifstream &infile){
	string tmp;
	while(infile >> tmp){
		if (tmp == "C"){
			sys = systemSensor(infile);
			continue;
		}

		else if (tmp == "A"){
			Job job = jobSensor(infile) ;
			jobSchedule(job);
			continue;
		}

		else if(tmp == "Q"){
			Request request = requestSensor(infile);
			requestSchedule(request);
			continue;
		}

		else if(tmp == "L"){
			Release release = releaseSensor(infile);
			releaseSchedule(release);
			continue;
		}

		else if(tmp == "D"){
			int printTime;
			infile >> tmp;
			printTime = stoi(tmp);
			printStatus(printTime);

			continue;
		}

	}

	printStatus(9999);
}

System systemSensor(ifstream &infile){
	string tmp;
	int startTime, memory, deviceNum, quantum;

	infile >> tmp;
	startTime = stoi(tmp);
	infile >> tmp;
	memory = stoi(tmp.substr(2));
	infile >> tmp;
	deviceNum = stoi(tmp.substr(2));
	infile >> tmp;
	quantum = stoi(tmp.substr(2));
	QUANTUM = quantum;

	return System(startTime, memory, deviceNum, quantum);
}

Job jobSensor(ifstream &infile){
	string tmp;
	int arrivalTime, id, memory, maxNeed, runTime, priority;

	infile >> tmp;
	arrivalTime = stoi(tmp);
	infile >> tmp;
	id  = stoi(tmp.substr(2));
	infile >> tmp;
	memory = stoi(tmp.substr(2));
	infile >> tmp;
	maxNeed = stoi(tmp.substr(2));
	infile >> tmp;
	runTime = stoi(tmp.substr(2));
	infile >> tmp;
	priority = stoi(tmp.substr(2));
	return Job(arrivalTime, id, memory, maxNeed, runTime, priority);
}

Request requestSensor(ifstream &infile){
	string tmp;
	int requestTime, id, deviceNum;
	infile >> tmp;
	requestTime = stoi(tmp);
	infile >> tmp;
	id = stoi(tmp.substr(2));
	infile >> tmp;
	deviceNum = stoi(tmp.substr(2));
	return Request(requestTime, id, deviceNum);
}

Release releaseSensor(ifstream &infile){
	string tmp;
	int releaseTime, id, deviceNum;
	infile >> tmp;
	releaseTime = stoi(tmp);
	infile >> tmp;
	id = stoi(tmp.substr(2));
	infile >> tmp;
	deviceNum = stoi(tmp.substr(2));
	return  Release(releaseTime, id, deviceNum);
}

#endif /* PROCESS_HPP_ */
