#include "Arbitronic.h"
#include "Sandbox/SandboxApp.h"
#include "Logging/Sandbox_Log.h"
#include "Maths/MathsWrapper.h"

#ifdef SANDBOX_DEBUG
int main(int argc, char** argv) {
   ARB_SANDBOX_INFO("Arbitronic 3D Engine Initialized");

   ARB::Vector3f_32t v1 = ARB::Vector3f_32t(1.0, 2.0, 3.0);
   ARB::Vector3f_32t v2 = ARB::Vector3f_32t(2.0, 2.0, 4.0);
   ARB::Vector3f_32t v3 = v1 + v2;
   v3.AddScaledVector(v1, 2.4);
   ARB_SANDBOX_TRACE("dot product is {0}", v1.DotProduct(v3));

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


