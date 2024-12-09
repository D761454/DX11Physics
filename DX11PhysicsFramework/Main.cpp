#include "DX11PhysicsFramework.h"
#include <windows.h>
#include <comdef.h>

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	DX11PhysicsFramework application = DX11PhysicsFramework();

	if (FAILED(application.Initialise(hInstance, nCmdShow)))
	{
		return -1;
	}

	// Main message loop
	MSG msg = { 0 };

	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			bool handled = false;

			if (msg.message >= WM_KEYFIRST && msg.message <= WM_KEYLAST)
			{
				handled = application.HandleKeyboard(msg);
			}
			else if (WM_QUIT == msg.message)
				break;

			if (!handled)
			{
				TranslateMessage(&msg);
				DispatchMessageW(&msg);
			}
		}
		else
		{
			application.Update();
			application.Draw();
		}
	}

	return (int)msg.wParam;
}