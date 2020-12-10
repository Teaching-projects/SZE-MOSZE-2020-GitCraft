SZE-MOSZE-2020-GitCraft
==========================

###  Alap dolgok:
#### Character objektumok képesek harcolni
#### 100 Xp megszerzése esetén szintlépés történik meg a karakterknél
#### A main parancssorból kapja az argumentumokat, amelyeket felhasználva lejátszhatunk egy játékot.

## Leírás
A játék működését a mainből indítjuk. A kérésnek megfelelően, a szoftver parancssorból kapja a szükséges argumentumokat, amelyek alapján felépít egy pályát. Megfelelő argumentumok nélkül a program hibát fog dobni és leáll. A megadott argumentumok ".json" kiterjesztésű fájlnevek legyenek. Ezek most a *scenario1.json*, *scenario2.json* és *sc_test.json* fájlok.
Kétféleképpen működik a játék:
* ha csak egy *scenario* fájlt adunk meg, akkor bekér egy map-et a main, ami a pálya felépítését tartalmazza
* *prepared* módban egy *json* fájlon keresztül adjuk meg a szükséges adatokat (*markedmap*, hős, monster típusok) működésre példa:
**./main prepared PreparedGame.json**
A karakterek megütik egymást, melynek hatására adott sebzés bevitele hatására nő az aktuális Xp, 100 Xp megszerzése esetén a karakter szintet lép. A Max Hp-ja 10%-al, illetve a sebzés is 10%-al nő. Emelkedik emellett a védekezési pont is, amely csak a fizikai csapásokat - vagy azok egy részét - semlegesíti. Természetesen a támadás ideje redukálódik. Az aktuális Hp a maximális Hp-val lesz egyenlő. Abban az esetben, ha a megütött karakter Hp-ja kisebb mint a sebzése a támadást indítónak, Xp-ként a Hp értékét kapja meg a karakter.

### Character
Minden karakter létrehozásakor rendelkezni fog egy névvel, kezdő HP-val és sebzéssel (fizikai, mágikus), defense értékkel, light radiussal és egy sebzési idővel. Ezek mellett megvan az, hogy melyik érték mennyi pluszt kap, ha *levelup* történik. Mivel ezek az osztály **private** tulajdonságaihoz tartoznak, ezért egy-egy **gettert** hoztunk létre, hogy a későbbiekben másik osztályban is kiolvashassuk ezen tulajdonságokat. További függvények:
* Az osztály rendelkezik egy **isAlive()** függvénnyel, amely meghatározza, hogy az adott karakter életben van -e. Ez akkor nem lesz igaz, ha a HP-ja 0 lesz.
* Az overloaded << operátor segítségével kiíratjuk a karakter tulajdonságait a mintában megadott módon.
* Az **attack(Character &c)** a sebzések beviteléért, az ellenfél Hp-jának megfelelő értékkel történő csökkentésért felelős. Továbbá a sebzés bevitelével a Karakter Xp értékének növelése is a metódus segítségével történik meg.
* A **levelup()** segítségével történik meg a szintlépés. Abban az esetben, ha a felhasználó Xp-je eléri 100-at, vagy annak egész számú többszörösét, akkor megtörténik a szintlépés, akár egyszerre több szint is. Az Xp, csökkentve lesz a szintlépések számával arányosan 100-al.
* A **parseUnit(std::string charSheetName)** teszi lehetővé az argumentumként kapott fájlokból való program futtatást. Ez úgy működik, hogy ha létező fájlnevet kap, akkor **loadUnit(ifstream &jsonFile)** hívódik meg, más esetben megpróbálkozik a program a **loadUnit(std::string data)** függvény hívásával.

### Hero, Monster
Ez a két osztály örökli a **Character** osztály tulajdonságait. A különbség köztük, hogy egy **Hero** rendelkezik xp-vel, tud szintet lépni és ennek megfelelően változnak a harcot befolyásoló tulajdonságai. Ezeken kívül a **Hero** rendelkezik egy *fightTilDeath(Monster &m)* függvénnyel is, amely különböző harcok lebonyolítására alkalmas.

### Json Parser
A **JSON** osztály segítségével olvassuk be a megfelelő adatokat, különböző módokon:
- **typedef**-ek segítségével van egy map-ünk, ami képes *listet*, *stringet*, *intet*, *doublet* is tárolhat. A *list*-re azért van szükség, mert ha az adott
*json* kiterjesztésű fájlokban listaszerűen adjuk meg a **Monstereket**, akkor a **loadInputFromString(std::string data)** képes ezeket is feldolgozni.
- A **loadInputFromString(std::string data)** reguláris kifejezés segítségével keres kulcs-érték párokat. (*matches[1]* = kulcs, *matches[2]* = érték minden ciklusban) A ciklus végén a *matches[2]* ellenőrzésre kerül, hogy milyen típusú értékként legyen tárolva a map-ben. A map *stringet* vár kulcsként, és *variant* template segítségével menthetünk bele *stringet*, *intet* és *doublet* is.
- A **variant_cast** függvény segít nekünk abban, hogy ha listát kapunk a **loadInputFromString(std::string data)**-ban, akkor az adott map kulcsához tartozó változó típusát el tudjuk dönteni.
- A **parseContent(std::istream &jsonFile)** egy *istreamet* vár argumentumként. Ha például ez egy *fstream*, akkor abból minden sor ki lesz olvasva, amelyeket beleírunk egy stringbe, majd rekurzív módon visszatérítési értékként meghívjuk a **loadUnitFromString(std::string data)** függvényt.
- A **parseFromFile(const std::string &jsonFilePath)** egy fájl elérési útvonalát várja argumentumként, amely segítségével magát a fájlt megnyitja,
majd továbbadja a **parseContent(std::istream &file)** függvénynek.
- **parseArray(const std::string& listData)** függvény felelős azért, hogy ha a **loadInputFromString(std::string data)** *list*-t érzékel, akkor feldolgozza
azt. A **loadInputFromString(std::string data)**-ban ist használt reguláris kifejezések detektálják a különböző típusú ',' karakterrel elválasztott értékeket. Ha a
',' karakter előbb jön, mint maga az érték, akkor hibát dob a rendszer. Egyéb esetben továbbadja a **parseValues(const std::string& data)** függvénynek.
- **parseValues(const std::string& data)** függvény feldolgozza a **loadInputFromString(std::string data)** -ban található map megengedett értékeit. Ha a lista *json* kiterjesztésű, nem engedjük meg a fájlon belüli szóközöket. Erre azért van szükség, mert ha ily módon adjuk meg a **monster** listát:
["     Fallen.json", "Zombie.json", "Zombie.json "],
akkor is feldolgozza az adott fájlhoz tartozó adatokat. Ennek segítésére van két lambdafüggvényünk, amely detektálja a szóközöket és a '"' karaktereket is.

### Game, PreparedGame
A két osztály közötti különbség, hogy a **PreparedGame** csak *prepared* módban működik. Ekkor egy *json* fájlon keresztül adjuk meg a szükséges adatokat (*markedmap*, hős, monster típusok) és a játék azonnal betöltődik és játszhatóvá válik. A sima **Game** osztály ennek az őse és itt találhatóak a játék futásáért felelős függvények.

### Map, MarkedMap
Ezen két osztály felel a pálya felépítésének tárolásáért. Tartalmazzák a szükséges koordinátákat, amelyek alapján eldönthető, hogy egy mező üres, fal, vagy foglalt -e. A **Map** a osztály egy továbbfejlesztett változata a **MarkedMap** osztály. Ez annyit jelent, hogy előbbi csak a falak és szabad mezők koordinátáit tartalmazza. Ezen felül a pálya méreteit is megadja. A **MarkedMap** örökli ezen tulajdonságokat, de képes olyan pályákat betölteni, amelyeken előre megvannak a hős és a szörnyek által foglalt területek is.

### Unit Test
A **unit_test** mappán belül a **unit_test.cpp** tartalmazza a teszteket a **Game**, a **JSON**, a **Map**, a **Character**, a **MarkedMap** és a **PreparedGame**, osztályokhoz.

### Dokumentáció:
https://teaching-projects.github.io/SZE-MOSZE-2020-GitCraft/