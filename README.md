# SZE-MOSZE-2020-GitCraft
==========================

###  Alap dolgok:
#### Character objektumok képesek harcolni
#### Game objektum elindítja a játékot és szimulál egy egyszerű harcot
==========================

## Leírás
Az játék működését egyelőre a Character és a Game osztályok biztosítják.

### Character
Minden karakter létrehozásakor rendelkezni fog egy névvel, kezdő HP-val és sebzéssel. Mivel ezek az osztály **private** tulajdonságaihoz tartoznak, ezért egy-egy **gettert** hoztunk létre, hogy a későbbiekben más osztályok is kiolvashassák ezen tulajdonságokat. További függvények:
* Az osztály rendelkezik egy **isAlive()** függvénnyel, amely meghatározza, hogy az adott karakter életben van -e. Ez akkor nem lesz igaz, ha a HP-ja 0 lesz.
* A **setHp(int dmg)** függvény biztosítja egy adott karakter HP-jának módosulását oly módon, hogy az soha nem mehet 0 alá.
* A **print()** függvény kiírja a karakter tulajdonságait a mintában megadott módon.
* Az **attack(Character* c)** teszi lehetővé egy másik Character objektum megtámadását. Ez egyelőre csak a sebzés alapján módosítja az ellenfél HP-ját a **setHP()** függvény meghívásával.

### Game
A játék futását ez az osztály teszi lehetővé. Rendelkezik egy **bool running** értékkel, amely megmondja, hogy éppen fut -e a játék, vagy sem. Függvényei:
* **start():** elindítja a játékot.
* **stop():** megállítja a játékot.
* **run():** a játék futása alatt történő dolgok ide kerülnek (most itt fut le a szimuláció is).# SZE-MOSZE-2020-GitCraft
