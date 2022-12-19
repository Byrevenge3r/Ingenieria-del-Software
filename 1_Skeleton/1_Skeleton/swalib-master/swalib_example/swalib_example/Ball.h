#pragma once
#include "../../common/vector2d.h"
#include "../../common/stdafx.h"

const unsigned int NUM_BALLS = 10;	// Max. num balls.
const float MAX_BALL_SPEED = 8.f;	// Max vel. of ball. (pixels/?).


class Ball
{
public:
	vec2   pos;	// Position.
	vec2   vel;	// Velocity.
	GLuint gfx;	// OpenGL for id. for visualization purposes. 
	float  radius;	// Radius.


	Ball();

};

typedef  Ball tBalls[NUM_BALLS];	// Array of balls.
