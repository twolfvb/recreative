// B i b l i o t e c a s n e c e s a r i a s
#include<vector>
#include<cmath>
class PoligonoReg {
public :
PoligonoReg (int n, float l) ;
virtual float getArea(); // Re torna area d e l p o l i g o n o
virtual float getPerimetro(); // Re torna p e r im e t r o d e l p o l i g o n o
protected :
int n_lados; // Numero de l a d o s
float lado; // Largo de s u s l a d o s
};
