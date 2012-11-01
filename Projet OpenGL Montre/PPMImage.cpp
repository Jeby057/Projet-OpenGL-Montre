#include "PPMImage.h"

PPMImage::PPMImage(char *fichier)
{
	Load(fichier);
}


PPMImage::~PPMImage(void)
{
	if (_data)
      delete [] _data;
}


void PPMImage::Load(char *fichier)
{
	char buff[16];

    ifstream fp(fichier, ios::in|ios::binary);
    int maxval,lig_comm=0;

    if (!fp.is_open()){
	cerr <<"Unable to open file " << fichier << endl;
	throw 0;
    }

    fp.read(buff, 3);
    if (fp.bad()){
      cerr <<"Unable to open file " << fichier << endl;
      throw 0;
    }
    
    if (buff[0] != 'P' || buff[1] != '6'){
	cerr << "Invalid image format (must be `P6')\n" ;
	throw 0;
    }

    if (buff[2] != 0x0a)
      fp.seekg(-1,ios::cur);

    while (fp.read(buff, 1), buff[0] == '#'){
      lig_comm++;
      while (fp.read(buff, 1), buff[0] != '\n');
    }

    fp.seekg(-1,ios::cur);

    fp >> _sizeX;
    fp >> _sizeY;
    if (fp.bad()){
      cerr << "Error loading image " << fichier << endl ;
      throw 0;
    }

    fp >> maxval;
    if (fp.bad()){
      cerr << "Error loading image " << fichier << endl ;
      throw 0;
    }

    while (fp.read(buff, 1), buff[0] != '\n');

    _data = new  GLubyte[3 * _sizeX * _sizeY];
    if (!_data)
    {
      cerr <<  "Unable to allocate memory\n";
      throw 0;
    }

    fp.read((char*)_data, 3 * _sizeX*_sizeY);
    if (fp.bad()) {
      cerr <<  "Error loading image " << fichier << endl;
      throw 0;
    }
    
    fp.close();
}

int PPMImage::GetSizeX()
{
	return _sizeX;
}

int PPMImage::GetSizeY()
{
	return _sizeY;
}

GLubyte* PPMImage::GetImage()
{
	return _data;
}
