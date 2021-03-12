#pragma once
class Property
{

private:
	int id;
	char* description;
	int order;
public:
	Property(int, char*, int);

	void setId(int);

	int getId() {
		return this->id;
	}

	void setDescription(char*);

	char* getDescription() {
		return this->description;
	}

	void setOrder(int);

	int getOrder() {
		return this->order;
	}

};

