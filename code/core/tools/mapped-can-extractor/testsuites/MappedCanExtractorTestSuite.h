/**
 * odrecintegrity - Tool for checking the integrity of recorded data
 * Copyright (C) 2014 - 2015 Christian Berger
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef MAPPEDCANEXTRACTORTESTSUITE_H_
#define MAPPEDCANEXTRACTORTESTSUITE_H_

#include "cxxtest/TestSuite.h"

// Include local header files.
#include "../include/MappedCanExtractor.h"

using namespace std;

/**
 * The actual testsuite starts here.
 */
class RecIntegrityTest : public CxxTest::TestSuite {
    public:
        void testExample() {
            TS_ASSERT(true);
        }


};

#endif /*MAPPEDCANEXTRACTORTESTSUITE_H_*/
