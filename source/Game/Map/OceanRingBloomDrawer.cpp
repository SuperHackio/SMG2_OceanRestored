#include "Game/Map/OceanRingBloomDrawer.h"
#include "Game/Map/OceanRing.h"
#include "Game/Map/OceanRingDrawer.h"
#include "Game/Util/ObjUtil.h"
#include "Game/Util/LiveActorUtil.h"
#include "Game/Util/CameraUtil.h"
#include "Game/NameObj/NameObjCategories.h"

OceanRingBloomDrawer::OceanRingBloomDrawer(OceanRing* pRing) : NameObj("オーシャンリング[ブルーム描画]") {
    mRing = pRing;
}

void OceanRingBloomDrawer::init(const JMapInfoIter& rIter) {
    MR::connectToScene(this, -1, -1, -1, MR::DrawType_OceanBowlBloomDrawer);
}

void OceanRingBloomDrawer::draw() const {
    if (!MR::isValidDraw(mRing) || !MR::isCameraInWater()) {
        return;
    }

    mRing->mRingDrawer->drawBloom();
}