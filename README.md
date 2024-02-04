# FFT optimization practice for UNN Winter School 2024

Репозиторий для практической работы по оптимизации алгоритмов для архитектуры RISC-V на примере Дискретного Преобразования Фурье (DFT)

## Правила игры

Ваша основная задача - разработать алгоритмические оптимизации для маленьких длин DFT - 8 и 16. Как вы уже могли заметить, 8 и 16 - это степени двойки, для них можно написать быстрое преобразование Фурье - FFT. Осталось только сделать его **быстрым**.

Рекомендуем после алгоритмической оптимизации попробовать сделать следующий шаг и заняться уже низкоуровневой оптимизацией - например, попробовать векторизовать небольшие алгоритмы.

Предлагаем поучаствовать в своего рода соревнованиях. Раз главной целью оптимизации обычно является высокая производительность, она и будет зачетной метрикой. Чем меньше тактов уйдет на вычисление одного элемента, тем выше строчка в турнирной таблице.  \
Алгоритмы большей длины имеют большую потенциальную производительность, но заметно сложнее пишутся. _Не факт, что в довольно жестких временных рамках практикума удастся раскрыть потенциал алгоритмов в полной мере, поэтому мы будем вести зачет по длинам по раздельности._

## Задачи

1) Разработать оптимизации для DFT2 и DFT4. _Мы проделали это вместе на вводной лекции_
2) Написать преобразование Фурье общего вида по [алгоритму Кули-Тьюки](How2CooleyTukey.md).
    * _Опционально_: по Кули-Тьюки собрать DFT4 из DFT2
3) Выбрать длину DFT (8 или 16) и алгоритмически оптимизировать код для Кули-Тьюки
    * _Опционально_: разработать код для обеих длин
4) Поэкспериментировать с RVV оптимизациями: разработать векторный код для DFT2 и DFT4
    * _Опционально_: попробовать распространить оптимизацию на DFT8 или DFT16
    * _Опционально_: попробовать распараллелить код с помощью OpenMP и сравнить

## Алгоритм работы

1) Создать fork репозитория.
2) Собрать проект для RISC-V архитектуры.
3) Запустить примеры, бенчмарки и тесты на RISC-V Qemu и RISC-V плате.
4) Проверить правильность реализации DFT4.
    * Включить сборку тестов для DFT4. Запустить их.
5) Добавить реализации DFT выбранных длин.
    * Включить сборку тестов для реализованных длин DFT. Запустить их, убедиться в корректности реализации.
    * Запустить бенчмарки, сравнить с другими реализациями (если есть).
6) Открыть Pull Request c оптимизациями DFT.
    * В описании должны быть замеры бенчмарков с RVV платы.
    * CI должен быть зеленым.

## Структура репозитория

* [lib](lib) - библиотека с реализациями DFT
* [examples](examples) - примеры использования библиотеки
* [perf](perf) - бенчмарки для замеров времени выполнения алгоритмов
* [test](test) - функциональные тесты для проверки корректности алгоритмов

## Сборка проекта

Для сборки проекта можно использовать скрипт [build.sh](build.sh). Перед запуском необходимо установить пути для кросс-компиляторов `C_COMPILER_PATH` и `CXX_COMPILER_PATH` и выставить соответствующие параметры сборки.

Опции конфигурации проекта:
* `ENABLE_TEST` - Сборка тестов (`ON`\\`OFF`)
* `ENABLE_BENCH` -  Сборка бенчмарков (`ON`\\`OFF`)
* `TARGET_ARCH` - Целевая архитектура
    * `RISCV_GENERIC` - Скалярная версия библиотеки (без RVV)
    * `RISCV_VECTOR` - Векторная версия библиотеки (RVV 0.7.1)
* `BUILD_TYPE` - Режим сборки (`Release`\\`Debug`)
* `BUILD_FOLDER` - Папка для артефактов сборки
* `BUILD_STATIC` - Включить статическую линковку (`ON`\\`OFF`)

## Пример запуска с помощью QEMU

``
qemu-riscv64 -cpu c910v ./_build/examples/dft4_example
``

В случае ошибки:\
``
qemu-riscv64: Could not open '/lib/ld-linux-riscv64-lp64d.so.1': No such file or directory
``\
необходимо сконфигурировать проект с `-DBUILD_STATIC=ON` или добавить ключ запуска `-L <path-to-toolchain>/sysroot/`

## Отладка кода на RISC-V

[Краткая инструкция](docs/How2Debug.md)
