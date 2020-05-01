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


install(){
	$DIREXISTS $INSTALL_INCLUDE || $MKDIR $INSTALL_INCLUDE/amicayse
	$CP $FILES $INSTALL_INCLUDE/amicayse
	echo $CPATH | grep -q $INSTALL_INCLUDE
	if [[ $? != 0 ]]; then
		echo "export CPATH=$INSTALL_INCLUDE:$CPATH" >> $HOME/.bashrc
	fi
}
	#ifeq (RES, 0)
	#	export CPATH=$(INSTALL_INCLUDE):$(CPATH)
	#endif


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