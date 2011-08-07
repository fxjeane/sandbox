#ifndef ET_BUCKET_H
#define ET_BUCKET_H
#include "equinox.h"

struct EtBucket {
	EtPoint2	pos;
	int			width;
	int			height;
};
typedef struct EtBucket EtBucket;

struct EtBucketWorker {
	EtBucket	*buckets;
	int			x;
	int			y;
};
typedef struct EtBucketWorker EtBucketWorker;

void CalculateBuckets(EtBucketWorker*,const int, const int, const int);

#endif // ET_BUCKET_H
