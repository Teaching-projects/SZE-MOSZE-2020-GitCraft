SZE-MOSZE-2020-GitCraft
==========================

###  Alap dolgok:
#### Character objektumok képesek harcolni
#### 100 Xp megszerzése esetén szintlépés történik meg a karakterknél
#### A main parancssorból kapja az argumentumokat, amelyeket felhasználva szimulál egy harcot.

## Leírás
Az játék működését egyelőre a Character osztály és a main biztosítják. A kérésnek megfelelően, a szoftver parancssorból kapja az argumentumokat és ez alapján lebonyolít egy harcszimulációt. Argumentumok nélkül a program hibát fog dobni és leáll. A megadott argumentumok ".json" kiterjesztésű fájlnevek legyenek. Megadáskor elegendő a fájl nevét és a kiterjesztést megadni. Például: Ork.json Troll.json. Ha a fájl nem létezik a program egy exceptiont fog dobni, hogy nem lehetséges a fájl megnyitása.
A karakterek megütik egymást, melynek hatására adott sebzés bevitele hatására nő az aktuális Xp, 100 Xp megszerzése esetén a karakter szintet lép. A Max Hp-ja 10%-al, illetve a sebzés is 10%-al. Az aktuális Hp a maximális Hp-val lesz egyenlő. Abban az esetben, ha a megütött karakter Hp-ja kisebb mint a sebzése a támadást indítónak, Xp-ként a Hp értékét kapja meg a karakter.

### Character
Minden karakter létrehozásakor rendelkezni fog egy névvel, kezdő HP-val és sebzéssel. Mivel ezek az osztály **private** tulajdonságaihoz tartoznak, ezért egy-egy **gettert** hoztunk létre, hogy a későbbiekben másik osztályban is kiolvashassuk ezen tulajdonságokat. További függvények:
* Az osztály rendelkezik egy **isAlive()** függvénnyel, amely meghatározza, hogy az adott karakter életben van -e. Ez akkor nem lesz igaz, ha a HP-ja 0 lesz.
* Az overloaded << operátor segítségével kiíratjuk a karakter tulajdonságait a mintában megadott módon.
* A **fight(Charachter &c)** teszi lehetővé egy másik Character objektum megtámadását, valamint a szintlépést.
* Az **attack(Character &c)** a sebzések beviteléért, az ellenfél Hp-jának megfelelő értékkel történő csökkentésért felelős. Továbbá a sebzés bevitelével a Karakter Xp értékének növelése is a metódus segítségével történik meg.
* A **levelup()** segítségével történik meg a szintlépés. Abban az esetben, ha a felhasználó Xp-je eléri 100-at, vagy annak egész számú többszörösét, akkor megtörténik a szintlépés, akár egyszerre több szint is. Az Xp, csökkentve lesz a szintlépések számával arányosan 100-al.
* A **parseUnit(std::string charSheetName)** teszi lehetővé az argumentumként kapott fájlokból való program futtatást.