#pragma once

#include "Game/NameObj/NameObj.h"

class OceanRing;

class OceanRingBloomDrawer : public NameObj {
public:
    OceanRingBloomDrawer(OceanRing*);

    virtual void init(const JMapInfoIter&);
    virtual void draw() const;

    OceanRing* mRing;  // 0xC
};