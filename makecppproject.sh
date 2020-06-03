#!/bin/bash

PROJNAME=$1
echo $PROJNAME 
mkdir $PROJNAME
cp ~/dev/mte140/main.cpp ./$PROJNAME
code $PROJNAME


