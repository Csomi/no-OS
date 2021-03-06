#!/bin/bash

set -e

sudo apt-get update

TOP_DIR="$(pwd)"
DEPS_DIR="${TOP_DIR}/deps"

. ./ci/travis/lib.sh

build_astyle() {
    . ./ci/travis/astyle.sh
}

build_cppcheck() {
    . ./ci/travis/cppcheck.sh
}

build_drivers() {
    sudo apt-get install gcc-arm-none-eabi libnewlib-arm-none-eabi
    make -C ./drivers -f Makefile
}

build_doxygen() {
    sudo apt-get install -y graphviz
    # Install a recent version of doxygen
	DOXYGEN_URL="https://sourceforge.net/projects/doxygen/files/rel-1.8.17/doxygen-1.8.17.src.tar.gz/"
	mkdir -p "${DEPS_DIR}"
	cd ${DEPS_DIR}
	[ -d "doxygen" ] || {
		mkdir doxygen && wget --quiet -O - ${DOXYGEN_URL} | tar --strip-components=1 -xz -C doxygen
	}

    # Install Doxygen
    cd doxygen
    patch ./src/docparser.cpp < ${TOP_DIR}/ci/travis/patch_doxy.patch
    mkdir -p build && cd build
    cmake ..
    make -j${NUM_JOBS}
    sudo make install
    cd ../..

    #Generate *.dox files for drivers and projects
    . ${TOP_DIR}/ci/travis/gen_dox.sh

    # Build Documentation
    cd ${TOP_DIR}/doc
    mkdir -p build && cd build
    cmake ..
    cd ../..

    . ./ci/travis/doxygen.sh
}

build_${BUILD_TYPE}
