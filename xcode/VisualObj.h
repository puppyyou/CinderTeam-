//  VisualObj.h
//  VERYNICE
//
//  Created by Leslie on 10/6/14.
//

#pragma once

class VisualObj {

public:
	
	
    VisualObj(); // Default Constructor, takes no arguments
    VisualObj(int x, int y);
    
    ~VisualObj();
    
    //void predraw( int x, int y );
    
    void draw();
	
    int getX();
    int getY();
    int getRadius();
	
	const ci::ColorAf& getColor();
	
    void setX( int x ) { mX = x; }
	void setY( int y ) { mY = y; }
	void setRadius( int radius ) { mRadius = radius; }
	void setColor( const ci::Colorf &color ) { mColor = color; }
    
    private:
    int mX, mY;
    int mRadius;
    ci::Colorf mColor;
};
