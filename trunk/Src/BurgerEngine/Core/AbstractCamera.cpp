#include "AbstractCamera.h"
#include "BurgerEngine/Graphics/CommonGraphics.h"

//--------------------------------------------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------------------------------------------
AbstractCamera::AbstractCamera( float fFOV, float fNear, float fFar )
	: m_fFOV( fFOV )
	, m_fNear( fNear )
	, m_fFar( fFar )
{
	m_f3Pos = vec3( 0.0f, 15.0f, 2.0f );
	m_f3Aim = vec3( 0.0f, 0.0f, 50.0f );
	m_f3Up = vec3( 0.0f, 1.0f, 0.0f );

	m_f3DofParams = vec4( -10.0f,  15.0f, 150.0f, 0.8f );
	m_fDofOffset = 0.0f;
}

void AbstractCamera::LookAt()
{
	gluLookAt( m_f3Pos.x, m_f3Pos.y, m_f3Pos.z, m_f3Aim.x, m_f3Aim.y, m_f3Aim.z, m_f3Up.x, m_f3Up.y, m_f3Up.z );
}