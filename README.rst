###########################
Taschenrechner & Adressbuch
###########################
==============
Taschenrechner
==============
~~~~~~~~~~~~~~~~
Aufgabenstellung
~~~~~~~~~~~~~~~~
Es soll ein einfacher Taschenrechner implementiert werden, welche die Operationen (Add, Sub, Mul, Div) in einem FP-Array speichert.
Die Operations-Header:

.. code:: c

    int addition(int,int);
    int subtraktion(int,int);
    int division(int,int);
    int multiplikation(int,int);

~~~~~~~~~~~~~~~~~~~~~~
Ablauf Implementierung
~~~~~~~~~~~~~~~~~~~~~~
#. Definition der Funktions-Prototypen
#. Implementation der Operations-Methoden (Addition, Substraktion, Multiplikation, Division)
#. Anlegen des Funktions-Pointer Arrays und Zuweisung zu den Funktionen
#. Implmentation des Auswahlmenüs und auslesen der Benutzer Eingaben
#. Testen des Programmes

~~~~~~~~~~~~~~~~~
Aufwandsschätzung
~~~~~~~~~~~~~~~~~
+-------------------------------+-------------------+-------------+
|            Schritt            |   Geplante Zeit   |   Aufwand   |
+===============================+===================+=============+
| Prototypen                    |    00:02:00h      |   Gering    |
+-------------------------------+-------------------+-------------+
| Implementation Operationen    |    00:02:00h      |   Gering    |
+-------------------------------+-------------------+-------------+
| Anlegen Funktions-ptr Array   |    00:01:00h      |   Gering    |
+-------------------------------+-------------------+-------------+
| Implementation Menü&Eingaben  |    00:15:00h      |   Gering    |
+-------------------------------+-------------------+-------------+
| Testen                        |    00:05:00h      |   Gering    |
+-------------------------------+-------------------+-------------+

~~~~~~~~~~~~~~~~
Zeitaufzeichnung
~~~~~~~~~~~~~~~~
+-------------------------------+---------------+---------------+--------------+--------------+
|            Schritt            |     Datum     |     Start     |     Ende     |     Zeit     |
+===============================+===============+===============+==============+==============+
| Prototypen                    |  18. 10 2013  |   09:50:00    |   09:51:40   |  00:01:40h   |
+-------------------------------+---------------+---------------+--------------+--------------+
| Implementation Operationen    |  18. 10 2013  |   09:52:00    |   09:53:58   |  00:01:58h   |
+-------------------------------+---------------+---------------+--------------+--------------+
| Anlegen Funktions-ptr Array   |  18. 10 2013  |   09:55:00    |   09:56:31   |  00:01:31h   |
+-------------------------------+---------------+---------------+--------------+--------------+
| Implementation Menü&Eingaben  |  18. 10 2013  |   10:02:00    |   10:05:43   |  00:03:43h   |
+-------------------------------+---------------+---------------+--------------+--------------+
| Testen                        |  18. 10 2013  |   10:05:50    |   10:06:20   |  00:01:30h   |
+-------------------------------+---------------+---------------+--------------+--------------+
| Implementation Menü&Eingaben  |  18. 10 2013  |   10:07:20    |   10:16:30   |  00:09:10h   |
+-------------------------------+---------------+---------------+--------------+--------------+
| Testen                        |  18. 10 2013  |   10:16:41    |   10:18:05   |  00:01:24h   |
+-------------------------------+---------------+---------------+--------------+--------------+
| Implementation Menü&Eingaben  |  18. 10 2013  |   10:20:26    |   10:21:56   |  00:01:30h   |
+-------------------------------+---------------+---------------+--------------+--------------+
| Testen                        |  18. 10 2013  |   10:22:02    |   10:23:25   |  00:01:23h   |
+-------------------------------+---------------+---------------+--------------+--------------+
| SUMME                         |               |               |              |  00:23:49h   |
+-------------------------------+---------------+---------------+--------------+--------------+

==========
Adressbuch
==========
~~~~~~~~~~~~~~~~
Aufgabenstellung
~~~~~~~~~~~~~~~~
Schreiben Sie ein C-Programm, welches ein einfaches Adressbuch implementiert. Verwenden Sie dabei zwei Structs (PERSON, ADDRESS) um die notwendigen Informationen abzulegen. Die Ein- und Ausgabe soll über ein einfaches CLI-Menü erfolgen. Verwenden Sie für die einzelnen Funktionalitäten auch entsprechende Funktionen, welche Sie mittels call-by-reference implementieren.

Verwenden Sie dabei einen dynamischen Speicher um beim Hinzufügen von neuen Personen nicht auf einen statischen Wert beschränkt zu sein!

Bitte beachten Sie, dass der Zuweisungsoperator bei String-Zuweisungen nicht verwendet darf (siehe "C von A bis Z").

~~~~~~~~~~~~~~~~~~~
Aufwandsabschätzung
~~~~~~~~~~~~~~~~~~~
+-------------------------------+---------------+-------------+
|            Schritt            | Geplante Zeit |   Aufwand   |
|            Schritt            |     [H:MM]    |             |
+===============================+===============+=============+
| Prototypen                    |      0:40     |   Mittel    |
+-------------------------------+---------------+-------------+
| Structs                       |      1:00     |   Mittel    |
+-------------------------------+---------------+-------------+
| Implementation Operationen    |      2:00     |    Hoch     |
+-------------------------------+---------------+-------------+
| Speicherverwaltung            |      0:30     |   Mittel    |
+-------------------------------+---------------+-------------+
| Implementation Menü&Eingaben  |      2:00     |    Hoch     |
+-------------------------------+---------------+-------------+
| Testen                        |      0:15     |   Gering    |
+-------------------------------+---------------+-------------+

~~~~~~~~~~~~~~~~~~~~~~
Ablauf Implementierung
~~~~~~~~~~~~~~~~~~~~~~
#. Definition der Funktions-Prototypen
#. Definition der Structs
#. Funktionen erstellen
#. Programmschleife mit User IO erstellen

~~~~~~~~~~~
Ablauf Test
~~~~~~~~~~~
----------
Test Daten
----------

.. code:: text

    Homer
    Simpson
    (939)555-0113
    chunkylover53@aol.com
    Evergreen Terrace
    742
    Springfield
    USA
    Tennessee
    37172

.. code:: text

    SpongeBob
    SquarePants
    177-664-3262 
    ssquarepants@krustykrab.mh
    Conch Street
    124
    Bikini Bottom
    Marshall Islands
    Bikini Atoll
    96960

.. code:: text

    $ ./a.out 
    Was wollen sie machen?
                                      [ Hilfe ]
    =============================================================================
                         Diese Befehle stehen zur verfuegung:
    -----------------------------------------------------------------------------
    Help     0 - Zeigt diese Hilfestellung an.
    List     0 - Listet alle eingetragenen Personen auf und zeigt ihren Index an.
    Add      0 - Fuegt eine neue Person hinzu.
    Rm   index - Entfernt die Person am angegebenen Index.
    Mod  index - Aendert die Person am angegebenen Index.
    Show index - Zeigt alle Daten zu der Person am angegebenen Index.
    Quit     0 - Beendet das Programm
    -----------------------------------------------------------------------------
    
    [h 0|l 0|a 0|r index|m index|s index|q 0]
    l 0
    
    [h 0|l 0|a 0|r index|m index|s index|q 0]
    r -1
    Index out of Bound

    [h 0|l 0|a 0|r index|m index|s index|q 0]
    m 0
    Index out of Bound

    [h 0|l 0|a 0|r index|m index|s index|q 0]
    s 1
    Index out of Bound

    [h 0|l 0|a 0|r index|m index|s index|q 0]
    a 0
    Vorname       : Homer
    Nachname      : Simpson
    Telephonnummer: (939) 555-0113
    Emailadresse  : chunkylover53@aol.com
    Strasse       : Evergreen Terrace
    Strasse       : 742
    Stadt         : Springfield
    Land          : USA
    Staat         : Tennessee
    Postleitzahl  : 37172

    [h 0|l 0|a 0|r index|m index|s index|q 0]
    l 0
    [0] Homer Simpson

    [h 0|l 0|a 0|r index|m index|s index|q 0]
    a 0
    Vorname       : SpongeBob
    Nachname      : SquarePants
    Telephonnummer: 177-664-3262 
    Emailadresse  : ssquarepants@krustykrab.mh
    Strasse       : Conch Street
    Strasse       : 124
    Stadt         : Bikini Bottom
    Land          : Marshall Islands
    Staat         : Bikini Atoll
    Postleitzahl  : 96960

    [h 0|l 0|a 0|r index|m index|s index|q 0]
    l 0
    [0] Homer Simpson
    [1] SpongeBob SquarePants

    [h 0|l 0|a 0|r index|m index|s index|q 0]
    m 0
    Aendern einer Person.
    Bei Eingaben die mit . beginnen wird der alte Wert behalten.
    Vorname        [Homer]: .
    Nachname       [Simpson]: .
    Telephonnummer [(939)]: 555-7334 
    Emailadresse   [chunkylover53@aol.com]: .
    Strasse 1      [Evergreen]: .
    Strasse 2      [742]: .
    Stadt          [Springfield]: .
    Land           [USA]: .
    Staat          [Tennessee]: .
    Postleitzahl   [37172]: .

    [h 0|l 0|a 0|r index|m index|s index|q 0]
    l 0
    [0] Homer Simpson
    [1] SpongeBob SquarePants

    [h 0|l 0|a 0|r index|m index|s index|q 0]
    s 1
    Vorname       : SpongeBob
    Nachname      : SquarePants
    Telephonnummer: 177-664-3262
    Emailadresse  : ssquarepants@krustykrab.mh
    Strasse 1     : Conch
    Strasse 2     : 124
    Stadt         : Bikini
    Land          : Marshall
    Staat         : Bikini
    Postleitzahl  : 96960

    [h 0|l 0|a 0|r index|m index|s index|q 0]
    q 0
    
~~~~~~~~~~~~~~~~
Zeitaufzeichnung
~~~~~~~~~~~~~~~~
+----------------------------+--------------+---------+---------+-----------+
| Task                       | Date         | From    | To      | Duration  |
+----------------------------+--------------+---------+---------+-----------+
|                            | [YYYY-MM-DD] | [HH:MM] | [HH:MM] |    [H:MM] |
+============================+==============+=========+=========+===========+
| Structs                    |  2013-10-18  |  09:50  |  10:10  |     0:20  |
+----------------------------+--------------+---------+---------+-----------+
| Prototypen                 |  2013-10-18  |  10:10  |  10:30  |     0:20  |
+----------------------------+--------------+---------+---------+-----------+
| Kommentare addressbuch.h   |  2013-10-18  |  10:30  |  10:50  |     0:20  |
+----------------------------+--------------+---------+---------+-----------+
| Implementierungen          |  2013-10-18  |  11:00  |  12:20  |     1:20  |
+----------------------------+--------------+---------+---------+-----------+
| Implementierung II         |  2013-10-28  |  17:20  |  18:20  |     1:00  |
+----------------------------+--------------+---------+---------+-----------+
| nachdenken eingaben parsen |  2013-10-28  |  18:20  |  ??:??  |     ?:??  |
+----------------------------+--------------+---------+---------+-----------+
| input loop                 |  2013-11-03  |  17:00  |  18:30  |     1:30  |
+----------------------------+--------------+---------+---------+-----------+
