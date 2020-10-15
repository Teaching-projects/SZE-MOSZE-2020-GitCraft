SZE-MOSZE-2020-GitCraft
==========================

###  Alap dolgok:
#### Character objektumok képesek harcolni
#### A main parancssorból kapja az argumentumokat, amelyeket felhasználva szimulál egy harcot.

## Leírás
Az játék működését egyelőre a Character osztály és a main biztosítják. A kérésnek megfelelően, a szoftver parancssorból kapja az argumentumokat és ez alapján lebonyolít egy harcszimulációt. Argumentumok nélkül a program hibát fog dobni és leáll. A megadott argumentumok ".json" kiterjesztésű fájlnevek legyenek. Megadáskor elegendő a fájl nevét és a kiterjesztést megadni. Például: Ork.json Troll.json. Ha a fájl nem létezik a program egy exceptiont fog dobni, hogy nem lehetséges a fájl megnyitása.

### Character
Minden karakter létrehozásakor rendelkezni fog egy névvel, kezdő HP-val és sebzéssel. Mivel ezek az osztály **private** tulajdonságaihoz tartoznak, ezért egy-egy **gettert** hoztunk létre, hogy a későbbiekben másik osztályban is kiolvashassuk ezen tulajdonságokat. További függvények:
* Az osztály rendelkezik egy **isAlive()** függvénnyel, amely meghatározza, hogy az adott karakter életben van -e. Ez akkor nem lesz igaz, ha a HP-ja 0 lesz.
* Az overloaded << operátor segítségével kiíratjuk a karakter tulajdonságait a mintában megadott módon.
* Az **attack(Character &c)** teszi lehetővé egy másik Character objektum megtámadását. Ez egyelőre csak a sebzés alapján módosítja az ellenfél HP-ját.
* A **parseUnit(std::string charSheetName)** teszi lehetővé az argumentumként kapott fájlokból való program futtatást. Ez úgy működik, hogy ha létező fájlnevet kap, akkor **loadUnit(ifstream &jsonFile)** hívódik meg, más esetben megpróbálkozik a program a **loadUnit(std::string data)** függvény hívásával.

### Json Parser
A **Character** osztály statikus **parseUnit(Character &C, std::string charSheetName)** függvénye a **Parser** osztály függvényeit használja. Ebből kettő van, ugyanazzal a névvel, de más argumentumokkal:
- A **loadUnit(std::string data)** bemenetként egy *stringet* vár, amelyből folyamatosan olvassa be a karakter tulajdonságának nevét (kulcs) és annak értékét, miközben folyamatosan "csonkítja" az eredeti *stringet*. Utóbbi lépéssel sikerült biztosítani, hogy a *whitespacek* ne zavarjanak be, végül egy map-et ad vissza, amelyben a *key* és az *value* is *string* típusú. A függvény eleje ellenőrzi, hogy az adott *string* nem véletlenül egy *json* fájl neve. Ha az, akkor rekurziós módszerrel a másik függvény értéke lesz visszaadva. A program elvárja, hogy a *kulcsok* és az *értékek* között egy **':'** karakter legyen, különben *errort* fog dobni.
- A **loadUnit(std::istream &jsonFile)** egy *istreamet* vár argumentumként. Ha például ez egy *fstream*, akkor abból minden sor ki lesz olvasva, amelyeket beleírunk egy stringbe, majd rekurzív módon visszatérítési értékként meghívjuk a **loadUnit(std::string data)** függvényt.

### Unit Test
A **unit_test** mappán belül a **test_parser.cpp** tartalmazza a teszteket mind a három meglévő *json* fájlhoz. Mindhárom egy *expected* map tartalmát veti össze a *json* fájlokból beolvasott *output* map tartalmával a következő módon:
- A **file_name** teszt ellenőrzi a **loadUnit(std::istream &jsonFile)** működését. Ez beolvassa a *Troll.json* adatait.
- A **file_istream** teszt ellenőrzi, hogy ha a **loadUnit(std::string data)** egy *json* fájl nevét kapja meg, akkor is helyesen olvassa -e be az *Elf.json* fájlban található adatokat.
- A **file_string** megnyitja az *Orc.json* fájlt, beolvassa egy *stringbe* a sorait, majd a kapott *stringet* átadja a **loadUnit(std::string data)** függvénynek, ahol a **Json Parser** bekezdésben leírtak alapján beolvassa az adatokat.