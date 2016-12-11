/*
 * Copyright (C) 2016 Hedede <haddayn@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 */
#ifndef Daedalus_FileSystem_SourceBuffer
#define Daedalus_FileSystem_SourceBuffer
#include <istream>
namespace Daedalus {
/* TODO: replace with std::string_view
 */
struct SourceBuffer {
	SourceBuffer(std::string const& str)
		: buffer{str.data()}, length{str.size()}
	{ }

	SourceBuffer(char const* begin, char const* end)
		: buffer{begin}, length{ size_t(end - begin) }
	{ }


	char const* begin()
	{
		return buffer;
	}

	char const* end()
	{
		return buffer + length;
	}

	size_t size()
	{
		return length;
	}

private:
	char const* buffer;
	size_t length;
};
} // namespace daedalus
#endif//Daedalus_FileSystem_SourceBuffer
