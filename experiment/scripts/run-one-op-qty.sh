#!/bin/bash

#########################################################################################
# ./run-one-op-qty.sh <project_root_dir> <file_project_names> <operator> number_of_executions>
# ./run-one-op-qty.sh $HOME/temp/matheus-tcc/delamaro/mode-test files.txt SSDL 10
#########################################################################################


if [ "$#" -ne 4 ]
then
  echo "Usage: run-one-op-qty.sh <project_root_dir> <file_project_names> <operator> <number_of_executions>"
  exit 1
else
   EXPER_HOME=$1
   FILES=$2
   ONEOP=$3
   MAXEXEC=$4

   for PROG in $(cat ${EXPER_HOME}/$FILES)
   do
      echo "############### TESTING PROGRAM: $PROG ###############"
      SESSION=S_$PROG

      # Compilando o código
      cd $EXPER_HOME/$PROG

      $EXPER_HOME/../scripts/quantity-mutant-per-opeator.sh $SESSION equivalent-${PROG}.txt equivalent-list-op-${PROG}.txt equivalent-qty-${PROG}.txt

      seq=1
      while [ $seq -le $MAXEXEC ]; 
      do
         OUTDIR=seq-${seq}

         echo $seq

         $EXPER_HOME/../scripts/quantity-mutant-per-opeator.sh $SESSION $OUTDIR/live-before-ALL.txt $OUTDIR/live-before-list-op-ALL.txt $OUTDIR/live-before-qty-ALL.txt

         $EXPER_HOME/../scripts/quantity-mutant-per-opeator.sh $SESSION $OUTDIR/live-before-${ONEOP}.txt $OUTDIR/live-before-list-op-${ONEOP}.txt $OUTDIR/live-before-qty-${ONEOP}.txt
         
         ctc=1
         for tc in $(cat $OUTDIR/testset-sequence.txt)
         do
            echo -n "."
            TCDIR=$OUTDIR/${ctc}-${tc}

            $EXPER_HOME/../scripts/quantity-mutant-per-opeator.sh $SESSION $TCDIR/live-ALL.txt $TCDIR/live-list-op-ALL.txt $TCDIR/live-qty-ALL.txt

            $EXPER_HOME/../scripts/quantity-mutant-per-opeator.sh $SESSION $TCDIR/live-${ONEOP}.txt $TCDIR/live-list-op-${ONEOP}.txt $TCDIR/live-qty-${ONEOP}.txt

            ctc=$((ctc + 1))
         done

         echo
         
         seq=$((seq + 1))
      done
   done
fi