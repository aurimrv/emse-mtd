#!/bin/bash

################################################################################
# import-new-tc.sh $HOME/temp/matheus-tcc/delamaro/clean-programs checkIt 1 5
################################################################################


if [ "$#" -ne 4 ]
then
  echo "Usage: import-new-tc.sh <projects root directory> <project name> <from> <to>"
  exit 1
else
   EXPER_HOME=$1
   PROG=$2
   FROM=$3
   TO=$4

   SESSION=S_$PROG

   # Compilando o código
   cd $EXPER_HOME/$PROG

   # Importar casos de teste
   tc=$FROM
   NTC=$TO
   while [ $tc -le $NTC ]; 
   do
      param=$(head -$tc testset.txt | tail -1)
      echo "Importing TC $tc of $NTC - param: $param"
      tcase-add -p "$param" -EE ${PROG}_inst -trace $SESSION
      tc=$((tc + 1))
   done

   # Executar Mutantes
   exemuta -exec -v . -trace $SESSION

   # Geração do Relatório
   report -tcase -S ${OUTRE}-live $SESSION
fi