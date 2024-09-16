#!/bin/bash

valgrind --tool=memcheck --leak-check=full --log-file=blas.memory ./tema3_blas ../input/input_valgrind
valgrind --tool=memcheck --leak-check=full --log-file=neopt.memory ./tema3_neopt ../input/input_valgrind
valgrind --tool=memcheck --leak-check=full --log-file=opt_m.memory ./tema3_opt_m ../input/input_valgrind