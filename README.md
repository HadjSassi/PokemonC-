# Introduction C++
## 3éme année IS (par HADJ SASSI Mahdi)
### 2025-2026 (Semestre 1) (Encadré par M. TAUVEL)

# TP 1: Pokemon Selector

## 1.1 Mise en place du Framework SFML

Pour faire marcher SFML, il faut d'abord l'installer. Vous pouvez télécharger la bibliothèque en utilisant
la commande `sudo apt-get install libsfml-dev` sur les systèmes basés sur Debian/Ubuntu.

Lorsque qu'on a voulu le faire marché, on a eu des problémes de ce genre !
```
c++ /home/mahdihadjsassi/ENSEA/C++/projects/main.cpp -o main /usr/bin/ld: /tmp/ccV9YVlD.o: 
warning: relocation against _ZTVN2sf11CircleShapeE' in read-only section .text._ZN2sf11CircleShapeD2Ev[_ZN2sf11CircleShapeD5Ev]'
......
ld returned 1 exit status
```

Et merci au LLM, la solution c'est de faire lancer ces commandes de cmake pour le build : 

```bash
cmake -S . -B build
cmake --build build
./build/pokemon
```

Donc, pour faciliter la tache, on a fait un petit makefile pour lancer rapidement les commandes cmake. 

et voici le résultat pour l'exécution du programme :

![img.png](documentation/tache1.1.png)

## 1.2 Premiéres classes

On a inclus les fichiers de pokemon.hpp et .cpp de cours, dans le projet, et on a testé l'intégratlié de projet.

on a commité sur ce niveau, pour tester l'integration, dans les prochians commits, on va effacer les deux lignes 
pour afficher le pokemon.

le commit est le suivant : 
```commit 3e33fe2a63d75b236f83621f8c3c603616b3fe5b```

le resultat de l'execution est le suivant :
```
./pokemon
ID: 1
Name: monster1
Hit Points: 100
Attack: 20
Defense: 10
Generation: 1
make[1]: on quitte le répertoire «/home/mahdihadjsassi/ENSEA/C++/projects»
```