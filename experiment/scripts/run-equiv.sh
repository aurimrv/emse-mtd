#!/bin/bash

#####################################################################
# run-equivs.sh $HOME/temp/matheus-tcc/delamaro/clean-programs files.txt
#####################################################################


if [ "$#" -ne 2 ]
then
  echo "Usage: run-equivs.sh <projects root directory> <file with directory names to be tested>"
  exit 1
else
   EXPER_HOME=$1
   FILES=$2

   OUTTN=script-test-new.out
   OUTMG=script-muta-gen.out
   OUTTC=script-tcase-add.out
   OUTRE=report
   OUTEQ=script-equivalent.txt
   CMDTIME=script-execution-time.csv
   for PROG in $(cat ${EXPER_HOME}/$FILES)
   do
      SESSION=S_$PROG

      # Compilando o código
      cd $EXPER_HOME/$PROG

      # All live mutants are equivalent
      #mv equivalent-${PROG}.txt equivalent-${PROG}.bkp
      muta -l $SESSION | info-muta -alive > equivalent-${PROG}.txt

      # Geração do Relatório
      report -tcase -S ${OUTRE}-live $SESSION

      # Marcando Mutantes Equivalentes
      date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
      echo ";START muta -equiv" >> $CMDTIME
      equivalents=$(cat equivalent-${PROG}.txt)
      if [[ -n "$equivalents" ]]; then
         muta -equiv -x "$equivalents" $SESSION
      fi      
      exemuta -exec -v . -trace $SESSION
      date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
      echo ";END muta -equiv" >> $CMDTIME

      # Geração do Relatório
      report -tcase -S ${OUTRE}-final $SESSION
   done
fi