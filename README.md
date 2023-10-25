# v0.1
1. Savo parašytą programą išskaidžiau į tris failus: ***mylib.h***, ***main.cpp***, ***mylib.cpp***. **Mylib.cpp** yra aprašytos visos funkcijos (medianos, vidurkio skaičiavimas, atsitiktinai sugeneruoti skaičiai, ir dvi funkcijos iš main.cpp). **Mylib.h** yra sudėtos reikalingos bibliotekos, studento struktūra ir deklaruojamos dvi svarbiausios funkcijos, kurios yra naudojamos pagrindiniame faile **main.cpp**.
2. Iškvietus failą pirmiausia galime pasirinkti ar norime įvesti naujus studentus ir atlikti veiksmus su jais ( funkcija *mano_funkcija()*), ar nuskaityti duomenis iš tekstinio failo (funkcija *mano_funkcija1()*). Programa prašo naudotojo įvesti 1 arba 2, o neteisingai įvedus, ji grąžina klaidą ir vėl klausia naudotojo pasirinkimo.
3. Jei pasirinkome pirmoje dalyje 1, toliau bus prašoma įvesti kiek bus studentų. Parašius ne skaičių bus išvedama klaida ir prašoma tai padaryti dar kartą. Ciklas pasibaigs įvedus int tipo simbolį. Tada reikės suvesti vardą ir pavardę, kai ateis pažymių eilė galėsime pasirinkti ar norime juos suvesti patys, paraše 1, ar sugeneruoti įraše 2. Jei nusprendėme pažymius rašyti , tai galėsi pabaigti įvedę -1. Suvedus, vėl galime pasirinkti, kaip norime skaičiuoti galutinį balą, pagal vidurkį ar medianą. Visa informacija yra išspausdinama į lentelę. Įvedimo vietose bus ieškmoma klaidų, tokių kaip: įrašėme ne skaičių arba ne 1 ir ne 2. Klaida bus spausdinama iki tol kol pasirinksime 1 ar 2.
4. Jeigu pradžioje pasirinkome 2, bus vykdoma funkcija *mano_funkcija1()*. Pirmiausia bus prašoma įvesti tekstinio failo pavadinimą, kuris turi būti tame pačiame aplanke, kaip ir mūsų programa. Jei kartais nepavyktų failo nuskaityti apie tai bus pranešta juodame lange. Sėkmingai išsaugojus duomenys, jie bus išvedami į lentelę.


# v0.2

Savo programą išskaidžiau į keturis failus: **main.cpp**, **mylib.cpp**, **mylib.h, **timer.h** .
**Main.cpp** pradžioje įvedus skaičių 3, galėsime sugeneruoti failus ir atlikus veiksmus su jais, paskaičiuoti vidutinį laiką. Sukūriau vektorių pavadinimu sąrašas, su kurio skaičiais visa programa vėliau ir dirba. Pirmiausia sugeneruoja atsitiktinai skaičius ir įrašo į failą su funkcija *studFailas()*. Tada galima įvesti skaičių, kiek kartu norėsime atlikti laiko testavimą. Iš sugeneruoto failo informacija yra nuskaitoma ir išsaugojama į vektorių studentas, tai vyksta su funkcija *nuskaitymas()*. Vėliau iškviečiu funkcija *surusiuoti()*, kuri studentus suskirsto į du atskirus vektorius pagal jų galutinį balą vidurkį/medianą. Galiausiai du kartus yra vykdoma funkciją *isvedimas()*, kad butu įrašyti vargšiukai ir galvočiai. Visus šiuos veiksmus kartojame tiek kartų, kiek įvedėme laiko testavimo skaičių. Pabaigoje iškviečiame funkcija *isvedimasLaiko()*, kuri paskaičiuoja vidutinį darbo laiką su tam tikra funkcija. Visa tai yra įdėta į for cikla ir vykdoma su 1000, 10000, 100000, 1000000, 10000000.

Laiko skaičiavimas:
2. **Timer1** - paskaičiuoja funkcijos *nuskaitymas()* vidutinį darbo laiką.
3. **Timer2** - paskaičiuoja funkcijos *surusiuoti()* vidutinį darbo laiką.
4. **Timer3** - paskaičiuoja funkcijos *isvedimas()*  vidutinį darbo laiką (vektoriaus vargsiukai išvedimas į failą).
5. **Timer4** - paskaičiuoja funkcijos *isvedimas()* vidutinį  darbo laiką (vektoriaus galvociai išvedimas į failą).
6. **Timer5** - paskaičiuoja vidutini darbo laiką nuo funkcijos *studFailas()* iki paskutinio *isvedimas()*.

<img width="600" alt="Screenshot 2023-10-25 125942" src="https://github.com/Aracinskaite/Objektinis1/assets/144428697/84fbd3d9-bfbb-4a84-af85-b7f108aea54d">




