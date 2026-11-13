#pragma once

#include "revolution.h"
#include "Kamek/hooks.h"

#include "Game/LiveActor/LiveActor.h"
#include "Game/Util.h"

// Adds a new Object Arguments to OceanSphere allowing you to choose it's looks

bool isSkullSharkGalaxy(const JMapInfoIter& rIter) {
	s32 b = 0;
	MR::getJMapInfoArg0NoInit(rIter, &b);
	return b == 1;
}
kmWrite32(0x8025CE18, PPC_MR(3, 30));
kmCall(0x8025CE1C, isSkullSharkGalaxy);


bool isTearDropGalaxy(const JMapInfoIter& rIter) {
	s32 b = 0;
	MR::getJMapInfoArg0NoInit(rIter, &b);
	return b == 2;
}
kmWrite32(0x8025CE34, PPC_MR(3, 30));
kmCall(0x8025CE38, isTearDropGalaxy);