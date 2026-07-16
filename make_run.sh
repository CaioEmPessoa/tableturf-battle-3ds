#!/bin/bash

FILENAME='tableturf-battle'
FILETYPE='3dsx'
DS_IP='192.168.XXX.XXX' # 192.168.XXX.XXX (without port) (needed if on original hardware)
CITRA_PATH='/home/user/Citra.AppImage' # (needed if on citra)

# -c: clear shell when running the script
# -r: run app after making it
# -n: run the app in native 3ds
# -h: shows help message

while getopts ":c:r:n:h:" opt; do
  case $opt in
    c) clear_arg="$OPTARG"
    ;;
    r) run_arg="$OPTARG"
    ;;
    n) native_arg="$OPTARG"
    ;;
    \?) echo "Invalid option -$OPTARG" >&2
    exit 1
    ;;
  esac
done

if [ "$1" == "help" ]; then
    printf "\nMakeRun Script: \n"
    printf " -c bool (false): clear shell when running the script \n"
    printf " -r bool (true ): run app after making it \n"
    printf " -n bool (false): run the app in native 3ds insted of citra \n"
    printf " help: shows this help message \n"
    printf " \n------------------------------------------------------------- \n\n"
    printf " Remember to config this script with the filename, type, \n"
    printf " your 3ds ip and/or the citra path in your system in \n"
    printf " the variables at the top. \n    \n"
    exit
fi


if [ "$clear_arg" == "true" ]; then
    clear
fi

make clean
make

if [ "$run_arg" != "false" ]; then
    if [ ! -f "./$FILENAME-3ds.$FILETYPE" ]; then
        printf "MakeRun> compilation error! Will not attempt to run program. \n"
        exit
    fi

    if [ "$native_arg" == "true" ]; then
        printf "MakeRun> Will attempt to run on 3dslink... \n"
        3dslink $FILENAME-3ds.$FILETYPE -a $DS_IP
    else
        printf "MakeRun> Will attempt to run on citra... \n"
        "$CITRA_PATH" "./$FILENAME-3ds.$FILETYPE"
    fi
fi