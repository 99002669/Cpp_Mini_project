# Cpp_Mini_project
## *-Song Store Management System-*
This Mini Project is implemented in the C++ programming language with the inclusion of Linux related concepts such as Threads and Mutex to perform mutual exclusion. This project is an implementation of addition, deletion and updation of songs and their data such as Name, ID, Artist, Price, Genre, Release year. One thread would handle the addition of songs while the other thread is used to count the list of songs inserted or currently in the database. A mutex lock is applied so that the process of counting would happen only after the first thread's instructions are executed and the lock is released. Google Testing has been implemented to perform the unit testing on the Project. STL concepts such as lists were implemented in this project to take in the song details into a list and to access them later for further modifications and display.





|CppCheck|Codacy|Valgrind|UnitTesting|C/C++ CI|
|--------|------|--------|-----------|--------|
|![cppcheck-action](https://github.com/99002669/Cpp_Mini_project/workflows/cppcheck-action/badge.svg)|[![Codacy Badge](https://app.codacy.com/project/badge/Grade/06a7464593d7406585c1cdb377bd5814)](https://www.codacy.com/gh/99002669/Cpp_Mini_project/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=99002669/Cpp_Mini_project&amp;utm_campaign=Badge_Grade)|![Valgrind](https://github.com/99002669/Cpp_Mini_project/workflows/Valgrind/badge.svg)|![Unit testing](https://github.com/99002669/Cpp_Mini_project/workflows/Unit%20testing/badge.svg?branch=master)|![C/C++ CI](https://github.com/99002669/Cpp_Mini_project/workflows/C/C++%20CI/badge.svg)|
