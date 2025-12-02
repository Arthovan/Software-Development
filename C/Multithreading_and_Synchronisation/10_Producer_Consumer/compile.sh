mkdir build
gcc -g -c Queue.c -o build/Queue.o
gcc -g -c Assignment_prod_cons_on_Q.c -o build/Assignment_prod_cons_on_Q.o
gcc -g -c Assignment_prod_cons_on_Q_Solution.c -o build/Assignment_prod_cons_on_Q_Solution.o
gcc -g build/Assignment_prod_cons_on_Q.o build/Queue.o -o build/exe -lpthread
gcc -g build/Assignment_prod_cons_on_Q_Solution.o build/Queue.o -o build/solution.exe -lpthread