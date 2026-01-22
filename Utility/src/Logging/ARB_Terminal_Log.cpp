#include "ARBpch.h"
#include "ARB_Terminal_Log.h"
#include "fmt/include/fmt/chrono.h"

namespace ARB {
	namespace Editor {
		void ARB_Terminal_Log::t_trace(std::string msg) {
			ARBLogDetail log;
			log.msg_level = arb_log_level::trace;

			SYSTEMTIME st;
			GetLocalTime(&st);

			log.log_msg = fmt::format("[{0}][trace] {1} [{2}:{3}:{4}]", logger_name, msg, st.wHour, st.wMinute, st.wSecond);
			terminalLogs.push_back(log);
		}
		void ARB_Terminal_Log::t_info(std::string msg) {
			ARBLogDetail log;
			log.msg_level = arb_log_level::info;

			SYSTEMTIME st;
			GetLocalTime(&st);

			log.log_msg = fmt::format("[{0}][info] {1} [{2}:{3}:{4}]", logger_name, msg, st.wHour, st.wMinute, st.wSecond);
			terminalLogs.push_back(log);
		}
		void ARB_Terminal_Log::t_warn(std::string msg) {
			ARBLogDetail log;
			log.msg_level = arb_log_level::warn;

			SYSTEMTIME st;
			GetLocalTime(&st);

			log.log_msg = fmt::format("[{0}][warn] {1} [{2}:{3}:{4}]", logger_name, msg, st.wHour, st.wMinute, st.wSecond);
			terminalLogs.push_back(log);
		}
		void ARB_Terminal_Log::t_error(std::string msg) {
			ARBLogDetail log;
			log.msg_level = arb_log_level::error;

			SYSTEMTIME st;
			GetLocalTime(&st);

			log.log_msg = fmt::format("[{0}][error] {1} [{2}:{3}:{4}]", logger_name, msg, st.wHour, st.wMinute, st.wSecond);
			terminalLogs.push_back(log);
		}
	}
}