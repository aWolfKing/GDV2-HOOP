#pragma once
using namespace std;
#include <string>

class npc
{
public:
	npc();
	npc(string _name);
	~npc();

	string name;

	virtual void render();

private:

};

class role
{
public:
	virtual void render();
private:

};



class Elf : public npc
{
public:
	Elf(string _name, role _role);
	void render();
	role _role;
private:

};


class Farmer : public role
{
public:
	void render();

private:

};

class Soldier : public role
{
public:
	void render();

private:

};

class Shaman : public role
{
public:
	void render();

private:

};
