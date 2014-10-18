//  VisualObj.cpp
//  VERYNICE
//
//  Created by Leslie on 10/6/14.
//


#include "VisualObj.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <iostream>


using namespace std;
using namespace ci;


VisualObj::VisualObj( int x, int y )
: mX( x ), mY( y ), mRadius( 10 ), mColor( randFloat(), randFloat(), randFloat() )
{
    cout << "I'm constructing with two integers" << endl;
}

// Unlike constructors, destructors can't be
// overloaded. There should be one way to destroy a specific class. We'll learn

VisualObj::~VisualObj()
{
    cout << "I'm destructing myself" << endl;
}

int VisualObj::getX()
{
    return mX;
}

// Definition of getY as above.
int VisualObj::getY()
{
    return mY;
}

// Definition of getRadius as above.
int VisualObj::getRadius()
{
    return mRadius;
}

void VisualObj::draw()
{
    gl::color( mColor );
    gl::drawSolidCircle( Vec2f( mX, mY ), mRadius );
}

