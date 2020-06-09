#include "lab2_drones_manager.hpp"
#include <iostream>

//using namespace std;
// TODO: Implement all of the listed functions below
// See the assignment specifications and the header file for details
// Your code needs to pass at least all of the provided test cases

DronesManager::DronesManager() {
	first = nullptr;
	last = nullptr;
	size = 0;
}

DronesManager::~DronesManager() { 
	if(!empty()) {
		if(size==1) {
			delete first;
			first = nullptr;
			last = nullptr;
		} else {
			DroneRecord* current = last;
			DroneRecord* prev = last->prev;
			for(int node = 0; node < size - 1; node++) {
				current = prev;
				if (current->prev != nullptr)
					prev = current->prev;
				delete current;
			} // iterates through list freeing nodes
			first = nullptr;
			last=nullptr;
		}
	}
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	bool checkA = (lhs.droneID==rhs.droneID && lhs.range==rhs.range && lhs.yearBought==rhs.yearBought);
	bool checkB = (lhs.batteryType==rhs.batteryType && lhs.description==rhs.description
		&& lhs.droneType==rhs.droneType && lhs.manufacturer==rhs.manufacturer);
	return checkA && checkB;
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	return size==0;
}

DronesManager::DroneRecord* DronesManager::getDroneRecord(unsigned int index) const {
	if(index>size || empty())
		return nullptr;
	DroneRecord* current = first;
	DroneRecord* next;
	for(int node = 0; node < index; node++) {
		next = current->next;
		current = next;
	}
	return current;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	if(index>size) 
		return *last;
	if(empty())
		return DroneRecord(0);
	return *getDroneRecord(index);
}

int DronesManager::search(DroneRecord value) const {
	if(empty())
		return -1;
	DroneRecord* current = first;
	DroneRecord* next;
	for(int node = 0; node < size; node++){
		if(value == *current)
			return node;
		next = current->next;
		current = next;
	}
	return size;
}

void DronesManager::print() const {
	for(int node = 0; node < size; node++) {
		DroneRecord* drone = getDroneRecord(node);
		cout << "DATA FOR DRONE: " << node + 1 << endl;
		cout << "Drone ID is: " << drone->droneID << endl;
		cout << "Drone Range: " << drone->range << endl;
		cout << "Drone Year bought is: " << drone->yearBought << endl;
		cout << "Drone Type : " << drone->droneType << endl;
		cout << "Drone Battery type is: " << drone->batteryType << endl;
		cout << "Drone Description: " << drone->description << endl << endl;
		cout << "this drone's address is: " << drone << endl << endl;
		cout << "prev is: " << drone->prev << endl;
		cout << "Next is: " << drone->next << endl << endl;
	}
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	if(index>size)
		return false;
	DroneRecord* new_drone = new DroneRecord();
	new_drone->batteryType = value.batteryType;
	new_drone->droneID = value.droneID;
	new_drone->droneType = value.droneType;
	new_drone->description = value.description;
	new_drone->manufacturer = value.manufacturer;
	new_drone->range = value.range;
	new_drone->yearBought = value.yearBought;
	new_drone->next = nullptr;
	new_drone->prev = nullptr;

	DroneRecord* current = getDroneRecord(index);
	if(current == first || empty())
		return insert_front(value);
	if(index == size) 
		return insert_back(value);
	
	DroneRecord* prev = current->prev;

	new_drone->next = current;
	new_drone->prev = current->prev;
	prev->next = new_drone;
	current->prev = new_drone;
	size++;
	return true;
}

bool DronesManager::insert_front(DroneRecord value) {
	DroneRecord* new_drone = new DroneRecord();
	new_drone->batteryType = value.batteryType;
	new_drone->droneID = value.droneID;
	new_drone->droneType = value.droneType;
	new_drone->description = value.description;
	new_drone->manufacturer = value.manufacturer;
	new_drone->range = value.range;
	new_drone->yearBought = value.yearBought;
	new_drone->next = nullptr;
	new_drone->prev = nullptr;
	if(empty()) {
		first = new_drone;
		last = new_drone;
		new_drone->next = nullptr;
		new_drone->prev = nullptr;
		size++;
		/*cout << "New item       " << new_drone << endl;
		cout << "new item next  " << new_drone->next << endl;*/
		return true;
	} else {
	DroneRecord* next = first;
	first = new_drone;
	new_drone->prev = nullptr;
	new_drone->next = next;
	next->prev = new_drone;
	/*cout << "New item       " << new_drone << endl;
	cout << "new item next  " << new_drone->next << endl;
	cout << "next item      " << next << endl;
	cout << "next item prev " << next->prev << endl;*/
	}


	size++;
	return true;
}

bool DronesManager::insert_back(DroneRecord value) {
	DroneRecord* new_drone = new DroneRecord();
	new_drone->batteryType = value.batteryType;
	new_drone->droneID = value.droneID;
	new_drone->droneType = value.droneType;
	new_drone->description = value.description;
	new_drone->manufacturer = value.manufacturer;
	new_drone->range = value.range;
	new_drone->yearBought = value.yearBought;
	
	if(empty()) {
		first = new_drone;
		last = new_drone;
		new_drone->next = nullptr;
		new_drone->prev = nullptr;
		size++;
		return true;
	} else {
		DroneRecord* prev = last;
		last = new_drone;
		new_drone->next = nullptr;
		new_drone->prev = prev;
		prev->next = new_drone;
		size++;
		return true;
	}
}

bool DronesManager::remove(unsigned int index) {
	if(index>size || empty())
		return false;
	DroneRecord* current = getDroneRecord(index);
	if(current == first)
		return remove_front();
	if(current == last) 
		return remove_back();

	DroneRecord* next = current->next;
	DroneRecord* prev = current->prev;
	
	delete current;
	next->prev = prev;
	prev->next = next;
	size--;
	return true;
}

bool DronesManager::remove_front() {
	if(empty())
		return false;
	DroneRecord* current = first;
	if(size==1) {
		delete current;
		first = nullptr;
		last = nullptr;
		size--;
		return true;
	} else {
		DroneRecord* next = first->next;
		first = next;
		next->prev = nullptr;
		delete current;
		size--;
	} 
	return true;
}

bool DronesManager::remove_back() {
	if(empty())
		return false;
	DroneRecord* current = last;
		if(size==1) {
		delete current;
		last = nullptr;
		first = nullptr;
		size--;
		return true;
	} else {
		DroneRecord* prev = current->prev;
		delete current;
		last = prev;
		prev->next = nullptr;
		size--;
	}
	return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	if(index>size || empty())
		return false;
	DroneRecord* current = getDroneRecord(index);
	DroneRecord* new_drone = new DroneRecord();
	current->batteryType = value.batteryType;
	current->droneID = value.droneID;
	current->droneType = value.droneType;
	current->description = value.description;
	current->manufacturer = value.manufacturer;
	current->range = value.range;
	current->yearBought = value.yearBought;
	return true;
}

bool DronesManager::reverse_list() {
	DroneRecord* current = first;
	DroneRecord* new_last = first;
	DroneRecord* next_node;
	DroneRecord* next_holder;
	//DroneRecord* prev_holder;
	for(int node = 0; node < size; node++) {
		next_node = current->next;

		next_holder = current->next;
		current->next = current->prev;
		current->prev = next_holder;

		current = next_node;
	}
	first = last;
	last = new_last;
	return true;
}