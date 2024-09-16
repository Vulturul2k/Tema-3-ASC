#!/bin/bash

valgrind --tool=cachegrind --branch-sim=yes --cache-sim=yes --log-file=blas.cache ./tema3_blas ../input/input_valgrind
valgrind --tool=cachegrind --branch-sim=yes --cache-sim=yes --log-file=neopt.cache ./tema3_neopt ../input/input_valgrind
valgrind --tool=cachegrind --branch-sim=yes --cache-sim=yes --log-file=opt_m.cache ./tema3_opt_m ../input/input_valgrind