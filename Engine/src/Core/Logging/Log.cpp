#include "ARBpch.h"
#include "Log.h"

namespace ARB{
	Log::Log(std::string name){
		Logger logger1;
		logger1.logger = new spdlog::logger(name);
		logger1.sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();
		logger1.logger->set_level(spdlog::level::trace);
		logger1.logger->sinks().push_back(logger1.sink);
		logger1.logger->set_pattern("[%n]%^[%l]  %v%$ [%r]");

		Logger logger2;
		logger2.logger = new spdlog::logger(name);
		logger2.sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();
		logger2.logger->set_level(spdlog::level::trace);
		logger2.logger->sinks().push_back(logger2.sink);
		logger2.logger->set_pattern("[%n]%^[%l]::%s:%#  %v%$ [%r]");

		Logger logger3;
		logger3.logger = new spdlog::logger(name);
		logger3.sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();
		logger3.logger->set_level(spdlog::level::trace);
		logger3.logger->sinks().push_back(logger3.sink);
		logger3.logger->set_pattern("[%n]%^[%l]::%s:%#:%!  %v%$ [%r]");

		m_loggers.push_back(logger1);
		m_loggers.push_back(logger2);
		m_loggers.push_back(logger3);
	}
}
