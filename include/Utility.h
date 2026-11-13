#pragma once

#include "revolution.h"
#include "Game/Util/CameraUtil.h"

inline void PSMTX44Copy_ASM(const register Mtx44 src, register Mtx44 dst)
{
    __asm {
        psq_l       fp1, 0(src), 0, 0;
        psq_st      fp1, 0(dst), 0, 0;
        psq_l       fp1, 8(src), 0, 0;
        psq_st      fp1, 8(dst), 0, 0;
        psq_l       fp1, 16(src), 0, 0;
        psq_st      fp1, 16(dst), 0, 0;
        psq_l       fp1, 24(src), 0, 0;
        psq_st      fp1, 24(dst), 0, 0;
        psq_l       fp1, 32(src), 0, 0;
        psq_st      fp1, 32(dst), 0, 0;
        psq_l       fp1, 40(src), 0, 0;
        psq_st      fp1, 40(dst), 0, 0;
        psq_l       fp1, 48(src), 0, 0;
        psq_st      fp1, 48(dst), 0, 0;
        psq_l       fp1, 56(src), 0, 0;
        psq_st      fp1, 56(dst), 0, 0;
    }
}

inline void loadTexProjectionMtx(u32 id) {
    Mtx44 cameraProjection;
    PSMTX44Copy_ASM(&MR::getCameraProjectionMtx()[0], &cameraProjection[0]);
    cameraProjection[2][0] = 0.0f;
    cameraProjection[2][1] = 0.0f;
    cameraProjection[2][2] = -1.0f;
    cameraProjection[2][3] = 0.0f;
    cameraProjection[3][0] = 0.0f;
    cameraProjection[3][1] = 0.0f;
    cameraProjection[3][2] = 0.0f;
    cameraProjection[3][3] = 1.0f;
    Mtx matrix;
    PSMTXConcat((const MtxPtr)&cameraProjection[0][0], MR::getCameraViewMtx(), matrix);
    TMtx34f mat;
    mat.identity();
    mat[0][0] = 0.5f;
    mat[0][2] = 0.5f;
    mat[1][1] = -0.5f;
    mat[1][2] = 0.5f;
    PSMTXConcat(mat, matrix, matrix);
    GXLoadTexMtxImm(matrix, id, GX_MTX3x4);
}