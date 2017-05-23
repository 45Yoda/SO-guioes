mkfifo umpipe (fifo com nome pipe);


escrever no pipe (num terminal)
ls > umpipe

ler no pipe (outro terminal)
wc < umpipe





     SV
    /
   /
  /
r dados
  \     Espera
  N\ S/
    \/tam   EOF
     \   N/
    N \  /
       \/Já teve?
        \
        S\
          \Espera


podemos acabar com linhas misturadas se estivermos a escrever e a ler ao mesmo tempo
escrever linhas com menos de 512 bytes temos a certeza que a linha acaba inteira
