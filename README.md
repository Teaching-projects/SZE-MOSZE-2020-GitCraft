SZE-MOSZE-2020-GitCraft
==========================

###  Alap dolgok:
#### Character objektumok képesek harcolni
#### A main parancssorból kapja az argumentumokat, amelyeket felhasználva szimulál egy harcot.

## Leírás
Az játék működését egyelőre a Character osztály és a main biztosítják. A kérésnek megfelelően, a szoftver parancssorból kapja az argumentumokat és ez alapján lebonyolít egy harcszimulációt. Argumentumok nélkül a program hibát fog dobni és leáll.

### Character
Minden karakter létrehozásakor rendelkezni fog egy névvel, kezdő HP-val és sebzéssel. Mivel ezek az osztály **private** tulajdonságaihoz tartoznak, ezért egy-egy **gettert** hoztunk létre, hogy a későbbiekben másik osztályban is kiolvashassuk ezen tulajdonságokat. További függvények:
* Az osztály rendelkezik egy **isAlive()** függvénnyel, amely meghatározza, hogy az adott karakter életben van -e. Ez akkor nem lesz igaz, ha a HP-ja 0 lesz.
* A **setHp(int dmg)** függvény biztosítja egy adott karakter HP-jának módosulását oly módon, hogy az soha nem mehet 0 alá.
* A **print()** függvény kiírja a karakter tulajdonságait a mintában megadott módon.
* Az **attack(Character &c)** teszi lehetővé egy másik Character objektum megtámadását. Ez egyelőre csak a sebzés alapján módosítja az ellenfél HP-ját a **setHP()** függvény meghívásával.
