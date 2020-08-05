Домашнее задание №5 (Урок 12) 
=============================
по курсу компании OTUS
-----------------------

Для установки программы необходимо иметь компилятор gcc версии 8 или выше. При необходимости 

Для компиляции программы выполните в верхней директории проекта:  <br>
cmake CMAKE_C_FLAGS="-lstdc++fs" .             <br>
cmake --build .     

Если компилятор, поддерживающий std::filesystem установлен отдельно (как на целевой системе ubuntu 18.04), то первую команду необходимо заменить на следующий вариант:  <br>  
cmake -D CMAKE_C_COMPILER=gcc-8 -D CMAKE_CXX_COMPILER=g++-8 -D CMAKE_C_FLAGS="-lstdc++fs" . 

Подробнее документацию можно посмотреть по ссылке   <br> 
https://paulokoelio.github.io/otus12hw5/  


========= Лицензия =============
--------------------------------

На проект в целом распространяется лицензия:  <br>
Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International Public License  <br>
Условия лицензии приводятся на сайте:  <br>
https://creativecommons.org/licenses/by-nc-nd/4.0/  <br>
https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode  <br>
Полные условия лицензии указаны в файле License-BY-NC-ND-4.pdf
