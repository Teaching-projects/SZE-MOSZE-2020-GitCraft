# Tagok

| Név | Github azonosito  | Javasolt relatív érdemjegy | Becsült óra | Indoklás  | 
| --- | ---- | --- | ------------------ | --------- |
| Bézi Patrik | @Patorik | 4 | 100-110 | Leginkább  a JSON parseren dolgoztam, valamint a unit testek egy részét én írtam. Ezek jól is működnek, ellátják a feladatukat. Mindemellett segítettem debuggolni, valamint a github használatát elsajátítani a többieknek. Részt vettem a dokumentáció egy részében, illetve segítettem a GHA-k és a docker konfigurálásában is. |
| Pokorni Dávid | @davidpokorni | 4 | 100-110 | A karakterek működését én valósítottam meg, továbbá a Game,Map,PreparedGame, MarkedMap osztályok megvalósításában is aktívan vettem részt. Emellett a dokumentációt valósítottam meg, illetve a unit tesztek másik részét.Aktívan részt vettem a GHA beállításában és a yml fájlok elkészítésében. Részt vettem a Makefile kiegészítésben a későbbi feladatok folyamán. Segítettem a docker bekonfigurálásában, illetve a debugolásban. |
| Zelles Tamás | @ztamas97 | 4 | 100-110 | Részt vettem a kódolás legnagyobb részében(Game, MarkedMap, Map,  Monster, Hero, PreparedGame, LightRadius, Levelup,...), a Makefilet, valamint a GHA-hoz kapcsolodó megoldások(yml, iotest, cppcheck, valgrind) nagy részét én kiviteleztem. A docker fájlok elkészítésében is aktívan részt vettem. A dokumentálásban, valamint a többi eszköz használatában pedig igyekeztem a többieket támogatni felmerülő hibák esetén, debuggolásnál.  |

# Feladat összegzése
A csapattagok összességében nagyon jó összhangban voltak egymással. Ha valaki valamivel lemaradt, igyekeztünk a másik segítségére lenni, hogy a lemaradását behozza.
Többször sikerült bizonyos dolgokat közösen megoldani, aminek szintén pozitív hatása volt. Ilyenkor általában **Live Share**-t használtunk.

# Videók

 - [Gameplay](/videos/gameplay.mp4)
 - [CodeBaseDefense](/videos/codebasedefense.mp4)

# Befejezett feladatok

| Feladat | Merge ideje a határidóhöz (nap) | Change request körök | Reviewer | 
| ------- | ------------------------------- | -------------------- | -------- |
| Feladat 1 | +3 | 1 | @wajzy| 
| Feladat 2 | 0 | 1 | @hegyhati |
| jsonparser | +2 | 1 | @wajzy |
| levelup | -1 | 1 | @oliverosz |
| attackspeed | +2 | 0 | @vizvezetek |
| documentation | -1 | 0 | @cadboleny / @dobaybalazs |
| unittest | -1 | 0 | @cadboleny / @dobaybalazs, @tupoljev |
| makefile | -4 | 1 | @hegyhati |
| refactor | 0 | 0 | @hegyhati |
| docker | 0 | 0 | @hegyhati |
| parserupgrade | Merge: 12.04. | 0 | @cadboleny / @dobaybalazs, @tupoljev |
| gamemap(map,defense,game,damage) | Merge: 12.06. | 0 | @cadboleny / @dobaybalazs, @tupoljev |
| finalround(markedmap, preparedgame, light radius) | Merge: 12.08. | 0 | @cadboleny / @dobaybalazs, @tupoljev |
| renderer | nem készült el teljesen | - | - |

# Unit tesztek

| Osztály | Publikus metódusok száma | Unit tesztelt metódusok száma | Unit tesztek száma |
| --- | --- | --- | --- |
| `Character` | 10 | 7 | 7 |
| `Hero` | 8 | 0 | 3 | 
| `Monster` | 4 | 0 | 0 | 
| `JSON` | 8 | 4 | 8 | 
| `Map` | 7 | 4 | 3 | 
| `Game` | 7 | 2 | 6 | 
| `PreparedGame` | 1 | 0 | 1 | 
| `MarkedMap` | 2 | 0 | 1 | 

# Kód dokumentáció

| Teljesen dokumentált osztályok | Részben dokumentált osztályok | Nem dokumentált osztályok |
| --- | --- | --- | 
| `Character` |  | ... | 
| `Hero` | ... | ... |  
| `Monster` | ... | ... |  
| `JSON` | ... | ... |
| `Game` | ... | ... |
| `Map` | ... | ... | 
| `PreparedGame` | ... | ... | 
| `MarkedGame` | ... | ... | 


# Mindenféle számok

 - Összes cpp kódsor : 973/1205
 - Egyéb kódsor: Make(62), Doxyfile(271), Shellscript(43), yml(85)
 - cppcheck
   - warning :0
   - style : x
   - performance : 0
   - unusedFunction : 0
   - missingInclude : 0
 
# Implicit megtanult dolgok
Olyanok, amik nem a tárgy anyaga, de muszáj/hasznos volt elsajátítani:
 - alapvető shell/python scripting
 - std::variant
 - varian_cast
 - regexp
 - unit_test
 - Docker
 - Makefile
 - GHA
 - Visual Studio Code -> Liveshare

# Feedback (optional)
 
- Melyik részt találtátok a leghasznosabbnak, miért? Makefile készítése. Gyors fordítási lehetőség.
- Használtátok-e az itt megszerzett dolgokat esetleg közben máskor: Github-ot.
- Online videókról: Összességében jók voltak, bár előfordult, hogy nehezen hallható volt egy-két előadás.