
#include <stdio.h>
#include "equinox.h"

int main() {
	printf("###########################################\n");	
	printf("Running EtNode Unit Test\n");
	printf("###########################################\n");
	EtNode myNode = EiNode("MyNode");	
	printf("-----------------------------\n");
	printf("Test adding and changing Byte param\n");
	EtParam byte = EiParamByte("byte",'a');
	EiNodeAddParam(&myNode,byte);
	printf("Param %s initialized to  %c\n",
			"byte",EiNodeGetByte(&myNode,"byte"));
	EiNodeSetByte(&myNode,"byte",'b');
	printf("Param %s value changed to  %c\n",
			"byte",EiNodeGetByte(&myNode,"byte"));
	
	printf("-----------------------------\n");
	printf("Test adding and changing Boolean param\n");
	EtParam boolean = EiParamBool("bool",0);
	EiNodeAddParam(&myNode,boolean);
	printf("Param %s initialized to  %i\n",
			"bool",EiNodeGetBool(&myNode,"bool"));
	EiNodeSetBool(&myNode,"bool",1);
	printf("Param %s value changed to  %i\n",
			"bool",EiNodeGetBool(&myNode,"bool"));
	
	printf("-----------------------------\n");
	printf("Test adding and changing Integer param\n");
	EtParam integer = EiParamInt("int",10);
	EiNodeAddParam(&myNode,integer);
	printf("Param %s initialized to  %i\n",
			"int",EiNodeGetInt(&myNode,"int"));
	EiNodeSetInt(&myNode,"int",1);
	printf("Param %s value changed to  %i\n",
			"int",EiNodeGetInt(&myNode,"int"));
	
	return 0;
}
