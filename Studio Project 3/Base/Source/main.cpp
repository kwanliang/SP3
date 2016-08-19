#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "Application.h"

int main( void )
{
	Application &app = Application::GetInstance();
	app.Init();
	app.Run();
	app.Exit();

    _CrtDumpMemoryLeaks();
}