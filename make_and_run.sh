#!/bin/bash

DSIP='YUORIP'
FILENAME='tableturf-battle'

make

3dslink $FILENAME-3ds.3dsx -a $DSIP