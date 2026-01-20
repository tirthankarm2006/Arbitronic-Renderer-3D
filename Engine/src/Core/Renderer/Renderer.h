#pragma once

#ifndef _ARB_RENDERER_H_
#define _ARB_RENDERER_H_
#include "Arbitronic.h"

namespace ARB {
	class Renderer
	{
	public:
		enum class RendererType {
			FORWARD,
			DEFFERED
		};
	public:
		RendererType renderType;
	};
}

#endif // !_ARB_RENDERER_H_