echo "Testando (exemplo inicial)..."
echo

output=$(./main.out)

if [ $? -eq 0 ] ; then
  echo "Running ok: Program exited zero"
else
  echo "Fail on running: Program did not exit zero"
  exit 1
fi

echo
echo "Teste de execucao realizado com sucesso"

$(rm main.out *.o)

exit 0