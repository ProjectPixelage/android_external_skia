/*
 * Copyright 2019 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef GrUtil_DEFINED
#define GrUtil_DEFINED

#include "include/core/SkTypes.h"

enum GrIntelGpuFamily {
    kUnknown_IntelGpuFamily,

    // 6th gen
    kSandyBridge_IntelGpuFamily,

    // 7th gen
    kIvyBridge_IntelGpuFamily,
    kValleyView_IntelGpuFamily, // aka BayTrail
    kHaswell_IntelGpuFamily,

    // 8th gen
    kCherryView_IntelGpuFamily, // aka Braswell
    kBroadwell_IntelGpuFamily,

    // 9th gen
    kApolloLake_IntelGpuFamily,
    kSkyLake_IntelGpuFamily,
    kGeminiLake_IntelGpuFamily,
    kKabyLake_IntelGpuFamily,
    kCoffeeLake_IntelGpuFamily,

    // 11th gen
    kIceLake_IntelGpuFamily,
};

GrIntelGpuFamily GrGetIntelGpuFamily(uint32_t deviceID);

#endif
