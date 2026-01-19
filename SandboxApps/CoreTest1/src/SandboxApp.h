#pragma once
#include "Arbitronic.h"

class SandboxApp : public ARB::Sandbox
{
public:
	SandboxApp();
	void runApp() override;
};

ARB::Sandbox* GetSandboxApp() {
	return new SandboxApp();
}