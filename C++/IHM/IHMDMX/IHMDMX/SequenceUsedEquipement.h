#pragma once
class SequenceUsedEquipement
{
private:
	int id;
	int value;
public:
	SequenceUsedEquipement(int, int);
	int getId() {
		return this->id;
	}
	int setId(int);
	int getSequenceValue() {
		return this->value;
	}
	int setSequenceValue(int);
};

