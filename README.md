SZE-MOSZE-2020-GitCraft
==========================

###  Alap dolgok:
#### Character objektumok képesek harcolni
#### 100 Xp megszerzése esetén szintlépés történik meg a karakterknél
#### A main parancssorból kapja az argumentumokat, amelyeket felhasználva szimulál egy harcot.

## Leírás
Az játék működését egyelőre a Character osztály és a main biztosítják. A kérésnek megfelelően, a szoftver parancssorból kapja azt az egyetlen argumentumot, amely alapján lebonyolít egy harcszimulációt. Pontosan 1 db argumetumot kell megadni, különben a program hibát fog dobni és leáll. A megadott argumentumok ".json" kiterjesztésű fájlnevek legyenek. Ezek most a *scenario1.json* és *scenario2.json* fájlok.
A karakterek megütik egymást, melynek hatására adott sebzés bevitele hatására nő az aktuális Xp, 100 Xp megszerzése esetén a karakter szintet lép. A Max Hp-ja 10%-al, illetve a sebzés is 10%-al. Az aktuális Hp a maximális Hp-val lesz egyenlő. Abban az esetben, ha a megütött karakter Hp-ja kisebb mint a sebzése a támadást indítónak, Xp-ként a Hp értékét kapja meg a karakter.

### Character
Minden karakter létrehozásakor rendelkezni fog egy névvel, kezdő HP-val és sebzéssel és egy sebzési idővel. Mivel ezek az osztály **private** tulajdonságaihoz tartoznak, ezért egy-egy **gettert** hoztunk létre, hogy a későbbiekben másik osztályban is kiolvashassuk ezen tulajdonságokat. További függvények:
* Az osztály rendelkezik egy **isAlive()** függvénnyel, amely meghatározza, hogy az adott karakter életben van -e. Ez akkor nem lesz igaz, ha a HP-ja 0 lesz.
* Az overloaded << operátor segítségével kiíratjuk a karakter tulajdonságait a mintában megadott módon.
* Az **attack(Character &c)** a sebzések beviteléért, az ellenfél Hp-jának megfelelő értékkel történő csökkentésért felelős. Továbbá a sebzés bevitelével a Karakter Xp értékének növelése is a metódus segítségével történik meg.
* A **levelup()** segítségével történik meg a szintlépés. Abban az esetben, ha a felhasználó Xp-je eléri 100-at, vagy annak egész számú többszörösét, akkor megtörténik a szintlépés, akár egyszerre több szint is. Az Xp, csökkentve lesz a szintlépések számával arányosan 100-al.
* A **parseUnit(std::string charSheetName)** teszi lehetővé az argumentumként kapott fájlokból való program futtatást. Ez úgy működik, hogy ha létező fájlnevet kap, akkor **loadUnit(ifstream &jsonFile)** hívódik meg, más esetben megpróbálkozik a program a **loadUnit(std::string data)** függvény hívásával.

### Hero, Monster
Ez a két osztály örökli a **Character** osztály tulajdonságait. A különbség köztük, hogy egy **Hero** rendelkezik xp-vel, tud szintet lépni és ennek megfelelően változik nála a *hp* és a *damage*. Ezeken kívül a **Hero** rendelkezik egy *fightTilDeath(Monster &m)* függvénnyel is, amely különböző harcok lebonyolítására alkalmas.

### Json Parser
A **JSON** osztály segítségével olvassuk be a megfelelő adatokat, különböző módokon:
- A **loadUnitFromString(std::string data)** reguláris kifejezés segítségével keres kulcs-érték párokat. (*matches[1]* = kulcs, *matches[2]* = érték minden ciklusban) A ciklus végén a *matches[2]* ellenőrzésre kerül, hogy milyen típusú értékként legyen tárolva a map-ben. A map *stringet* vár kulcsként, és *variant* template segítségével menthetünk bele *stringet*, *intet* és *doublet* is.
- A **parseContent(std::istream &jsonFile)** egy *istreamet* vár argumentumként. Ha például ez egy *fstream*, akkor abból minden sor ki lesz olvasva, amelyeket beleírunk egy stringbe, majd rekurzív módon visszatérítési értékként meghívjuk a **loadUnitFromString(std::string data)** függvényt.
- A **parseFromFile(const std::string &jsonFilePath)** egy fájl elérési útvonalát várja argumentumként, amely segítségével magát a fájlt megnyitja,
majd továbbadja a **parseContent(std::istream &file)** függvénynek.

### Unit Test
A **unit_test** mappán belül a **test_parser.cpp** tartalmazza a teszteket különböző esetekhez.

### Dokumentáció:
https://teaching-projects.github.io/SZE-MOSZE-2020-GitCraft/
