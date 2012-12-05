#ifndef _PPM_IMAGE_H
#define _PPM_IMAGE_H

#include "Include.h"

class PPMImage
{
	int _sizeX, _sizeY;
	GLubyte *_data;

public:
	PPMImage(char *fichier);
	virtual ~PPMImage(void);
	virtual void Load(char *fichier);

	int GetSizeX();
	int GetSizeY();
	GLubyte* GetImage();
};
#endif
