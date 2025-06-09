#!/bin/bash

#####################################################################################################
# ./syntesis-score-one-op.sh <root-dir> <file-with-project-names> <operator> <number_of_executions>
#
# ./scripts/syntesis-score-one-op.sh $PWD/programs files.txt SSDL 10
#####################################################################################################

if [ "$#" -ne 4 ]
then
  echo "Usage: syntesis-score-one-op.sh <project_root_dir> <file_project_names> <operator> <number_of_executions>"
  exit 1
else
	ROOT=$1
	PROJECTS=$2
	ONEOP=$3
	MAXEXEC=$4

	for f in $(cat $ROOT/$PROJECTS)
	do 
		OUTFILE=$ROOT/$f/syntese-score-${ONEOP}.csv
		echo "Working on Program $f"
		echo "PROG;SEQ;CTC;TC;ACTIVE-OP;ALIVE-OP;EQUIVALENT-OP;SCORE-OP;ACTIVE-ALL;ALIVE-ALL;EQUIVALENT-ALL;SCORE-ALL;START-EXEC;END-EXEC;TIME-DIFF" > $OUTFILE

		seq=1
    while [ $seq -le $MAXEXEC ]; 
    do
			echo -n "$f;$seq;0;0;" >> $OUTFILE
			cat $ROOT/$f/seq-$seq/report-before-${ONEOP}.lst | grep ACTIVE | awk '{printf("%s;",$4)}' >> $OUTFILE
			cat $ROOT/$f/seq-$seq/report-before-${ONEOP}.lst | grep ALIVE | awk '{printf("%s;",$4)}' >> $OUTFILE
			cat $ROOT/$f/seq-$seq/report-before-${ONEOP}.lst | grep EQUIVALENT | awk '{printf("%s;",$4)}' >> $OUTFILE
			cat $ROOT/$f/seq-$seq/report-before-${ONEOP}.lst | grep SCORE | awk '{printf("%s;",$4)}' >> $OUTFILE
			cat $ROOT/$f/seq-$seq/report-before-ALL.lst | grep ACTIVE | awk '{printf("%s;",$4)}' >> $OUTFILE
			cat $ROOT/$f/seq-$seq/report-before-ALL.lst | grep ALIVE | awk '{printf("%s;",$4)}' >> $OUTFILE
			cat $ROOT/$f/seq-$seq/report-before-ALL.lst | grep EQUIVALENT | awk '{printf("%s;",$4)}' >> $OUTFILE
			cat $ROOT/$f/seq-$seq/report-before-ALL.lst | grep SCORE | awk '{printf("%s;",$4)}'>> $OUTFILE
			TIME="-;-"
			echo -n "$TIME" >> $OUTFILE
			DIFF=";-"
			echo -n "$DIFF" >> $OUTFILE
			echo "" >> $OUTFILE

    	echo -n .
			ctc=1
			for tc in $(cat $ROOT/$f/seq-$seq/testset-sequence.txt)
			do
				echo -n "$f;$seq;$ctc;$tc;" >> $OUTFILE
				cat $ROOT/$f/seq-$seq/${ctc}-${tc}/report-${ONEOP}.lst | grep ACTIVE | awk '{printf("%s;",$4)}' >> $OUTFILE
				cat $ROOT/$f/seq-$seq/${ctc}-${tc}/report-${ONEOP}.lst | grep ALIVE | awk '{printf("%s;",$4)}' >> $OUTFILE
				cat $ROOT/$f/seq-$seq/${ctc}-${tc}/report-${ONEOP}.lst | grep EQUIVALENT | awk '{printf("%s;",$4)}' >> $OUTFILE
				cat $ROOT/$f/seq-$seq/${ctc}-${tc}/report-${ONEOP}.lst | grep SCORE | awk '{printf("%s;",$4)}' >> $OUTFILE
				cat $ROOT/$f/seq-$seq/${ctc}-${tc}/report-ALL.lst | grep ACTIVE | awk '{printf("%s;",$4)}' >> $OUTFILE
				cat $ROOT/$f/seq-$seq/${ctc}-${tc}/report-ALL.lst | grep ALIVE | awk '{printf("%s;",$4)}' >> $OUTFILE
				cat $ROOT/$f/seq-$seq/${ctc}-${tc}/report-ALL.lst | grep EQUIVALENT | awk '{printf("%s;",$4)}' >> $OUTFILE
				cat $ROOT/$f/seq-$seq/${ctc}-${tc}/report-ALL.lst | grep SCORE | awk '{printf("%s;",$4)}'>> $OUTFILE
				TIME=$(cat $ROOT/$f/seq-$seq/*-$tc.csv | awk 'BEGIN{FS=";"}{printf("%s;",$1)}')
				echo -n "$TIME" >> $OUTFILE
				DIFF=$(python $ROOT/../scripts/time-diff.py --interval "$TIME" --format "%Y-%m-%d %H:%M:%S.%f%z")
				echo -n "$DIFF" >> $OUTFILE
				echo "" >> $OUTFILE
				ctc=$((ctc + 1))
			done
			seq=$((seq + 1))
		done
		echo
	done
fi