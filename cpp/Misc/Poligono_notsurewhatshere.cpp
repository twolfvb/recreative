//#include <iostream>
//#include "Hand.h"
//#include <string>
//
//using std::string;
//
//int main() {
//    Paper *paper = new Paper();
//    Stone stone ;
//    Spock spock;
//    Lizard lizard;
//                int result = stone.play(*paper);
//    delete paper;
//    string result_string = std::to_string(static_cast<long long>(result));
//    std::cout << "stone plays with paper and the result is " + result_string << std::endl;
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}

#include <iostream>
#include<vector>
#include<cmath>
class PoligonoReg {
 public :
  PoligonoReg (int n, float l) ;
  virtual float getArea();
  virtual float getPerimetro();
 protected :
  int n_lados;
  float lado;
};

PoligonoReg::PoligonoReg(int n, float l) : n_lados(n), lado(l) {}

float PoligonoReg::getPerimetro() {
  return lado * n_lados;
}
float PoligonoReg::getArea() {
  // el area de un poligono regular de N lados es n_lados * tamano_lado * apothem / 2
  // apothem se saca de la siguiente formula https://wikimedia.org/api/rest_v1/media/math/render/svg/b7e1a9c3d80699fe3b4c0922ac00f37c07808aba
  double pi = 3.14159267;
  float apothem = (lado/2) * tan(pi * (n_lados-2) / (n_lados * 2));
  return n_lados * lado * apothem / 2;
}

class Triangulo : public PoligonoReg {
 public:
  Triangulo (float l) : PoligonoReg(3, l) {}
};

class Cuadrado : public PoligonoReg {
 public:
  Cuadrado (float l) : PoligonoReg(4, l) {}
};

std::vector<PoligonoReg> addCuadrado(std::vector<PoligonoReg> vecp, Cuadrado c){
  vecp.push_back(c);
  return vecp;
}

class Envio {
 private:
  std::string direccion;
  bool recibido;

 public:
  Envio(int Id, std::string direccion, bool recibido) // estos 3 input pedia el enunciado, pero luego pedia 4
      : Id(Id),
      direccion(direccion),
      recibido(recibido),
      precio(0) {};
  Envio(int Id, std::string direccion, int precio, bool recibido) // Este si tiene 4 input
      : Id(Id),
        direccion(direccion),
        recibido(recibido),
        precio(precio) {};
  int Id;
  int precio;
  void CambiaDireccion(std::string nuevaDireccion);
  void MarcarRecibido(bool Recibido);
  bool getRecibido() {return recibido;};
};

void Envio::CambiaDireccion(std::string nuevaDireccion) {
  this->direccion = nuevaDireccion;
}

void Envio::MarcarRecibido(bool Recibido) {
  this->recibido = Recibido;
}

int main() {
  Triangulo *t = new Triangulo(1);
  std::cout << "area  del triangulo es " <<  t->getArea() << std::endl;
  std::cout << "perim del triangulo es " <<  t->getPerimetro() << std::endl;
  //t->getArea();

  Cuadrado *c = new Cuadrado(2);
  std::cout << "area  del cuadrado es " <<  c->getArea() << std::endl;
  std::cout << "perim del cuadrado es " <<  c->getPerimetro() << std::endl;
  //t->getArea();

  PoligonoReg *p = new PoligonoReg(4,1);
  std::cout << "area  del poligono es " <<  p->getArea() << std::endl;
  std::cout << "perim del poligono es " <<  p->getPerimetro() << std::endl;

  std::vector<PoligonoReg> poligonos;

  Cuadrado *c2 = new Cuadrado(4);
  Cuadrado *c3 = new Cuadrado(2);

  std::cout << " lalala" << std::endl;

  poligonos = addCuadrado(poligonos, *c);
  poligonos = addCuadrado(poligonos, *c2);
  poligonos = addCuadrado(poligonos, *c3);
  std::cout << " lalala" << std::endl;
  std::cout << "numero de cuadrados guardados es " << poligonos.size() << std::endl;
  for (auto poli_iter = poligonos.begin(); poli_iter != poligonos.end(); poli_iter++) {
    std::cout << "area para este poligono es  " << poli_iter->getArea() << std::endl;
  }

  Envio *e1 = new Envio(5, std::string("avenida pedro montt 1234"), 100, false);
  std::cout << "el envio tiene precio " << e1->precio << std::endl;
  std::cout << "el envio ha sido recibido? " << e1->getRecibido() << std::endl;
  e1->MarcarRecibido(true);
  std::cout << "el envio ha sido recibido? " << e1->getRecibido() << std::endl;

}
