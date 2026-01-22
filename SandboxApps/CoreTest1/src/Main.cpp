#include "Arbitronic.h"
#include "Sandbox/SandboxApp.h"
#include "Logging/Sandbox_Log.h"

#ifdef SANDBOX_DEBUG
int main(int argc, char** argv) {
   ARB_SANDBOX_INFO("Arbitronic 3D Engine Initialized");

   SandboxApp* myApp = new SandboxApp();
   myApp->runApp();

   ARB_SANDBOX_TRACE("Arbitronic 3D Engine Closed");

   return 0;
}
#endif // ARB_DEBUG

#ifdef SANDBOX_RELEASE
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    ARB_INFO("Arbitronic 3D Engine Initialized");

    return 0;
}
#endif // !


