#include "DateAndTime.h"

class Appointment
{
public:
	Appointment(DateAndTime start, DateAndTime end); // , char desc[] = "");

	DateAndTime m_startOfAppointment;
	DateAndTime m_endOfAppointment;
	char m_class[6] = "class";
	char m_classRoom [5] = "x.yz";
	char m_teacher[7] = "person";
	char m_description [12] = "description";

	void drawVisual();
	void removeAppointment();
	float getDurationInHours();
	float getDurationInMinutes();
private:

};
