#!/bin/bash

3DSIP='192.168.15.27:174'
FILENAME='tableturf-battle'

make

sleep 1

3dslink $FILENAME-3ds.3dsx $3DSIP