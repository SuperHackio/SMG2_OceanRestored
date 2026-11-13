#pragma once

#include "revolution.h"
#include "Kamek/hooks.h"
#include "Game/Map/OceanBowl.h"
#include "Game/Map/OceanRing.h"
#include "Game/Map/WaterInfo.h"
#include "Game/Scene/SceneObjHolder.h"

#include "ModuleData_WaterAreaHolder_Ext.h"

WaterAreaHolder_Ext* WaterAreaHolder_ExtendedCtor(WaterAreaHolder_Ext* pHolder) {
	pHolder->mOceanBowlNum = 0;
	pHolder->mOceanBowls = new OceanBowl * [0x20];
	for (s32 i = 0; i < 0x20; i++)
		pHolder->mOceanBowls[i] = nullptr;

	pHolder->mOceanRingNum = 0;
	pHolder->mOceanRings = new OceanRing * [0x20];
	for (s32 i = 0; i < 0x20; i++)
		pHolder->mOceanRings[i] = nullptr;

	return pHolder;
}

kmBranch(0x8026B484, WaterAreaHolder_ExtendedCtor);

class WaterStream;
extern "C" {
	bool __kAutoMap_8026D0F0(WaterStream*, const TVec3f&, const TVec3f&, WaterInfo*);
}

 bool getWaterAreaInfo_Ext(WaterInfo* pInfo, const TVec3f& a, const TVec3f& b) {
	 if (pInfo->mWaterStream)
		 return __kAutoMap_8026D0F0(pInfo->mWaterStream, a, b, pInfo);
	 if (pInfo->mOceanBowl)
		 return pInfo->mOceanBowl->calcWaterInfo(a, b, pInfo);
	 if (pInfo->mOceanRing)
		 return pInfo->mOceanRing->calcWaterInfo(a, b, pInfo);
	 return false;
}

kmCall(0x80061910, getWaterAreaInfo_Ext);
kmWrite32(0x80061914, 0x2C030000); // cmpwi r3, 0
// Leaving the branch if equal alone
kmWrite32(0x8006191C, 0x60000000); // nop
kmWrite32(0x80061920, 0x60000000); // nop
kmWrite32(0x80061924, 0x60000000); // nop
// Leaving the branch alone
kmWrite32(0x8006192C, 0x83FB0040); // lwz r31, 0x40(r27)



bool tryInOceanArea_Ext() {
	register TVec3f* vec;
	register WaterInfo* info;
	__asm {
		mr vec, r27
		mr info, r28
	}

	WaterAreaHolder_Ext* pHolder = (WaterAreaHolder_Ext*)MR::getSceneObjHolder()->getObj(SCENE_OBJ_WATER_AREA_HOLDER);

	for (s32 i = 0; i < pHolder->mOceanBowlNum; i++) {
		OceanBowl* pBowl = pHolder->mOceanBowls[i];
		if (pBowl->isInWater(*vec)) {
			info->mOceanBowl = pBowl;
			return true;
		}
	}

	for (s32 i = 0; i < pHolder->mOceanRingNum; i++) {
		OceanRing* pRing = pHolder->mOceanRings[i];
		if (pRing->isInWater(*vec)) {
			info->mOceanRing = pRing;
			return true;
		}
	}

	return false;
}
kmCall(0x8026B754, tryInOceanArea_Ext);