#!/bin/bash

#####################################################################################################
# ./program-metrics.sh <root-dir> <file-with-project-names>
#
# ./scripts/program-metrics.sh $PWD/programs files.txt <operator>
#####################################################################################################

if [ "$#" -ne 3 ]
then
  echo "Usage: program-metrics.sh <project_root_dir> <file_project_names> <one-op operator>"
  exit 1
else
	ROOT=$1
	PROJECTS=$2
	ONEOP=$3

	OUTFILE=$ROOT/program-metrics.csv
	echo "PROG,FUN,LOC,TOTAL,EQ,NON_EQ,${ONEOP},EQ_${ONEOP},NON_EQ_${ONEOP},TS" > $OUTFILE

  SUNTOTAL=0
  SUNEQ=0
  SUNNONEQ=0

	for f in $(cat $ROOT/$PROJECTS)
	do 
		echo "Working on Program $f"

		# Computing Function and LOC data
		NF=0
		TOTALLOC=0
		for func in $(cat $ROOT/$f/functions.txt)
	  do
	  	echo "   $func"
			locf=$(grep "|$func " $ROOT/$f/script-test-new.out | awk '{print $2}')
			TOTALLOC=$((TOTALLOC + locf))
			NF=$((NF + 1))
		done

		# Computing Mutant Data Total
		TOTAL=$(cat $ROOT/$f/report-final.lst | grep ACTIVE | awk '{printf("%s",$4)}')
		EQ=$(cat $ROOT/$f/report-final.lst | grep EQUIVALENT | awk '{printf("%s",$4)}')
		NONEQ=$((TOTAL - EQ))


		# Computing Mutant Data for ONEOP
		TOTALONEOP=$(cat $ROOT/$f/report-per-operator/report-${ONEOP}.lst | grep ACTIVE | awk '{printf("%s",$4)}')
		EQONEOP=$(cat $ROOT/$f/report-per-operator/report-${ONEOP}.lst | grep EQUIVALENT | awk '{printf("%s",$4)}')
		NONEQONEOP=$((TOTALONEOP - EQONEOP))

		TC=$(wc -l $ROOT/$f/testset.txt | awk '{print $1}')

		echo "${f},${NF},${TOTALLOC},${TOTAL},${EQ},${NONEQ},${TOTALONEOP},${EQONEOP},${NONEQONEOP},${TC}" >> $OUTFILE
	done
fi