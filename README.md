# v0.1
1. Savo parašytą programą išskaidžiau į tris failus: ***mylib.h***, ***main.cpp***, ***mylib.cpp***. **Mylib.cpp** yra aprašytos visos funkcijos (medianos, vidurkio skaičiavimas, atsitiktinai sugeneruoti skaičiai, ir dvi funkcijos iš main.cpp). **Mylib.h** yra sudėtos reikalingos bibliotekos, studento struktūra ir deklaruojamos dvi svarbiausios funkcijos, kurios yra naudojamos pagrindiniame faile **main.cpp**.
2. Iškvietus failą pirmiausia galime pasirinkti ar norime įvesti naujus studentus ir atlikti veiksmus su jais ( funkcija *mano_funkcija()*), ar nuskaityti duomenis iš tekstinio failo (funkcija *mano_funkcija1()*). Programa prašo naudotojo įvesti 1 arba 2, o neteisingai įvedus, ji grąžina klaidą ir vėl klausia naudotojo pasirinkimo.
3. Jei pasirinkome pirmoje dalyje 1, toliau bus prašoma įvesti kiek bus studentų. Parašius ne skaičių bus išvedama klaida ir prašoma tai padaryti dar kartą. Ciklas pasibaigs įvedus int tipo simbolį. Tada reikės suvesti vardą ir pavardę, kai ateis pažymių eilė galėsime pasirinkti ar norime juos suvesti patys, paraše 1, ar sugeneruoti įraše 2. Jei nusprendėme pažymius rašyti , tai galėsi pabaigti įvedę -1. Suvedus, vėl galime pasirinkti, kaip norime skaičiuoti galutinį balą, pagal vidurkį ar medianą. Visa informacija yra išspausdinama į lentelę. Įvedimo vietose bus ieškmoma klaidų, tokių kaip: įrašėme ne skaičių arba ne 1 ir ne 2. Klaida bus spausdinama iki tol kol pasirinksime 1 ar 2.
4. Jeigu pradžioje pasirinkome 2, bus vykdoma funkcija *mano_funkcija1()*. Pirmiausia bus prašoma įvesti tekstinio failo pavadinimą, kuris turi būti tame pačiame aplanke, kaip ir mūsų programa. Jei kartais nepavyktų failo nuskaityti apie tai bus pranešta juodame lange. Sėkmingai išsaugojus duomenys, jie bus išvedami į lentelę.


# v0.2

Savo programą išskaidžiau į keturis failus: **main.cpp**, **mylib.cpp**, **mylib.h, **timer.h** .
**Main.cpp** pradžioje įvedus skaičių 3, galėsime sugeneruoti failus ir atlikus veiksmus su jais, paskaičiuoti vidutinį laiką. Sukūriau vektorių pavadinimu sąrašas, su kurio skaičiais visa programa vėliau ir dirba. Pirmiausia sugeneruoja atsitiktinai skaičius ir įrašo į failą su funkcija *studFailas()*. Tada galima įvesti skaičių, kiek kartu norėsime atlikti laiko testavimą. Iš sugeneruoto failo informacija yra nuskaitoma ir išsaugojama į vektorių studentas, tai vyksta su funkcija *nuskaitymas()*. Vėliau iškviečiu funkcija *surusiuoti()*, kuri studentus suskirsto į du atskirus vektorius pagal jų galutinį balą vidurkį/medianą. Galiausiai du kartus yra vykdoma funkciją *isvedimas()*, kad butu įrašyti vargšiukai ir galvočiai. Visus šiuos veiksmus kartojame tiek kartų, kiek įvedėme laiko testavimo skaičių. Pabaigoje iškviečiame funkcija *isvedimasLaiko()*, kuri paskaičiuoja vidutinį darbo laiką su tam tikra funkcija. Visa tai yra įdėta į for cikla ir vykdoma su 1000, 10000, 100000, 1000000, 10000000.

Laiko skaičiavimas:
1. **Timer1** - paskaičiuoja funkcijos *nuskaitymas()* vidutinį darbo laiką.
2. **Timer2** - paskaičiuoja funkcijos *surusiuoti()* vidutinį darbo laiką.
3. **Timer3** - paskaičiuoja funkcijos *isvedimas()*  vidutinį darbo laiką (vektoriaus vargsiukai išvedimas į failą).
4. **Timer4** - paskaičiuoja funkcijos *isvedimas()* vidutinį  darbo laiką (vektoriaus galvociai išvedimas į failą).
5. **Timer5** - paskaičiuoja vidutini darbo laiką nuo funkcijos *studFailas()* iki paskutinio *isvedimas()*.

<img width="600" alt="Screenshot 2023-10-25 125942" src="https://github.com/Aracinskaite/Objektinis1/assets/144428697/84fbd3d9-bfbb-4a84-af85-b7f108aea54d">



# v0.3

*v0.3* kodas išlieka panašus  į *v0.2*, tik vietoje **vector<studentas>** pakeičiu į **list<studentas>** . Laiko matavimimai beveik nesikeičia. Matytumėme didesnius laiko skirtumus, jeigu reikėtų įterpti arba ištrinti studentus, tada *list* veikimo greitis būtų mažesnis nei *vector*.
Taip pat prie kodo, kai reikia įvesti studentus arba juos nuskaityti ir išvesti į konsole, pridėjau kiekvieno studento adresą.

Laiko skaičiavimas:
1. **Timer1** - paskaičiuoja funkcijos *nuskaitymas()* vidutinį darbo laiką.
2. **Timer2** - paskaičiuoja funkcijos *surusiuoti()* vidutinį darbo laiką.
3. **Timer3** - paskaičiuoja funkcijos *isvedimas()*  vidutinį darbo laiką (vektoriaus vargsiukai išvedimas į failą).
4. **Timer4** - paskaičiuoja funkcijos *isvedimas()* vidutinį  darbo laiką (vektoriaus galvociai išvedimas į failą).
5. **Timer5** - paskaičiuoja vidutini darbo laiką nuo funkcijos *studFailas()* iki paskutinio *isvedimas()*.


list:                                                                                  
<img width="437" alt="Screenshot 2023-10-27 102952" src="https://github.com/Aracinskaite/Objektinis1/assets/144428697/456b96d0-813a-4760-8b97-2cd80081979a">


vector:

<img width="441" alt="Screenshot 2023-10-27 104626" src="https://github.com/Aracinskaite/Objektinis1/assets/144428697/edf12051-6ff3-4e16-89ab-a8464b5d7873">




# v1.0

*v1.0* turime tris strategijas, kiekviena iš jų skirasi savo konteinerio (***vector*** arba ***list***) dalijimu į dvi grupes. Todėl aptarsiu kiekvienos strategijos dalijimo į tas grupes veikimą.
Apie programos veikimo principa skaityti *v0.1*, *v0.2* ir *v0.3* .

**1.** **Strategija.** Iš lentelės matome, kad konteinerių laikai nelabai skiriasi.
   |Tekstiniai failai|Skaidymo laikas į du koneteinersiu (vector)|Skaidymo laikas į du koneteinersiu (list)|
   |---------------|---------------|---------------|
   |1000.txt|0.00 s.|0.00 s.|
   |10000.txt|0.02 s.|0.02 s.|
   |100000.txt|0.28 s.|0.21 s.|
   |1000000.txt|2.94 s.|2.10 s.|
   |10000000.txt|31.94 s.|21.67 s.|

**2. Strategija.** Konteineris list veikia žymiai greičiau, nes vector konteineris yra greitas tik tada, kai norime pasiekti bet kokį elementą, tačiau dirba lėtai jei norime įterpti arba ištrinti elementą. (Dėl vector lėto veikimo su šita strategija nebesulaukiau kol suskirstis du paskutinius failus).
   |Tekstiniai failai|Skaidymo laikas į du koneteinersiu (vector)|Skaidymo laikas į du koneteinersiu (list)|
   |---------------|---------------|---------------|
   |1000.txt|0.03 s.|0.00 s.|
   |10000.txt|3.04 s.|0.00 s.|
   |100000.txt|306.26 s.|0.09 s.|
   |1000000.txt|...|1.34 s.|
   |10000000.txt|...|18.14 s.|

**3. Strategija.** Šiai strategijai naudojau vector programą iš 1 strategijos, nes ji veikė greičiau nei 2. Iš pasiūlitų algortimu panaudojau : partition, copy. Lentelėje pateikiau palyginimą su panaudotais algoritmais ir su programa iš 1 strategijos, kad galėtume pažiūrėti ar programos veikimas pagreitėjo. Matome, kad didėjant failo dydžiui veikimo greitis vis labiau skiriasi.
   |Tekstiniai failai|Skaidymo laikas į du koneteinersiu (iš 1 stra.)|Skaidymo laikas į du koneteinersiu (su algoritmais)|
   |---------------|---------------|---------------|
   |1000.txt|0.00 s.|0.00 s.|
   |10000.txt|0.02 s.|0.02 s.|
   |100000.txt|0.28 s.|0.17 s.|
   |1000000.txt|2.94 s.|2.06 s.|
   |10000000.txt|31.94 s.|24.47 s.|   


***Cmake naudojimosi instrukcija:***
1. Parsisiunčiame tekstinį failą *CMakeLists.txt*, aplankus *src*, *Include* ir *RUNfile.bat* .
2. Parsiųstus failus sukeliama į vieną aplanką.
3. Paspaudus ant *RUNfile.bat* programa pasileidžia ir galite su ja dirbti.




# v1.1
Iš struktūros į klasę pakeičiau programą iš v1.0, 2 strategijos  (koneteineris - list). Apačioje pateikta lentelės, kuri palygina klasės ir struktūros veikimo geičius.

Struktūros:
|Tekstiniai failai| Nuskaitymo laikas| Dalijimas į dvi grupes| 'varkšiukai' įrašymas| 'galvočiai' įrašymas|
|-----------------|------------------|-----------------------|----------------------|---------------------|
|1000.txt|0.02 s.|0.00 s.|0.01 s.|0.00 s.|
|10000.txt|0.04 s.|0.00 s.|0.04 s.|0.02 s.|
|100000.txt|0.39 s.|0.09 s.|0.37 s.|0.23 s.|
|1000000.txt|4.85 s.|1.34 s.|3.66 s.|2.54 s.|
|10000000.txt|50.22 s.|18.14 s.| 37.29 s.|34.64 s.|  

Klasės:
|Tekstiniai failai| Nuskaitymo laikas| Dalijimas į dvi grupes| 'varkšiukai' įrašymas| 'galvočiai' įrašymas|
|-----------------|------------------|-----------------------|----------------------|---------------------|
|1000.txt|0.00 s.|0.00 s.|0.02 s.|0.00 s.|
|10000.txt|0.06 s.|0.02 s.|0.03 s.|0.05 s.|
|100000.txt|0.52 s.|0.13 s.|0.43 s.|0.35 s.|
|1000000.txt|5.06 s.|1.60 s.|4.26 s.|3.12 s.|
|10000000.txt|43.23 s.|20.29 s.|43.35 s.|30.84 s.|  

Klasė su **O1** :
|Tekstiniai failai| Nuskaitymo laikas| Dalijimas į dvi grupes| 'varkšiukai' įrašymas| 'galvočiai' įrašymas|
|-----------------|------------------|-----------------------|----------------------|---------------------|
|1000.txt|0.01 s.|0.00 s.|0.00 s.|0.00 s.|
|10000.txt|0.04 s.|0.01 s.|0.05 s.|0.03 s.|
|100000.txt|0.47 s.|0.12 s.|0.41 s.|0.33 s.|
|1000000.txt|5.50 s.|1.56 s.|4.34 s.|3.32 s.|
|10000000.txt|44.19 s.|21.18 s.|45.10 s.|32.42 s.|  
Klasė su **O2** :
|Tekstiniai failai| Nuskaitymo laikas| Dalijimas į dvi grupes| 'varkšiukai' įrašymas| 'galvočiai' įrašymas|
|-----------------|------------------|-----------------------|----------------------|---------------------|
|1000.txt|0.00 s.|0.00 s.|0.01 s.|0.00 s.|
|10000.txt|0.05 s.|0.00 s.|0.05 s.|0.03 s.|
|100000.txt|0.40 s.|0.11 s.|0.39 s.|0.37 s.|
|1000000.txt|5.26 s.|1.56 s.|4.28 s.|3.17 s.|
|10000000.txt|43.38 s.|19.90 s.|45.74 s.|30.78 s.| 
Klasė su **O3** :
|Tekstiniai failai| Nuskaitymo laikas| Dalijimas į dvi grupes| 'varkšiukai' įrašymas| 'galvočiai' įrašymas|
|-----------------|------------------|-----------------------|----------------------|---------------------|
|1000.txt|0.02 s.|0.00 s.|0.01 s.|0.00 s.|
|10000.txt|0.06 s.|0.00 s.|0.03 s.|0.03 s.|
|100000.txt|0.61 s.|0.14 s.|0.41 s.|0.32 s.|
|1000000.txt|5.11 s.|2.14 s.|4.37 s.|3.40 s.|
|10000000.txt|46.18 s.|20.30 s.|43.79 s.|31.21 s.| 




 

