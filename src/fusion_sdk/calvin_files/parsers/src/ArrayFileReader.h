////////////////////////////////////////////////////////////////
//
// Copyright (C) 2005 Affymetrix, Inc.
//
// This library is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License 
// (version 2.1) as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
// for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this library; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
//
////////////////////////////////////////////////////////////////


#ifndef _ArrayFileReader_HEADER_
#define _ArrayFileReader_HEADER_

/*! \file ArrayFileReader.h This file provides interfaces to read an array file.
 */

#include "calvin_files/array/src/ArrayData.h"
#include "calvin_files/parameter/src/Parameter.h"
#include "calvin_files/portability/src/AffymetrixBaseTypes.h"
#include "calvin_files/utils/src/AffymetrixGuid.h"
//
#include <cstring>
#include <fstream>
#include <string>
//

namespace affymetrix_calvin_io
{

/*! This class provides interfaces to read an array file. */
class ArrayFileReader
{
public:
	/*! Constructor */
	ArrayFileReader();

	/*! Destructor */
	~ArrayFileReader();

protected:
	/*! The files version number. */
	std::wstring fileVersionNumber;

public:
	/*! Reads the entire contents of the file.
	 *
	 * @param fileName The name of the array file to read.
	 * @param arrayData The array data to read from the file.
 	 * @param headerOnly Flag to indicate that the header line should only be read.
	 */
	bool Read(const std::string &fileName, affymetrix_calvin_array::ArrayData &arrayData, bool headerOnly=false);

	/*! Determines if a file is of the specified type.
	 *
	 * @param fileName The name of the file to check.
	 * @param dataTypeId An identifier to the type of data.
	 * @return True if the file matches the type desired.
	 */
	static bool IsFileType(const std::string &fileName, const affymetrix_calvin_utilities::AffymetrixGuidType &dataTypeId);

	/*! The identifier of the type of data stored in the file.
	 *
 	 * @param fileName The name of the file to check.
	 * @return The identifier of the type of data.
	 */
	static affymetrix_calvin_utilities::AffymetrixGuidType DataTypeIdentifier(const std::string &fileName);
};

};

#endif // _ArrayFileReader_HEADER_
