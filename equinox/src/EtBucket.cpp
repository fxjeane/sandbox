#include "EtBucket.h"

void EiCalculateBuckets(EtBucketWorker *bucketw,
					  const int xres, const int yres,
					  const int bucketSize) {
	unsigned int x,y,i,j;
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
			EtPoint2 pos = {x,y};
			EtBucket tmp ;
			int nextx = x + bucketSize;
			int nexty = y + bucketSize;

			if ((nexty == yres)  && (nextx < xres)) {
				//printf("-- Touch Bottom Edge x %i y %i\n",nextx,nexty);
				tmp.pos 	= pos;
				tmp.width	= bucketSize;
				tmp.height  = bucketSize;
			} else if ((nexty < yres)  && (nextx == xres)) {
				//printf("-- Touch Right Edge x %i y %i\n",nextx,nexty);
				tmp.pos 	= pos;
				tmp.width	= bucketSize;
				tmp.height  = bucketSize;
			}  else if ((nexty == yres)  && (nextx == xres)) {
				//printf("-- Touch Bottom Corner -- x %i y %i\n",nextx,nexty);
				tmp.pos 	= pos;
				tmp.width	= bucketSize;
				tmp.height  = bucketSize;
			} else if ((nexty < yres)  && (nextx < xres)) {
				tmp.pos 	= pos;
				tmp.width	= bucketSize;
				tmp.height  = bucketSize;
			} else if ((nexty > yres) && (nextx < xres)) {
				tmp.pos 	= pos;
				tmp.width	= bucketSize;
				tmp.height 	= yres - y;
			} else if ((nexty < yres) && (nextx > xres)) {
				tmp.pos 	= pos;
				tmp.width	= xres - x;
				tmp.height 	= bucketSize;
			} else if ((nexty > yres) && (nextx > xres)) {
				tmp.pos 	= pos;
				tmp.width	= xres - x;
				tmp.height	= yres - y;
			}
			buckets[i++] = tmp;

		//	printf("ADD Bucket %i pos = %i %i, w = %i, h = %i\n",j++,
		//			tmp.pos.x,tmp.pos.y,tmp.width,tmp.height);
		}
	}
	memcpy(bucketw->buckets,buckets,bsize * wsize);
}

void EiProcessBucket(EtBucket bucket, Rgba **pixels) {
		//printf("Bucket pos = %i %i, w = %i, h = %i\n",
		//		bucket.pos.x,bucket.pos.y,
		//			bucket.width,bucket.height);
		for (int y = bucket.pos.y; y < bucket.pos.y + bucket.height; ++y)
		{
			//Rgba *col = &pixels[y];
			for (int x = bucket.pos.x; x < bucket.pos.x + bucket.width;++x)
			{
				printf("x %i y %i\n",x,y);
				Rgba *p = &pixels[x][y];
				p->r = 0;
				p->g = 1;
				p->b = 0;
				p->a = 1;
			}
		}
};
