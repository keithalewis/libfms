#!/bin/bash
# Generate project template

NAME=$1

mkdir -p $NAME
cd $NAME

cat > CMakeLists.txt <<EoF
project($NAME)
add_library(\${PROJECT_NAME} $NAME.cpp)
add_subdirectory(test)
EoF

cat > $NAME.cpp <<EoF
#include "$NAME.h"
EoF

cat > $NAME.h <<EoF
// $NAME.h - DESCRIPTION
#pragma once
EoF

for i in *.h
do
	if [ $i != $NAME.h ]; then
		echo "#include \"$i\"" >> $NAME.h
	fi
done

mkdir -p test
cd test

