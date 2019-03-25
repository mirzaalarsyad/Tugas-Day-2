#include <iostream>
#include <cmath>

constexpr double dT= 1e-4;

struct Vector {
  double x;
  double y;
};

Vector add(Vector v1, Vector v2) {
  Vector v;
  v.x = v1.x + v2.x;
  v.y = v1.y + v2.y;
  
  return v;
}

Vector sub(Vector v1, Vector v2) {
  Vector v;
  v.x = v1.x - v2.x;
  v.y = v1.y - v2.y;
  
  return v;
}

Vector mul(Vector v, double k) {
  Vector w;
  w.x = v.x * k;
  w.y = v.y * k;
  
  return w;
}
Vector rot(Vector v, double k) {
  Vector w;
  w.x = std::cos(k)*v.x - std::sin(k)*v.y;
  w.y = std::sin(k)*v.x + std::cos(k)*v.y;
  
  return w;
}
Vector calc(Vector v, double w, double aM, double t) {
  Vector r;
  r.x = 0;
  r.y = 0;
  Vector a;
  a.x = aM;
  a.y = 0;
	for (double t1 = 0; t1 < t; t1 += dT) {
    r = add(r, mul(v, dT));
    v = add(v, mul(a,dT));
    a = rot(a, w*dT);
  }
  return r;
}


Vector calc1(Vector r, double t) {
  double w = 0.1;
  double aM = 0.1;
  double in;
  Vector cekr;
  bool a;
  Vector v0;
  v0.x=0;
  v0.y=0;
  for(int i=1;i<=4;i++){
    in=pow(10.0,-i);
    a=false;
    while (!a){
      Vector cekr = calc(v0,w,(aM+in),t);
      std::cout << incr << ' ' << w << ' ' << aM << ' ' << cekr.x << ' ' << cekr.y << std::endl;
      if(cekr.x<=r.x){
        aM+=in;
      }
      else{
        Vector cekr = calc(v0,(w+incr),aM,t);
        if(cekr.y<=r.y){
          w+=in;
        }
        else{
          a=true;
        }
      }
    }
  }
  Vector ret;
  ret.x=w;
  ret.y=aM;
  return ret;


}

int main() {
  Vector v;
  double w, aM, t;
  std::cin >> v.x >> v.y >> w >> aM >> t;
  Vector r = calc(v,w,aM,t);
  std::cout << r.x << ' ' << r.y << '\n';
  std::cin >> r.x >> r.y >> t;
  Vector hasil = calc1(r,t);
  std::cout << hasil.x << ' ' << hasil.y << std::endl;
}