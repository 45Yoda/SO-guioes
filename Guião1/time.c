experiencia time

time ./mycat-v2 1 < LIXO > /dev/null
real 0m3,162s
time ./mycat-v2 10 < LIXO > /dev/null
real 0m0,341s
time ./mycat-v2 100 < LIXO > /dev/null
real 0m0,035s
time ./mycat-v2 1000 < LIXO > /dev/null
real 0m0,006s
time ./mycat-v2 10000 < LIXO > /dev/null (bit bucket)
real 0m0,002s

1000 vezes mais demorado (comparando 1 com 10000)
