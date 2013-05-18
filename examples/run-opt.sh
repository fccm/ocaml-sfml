#!/usr/bin/env bash

LIBDIR="+sfml"
_LIBS="$1"
LIBS=""
for L in $_LIBS
do
	THIS=`echo $L | sed -e 's/cma$/cmxa/g'`
	LIBS="$LIBS $THIS"
done
echo "LIBS -> $LIBS"

if [ -d ../src ]
then
	pushd ../src
	make -j $LIBS
	popd
	LIBDIR="../src/"
fi

echo
echo "========================"
echo "running"
echo

ocamlopt bigarray.cmxa -I $LIBDIR \
  $LIBS $2
