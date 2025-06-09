# Experimento LLM na Geração de Casos de Teste

## Variáveis de ambiente

```
EXPER_HOME=<caminho até programas>
PROG=<nome diretorio programa em teste>
```

Por exemplo:

```
EXPER_HOME=$HOME/temp/matheus-tcc/delamaro/clean-programs

PROG=boundedQueue
SESSION=S_$PROG
```

## Comandos execução

1) Compilando o código

```
cd $EXPER_HOME/$PROG
compilation=$(cat compile.txt)
$compilation
```

2) Criação da Sessão de Teste

```
test-new -S $PROG -E $PROG -C "$compilation"  $SESSION
```

2.1) Criar codigo versão instrumentada

```
instrum -EE $SESSION __${PROG}
```

2.2) Compilar código instrumentado

```
gcc __${PROG}_inst.c  __${PROG}_pp.c driver.c -o ${PROG}_inst -w -lm -I$PROTEUMIMHOME
```

3) Geração dos Mutantes Unitários

```
functions=$(cat functions.txt | awk '{printf("-unit %s ", $1)}')

muta-gen $functions -u- 1.0 0 $SESSION
```

3.1) Geração do relatório inicial

```
exemuta -exec -v . -trace $SESSION
report -tcase -S ${PROG}_initial $SESSION
```

4) Marcando Mutantes Equivalentes

```
equivalents=$(cat equivalent-${PROG}.txt)

muta -equiv -x "$equivalents" $SESSION
```

5) Importar casos de teste

```
tc=1
NTC=$(wc -l testset.txt | awk '{print $1}')
while [ $tc -le $NTC ]; 
do
   param=$(head -$tc testset.txt | tail -1)
   tcase-add -p "$param" -EE ${PROG}_inst -trace $SESSION
   tc=$((tc + 1))
done
```

6) Executar Mutantes

```
exemuta -exec -v . -trace $SESSION
```

7) Geração do Relatório

```
report -tcase -S ${PROG}_final $SESSION
```