#include "CommonFunction.h"
#include <windows.h>
std::wstring Utf8ToUtf16(const std::string& utf8Str) {
	if (utf8Str.empty()) {
		return std::wstring();
	}
	// Calculate the size of the UTF-16 string
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), (int)utf8Str.size(), NULL, 0);
	if (size_needed <= 0) {
		return std::wstring();
	}
	// Allocate a buffer for the UTF-16 string
	std::wstring utf16Str(size_needed, 0);
	// Convert UTF-8 to UTF-16
	MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), (int)utf8Str.size(), &utf16Str[0], size_needed);
	return utf16Str;
}