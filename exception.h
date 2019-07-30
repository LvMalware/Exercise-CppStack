/*
 * exception.h -- header file for exceptions
 *
 * Copyright (c) 2019 Lucas V. Araujo <lucas.vieira.ar@protonmail.com>
 *
 * This program is a free software, distributed under the GNU GPLv3.0+
 *
 */


#include <cstdio>
#include <string>

#ifndef _EXCEPTION_H
#define _EXCEPTION_H

using std::string;

class Exception
{
private:
	string   file;
	unsigned line;
	int      code;
	string   message;
public:
	Exception(const char *eFile, const char *eMsg, unsigned eLine, int eCode)
	{
		file    = eFile;
		line    = eLine;
		code    = eCode;
		message = eMsg;
	}

	void
	show()
	{
		printf("%s:%u (%d) %s\n", file.c_str(), line, code, message.c_str());
	}
};

#endif
