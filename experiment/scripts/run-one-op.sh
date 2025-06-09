#!/bin/bash

#########################################################################################
# ./run-one-op.sh <project_root_dir> <file_project_names> <operator> number_of_executions>
# ./run-one-op.sh $HOME/temp/matheus-tcc/delamaro/mode-test files.txt SSDL 10
#########################################################################################


if [ "$#" -ne 4 ]
then
  echo "Usage: run-one-op.sh <project_root_dir> <file_project_names> <operator> <number_of_executions>"
  exit 1
else
   EXPER_HOME=$1
   FILES=$2
   ONEOP=$3
   MAXEXEC=$4

   OUTRE=report

   for PROG in $(cat ${EXPER_HOME}/$FILES)
   do
      echo "############### TESTING PROGRAM: $PROG ###############"
      SESSION=S_$PROG

      # Compilando o código
      cd $EXPER_HOME/$PROG

      # Encontrando good of one-op
      tcase -e $SESSION
      exemuta -select -all 0 -u-$ONEOP 1 $SESSION
      exemuta -exec -v . -trace $SESSION
      list-good -research $SESSION > good-${ONEOP}.txt

      seq=1
      while [ $seq -le $MAXEXEC ]; 
      do
         # Restoring test session to inicial state
         tcase -e $SESSION
         exemuta -select -all 1 $SESSION
         exemuta -exec -v . -trace $SESSION

         OUTDIR=seq-${seq}

         if [ ! -d $OUTDIR ]
         then
            mkdir $OUTDIR
         fi

         CMDTIME=$OUTDIR/script-oneop-execution-time.csv

         # Import good random test sequence incrementaly
         sequence=$(python $EXPER_HOME/../scripts/shuffle.py --good good-${ONEOP}.txt)

         date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
         echo ";START ITERATION $seq WITH TEST CASE ORDER: $sequence" >> $CMDTIME

         date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
         echo ";DISABLING ALL TEST CASES tcase -i" >> $CMDTIME
         tcase -i $SESSION
         exemuta -exec -v . -trace $SESSION
         report -tcase -S $OUTDIR/report-before-ALL $SESSION
         muta -l $SESSION | info-muta  -active -alive > $OUTDIR/live-before-ALL.txt

         exemuta -select -all 0 -u-$ONEOP 1 $SESSION
         exemuta -exec -v . -trace $SESSION
         report -tcase -S $OUTDIR/report-before-$ONEOP $SESSION
         muta -l $SESSION | info-muta  -active -alive > $OUTDIR/live-before-${ONEOP}.txt

         echo $sequence > $OUTDIR/testset-sequence.txt

         ctc=1
         for tc in ${sequence}
         do
            STAMP=$(date "+%Y-%m-%d-%H-%M-%S-%N")

            TCDIR=$OUTDIR/${ctc}-${tc}
            if [ ! -d  $TCDIR ]
            then
               mkdir $TCDIR
            fi

            date --rfc-3339=ns |tr -d "\n" >> $OUTDIR/${ctc}-${STAMP}-${tc}.csv
            echo ";BEGIN EXECUTION;$tc" >> $OUTDIR/${ctc}-${STAMP}-${tc}.csv

            date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
            echo ";ENABLE TEST CASE $tc" >> $CMDTIME
            echo "tcase -e -x "$tc" $SESSION"
            tcase -e -x "$tc" $SESSION

            date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
            echo ";ENABLE ONLY $ONEOP MUTANTS" >> $CMDTIME
            exemuta -select -all 0 -u-$ONEOP 1 $SESSION

            date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
            echo ";EXECUTING $ONEOP MUTANTS WITH TEST CASES" >> $CMDTIME
            exemuta -exec -v . -trace $SESSION

            date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
            echo ";GENERATING $ONEOP REPORT" >> $CMDTIME
            report -tcase -S $TCDIR/${OUTRE}-${ONEOP} $SESSION

            date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
            echo ";RESGISTERING ALL LIVE MUTANTS OF $ONEOP muta -l" >> $CMDTIME
            muta -l $SESSION | info-muta -active -alive > $TCDIR/live-$ONEOP.txt

            date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
            echo ";ENABLING $ONEOP GOOD TEST CASES" >> $CMDTIME
            list-good $SESSION > $TCDIR/good-${ONEOP}.txt
            tcase -e -x "$(cat $TCDIR/good-${ONEOP}.txt)" $SESSION
            report -tcase -L 32 -S $TCDIR/test-case-status $SESSION 

            date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
            echo ";ENABLE ALL MUTANTS" >> $CMDTIME
            exemuta -select -all 1 $SESSION

            date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
            echo ";EXECUTING ALL MUTANTS WITH TEST CASES" >> $CMDTIME
            exemuta -exec -v . -trace $SESSION

            date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
            echo ";GENERATING ALL MUTANTS REPORT" >> $CMDTIME
            report -tcase -S $TCDIR/${OUTRE}-ALL $SESSION

            date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
            echo ";RESGISTERING ALL LIVE MUTANTS muta -l" >> $CMDTIME
            muta -l $SESSION | info-muta  -active -alive > $TCDIR/live-ALL.txt

            date --rfc-3339=ns |tr -d "\n" >> $OUTDIR/${ctc}-${STAMP}-${tc}.csv
            echo ";END EXECUTION;$tc" >> $OUTDIR/${ctc}-${STAMP}-${tc}.csv
            ctc=$((ctc + 1))
         done

         date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
         echo ";ENABLING ALL TEST CASES tcase -e" >> $CMDTIME
         # Restoring section to initial state
         tcase -e $SESSION
         exemuta -select -all 1 $SESSION
         exemuta -exec -v . -trace $SESSION

         date --rfc-3339=ns |tr -d "\n" >> $CMDTIME
         echo ";END ITERATION $seq WITH TEST CASE ORDER: $sequence" >> $CMDTIME
         
         seq=$((seq + 1))
      done
   done
fi