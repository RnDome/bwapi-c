# Find BWAPI (C++ library https://github.com/bwapi/bwapi/releases)
#  Input variable: BWAPI_PATH

find_path(BWAPI_INCLUDE_DIRS NAMES BWAPI.h PATHS ${BWAPI_PATH}/include)

set(old_prefixes ${CMAKE_FIND_LIBRARY_PREFIXES})
set(old_suffixes ${CMAKE_FIND_LIBRARY_SUFFIXES})

set(CMAKE_FIND_LIBRARY_PREFIXES "")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".dll")

find_library(BWAPI_LIBRARIES NAMES BWAPI PATHS ${BWAPI_PATH}/lib)

set(CMAKE_FIND_LIBRARY_PREFIXES ${old_prefixes})
set(CMAKE_FIND_LIBRARY_SUFFIXES ${old_suffixes})

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BWAPI DEFAULT_MSG BWAPI_LIBRARIES BWAPI_INCLUDE_DIRS)
