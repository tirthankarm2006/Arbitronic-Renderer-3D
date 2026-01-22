#pragma once

#ifndef _ARB_TERMINAL_LOG_H_
#define _ARB_TERMINAL_LOG_H_

namespace ARB {
	namespace Editor {

#define ARB_TERMINAL_TRACE(msg, ...) ARB::Editor::terminalLogger->t_trace(fmt::format(msg, __VA_ARGS__))
#define ARB_TERMINAL_INFO(msg, ...) ARB::Editor::terminalLogger->t_info(fmt::format(msg, __VA_ARGS__))
#define ARB_TERMINAL_WARN(msg, ...) ARB::Editor::terminalLogger->t_warn(fmt::format(msg, __VA_ARGS__))
#define ARB_TERMINAL_ERROR(msg, ...) ARB::Editor::terminalLogger->t_error(fmt::format(msg, __VA_ARGS__))

#define ARB_TERMINAL_LOG_LEVEL_TRACE 0
#define ARB_TERMINAL_LOG_LEVEL_INFO 1
#define ARB_TERMINAL_LOG_LEVEL_WARN 2
#define ARB_TERMINAL_LOG_LEVEL_ERROR 3

		class ARB_Terminal_Log {
		public:
			enum class arb_log_level : uint8_t {
				trace = ARB_TERMINAL_LOG_LEVEL_TRACE,
				info = ARB_TERMINAL_LOG_LEVEL_INFO,
				warn = ARB_TERMINAL_LOG_LEVEL_WARN,
				error = ARB_TERMINAL_LOG_LEVEL_ERROR
			};
		private:
			typedef struct {
				std::string log_msg;
				arb_log_level msg_level;
			}ARBLogDetail;

			std::string logger_name;

			std::vector<ARBLogDetail> terminalLogs;
		public:
			ARB_Terminal_Log(std::string name) : logger_name(name) { }
			void Clear_All_Logs() { terminalLogs.clear(); }
			inline std::string& Get_Terminal_Log_Msg(int i) { return terminalLogs[i].log_msg; }
			inline arb_log_level& Get_Terminal_Log_Level(int i) { return terminalLogs[i].msg_level; }
			inline int Get_Num_Terminal_Log_Msgs() { return terminalLogs.size(); }

			void t_trace(std::string msg);
			void t_info(std::string msg);
			void t_warn(std::string msg);
			void t_error(std::string msg);
		};
		static Editor::ARB_Terminal_Log* terminalLogger = new Editor::ARB_Terminal_Log("Engine");
	}

}

#endif // !_ARB_TERMINAL_LOG_H_