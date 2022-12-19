#include "Render.h"
#include "Logic.h"
#include "../../common/vector2d.h"
#include "../../common/font.h"
#include "../../common/stdafx.h"
#include "../../common/sys.h"
#include "../../common/core.h"
#include "Ball.h"

extern tBalls balls;
GLuint texsmallball;
GLuint  texbkg;

void Render::init()
{
	FONT_Init();	// Characters and symbols inicialization to draw on screen.

	texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);
	texsmallball = CORE_LoadPNG("data/tyrian_ball.png", false);

	// Set up rendering.
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT); // Sets up clipping.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Specifies clear values for the color buffers.
	glMatrixMode(GL_PROJECTION);	// Specifies projection matrix is the current matrix.
	glLoadIdentity();	// Replaces the current matrix with the identity matrix.
	glOrtho(0.0, SCR_WIDTH, 0.0, SCR_HEIGHT, 0.0, 1.0);	// Multiplies the current matrix by an orthographic matrix.
	glEnable(GL_TEXTURE_2D);	// Enabling two-dimensional texturing.
	// NOTA: Mirar diferencias comentando las 2 siguientes funciones.
	glEnable(GL_BLEND);	// Blend the incoming RGBA color values with the values in the color buffers.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	// Blend func. for alpha color.

}

void Render::draw(double elapsed)
{

	glClear(GL_COLOR_BUFFER_BIT);	// Clear color buffer to preset values.

	// Render backgground
	for (int i = 0; i <= SCR_WIDTH / 128; i++) {
		for (int j = 0; j <= SCR_HEIGHT / 128; j++) {
			CORE_RenderCenteredSprite(vec2(i * 128.f + 64.f, j * 128.f + 64.f), vec2(128.f, 128.f), texbkg);
		}
	}

	// Render balls
	for (int i = 0; i < NUM_BALLS; i++) {
		CORE_RenderCenteredSprite(balls[i].pos, vec2(balls[i].radius * 2.f, balls[i].radius * 2.f), balls[i].gfx);
	}

	// Text
	char str[15];
	sprintf(str, "FPS: %.2f",1.0/ elapsed );
	FONT_DrawString(vec2(SCR_WIDTH / 2 - 6 * 16, 16), str);
	SYS_Show();
	SYS_Pump();	// Process Windows messages.
}

void Render::end()
{
	CORE_UnloadPNG(texbkg);
	CORE_UnloadPNG(texsmallball);
	FONT_End();
}