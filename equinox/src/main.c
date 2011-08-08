#include <stdio.h>
#include "equinox.h"
#include "exr.h"

int main() {
	//EiLoadPlugins("plugin");
	//EtNode cam = EiNode("ortho_camera");
	
	int xres, yres;
	int r,c;
	xres = 800;
	yres = 400;
	int i,j;

	Rgba px[xres][yres];

/*	// Why wont this work
	Rgba **px;
	px = (Rgba**)malloc(sizeof(Rgba*) * (xres));
	for (i = 0; i < xres; ++i) {
		px[i] = (Rgba*)malloc(sizeof(Rgba) * (yres));
	} */

	EtBucketWorker *bucketw = (EtBucketWorker*)malloc(sizeof(EtBucketWorker));
	EiCalculateBuckets(bucketw,xres,yres,32);

	for (i=0;i< bucketw->num;i++) {
		EtBucket thisb = bucketw->buckets[i];
		//printf("GET Bucket %i pos = %i %i, w = %i, h = %i\n",j++,
		//		thisb.pos.x,thisb.pos.y,thisb.width,thisb.height);
		for (int y = thisb.pos.y; y < thisb.pos.y + thisb.height; y++)
		{
			for (int x = thisb.pos.x; x < thisb.pos.x + thisb.width; x++)
			{
				Rgba *p = &px[x][y];
				p->r = 0;
				p->g = 1;
				p->b = 0;
				p->a = 1;
			}
		}
	}

	writeRgbaImage("test.exr",*px,xres, yres);
	return 0;
}

