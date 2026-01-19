#pragma once

#ifndef _ARB_UIWINDOWTAB_H_
#define _ARB_UIWINDOWTAB_H_

namespace ARB {
	namespace Editor {
		class UIWindowTab
		{
		public:
			UIWindowTab(const char* name, glm::vec2 pos, glm::vec2 size);
			void createFrame();
			void endFrame();
		private:
			std::string name;
			bool setWindowParams = false;
			glm::vec2 position;
			glm::vec2 size;
		};
	}
}

#endif // !_ARB_UIWINDOWTAB_H_

