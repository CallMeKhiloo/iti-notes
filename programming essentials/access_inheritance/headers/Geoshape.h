#ifndef __GEO__
#define __GEO__

class Geoshape
{
protected:
    float dim1, dim2;

public:
    Geoshape();
    Geoshape(float x);
    Geoshape(float x, float y);

    void setdim1(float x);
    void setdim2(float x);

    float getdim1();
    float getdim2();

    float calculateArea();
};

#endif