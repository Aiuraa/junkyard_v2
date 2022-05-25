#!/bin/sh

DIR="$( cd "$( dirname "$0" )" && pwd )"
WINEPATH=$HOME/.local/share/lutris/runners/wine/lutris-fshack-7.2-x86_64/bin

WINEPREFIX=$DIR WINEARCH=win32 $WINEPATH/wine $1
