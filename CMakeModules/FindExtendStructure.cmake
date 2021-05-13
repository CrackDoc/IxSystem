SET(ExtendStructure_DIR ${CMAKE_INSTALL_PREFIX}/ExtendStructure CACHE STRING "settting ExtendStructure_DIR path" FORCE)

#SET(ExtendStructure_DIR "" CACHE PATH "Location of ExtendStructure")

FIND_PATH(ExtendStructure_INCLUDE_DIR ExtendStructureExport.h
	${ExtendStructure_DIR}/include
    "${ExtendStructure_DIR}/Public Headers"
    "$ENV{ExtendStructure_PATH}/Public Headers"
    $ENV{ExtendStructure_PATH}
    $ENV{ExtendStructure_DIR}/include
    $ENV{ExtendStructure_DIR}
    /usr/local/include
	/usr/local/ExtendStructure/include
    /usr/include
	/usr/ExtendStructure/include
	/opt/include
    /opt/local/ExtendStructure/include
    /opt/ExtendStructure/include
    "C:/ExtendStructure/include"
	"C:/Program Files/ExtendStructure/include"
)

FIND_LIBRARY(ExtendStructure_LIBRARY
NAMES "ExtendStructure"
PATHS
	${ExtendStructure_DIR}/lib
    $ENV{ExtendStructure_PATH}
    $ENV{ExtendStructure_DIR}/lib
    $ENV{ExtendStructure_DIR}
    /usr/local/lib
	/usr/local/ExtendStructure/lib
    /usr/lib
	/usr/ExtendStructure/lib
	/opt/lib
    /opt/local/ExtendStructure/lib
    /opt/ExtendStructure/lib
    "C:/ExtendStructure/lib"
	"C:/Program Files/ExtendStructure/lib"
)
SET(ExtendStructure_FOUND FALSE)
IF (ExtendStructure_INCLUDE_DIR AND ExtendStructure_LIBRARY)
   SET(ExtendStructure_FOUND TRUE)
ENDIF (ExtendStructure_INCLUDE_DIR AND ExtendStructure_LIBRARY)
