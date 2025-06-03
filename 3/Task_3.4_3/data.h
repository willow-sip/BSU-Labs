struct Student {
    char name[100];
    int age;
    char gender;
    int course;
    float performance;
};

Student students[] = {
        {"Ivanov Ivan Ivanovich", 20, 'M', 1, 4.5},
        {"Petrova Anna Sergeyevna", 22, 'F', 2, 4.7},
        {"Sidorov Aleksey Valeryevich", 21, 'M', 1, 3.8},
        {"Kuznetsova Mariya Petrovna", 23, 'F', 2, 4.9},
        {"Smirnov Dmitry Alexandrovich", 19, 'M', 3, 4.0},
        {"Fedorova Olga Maksimovna", 24, 'F', 3, 4.6},
        {"Vasiliev Sergey Ivanovich", 25, 'M', 1, 4.2},
        {"Nikolaeva Elena Viktorovna", 20, 'F', 2, 4.8},
        {"Morozov Andrey Sergeyevich", 22, 'M', 3, 3.9},
        {"Dmitrieva Anastasiya Vladimirovna", 21, 'F', 1, 4.1},
        {"Kovalev Alexey Dmitrievich", 23, 'M', 2, 4.3},
        {"Semenova Yulia Alexandrovna", 19, 'F', 3, 4.5},
        {"Petrov Ivan Sergeyevich", 26, 'M', 1, 4.0},
        {"Zaitseva Marina Petrovna", 24, 'F', 2, 4.6},
        {"Frolov Viktor Alekseevich", 27, 'M', 3, 3.7},
        {"Gromova Daria Ivanovna", 22, 'F', 1, 4.9},
        {"Borisov Pavel Sergeyevich", 20, 'M', 2, 4.4},
        {"Karpova Svetlana Mikhailovna", 23, 'F', 3, 4.8},
        {"Sokolov Artem Valeryevich", 21, 'M', 1, 4.1},
        {"Tikhonova Alena Sergeyevna", 19, 'F', 2, 4.2},
        {"Lebedev Igor Alexandrovich", 25, 'M', 3, 3.8},
        {"Vlasova Kristina Dmitrievna", 24, 'F', 1, 4.7},
        {"Kolesnikov Anton Ivanovich", 22, 'M', 2, 4.3},
        {"Shcherbakova Oksana Valeryevna", 20, 'F', 3, 4.5},
        {"Fomin Denis Sergeyevich", 23, 'M', 1, 4.0},
        {"Makarova Lyudmila Petrovna", 21, 'F', 2, 4.6},
        {"Gusev Alexey Ivanovich", 26, 'M', 3, 4.2},
        {"Semyonova Irina Viktorovna", 19, 'F', 1, 4.8},
        {"Kuzmin Dmitry Alekseevich", 24, 'M', 2, 4.1},
        {"Pavlova Anna Sergeyevna", 22, 'F', 3, 4.4}
};

const int MAX_STUDENTS = 100;
