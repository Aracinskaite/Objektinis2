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

Atlikome analize priklausomai nuo kompiliatoriaus optimizavimo lygio. Rezultatus surašėme į lenteles, pateiktas žemiau.
**O1** :
|Tekstiniai failai| Nuskaitymo laikas| Dalijimas į dvi grupes| 'varkšiukai' įrašymas| 'galvočiai' įrašymas|
|-----------------|------------------|-----------------------|----------------------|---------------------|
|1000.txt|0.01 s.|0.00 s.|0.00 s.|0.00 s.|
|10000.txt|0.04 s.|0.01 s.|0.05 s.|0.03 s.|
|100000.txt|0.47 s.|0.12 s.|0.41 s.|0.33 s.|
|1000000.txt|5.50 s.|1.56 s.|4.34 s.|3.32 s.|
|10000000.txt|44.19 s.|21.18 s.|45.10 s.|32.42 s.|  

**O2** :
|Tekstiniai failai| Nuskaitymo laikas| Dalijimas į dvi grupes| 'varkšiukai' įrašymas| 'galvočiai' įrašymas|
|-----------------|------------------|-----------------------|----------------------|---------------------|
|1000.txt|0.00 s.|0.00 s.|0.01 s.|0.00 s.|
|10000.txt|0.05 s.|0.00 s.|0.05 s.|0.03 s.|
|100000.txt|0.40 s.|0.11 s.|0.39 s.|0.37 s.|
|1000000.txt|5.26 s.|1.56 s.|4.28 s.|3.17 s.|
|10000000.txt|43.38 s.|19.90 s.|45.74 s.|30.78 s.| 

**O3** :
|Tekstiniai failai| Nuskaitymo laikas| Dalijimas į dvi grupes| 'varkšiukai' įrašymas| 'galvočiai' įrašymas|
|-----------------|------------------|-----------------------|----------------------|---------------------|
|1000.txt|0.02 s.|0.00 s.|0.01 s.|0.00 s.|
|10000.txt|0.06 s.|0.00 s.|0.03 s.|0.03 s.|
|100000.txt|0.61 s.|0.14 s.|0.41 s.|0.32 s.|
|1000000.txt|5.11 s.|2.14 s.|4.37 s.|3.40 s.|
|10000000.txt|46.18 s.|20.30 s.|43.79 s.|31.21 s.| 


# v1.2
Savo parašytą programą išskaidžiau į keturi failus: ***studlib.h***, ***main.cpp***, ***stud.cpp*** ***timer.h***. **stud.cpp** yra aprašytos visos funkcijos (medianos, vidurkio skaičiavimas, atsitiktinai sugeneruoti skaičiai, ir  funkcijos iš main.cpp). **Mylib.h** yra sudėtos reikalingos bibliotekos, studento klasė su operatoriais, seteriais ir geteriais.

Šioje versijoje įdėjau *input* ir *output* operatorius, kurie įveda ir nuskaito studento vardą bei pavardę. Į operatoriau įterpiau tik juos, nes galėsiu pritaikyti visoms savo funkcijoms, kurios naudoja vardą ir pavardę.
Taip pat, pritaikiau *"Rule of three"*, kuri susideda iš destruktoriaus, kopijavimo konstruktoriaus ir kopijavimo priskyrimo operatoriaus. Nuotraukoje pateikiu, kaip mano programos kodas iškviečia destruktorių ir atspauzdina "Iškviestas destruktorius":

<img width="757" alt="Screenshot 2023-12-08 222638" src="https://github.com/Aracinskaite/Objektinis2/assets/144428697/8eb0b1fb-8f5d-4e60-af48-97c7f0343f40">

# v1.5
Savo parašytą programą išskaidžiau į keturi failus: ***studlib.h***, ***main.cpp***, ***stud.cpp*** ***timer.h***. **stud.cpp** yra aprašytos visos funkcijos (medianos, vidurkio skaičiavimas, atsitiktinai sugeneruoti skaičiai, ir  funkcijos iš main.cpp). **Mylib.h** yra sudėtos reikalingos bibliotekos, studento klasė su operatoriais, seteriais ir geteriais.

Savo programą papildžiau bazine (abstrakčia) klase pavadinimu **Zmogus**. Ją idėjau į savo *studlib.h* failą. *Zmogus* bazinė klasė yra protected kintamieji: vardas, pavardė. Taip pat ten yra jų geteriai ir seteriai, bet objektų kūrimas iš *Zmogus* klasės yra negalimas. Todėl kita mano klasė **Studentas** (ji yra išvestinė klasė iš Zmogus) sukuria juos.

Šioje nuotraukoje galime matyti, jog bazinė klasė *Zmogus* negali sukurti objektų:
<img width="691" alt="Screenshot 2023-12-15 002932" src="https://github.com/Aracinskaite/Objektinis2/assets/144428697/efef99e2-851b-4340-adfe-384f21be4884">


# v2.0

Savo parašytą programą išskaidžiau į keturi failus: ***studlib.h***, ***main.cpp***, ***stud.cpp*** ***timer.h***. **stud.cpp** yra aprašytos visos funkcijos (medianos, vidurkio skaičiavimas, atsitiktinai sugeneruoti skaičiai, ir  funkcijos iš main.cpp). **Mylib.h** yra sudėtos reikalingos bibliotekos, studento klasė su operatoriais, seteriais ir geteriais.

Taip pat, prie šios versijos pridėjau failą ***test.cpp***. Jame parašiau du testus, kurie tikrina ar mano funkcijos *vidurkiosk()* ir *medianossk()* veikia teisingai ir skaičiuojant galutinį balą su jomis gaunamas teisingas atsakymas. Testai yra nerealizuoti, bet jeigu juos realizuosime, tai paleidus juos turėtu išvesti ar su mano funkcijomis gaunamas teisingas rezultatas, kuris buvo nurodytas teste.

Dar šiai versijai sukūriau *doxygen* html failą, kurį galime rasti šioje versijoje v2.0 atsidarę aplanką html ir jame suradę failą index.html .

