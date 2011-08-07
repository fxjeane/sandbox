#include "EtBucket.h"

void CalculateBuckets(EtBucketWorker *bucketw,
					  const int xres, const int yres,
					  const int bucketSize) {
	int r,c,i,j;
	unsigned int x,y;
	x = xres / bucketSize;
	y = yres / bucketSize;
	// check for remainder buckets
	if (x % bucketSize) x++;
	if (y % bucketSize) y++;

	const unsigned int bsize = sizeof(EtBucket);
	const unsigned int wsize = bsize * x * y;
	bucketw->buckets = malloc(wsize);
	bucketw->x = x;
	bucketw->y = y;
	
	i = j =0;
	for (c=0; c < xres; c+=bucketSize) {
		for (r=0; r < yres; r+=bucketSize) {
			EtPoint2 pos = {c,r};
			EtBucket tmp ;

			if ((r + bucketSize < yres) && (c + bucketSize < xres)) {
				tmp.pos 	= pos;
				tmp.width	= bucketSize;
				tmp.height = bucketSize;
				bucketw->buckets[i] = tmp;
				i+= bsize;
			}
			if ((r + bucketSize > yres) && (c + bucketSize < xres)) {
				tmp.pos 	= pos;
				tmp.width	= yres - r;
				tmp.height 	= bucketSize;
				bucketw->buckets[i] = tmp;
				i+= bsize;
			}
			if ((r + bucketSize < yres) && (c + bucketSize > xres)) {
				tmp.pos 	= pos;
				tmp.width	= bucketSize;
				tmp.height 	= xres - c;
				bucketw->buckets[i] = tmp;
				i+= bsize;
			}
			if ((r + bucketSize > yres) && (c + bucketSize > xres)) {
				tmp.pos 	= pos;
				tmp.width	= yres - r;
				tmp.height	= xres - c;;
				bucketw->buckets[i] = tmp;
				i+= bsize;
			}
		}
	}
}
