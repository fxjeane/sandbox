#include <stdio.h>
#include "plugin.h"

int main() {

	EtParamDef foo = EiParamDefInt("foo",10);
	EtParamDef fee = EiParamDefInt("fee",20);
	EtParamDef fii = EiParamDefInt("fii",301);

	EtNode myNode = EiNode("MyNode");	
	EiNodeAddParam(&myNode,foo);
	EiNodeAddParam(&myNode,fee);
	EiNodeAddParam(&myNode,fii);

	printf("Param %s has value %d\n","foo",EiNodeGetInt(&myNode,"foo"));
	printf("Param %s has value %d\n","fee",EiNodeGetInt(&myNode,"fee"));
	printf("Param %s has value %d\n","fii",EiNodeGetInt(&myNode,"fii"));

	return 0;
}
