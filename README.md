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
