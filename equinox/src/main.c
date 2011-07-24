#include <stdio.h>
#include "equinox.h"

int main() {
	EtParam foo = EiParamInt("foo",256234);
	EtParam fee = EiParamBool("fee",0);
	EtParam fii = EiParamBool("fii",1);
	EtParam faa = EiParamFlt("faa",1.24);

	EtNode myNode = EiNode("MyNode");	
	EiNodeAddParam(&myNode,foo);
	EiNodeAddParam(&myNode,fee);
	EiNodeAddParam(&myNode,fii);
	EiNodeAddParam(&myNode,faa);

	//EiNodePrintNode(&myNode); 
	printf("Param %s has value %i\n","foo",EiNodeGetInt(&myNode,"foo"));
	printf("Param %s has value %i\n","fee",EiNodeGetBool(&myNode,"fee"));
	printf("Param %s has value %i\n","fii",EiNodeGetBool(&myNode,"fii"));
	printf("Param %s has value %f\n","faa",EiNodeGetFlt(&myNode,"faa"));

	EiNodeSetInt(&myNode,"foo",22);
	printf("Param %s has value %d\n","foo",EiNodeGetInt(&myNode,"foo"));
	EiNodeSetFlt(&myNode,"faa",3.174);
	printf("Param %s has value %f\n","faa",EiNodeGetFlt(&myNode,"faa"));
	return 0;
}
