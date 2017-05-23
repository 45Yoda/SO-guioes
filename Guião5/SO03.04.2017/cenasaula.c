//pfd[0]-> leitura (output)

//pfd[1]-> escrita (input)

//pipes anonimos são unidireccionais (unix tradicional)


/*                  _______________
         _(pfd[1])->|____PIPE______|->(pfd[0])_
        /                                      \
       |                                        |
   write()                                   read()
*/
