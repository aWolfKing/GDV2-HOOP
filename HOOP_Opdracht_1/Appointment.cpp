#include "Appointment.h"

Appointment::Appointment(DateAndTime m_start, DateAndTime m_end) { // char m_desc [12]) {		//no default constructor?
	m_startOfAppointment = m_start;
	m_endOfAppointment = m_end;
	//m_class = m_clss;
	//m_classRoom = m_classrm;
	//m_teacher = m_teachr;
	//m_description = m_desc;	//Error
}

void Appointment::drawVisual() {
	//draws the appointment into the agenda
}

void Appointment::removeAppointment() {
	//removes the appointment
}

float Appointment::getDurationInHours() {
	//returns the duration of the class in hours
}

float Appointment::getDurationInMinutes() {
	//returns the duration of the class in minutes
}