#!/bin/bash

FILENAME='tableturf-battle'
FILETYPE='3dsx'
RUN_ON_CITRA=false # run on citra or original hardware
DSIP='YUORIP' # 192.168.XXX.XXX (without port) (needed if on original hardware)
CITRA_PATH='path/to/citra.app' # (needed if on citra)

make

if [ $RUN_ON_CITRA == false ]; then
    3dslink $FILENAME-3ds.$FILETYPE -a $DSIP
else
    "$CITRA_PATH" "./$FILENAME-3ds.$FILETYPE"
fi