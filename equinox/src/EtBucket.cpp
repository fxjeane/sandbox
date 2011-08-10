#include "EtBucket.h"

void EiCalculateBuckets(EtBucketWorker *bucketw,
					  const int xres, const int yres,
					  const int bucketSize) {
	unsigned int x,y,i;
	unsigned int numx,numy;
	numx = xres / bucketSize;
	numy = yres / bucketSize;
	// check for remainder buckets
	if (xres % bucketSize != 0) numx++;
	if (yres % bucketSize != 0) numy++;

	const unsigned int bsize = sizeof(EtBucket);
	const unsigned int wsize = numx * numy;
	EtBucket buckets[wsize];
	bucketw->buckets = (EtBucket*)malloc(bsize * wsize);
	bucketw->num = wsize;
	i = 0;
	for (y=0; y < yres; y+=bucketSize) {
		for (x=0; x < xres; x+=bucketSize) {
			EtBucket tmp ;
			tmp.pos.x = x; tmp.pos.y = y;
			int nextx 	= x + bucketSize;
			int nexty 	= y + bucketSize;
			int modx  	= (nextx % xres);
			tmp.width 	= modx > bucketSize ? bucketSize : modx == bucketSize ? bucketSize:bucketSize - modx;
			int mody	= (nexty % yres);
			tmp.height	= mody > bucketSize ? bucketSize : mody == bucketSize ? bucketSize:bucketSize - mody;
			buckets[i++] = tmp;
		}
	}
	memcpy(bucketw->buckets,buckets,bsize * wsize);
}

void EiProcessBucket(EtBucket bucket, Rgba *px, int &iterator) {
		int x,y;
		for (int y = bucket.pos.y; y < bucket.pos.y + bucket.height ; y++)
		{
			for (int x = bucket.pos.x; x < bucket.pos.x + bucket.width; x++)
			{
				Rgba *p = &px[iterator++];
				p->r = 0;
				p->g = 1;
				p->b = 0;
				p->a = 1;
			}
		}
};
