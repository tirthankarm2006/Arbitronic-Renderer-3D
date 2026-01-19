#include "ARBpch.h"
#include "Core/Logging/ARB_Terminal_Log.h"
#include "Core/Logging/Log.h"
#include "Core/Sandbox/Sandbox.h"

extern ARB::Sandbox* GetSandboxApp();

#ifdef ARB_DEBUG
int main(int argc, char** argv) {
   ARB_INFO("Arbitronic 3D Engine Initialized");

   ARB::Sandbox* myApp = GetSandboxApp();
   myApp->runApp();

   ARB_TRACE("Arbitronic 3D Engine Closed");

   return 0;
}
#endif // ARB_DEBUG

#ifdef ARB_RELEASE
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    ARB_INFO("Arbitronic 3D Engine Initialized");

    return 0;
}
#endif // !


