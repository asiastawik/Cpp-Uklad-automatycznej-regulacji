# Projekt 3: Układ automatycznej regulacji

## Opis projektu

Tematem projektu jest sterowanie temperaturą w wirtualnym pomieszczeniu, które oddaje ciepło do otoczenia o określonej temperaturze. Celem jest implementacja układu automatycznej regulacji (UAR), który na podstawie pomiarów aktualnej temperatury w pomieszczeniu, steruje grzejnikiem, aby utrzymać temperaturę jak najbliżej zadanej wartości.

## Spis treści
- [Etap 1: Symulacja UAR](#etap-1-symulacja-uar)
- [Etap 2: Sterowanie procesem](#etap-2-sterowanie-procesem)
- [Etap 3: Wyjątki](#etap-3-wyj%C4%85tki)
- [Instalacja](#instalacja)
- [Przykładowe użycie](#przyk%C5%82adowe-u%C5%BCycie)
- [Autorzy](#autorzy)

## Etap 1: Symulacja UAR

W pierwszym etapie projektu skoncentrujemy się na symulacji działania układu dynamicznego:

1. **Implementacja klasy `Symulacja`**:
   - Metoda `iteracja` wykonuje pojedynczy krok symulacji przyjmując czas próbkowania (`Δ𝑡`).
   - Metoda `przebieg` umożliwia wykonanie określonej liczby iteracji.
   - W każdej iteracji aktualizowany jest stan obiektu `Pomieszczenie`, a jego temperatura jest drukowana na konsoli.

2. **Implementacja klasy `Grzejnik`**:
   - Klasa ta posiada atrybuty: moc nominalna oraz aktualny poziom mocy.
   - Wprowadzone zabezpieczenia uniemożliwiają ustawienie poziomu mocy powyżej 100%.

3. **Logowanie danych**:
   - Klasa `Symulacja` zostanie wzbogacona o funkcję logowania przebiegów (temperatura, czas, moc wyjściowa) za pomocą szablonu `std::vector`.
   - Dodana zostanie również metoda `zapis`, umożliwiająca eksport danych do pliku CSV.

## Etap 2: Sterowanie procesem

W drugim etapie projektu zaimplementujemy algorytmy sterowania:

1. **Regulator dwupołożeniowy (`RegulatorBB`)**:
   - Implementacja regulatora, który generuje dwa sygnały: 0 (brak grzania) i 1 (pełne grzanie).
   
2. **Regulator PID (`RegulatorPID`)**:
   - Klasa ta oblicza sygnał sterujący na podstawie różnicy pomiędzy temperaturą zadaną a aktualną.
   - Wzór na sygnał sterujący uwzględnia trzy składowe: proporcjonalną, całkującą i różniczkującą.

3. **Polimorfizm**:
   - Umożliwienie użycia różnych typów regulatorów w sposób polimorficzny.

4. **Menu dla użytkownika**:
   - Umożliwienie wyboru rodzaju regulatora przed rozpoczęciem symulacji.

5. **Agregacja regulatorów z obiektami `Pomieszczenie` i `Grzejnik`**.

## Etap 3: Wyjątki

W ostatnim etapie projektu dodamy obsługę wyjątków:

1. **Zabezpieczenia przed nieprawidłowym działaniem**:
   - Wykrywanie prób uruchomienia regulatora bez wcześniejszego skonfigurowania obiektów `Pomieszczenie` i `Grzejnik`.

2. **Inne potencjalne sytuacje do zabezpieczenia**:
   - Określenie dodatkowych scenariuszy, które mogą prowadzić do błędów.

3. **Własne klasy wyjątków**.
