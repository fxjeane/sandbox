#ifndef EXR_H
#define EXR_H

#include <ImfRgbaFile.h>
#include <ImfOutputFile.h>
#include <ImfInputFile.h>
#include <ImfChannelList.h>
#include <ImfStringAttribute.h>
#include <ImfMatrixAttribute.h>
#include <ImfArray.h>
#include "EtColor.h"
#include "EtApi.h"

using namespace Imf;
using namespace Imath;


ET_API void writeRgbaImage(const char *name,const Rgba *pxl,int w, int h);
ET_API void writeImage(const char *name,const EtColor *pxl,int w, int h);
#endif // EXR_H
