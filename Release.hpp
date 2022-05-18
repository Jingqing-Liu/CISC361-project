/*
 * Release.hpp
 *
 *  Created on: May 13, 2022
 *      Author: Jingqing Liu, Zhiwen Zhu, Yuchen Zhang
 *
 */

#ifndef RELEASE_HPP_
#define RELEASE_HPP_

#include "HoldQueueOne.hpp"

class Release{
	int releaseTime, id, deviceNum;
public:
	Release();
	Release(int r, int i, int d){
		releaseTime = r;
		id = i;
		deviceNum = d;
	}
	int getReleaseTime(){
		return releaseTime;
	}
	int getID(){
		return id;
	}
	int getDeviceNum(){
		return deviceNum;
	}
};



#endif /* RELEASE_HPP_ */
