#include <stdio.h>
#include "equinox.h"



int main() {
	//EiLoadPlugins("plugin");
	//EtNode cam = EiNode("ortho_camera");
	
	//cam.defaultMtds->init();
	int xres, yres;
	int r,c;
	xres = 100;
	yres = 100;
	EtBucketWorker *bucketw = malloc(sizeof(EtBucketWorker));
	CalculateBuckets(bucketw,xres,yres,32);
		
	int i,j;
	int bsize = sizeof(EtBucket);
	int wsize = bsize * bucketw->x * bucketw->y;
	for (i = 0 ; i < wsize ;i += bsize) {
		EtBucket thisb = bucketw->buckets[i];
		printf("Bucket %i pos = %i %i, w = %i, h = %i\n",j++, thisb.pos.x,thisb.pos.y,thisb.width,thisb.height);
	}
	return 0;
}

