#include <stdio.h>
#include "equinox.h"
#include "exr.h"

int main() {
	EiLoadPlugins("plugin");
	EtNode cam = EiNode("ortho_camera");
	
	EtPoint foo = EiNodeGetPnt(&cam,"position");
	printf("pos = %f %f %f\n",foo.x,foo.y,foo.z);
	foo = EiNodeGetPnt(&cam,"lookAt");
	printf("dir = %f %f %f\n",foo.x,foo.y,foo.z);
	EiNodeSetPnt(&cam,"lookAt",0.5,0.1,0.0);
	foo = EiNodeGetPnt(&cam,"lookAt");
	printf("dir = %f %f %f\n",foo.x,foo.y,foo.z);
	
	int xres, yres;
	int r,c;
	xres = 640;
	yres = 480;
	int i;

	Rgba *px = (Rgba*)malloc(sizeof(Rgba) * xres * yres);

	EtBucketWorker *bucketw = (EtBucketWorker*)malloc(sizeof(EtBucketWorker));
	EiCalculateBuckets(bucketw,xres,yres,32);
	int j = 0;
	for (i=0;i< bucketw->num;i++) {
		EtBucket thisb = bucketw->buckets[i];
		EiProcessBucket(thisb,px,j);
	}

	writeRgbaImage("test.exr",px,xres, yres);
	return 0;
}

