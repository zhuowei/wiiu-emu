#pragma once
#include "systemtypes.h"

#pragma pack(push, 1)

// BindFlagsToString__20_GX2RResourceTrackerSF18_GX2RResourceFlags
// UsageFlagsToString__20_GX2RResourceTrackerSF18_GX2RResourceFlags
enum class GX2RResourceFlags
{
   // GX2R_BIND_*
   BindTexture       = 1 << 0,
   BindColorBuffer   = 1 << 1,
   BindDepthBuffer   = 1 << 2,
   BindScanBuffer    = 1 << 3,
   BindVertexBuffer  = 1 << 4,
   BindIndexBuffer   = 1 << 5,
   BindUniformBlock  = 1 << 6,
   BindShaderProgram = 1 << 7,
   BindStreamOutput  = 1 << 8,
   BindDisplayList   = 1 << 9,
   BindGSRing        = 1 << 10,

   // GX2R_USAGE_*
   UsageCpuRead      = 1 << 11,
   UsageCpuWrite     = 1 << 12,
   UsageGpuRead      = 1 << 13,
   UsageGpuWrite     = 1 << 14,
   UsageDmaRead      = 1 << 15,
   UsageDmaWrite     = 1 << 16,
   UsageForceMEM1    = 1 << 17,
   UsageForceMEM2    = 1 << 18,
};

enum class GX2SurfaceFormat
{
   First = 0x01,
   R8G8B8A8 = 26,
   Last = 0x83f,
};

static inline std::ostream&
operator<<(std::ostream& os, const GX2SurfaceFormat& val)
{
   switch (val) {
   case GX2SurfaceFormat::R8G8B8A8:
      return os << "R8G8B8A8";
   default:
      return os << static_cast<int>(val);
   }
}

enum class GX2SurfaceDim
{
   Texture2D = 1,          // guessed from game ;D
   Texture2DMSAA = 6,      // GX2InitTextureRegs
   Texture2DMSAAArray = 7  // GX2InitTextureRegs
};

static inline std::ostream&
operator<<(std::ostream& os, const GX2SurfaceDim& val)
{
   switch (val) {
   case GX2SurfaceDim::Texture2D:
      return os << "Texture2D";
   case GX2SurfaceDim::Texture2DMSAA:
      return os << "Texture2DMSAA";
   case GX2SurfaceDim::Texture2DMSAAArray:
      return os << "Texture2DMSAAArray";
   default:
      return os << static_cast<int>(val);
   }
}

// GX2SetAAModeEx
enum class GX2AAMode
{
   Mode1X = 0, // GX2ResolveAAColorBuffer
   First = 0,
   Last = 3
};

static inline std::ostream&
operator<<(std::ostream& os, const GX2AAMode& val)
{
   switch (val) {
   case GX2AAMode::Mode1X:
      return os << "Mode1X";
   default:
      return os << static_cast<int>(val);
   }
}

// GX2GetSurfaceInfo GX2_TILE_MODE_LINEAR_SPECIAL
enum class GX2TileMode
{
   Default = 0,
   LinearSpecial = 0x10,
};

static inline std::ostream&
operator<<(std::ostream& os, const GX2TileMode& val)
{
   switch (val) {
   case GX2TileMode::Default:
      return os << "Default";
   case GX2TileMode::LinearSpecial:
      return os << "LinearSpecial";
   default:
      return os << static_cast<int>(val);
   }
}

// GX2SetColorBuffer
enum class GX2SurfaceUse
{
   Texture     = 1 << 0,
   ColorBuffer = 1 << 1,
   DepthBuffer = 1 << 2,
};

static inline std::ostream&
operator<<(std::ostream& os, const GX2SurfaceUse& val)
{
   switch (val) {
   case GX2SurfaceUse::Texture:
      return os << "Texture";
   case GX2SurfaceUse::ColorBuffer:
      return os << "ColorBuffer";
   case GX2SurfaceUse::DepthBuffer:
      return os << "DepthBuffer";
   default:
      return os << static_cast<int>(val);
   }
}

// GX2InitTextureRegs
// G2XRCreateSurface
struct GX2Surface
{
   be_val<GX2SurfaceDim> dim; // "GX2_SURFACE_DIM_2D_MSAA or GX2_SURFACE_DIM_2D_MSAA_ARRAY" = 0 or 6?
   be_val<uint32_t> width;
   be_val<uint32_t> height;
   be_val<uint32_t> depth;
   be_val<uint32_t> mipLevels; // GX2CalcSurfaceSizeAndAlignment -> _GX2CalcNumLevels
   be_val<GX2SurfaceFormat> format;
   be_val<GX2AAMode> aa;
   union // Is this correct?? Union???
   {
      be_val<GX2SurfaceUse> use; // GX2InitTextureRegs
      be_val<uint32_t> resourceFlags; // G2XRCreateSurface
   };
   be_val<uint32_t> imageSize;
   be_ptr<void> image;
   be_val<uint32_t> mipmapSize; // sizeof mipPtr
   be_ptr<void> mipmaps;
   be_val<uint32_t> tileMode;
   be_val<uint32_t> swizzle; // GX2SetSurfaceSwizzle;
   be_val<uint32_t> alignment;
   be_val<uint32_t> pitch;
   UNKNOWN(0x74 - 0x40);
};
CHECK_OFFSET(GX2Surface, 0x0, dim);
CHECK_OFFSET(GX2Surface, 0x4, width);
CHECK_OFFSET(GX2Surface, 0x8, height);
CHECK_OFFSET(GX2Surface, 0xc, depth);
CHECK_OFFSET(GX2Surface, 0x10, mipLevels);
CHECK_OFFSET(GX2Surface, 0x14, format);
CHECK_OFFSET(GX2Surface, 0x18, aa);
CHECK_OFFSET(GX2Surface, 0x1c, use);
CHECK_OFFSET(GX2Surface, 0x1c, resourceFlags);
CHECK_OFFSET(GX2Surface, 0x20, imageSize);
CHECK_OFFSET(GX2Surface, 0x24, image);
CHECK_OFFSET(GX2Surface, 0x28, mipmapSize);
CHECK_OFFSET(GX2Surface, 0x2c, mipmaps);
CHECK_OFFSET(GX2Surface, 0x30, tileMode);
CHECK_OFFSET(GX2Surface, 0x34, swizzle);
CHECK_OFFSET(GX2Surface, 0x38, alignment);
CHECK_OFFSET(GX2Surface, 0x3C, pitch);
CHECK_SIZE(GX2Surface, 0x74);

struct GX2DepthBuffer
{
   GX2Surface surface;

   uint32_t viewMip; // GX2ClearDepthStencilEx
   uint32_t viewFirstSlice; // GX2ClearDepthStencilEx
   uint32_t viewNumSlices; // GX2ClearDepthStencilEx
   void *hiZPtr; // GX2ExpandDepthBuffer
   // UNKNOWN SIZE
};
CHECK_OFFSET(GX2DepthBuffer, 0x74, viewMip);
CHECK_OFFSET(GX2DepthBuffer, 0x78, viewFirstSlice);
CHECK_OFFSET(GX2DepthBuffer, 0x7C, viewNumSlices);
CHECK_OFFSET(GX2DepthBuffer, 0x80, hiZPtr);

struct GX2ColorBuffer
{
   GX2Surface surface;

   uint32_t viewMip; // GX2ClearBuffersEx
   uint32_t viewFirstSlice; // GX2ClearBuffersEx
   uint32_t viewNumSlices; // GX2ClearBuffersEx
   // UNKNOWN SIZE
};
CHECK_OFFSET(GX2ColorBuffer, 0x74, viewMip);
CHECK_OFFSET(GX2ColorBuffer, 0x78, viewFirstSlice);
CHECK_OFFSET(GX2ColorBuffer, 0x7C, viewNumSlices);

#pragma pack(pop)

void
GX2CalcSurfaceSizeAndAlignment(GX2Surface *surface);

void
GX2CalcDepthBufferHiZInfo(GX2DepthBuffer *depthBuffer, be_val<uint32_t> *outSize, be_val<uint32_t> *outAlignment);

void
GX2SetColorBuffer(GX2ColorBuffer *colorBuffer, uint32_t unk1);

void
GX2SetDepthBuffer(GX2DepthBuffer *depthBuffer);

void
GX2InitColorBufferRegs(GX2ColorBuffer *colorBuffer);

void
GX2InitDepthBufferRegs(GX2DepthBuffer *depthBuffer);
