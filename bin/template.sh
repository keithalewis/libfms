#!/bin/bash
# Generate project template
USAGE="$0 PROJECTNAME"
echo "n = $#"
if [ $# -lt 1 ];then
	echo "USAGE: $USAGE" 1>&2
	exit -1
fi

NAME=$1

mkdir -p ${NAME}
cd ${NAME}

cat > CMakeLists.txt <<EoF
project(${NAME})
add_library(\${PROJECT_NAME} ${NAME}.cpp)
add_subdirectory(test)
EoF

cat > ${NAME}.cpp <<EoF
#include "${NAME}.h"
EoF

cat > ${NAME}.h <<EoF
// $NAME.h - DESCRIPTION
#pragma once
EoF

for i in *.h
do
	if [ "$i" != "${NAME}.h" ]; then
		echo "#include \"$i\"" >> ${NAME}.h
	fi
done

mkdir -p test
cd test
cat > CMakeLists.txt <<EoF
project(test_${NAME})
add_executable(test_${NAME} test_${NAME}.cpp)
include_directories (\${${NAME}_SOURCE_DIR}})
include_directories($ENV{ROOTDIR}/include)
target_link_libraries(test_${NAME}
        ${NAME}
)
EoF

cat > test_${NAME}.cpp <<EoF
#include "ensure.h"
#include "${NAME}.h"
// loop over existing headers

int main()
{
	// insert tests
	return 0;
}
EoF
