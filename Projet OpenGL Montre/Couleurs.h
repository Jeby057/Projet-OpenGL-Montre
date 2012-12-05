#ifndef MODULE_COULEURS_H
#define MODULE_COULEURS_H

#include "stdlib.h"

class Couleur
{
	static float blanc[];
	static float jaune[];
	static float cyan[];
	static float magenta[];
	static float rouge[];
	static float vert[];
	static float bleu[];
	static float noir[];
	static float grisTresFonce[];
	static float grisFonce[];
	static float grisMoyen[];
	static float grisClair[];
	static float jauneClair[];
	static float jauneFonce[];
	static float cyanFonce[];
	static float magentaFonce[];
	static float rougeFonce[];
	static float vertFonce[];
	static float bleuFonce[];
	static float brun[];
	static float rose[];
	static float roseFonce[];
	static float bleuCiel[];
	static float bleuCielFonce[];

public:
	static float* Blanc(void);
	static float* Cyan(void);
	static float* Magenta(void);
	static float* Jaune(void);
	static float* Rouge(void);
	static float* Vert(void);
	static float* Bleu(void);
	static float* Noir(void);
	static float* GrisTresFonce(void);
	static float* GrisFonce(void);
	static float* GrisMoyen(void);
	static float* GrisClair(void);
	static float* JauneClair(void);
	static float* JauneFonce(void);
	static float* CyanFonce(void);
	static float* MagentaFonce(void);
	static float* RougeFonce(void);
	static float* VertFonce(void);
	static float* BleuFonce(void);
	static float* Brun(void);
	static float* Rose(void);
	static float* RoseFonce(void);
	static float* BleuCiel(void);
	static float* BleuCielFonce(void);

	static float* Blanc(float alpha);
	static float* Cyan(float alpha);
	static float* Magenta(float alpha);
	static float* Jaune(float alpha);
	static float* Rouge(float alpha);
	static float* Vert(float alpha);
	static float* Bleu(float alpha);
	static float* Noir(float alpha);
	static float* GrisTresFonce(float alpha);
	static float* GrisFonce(float alpha);
	static float* GrisMoyen(float alpha);
	static float* GrisClair(float alpha);
	static float* JauneClair(float alpha);
	static float* JauneFonce(float alpha);
	static float* CyanFonce(float alpha);
	static float* MagentaFonce(float alpha);
	static float* RougeFonce(float alpha);
	static float* VertFonce(float alpha);
	static float* BleuFonce(float alpha);
	static float* Brun(float alpha);
	static float* Rose(float alpha);
	static float* RoseFonce(float alpha);
	static float* BleuCiel(float alpha);
	static float* BleuCielFonce(float alpha);
	static float* Gris(float niveau,float alpha);
	static float* newCouleur(float* c);
	static void freeCouleur(float* c);
	static float* newCouleur(float r,float v,float b,float a);
	static float** paletteColoree(void);
	static float** paletteGrisee(void);

};
#endif
