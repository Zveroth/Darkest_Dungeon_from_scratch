#pragma once

#include "assert.h"
#include "stdio.h"

//FatalError calls will:
//in DEBUG - print the message in the console
//in RELEASE - save the error message in the FatalErrorInfo.txt file
#ifndef _DEBUG
#include "fstream"

#define FatalError_Size(Message, ByteSize)\
{\
	std::ofstream DebugFile;\
	DebugFile.open("FatalErrorInfo.txt");\
	DebugFile << Message;\
	DebugFile << " ";\
	DebugFile << ByteSize;\
	DebugFile << "B";\
	DebugFile.close();\
	assert(false);\
}

#define FatalError(Message)\
{\
	std::ofstream DebugFile;\
	DebugFile.open("FatalErrorInfo.txt");\
	DebugFile << Message;\
	DebugFile.close();\
	assert(false);\
}

#define Error(Message)\
{\
	std::ofstream DebugFile;\
	DebugFile.open("ErrorLog.txt", std::ios_base::app);\
	DebugFile << Message;\
	DebugFile.close();\
}

#else

#define FatalError_Size(Message, ByteSize)\
{\
	printf(Message, ByteSize);\
	assert(false);\
}

#define FatalError(Message)\
{\
	printf(Message);\
	assert(false);\
}

#define Error(Message)\
{\
	printf(Message);\
}

#endif // !_DEBUG