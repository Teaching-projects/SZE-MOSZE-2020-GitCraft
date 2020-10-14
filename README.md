SZE-MOSZE-2020-GitCraft
==========================

###  Alap dolgok:
#### Character objektumok képesek harcolni
#### A main parancssorból kapja az argumentumokat, amelyeket felhasználva szimulál egy harcot.

## Leírás
Az játék működését egyelőre a Character osztály és a main biztosítják. A kérésnek megfelelően, a szoftver parancssorból kapja az argumentumokat és ez alapján lebonyolít egy harcszimulációt. Argumentumok nélkül a program hibát fog dobni és leáll. A megadott argumentumok ".json" kiterjesztésű fájlnevek legyenek. Megadáskor elegendő a fájl nevét és a kiterjesztést megadni. Például: Ork.json Troll.json. Ha a fájl nem létezik a program egy exceptiont fog dobni, hogy nem lehetséges a fájl megnyitása.

### Character
Minden karakter létrehozásakor rendelkezni fog egy névvel, kezdő HP-val és sebzéssel és egy sebzési idővel. Mivel ezek az osztály **private** tulajdonságaihoz tartoznak, ezért egy-egy **gettert** hoztunk létre, hogy a későbbiekben másik osztályban is kiolvashassuk ezen tulajdonságokat. További függvények:
* Az osztály rendelkezik egy **isAlive()** függvénnyel, amely meghatározza, hogy az adott karakter életben van -e. Ez akkor nem lesz igaz, ha a HP-ja 0 lesz.
* Az overloaded << operátor segítségével kiíratjuk a karakter tulajdonságait a mintában megadott módon.
* Az **attack(Character &c)** privát függvény teszi lehetővé a **takeDamage(Character& player, Character& enemy)** számára, hogy a sebzések időtartamát felhasználva végrehajtódjon a támadás. 
* A **parseUnit(std::string charSheetName)** teszi lehetővé az argumentumként kapott fájlokból való program futtatást.
*A **takeDamage(Character& player, Character& enemy)** függvény a **attack(Character &c)** és a sebzési idővel kalkulálva leszimulálja a harcot a két megadott Character között. Ezt követően kiírja a győztest és adatait.

### Dokumentáció:
https://teaching-projects.github.io/SZE-MOSZE-2020-GitCraft/