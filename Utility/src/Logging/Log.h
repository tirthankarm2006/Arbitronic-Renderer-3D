#pragma once

#ifndef _ARB_LOG_H_
#define _ARB_LOG_H_
#include "ARBpch.h"

namespace ARB {

#ifdef ARB_DEBUG
#define ARB_LOGGER_INFO(log_instance, info_msg, ...) if(log_instance != nullptr) SPDLOG_LOGGER_INFO(log_instance, info_msg, __VA_ARGS__)
#define ARB_LOGGER_TRACE(log_instance, trace_msg, ...) if(log_instance != nullptr) SPDLOG_LOGGER_TRACE(log_instance, trace_msg, __VA_ARGS__)
#define ARB_LOGGER_WARN(log_instance, warn_msg, ...) if(log_instance != nullptr) SPDLOG_LOGGER_WARN(log_instance, warn_msg, __VA_ARGS__)
#define ARB_LOGGER_ERROR(log_instance, error_msg, ...) if(log_instance != nullptr) SPDLOG_LOGGER_ERROR(log_instance, error_msg, __VA_ARGS__)
#define ARB_LOGGER_CRITICAL(log_instance, critical_msg, ...) if(log_instance != nullptr) SPDLOG_LOGGER_CRITICAL(log_instance, critical_msg, __VA_ARGS__)

#define ARB_INFO(msg, ...) ARB_LOGGER_INFO(ARB::g_logger->m_loggers[0].logger, msg,  __VA_ARGS__)
#define ARB_TRACE(msg, ...) ARB_LOGGER_TRACE(ARB::g_logger->m_loggers[1].logger, msg,  __VA_ARGS__)
#define ARB_WARN(msg, ...) ARB_LOGGER_WARN(ARB::g_logger->m_loggers[2].logger, msg,  __VA_ARGS__)
#define ARB_ERROR(msg, ...) ARB_LOGGER_ERROR(ARB::g_logger->m_loggers[2].logger, msg,  __VA_ARGS__)
#define ARB_CRITICAL(msg, ...) ARB_LOGGER_CRITICAL(ARB::g_logger->m_loggers[2].logger, msg,  __VA_ARGS__)

#elif ARB_RELEASE
#define ARB_LOGGER_INFO(log_instance, ...)
#define ARB_LOGGER_TRACE(log_instance, ...)
#define ARB_LOGGER_WARN(log_instance, ...)
#define ARB_LOGGER_ERROR(log_instance, ...)
#define ARB_LOGGER_CRITICAL(log_instance, ...)

#define ARB_INFO(log_instance, ...)
#define ARB_TRACE(log_instance, ...)
#define ARB_WARN(log_instance, ...)
#define ARB_ERROR(log_instance, ...)
#define ARB_CRITICAL(log_instance, ...)

#endif

	class Log
	{
	public:
		typedef struct {
			spdlog::logger* logger;
			std::shared_ptr<spdlog::sinks::wincolor_stdout_sink_mt> sink;
		}Logger;

		Log(std::string name);
		
		//Different loggers will have different formatting
		std::vector<Logger> m_loggers;
	};

	static Log* g_logger = new ARB::Log("Engine");
}

#endif // !_ARB_LOG_H_
