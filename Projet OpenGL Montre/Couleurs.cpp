#include "Couleurs.h"

float Couleur::blanc[] = { 1.0F,1.0F,1.0F,1.0F };
float Couleur::jaune[] = { 1.0F,1.0F,0.0F,1.0F };
float Couleur::cyan[] = { 0.0F,1.0F,1.0F,1.0F };
float Couleur::magenta[] = { 1.0F,0.0F,1.0F,1.0F };
float Couleur::rouge[] = { 1.0F,0.0F,0.0F,1.0F };
float Couleur::vert[] = { 0.0F,1.0F,0.0F,1.0F };
float Couleur::bleu[] = { 0.0F,0.0F,1.0F,1.0F };
float Couleur::noir[] = { 0.0F,0.0F,0.0F,1.0F };
float Couleur::grisTresFonce[] = { 0.1F,0.1F,0.1F,1.0F };
float Couleur::grisFonce[] = { 0.25F,0.25F,0.25F,1.0F };
float Couleur::grisMoyen[] = { 0.5F,0.5F,0.5F,1.0F };
float Couleur::grisClair[] = { 0.75F,0.75F,0.75F,1.0F };
float Couleur::jauneClair[] = { 0.75F,0.75F,0.0F,1.0F };
float Couleur::jauneFonce[] = { 0.5F,0.5F,0.0F,1.0F };
float Couleur::cyanFonce[] = { 0.0F,0.5F,0.5F,1.0F };
float Couleur::magentaFonce[] = { 0.5F,0.0F,0.5F,1.0F };
float Couleur::rougeFonce[] = { 0.5F,0.0F,0.0F,1.0F };
float Couleur::vertFonce[] = { 0.0F,0.5F,0.0F,1.0F };
float Couleur::bleuFonce[] = { 0.0F,0.0F,0.5F,1.0F };
float Couleur::brun[] = { 0.8F,0.6F,0.4F,1.0F };
float Couleur::rose[] = { 1.0F,0.65F,0.65F,1.0F };
float Couleur::roseFonce[] = { 0.6F,0.25F,0.25F,1.0F };
float Couleur::bleuCiel[] = { 0.5F,0.5F,1.0F,1.0F };
float Couleur::bleuCielFonce[] = { 0.25F,0.25F,0.5F,1.0F };


float* Couleur::Blanc(void) {
  return(blanc);
}

float* Couleur::Jaune(void) {
  return(jaune);
}

float* Couleur::Cyan(void) {
  return(cyan);
}

float* Couleur::Magenta(void) {
  return(magenta);
}

float* Couleur::Rouge(void) {
  return(rouge);
}

float* Couleur::Vert(void) {
  return(vert);
}

float* Couleur::Bleu(void) {
  return(bleu);
}

float* Couleur::Noir(void) {
  return(noir);
}

float* Couleur::GrisTresFonce(void) {
  return(grisTresFonce);
}

float* Couleur::GrisFonce(void) {
  return(grisFonce);
}

float* Couleur::GrisMoyen(void) {
  return(grisMoyen);
}

float* Couleur::GrisClair(void) {
  return(grisClair);
}

float* Couleur::JauneClair(void) {
  return(jauneClair);
}

float* Couleur::JauneFonce(void) {
  return(jauneFonce);
}

float* Couleur::CyanFonce(void) {
  return(cyanFonce);
}

float* Couleur::MagentaFonce(void) {
  return(magentaFonce);
}

float* Couleur::RougeFonce(void) {
  return(rougeFonce);
}

float* Couleur::VertFonce(void) {
  return(vertFonce);
}

float* Couleur::BleuFonce(void) {
  return(bleuFonce);
}

float* Couleur::Brun(void) {
  return(brun);
}

float* Couleur::Rose(void) {
  return(rose);
}

float* Couleur::RoseFonce(void) {
  return(roseFonce);
}

float* Couleur::BleuCiel(void) {
  return(bleuCiel);
}

float* Couleur::BleuCielFonce(void) {
  return(bleuCielFonce);
}

float* Couleur::BleuCiel(float alpha) {
  static float coul[4];
  coul[0] = bleuCiel[0];
  coul[1] = bleuCiel[1];
  coul[2] = bleuCiel[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::BleuCielFonce(float alpha) {
  static float coul[4];
  coul[0] = bleuCielFonce[0];
  coul[1] = bleuCielFonce[1];
  coul[2] = bleuCielFonce[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::Rose(float alpha) {
  static float coul[4];
  coul[0] = rose[0];
  coul[1] = rose[1];
  coul[2] = rose[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::RoseFonce(float alpha) {
  static float coul[4];
  coul[0] = roseFonce[0];
  coul[1] = roseFonce[1];
  coul[2] = roseFonce[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::Gris(float niveau,float alpha) {
  static float coul[4];
  coul[0] = niveau;
  coul[1] = niveau;
  coul[2] = niveau;
  coul[3] = alpha;
  return(coul);
}

float* Couleur::GrisFonce(float alpha) {
  static float coul[4];
  coul[0] = grisFonce[0];
  coul[1] = grisFonce[1];
  coul[2] = grisFonce[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::GrisTresFonce(float alpha) {
  static float coul[4];
  coul[0] = grisTresFonce[0];
  coul[1] = grisTresFonce[1];
  coul[2] = grisTresFonce[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::GrisMoyen(float alpha) {
  static float coul[4];
  coul[0] = grisMoyen[0];
  coul[1] = grisMoyen[1];
  coul[2] = grisMoyen[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::GrisClair(float alpha) {
  static float coul[4];
  coul[0] = grisClair[0];
  coul[1] = grisClair[1];
  coul[2] = grisClair[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::Blanc(float alpha) {
  static float coul[4];
  coul[0] = blanc[0];
  coul[1] = blanc[1];
  coul[2] = blanc[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::Jaune(float alpha) {
  static float coul[4];
  coul[0] = jaune[0];
  coul[1] = jaune[1];
  coul[2] = jaune[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::Cyan(float alpha) {
  static float coul[4];
  coul[0] = cyan[0];
  coul[1] = cyan[1];
  coul[2] = cyan[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::Magenta(float alpha) {
  static float coul[4];
  coul[0] = magenta[0];
  coul[1] = magenta[1];
  coul[2] = magenta[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::Noir(float alpha) {
  static float coul[4];
  coul[0] = noir[0];
  coul[1] = noir[1];
  coul[2] = noir[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::Vert(float alpha) {
  static float coul[4];
  coul[0] = vert[0];
  coul[1] = vert[1];
  coul[2] = vert[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::Rouge(float alpha) {
  static float coul[4];
  coul[0] = rouge[0];
  coul[1] = rouge[1];
  coul[2] = rouge[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::Bleu(float alpha) {
  static float coul[4];
  coul[0] = bleu[0];
  coul[1] = bleu[1];
  coul[2] = bleu[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::JauneClair(float alpha) {
  static float coul[4];
  coul[0] = jauneClair[0];
  coul[1] = jauneClair[1];
  coul[2] = jauneClair[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::JauneFonce(float alpha) {
  static float coul[4];
  coul[0] = jauneFonce[0];
  coul[1] = jauneFonce[1];
  coul[2] = jauneFonce[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::CyanFonce(float alpha) {
  static float coul[4];
  coul[0] = cyanFonce[0];
  coul[1] = cyanFonce[1];
  coul[2] = cyanFonce[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::MagentaFonce(float alpha) {
  static float coul[4];
  coul[0] = magentaFonce[0];
  coul[1] = magentaFonce[1];
  coul[2] = magentaFonce[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::VertFonce(float alpha) {
  static float coul[4];
  coul[0] = vertFonce[0];
  coul[1] = vertFonce[1];
  coul[2] = vertFonce[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::RougeFonce(float alpha) {
  static float coul[4];
  coul[0] = rougeFonce[0];
  coul[1] = rougeFonce[1];
  coul[2] = rougeFonce[2];
  coul[3] = alpha;
  return(coul);
}

float* Couleur::BleuFonce(float alpha) {
  static float coul[4];
  coul[0] = bleuFonce[0];
  coul[1] = bleuFonce[1];
  coul[2] = bleuFonce[2];
  coul[3] = alpha;
  return(coul);
}


float* Couleur::newCouleur(float r,float v,float b,float a) {
  static float coul[4];
  coul[0] = r;
  coul[1] = v;
  coul[2] = b;
  coul[3] = a;
  return(coul);
}

float* Couleur::newCouleur(float* c) {
  float* coul =(float*) calloc(4,sizeof(float));
  coul[0] = c[0];
  coul[1] = c[1];
  coul[2] = c[2];
  coul[3] = c[3];
  return(coul);
}

void freeCouleur(float* c) {
  free(c);
}

float** Couleur::paletteColoree(void) {
  int i;
  float **p =(float**) calloc(256,sizeof(float*));
  for ( i = 0 ; i <= 51 ; i++ ) {
    p[i] =(float*) calloc(4,sizeof(float));
    p[i][0] = 0.0F;
    p[i][1] = 1.0F;
    p[i][2] = i/51.0F;
    p[i][3] = 1.0F; }
  for ( ; i <= 102 ; i++ ) {
    p[i] =(float*) calloc(4,sizeof(float));
    p[i][0] = 0.0F;
    p[i][1] = 1.0F-(i-51)/51.0F;
    p[i][2] = 1.0F;
    p[i][3] = 1.0F; }
  for ( ; i <= 153 ; i++ ) {
    p[i] =(float*) calloc(4,sizeof(float));
    p[i][0] = (i-102)/51.0F;
    p[i][1] = 0.0F;
    p[i][2] = 1.0F;
    p[i][3] = 1.0F; }
  for ( ; i <= 204 ; i++ ) {
    p[i] =(float*) calloc(4,sizeof(float));
    p[i][0] = 1.0F;
    p[i][1] = 0.0F;
    p[i][2] = 1.0F-(i-153)/51.0F;
    p[i][3] = 1.0F; }
  for ( ; i <= 255 ; i++ ) {
    p[i] =(float*) calloc(4,sizeof(float));
    p[i][0] = 1.0F;
    p[i][1] = (i-204)/51.0F;
    p[i][2] = 0.0F;
    p[i][3] = 1.0F; }
  return(p);
}

float** Couleur::paletteGrisee(void) {
  int i;
  float **p =(float**) calloc(256,sizeof(float*));
  for ( i = 0 ; i <= 255 ; i++ ) {
    p[i] =(float*) calloc(4,sizeof(float));
    p[i][0] = p[i][1] = p[i][2] = i/255.0F;
    p[i][3] = 1.0F; }
  return(p);
}
