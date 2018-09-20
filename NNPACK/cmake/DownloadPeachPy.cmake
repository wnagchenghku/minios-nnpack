CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12 FATAL_ERROR)

PROJECT(peachpy-download NONE)

FIND_PACKAGE(PythonInterp REQUIRED)

INCLUDE(ExternalProject)
ExternalProject_Add(peachpy
	GIT_REPOSITORY https://github.com/Maratyszcza/PeachPy.git
	GIT_TAG master
	SOURCE_DIR "${CONFU_DEPENDENCIES_SOURCE_DIR}/peachpy"
	BINARY_DIR "${CONFU_DEPENDENCIES_BINARY_DIR}/peachpy"
	PATCH_COMMAND "PYTHONPATH=${PYTHON_SIX_SOURCE_DIR}:${PYTHON_ENUM_SOURCE_DIR}:${PYTHON_OPCODES_SOURCE_DIR}" ${PYTHON_EXECUTABLE} setup.py generate
	CONFIGURE_COMMAND ""
	BUILD_COMMAND ""
	INSTALL_COMMAND ""
	TEST_COMMAND ""
)
