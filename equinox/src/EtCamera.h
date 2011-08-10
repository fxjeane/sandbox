#ifndef ET_CAMERA_H
#define ET_CAMERA_H
#include "EtTypes.h"
#include "EtPluginManager.h"
#include "EtGeometry.h"

struct EtCameraData {
	EtPoint		o;
};
typedef struct EtCameraData EtCameraData;

struct EtCameraMethods {
	void (* createRay)(void);
};
typedef struct EtCameraMethods EtCameraMethods;

#define camera_create_ray void createRay (void)
#endif // ET_CAMERA_H
