#!/bin/bash

CP="cp"
RM="rm"
RMFLAGS="-f"
MKDIR="mkdir -p"
DIREXISTS="test -d"

GIT="git"
PULL="pull"
REMOTE="origin"
BRANCH="master"
MAKE="make"

FILES="*.h"


INSTALL_INCLUDE="$HOME/.amicayse/include"
INSTALL_LIB="$HOME/.amicayse/lib"
INSTALL_BIN="$HOME/.amicayse/bin"

install(){
	$DIREXISTS $INSTALL_INCLUDE || $MKDIR $INSTALL_INCLUDE/amicayse
	$CP $FILES $INSTALL_INCLUDE/amicayse
	echo $CPATH | grep -q $INSTALL_INCLUDE
	if [[ $? != 0 ]]; then
		echo "export CPATH=$INSTALL_INCLUDE:$CPATH" >> $HOME/.bashrc
	fi

	$DIREXISTS $INSTALL_LIB || $MKDIR $INSTALL_LIB
	echo $LD_LIBRARY_PATH | grep -q $INSTALL_LIB
	if [[ $? != 0 ]]; then
		echo "export LD_LIBRARY_PATH=$INSTALL_LIB$LD_LIBRARY_PATH" >> $HOME/.bashrc
	fi

	$DIREXISTS $INSTALL_LIB || $MKDIR $INSTALL_LIB
	echo $LIBRARY_PATH | grep -q $INSTALL_LIB
	if [[ $? != 0 ]]; then
		echo "export LIBRARY_PATH=$INSTALL_LIB$LIBRARY_PATH" >> $HOME/.bashrc
	fi

	$DIREXISTS $INSTALL_BIN || $MKDIR $INSTALL_BIN
	echo $PATH | grep -q $INSTALL_BIN
	if [[ $? != 0 ]]; then
		echo "export PATH=$INSTALL_BIN:$PATH" >> $HOME/.bashrc
	fi
}


update(){
	$GIT $PULL $REMOTE $BRANCH
	install
}

if [[ $# == 0 ]]; then
	install
elif [[ $# == 1 ]]; then
	if [[ $1 == "update" ]]; then
		update
	elif [[ $1 != "install" ]]; then
		echo "invalid option"
	else
		install
	fi
else
	echo "Too many arguments"
fi