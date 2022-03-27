# palindrom
Wprowadzenie

Gra Palindrom jest rozgrywana za pomocą pionów na 64-polowej planszy podzielonej na kolumny, od a do h, oraz wiersze.

W grze bierze udział dwóch graczy, nazywanych Pierwszym i Drugim. Każdy gracz ma swój rodzaj piona.

Na początku gry plansza jest pusta. Zaczyna gracz Pierwszy.

Gracze, na przemian, wykonują ruch, kładąc swój pion na polu planszy. Pion jest umieszczany w wybranej przez gracza kolumnie, w jej pierwszym wolnym polu, licząc od dołu planszy.

Gracz wygrywa, jeśli swoim ruchem zbudował palindrom z pięciu pionów na kolejnych polach tego samego wiersza, kolumny lub przekątnej.
Polecenie

Napisz program umożliwiający grę w Palindrom dwóm graczom.

Program, w pętli:

    pisze diagram aktualnego stanu planszy i wskazuje, który gracz ma wykonać ruch;

    próbuje wczytać polecenie gracza;

    jeśli się nie udało, bo dane się skończyły, kończy pracę;

    jeśli wczytał polecenie błędne, ignoruje je;

    jeśli wczytał polecenie wykonania ruchu, wykonuje je;

    jeśli wczytał polecenie przerwania gry, kończy pracę.

Pętla kończy się, gdy:

    skończą się dane, lub

    program dostanie polecenie przerwania gry, lub

    jeden z graczy wygra.

Jeśli jeden z graczy wygra, program, na zakończenie pracy, pisze diagram końcowego stanu planszy i informuje, kto wygrał.
Postać danych

Na wejściu programu są polecenia graczy. Każde polecenie zajmuje jeden wiersz.

Jedynym znakiem w wierszu polecenia wykonania ruchu jest mała litera od a do h, będąca nazwą kolumny, w której gracz chce umieścić pion.

Polecenie jest poprawne, jeśli we wskazanej kolumnie jest wolne pole.

Jedynym znakiem w wierszu polecenia przerwania gry jest =.

Wiersz, który nie jest poprawnym poleceniem wykonania ruchu lub przerwania gry, jest poleceniem błędnym.

Wolno założyć, że każde polecenie użytkownika, także ostatnie, jest w wierszu poprawnie zakończonym reprezentacją końca wiersza \n.
Postać wyniku

Na wyjściu programu jest ciąg diagramów planszy. Po każdym diagramie jest wiersz z informacją, kto ma wykonać ruch lub kto wygrał.

Diagram opisuje pole planszy za pomocą znaku

    - gdy pole jest puste;

    1 gdy na polu jest pion gracza Pierwszego;

    2 gdy na polu jest pion gracza Drugiego.

Przed każdym znakiem opisującym pole jest spacja.

Opisy pól są pogrupowane w wiersze, a w wierszu uporządkowane w kolejności kolumn od a do h.

Po ostatnim wierszu pól diagramu jest wiersz z nazwami kolumn. Każda z nich jest poprzedzona spacją.

Informacja o tym, kto ma wykonać ruch, ma postać wiersza z nazwą gracza, 1 lub 2, po której jest dwukropek.

Informacja o tym, kto wygrał, ma postać wiersza z nazwą gracza, 1 lub 2, po której jest kropka.

W tekście wynikowym programu nie ma żadnych znaków, które nie zostały wymienione powyżej.

Każdy wypisywany wiersz, także ostatni, jest zakończony końcem wiersza \n.
