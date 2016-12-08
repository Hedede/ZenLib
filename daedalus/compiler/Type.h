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
#ifndef Daedalus_Type
#define Daedalus_Type
namespace Daedalus {
class Class;
/*!
 * Reference to a type, with added type modifiers.
 */
struct Type {
	Class* baseType;
	bool isConst;
	unsigned count;
};
} // namespace daedalus
#endif//Daedalus_Type
