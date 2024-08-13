/*
 * Copyright 2024 Google LLC.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkPngRustCodec_DEFINED
#define SkPngRustCodec_DEFINED

#include <memory>

#include "include/codec/SkCodec.h"
#include "include/codec/SkEncodedImageFormat.h"
#include "third_party/rust/cxx/v1/cxx.h"

struct SkEncodedInfo;
class SkStream;

// This class provides the Skia image decoding API (`SkCodec`) on top of:
// * The third-party `png` crate (PNG decompression and decoding implemented in
//   Rust)
// * Skia's `SkSwizzler` and `skcms_Transform` (pixel format and color space
//   transformations implemented in C++).
class SkPngRustCodec : public SkCodec {
public:
    static std::unique_ptr<SkPngRustCodec> MakeFromStream(std::unique_ptr<SkStream>, Result*);

    SkPngRustCodec(SkEncodedInfo&&, std::unique_ptr<SkStream>, rust::Vec<uint8_t> decodedData);
    ~SkPngRustCodec() override;

private:
    // SkCodec overrides:
    SkEncodedImageFormat onGetEncodedFormat() const override;
    Result onGetPixels(const SkImageInfo& info,
                       void* pixels,
                       size_t rowBytes,
                       const Options&,
                       int* rowsDecoded) override;

    // TODO(https://crbug.com/356878144): Don't store a vector of
    // already-decoded pixels going forward.  Instead, we should store a
    // `rust::Box<rust_png::Reader>` and decode on demand (e.g. in
    // `onGetPixels`).
    rust::Vec<uint8_t> fDecodedData;
};

#endif  // SkPngRustCodec_DEFINED
