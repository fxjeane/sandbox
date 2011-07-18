#include <stdio.h>
#include "equinox.h"

int main() {
	EtParamDef foo = EiParamDefInt("foo",1);
	EtParamDef fee = EiParamDefInt("fee",2);
	EtParamDef fii = EiParamDefInt("fii",3);

	EtNode myNode = EiNode("MyNode");	
	EiNodeAddParam(&myNode,foo);
	EiNodeAddParam(&myNode,fee);
	EiNodeAddParam(&myNode,fii);

	printf("Param %s has value %d\n","foo",EiNodeGetInt(&myNode,"foo"));
	printf("Param %s has value %d\n","fee",EiNodeGetInt(&myNode,"fee"));
	printf("Param %s has value %d\n","fii",EiNodeGetInt(&myNode,"fii"));

	//EiNodeSetInt(&myNode,"foo",400);
	//printf("Param %s has value %d\n","foo",EiNodeGetInt(&myNode,"fii"));
	return 0;
}
