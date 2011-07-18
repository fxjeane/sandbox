
#ifndef ETPARAM_H
#define ETPARAM_H

//#include "buf.h"
#include "EtTypes.h"

union EtParamValue {
	int		intVal;
	double	dblVal;
};
typedef union EtParamValue EtParamValue;

struct EtParamDef {
	const char 		*name;
	int 			type;
	EtParamValue	defVal;
};
typedef struct EtParamDef EtParamDef;

struct EtParamData {
	EtParamValue	val;
};
typedef struct EtParamData EtParamData;

int EiGetParamDefSize(const EtParamDef param);

EtParamDef EiParamDefInt(const char *name,const int def);

#endif // ETPARAM_H
