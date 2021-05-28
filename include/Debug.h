#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>

#define BOREAL_DEBUG_DISABLE	0x00 // No Debug
#define BOREAL_DEBUG_LOG		0x01 // Bit 0
#define BOREAL_DEBUG_WARNING	0x02 // Bit 1
#define BOREAL_DEBUG_ERROR		0x04 // Bit 2

namespace Boreal {
	/**
	* @brief Allows user to log messages, as well as warnings and errors. Allows filtering for specific message types (log, warning, and error).
	* 
	* @section Description
	* 
	* The debug class is a static class that contains functions for logging messages to be used by the application.
	* It also tracks all logs, warnings, and errors in buffers that can be printed out.
	* It also tracks the number of logs, warnings, and errors.
	* Finally, it allows the user to filter which logs they want to see for a given run.
	* 
	*/
	class Debug {
	private:
		static HANDLE hConsole;								// Handle to stdout
		static std::vector<std::string> m_LogBuffer;		// Vector of log outputs
		static std::vector<std::string> m_WarningBuffer;	// Vector of warning outputs
		static std::vector<std::string> m_ErrorBuffer;		// Vector of error outputs
		static unsigned int m_LogFilter;					// Filter for logging
		static void Print(std::string message, WORD colour = (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE));// Private print function
	public:
		// Logging functions

		/**
		* @brief Logs a regular message (white text). Filters the message and adds it to buffer.
		* 
		* @param message Message to be logged to the console.
		*/
		static void Log(std::string message);

		/**
		* @brief Logs a warning message (yellow text). Filters the message and adds it to buffer.
		* 
		* @param message Message to be logged to the console.
		*/
		static void LogWarning(std::string message);

		/**
		* @brief Logs an error message (red text). Filters the message and adds it to buffer.
		* 
		* @param message Message to be logged to the console.
		*/
		static void LogError(std::string message);
		
		// Getters for counts

		/**
		* @brief Get log count returns the number of logs in the log buffer.
		* 
		* @return Returns the number of logs in the log buffer as a size_t.
		*/
		static size_t GetLogCount() { return m_LogBuffer.size(); }

		/**
		* @brief Get warning count returns the number of warnings in the warning buffer.
		*
		* @return Returns the number of warning logs in the warning buffer as a size_t.
		*/
		static size_t GetWarningCount() { return m_WarningBuffer.size(); }

		/**
		* @brief Get error count returns the number of errors in the error buffer.
		*
		* @return Returns the number of error logs in the error buffer as a size_t.
		*/
		static size_t GetErrorCount() { return m_ErrorBuffer.size(); }

		// Useful Print Functions

		/**
		* @brief Prints all logs in the log buffer.
		*/
		static void PrintLogs();

		/**
		* @brief Prints all warnings in the warning buffer.
		*/
		static void PrintWarnings();

		/**
		* @brief Prints all errors in the error buffer.
		*/
		static void PrintErrors();

		/**
		* @brief Prints number of logs in the log buffer
		*/
		static void PrintLogCount();

		/**
		* @brief Prints number of warnings in the warning buffer
		*/
		static void PrintWarningCount();

		/**
		* @brief Prints number of errors in the error buffer
		*/
		static void PrintErrorCount();

		// Set log filter

		/**
		* @brief Set log filter allows the user to filter the messages that will be printed on the console.
		* 
		* @param logFilter Filter used to determine which messages will be logged. Set to BOREAL_DEBUG_DISABLE to disable all output.
		* Use BOREAL_DEBUG_LOG to filter in regular logs, BOREAL_DEBUG_WARNING to filter in warning logs, and BOREAL_DEBUG_ERROR to filter in error logs.
		* The filters can be combined using the | operator, for example to filter in both warning and error logs use BOREAL_DEBUG_WARNING | BOREAL_DEBUG_ERROR
		*/
		static void SetLogFilter(unsigned int logFilter) { m_LogFilter = logFilter; }
	};
}