Динамична памет



Паметта в С++ програмите се дели на две части:

Stack - за всички променливи, декларирани във функции ще бъдат заделена памет тук

Heap - паметта тук се заделя динамично (при стартиране на програмата).



Често в програмите ви няма да знаете точно колко памет да заделите, а ще разбирате чак когато програмата е стартирана.



Оператори new и delete

Когато решим да заделяме памет динамично, то ние трябва сами да я менажираме. Това означава, че както я заделяме, така трябва и да я освобождаваме.

Заделянето на динамична памет става чрез оператора new, който връща референция към адресът на заделената памет, поради което винаги ще използваме указатели.

int* bigNumber = new int;

За масиви - int* tenBigNumbers = new int[10];

Освобождаването на динамично заделена памет става чрез оператора deletе.

delete bigNumber;

За масиви - delete[] bigNumber;