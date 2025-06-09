#!/bin/bash

#####################################################################################################
# ./syntesis-number-mutants-per-oprator.sh <root-dir> <file-with-project-names>
#
# ./scripts/syntesis-number-mutants-per-oprator.sh $PWD/programs files.txt
#####################################################################################################

if [ "$#" -ne 2 ]
then
  echo "Usage: syntesis-number-mutants-per-oprator.sh <project_root_dir> <file_project_names>"
  exit 1
else
	EXPER_HOME=$1
	FILES=$2  

  for PROG in $(cat ${EXPER_HOME}/$FILES)
  do
    echo "############### COUNTING MUTANTS IN PROGRAM: $PROG ###############"
    SESSION=S_$PROG

    # Compilando o código
    cd $EXPER_HOME/$PROG

    OUTDIR="report-per-operator"
    if [ ! -d $OUTDIR ]
    then
      mkdir $OUTDIR
    fi

    # Restoring test session to inicial state
    tcase -e $SESSION
    exemuta -select -all 1 $SESSION
    exemuta -exec -v . -trace $SESSION

		OUTPUT=number-of-mutants-per-operator.csv

		echo "Operator,NON_EQ,EQ,TOTAL" > $OUTPUT
    SUNTOTAL=0
    SUNEQ=0
    SUNNONEQ=0

    # Counting mutants for each operator
    for ONEOP in $(cat $EXPER_HOME/../scripts/unit-operators-list.txt)
    do
    	echo -n "."

      exemuta -select -all 0 -u-$ONEOP 1 $SESSION
      exemuta -exec -v . -trace $SESSION
      report -tcase -S $OUTDIR/report-${ONEOP} $SESSION

			TOTAL=$(cat $OUTDIR/report-${ONEOP}.lst | grep ACTIVE | awk '{printf("%s",$4)}')
			EQ=$(cat $OUTDIR/report-${ONEOP}.lst | grep EQUIVALENT | awk '{printf("%s",$4)}')
			NONEQ=$((TOTAL - EQ))

      SUNTOTAL=$((SUNTOTAL + TOTAL))
      SUNEQ=$((SUNEQ + EQ))
      SUNNONEQ=$((SUNNONEQ + NONEQ))

			echo "${ONEOP},${NONEQ},${EQ},${TOTAL}" >> $OUTPUT

      # Restoring section to initial state
      tcase -e $SESSION
      exemuta -select -all 1 $SESSION
      exemuta -exec -v . -trace $SESSION
    done
    echo "Total,${SUNNONEQ},${SUNEQ},${SUNTOTAL}" >> $OUTPUT
    echo ""
  done
fi