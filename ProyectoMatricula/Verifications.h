//USO DESCARTADO

#include "Menu.h"
#pragma once

bool dateVerification(string day, int startHour, int endHour) {
	string daysVector[5] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes" };
	int hoursVector[16] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
	bool dayFound = false;
	bool hourFound = false;

	while (dayFound == false)
	{
		for (int i = 0; i < 5; i++)
		{
			if (day == daysVector[i])
			{
				while (hourFound == false)
				{
					for (int j = 0; j < 16; j++)
					{
						if (startHour == hoursVector[j])
						{
							hourFound = true;
						}
						else if (endHour == hoursVector[j])
						{
							hourFound = true;
						}
						else if (startHour > endHour)
						{
							cout << "La hora de inicio no puede ser mayor a la hora de finalizacion, porfavor, ingrese una hora de inicio y finalizacion valida." << endl;
						}
						else if (startHour < 7 || startHour > 22 || endHour < 7 || endHour > 22)
						{
							cout << "La hora de inicio y finalizacion no puede ser menor a las 7:00 ni mayor a las 22:00, porfavor, ingrese una hora de inicio y finalizacion valida." << endl;
						}
						else if (startHour == endHour)
						{
							cout << "La hora de inicio no puede ser igual a la hora de finalizacion, porfavor, ingrese una hora de inicio y finalizacion valida." << endl;
						}
						else
						{
							cout << "Hora no valida, porfavor, ingrese una hora valida." << endl;
						}
					}
				}
			}
		}
		if (dayFound == false)
		{
			cout << "Dia no valido, porfavor, ingrese un dia valido." << endl;
		}
	}

	if ((dayFound == true) && (hourFound == true))
	{
		return true;
	}
	else
	{
		return false;
	}
}