#!/bin/sh

export ANA_BASE_DIR=$PWD
export ANA_DATA_DIR=${ANA_BASE_DIR}/data
export ANA_SRC_DIR=${ANA_BASE_DIR}/src
export ANA_BIN_DIR=${ANA_BASE_DIR}/bin
export ANA_RUN_DIR=${ANA_BASE_DIR}/run
export ANA_TXT_DIR=${ANA_BASE_DIR}/txt
export ANA_LIST_DIR=${ANA_BASE_DIR}/list
export ANA_DB_DIR=${ANA_BASE_DIR}/db
export ANA_HIST_DIR=${ANA_BASE_DIR}/hist
export ANA_PLOT_DIR=${ANA_BASE_DIR}/plot
export ANA_PS_DIR=${ANA_BASE_DIR}/ps
export ANA_SPLINE_DIR=${ANA_BASE_DIR}/splines

if [ ! -d $ANA_DATA_DIR ]; then
  echo "directory $ANA_DATA_DIR does not exist!"
fi
if [ ! -d $ANA_PLOT_DIR ]; then
  echo "directory $ANA_PLOT_DIR does not exist!"
fi
if [ ! -d $ANA_RUN_DIR ]; then
  echo "directory $ANA_RUN_DIR does not exist!"
fi
if [ ! -d $ANA_SPLINE_DIR ]; then
  echo "directory $ANA_SPLINE_DIR does not exist!"
fi
if [ ! -d $ANA_SRC_DIR ]; then
  echo "directory $ANA_SRC_DIR does not exist!"
fi

if [ ! -d $ANA_BIN_DIR ]; then
  echo "directory $ANA_BIN_DIR does not exist!"
  mkdir bin
fi
if [ ! -d $ANA_TXT_DIR ]; then
  echo "directory $ANA_TXT_DIR does not exist!"
  mkdir txt
fi
if [ ! -d $ANA_LIST_DIR ]; then
  echo "directory $ANA_LIST_DIR does not exist!"
  mkdir list
fi
if [ ! -d $ANA_DB_DIR ]; then
  echo "directory $ANA_DB_DIR does not exist!"
  mkdir db
fi
if [ ! -d $ANA_HIST_DIR ]; then
  echo "directory $ANA_HIST_DIR does not exist!"
  mkdir hist
fi
if [ ! -d $ANA_PS_DIR ]; then
  echo "directory $ANA_PS_DIR does not exist!"
  mkdir ps
fi

printenv | grep ANA_

