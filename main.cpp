//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real
{
protected:
  double r{};
public:
  Real (double x): r{x} {}
  double GetReal(){return r;}
Real operator*(double n) const 
{
  Real y{r*n};
  return y;
}
};

class Complex:public Real 
{
protected:
  double newr; 
public:
  Complex (double x, double y):Real(x), newr{y}{}
double GetImaginary(){return newr;}
Complex operator*(double w) const 
{
  Complex y{r*w,newr*w};
    return y; 
}
};

class Surreal: public Complex 
{
  protected:
    double xyz; 
  public:
  Surreal ( double x, double y, double z):Complex (x,y), xyz{z}{}
  double GetSurreal(){return xyz;}
  Surreal operator*(double w)const
  {
    Surreal y{r*w,newr*w,xyz*w};
    return y; 
  }
  
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
