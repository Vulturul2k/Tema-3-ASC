Tema 2 ASC - Florea Radu 332CD

## solver_neopt
Aici am 2 functii care fac inmultirea matricilor B*A si At*B,  in ele tin cont ca matricea A este superior triunghiulara si parcurg for-ul pana la j, respectiv i pentru At. Matricile sunt stocate intr-un vector si sunt parcurse cu [i*N + j]. In functia principala, fac suma matricilor si calculez inmultirea sumei cu transpusa lui B, aici, matricea nu mai este superior triunghiulara.
## sopler_opt
In varianta optima nu am mai folosit functii, in loc de int si double am folosit register int, respectiv register double. M-am folosit de pointeri pentru cautarea in memorie. Cand am incrementat pointerul cu ++, m-am mutat pe alta coloana, cu +=N, m-am mutat pe alta linie. O alta optimizare facuta, este folosirea unei variabile pentru calcularea sumei (sum), ulterior atribuind-o matricii.
## solver_blas
Aici am alocat memorie pentru C, temp1 si temp2. In temp1 si temp2 am copiat matricea B, deoarece cblas_dtrmm suprascrie una din matrici. Am calculat cu cblas_dtrmm inmultirea matricilor At*B si B*A, deoarece A este superior triunghiulara. La At*B am specificat ca a este transpusa(CblasTrans), in B*A am specificat ordinea(side, CblasRight). Cu cblass_daxpy am calculat suma celor 2 matrici.
Pentru inmultirea sumei cu transpusa lui B, am folosit functia cblas_dgemm (C←αBA + βC), unde am specificat ca B este transpus, alfa e 1 si beta e 0.
Am eliberat memoria si am returnat matricea C.

## explicatii grafic
Testele au fost rulate pe fep direct
200 981 out1
400 123 out2
800 456 out3
1000 753 out4
1200 789 out5
Functiile Blas au rulat cel mai rapid. Rezolvarea neoptima este cea mai lenta, crescand direct proportional cu marimea testului. Rezolvare optima este mult mai rapida decat cea neoptima, dar nici nu se aproprie de cea blas. Viteza rezolvarii optime se datoreaza in principal folosirea variabilelor de tip register dar si folosirea pointerilor care economisesc timpul folosit pentru cautarea in memorie.

## explicatii cache
dar si explicatii oferite despre efectul optmizarilor facute de mana in varianta opt_m asupra valorilor obtinute
### I refs (Instruction References) Un număr mai mare de I refs indică un cod mai lung și posibil mai complex.
neopt 5,934,718,000
opt 1,859,739,766 . Aici am optimizat codul si prin folosirea de mai putine functii si instructiuni de tip for
blas 250,268,166 Functiile apelate folosesc mai putine instructiuni
### D refs (Data References) Indica o eficienta mai buna in utilizarea cache-ului:
neopt 2,972,436,213
opt 431,462,365. Am optimizat algoritmul folosind mai putine date decat la neoptimizat. (Mai putine malloc-uri de exemplu, dar si folosirea pointerilor pentru cautare).
blas 99,121,231
### Branches: Numarul total de instructiuni de ramificare (conditionale si indirecte).
neopt 138,855,652
opt 133,493,373 Optimizarea este una destul de mica fata de varianta neoptimizata. Algoritmul este in esenta aceelasi.
blas 8,377,493 Aici am un numar mult mai mic de Branch-uri fata de algoritmul normal.


## Efectul optimizarilor in varianta opt_m
Optimizarile manuale au dus la:

Reducerea I refs: Prin eliminarea functiilor suplimentare si a unor bucle for inutile, numărul de instrucțiuni a scăzut.
Reducerea D refs: Utilizarea pointerilor si reducerea alocarilor de memorie au dus la un număr mai mic de referințe la date.
Reducerea Branches: Desi reducerea este mica, eliminarea unor instructiuni conditionale a contribuit la o mica imbunatatire.