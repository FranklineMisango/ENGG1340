#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


struct Car {
	string id;
	Car *next;
};

void appendCar(Car *&head, string id);
void printTrain(Car *&head);

int main() {
	Car *head = NULL;
	int n;
	cin >> n;
	string id;
	for (int i = 0; i < n; i++) {
		cin >> id;
		appendCar(head, id);
	}
	printTrain(head);

	return 0;
}

// Please implement the function appendCar() here
void appendCar(Car *&head, string id) {
    Car *newCar = new Car;
    newCar->id = id;
    newCar->next = NULL;
    if (head == NULL) {
        head = newCar;
    }
    else {
        Car *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCar;
    }
}


void printTrain(Car *&head) {
	Car *current = head;
	while (current != NULL) {
		if (current->next != NULL) {
			cout << current->id << ", ";
		}
		else {
			cout << current->id;
		}
		current = current->next;
	}
}

