#ifndef ET_BUCKET_H
#define ET_BUCKET_H
#include "EtGeometry.h"
#include "exr.h"

struct EtBucket {
	EtPoint2	pos;
	int			width;
	int			height;
};
typedef struct EtBucket EtBucket;

struct EtBucketWorker {
	EtBucket			*buckets;
	unsigned int	num;
};
typedef struct EtBucketWorker EtBucketWorker;

ET_API void EiCalculateBuckets(EtBucketWorker*,const int, const int, const int);
ET_API void EiProcessBucket(const EtBucket,Rgba**);

#endif // ET_BUCKET_H
