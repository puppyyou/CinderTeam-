#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Camera.h"
#include "VisualObj.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MatrixTransformApp : public AppNative {
public:
	void setup();
    void prepareSettings( Settings *settings );
	void mouseDown(MouseEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
    void drawOneSphere(Vec3f iPosition,float size,int segments);
    
    // create the function here
	void drawStrokedCubeUncentered(const Vec3f &position, const Vec3f &size);
	
	CameraPersp mCam;
	bool		mPaused;

};

void MatrixTransformApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 612 );
#if ! defined( CINDER_COCOA_TOUCH )
	//settings->setResizable( false );
#endif
	settings->setFrameRate( 60 );
}

void MatrixTransformApp::drawOneSphere(Vec3f iPosition,float size, int segments)
{
    gl::drawSphere(iPosition , size,segments);
}

void MatrixTransformApp::drawStrokedCubeUncentered(const Vec3f& ori, const Vec3f& size)
{
	Vec3f max = ori + size;
}

void MatrixTransformApp::setup()
{
	// Enable alpha blending:
	gl::enableAlphaBlending();
	gl::enableDepthRead();
	gl::enableDepthWrite();
	
	// Setup camera:
	mCam.setPerspective( 60, getWindowAspectRatio(), 1, 1000 );
	
//	// Setup state handlers:
//	mMinIndex = 0;
//	mMaxIndex = 4;
//	mIndex    = mMinIndex;
//	mPaused   = false;
}

void MatrixTransformApp::mouseDown( MouseEvent event )
{
    
}

void MatrixTransformApp::keyUp(KeyEvent event)
{
	switch( event.getChar() ) {
		case ' ': {
			mPaused = !mPaused;
			break;
		}
		default: { break; }
	}
}

void MatrixTransformApp::update()
{
}

void MatrixTransformApp::draw()
{
	// Clear window:
	gl::clear( Color( 0, 0.1, 0.18 ) );
	
	// Update camera position:
    
    mCam.lookAt( Vec3f( cos( getElapsedSeconds() ), 1.0, sin( getElapsedSeconds() ) ) * 5.0, Vec3f::zero() );
	
	// Set matrix from camera:
	gl::setMatrices( mCam );
	
	
	// Draw origin:
    // Draw the pole
	//gl::drawCoordinateFrame();
	
	// Prepare matrix transformation settings:
	Vec3f tCubeDimension   = Vec3f( 1.0, 1.0, 1.0 );
	Vec3f tCubeTranslation = Vec3f( 1.2, 0.0, 0.0 );
	Vec3f tCubeScale       = Vec3f( 0.5, 0.5, 0.5 );
	Vec3f tCubeRotation    = Vec3f( sin(getElapsedSeconds()), -100, cos(getElapsedSeconds()) );
	
	{
	
        gl::pushMatrices();
	    gl::translate( tCubeTranslation );
		
		// Apply rotation:
		//gl::rotate( tCubeRotatioN );

		gl::scale( tCubeScale );
        gl::color( Color8u(255, 251, 71) );
    
        drawOneSphere(Vec3f(0,-2,0),2,36);
        
        gl::color( Color8u( 181, 226, 250 ) );
        drawOneSphere(Vec3f(-2,-1,4),1,36);
        
        gl::color( Color8u( 81, 25, 114 ) );
        drawOneSphere(Vec3f(-4,-2,0),1,36);
        
        gl::color( Color8u( 219, 250, 234 ) );
        drawOneSphere(Vec3f(1,3,0),1,36);
        
        gl::pushMatrices();
        gl::translate(Vec2f(1,0.5));
        //gl::rotate(Vec3f(2,2,2));
        
        gl::color( Color( 0.0, 0.2, 0.5 ) );
        drawOneSphere(Vec3f(5,5,0),1.8,36);
        
        gl::popMatrices();
        
        
        for (int i=0; i<5; i=i+1.5){
           
            float r;
            {
                gl::pushMatrices();
                gl::translate( tCubeTranslation * i );
                r = (2.0 * (i+1))*10;
            }
            
            gl::color( Color8u( r+5, r, r ) );
            gl::drawSphere( Vec3f::zero(), 0.1, 20 );
            //drawSphere (const Vec3f &center, float radius, int segments=12
     
                gl::popMatrices();
            // }
        }
        
        // Pop matrix:
		gl::popMatrices();
	}
	

    
	
	// Update index:
//	if( !mPaused && getElapsedFrames() % 100 == 0 ) {
//		mIndex++;
//		if( mIndex > mMaxIndex ) {
//			mIndex = mMinIndex;
//		}
//        
//	}
    
}

CINDER_APP_NATIVE( MatrixTransformApp, RendererGl )