/*
 * System.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef MODULES_CLASSES_SYSTEM_HPP_
#define MODULES_CLASSES_SYSTEM_HPP_


#include "CPU.hpp"

class System{
	int startTime,  memory, deviceNum, Quantum, availableMemory,availableDevices;
	CPU cpu;

public:
	System(){
		startTime = 0;
		memory = 0;
		deviceNum = 0;
		Quantum = 0;
		availableMemory = 0;
		availableDevices = 0;
		cpu = CPU();
	}
	System(int s, int m, int dn, int q){
		startTime = s;
		memory = m;
		deviceNum = dn;
		Quantum = q;
		availableMemory = m;
		availableDevices = dn;
		cpu = CPU();
	}
	int getMemory() {
		return memory;
	}
	int getMaxDevices(){
		return deviceNum;
	}
	int getDeviceNum() {
		return deviceNum;
	}
	int getAvailableMemory() {
		return availableMemory;
	}
	int getAvailableDevices() {
		return availableDevices;
	}
	Job getCurrentJob(){
		return cpu.currentJob;
	}

	bool getIdle() {
		return cpu.idle;
	}

	void setCurrentDevices(int deviceNum) {
		availableDevices = deviceNum;
	}

	void setCurrentJob(Job j){
		cpu.currentJob = j;
	}

	void startJob(Job job, int currentTime){
		cpu.idle = false;
		cpu.currentJob = job;
		cpu.currentJob.setStartTime(currentTime);

	}
	void terminateJob(){
		cpu.idle = true;
		cpu.currentJob = Job();

	}

	void increaseAvailableDevices(int d) {
		availableDevices += d;
	}

	void decreaseAvailableDevices(int d) {
		availableDevices -= d;
	}

	void increaseAvailableMemory(Job j){
		availableMemory += j.getMemory();
	}
	void decreaseAvailableMemory(Job j){
		availableMemory -= j.getMemory();
	}

	void print(){
		cout << "Current Available Main Memory = " << availableMemory << endl;
		cout << "Current Devices = " << availableDevices << endl;

		output << "Current Available Main Memory = " << availableMemory << endl;
		output << "Current Devices = " << availableDevices << endl;
	}
};




#endif /* MODULES_CLASSES_SYSTEM_HPP_ */
