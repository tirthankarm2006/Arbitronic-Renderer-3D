#include "ARBpch.h"
#include "UIWindowTab.h"

namespace ARB {
	namespace Editor {
		UIWindowTab::UIWindowTab(const char* name, glm::vec2 pos, glm::vec2 size) : name(name), size(size), position(pos) {
		}

		void UIWindowTab::createFrame() {
			ImGui::Begin(name.c_str(), nullptr);

			if (!setWindowParams) {
				const ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImVec2 work_pos = viewport->WorkPos; // top-left of work area
				ImVec2 work_size = viewport->WorkSize; // size of work area

				ImGui::SetWindowPos(ImVec2(work_pos.x + position.x, work_pos.y + position.y), ImGuiCond_Always);
				ImGui::SetWindowSize(ImVec2(size.x, size.y));
				setWindowParams = true;
			}
		}

		void UIWindowTab::endFrame() {
			ImGui::End();
		}
	}
}
