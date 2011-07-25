#include <stdio.h>
#include "equinox.h"

int main() {
	printf("###########################################\n");	
	printf("Running EtParam Unit Test\n");
	printf("###########################################\n");
	printf("-----------------------------\n");
	printf("Test Byte\n");
	EtParam byte = EiParamByte("byte",'a');
	printf("Param %s initialized to  %c\n",
			"byte",byte.val.BYTE);
	byte.val.BYTE='b';
	printf("Param %s value changed to  %c\n",
			"byte",byte.val.BYTE);
	
	printf("-----------------------------\n");
	printf("Test Boolean\n");
	EtParam boolean = EiParamBool("bool",0);
	printf("Param %s initialized to  %i\n",
			"bool",boolean.val.BOOL);
	boolean.val.BOOL=1;
	printf("Param %s value changed to  %i\n",
			"bool",boolean.val.BOOL);
	
	printf("-----------------------------\n");
	printf("Test Integer\n");
	EtParam integer = EiParamInt("int",10);
	printf("Param %s initialized to  %i\n",
			"int",integer.val.INT);
	integer.val.INT = -20;
	printf("Param %s value changed to  %i\n",
			"int",integer.val.INT);
	
	printf("-----------------------------\n");
	printf("Test UInteger\n");
	EtParam uinteger = EiParamUInt("uint",10);
	printf("Param %s initialized to  %u\n",
			"uint",uinteger.val.UINT);
	uinteger.val.UINT = 20;
	printf("Param %s value changed to  %u\n",
			"uint",uinteger.val.UINT);
	
	return 0;
}
