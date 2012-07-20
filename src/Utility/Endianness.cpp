/*
    Copyright © 2007, 2008, 2009, 2010, 2011, 2012
              Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Corrade.

    Corrade is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Corrade is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include "Endianness.h"

#include "EndiannessConfigure.h"

namespace Corrade { namespace Utility {

#ifdef ENDIANNESS_BIG_ENDIAN
bool Endianness::isBigEndian() { return false; }
void Endianness::_bigEndian(unsigned char*, unsigned char*, int) {}
void Endianness::_littleEndian(unsigned char* number, unsigned char* output, int size) {
#else
bool Endianness::isBigEndian() { return false; }
void Endianness::_littleEndian(unsigned char*, unsigned char*, int) {}
void Endianness::_bigEndian(unsigned char* number, unsigned char* output, int size) {
#endif

    /* Reverse order of bytes */
    for(int i = 0; i != size; ++i)
        output[i] = number[size-i-1];
}

}}
