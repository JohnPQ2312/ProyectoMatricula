#include <iostream>
#include "Register.h"

using namespace std;

int main() {
	Register register1;

	register1.addStudent("Juan Perez", "123456", "Ingenieria en Sistemas", 1);
	register1.addCourse("INF101", "Programacion I", "Ing. Carlos Perez", 5);
	register1.addCourse("INF102", "Programacion II", "Ing. Carlos Perez", 5);
	register1.addSchedule("Lunes", 8, 10, "A-101");
	register1.addSchedule("Martes", 8, 10, "A-101");
	register1.assignSchedule(0, 1, 0);
	register1.assignSchedule(0, 1, 1);

	register1.showCourses();
}