#include "Debug.h"

#include <string>

namespace Boreal {
	// Console handle
	HANDLE Debug::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Initialize buffers
	std::vector<std::string> Debug::m_LogBuffer = std::vector<std::string>();
	std::vector<std::string> Debug::m_WarningBuffer = std::vector<std::string>();
	std::vector<std::string> Debug::m_ErrorBuffer = std::vector<std::string>();

	// Initialize filter
	unsigned int Debug::m_LogFilter = BOREAL_DEBUG_LOG | BOREAL_DEBUG_WARNING | BOREAL_DEBUG_ERROR;

	// Private print function, doesn't log
	void Debug::Print(std::string message, WORD colour){
		SetConsoleTextAttribute(hConsole, colour);
		std::cout << message << std::endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	// Log Regular
	void Debug::Log(std::string message) {
		// Add to log buffer
		m_LogBuffer.push_back(message);

		// Print to console if enabled
		if ((m_LogFilter & BOREAL_DEBUG_LOG) == BOREAL_DEBUG_LOG) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			std::cout << message << std::endl;
		}
	}

	// Log Warning
	void Debug::LogWarning(std::string message) {
		// Add to warning buffer
		m_WarningBuffer.push_back(message);

		// Print to console if enabled
		if ((m_LogFilter & BOREAL_DEBUG_WARNING) == BOREAL_DEBUG_WARNING) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
			std::cout << message << std::endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}

	// Log Error
	void Debug::LogError(std::string message) {
		// Add to error buffer
		m_ErrorBuffer.push_back(message);

		// Print to console if enabled
		if ((m_LogFilter & BOREAL_DEBUG_ERROR) == BOREAL_DEBUG_ERROR) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << message << std::endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}

	void Debug::PrintLogs(){
		// Print all logs in log vector
		for(int i = 0; i < m_LogBuffer.size(); i++){
			Print(m_LogBuffer[i]);
		}
	}

	void Debug::PrintWarnings(){
		// Print all logs in log vector
		for (int i = 0; i < m_WarningBuffer.size(); i++) {
			Print(m_WarningBuffer[i], FOREGROUND_RED | FOREGROUND_GREEN);
		}
	}

	void Debug::PrintErrors(){
		// Print all logs in log vector
		for (int i = 0; i < m_ErrorBuffer.size(); i++) {
			Print(m_ErrorBuffer[i], FOREGROUND_RED);
		}
	}

	void Debug::PrintLogCount(){
		// Print log count
		std::string text = std::string("Regular logs: ") + std::to_string(m_LogBuffer.size());
		Print(text);
	}

	void Debug::PrintWarningCount() {
		// Print warning count
		std::string text = std::string("Warning logs: ") + std::to_string(m_WarningBuffer.size());
		Print(text, FOREGROUND_RED | FOREGROUND_GREEN);
	}

	void Debug::PrintErrorCount() {
		// Print error count
		std::string text = std::string("Error logs: ") + std::to_string(m_ErrorBuffer.size());
		Print(text, FOREGROUND_RED);
	}
}