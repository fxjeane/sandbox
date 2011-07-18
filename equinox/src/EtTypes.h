
#ifndef EITYPES_H
#define EITYPES_H

#define EI_TYPE_BYTE        	0x00  
#define EI_TYPE_INT				0x01  
#define EI_TYPE_UINT            0x02  
#define EI_TYPE_BOOLEAN       	0x03  
#define EI_TYPE_FLOAT           0x04  
#define EI_TYPE_RGB         	0x05  
#define EI_TYPE_RGBA        	0x06  
#define EI_TYPE_VECTOR       	0x07  
#define EI_TYPE_POINT         	0x08  
#define EI_TYPE_POINT2       	0x09  
#define EI_TYPE_STRING        	0x0A  
#define EI_TYPE_POINTER     	0x0B  
#define EI_TYPE_NODE          	0x0C  
#define EI_TYPE_ARRAY         	0x0D  
#define EI_TYPE_MATRIX        	0x0E  
#define EI_TYPE_ENUM         	0x0F  
#define EI_TYPE_UNDEFINED     	0xFF  
#define EI_TYPE_NONE         	0xFF 


/*
 * NULL value for null pointers
 */
#ifndef NULL
#define NULL 0x00000000
#endif


/****************************************************************************
   Basic data types
****************************************************************************/

typedef void               EtVoid;
typedef char               EtChar;
typedef char               EtBoolean;
#define TRUE 1
#define FALSE 0

typedef unsigned short     EtUShort;
typedef short              EtShort;
typedef unsigned long      EtULong;
typedef long               EtLong;

typedef signed long long   EtLLong;
typedef unsigned long long EtULLong;
#define AI_LLONG(x) x##ll
#define AI_ULLONG(x) x##ull

typedef int                EtInt;
typedef unsigned int       EtUInt;

typedef char               EtInt8;
typedef short              EtInt16;
typedef int                EtInt32;
typedef EtLLong            EtInt64;
typedef unsigned char      EtUInt8;
typedef unsigned short     EtUInt16;
typedef unsigned int       EtUInt32;
typedef EtULLong           EtUInt64;

typedef unsigned char      EtByte;

typedef float              EtFloat;
typedef double             EtDouble;

typedef const EtChar*      EtConstCharPtr;
typedef EtVoid*            EtVoidPtr;

#endif

