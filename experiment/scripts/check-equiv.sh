#!/bin/bash

#####################################################################
# check-equiv.sh $HOME/temp/matheus-tcc/delamaro/clean-programs files.txt
#####################################################################

OUTRE=report

if [ "$#" -ne 2 ]
then
  echo "Usage: check-equiv.sh <projects root directory> <file with directory names to be tested>"
  exit 1
else
   EXPER_HOME=$1
   FILES=$2

   for PROG in $(cat ${EXPER_HOME}/$FILES)
   do
      SESSION=S_$PROG

      # Compilando o código
      cd $EXPER_HOME/$PROG
      
      echo "############### TESTING PROGRAM: $PROG ###############"
      
      muta -l $SESSION | info-muta -alive >> equivalent-${PROG}.txt
      #muta -l $SESSION | info-muta -equiv >> equivalent-${PROG}.txt

      sleep 1

      # Marcando Mutantes Equivalentes
      equivalents=$(cat equivalent-${PROG}.txt)
      if [ -n "${equivalents}" ]
      then
         muta -equiv -x "$equivalents" $SESSION
         exemuta -exec -v . -trace $SESSION
      fi

      # Geração do Relatório
      report -tcase -S ${OUTRE}-final $SESSION
   done
fi
