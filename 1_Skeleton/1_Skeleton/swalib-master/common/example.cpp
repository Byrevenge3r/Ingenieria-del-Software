#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "vector2d.h"
#include <Windows.h>
#include "../../swalib-master/swalib_example/swalib_example/ball.h"
#include "../../swalib-master/swalib_example/swalib_example/Logic.h"
#include "../../swalib-master/swalib_example/swalib_example/Render.h"




float GetTime()
{
	LARGE_INTEGER frequency;
	LARGE_INTEGER prevtime{};
	QueryPerformanceFrequency(&frequency);

	LARGE_INTEGER start;
	QueryPerformanceCounter(&start);

	LARGE_INTEGER end;
	QueryPerformanceCounter(&end);

	LARGE_INTEGER currentTime;
	QueryPerformanceFrequency(&currentTime);

	return (static_cast<double> (currentTime.QuadPart - static_cast<double> (prevtime.QuadPart) / static_cast<double> (frequency.QuadPart)));
}


int Main(void)
{

	Logic logic;
	Render render;
	double fixedtick = 1.0 / 60.0;
	float timeforfps = 0;
	float lastime = GetTime();
	double currentime = 0; double deltatime = 0;

	render.init();
	logic.Init();
	//SYS_Sleep(17);


	while (!SYS_GottaQuit())
	{

		currentime = GetTime();
		deltatime += currentime - lastime;
		timeforfps = deltatime;

		while (deltatime >= fixedtick)
		{
			logic.Update();
			deltatime -= fixedtick;
		}

		render.draw(timeforfps);

	}

	logic.end();	
	render.end();

	return 0;
}