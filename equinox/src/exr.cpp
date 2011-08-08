#include "exr.h"

void writeRgbaImage(const char *name, const Rgba *pixels,int w,int h) 
{
	RgbaOutputFile file (name, w, h, WRITE_RGBA); 
	file.setFrameBuffer (pixels, 1, w); 
	file.writePixels (h);  
}

void  writeImage(const char *name,const EtColor *pxl,
					  int w, int h)
{
	//
	// Write an image with only a G (green) and a Z (depth) channel,
	// using class OutputFile.
	//
	//	- create a file header
	//	- add G and Z channels to the header
	//	- open the file, and store the header in the file
	//	- describe the memory layout of the G anx Z pixels
	//	- store the pixels in the file
	//

	Header header (w, h);
	header.channels().insert ("R", Channel (FLOAT));
	header.channels().insert ("G", Channel (FLOAT));
	header.channels().insert ("B", Channel (FLOAT));
	//header.channels().insert ("Z", Channel (FLOAT));

	OutputFile file (name, header);

	FrameBuffer frameBuffer;

	frameBuffer.insert ("R",						// name
						Slice (FLOAT,				// type
						(char *) &pxl->r,				// base
						sizeof (pxl->r) * 1,			// xStride
						sizeof (pxl->r) * w));		// yStride
	frameBuffer.insert ("G",						// name
						Slice (FLOAT,				// type
						(char *) &pxl->g,				// base
						sizeof (pxl->g) * 1,			// xStride
						sizeof (pxl->g) * w));		// yStride
	frameBuffer.insert ("B",						// name
						Slice (FLOAT,				// type
						(char *) &pxl->b,				// base
						sizeof (pxl->b) * 1,			// xStride
						sizeof (pxl->b) * w));		// yStride
/*
	frameBuffer.insert ("Z",					// name
			Slice (FLOAT,				// type
				(char *) zPixels,		// base
				sizeof (*zPixels) * 1,		// xStride
				sizeof (*zPixels) * width));	// yStride
*/
	file.setFrameBuffer (frameBuffer);
	file.writePixels (h);
}
