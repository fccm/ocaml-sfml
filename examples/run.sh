#!/usr/bin/env bash

LIBDIR="+sfml"

if [ -d ../src ]
then
	pushd ../src
	make -j $1
	popd
	LIBDIR="../src/"
fi

echo
echo "========================"
echo "running"
echo
echo ocaml bigarray.cma -I $LIBDIR   $1 $2
echo
     ocaml bigarray.cma -I $LIBDIR   $1 $2
